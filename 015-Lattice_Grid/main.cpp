#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

int main(){

    const int N = 20;

    /** 
     *      ==========================
     *      ||  WITH COMBINATORICS  ||
     *      ==========================
     * 
     *      See n=2 -> for example (L,L,R,R) -> Problem is how to place 2 L into 4 positions
     *              -> (2n) over (n) = (2n)! / (n! * n!)
     *              However: This is hard to calculate because the solution of 40! is over the limit of long long datatype
     *              Solution: use multiplicative formula
     * */

    unsigned long long n = 2*N;
    unsigned long long k = N;

    cout << n << " " << k << endl;

    unsigned long long sol = 1;
    unsigned long long errorSol = 1;


    for(int j=1; j<(k+1); j++){
        sol      = (sol * (n+1-j))/j;           // DANGER !! ALL sol steps are natural but only if you do the division last
        errorSol = errorSol * ((n+1-j)/j);      
    }
    cout << setw(30) << "with combinatorics: " <<  "#paths = " << sol << endl;
    cout << setw(30) << "wrong combinatorics: " <<  "#paths = " << errorSol << endl;


    /**
     *      ============================
     *      ||  WITH DYN PROGRAMMING  ||
     *      ============================
     * 
     *      Build 2D-Array of (n+1) * (n+1) and fill edges with 1 (because on the edge only 1 path)
     *      THen use pascals triangular to add the amounts of possible paths e.g. for n=2
     * 
     *            1
     *          1   1
     *        1   2   1
     *          3   3   
     *            6 
     * 
     *      which can be represented in a 3x3 matrix
     * 
     * */

    
    long long mat[N+1][N+1];

    for(int i=0; i<(N+1); i++){
        // horizontal edge
        mat[0][i] = 1;
        // vertical edge
        mat[i][0] = 1;
    }

    for(int i=1; i<(N+1); i++){
        for(int j=1; j<(N+1); j++){
            mat[i][j] = mat[i-1][j] + mat[i][j-1];
        }
    }

    cout << setw(30) << "with dynamic programing: " <<  "#paths = " << mat[N][N] << endl;

    return 0;
}