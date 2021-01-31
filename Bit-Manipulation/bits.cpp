#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include <unordered_map>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;


void bin(unsigned n)
{
    if (n > 1) {
        bin(n / 2);
    }

    cout << n % 2;
}

void printBits(int n) {
    bin(n);
    cout << endl;
}


//Set bit to 1. If it's already a 1, it remains a 1
int SetBit(int num, int x){
  return num | (1 << x);
}

//Setting bit to 0. If its already a 0, it stays a 0
int ClearBit(int num, int x){
  return num & ~(1 << x);
}

//If bit is 0, it becomes a 1, if its a 1, it becomes a 0
int ToggleBit(int num, int x){
  return num ^ (1 << x);
}

//Get value of a bit
int GetValue(int num, int x){
  return num | ~(1 << x);
}

bool IsPowerof2(int num){
  return (num & (num -1) == 0);
}

bool IsPowerof2(int num){
	while(num > 0 ){
	    if( 1 == (num & 1) ){
	      return (num == 1);
	    }
	    num = num >> 1;
	}
  return false;
}



bool OppositeSigns(int x, int y){
  return (x ^ y) < 0;
}

int 2PowN(int n){
  return 1 << n;
}

int Double(int n){
  return n << 1;
}

int Plus1(int x){
  return -(~x);
}

//Add operator
int Add(int x, int y){
  
  while(y != 0){
    int carry = x&y;
    x = x ^ y;
    y = carry << 1;
  }
  return x;
}

//Maximum of 2 numbers
int Max(int x, int y){
  return (x+y)/2 + abs((x-y)/2);
}

//Minimum of 2 numbers
int Min(int x, int y){
  return (x+y)/2 - abs((x-y)/2);
}
