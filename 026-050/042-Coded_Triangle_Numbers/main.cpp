#include <iostream>
#include <ctime>
#include <set>
#include <fstream>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

int main(){
    
    long long loopRuns = 0;
    clock_t start = clock();

    set<int> triagNumbers;
    for(int i = 1; i<100; i++){
        int num = 0.5 * i * (i+1);
        triagNumbers.insert(num);
    }

    if(DEBUG){
        for(auto it = triagNumbers.begin(); it != triagNumbers.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }

    if(DEBUG){
        string s = "SKY";
        int stringNum = 0;
        for(int i = 0; i < s.length(); i++){
            stringNum += (int) s[i] - 64;
        }
        cout << stringNum << endl;
        if(triagNumbers.find(stringNum) != triagNumbers.end()){
            cout << s << endl;
        }
    }


    fstream fin("words.txt", ios::in);
    if(!fin)
        throw runtime_error("Could not open the file");
    
    string temp;
    int res = 0;
    while(getline(fin, temp, ',')){
        temp = temp.substr(1, temp.length()-2);
        int stringNum = 0;
        for(int i = 0; i < temp.length(); i++){
            loopRuns++;
            stringNum += (int) temp[i] - 64;
        }
        if(triagNumbers.find(stringNum) != triagNumbers.end()){
            res++;
        }
    }
    fin.close();
    clock_t end = clock();


    cout << "result: " << res << endl;
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "loop runs: " << loopRuns << endl;
    return 0;
}