#include <iostream>
#include <algorithm>

using namespace std;

int primes[] = {2,3,5,7,11,13,17};

bool checkIt(int* pandigital) {
	if(pandigital[0]==0) {
		return false;
	}
	int test=pandigital[1]*10+pandigital[2];
	for(int i=3;i<10;i++) {
		test=(test*10)%1000+pandigital[i];
		if(test%primes[i-3]!=0) {
			return false;
		}
	}
	
	return true;
}

uint64_t sum;
int start_pand[] = {0,1,2,3,4,5,6,7,8,9};

uint64_t getTheNum(int* pandigital) {
	uint64_t res=0;
	for(int i=0;i<10;i++) {
		res*=10;
		res+=pandigital[i];
	}
	return res;
}

int main() {
	sum=0;
	do {
		if(checkIt(start_pand)) {
			sum=sum+getTheNum(start_pand);
			cout<<getTheNum(start_pand)<<endl;
		}
	} while (next_permutation(start_pand,start_pand+10));
	cout<<sum<<endl;
	return 0;
}









