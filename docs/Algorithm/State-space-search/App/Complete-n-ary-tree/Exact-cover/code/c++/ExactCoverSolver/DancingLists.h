//
// Created by kai on 2023/6/18.
//

#ifndef EXACTCOVERSOLVER_DANCINGLISTS_H
#define EXACTCOVERSOLVER_DANCINGLISTS_H
#include <iostream>

namespace kai_exact_cover_solver {
    /**
     * \brief A node containing data of variable type @c T and four links to other nodes - left, right, up and down.
     *
     */
    template<class T>
    class Node {
    public:
        Node(const T &theData,
             Node<T> *theRight = nullptr,
             Node<T> *theLeft = nullptr,
             Node<T> *theUp = nullptr,
             Node<T> *theDown = nullptr)
                : data_(theData), right_(theRight), left_(theLeft), up_(theUp), down_(theDown) {}

        void set_data(const T &theData) { data_ = theData; } //!< Sets the node's data to @p theData.
        T &data() const { return const_cast<T &>(data_); } //!< \return the data object.
        // don't know why I have to cast the argument, but compiler otherwise complains
        Node<T> *right() const { return right_; } //!< \return the right link.
        Node<T> *left() const { return left_; } //!< \return the left link.
        Node<T> *up() const { return up_; } //!< \return the up link.
        Node<T> *down() const { return down_; } //!< \return the down link.
        void set_right(Node<T> *node) { right_ = node; } //!< Points the right link to @c node.
        void set_left(Node<T> *node) { left_ = node; } //!< Points the left link to @c node.
        void set_up(Node<T> *node) { up_ = node; } //!< Points the up link to @c node.
        void set_down(Node<T> *node) { down_ = node; } //!< Points the down link to @c node.
    private:
        T data_;
        Node<T> *right_;
        Node<T> *left_;
        Node<T> *up_;
        Node<T> *down_;
    };


    /**
     * \brief Implementation of a matrix as a linked data structure.
     *
     * An efficient implementation of a boolean matrix, used in a solution of the Exact Cover Problem.
     * This implementation only stores non-zero entries, and is especially suitable for sparse matrices.
     * Moreover, rows and columns are represented as circular doubly linked lists, so as to be naturally
     * amenable to the so-called ``Dancing Links'' algorithm of D. Knuth.
     *
     * The following is a helpful illustration of the IncidenceMatrix data structure taken from [this article](https://arxiv.org/pdf/cs/0011047.pdf) by Knuth.
     * ![An image of a linked matrix](../images/linked_matrix_image_(Knuth).png)
     *
     * The data structure consists of a *root* or *head* node (got by calling \ref head() ) which is linked to the
     * *column headers* (objects of type \ref Column ), each of which represents a column of the matrix and whose
     * \ref Column#size() records the number of 1's in that column. Each 1 is represented by an object of type
     * \ref MNode, and each row and column (including the header) is a circular doubly linked list.
     *
     * For each node, \ref MData#column_id points to the column header, and \ref MData#row_id is the row index.  The
     * values of the row index are determined by the matrix passed as an argument to the constructor - gaps in the
     * row index values of an \ref IncidenceMatrix reflect zero rows in the original matrix.  For
     * column headers, \ref MData#row_id = -1.  Also for \ref head(), \ref MData#column_id = @c NULL.
     *
     * @see dancing_links.h, \ref dancing_links_GJK::Exact_Cover_Solver
     */
    class IncidenceMatrix {
    public:
        IncidenceMatrix(); //!< Creates an empty matrix.
        /**
         * @brief Converts a standard boolean matrix to \ref IncidenceMatrix form.
         * @param matrix A boolean matrix.
         * @param m The number of rows in @p matrix.
         * @param n The number of columns in @p matrix.
         */
        IncidenceMatrix(bool **matrix, int m, int n);

        MNode *head() const; //!< \return the head node of the matrix (see the detailed class description).
        bool is_trivial() const; //!< \return 1 if the matrix is empty (ie consists only of a head node), 0 otherwise.
        int number_of_rows() const; //!< \return the number of rows (equivalently, the maximum column size).
        /**
         * @brief Removes the row containing the node @p node.
         * @param node A node of the matrix.
         *
         * Does not alter any left, right, up or down links belonging to nodes in the row.  If the matrix is empty
         * or @p node is \ref head() or a column header, no action is taken.
         *
         * \ref Column#size() values are updated, but \ref row_id values are **not** changed.
         */
        void remove_row(MNode *node);

        /**
         * @brief Undoes the action of \ref IncidenceMatrix#remove_row "remove_row"( @p node).
         *
         * **Precondition** Neither the row containing @c node, nor the calling object have been altered since the
         * last call to \ref remove_row.
         */
        void restore_row(MNode *node);

        /**
         * @brief Removes the column containing the node @p node.
         * @param node A node of the matrix.
         *
         * Removes the entire column, including the column header.  Does not alter any left, right, up or down links belonging to nodes in the column.  If @p node is \ref head(),
         * no action is taken.
         */
        void remove_column(MNode *node);

        /**
         * @brief Undoes the action of \ref IncidenceMatrix#remove_column "remove_column"( @p node).
         *
         * **Precondition** Neither the column containing @c node, nor the calling object have been altered since the
         * last call to \ref remove_column.
         */
        void restore_column(MNode *node);

        ~IncidenceMatrix();

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
     * when converted to type IncidenceMatrix, will be displayed as
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

    will be displayed.  This can be used to check that the \ref Column#size() values are correct.
     */
        void DEBUG_display(std::ostream &out_stream = std::cout);

    private:
        MNode *root;
        int row_count;      // 1 plus the index of the last nonzero row index of the ORIGINAL matrix
        // set in the constructor and not ever modified
        // only needed for DEBUG_display()
        // note: if many rows have been deleted from the matrix, this could well be unnecessarily large.
    };
};


#endif //EXACTCOVERSOLVER_DANCINGLISTS_H
