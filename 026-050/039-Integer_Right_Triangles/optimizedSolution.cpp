#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

/** 
 *      (I)     a² = b² + c²                                                ( PYTAGORAS )
 *      (II)    p = a + b + c   <=>   a = p - b - c                         ( PERIMETER )
 *  
 *      <=>     a² = (p-b-c)² = p² + b² + c² -2bp -2cp + 2bc = b² + c²
 *      <=>                     p² - 2bp -2cp +2bc = 0
 *      <=>                     p² - 2cp = 2bp - 2bc
 *                                       = b (2p - 2c)
 * 
 *      <=>     b = (p² - 2cp) / (2p - 2c)
 *             ===========================     
 * */

int main(){
    
    long long amountUniqueComputations = 0;
    clock_t start = clock();

    int maxSolutions = 0;
    int resultP = -1;

    // run over all perimeter
    for(int p = 2; p <= 1000; p++){
        int numSolutions = 0;

        // run over all possibilities of lengths of a kathete
        // the kathete is shorter than the hypothenuse
        // the hypothenuse is larger than a third of the perimeter
        // one of the kathetes could be longer than p/3 but never both together
        // we find the other kathete via calculation 

        for(int c = 2; c < p/3; c++){

            double b = (double)(p*p - 2*c*p) / (2*p - 2*c);
            amountUniqueComputations++;

            // If that division yields a correct integer
            if(floor(b) == ceil(b))
                numSolutions++;
        }

        if(numSolutions > maxSolutions){
            maxSolutions = numSolutions;
            resultP = p;
        }
    }

    cout << "perimeter with maximum #solutions = " << resultP << endl;

    

    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "unique Computations: " << amountUniqueComputations << endl;
    return 0;
}