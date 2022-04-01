#include <iostream>
#include <set>
#include <cmath>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 1000;

void sieveOfEratosthenes(const long size, set<long> & primes){

    bool arr[size];
    long root = sqrt(size);
    for(long i=0; i<size; i++)
        arr[i] = true;
    
    arr[0] = false;
    arr[1] = false;

    // Laufe über alle möglichen Kandidaten von Primfaktoren
    for(long j=2; j<size; j++){
        if(arr[j] == true){
            // j ist Primzahl
            primes.insert(j);
            // Setze alle Vielfachen von j auf false
            for(long k = 2*j; k<size; k=k+j){
                arr[k] = false;
            }
        }
        else{
            // Überspringen
        }
    }

    return;
}

int main(){
    clock_t start = clock();
    
    // FORMULA
    // n*n + |a|*n + |b| = PRIMZAHL     |a| <= 100
    //                                  |b| <= 100

    set<long> primes;
    sieveOfEratosthenes(100000, primes); 

    int nMax = 0;
    int aMax = 0;
    int bMax = 0;

    int n = 0;
    int curPrime = 0;

    for(int a=-SIZE; a<=SIZE; a++){
        for(int b=-SIZE; b<=SIZE; b++){

            

            while(true){
                curPrime = n*n + a*n + b;
                if(primes.count(curPrime) == 0){
                    if(n > nMax){
                        nMax = n-1;
                        aMax = a;
                        bMax = b;
                    }
                    // cout << a << " " << b << " " << n << endl;
                    n = 0;
                    break;
                }
                n++;
            }

        }
    }

    cout << aMax << " " << bMax << " " << nMax << endl;
    cout << "Product of Coefficients = " << aMax*bMax << endl;
    


    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;

    return 0;
}