#include <iostream>
#include <ctime>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

int main(){
    
    clock_t start = clock();

    int anz = 0;
    
    cout << "possibilities: " << anz << endl;

    clock_t end = clock();
    double runtime = (end - start)*1000000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ns" << endl;
    return 0;
}