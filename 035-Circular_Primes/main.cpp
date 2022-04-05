#include <iostream>
#include <ctime>
#include <cmath>
#include <set>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 1000000;

void sieveOfEratosthenes(const long size, set<int> & primes){

    bool arr[size];
    long root = sqrt(size);
    for(long i=0; i<size; i++)
        arr[i] = true;
    
    arr[0] = false;
    arr[1] = false;

    // Laufe über alle möglichen Kandidaten von Primfaktoren
    for(long j=2; j<=size; j++){
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
    
    long long amountUniqueComputations = 0;
    clock_t start = clock();
    
    set<int> primes;
    sieveOfEratosthenes(SIZE,primes);
    int circPrimes = 0;

    for(auto it = primes.begin(); it != primes.end(); ++it){
        bool notPrime = false;
        string num = to_string(*it);
        for(int j = 0; j < num.size()-1; j++){
            num = num + num[0];
            num.erase(num.begin(), num.begin()+1);
            if( primes.find(stoi(num)) == primes.end() ){
                // current rotation is not a prime number
                notPrime = true;
                break;
            }
            
        }
        if(notPrime)
            continue;
        cout << *it << endl;
        circPrimes++;
    }

    cout << "amount of circ Primes below " << SIZE << " = " << circPrimes << endl;

    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "unique Computations: " << amountUniqueComputations << endl;
    return 0;
}