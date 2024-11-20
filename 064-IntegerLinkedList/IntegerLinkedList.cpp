#include "IntegerLinkedList.hpp"
#include <string>
using namespace std;


IntegerLinkedList::IntegerLinkedList(): head(nullptr) {}

IntegerLinkedList::IntegerLinkedList(const IntegerLinkedList &rhs) : head(nullptr) {
    copyNodes(rhs.head);    
}

void IntegerLinkedList::copyNodes(IntegerLinkedListNode* currentRHS) {
    while (currentRHS != nullptr) {
        this->appendDigit(currentRHS->data);
        currentRHS = currentRHS->next;
    }
}

void IntegerLinkedList::deallocateNodes() {
    IntegerLinkedListNode* current = head;
    while(current){
        IntegerLinkedListNode* next = current->next;
        delete current;
        current = next;
    }
}


IntegerLinkedList & IntegerLinkedList::operator=(const IntegerLinkedList &rhs) {
    deallocateNodes();
    copyNodes(rhs.head);
    return *this;
}

IntegerLinkedList::IntegerLinkedList(IntegerLinkedList &&rhs): head(rhs.head) {
    rhs.head = nullptr;
}

IntegerLinkedList & IntegerLinkedList::operator=(IntegerLinkedList &&rhs){
    deallocateNodes();
    head = rhs.head;
    rhs.head = nullptr;

    return *this;
}



IntegerLinkedList::~IntegerLinkedList() {
     deallocateNodes();
}

IntegerLinkedList IntegerLinkedList::operator+(const IntegerLinkedList& rhs) {
    IntegerLinkedList result;

    IntegerLinkedListNode* p1 = this->head;
    IntegerLinkedListNode* p2 = rhs.head;
    int carry = 0;

    // Traverse both lists
    while (p1 || p2 || carry) {
        int sum = carry;

        if (p1) {
            sum += p1->data;
            p1 = p1->next;
        }

        if (p2) {
            sum += p2->data;
            p2 = p2->next;
        }

        carry = sum / 10;             
        result.appendDigit(sum % 10);  
    }

    return result;
}



bool IntegerLinkedList::operator==(const IntegerLinkedList& rhs) const {
    IntegerLinkedListNode* p1 = this->head;
    IntegerLinkedListNode* p2 = rhs.head;
    bool result = 1;
    // Traverse both lists
    while (p1 || p2 ) {
        result &= (p1->data==p2->data);
        p1 = p1->next;
        p2 = p2->next;
    }
    return result;
}

bool IntegerLinkedList::operator!=(const IntegerLinkedList& rhs) const {
    return !(*this==rhs);
}

IntegerLinkedList IntegerLinkedList::fromString(const std::string& s) {
    IntegerLinkedList result;

    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        if (*it < '0' || *it > '9') {
            throw std::invalid_argument("String contains non-digit characters.");
        }

        int digit = *it - '0';  
        result.appendDigit(digit);
    }

    return result;
}

IntegerLinkedList IntegerLinkedList::fromInt(int i) {
    if (i < 0) {
        throw std::invalid_argument("Input integer must be non-negative.");
    }

    IntegerLinkedList result;  

    if (i == 0) {
        result.appendDigit(0);
        return result;
    }
    while (i > 0) {
        int digit = i % 10;         
        result.appendDigit(digit); 
        i /= 10;
    }
    return result;
}




std::ostream& operator<<(std::ostream& s, const IntegerLinkedList& rhs) {

    auto printReverse = [](std::ostream& s, IntegerLinkedListNode* node, auto& printReverseRef) -> void {
        if (!node) return;  
        printReverseRef(s, node->next, printReverseRef);  
        s << node->data; 
    };

    if (!rhs.head) {
        s << "";
    } else {
        printReverse(s, rhs.head, printReverse); 
    }

    return s;
}
