#include <iostream>
using namespace std;
void functiondescending(int n)
{
	if(n<1)
	{
		return;
	}
	else
	{
		if(n%2!=0)
		{
			cout<<n<<" ";
			n--;
			functiondescending(n);
		}
		else
		{
			n--;
			functiondescending(n);
		}
	}
}
main()
{
	functiondescending(10);
}
