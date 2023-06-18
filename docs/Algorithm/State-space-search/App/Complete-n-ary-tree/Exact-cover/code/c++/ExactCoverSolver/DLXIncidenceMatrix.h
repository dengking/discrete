//
// Created by kai on 2023/6/18.
//

#ifndef EXACTCOVERSOLVER_DLXINCIDENCEMATRIX_H
#define EXACTCOVERSOLVER_DLXINCIDENCEMATRIX_H

#include <iostream>

namespace kai_exact_cover_solver {
    /**
     * \brief A node containing data of variable type @c T and four links to other nodes - left, right, up and down.
     *
     */
    template<class T>
    class DLXNode {
    public:
        DLXNode(const T &theData,
                DLXNode<T> *theRight = nullptr,
                DLXNode<T> *theLeft = nullptr,
                DLXNode<T> *theUp = nullptr,
                DLXNode<T> *theDown = nullptr)
                : data_(theData), right_(theRight), left_(theLeft), up_(theUp), down_(theDown) {}

        //!< Sets the node's data to @p theData.
        void set_data(const T &theData) {
            data_ = theData;
        }

        //!< \return the data object.
        T &data() const {
            return const_cast<T &>(data_);         // don't know why I have to cast the argument, but compiler otherwise complains

        }

        DLXNode<T> *right() const { return right_; } //!< \return the right link.
        DLXNode<T> *left() const { return left_; } //!< \return the left link.
        DLXNode<T> *up() const { return up_; } //!< \return the up link.
        DLXNode<T> *down() const { return down_; } //!< \return the down link.
        void set_right(DLXNode<T> *node) { right_ = node; } //!< Points the right link to @c node.
        void set_left(DLXNode<T> *node) { left_ = node; } //!< Points the left link to @c node.
        void set_up(DLXNode<T> *node) { up_ = node; } //!< Points the up link to @c node.
        void set_down(DLXNode<T> *node) { down_ = node; } //!< Points the down link to @c node.

        /**
         * @brief Joins two nodes together horizontally.
         *
         * Sets the right link of @p left to @p right and the left link of @p right to @p left.
         * Assumes neither @p left nor @p right point to @c nullptr.
         */
        static void join_node_horizontally(DLXNode<T> *left, DLXNode<T> *right) {
            left->set_right(right);
            right->set_left(left);
        }

        /**
         * @brief Joins two nodes together vertically.
         *
         * Sets the up link of @p down to @p up and the down link of @p up to @p down.
         * Assumes neither @p down nor @p up point to @c nullptr.
         */
        static void join_node_vertically(DLXNode<T> *down, DLXNode<T> *up) {
            down->set_up(up);
            up->set_down(down);
        }

    private:
        T data_;
        DLXNode<T> *right_;
        DLXNode<T> *left_;
        DLXNode<T> *up_;
        DLXNode<T> *down_;
    };

    /**
     * @brief Joins two nodes together horizontally.
     *
     * Sets the right link of @p left to @p right and the left link of @p right to @p left.
     * Assumes neither @p left nor @p right point to @c nullptr.
     */
    template<class T>
    static void join_node_horizontally(DLXNode<T> *left, DLXNode<T> *right) {
        DLXNode<T>::join_node_horizontally(left, right)
    }

    /**
     * @brief Joins two nodes together vertically.
     *
     * Sets the up link of @p down to @p up and the down link of @p up to @p down.
     * Assumes neither @p down nor @p up point to @c nullptr.
     */
    template<class T>
    static void join_node_vertically(DLXNode<T> *down, DLXNode<T> *up) {
        DLXNode<T>::join_node_vertically(down, up);
    }

    class DLXColumnHeaderNode;

    /**
     * data of node in the incidence matrix
     * Identifies location of a node within a matrix
     */
    struct DLXMatrixNodeData {
    public:
        DLXMatrixNodeData(int r = -1, DLXColumnHeaderNode *c = nullptr) : row_id_(r), column_header_(c) {}

        int row_id_;  //!< A number identifying the row
        DLXColumnHeaderNode *column_header_; //!< A pointer to the column header
    };

    //! The default matrix node used in this project.
    using DLXMatrixNode = DLXNode<DLXMatrixNodeData>;

    /*!
     * \brief A type of \ref DLXMatrixNode which acts as a header for a column
     *
     * The \ref DLXMatrixNodeData#row_id_ is set to -1 and \ref DLXMatrixNodeData#column_header_ points to the object itself.
     * \ref DLXColumnHeaderNode objects also store the size of their column, which can be accessed via member functions.
     */
    class DLXColumnHeaderNode : public DLXMatrixNode {
    public:
        DLXColumnHeaderNode(int theSize = 0)
                : DLXMatrixNode(DLXMatrixNodeData(-1, this)), _size(theSize) {}

        int size() const { return _size; } //!< returns the number of nodes in the column.
        void set_size(int N) { _size = N; } //!< sets the number of nodes in the column to @p N.
        void add_to_size(int N) { _size += N; } //!< Adds @p N to the number of nodes in the column.
    private:
        int _size;
    };


