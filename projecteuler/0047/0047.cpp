#include <set>
#include <iostream>

using namespace std;

#define PRIMELIM 1000000
#define DISTINCT_TARGET 4
set<int> composites[PRIMELIM];

void build_composites() 
{
	for(int i=2;i<PRIMELIM;i++)
	{
		if(composites[i].size()==0)
		{
			for (int j=i*2;j<PRIMELIM; j+=i)
			{
				composites[j].insert(i);
			}
		}
	}
}

int main()
{
	build_composites();
	int i=1+DISTINCT_TARGET;
	while (i<PRIMELIM)
	{
		bool bDistinctFactors=true;
		for(int j=0;j<DISTINCT_TARGET;j++) 
		{
			if(composites[i-j].size()!=DISTINCT_TARGET) {
				bDistinctFactors=false;
				break;
			}
		}
		if(bDistinctFactors) {
			for(int  j=0;j<DISTINCT_TARGET;j++) {
				cout<<i-j<<" : ";
				for(auto& prime : composites[i-j]) {
					cout<<prime<<" ";
				}
				cout<<endl;				
			}
			cout <<i+1-DISTINCT_TARGET<<endl;
			break;
		}
		i++;
	}
	cout << "Le done" <<endl;
	return 0;
}

