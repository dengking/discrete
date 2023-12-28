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
        return f"Node:row={self.value},col={self.column.value}"


class ColumnNode(Node):
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


class DancingLinksAlgorithm:

    def __init__(self, matrix: List[List]):
        self.root = RootNode()  # Create our root node for accessing the matrix
        self.columns = []  # all columns
        self.__create_sparse_matrix__(matrix)
        self.solutions = []  # 所有的答案

    def __create_sparse_matrix__(self, matrix: List):
        # Create the column header nodes
        for col_idx in range(len(matrix[0])):
            new_node = ColumnNode(col_idx)
            last_node = self.root.left
            new_node.right = self.root
            self.root.left = new_node
            new_node.left = last_node
            last_node.right = new_node
            self.columns.append(new_node)

        for row_idx in range(len(matrix)):  # 逐行构建
            row_start_node = None
            for col_idx in range(len(matrix[0])):
                if matrix[row_idx][col_idx]:
                    # Link new node up/down
                    header: ColumnNode = self.columns[col_idx]
                    new_node = Node(header)
                    new_node.value = row_idx
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
        node: Union[Node, ColumnNode] = self.root
        while node.right != self.root:
            node = node.right
            column = node
            print(node, 'node_count:', node.node_count)
            while node.down != column:
                node = node.down
                print('\t{} Right{} Left{}'.format(node, node.right, node.left))
            node = node.down

    def get_min_column(self) -> ColumnNode:
        """
        get_min_column implements Heuristic S from Donald Knuth's Dancing Links paper. The Heuristic is to
        deterministically choose the column with the least number of nodes.
        :return:
        """
        node: Union[Node, ColumnNode] = self.root.right
        min_column = node
        while node != self.root:
            if node.node_count < min_column.node_count:
                min_column = node
            node = node.right
        return min_column

    @classmethod
    def __cover__(cls, node: Union[ColumnNode, Node]):
        column = node.column
        column.right.left = column.left
        column.left.right = column.right

        row = column.down
        while row != column:
            right_node = row.right
            # 需要注意: 对于row本身是不需要执行下面循环体的，这是因为需要通过列拿到这些行，所以不能够将这列和这些行的关系解除
            # 在前面的逻辑中这一列已经被从control row中剔除了，所以它们无法通过这一列被检索到
            while right_node != row:
                right_node.up.down = right_node.down
                right_node.down.up = right_node.up
                right_node.column.node_count -= 1
                right_node = right_node.right
            row = row.down

    @classmethod
    def __uncover__(cls, node):
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
        self.__solve_impl__(0)
        return self.solutions

    def __solve_impl__(self, k, solution=[]):
        if self.root.right == self.root:
            self.solutions.append(solution[:])
            return

        column = self.get_min_column()
        if column.node_count == 0:
            return
        self.__cover__(column)
        print(f'cover column:{column}')
        row_node = column.down
        while row_node != column:
            solution.append(row_node)
            left_node = row_node.left
            while left_node != row_node:  # 将这一行所有占据的列给消除掉
                self.__cover__(left_node)
                left_node = left_node.left

            self.__solve_impl__(k + 1, solution)

            solution.pop()
            # undo
            right_node = row_node.right
            while right_node != row_node:
                self.__uncover__(right_node)
                right_node = right_node.right
            row_node = row_node.down  # move next

        self.__uncover__(column)
        print(f'uncover column:{column}')


if __name__ == '__main__':
    constraint_matrix1 = [
        [(0, 0, 1), 0, 0, 0, (0, 0, 1), 0, 0, 0, (0, 0, 1), 0, 0, 0],  # 1 at (0,0)
        [0, (0, 1, 1), 0, 0, (0, 1, 1), 0, 0, 0, 0, (0, 1, 1), 0, 0],  # 1 at (0,1)
        [0, 0, (1, 0, 1), 0, 0, (1, 0, 1), 0, 0, (1, 0, 1), 0, 0, 0],  # 1 at (1,0)
        [0, 0, 0, (1, 1, 1), 0, (1, 1, 1), 0, 0, 0, (1, 1, 1), 0, 0],  # 1 at (1,1)
        [(0, 0, 2), 0, 0, 0, 0, 0, (0, 0, 2), 0, 0, 0, (0, 0, 2), 0],  # 2 at (0,0)
        [0, (0, 1, 2), 0, 0, 0, 0, (0, 1, 2), 0, 0, 0, 0, (0, 1, 2)],  # 2 at (0,1)
        [0, 0, (1, 0, 2), 0, 0, 0, 0, (1, 0, 2), 0, 0, (1, 0, 2), 0],  # 2 at (1,0)
        [0, 0, 0, (1, 1, 2), 0, 0, 0, (1, 1, 2), 0, 0, 0, (1, 1, 2)]  # 2 at (1,1)
    ]

    dlx1 = DancingLinksAlgorithm(constraint_matrix1)
    print(dlx1.solve())

    constraint_matrix2 = [
        [1, 0, 0, 1, 0, 0, 1],
        [1, 0, 0, 1, 0, 0, 0],
        [0, 0, 0, 1, 1, 0, 1],
        [0, 0, 1, 0, 1, 1, 0],
        [0, 1, 1, 0, 0, 1, 1],
        [0, 1, 0, 0, 0, 0, 1],
    ]
    dlx2 = DancingLinksAlgorithm(constraint_matrix2)
    print(dlx2.solve())
