//
// Created by kai on 2023/6/18.
//

#ifndef EXACTCOVERSOLVER_DLX_H
#define EXACTCOVERSOLVER_DLX_H

#include <vector>
#include <stack>
#include "ExactCoverSolver.h"
#include "DLXIncidenceMatrix.h"

namespace kai_exact_cover_solver {

    /**
     * \brief Knuth's Algorithm X
     * see also:
     * - https://en.wikipedia.org/wiki/Knuth%27s_Algorithm_X
     */
    class DLX : public ExactCoverSolver {
        typedef std::vector<int> SolutionStack;
        enum class RowColumnTag {
            row, column
        };
        /**
         * \brief Holds the data of a row or column removal (of a matrix determined by context).
         * Whether a row or column was removed is determined by \ref HistoryRecord#type.
         * The field \ref HistoryRecord#node records the node which was passed to \ref DLXIncidenceMatrix#remove_row or \ref DLXIncidenceMatrix#remove_column.
         */
        struct HistoryRecord {
            DLXMatrixNode *node_;
            RowColumnTag type_;
        };

        //! Each \ref HistoryStack is to hold the data accumulated by a single call to \ref update().
        typedef std::stack<HistoryRecord> HistoryStack;

        /**
        * \brief A class used to represent the history of a solution finding process (depth first search).
        */
        typedef std::stack<HistoryStack> AllHistoryStack;
    public:

        std::vector<int> solve(bool **bool_matrix, int m, int n) override {
            DLXIncidenceMatrix incidence_matrix = DLXIncidenceMatrix(bool_matrix, m, n);
            AllHistoryStack allHistory;
            std::vector<int> solution;
            solution.reserve(m);
            DLX_solve(incidence_matrix, solution, allHistory);
            solution.shrink_to_fit();
            return solution;
        }

    private:
        /* Given a matrix of linked nodes incidence_matrix, return a pointer to the column with the fewest nodes
         * If there are no columns, return NULL
         */
        DLXColumnHeaderNode *choose_column(DLXIncidenceMatrix &incidence_matrix) {
            if (incidence_matrix.is_trivial()) return nullptr;

            DLXColumnHeaderNode *col = static_cast<DLXColumnHeaderNode *>(incidence_matrix.head()->right());
            DLXColumnHeaderNode *max_col = col;

            while (col != incidence_matrix.head()) {
                if (col->size() < max_col->size()) {
                    max_col = col;
                }
                col = static_cast<DLXColumnHeaderNode *>(col->right());
            }
            return max_col;
        }

        /**
         * 
         * @param incidence_matrix 
         * @param solution 
         * @param allHistory 
         * @return 
         * true: solution successfully found
         */
        bool DLX_solve(DLXIncidenceMatrix &incidence_matrix, SolutionStack &solution, AllHistoryStack &allHistory) {
            DLXColumnHeaderNode *column_header = choose_column(incidence_matrix);
            // 'incidence_matrix' is empty => solution successfully found
            if (column_header == nullptr) {
                return true;
            }
            for (DLXMatrixNode *row_node = column_header->down();
                 row_node != static_cast<DLXMatrixNode *>(column_header); row_node = row_node->down()) {
                update(incidence_matrix, solution, allHistory, row_node);
                if (DLX_solve(incidence_matrix, solution, allHistory)) {
                    return true;
                } else {
                    downdate(incidence_matrix, solution, allHistory);
                }
            }
            // no solution exists
            return false;
        }


        /*
         *
         */
        void update(DLXIncidenceMatrix &M, SolutionStack &solution, AllHistoryStack &history, DLXMatrixNode *row_node) {
            solution.push_back(row_node->data().row_id_);

            HistoryStack temp_stack;
            HistoryRecord temp_item{};

            for (DLXMatrixNode *i = row_node->right(); i != row_node; i = i->right()) {
                for (DLXMatrixNode *j = i->up(); j != i; j = j->up()) {
                    if (j->data().column_header_ == j) continue;
                    M.remove_row(j);
                    temp_item.node_ = j;
                    temp_item.type_ = RowColumnTag::row;
                    temp_stack.push(temp_item);
                }
                M.remove_column(i);
                temp_item.node_ = i;
                temp_item.type_ = RowColumnTag::column;
                temp_stack.push(temp_item);
            }

            for (DLXMatrixNode *j = row_node->up(); j != row_node; j = j->up()) {
                if (j->data().column_header_ == j) continue;
                M.remove_row(j);
                temp_item.node_ = j;
                temp_item.type_ = RowColumnTag::row;
                temp_stack.push(temp_item);
            }
            M.remove_column(row_node);
            temp_item.node_ = row_node;
            temp_item.type_ = RowColumnTag::column;
            temp_stack.push(temp_item);

            history.push(temp_stack);
        }


        /*
         * Undoes the operations of 'update'
         */
        void downdate(DLXIncidenceMatrix &M, SolutionStack &solution, AllHistoryStack &history) {
            if (history.empty()) {
                return;
            }
            solution.pop_back();
            HistoryStack last = history.top();
            HistoryRecord it;
            while (!last.empty()) {
                it = last.top();
                if (it.type_ == RowColumnTag::row) {
                    M.restore_row(it.node_);
                } else if (it.type_ == RowColumnTag::column) {
                    M.restore_column(it.node_);
                }
                last.pop();
            }
            history.pop();
        }
    };
}

#endif //EXACTCOVERSOLVER_DLX_H
