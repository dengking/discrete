from typing import List, Union

"""
1、https://jovian.com/fuzzyray/dancing-links

"""


class Node:
    """Nodes for the sparse matrix"""

    def __init__(self, header_node=None):
        self.value = None  # 节点的值
        self.left = self
        self.right = self
        self.up = self
        self.down = self
        self.column = header_node

    def __repr__(self):
        return "Node: {}:{}".format(self.column.value, self.value)


class HeaderNode(Node):
    def __init__(self, column_id):
        super().__init__(header_node=self)
        self.value = column_id
        self.node_count = 0

    def __repr__(self):
        return "HeaderNode: {}".format(self.value)


class RootNode(Node):
    def __init__(self, value='root'):
        super().__init__()
        self.value = value

    def __repr__(self):
        return "RootNode"


class DancingLinkAlgorithm:

    def __init__(self, matrix: List):
        """

        :param matrix:
        """
        self.root = RootNode()  # Create our root node for accessing the matrix
        self.__create_sparse_matrix__(matrix)
        self.answers = []  # 所有的答案

    def __create_sparse_matrix__(self, matrix: List):
        """
        逐行创建spare matrix
        :param matrix:
        :return:
        """
        # Create the column header nodes
        for col_idx in range(len(matrix[0])):
            new_node = HeaderNode(col_idx)
            last_node = self.root.left
            new_node.right = self.root
            self.root.left = new_node
            new_node.left = last_node
            last_node.right = new_node

        # 逐行构建
        for row_idx in range(len(matrix)):
            row_start_node = None
            for col_idx in range(len(matrix[0])):
                if matrix[row_idx][col_idx]:
                    # Link new node up/down
                    header: HeaderNode = self.root.right
                    for _ in range(col_idx):
                        header = header.right
                    new_node = Node(header)
                    new_node.value = matrix[row_idx][col_idx]
                    col_last_node = header.up
                    new_node.down = header
                    header.up = new_node
                    new_node.up = col_last_node
                    col_last_node.down = new_node
                    header.node_count += 1

                    # Link new node left/right
                    if row_start_node:
                        row_last_node = row_start_node.left
                        new_node.right = row_start_node
                        row_start_node.left = new_node
                        new_node.left = row_last_node
                        row_last_node.right = new_node
                    else:
                        row_start_node = new_node

    def print_matrix(self):
        node = self.root
        while node.right != self.root:
            node = node.right
            column = node
            print(node, 'node_count:', node.node_count)
            while node.down != column:
                node = node.down
                print('\t{} Right{} Left{}'.format(node, node.right, node.left))
            node = node.down

    def get_min_column(self) -> HeaderNode:
        """
        get_min_column implements Heuristic S from Donald Knuth's Dancing Links paper. The Heuristic is to
        deterministically choose the column with the least number of nodes.
        :return:
        """
        node = self.root.right
        min_column = node
        while node.right != self.root:
            node = node.right
            if node.node_count < min_column.node_count:
                min_column = node
        return min_column

    def cover(self, node: Union[HeaderNode, Node]):
        """
        remove node所在的列的所有这一列的值为1的行，都要被删除
        :param node:
        :return:
        """
        column = node.column
        column.right.left = column.left
        column.left.right = column.right

        row = column.down
        while row != column:
            right_node = row.right
            while right_node != row:
                right_node.up.down = right_node.down
                right_node.down.up = right_node.up
                right_node.column.node_count -= 1
                right_node = right_node.right
            row = row.down

    def uncover(self, node):
        """
        restore
        :param node:
        :return:
        """
        column = node.column

        row = column.up
        while row != column:
            left_node = row.left
            while left_node != row:
                left_node.up.down = left_node
                left_node.down.up = left_node
                left_node.column.node_count += 1
                left_node = left_node.left
            row = row.up

        column.right.left = column
        column.left.right = column

    def solve(self):
        self.solve_impl(0)
        return self.answers

    def solve_impl(self, k, solutions=[]):
        """
        使用backtrack的方式得到所有的solution
        :param k:
        :param solutions:
        :return:
        """
        if self.root.right == self.root:
            self.answers.append(solutions[:])
            return

        column = self.get_min_column()
        self.cover(column)

        row_node = column.down
        while row_node != column:
            solutions.append(row_node)

            right_node = row_node.right
            while right_node != row_node:  # 将这一行所有占据的列给消除掉
                self.cover(right_node)
                right_node = right_node.right

            self.solve_impl(k + 1, solutions)

            solutions.pop()
            # undo
            column = row_node.column
            left_node = row_node.left
            while left_node != row_node:
                if left_node != self.root:
                    self.uncover(left_node)
                left_node = left_node.left

            row_node = row_node.down  # move next

        self.uncover(column)


if __name__ == '__main__':
    constraint_matrix = [
        [(0, 0, 1), 0, 0, 0, (0, 0, 1), 0, 0, 0, (0, 0, 1), 0, 0, 0],  # 1 at (0,0)
        [0, (0, 1, 1), 0, 0, (0, 1, 1), 0, 0, 0, 0, (0, 1, 1), 0, 0],  # 1 at (0,1)
        [0, 0, (1, 0, 1), 0, 0, (1, 0, 1), 0, 0, (1, 0, 1), 0, 0, 0],  # 1 at (1,0)
        [0, 0, 0, (1, 1, 1), 0, (1, 1, 1), 0, 0, 0, (1, 1, 1), 0, 0],  # 1 at (1,1)
        [(0, 0, 2), 0, 0, 0, 0, 0, (0, 0, 2), 0, 0, 0, (0, 0, 2), 0],  # 2 at (0,0)
        [0, (0, 1, 2), 0, 0, 0, 0, (0, 1, 2), 0, 0, 0, 0, (0, 1, 2)],  # 2 at (0,1)
        [0, 0, (1, 0, 2), 0, 0, 0, 0, (1, 0, 2), 0, 0, (1, 0, 2), 0],  # 2 at (1,0)
        [0, 0, 0, (1, 1, 2), 0, 0, 0, (1, 1, 2), 0, 0, 0, (1, 1, 2)]  # 2 at (1,1)
    ]
    dlx = DancingLinkAlgorithm(constraint_matrix)
    print(dlx.solve())
