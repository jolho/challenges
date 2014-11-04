#include <iostream>
#include <cstdlib>

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

int main ()
{
	int i,j,k;
	int max_consecutive=0;
	int result=0;
	int sum=0;
	
	calcSieve();
	buildPrimes();
	
	for(k=0;k<num_primes;k++) 
	{
		sum=primes[0];
		i=0;
		j=0;
		while(j<k) {
			if(primes[k]==sum) 
			{
				if(max_consecutive<j-i) 
				{
					max_consecutive=j-i;
					result = primes[k];
				}
			}
			if(primes[k]<sum)
			{
				sum-=primes[i];
				i++;
			}
			else 
			{
				j++;
				sum+=primes[j];
			}
		
		}
	}
	free(primes);
	cout<<result<<" "<<max_consecutive+1<<endl;
	return 0;
}
