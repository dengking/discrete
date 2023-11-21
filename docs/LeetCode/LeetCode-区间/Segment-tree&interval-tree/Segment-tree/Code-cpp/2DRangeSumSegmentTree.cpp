#include <vector>

using namespace std;

class RangeSumSegmentTree2D {
    std::vector<std::vector<int>> tree_;
    const std::vector<std::vector<int>> &matrix_;
public:
    RangeSumSegmentTree2D(const std::vector<std::vector<int>> &matrix) : matrix_{matrix} {
        int rowCnt = matrix.size();
        int colCnt = matrix[0].size();
        tree_.reserve(rowCnt * 4);
        for (int i = 0; i < rowCnt * 4; ++i) {
            tree_.emplace_back(colCnt * 4);
        }
        buildTreeRow(0, 0, rowCnt - 1);
    }

private:
    void buildTreeRow(int rowRoot, int rowLo, int rowHi) {
        if (rowLo != rowHi) {
            int mid = rowLo + (rowHi - rowLo) / 2;
            buildTreeRow(rowRoot * 2 + 1, rowLo, mid);
            buildTreeRow(rowRoot * 2 + 2, mid + 1, rowHi);
        }
        buildTreeCol(rowRoot, rowLo, rowHi, 0, 0, matrix_[0].size() - 1);
    }

    void buildTreeCol(int rowRoot, int rowLo, int rowHi, int colRoot, int colLo, int colHi) {

    }
};

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {

    }

    int sumRegion(int row1, int col1, int row2, int col2) {

    }
};
