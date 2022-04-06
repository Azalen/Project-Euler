#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

bool isRectangular(int a, int b, int c){
    // A TRIANGLE IS RECTANGULAR IF THE PYTAGORIAN EQUALITY HOLDS
    // a² + b² = c²

    if(a * a == b*b + c*c)
        return true;

    return false;
}

int main(){
    
    long long amountUniqueComputations = 0;
    clock_t start = clock();

    isRectangular(52,48,20);

    int maxP = 1000;
    int amountSolutions = 0;

    int maxSol = 3;
    int maxAmountSolPerimeter = -1;


    for(int perimeter = 3; perimeter <= maxP; perimeter++){

        amountSolutions = 0;
        // HYPOTHENUSE a
        for(int a = perimeter/3; a < perimeter; a++){
            
            // KATHETEN b und c
            for(int b = 1; b < a; b++){
                int c = perimeter - a - b;
                if(c < 1)
                    continue;
                if(c > b)
                    continue;
                if(!isRectangular(a,b,c))
                    continue;

                amountSolutions++;
            }
        }
        if(amountSolutions > maxSol){
            maxSol = amountSolutions;
            maxAmountSolPerimeter = perimeter;
        }
    }

    cout << maxAmountSolPerimeter << endl;

    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "unique Computations: " << amountUniqueComputations << endl;
    return 0;
}