    /**
     * \brief Implementation of a matrix as a linked data structure.
     *
     * An efficient implementation of a boolean matrix, used in a solution of the Exact Cover Problem.
     * This implementation only stores non-zero entries, and is especially suitable for sparse matrices.
     * Moreover, rows and columns are represented as circular doubly linked lists, so as to be naturally
     * amenable to the so-called ``Dancing Links'' algorithm of D. Knuth.
     *
     * The following is a helpful illustration of the DLXIncidenceMatrix data structure taken from [this article](https://arxiv.org/pdf/cs/0011047.pdf) by Knuth.
     * ![An image of a linked matrix](../images/linked_matrix_image_(Knuth).png)
     *
     * The data structure consists of a *root* or *head* node (got by calling \ref head() ) which is linked to the
     * *column headers* (objects of type \ref DLXColumnHeaderNode ), each of which represents a column of the matrix and whose
     * \ref DLXColumnHeaderNode#size() records the number of 1's in that column. Each 1 is represented by an object of type
     * \ref DLXMatrixNode, and each row and column (including the header) is a circular doubly linked list.
     *
     * For each node, \ref DLXMatrixNodeData#column_header_ points to the column header, and \ref DLXMatrixNodeData#row_id_ is the row index.  The
     * values of the row index are determined by the matrix passed as an argument to the constructor - gaps in the
     * row index values of an \ref DLXIncidenceMatrix reflect zero rows in the original matrix.  For
     * column headers, \ref DLXMatrixNodeData#row_id_ = -1.  Also for \ref head(), \ref DLXMatrixNodeData#column_header_ = @c nullptr.
     *
     * @see dancing_links.h, \ref dancing_links_GJK::Exact_Cover_Solver
     */
    class DLXIncidenceMatrix {
    public:
        /**
         * Creates an empty matrix.
         */
        DLXIncidenceMatrix() : root(new DLXMatrixNode(DLXMatrixNodeData())) {
            // make root->down_ constant somehow
            join_node_horizontally(root, root);
            row_count = 0;
        }

        /**
         * @brief Converts a standard boolean matrix to \ref DLXIncidenceMatrix form.
         * @param matrix A boolean matrix.
         * @param m The number of rows in @p matrix.
         * @param n The number of columns in @p matrix.
         */
        DLXIncidenceMatrix(bool **matrix, int m, int n) : root(new DLXMatrixNode(DLXMatrixNodeData())) {
            if (m == 0 || n == 0) {
                row_count = 0;
                return;
            }
            // create first_node_of_row column
            DLXMatrixNode *column_header_node = new DLXColumnHeaderNode(0);
            //column_header_node->data().column_id = static_cast<DLXColumnHeaderNode*>(column_header_node);        // point column object to itself
            join_node_horizontally(root, column_header_node);
            // create column header objects
            for (int j = 1; j < n; j++) {
                join_node_horizontally(column_header_node, new DLXColumnHeaderNode(0));
                column_header_node = column_header_node->right();
                //column_header_node->data().column_id = static_cast<DLXColumnHeaderNode*>(column_header_node);
            }
            join_node_horizontally(column_header_node, root); // cyclization

            // initialize m x n array of DLXMatrixNode pointers
            // note that the type of the element in the array is DLXMatrixNode pointer, so ptr_matrix's type is DLXMatrixNode ***
            DLXMatrixNode ***ptr_matrix = new DLXMatrixNode **[m];
            for (int k = 0; k < m; k++) {
                ptr_matrix[k] = new DLXMatrixNode *[n];
            }

            // 1、create nodes of LMatrix, referenced by pointers in ptr_matrix, also link the nodes vertically
            // 2、append to tail patten
            DLXMatrixNode *tail_node;
            column_header_node = root->right();
            // col_index = column of matrix, row_index = row of matrix
            for (int col_index = 0; col_index < n; col_index++, column_header_node = column_header_node->right()) {
                tail_node = column_header_node;
                for (int row_index = 0; row_index < m; row_index++) {
                    if (matrix[row_index][col_index]) {
                        ptr_matrix[row_index][col_index] = new DLXMatrixNode(
                                DLXMatrixNodeData(row_index, static_cast<DLXColumnHeaderNode *>(column_header_node))
                        );
                        join_node_vertically(ptr_matrix[row_index][col_index], tail_node);
                        tail_node = ptr_matrix[row_index][col_index];
                        (static_cast<DLXColumnHeaderNode *>(column_header_node))->add_to_size(1);
                    } else {
                        ptr_matrix[row_index][col_index] = nullptr;
                    }
                }
                join_node_vertically(column_header_node, tail_node); // cyclization
            }

            int row_index;
            // the for-loop below ignores zero rows at the bottom of the matrix
            for (row_index = m - 1; row_index >= 0; row_index--) {
                bool zero_node_in_row_flag = true;
                for (int col_index = 0; col_index < n; col_index++) {
                    if (matrix[row_index][col_index]) {
                        zero_node_in_row_flag = false;
                        break;
                    }
                }
                if (!zero_node_in_row_flag) break;
            }
            // 'row_index' is now the index of the last non-zero row, or -1 if there are no non-zero rows
            row_count = row_index + 1;
            // link the nodes horizontally
            DLXMatrixNode *first_node_of_row, *prev_node;
            // row_index = row, j = column
            for (; row_index >= 0; row_index--) {
                first_node_of_row = nullptr;
                for (int col_index = 0; col_index < n; col_index++) {
                    // find first_node_of_row non-zero matrix entry in row row_index,
                    // and make 'first_node_of_row' point to the corresponding node
                    if (ptr_matrix[row_index][col_index] != nullptr) {
                        if (first_node_of_row == nullptr) {
                            first_node_of_row = ptr_matrix[row_index][col_index];
                        } else {
                            join_node_horizontally(prev_node, ptr_matrix[row_index][col_index]);
                        }
                        prev_node = ptr_matrix[row_index][col_index];
                    }
                }
                if (first_node_of_row != nullptr) {  // if row row_index is not a zero row
                    join_node_horizontally(prev_node, first_node_of_row);
                }
            }

            // finished with ptr_matrix, so now delete it
            // note this doesn't delete the nodes of the new LMatrix, just their pointers which 
            // are stored in ptr_matrix
            for (int k = 0; k < m; k++) {
                delete[] ptr_matrix[k];
            }
            delete[] ptr_matrix;

        }

