#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

int main(){
    
    clock_t start = clock();

    int total = 0;
    for(int i = 64; i<296000; i++){

        int sum = 0;
        int num = i;

        // get digit 0-5 and calc digit power sum
        for(int digit = 0; digit < 6; digit++){
            
            // get current digit
            int curDigit = num % 10;
            num = num/10;

            // This is faster than math.pow() because of full integer calc
            int fifthPowOfCurDigit = 1;
            for(int j = 0; j < 5; j++){
                fifthPowOfCurDigit *= curDigit;
            }

            sum += fifthPowOfCurDigit;
        }
        if(sum == i)
            total += sum;

    }
    cout << total << endl;

    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    return 0;
}