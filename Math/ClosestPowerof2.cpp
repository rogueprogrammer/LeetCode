#include "header.h"

//2. Given a number WAP to find a number closet to it and is a power of 2 e.g.i / p 7 o / p 8.

bool IsPowerof2(int x){
	while (x > 1){
		if (x % 2 != 0){
			return false;
		}
		x /= 2;
	}
	return true;
}


int ClosestPowerof2(int x){
	int greaterthanx = 0;

	//closest power of 2 greater than x
	for (int i = x;; ++i){
		if (IsPowerof2(i)){
			greaterthanx = i; 
			break;
		}
	}

	int lessthanx = 0;

	//closest power of 2 less than x
	for (int i = x; i >= 1; --i){
		if (IsPowerof2(i)){
			lessthanx = i;
			break;
		}
	}

	return (abs(greaterthanx - x) <= abs(lessthanx - x)) ? greaterthanx : lessthanx;
}

void main(){
  cout << ClosestPowerof2(400) << endl;
}
