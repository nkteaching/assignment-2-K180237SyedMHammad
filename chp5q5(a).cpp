#include <iostream>
using namespace std;
void functionascending(int i,int n)
{
	if(i>n)
	{
		return;
	}
	else
	{
		if(i%2!=0)
		{
			cout<<i<<" ";
			functionascending(i+1,n);
		}
		else
		{
			functionascending(i+1,n);
		}
	}
}
main()
{
	functionascending(1,10);
}
