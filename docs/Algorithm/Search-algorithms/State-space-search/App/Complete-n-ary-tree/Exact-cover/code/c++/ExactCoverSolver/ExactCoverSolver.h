//
// Created by kai on 2023/6/18.
//

#ifndef EXACTCOVERSOLVER_EXACTCOVERSOLVER_H
#define EXACTCOVERSOLVER_EXACTCOVERSOLVER_H

#include <vector>

namespace kai_exact_cover_solver {

    class ExactCoverSolver {
    public:
        virtual std::vector<int> solve(bool **incidence_matrix, int m, int n) = 0;
    };

}

#endif //EXACTCOVERSOLVER_EXACTCOVERSOLVER_H
