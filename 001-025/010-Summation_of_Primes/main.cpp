#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 2000000;

void sieveOfEratosthenes(const long size, vector<long> & primes){

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
            // Setze alle Vielfachen von j auf false, solange j noch kleiner als die Wurzel
            // Ansonsten sind alle schon korrekt gesetzt und der restliche Teil sind Primzahlen
            if(j<root)
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
    
    vector<long> v;
    sieveOfEratosthenes(SIZE, v);

    long sum = 0;
    for(unsigned int i=0; i<v.size(); i++)
        sum += v[i];

    cout << sum << endl;

    return 0;
}