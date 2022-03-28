#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 10000;

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

void printMap(const map<int,int> & toPrint){
    for(auto it=toPrint.begin(); it != toPrint.end(); ++it){
        cout << setw(5) << (*it).first << " / " << setw(5) << (*it).second << endl;
    }
}

int main(){
    
    map<int, int> divisorSums;

    for(int i=1; i<= SIZE; i++){
        divisorSums[i] = calcDivisorSum(i);
    }

    if(DEBUG)
        printMap(divisorSums);
    
    vector<int> amicableNumbers;

    for(int a=1; a<= SIZE; a++){
        int b = divisorSums[a];
        if(divisorSums[b] == a && a != b){
            if(DEBUG){
                cout << a << " " << divisorSums[a] << " " << divisorSums[divisorSums[a]] << endl;
            }
            amicableNumbers.push_back(a);
        }
    }

    int sumOfAmicable = 0;
    for(auto it=amicableNumbers.begin(); it != amicableNumbers.end(); ++it){
        cout << *it << " ";
        sumOfAmicable += *it;
    }
    cout << endl;

    cout << "Sum of Amicable Numbers under " << SIZE << " = " << sumOfAmicable << endl;

    return 0;
}