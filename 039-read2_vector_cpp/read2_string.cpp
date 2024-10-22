#include <iostream>
#include <vector>
#include <string>
using namespace std;

void someFunction(vector<string> vec) {
  for (auto value : vec) {
    cout << value << " ";
  }
  cout << endl;
}

vector<string> anotherFunction(vector<string> vec) {
  for (size_t step = 0; step < vec.size() - 1; step++) {
    size_t min_idx = step;
    for (size_t i = step + 1; i < vec.size(); i++) {

      if (vec[i] > vec[min_idx])
        min_idx = i;
    }
    // cout << min_idx << step << endl ;
    string temp = vec[min_idx];
    vec[min_idx] = vec[step];
    vec[step] = temp;
    // someFunction(vec);
  }
  return vec;
}

// Driver code
int main(void) {
  vector<string> data = {"Duke", "University", "FinTech", "510"};
  vector<string> revised_data = anotherFunction(data);
  someFunction(revised_data);
}