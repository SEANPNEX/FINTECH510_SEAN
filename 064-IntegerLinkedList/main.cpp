#include "IntegerLinkedList.hpp"
#include <iostream>
using std::cout;

int main() {
    IntegerLinkedList l = IntegerLinkedList::fromString("1842");
    cout << l << "\n";


    IntegerLinkedList l2 = IntegerLinkedList::fromInt(1842);
    cout << l2 << "\n";

    if (l == l2) {
        cout << "There are equal\n"; 
    }

    IntegerLinkedList l3 = IntegerLinkedList::fromInt(1877);
    if (l3 != l2) {
        cout << "l3 does not equal l2\n"; 
    }

    cout << l +l2 +l3<< "\n";
 
    return EXIT_SUCCESS;
}