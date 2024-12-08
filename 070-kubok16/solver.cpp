#include "solver.hpp"
#include <iostream>

// full answer validator
bool solved(const std::vector<std::vector<int>> &grid, const std::vector<int> &row_sums, const std::vector<int> &col_sums) {
    for (int i = 0; i < 4; ++i) {
        int row_sum = std::accumulate(grid[i].begin(), grid[i].end(), 0);
        int col_sum = std::accumulate(grid.begin(), grid.end(), 0, [i](int sum, const std::vector<int> &row) {
            return sum + row[i];
        });
        if (row_sum != row_sums[i] || col_sum != col_sums[i]) {
            return false;
        }
    }
    return true;
}

// quick validator (for performance sake compared to the full validator)
bool solved_q(const std::vector<std::vector<int>> &grid, const std::vector<int> &row_sums, const std::vector<int> &col_sums, int row, int col) {
    int row_sum = 0, col_sum = 0, row_zeros = 0, col_zeros = 0;

    for (int i = 0; i < 4; ++i) {
        row_zeros += (grid[row][i] == 0);
        col_zeros += (grid[i][col] == 0);
        row_sum += grid[row][i];
        col_sum += grid[i][col];
    }

    if (row_sum > row_sums[row] || col_sum > col_sums[col]) {
        return false;
    }
    if ((row_zeros == 0 && row_sum != row_sums[row]) || (col_zeros == 0 && col_sum != col_sums[col])) {
        return false;
    }
    return true;
}

// single row validator
bool solved_row(const std::vector<std::vector<int>> &grid, const std::vector<int> &row_sums, int row) {
    if (row < 0 || row >= (int)grid.size()) {
        throw std::out_of_range("Invalid row index.");
    }
    int row_sum = std::accumulate(grid[row].begin(), grid[row].end(), 0);
    return row_sums[row] == row_sum;
}

// recursive solver
bool solve(std::vector<std::vector<int>> &grid, const std::vector<int> &row_sums, const std::vector<int> &col_sums, int row, int col, std::vector<bool> &used) {
    // reach the end of the tree
    if (row == 4) {
        return solved(grid, row_sums, col_sums);
    }
    // validate row and go to next
    if (col == 4) {
        if (solved_row(grid, row_sums, row)) {
            return solve(grid, row_sums, col_sums, row + 1, 0, used);
        }
        return false;
    }
    // base case: if filled value go to next
    if (grid[row][col] != 0) {
        return solve(grid, row_sums, col_sums, row, col + 1, used);
    }
    // base case: split the tree by trying unused values
    for (int i = 1; i <= 16; ++i) {
        if (used[i - 1]) continue;

        grid[row][col] = i;
        used[i - 1] = true;

        if (solved_q(grid, row_sums, col_sums, row, col) && solve(grid, row_sums, col_sums, row, col + 1, used)) {
            return true;
        }

        // solve failed: reset the value to 0
        used[i - 1] = false;
        grid[row][col] = 0;
    }
    return false;
}
