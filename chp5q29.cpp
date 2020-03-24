#include <iostream>
using namespace std;
void recurse(int n)
{
	if(n>1)
	{
		return;
	}
	else
	{
		cout<<n;
		n++;
		recurse(n);
	}
}
main()
{
	recurse(0);
}
