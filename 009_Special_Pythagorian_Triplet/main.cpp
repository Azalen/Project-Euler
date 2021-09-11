#include <iostream>
#include <cmath>

using namespace std;

const bool  DEBUG   = false;

// sqrt(1000) > 30
const int   SIZE    = 400;
const int   TARGET  = 1000;

int main(){

    long a,b;

    // Wichtig: Muss double sein damit in der if Bedingung im Fall, dass die Wurzel keine Ganzzahl ist auch nur genau == 1000 und nicht 
    //          bspw. == 1000.23 auch als korrekt getriggered wird
    double c;
    
    for(a=1; a<SIZE; a++){
        for(b=a+1; b<SIZE; b++){

            long a2 = a*a;
            long b2 = b*b;

            long squareSum = a2+b2;

            c = sqrt(squareSum);

            if( (a + b + c) == TARGET){
                cout << "a = " << a << " b = " << b << " c = " << c << " | a+b+c = " << a+b+c << endl;
                cout << "a2 = " << a2 << " b2 = " << b2 << " a2+b2 = " << a2+b2 << " c2 = " << c*c << endl;
                long prod = a*b*c;
                cout << "abc = " << prod << endl;
                return 0;
            }
        }
    }
    return 0;
}