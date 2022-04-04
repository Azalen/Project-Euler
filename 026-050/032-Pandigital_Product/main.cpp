#include <iostream>
#include <ctime>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

bool hasUniqueDigits(int number, multiset<int> & ms){
    do{
        int digit = number % 10;
        
        number = number / 10;
        if(ms.count(digit) > 0){
            // number already included
            return false;
        }
        if(digit == 0){
            return false;
        }
        ms.insert(digit);
    }
    while(number != 0);
    return true;
}

int main(){
    
    

    long long amountUniqueComputations = 0;
    clock_t start = clock();
    
    multiset<int> ms;
    set<int> pandigitalProducts;

    /**     
     *      a * b = c <=> c / b = a <=> Divident / Divisor = Quotient
     * */
    
    for(int divident = 1234; divident < 9876; divident++){
        ms.clear();
        
        // Check if current product is pandigital
        if(!hasUniqueDigits(divident, ms))
            continue;
        
        
        // Check all divisors of product
        
        for(int divisor = 2; divisor <= sqrt(divident); divisor++){

            amountUniqueComputations++;
            
            // Check if true divisor
            if(divident % divisor != 0)
                continue;
            
            multiset<int> msDivisor;
            for(auto it = ms.begin(); it != ms.end(); ++it){
                msDivisor.insert(*it);
            }
            
            // check if divisor pandigital
            if(!hasUniqueDigits(divisor,msDivisor))
                continue;

            if(DEBUG){
                cout << "msDivisor = {";
                for(auto it = msDivisor.begin(); it != msDivisor.end(); ++it){
                    cout << *it << " ";
                }
                cout << "}" << endl;
            }

            

            // Check if quotient is pandigital
            int quotient = divident / divisor;
            if(!hasUniqueDigits(quotient, msDivisor))
                continue;

            // Check if all nine digits are present
            if(msDivisor.size() != 9)
                continue;
            
            if(true)
                cout << setw(4) << divisor << " * " << setw(4) << quotient << " = " << setw(4) << divident << endl;
            pandigitalProducts.insert(divident);
        }
    }

    int pandigitalProductSum = 0;
    for(set<int>::iterator it = pandigitalProducts.begin(); it != pandigitalProducts.end(); ++it){
        pandigitalProductSum += *it;
    }

    clock_t end = clock();


    cout << "pandigital product sum = " << pandigitalProductSum << endl;
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "unique Computations: " << amountUniqueComputations << endl;
    return 0;
}