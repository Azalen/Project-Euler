#include <iostream>
#include <ctime>
#include <string>
#include "../../utility/sieveOfEratosthenes.cpp"
#include <cmath>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 1000000;

int reverse(int number){
    int rev = 0;
    int remainder = 0;
    
    while(number != 0){
        remainder = number % 10;
        rev = rev * 10 + remainder;
        number /= 10;
    }

    return rev;
}

bool isTruncatableLeftToRight(int number, set<int> & primes){
    do{

        number = number / 10;
        if(primes.count(number) != 1)
            return false;

    }while(number > 9);
    return true;
}

bool isTruncatableRightToLeft(int number, set<int> & primes){
    do{

        string num = to_string(number);
        num.erase(num.begin(),num.begin()+1);
        number = stoi(num);

        if(primes.count(number) != 1)
            return false;

    }while(number > 9);
    return true;
}

int main(){
    
    long long amountUniqueComputations = 0;
    clock_t start = clock();
    
    set<int> primes;
    sieveOfEratosthenes(SIZE, primes);

    int sumOfTruncatable = 0;
    int count = 0;
    for(auto it = primes.begin(); it != primes.end(); ++it){
        if(isTruncatableLeftToRight(*it, primes)){
            if(isTruncatableRightToLeft(*it, primes)){
                count++;
                sumOfTruncatable += *it;
                cout << *it << " ";
            }
        }
    }

    cout << endl;
    cout << "- count = " << count << endl;
    cout << "- sum of truncatable = " << sumOfTruncatable << endl;
    cout << endl;


    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "unique Computations: " << amountUniqueComputations << endl;
    return 0;
}