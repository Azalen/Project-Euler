#include <iostream>
#include <ctime>
#include <set>
#include <iomanip>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

bool hasUniqueDigits(long long num){
    set<int> digits;
    while(num > 0){
        int digit = num % 10;
        num /= 10;
        if(digits.find(digit) != digits.end())
            return false;
        digits.insert(digit);
    }
    return true;
}

int main(){
    
    long long loopRuns = 0;
    clock_t start = clock();

    /** IMPORTANT: We only need d8d9d10 to be a multiple of 17, not the entire number
     *      => figure out all combinations of 3 unique digits that are divisible by 17
     *      => enter new loop for 11 and so on
     * */

    long long sum = 0;

    for(int p17 = 17; p17 < 1000; p17 += 17){
        if(!hasUniqueDigits(p17))
            continue;

        for(int p13 = 13; p13 < 1000; p13 += 13){
            // first 2 digits of p17 have to be the last 2 digits of p13
            if(p17 / 10 != p13 % 100)
                continue;
            if(!hasUniqueDigits(p13))
                continue;

            // if(true)
            //     cout << p13 / 100 << (p13 % 100) / 10 << p13 % 10 << p17 % 10 << endl;

            
            int p13c = (p13*10) + (p17 % 10);
            if(!hasUniqueDigits(p13c))
                continue;
            
            for(int p11 = 11; p11 < 1000; p11 += 11){
                if(p13 / 10 != p11 % 100)
                    continue;
                if(!hasUniqueDigits(p11))
                    continue;

                int p11c = (p11*100) + (p13c % 100);
                if(!hasUniqueDigits(p11c))
                    continue;

                // OPTIMIZATION d6 must be 5 because if d6 = 0 
                //              then only 011,022,...,099 are possible
                //              => no unique digits

                if(p11c / 10000 != 5)
                    continue;
                if(DEBUG)
                    cout << setw(10) << p11c << endl;

                for(int p7 = 7; p7 < 1000; p7 += 7){
                    if(p11 / 10 != p7 % 100)
                        continue;
                    if(!hasUniqueDigits(p7))
                        continue;
                    
                    int p7c = (p7*1000) + (p11c % 1000);
                    if(!hasUniqueDigits(p7c))
                        continue;
                    if(DEBUG)
                        cout << setw(10) << p7c << endl;

                    for(int p5 = 5; p5 < 1000; p5 += 5){
                        if(p7 / 10 != p5 % 100)
                            continue;
                        if(!hasUniqueDigits(p5))
                            continue;
                        
                        int p5c = (p5 * 10000) + (p7c % 10000);
                        if(!hasUniqueDigits(p5c))
                            continue;
                        
                        // OPTIMIZATION d4 must be divisble by 2
                        if((p5c / 1000000) % 2 != 0)
                            continue;
                        if(DEBUG)
                            cout << setw(10) << p5c << endl;

                        for(int p3 = 3; p3 < 1000; p3 += 3){
                            if(p5 / 10 != p3 % 100)
                                continue;
                            if(!hasUniqueDigits(p3))
                                continue;

                            int p3c = (p3 * 100000) + (p5c % 100000);
                            if(!hasUniqueDigits(p3c))
                                continue;
                            if(DEBUG)
                                cout << setw(10) << p3c << endl;

                            // ALL CONDITIONS ARE NOW FULFILLED
                            // CHECK REMAINING POSSIBILITIES

                            for(int k = 12; k < 100; k++){
                                if(!hasUniqueDigits(k))
                                    continue;
                                long long comp = (k * (long long)100000000) + ((long long) p3c % 100000000);
                                if(!hasUniqueDigits(comp))
                                    continue;
                                if(true)
                                    cout << setw(10) << comp << endl;
                                sum += comp;

                            }

                        }
                    }
                }

            }
                

                
            
        }
    }

    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "sum of pandigitals: " << sum << endl;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "loop runs: " << loopRuns << endl;
    return 0;
}