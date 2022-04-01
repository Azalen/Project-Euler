#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <utility>

using namespace std;

const bool  DEBUG   = true;
const int   SIZE    = 1000;

int getRepCycleLength(int val){
    int depth = 1000;
    
    int cycle = 0;

    vector<pair<int,int>> ms;

    bool endDivision = false;
    int dividend = 1;
    int divisor = val;
    int quotient = -1;
    int remainder = -1;

    for(int i = 1; i<depth; i++){
        
        // INT DIVISION
        quotient = dividend / divisor;
        remainder = dividend - (quotient*divisor);


        if(remainder == 0){
            // END OF DIVISION -> NO CYCLE
            return 0;
        }
        
        // DIVISION CONTINUES INTO NEXT LOOP
        dividend = remainder * 10;
        
        
        // A CYCLE ENDS WHEN PAIR OF QUOTIENT & REMAINDER ARE THE SAME
        pair<int, int> divisionPair;
        divisionPair.first = quotient;
        divisionPair.second = remainder;

        // CHECK ALL PRIOR DIVISION PAIRS FOR EQUALITY
        for(int j = 0; j<ms.size(); j++){
            if( ms[j] == divisionPair ){
                return (i-j-1);
            }
        }

        // PUSH CURRENT DIVISION PAIR
        ms.push_back(divisionPair);

    }
    throw runtime_error("digit overflow");
    return -1;
}

int main(){
    
    int max = 0;
    int d = -1;

    for(int i = 1; i < 1000; i++){
        int cur = getRepCycleLength(i);
        if(cur > max){
            d = i;
            max = cur;
        }
    }

    cout << "d = " << d << endl;

    return 0;
}