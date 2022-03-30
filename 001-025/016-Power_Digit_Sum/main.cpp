#include "bigInt.h"

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

int main(){
    
    int n = 1000;

    BigInt b(n);
    
    for(int i=0; i<n; i++){
        b.mult2();
    }
    // b.print();
    cout << "sum of digits for 2^" << n << " = " << b.addDigits() << endl;

    return 0;
}