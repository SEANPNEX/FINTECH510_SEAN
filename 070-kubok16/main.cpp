#include "parse.hpp"
#include "solver.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
    string filename;
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        exit(EXIT_FAILURE);
    }

    // Parse and get the problem
    filename = argv[1];
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    vector<vector<int>> grid;
    vector<int> row_sums, col_sums;

    try {
        Parser parser(inputFile);
        parser.parseData();
        grid = parser.getGrid();
        row_sums = parser.getRowSums();
        col_sums = parser.getColumnSums();
    } catch (const std::exception &e) {
        cerr << "Error while parsing the file: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    // Initialize "used" vector based on existing numbers in the grid
    vector<bool> used(16, false);
    for (const auto &row : grid) {
        for (int val : row) {
            if (val != 0) {
                used[val - 1] = true; // Mark the number as used
            }
        }
    }

    // Solve the problem
    if (solve(grid, row_sums, col_sums, 0, 0, used)) {
        // Print column sums
        cout << string(3, ' '); // Padding for the row sum column
        for (const auto &col_sum : col_sums) {
            cout << setw(3) << col_sum;
        }
        cout << endl;

        // Print grid with row sums
        for (int i = 0; i < 4; ++i) {
            cout << setw(3) << row_sums[i]; // Print row sum
            for (int j = 0; j < 4; ++j) {
                cout << setw(3) << grid[i][j]; // Print grid values
            }
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
