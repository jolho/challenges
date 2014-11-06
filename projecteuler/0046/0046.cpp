#include <iostream>
#include <cstdlib>
#include<cmath>

using namespace std;

#define PRIMELIMIT 1000000
int sieve[PRIMELIMIT];
int *primes;
int num_primes;

void calcSieve() 
{
	num_primes=0;
	for(int i=0;i<PRIMELIMIT;i++) 
	{
		sieve[i]=0;
	}
	for(int i=2;i<PRIMELIMIT;i++) 
	{
		if(sieve[i]==0) 
		{
			num_primes++;
			for(int j=i*2;j<PRIMELIMIT;j+=i) 
			{
				sieve[j]=1;
			}
		}
	}
}

void buildPrimes() 
{
	int i,j;
	primes=(int*)malloc(sizeof(int)*num_primes);
	for(i=2,j=0;i<PRIMELIMIT;i++) 
	{
		if(sieve[i]==0) 
		{
			primes[j++]=i;
		}
	}
}

bool isGoldbach(int num,int prime)
{
	double calc=num;
	calc=(sqrt((calc-prime)/2));
	return calc==trunc(calc);
}

int main() 
{
	calcSieve();
	buildPrimes();
	for(int i=9;i<PRIMELIMIT;i+=2) 
	{
		if(sieve[i]==0) 
			continue;
		bool isThisGoldbach=false;
		for(int j=0;j<num_primes;j++) 
		{
			if(primes[j]>i)
				break;
			if(isGoldbach(i,primes[j])) 
			{
				isThisGoldbach=true;
				break;
			}
		}
		if(!isThisGoldbach) 
		{
			cout<<i<<endl;
			break;
		}
	}
	
	cout << "I'm done" <<endl;
	
	
	return 0;
}








