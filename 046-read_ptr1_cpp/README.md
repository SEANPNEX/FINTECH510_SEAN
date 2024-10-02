# Read Pointers

1. Create a file "answer.txt".
2. Execute the code under the instructions by hand as demonstrated with the memory/trace diagrams in class.
3. Write the output in your "answer.txt" file.
4. Take a picture of your diagram.
5. Create a Makefile to compile test.cpp into a program called "test".
6. Execute `./test` and compare the output to that you expected in answer.txt.  Make the necessary corrections to your diagrams and answer.txt.
7. Submit answer.txt, Makefile, and your diagram (this can be png/jpg/pdf) for grading.

[Visualize on PythonTutor](https://pythontutor.com/render.html#code=%23include%20%3Cstring%3E%0A%23include%20%3Ciostream%3E%0Ausing%20namespace%20std%3B%0A%0Aclass%20Link%20%7B%0Apublic%3A%0A%20%20%20%20string%20value%3B%0A%20%20%20%20Link*%20prev%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%0A%20%20%20%20Link*%20succ%3B%0A%20%20%20%20Link%28const%20string%26%20v,%20Link*%20p%20%3D%20nullptr,%20Link*%20s%20%3D%20nullptr%29%20%3A%20value%7Bv%7D,%20prev%7Bp%7D,%20succ%7Bs%7D%20%7B%20%7D%0A%7D%3B%0A%0ALink*%20insert%28Link*%20p,%20Link*%20n%29%20%7B%20%20%20%20%20%20%20//%20insert%20n%20before%20p%3B%20return%20n%0A%20%20%20%20if%20%28n%3D%3Dnullptr%29%20%7B%0A%20%20%20%20%20%20%20%20return%20p%3B%0A%20%20%20%20%7D%0A%20%20%20%20if%20%28p%3D%3Dnullptr%29%20%7B%0A%20%20%20%20%20%20%20%20return%20n%3B%0A%20%20%20%20%7D%0A%20%20%20%20n-%3Esucc%20%3D%20p%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//%20p%20comes%20after%20n%0A%20%20%20%20if%20%28p-%3Eprev%29%20%7B%0A%20%20%20%20%20%20%20%20p-%3Eprev-%3Esucc%20%3D%20n%3B%0A%20%20%20%20%7D%0A%20%20%20%20n-%3Eprev%20%3D%20p-%3Eprev%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//%20p%E2%80%99s%20predecessor%20becomes%20n%E2%80%99s%20predecessor%0A%20%20%20%20p-%3Eprev%20%3D%20n%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//%20n%20becomes%20p%E2%80%99s%20predecessor%0A%20%20%20%20return%20n%3B%0A%7D%0A%0Avoid%20print_all%28Link*%20p%29%20%7B%0A%20%20%20%20cout%20%3C%3C%20%22%7B%20%22%3B%0A%20%20%20%20while%20%28p%29%20%7B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20p-%3Evalue%3B%0A%20%20%20%20%20%20%20%20p%20%3D%20p-%3Esucc%3B%0A%20%20%20%20%20%20%20%20if%20%28p%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22,%20%22%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20cout%20%3C%3C%20%22%20%7D%22%20%3C%3C%20endl%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20Link*%20norse_gods%20%3D%20new%20Link%7B%22Thor%22%7D%3B%0A%20%20%20%20norse_gods%20%3D%20insert%28norse_gods,new%20Link%7B%22Odin%22%7D%29%3B%0A%20%20%20%20norse_gods%20%3D%20insert%28norse_gods,new%20Link%7B%22Freia%22%7D%29%3B%0A%20%20%20%20print_all%28norse_gods%29%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=false&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false)

```c++
#include <string>
#include <iostream>
using namespace std;

class Link {
public:
    string value;
    Link* prev;             
    Link* succ;
    Link(const string& v, Link* p = nullptr, Link* s = nullptr) : value{v}, prev{p}, succ{s} { }
};

Link* insert(Link* p, Link* n) {       // insert n before p; return n
    if (n==nullptr) {
        return p;
    }
    if (p==nullptr) {
        return n;
    }
    n->succ = p;                      // p comes after n
    if (p->prev) {
        p->prev->succ = n;
    }
    n->prev = p->prev;                // p’s predecessor becomes n’s predecessor
    p->prev = n;                      // n becomes p’s predecessor
    return n;
}

void print_all(Link* p) {
    cout << "{ ";
    while (p) {
        cout << p->value;
        p = p->succ;
        if (p) {
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

int main() {
    Link* norse_gods = new Link{"Thor"};
    norse_gods = insert(norse_gods,new Link{"Odin"});
    norse_gods = insert(norse_gods,new Link{"Freia"});
    print_all(norse_gods);
}
``` 
