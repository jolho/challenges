#include <set>
#include <iostream>

using namespace std;

#define PRIMELIM 1000000
#define DISTINCT_TARGET 3
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
	int i=4;
	while (i<PRIMELIM)
	{
		if(composites[i].size()==DISTINCT_TARGET&&composites[i-1].size()==DISTINCT_TARGET&&composites[i-2].size()==DISTINCT_TARGET) 
		{
			set<int> unite;
			for(auto& prime : composites[i]) {
				unite.insert(prime);
			}
			for(auto& prime : composites[i-1]) {
				unite.insert(prime);
			}
			for(auto& prime : composites[i-2]) {
				unite.insert(prime);
			}
			if(unite.size()==DISTINCT_TARGET*3) 
			{
				cout<<i-2<<":";
				for(auto& prime : composites[i-2]) {
					cout<<prime<<" ";
				}
				cout<<endl;
				cout<<i-1<<":";
				for(auto& prime : composites[i-1]) {
					cout<<prime<<" ";
				}
				cout<<endl;
				cout<<i<<":";
				for(auto& prime : composites[i]) {
					cout<<prime<<" ";
				}
				cout<<endl;
				cout <<i-2<<endl;
				break;
			}
		}
		i++;
	}
	cout << "Le done" <<endl;
	return 0;
}

