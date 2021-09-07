#include <iostream>
#include <cmath>
#include <list>

using namespace std;

void sieveOfEratosthenes(const long size, list<long> & primes){

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
            primes.push_back(j);
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

void PrimeFactor(long size, const list<long> & primes, list<long> & primeFactors){

    long root = sqrt(size);

    for(auto it=primes.begin(); it != primes.end(); ++it){
        if(*it <= root){
            if(size % (*it) == 0){
                primeFactors.push_back(*it);
            }
        }
        else
            break;
    }

    return;
}

long LPF(long number){
    long prime = 2;
    long max = 1;

    // PRIMFAKTORZERLEGUNG VON UNTEN
    // -> Zuerst durch 2,3,5, .. teilen und Rest betrachten

    while(prime <= number){
        // d.h. teilbar durch diesen Wert
        if(number % prime == 0){
            max = prime;
            number = number / prime;
        }
        else
            // Kann nach mehreren Teilungen durch 2 zB nicht mehr durch 4 teilbar sein
            prime++;
    }
    return max;

}

const long SIZE = 25;
const bool DEBUG = false;
const long x = 600851475143;

int main(){
    
    list<long> primes;
    list<long> primeFactors;
    
    sieveOfEratosthenes(SIZE,primes);
    if(DEBUG){
        for(auto it=primes.begin(); it != primes.end(); ++it){
            cout << *it << " ";
        }
        cout << endl << endl;
    }
    
    PrimeFactor(SIZE, primes, primeFactors);
    cout << "Primfaktor von " << SIZE << " sind ";
    for(auto it=primeFactors.begin(); it != primeFactors.end(); ++it){
        cout << *it << " ";
    }
    cout << endl << endl;

    long g = primeFactors.back();
    cout << "Der groesste Primfaktor von " << SIZE << " ist " << g << endl;

    cout << "Der groesste Primfaktor von " << x << " ist " << LPF(x) << endl;
}