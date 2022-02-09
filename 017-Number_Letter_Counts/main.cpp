#include <iostream>
#include <string>

using namespace std;

const bool DEBUG = false;

const string digit[10] = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

const string teens[10] = {
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

const string tenth[10] = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

int countBelow10(int i){
    int sol = digit[i].length();
    if(DEBUG)
            cout << i << " -> " << digit[i] << " ( # = " << sol << " )" << endl;
    return sol;
}
int countBelow20(int i){
    if(i >= 0 && i < 10){
        return countBelow10(i);
    }
    int sol = teens[i-10].length();
    if(DEBUG)
            cout << i << " -> " << teens[i-10] << " ( # = " << sol << " )" << endl;
    return sol;
}

int countBelow100(int i){
    int secondDigit = i / 10;
    int firstDigit = i % 10;

    if(i >= 0 && i <20){
        return countBelow20(i);
    }
    else{
        int sol = tenth[secondDigit].length() + digit[firstDigit].length();
        if(DEBUG)
            cout << i << " -> " << tenth[secondDigit] << "-" << digit[firstDigit] << " ( # = " << sol << " )" << endl;
        return sol;
    }
}

int countBelow1000(int i){

    int thirdDigit = i / 100;
    int secondDigit = (i / 10) % 10;
    int firstDigit = i % 10;

    if(i >= 0 && i < 100){
        return countBelow100(i);
    }
    else if(secondDigit == 0 && firstDigit == 0){
        int sol = countBelow10(thirdDigit) + countBelow100(i % 100) + 7; // "e.g. one hundred"
        if(DEBUG)
            cout << i << " -> " << sol << endl;
        return sol;
    }
    else{
        return countBelow10(thirdDigit) + countBelow100(i % 100) + 10; // "e.g. one hundred and one"
    }
    
}

int main(){

    int sum = 0;

    for(int i=0; i<1000; i++){
        sum = sum + countBelow1000(i);
    }

    sum = sum + string("one").length() + string("thousand").length();
    cout << "Final Result = " << sum << endl;

    return 0;
}