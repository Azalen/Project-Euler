#include <iostream>
#include "bigInt.h"

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

/**
 *      1 + 1 = 2
 *      1 + 2 = 3
 *      2 + 3 = 5
 * 
 * */


int main(){
    
    int n = 1005;
    int lookupDigit = 1000;

    BigInt temp(n);

    // FIBONACCI START
    BigInt pre(n);
    BigInt now(n);
    now.addBigInt(pre);
    int counter = 3;

    // FIBONACCI SEQUENCE ON BIG INT
    while(!now.checkDigit(lookupDigit)){
        temp.assign(now);
        now.addBigInt(pre);
        pre.assign(temp);
        counter++;
    }

    cout << counter << endl;

    
    
    



    return 0;
}