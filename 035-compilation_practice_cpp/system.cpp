#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::setw;
using std::fixed;
using std::setprecision;

// Note: file contains two errors.  After you fix the first report errors, you
// should see the next error message.
//
// setw and setprecision are used to format output in C++. Any line
// with these functions calls is correct. These functions will be presented
// later in the course.

// The program produces a systematic investment plan table, similar to 
// program demonstrated earlier with Python during the class.


double compute_sip_future_value(double payment, double periodic_interest_rate, int num_payments) {
    return payment * (pow(1 + periodic_interest_rate, num_payments) - 1) / periodic_interest_rate * (1 + periodic_interest_rate);
}

int main() {
    int num_rates = 10;

    // Print the header
    cout << "Value of $1 invested monthly at different interest rates by year\n";
    cout << setw((num_rates * 10 + 6) / 2) << "Interest Rate\n";
    cout << "Year  ";

    // Print the interest rate percentages
    for (int rate = 1; rate <= num_rates; rate++) {
        cout << setw(7) << rate << "%";
    }
    cout << "\n";

    // Calculate and print the future value for each year and rate
    for (int year = 1; year <= 10; year++){
        cout << setw(4) << year << "  ";

        for (int rate = 1; rate <= num_rates; rate++) {
            double periodic_rate = rate / 100.0 / 12.0;
            double gain = compute_sip_future_value(1, periodic_rate, year * 12);
            cout << setw(8) << fixed << setprecision(2) << gain;
        }
        cout << "\n";
    }

    return 0;
}