#include <iostream>

using namespace std;

int main() {
	int sum=0;
	int input;
	cin>>input;
	for(int i=1;i<input;i++) 
	{
		if(i%3==0||i%5==0)
		{
			sum+=i;
		}
	}
	cout<<sum<<endl;
	return 0;
}
