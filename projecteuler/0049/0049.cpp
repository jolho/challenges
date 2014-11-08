#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define PRIMELIMIT 10000
int sieve[PRIMELIMIT];

void calcSieve() 
{
	for(int i=0;i<PRIMELIMIT;i++) 
	{
		sieve[i]=0;
	}
	for(int i=2;i<PRIMELIMIT;i++) 
	{
		if(sieve[i]==0) 
		{
			for(int j=i*2;j<PRIMELIMIT;j+=i) 
			{
				sieve[j]=1;
			}
		}
	}
}

bool checkDigitPermutation(int a, int b)
{
	int digits[]={0,0,0,0,0,0,0,0,0,0};
	while(a>0)
	{
		digits[a%10]++;
		a/=10;
	}
	while(b>0)
	{
		digits[b%10]--;
		b/=10;
	}
	for(int i=0;i<10;i++)
		if(digits[i]!=0)
			return false;
	return true;
}


int main()
{
	calcSieve();
	for(int i=1000;i<PRIMELIMIT;i++)
	{
		if(sieve[i]==0)
		{
			for(int j=2;j<(PRIMELIMIT-i)/2;j++)
			{
				if(
					sieve[i+j]==0
					&&
					sieve[i+j+j]==0
					&&
					checkDigitPermutation(i, i+j)
					&&
					checkDigitPermutation(i, i+j+j)
				)
				{
					cout<<i<<" "<<i+j<<" "<<i+j+j<<endl;
				}
			}
		}
	}
	return 0;
}

