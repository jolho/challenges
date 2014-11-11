#include<iostream>

using namespace std;

/* So I was at a conference, and a booth guy was trying to convert a string of
 * 6 hexadecimal digits into a int. He was trying to use a switch on each
 * character, so I just had to help him with a bit of code and quickly fixed
 * him with this bit.
 */

int main()
{
	string S;
	cin>>S;
	cout<<S<<endl;
	
	int res=0;
	for(int i=0;i<S.size();i++)
	{
		char c = S[i];
		res<<=4;
		if(c&64)
		{
			res+=c-'A'+10;
		}
		else 
		{
			res+=c-'0';
		}
	}
	if(res&0x800000)
	{
		res=res|~0xffffff;
	}
	
	cout<<res<<endl;
	
}
