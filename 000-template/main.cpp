#include <iostream>
#include <ctime>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

int main(){
    
    long long loopRuns = 0;
    clock_t start = clock();


    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "loop runs: " << loopRuns << endl;
    return 0;
}