#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

int max(int i, int j){
    return i > j ? i : j;
}

int main(){
    
    vector<vector<int>> mat;

    /**     ==============
     *      ||  READ    ||
     *      ==============
     * */

    ifstream txtReader("./input.txt");
    vector<int> row;

    while(!txtReader.eof()){

        if(txtReader.peek() == '\n'){
            mat.push_back(row);
            row = {};
        }

        int temp;
        txtReader >> temp; 
        row.push_back(temp);
    }
    mat.push_back(row);
    
    for(unsigned int i = 0; i<mat.size(); i++){
        for(unsigned int j=0; j<mat[i].size(); j++){
            cout << setw(4) << mat[i][j] << " ";
        }
        cout << endl;
    }

    /**     ============================
     *      ||  DYNAMIC PROGRAMMING   ||
     *      ============================
     * */

    for(int i = mat.size()-2; i>=0; i--){
        int nextToLastRow = i;
        for(int j = 0; j<mat[nextToLastRow].size(); j++){
        mat[nextToLastRow][j] += max(mat[nextToLastRow+1][j], mat[nextToLastRow+1][j+1]);
        mat[nextToLastRow+1][j] = 0;
    }
    mat[nextToLastRow+1][mat[nextToLastRow].size()] = 0;
    }

    

    cout << endl;
    for(unsigned int i = 0; i<mat.size(); i++){
        for(unsigned int j=0; j<mat[i].size(); j++){
            cout << setw(4) << mat[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}