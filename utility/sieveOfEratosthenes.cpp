#include <iostream>
#include <vector>
#include <set>

template<typename T>
void sieveOfEratosthenes(const T size, std::vector<T> & primes){

    bool arr[size];
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

template<typename T>
void sieveOfEratosthenes(const T size, std::set<T> & primes){

    bool arr[size];
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