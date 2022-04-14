#include <iostream>
#include <ctime>
#include <iomanip>
#include <set>
#include <climits>
#include <cmath>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 10000;

/**     P(n) = (3n² - n) / 2 -> allows us to calculate the n-th pentagonal number
 * 
 *      But what if we want to know IF an arbitiary number is pentagonal?
 * 
 *      x   =   (3y² - y) / 2
 *      2x  =   3y² - y
 *      0   =   3y² - y - 2x
 *      0   =   y² - 1/3*y - 2/3x
 * 
 *      y   =   1/6 +- sqrt(1/36 + 2/3x)
 *      y   =   1/6 +- sqrt(1/36 + 24/36x)
 *      y   =   1/6 +- 1/6 * sqrt(1 + 24x)
 * 
 *      => you must choose the + because else y < 0 for each x > 1
 * 
 *      x is pentagonal number ONLY IF y is natural -> if is the y'th pentagonal number
 *      to ease computation:
 *  
 *      y   =   1/6 +   1/6 * sqrt(1+24x)
 *      y   =   (1 + sqrt(1+24x)) / 6         
 *  
 * 
 * */

bool isPentagonal(int x){
    double y = (1 + sqrt(1+24*x)) / 6.0;
    if(floor(y) == ceil(y))
        return true;
    return false;
}

int main(){
    
    long long loopRuns = 0;
    clock_t start = clock(); 

    for(int i = 1; i < SIZE; i++){
        int pi = (i * (3*i - 1)) / 2;
        
        for(int j = i-1; j > 0; j--){
            int pj = (j * (3*j - 1)) / 2;
            if(!isPentagonal(pi + pj))
                continue;
            if(!isPentagonal(pi - pj))
                continue;

            cout << setw(5) << i << " -> " << setw(8) << pi << endl;
            cout << setw(5) << j << " -> " << setw(8) << pj << endl;
            cout << "   |- pi + pj = " << setw(8) << pi + pj << endl;
            cout << "   |- pi - pj = " << setw(8) << pi - pj << endl;
            cout << endl;
        }
    }

    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "runtime: " << runtime << "ms" << endl;
    cout << setw(16) << "loop runs: " << loopRuns << endl;
    return 0;
}