#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>

bool solved(const std::vector<std::vector<int>> &grid, const std::vector<int> &row_sums, const std::vector<int> &col_sums);
bool solved_q(const std::vector<std::vector<int>> &grid, const std::vector<int> &row_sums, const std::vector<int> &col_sums, int row, int col);
bool solved_row(const std::vector<std::vector<int>> &grid, const std::vector<int> &row_sums, int row);
bool solve(std::vector<std::vector<int>> &grid, const std::vector<int> &row_sums, const std::vector<int> &col_sums, int row, int col, std::vector<bool> &used);

#endif // SOLVER_HPP
