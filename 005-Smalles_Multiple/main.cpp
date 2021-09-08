#include <iostream>

using namespace std;

const bool DEBUG = false;

// Euklidischer Algorithmus - Klassiche Version
// Betrachte größere Zahl und ziehe die kleinere von ihr ab solange, bis nicht mehr größer
// Danach selbe Methode nur, das ursprünglich kleinere Zahl nun die größere Zahl ist
// Tue dies solange, bis eine Zahl Null ist

long euklidClassic(long a, long b){
    if(a == 0)
        return b;

    while(b != 0){
        // In dieser Implementierung liegt der Trick im > anstatt >= -> somit wird a am Ende immer größer sein als b, d.h. mindestens 1
        if(a>b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

// Der moderne Euklidische Algorithmus benutzt anstelle mehrfacher Subtraktionen direkt Modulo um den Differenzwert zu errechnen
long euklidModern(long a, long b){
    long r;

    while(b != 0 && a != 0){
        if(DEBUG)
            cout << "a = " << a << " b = " << b << endl;

        if(a>b){
            r = a % b;
            a = r;
        }
        else{
            r = b % a;
            b = r;
        }
    }
    if(DEBUG)
        cout << "a = " << a << " b = " << b << endl;
    if(a > b)
        return a;
    return b;
}

// GCD = Greatest Common Divisor
long ggT(long a, long b){
    if(a >= 0 && b >= 0)
        return euklidModern(a,b);
    else
        cout << "Negative Zahlen nicht erlaubt" << endl;
    return -1;
}


// LCM = Least Common Multiple
// kgV(a,b) * ggT(a,b) = a*b
long kgV(long a, long b){
    long mult = a*b;
    return double(mult)/ggT(a,b);
}


long smallestMultiple(long size){
    long sum = 1;

    for(long i=2; i<=size; i++){
        if(DEBUG)
            cout << "kgV(" << sum << "," << i << ") = ";
        sum = kgV(sum,i);
        
            cout << sum << endl;
    }
    return sum;
}


int main(){

    long SIZE = 20;

    long x = smallestMultiple(SIZE);

    cout << "Die kleinste Zahl, welche durch alle Zahlen von 1 bis " << SIZE << " teilbar ist, ist " << x << endl;
    return 1;
}