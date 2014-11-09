#include <iostream>
#include <boost/lexical_cast.hpp>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

#define PRIMELIMIT 1000000
int sieve[PRIMELIMIT];
int *primes;
int num_primes;
map<string,int> patterns_count;

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

void addPattern(string pattern)
{
	patterns_count[pattern]++;
}

void recursiveBuildPatterns(string base,int index, char actual)
{
	if(index==base.size())
	{
		addPattern(base);
		return;
	}
	if(actual=='\0') 
	{
		string next=base;
		char chosen=next[index];
		next[index]='X';
		recursiveBuildPatterns(next,index+1,chosen);
		recursiveBuildPatterns(base,index+1,actual);
	}
	else 
	{
		if(actual==base[index])
		{
			string next=base;
			next[index]='X';
			recursiveBuildPatterns(next,index+1,actual);
		}
		recursiveBuildPatterns(base,index+1,actual);
	}
}

int main()
{
	calcSieve();
	buildPrimes();
	
	for(int i=0;i<num_primes;i++)
	{
		string prime = boost::lexical_cast<std::string>(primes[i]);
		recursiveBuildPatterns(prime,0,'\0');
	}
	for ( const auto& count : patterns_count)
	{
		if(count.second>=8) 
		{
			cout<<count.first<<" "<<count.second<<endl;
			for(char digit='0';digit<='9';digit++)
			{
				string numberToTest=count.first;
				for(int j=0;j<numberToTest.size();j++)
				{
					numberToTest[j]=numberToTest[j]=='X'?digit:numberToTest[j];
				}
				if(sieve[boost::lexical_cast<int>(numberToTest)]==0)
				{
					cout << numberToTest << " ";
				}
			}
			cout<<endl;
		}
	}

	return 0;
}
