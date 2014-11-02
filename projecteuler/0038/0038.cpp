#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
typedef boost::multiprecision::int128_t bigint;

int ipow(int base, int exp)
{
	int result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}

int numdigs(bigint num) 
{
	int res=0;
	while(num>0) 
	{
		num/=10;
		res++;
	}
	return res;
}

bool check_coverage (bigint num)
{
	int res=0;
	while(num>0)
	{
		int dig = (int)(num%10);
		res=res|(1<<dig);
		num/=10;
	}
	return res==0b1111111110;
}


int main() 
{
	bigint maximum = static_cast<bigint>(0);
	for(int base=1;base<10000;base++) 
	{
		int product=1;
		bigint pandigital=static_cast<bigint>(0);
		while(numdigs(pandigital)<9) 
		{
			int product_result=base*product;
			pandigital=pandigital*ipow(10,numdigs(product_result))+product_result;
			product++;
		}
		if(numdigs(pandigital)==9&&check_coverage(pandigital)) 
		{
			if(pandigital>maximum) 
			{
				maximum=pandigital;
			}
		}
		
	}
	
	cout<<maximum<<endl;
}



