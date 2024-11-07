#include <iostream>
#include <iomanip>
using namespace std;

// Subtotal: $     10.00
//      Tax: $      0.50
//      Tip: $      2.00
//            ==========
//    Total: $     12.50
//def print_receipt(subtotal, tax_rate, tip_rate):
//    """
//    Prints the bottom portion of a bill/receipt to stdout
//
//    Args:
//        float subtotal
//        float tax_rate
//        float tip_rate
//    Returns:
//        void
void print_receipt(double subtotal, double tax_rate, double tip_rate){
    double tax = tax_rate * subtotal;
    double tip = subtotal * tip_rate;
    double total = subtotal + tip + tax;
    cout << "Subtotal: $" << setw(10) << subtotal << setprecision(2) << endl;
    cout << "     Tax: $" << setw(10) << tax << setprecision(2) << endl;
    cout << "     Tip: $" << setw(10) << tip << setprecision(2) << endl;
    cout << "           " << setw(10) << setfill('=')  << "" << endl << setfill(' ');
    cout << "   Total: $" << setw(10) << total << setprecision(2) << endl;
}

int main() {
    print_receipt(10.00,.05,.2);
    cout << endl;
    print_receipt(12500.50,.06,.22);
}