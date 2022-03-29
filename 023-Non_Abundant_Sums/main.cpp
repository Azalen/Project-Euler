#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

int calcDivisorSum(int n){

    // find proper divisors of a number
    vector<int> divisors;
    int curNumber = n;
    int curLimit = curNumber / 2;
    if(n == 1){
        curLimit = 1;
    }
    for(int i=1; i<=curLimit; i++){
        if(curNumber % i == 0){
            divisors.push_back(i);
        }
    }

    int sumOfDivs = 0;
    if(DEBUG)
        cout << " i = " << setw(5) << n << " -> Divisors: ";
    for(auto it=divisors.begin(); it != divisors.end(); ++it){
        if(DEBUG)
            cout << *it << " ";
        sumOfDivs += *it;
        
    }
    if(DEBUG)
        cout << endl;
    return sumOfDivs;
}

int main(){
    
    int n = 28123;

    // FIND ALL ABUNDANT NUMBERS AND PUT IN ARRAY
    vector<int> abundantNumbers;
    for(int i = 1; i <= n; i++){
        if(calcDivisorSum(i) > i){
            abundantNumbers.push_back(i);
        }
    }

    int m = abundantNumbers.size();
    cout << "n = " << n << endl;
    cout << "m = " << m << endl;

    // PUT ALL SUMS OF ABUNDANT NUMBERS SMALLER THAN n INTO ARRAY
    // INSERT of SET automatically checks for duplicates (binary search + binary insert)
    set<int> abundantNumbersSums;
    for(int i=0; i<m; i++){
        for(int j=i; j<m; j++){

            int sum = abundantNumbers[i] + abundantNumbers[j];
            if(sum <= n){
                abundantNumbersSums.insert(sum);
            }

        }
    }

    int o = abundantNumbersSums.size();
    cout << "o = " << o << endl;

    // add together all numbers, that arent in the ABUNDANT SUM ARRAY
    int finalSum = 0;
    for(int i = 1; i <= n; i++){
        if(abundantNumbersSums.count(i) == 0){
            finalSum += i;
        }
    }
    cout << "Finale Summe = " << finalSum << endl;

    return 0;
}