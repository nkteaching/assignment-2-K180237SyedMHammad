#include<iostream>
using namespace std;
void check(int i,string x,char c)
{
	if(i==x.size())
	{
		cout<<"Not found!";
		return;
	}
	else
	{
		if(x[i]==c)
		{
			cout<<"Character found!";
			return;
		}
		else
		{
			i++;
			check(i,x,c);
		}
	}
}
main()
{
	string x;
	char c;
	cout<<"Enter string (without spaces):";
	cin>>x;
	cout<<"Enter character to be searched:";
	cin>>c;
	check(0,x,c);
}
