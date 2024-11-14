# include <vector>
# include <list>
# include <iostream>
#include <iterator>
#include <typeinfo>
using namespace std;


template <typename Container>
void print(const Container &container) {
    cout << "{";
    auto it = std::begin(container);  
    while (it != std::end(container)) {  
        cout << *it;
        ++it;
        if (it != std::end(container)) {
            cout << ", ";
        }
    }
    cout << "}\n";
}
template<typename Iter1, typename Iter2>
Iter2 copy2(Iter1 f1, Iter1 e1, Iter2 f2){
    while(f1!=e1){
        *f2 =*f1;
        ++f1;
        ++f2;
    }
    return f2;
}


int main() {
    int arr_begin[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int *arr = arr_begin;
    std::vector<int> vec{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::list<int> lst{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    auto it_vec = vec.begin();
    auto it_lst = lst.begin();

    while (it_lst != lst.end() && arr < arr_begin + 10 && it_vec != vec.end()) {
        *arr += 2;
        *it_vec += 3;
        *it_lst += 5;
        ++it_lst;
        ++arr;
        ++it_vec;
    }

    arr = arr_begin;
    copy2(arr, arr + 10, vec.begin());

    it_lst = lst.begin();
    copy2(it_lst, std::next(it_lst, 10), arr);

    cout << "array: ";
    print(arr_begin);

    cout << "vector: ";
    print(vec);

    cout << "list: ";
    print(lst);

    return 0;
}
