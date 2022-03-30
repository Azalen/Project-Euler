#include "bigInt.h"

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

int main(){
    
    BigInt bi(200);
    int n = 10;

    for(int i = 2; i <= n; i++){
        bi.multN(i);
    }
    bi.print();
    cout << "Sum of Digits = " << bi.addDigits() << endl;

    return 0;
}