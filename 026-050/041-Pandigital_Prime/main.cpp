#include <iostream>
#include <ctime>
#include <set>
#include <cmath>
#include "../../utility/sieveOfEratosthenes.cpp"

using namespace std;

const bool  DEBUG   = false;

void lexicographicPermutation(int * arr){

}

bool cantBePrime(int i){
    int digit = i % 10;
    if(digit == 2 || digit == 0 || digit == 5 || digit == 4 || digit == 8)
        return true;
    return false;
}

bool isSevenDigitPandigital(int i){
    set<int> digits;
    while(i > 0){
        int digit = i % 10;
        if(digit > 7)
            return false;
        if(digit == 0){
            // zero not allowed for pandigital number
            return false;
        }
            
        if(digits.find(digit) != digits.end()){
            // digit already in the set
            return false;
        }
        digits.insert(digit);
        i = i / 10;
    }
    return true;
}

bool isPrime(int num){
    int root = sqrt(num);
    for(int i = 2; i <= root; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int main(){
    
    long long amountUniqueComputations = 0;
    clock_t start = clock();

    /**     FACTS:
     *          - largest pandigital prime supposedly is a 9 digit number
     *          - it cant have 0,2,4,5,6,8 as last digit to be a prime
     * 
     *          - digit sum of 9-digit-pandigital = 45 => always divisible by 3 => never prime
     *          - digit sum of 8-digit-pandigital = 36 => always divisible by 3 => never prime
     *          - digit sum of 7-digit-pandigital = 28 => can be prime
     * 
     *          => SOLUTION MUST BE A 7-digit-pandigital containing only {1,2,3,4,5,6,7}
     * */

    int result = -1;
    for(int i = 7654321; i > 0; i = i-2){
        amountUniqueComputations++;
        if(cantBePrime(i))
            continue;
        if(!isSevenDigitPandigital(i))
            continue;
        if(isPrime(i)){
            result = i;
            break;
        }
    }
    cout << result << endl;
    

    clock_t end = clock();
    double runtime = (end - start)*1000000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ns" << endl;
    cout << "unique loop runs: " << amountUniqueComputations << endl;
    return 0;
}