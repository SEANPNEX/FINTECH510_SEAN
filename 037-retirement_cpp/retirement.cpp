#include <iostream>
#include <fstream>
#include <iomanip>  // For formatting the output
using namespace std;

class RetireInfo {
    public:
    int months;
    double contribution;
    double rate_of_return;
};


pair<int, double> update_stage(int age, double saving, double ror, double contribution){
    cout << "Age " << setw(3) << age / 12 << " month " << setw(2) << age % 12 << " you have $" << fixed << setprecision(2) << saving << endl;
    
    ofstream outfile;
    outfile.open("ans.txt", ios_base::app);
    outfile << "Age " << setw(3) << age / 12 << " month " << setw(2) << age % 12 << " you have $" << fixed << setprecision(2) << saving << endl;
    outfile.close();
    
    age += 1;
    saving = (1 + ror / (12 * 100)) * saving + contribution;
    return make_pair(age, saving);
}


/**
* @brief Calculates and prints the current balance as an individual works and retires
*
* @param startAge The time in months when the model beings
* @param initial The initial amount of savings an individual has
* @param working Details for the model about how long an individual  works with savings and investment gains
* @param retired Details for the model about how long the individual lives in retirement with expenditures and continued investment gains
*/
void retirement (int startAge, double initial, RetireInfo working, RetireInfo retired){
    int age = startAge;
    double saving = initial;

    for (int m = 0; m < working.months; ++m){
        tie(age, saving) = update_stage(age, saving, working.rate_of_return, working.contribution);
    }
    for (int m = 0; m < retired.months; ++m){
        tie(age, saving) = update_stage(age, saving, retired.rate_of_return, retired.contribution);
    }
}

int main(){
    RetireInfo working, retired;
    working.months = 489;
    working.contribution = 1000;
    working.rate_of_return = 4.5;
    retired.months = 384;
    retired.contribution = -4000;
    retired.rate_of_return = 1;

    retirement(327, 21345, working, retired);

    return 0;
}