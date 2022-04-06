#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

const bool  DEBUG   = false;

bool isPandigitalConcatProduct(int number){

    int faktor = 1;
    string concatProduct = "";

    while(concatProduct.length() < 9){
        int toConcat = faktor++ * number;
        concatProduct += to_string(toConcat);
    }

    string res = concatProduct;
    sort(concatProduct.begin(), concatProduct.end());

    if(concatProduct == "123456789"){
        cout << res << endl;
        return true;
    }

    return false;
}

int main(){
    
    long long amountUniqueComputations = 0;
    clock_t start = clock();
    
    /**
     *      FORMULA:
     *          fixed number * n = xxx  || while n = 1,2,3, .. until product is 9-digit
     *          
     *          all xxx concatenated should result in 9 digits
     * 
     *      LIMIT: 
     *          has to be less than 5 digits because 
     *              
     *              xxxxx * 1 = xxxxx       5 digits
     *              xxxxx * 2 > xxxxx      10 digits
     * 
     *          => bounds: 1 -> 9876
     * 
     *      OPTIMIZATION:
     *          We know there is a candidate which starts with 9 (918273645)
     *          -> think about how a 9 as first digit is achievable
     * 
     *          fixed number has 2 digits
     *              9x * 1 = 9x             2 digits
     *              9x * 2 = 18x            5 digits
     *              9x * 3 = 27x            8 digits
     *              9x * 4 = 36x           11 digits
     * 
     *          fixed number has 3 digits
     *              9xx * 1 = 9xx           3 digits
     *              9xx * 2 = 18xx          7 digits    
     *              9xx * 3 = 27xx         11 digits
     * 
     *          fixed number has 4 digits
     *              9xxx * 1 = 9xxx         4 digits
     *              9xxx * 2 = 18xxx        9 digits = PANDIGITAL
     * 
     *          => new bounds: 9123 -> 9876 
     *             (fixed numbers itself need to be pandigital because of *1 multiplication in 1st step)
     * 
     *      MORE:
     *              94xx * 1 = 94xx
     *              94xx * 2 = 188xx
     * 
     *              95xx * 1 = 95xx
     *              95xx * 2 = 190xx        CARRY to 9 => ALWAYS NOT PANDIGITAL
     * 
     *          => even better bounds: 9123 -> 9487
     *          
     *      EVENMORE:
     *              94xx * 1 = 94xx
     *              94xx * 2 = 188xx        DOUBLE DIGIT 8
     *                                          with single carry  = 9
     *                                          with double carry  = 0
     *                                          with tripple carry = 1
     *                                                  => ALL NUMBERS NOT ALLOWED ANYMORE
     * 
     *          => in times two multiplication there cannot be a double/tripple carry
     *          => even better bounds: 9123 -> 9387
     * 
     *      MOREMOREMORE:
     *              91xx * 1 = 91xx
     *              91xx * 2 = 182xx        DOUBLE DIGIT 1
     *                                                  => there cant be a 1 in the fixed number!
     * 
     *          => bestest bounds: 9234 -> 9387
     * 
     * */ 

    for(int i = 9234; i < 9387; i++){
        isPandigitalConcatProduct(i);
    }

    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "unique Computations: " << amountUniqueComputations << endl;
    return 0;
}