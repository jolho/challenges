#include<iostream>
#include<cmath>
#include<climits>

using namespace std;
#define BUFF 10000
int pentas[BUFF];

void fillPentas()
{
	for(int i=1;i<=BUFF;i++)
	{
		pentas[i-1]=i*(3*i-1)/2;
	}
}

bool isPenta(int num)
{
	double calc=num;
	calc=(sqrt(calc*24+1)+1)/6;
	return calc==trunc(calc);
}

int main() 
{
	int diff_result=INT_MAX;
	fillPentas();
	for(int i=0;i<BUFF;i++)
	{
		for(int j=i+1;j<BUFF;j++) 
		{
			int local_diff=pentas[j]-pentas[i];
			if(local_diff>diff_result)
				break;
			if(isPenta(pentas[j]+pentas[i])&&isPenta(local_diff))
			{
				//Thanks to the break above, local_diff is surely less then diff_result
				diff_result=local_diff;
				cout<<diff_result<<" "<<pentas[i]<<" "<<pentas[j]<<endl;
			}
		}
	}
	
	cout<<diff_result<<endl;
	
}
