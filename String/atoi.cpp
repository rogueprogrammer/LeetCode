#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <math.h>
using namespace std;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";}  cout << endl;

//https://leetcode.com/problems/string-to-integer-atoi/


//"1234"
//"-123asdv"
int atoi(const char *str ){
    
    int result;
    int i = 0;
    bool isNegative = false;
    //ignore the first set of white spaces
    while(str[i++] == ' '){ }
    
    if(str[i] == '-' || str[i] == '+'){
        if(str[i] == '-') isNegative = true;
        ++i;
    }
    

    while(str[i]){
        if(str[i] == ' ') { ++i; continue; }
        //ensure that str[i] is numeric
        if(str[i] > '9' || str[i] < '0'){ //check return code
            if(isNegative) result *= -1;
            return result;
        }
        int curDigit = str[i] - '0';
        
        result = curDigit + (result * 10); 
        ++i;
    }    
    if(isNegative){
        result *= -1;
    }
    return result;

}
