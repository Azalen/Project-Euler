#include <iostream>
#include <ctime>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;

const bool  DEBUG   = false;

void swap(int * arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

// reverse array from index i to index j
void reverse(int * arr, int i, int j){
    while(i < j){
        swap(arr,i,j);
        i++;
        j--;
    }
}

// advance the passed permutation in place
bool nextLexicograficPerm(int * perm, int N){
    // (1) find longest non-increasing suffix -> i becomes pivot for swap element
    int i = N-1;
    while(i > 0 && perm[i-1] >= perm[i]){
        i--;
    }
    // i is now the head index of the suffix
    if(i == 0){
        // head of suffix is 1st element => highest permutation
        return false;
    }
    int pivot = i-1;
    if(DEBUG){
        cout << "perm = {";
        for(int i = 0; i < N; i++)
            if(i == pivot){
                cout << "\033[1;31m" << perm[i] << "\033[0m" << " ";
            }
            else if(i > pivot){
                cout << "\033[1;34m" << perm[i] << "\033[0m" << " ";
            }
            else{
                cout << perm[i] << " ";
            }
            
        cout << "}" << endl;
    }

    // (2) find rightmost successor of i in the suffix
    int j = N-1;
    while(perm[j] <= perm[pivot]){
        j--;
    }
    if(DEBUG){
        cout << "perm = {";
        for(int i = 0; i < N; i++)
            if(i == pivot){
                cout << "\033[1;31m" << perm[i] << "\033[0m" << " ";
            }
            else if(i == j){
                cout << "\033[1;33m" << perm[i] << "\033[0m" << " ";
            }
            else if(i > pivot){
                cout << "\033[1;34m" << perm[i] << "\033[0m" << " ";
            }
            else{
                cout << perm[i] << " ";
            }
            
        cout << "}" << endl;
    }

    // (3) swap pivot and rightmost successor of pivot in the suffix
    swap(perm, pivot, j);
    if(DEBUG){
        cout << "perm = {";
        for(int i = 0; i < N; i++)
            if(i == pivot){
                cout << "\033[1;33m" << perm[i] << "\033[0m" << " ";
            }
            else if(i == j){
                cout << "\033[1;31m" << perm[i] << "\033[0m" << " ";
            }
            else if(i > pivot){
                cout << "\033[1;34m" << perm[i] << "\033[0m" << " ";
            }
            else{
                cout << perm[i] << " ";
            }
            
        cout << "}" << endl;
    }

    // (4) reverse the suffix
    reverse(perm,i,N-1);
    if(DEBUG){
        cout << "perm = {";
        for(int i = 0; i < N; i++)
            if(i == pivot){
                cout << "\033[1;33m" << perm[i] << "\033[0m" << " ";
            }
            else if(i > pivot){
                cout << "\033[1;32m" << perm[i] << "\033[0m" << " ";
            }
            else{
                cout << perm[i] << " ";
            }
            
        cout << "}" << endl;
    }
    return true;

}

int main(){
    
    long long loopRuns = 0;
    clock_t start = clock();

    int primes[7] = {2,3,5,7,11,13,17};

    /**
     *  LOOP:   1023456789 -> 9876543210
     * 
     *  FIRST:  we have to cut down the amount of computations making use of permutation logic
     *          right now we have to check numbers from 1.02 to 9.87 billion but we are truely only interested
     *          in permutations thus is 9*9! = 3.2 million cases
     * 
     *          => we need a way to compute the next permutation
     *          => lexicografic permutation algorithm 
     *                  see https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
     *                  or  E. W. Dijkstra, A Discipline of Programming, page 71
     * 
     * */

    int validPerms = 0;
    long long permSum = 0;

    int N = 10;
    int perm[N] = {1,0,2,3,4,5,6,7,8,9};
    do{
        loopRuns++;

        // d2d3d4 must be divisible by 2
        if(perm[3] % 2 != 0)
            continue;

        // d3d4d5 must be divisible by 3
        int digitSum = perm[2] + perm[3] + perm[4];
        if(digitSum % 3 != 0)
            continue;
        
        // d4d5d6 must be divisible by 5
        if(perm[5] % 5 != 0)
            continue;

        // d5d6d7 must be divisble by 7
        int d5d6d7 = 100*perm[4] + 10*perm[5] + perm[6];
        if(d5d6d7 % 7 != 0)
            continue;

        // d6d7d8 must be divisble by 11
        int d6d7d8 = 100*perm[5] + 10*perm[6] + perm[7];
        if(d6d7d8 % 11 != 0)
            continue;

        // d7d8d9 must be divisble by 13
        int d7d8d9 = 100*perm[6] + 10*perm[7] + perm[8];
        if(d7d8d9 % 13 != 0)
            continue;

        // d8d9d10 must be divisble by 17
        int d8d9d10 = 100*perm[7] + 10*perm[8] + perm[9];
        if(d8d9d10 % 17 != 0)
            continue;
        
        validPerms++;
        if(true){
        cout << "perm = { ";
        for(int i = 0; i < N; i++)
            cout << perm[i] << " ";
            
        cout << "}" << endl;
        }

        long long permVal = 0;
        for(int i = 0; i < N; i++){
            permVal += pow(10,N-1-i) * perm[i];
        }
        permSum += permVal;
        
    }while(nextLexicograficPerm(perm, N));

    clock_t end = clock();
    cout << "valid perms: " << validPerms << endl;
    cout << "perm sum: " << permSum << endl;
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "loop runs: " << loopRuns << endl;
    return 0;
}