        //!< \return the head node of the matrix (see the detailed class description).
        DLXMatrixNode *head() const {
            return root;
        }

        bool is_trivial() const; //!< \return 1 if the matrix is empty (ie consists only of a head node), 0 otherwise.
        int number_of_rows() const; //!< \return the number of rows (equivalently, the maximum column size).
        /**
         * @brief Removes the row containing the node @p node.
         * @param node A node of the matrix.
         *
         * Does not alter any left, right, up or down links belonging to nodes in the row.  If the matrix is empty
         * or @p node is \ref head() or a column header, no action is taken.
         *
         * \ref DLXColumnHeaderNode#size() values are updated, but \ref row_id_ values are **not** changed.
         */
        void remove_row(DLXMatrixNode *node);

        /**
         * @brief Undoes the action of \ref DLXIncidenceMatrix#remove_row "remove_row"( @p node).
         *
         * **Precondition** Neither the row containing @c node, nor the calling object have been altered since the
         * last call to \ref remove_row.
         */
        void restore_row(DLXMatrixNode *node);

        /**
         * @brief Removes the column containing the node @p node.
         * @param node A node of the matrix.
         *
         * Removes the entire column, including the column header.  Does not alter any left, right, up or down links belonging to nodes in the column.  If @p node is \ref head(),
         * no action is taken.
         */
        void remove_column(DLXMatrixNode *node);

        /**
         * @brief Undoes the action of \ref DLXIncidenceMatrix#remove_column "remove_column"( @p node).
         *
         * **Precondition** Neither the column containing @c node, nor the calling object have been altered since the
         * last call to \ref remove_column.
         */
        void restore_column(DLXMatrixNode *node);

        ~DLXIncidenceMatrix();

        /**
         * @brief Displays the matrix in ascii format, which is useful for debugging.
         * @param out_stream The output stream of the display.
         *
         * Each line of the display corresponds to a row of the matrix and ends with the row number.  Empty rows are included.
         * The head <tt>M.head()</tt> is represented by the symbol `H', column headers by the symbol `C', and all
         * other nodes (ie non-zero matrix entries) by `N'.  Left and right links are represented by the symbols
         * `<' and `>' respectively,
         * and each row is understood to wrap into a circular list.
         *
         * As an example, the matrix
         *
                1 0 1
                0 0 0
                0 1 1
         *
         * when converted to type DLXIncidenceMatrix, will be displayed as
         *
                 ROW DIAGRAM

                 >H<>C<>C<>C<    row -1
                    >N<   >N<    row 0
                                 row 1
                       >N<>N<    row 2
         *
         * Multiple @c assert statements will be made during the process of creating the display.  These
         * will check the structure of the matrix (including the up/down links, which are not displayed).
         *
         * Following the display of the matrix, the column sizes will be displayed in sequence.  For the above example,
                 COLUMN SIZES

                 >1<>1<>2<

        will be displayed.  This can be used to check that the \ref DLXColumnHeaderNode#size() values are correct.
         */
        void DEBUG_display(std::ostream &out_stream = std::cout);

    private:
        DLXMatrixNode *root; // dummy node
        int row_count;      // 1 plus the index of the last nonzero row index of the ORIGINAL matrix
        // set in the constructor and not ever modified
        // only needed for DEBUG_display()
        // note: if many rows have been deleted from the matrix, this could well be unnecessarily large.
    };
};


#endif //EXACTCOVERSOLVER_DLXINCIDENCEMATRIX_H
