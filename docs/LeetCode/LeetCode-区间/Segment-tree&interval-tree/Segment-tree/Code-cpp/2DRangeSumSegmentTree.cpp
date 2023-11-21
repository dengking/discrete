#include <vector>

using namespace std;

class RangeSumSegmentTree2D {
    std::vector<std::vector<int>> tree_;
    const std::vector<std::vector<int>> &matrix_;
    int rowCnt_;
    int colCnt_;
public:
    RangeSumSegmentTree2D(const std::vector<std::vector<int>> &matrix) : matrix_{matrix} {
        rowCnt_ = matrix.size();
        colCnt_ = matrix[0].size();
        tree_.reserve(rowCnt_ * 4);
        for (int i = 0; i < rowCnt_ * 4; ++i) {
            tree_.emplace_back(colCnt_ * 4);
        }
        buildTreeRow(0, 0, rowCnt_ - 1);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumRow(0, 0, rowCnt_ - 1, row1, col1, row2, col2);
    }

private:
    void buildTreeRow(int rowRoot, int rowLo, int rowHi) {
        if (rowLo != rowHi) {
            int mid = rowLo + (rowHi - rowLo) / 2;
            buildTreeRow(rowRoot * 2 + 1, rowLo, mid);
            buildTreeRow(rowRoot * 2 + 2, mid + 1, rowHi);
        }
        buildTreeCol(rowRoot, rowLo, rowHi, 0, 0, colCnt_ - 1);
    }

    void buildTreeCol(int rowRoot, int rowLo, int rowHi, int colRoot, int colLo, int colHi) {
        if (colLo == colHi) {
            if (rowLo == rowHi) {
                tree_[rowRoot][colRoot] = matrix_[rowLo][colLo];
            } else {
                tree_[rowRoot][colRoot] = tree_[rowRoot * 2 + 1][colRoot] + tree_[rowRoot * 2 + 2][colRoot];
            }
        } else {
            int mid = colLo + (colHi - colLo) / 2;
            buildTreeCol(rowRoot, rowLo, rowHi, colRoot * 2 + 1, colLo, mid);
            buildTreeCol(rowRoot, rowLo, rowHi, colRoot * 2 + 2, mid + 1, colHi);
            tree_[rowRoot][colRoot] = tree_[rowRoot][colRoot * 2 + 1] + tree_[rowRoot][colRoot * 2 + 2];
        }
    }

    int sumRow(int rowRoot, int rowLo, int rowHi, int row1, int row2, int col1, int col2) {
        if (row1 > row2) {
            return 0;
        }
        if (rowLo == row1 && rowHi == row2) {
            return sumCol(rowRoot, 0, 0, colCnt_ - 1, row1, col1, row2, col2);
        }
        int mid = rowLo + (rowHi - rowLo) / 2;
        return sumRow(rowRoot * 2 + 1, rowLo, mid, row1, min(row2, mid), col1, col2) +
               sumRow(rowRoot * 2 + 2, mid + 1, rowHi, max(row1, mid + 1), row2, col1, col2);
    }

    int sumCol(int rowRoot, int colRoot, int colLo, int colHi, int row1, int row2, int col1, int col2) {

    }
};

class NumMatrix {
    RangeSumSegmentTree2D rangeSumSegmentTree2D;
public:
    NumMatrix(vector<vector<int>> &matrix) : rangeSumSegmentTree2D{matrix} {

    }

    int sumRegion(int row1, int col1, int row2, int col2) {

    }
};
