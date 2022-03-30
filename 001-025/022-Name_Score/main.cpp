#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 10000;

int calcAlphabeticValue(const string & toCalc){
    int val = 0;
    for(int i=0; i<toCalc.size(); i++){
        int ascii = toCalc[i];
        ascii = ascii - 64;
        val += ascii;
    }
    return val;
}

int main(){
    
    ifstream fin("names.txt");

    vector<string> names;

    // NAMEN IN STRING ARRAY PUSHEN
    string temp;
    while(getline(fin, temp, ',')){
        names.push_back(temp);
    }

    // STRINGS IN ARRAY PARSEN
    for(auto it = names.begin(); it != names.end(); ++it){
        int len = (*it).length()-1;
        *it = (*it).substr(1,len-1);
    }

    // STRING ARRAY SORTIEREN
    std::sort(names.begin(), names.end());


    // SCORE BERECHNEN
    vector<int> nameScores;
    for(int i = 0; i < names.size(); i++){
        int nScore = calcAlphabeticValue(names[i]) * (i+1);
        nameScores.push_back(nScore);
    }

    // SCORES AUFADDIEREN
    long long finalScore = 0;
    for(auto it = nameScores.begin(); it != nameScores.end(); ++it){
        finalScore += *it;
    }

    cout << "Final Score = " << finalScore << endl;

    return 0;
}