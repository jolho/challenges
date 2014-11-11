#include <iostream>

using namespace std;

// Answer went to pretty big primes, so I got this dandy sieve from interwebs.
//MAX is LIM*LIM

#define MAX 900000000
#define LIM 30000

unsigned flag[MAX>>6]={0};

#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void sieve() {
    unsigned i, j, k;
    for(i=3; i<LIM; i+=2)
        if(!ifc(i))
            for(j=i*i, k=i<<1; j<LIM*LIM; j+=k)
                isc(j);
}

int main()
{
	sieve();
	bool horizontal=true;
	int testingNumber=1;
	int numberOfPrimes=0;
	int numberOfNoPrimes=1;
	
	int corner=0;
	
	double ratio =1;
	int length=0;
	
	do
	{
		if(corner==0)
			length+=2;
		testingNumber+=length;
		if(!ifc(testingNumber))
			numberOfPrimes++;
		else
			numberOfNoPrimes++;
		corner++;
		corner%=4;
		if(corner==0) 
		{
			ratio=(double)numberOfPrimes/(numberOfPrimes+numberOfNoPrimes);
		}
	} while(ratio>0.1);
	
	cout<<length+1<<endl;
	
	return 0;
}