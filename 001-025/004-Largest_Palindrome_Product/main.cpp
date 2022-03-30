#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> palindromes;

bool isPalindrome(int num){
    string test = to_string(num);
    if(test.length() != 6)
        return false;
    if(test[0] != test[5])
        return false;
    if(test[1] != test[4])
        return false;
    if(test[2] != test[3])
        return false;
    return true;
}

int largestPalindromeProduct(){
    for(int i = 999; i>0; i--){
        for(int j = i; j>0; j--){
            if(isPalindrome(i*j))
                palindromes.push_back(i*j);
        }
    }
    sort(palindromes.begin(), palindromes.end());
    if(palindromes.empty())
        return -1;
    return palindromes[palindromes.size()-1];
}



int main(){

    cout << "Das groesste Palindrom-Produkt zweier dreistelliger Zahlen ist " << largestPalindromeProduct() << endl;
}