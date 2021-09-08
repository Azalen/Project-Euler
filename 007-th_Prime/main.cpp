#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

const bool DEBUG = false;

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

    int SIZE = 150000;
    int n = 10001;

    vector<long> v;
    sieveOfEratosthenes(SIZE, v);

    cout << "Die " << n << "-te Primzahl ist " << v[n-1]<< endl;
    return 1;
}