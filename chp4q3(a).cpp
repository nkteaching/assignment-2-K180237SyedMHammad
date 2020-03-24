#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node()
		{
			data=NULL;
			next=NULL;
		}
		node(int a)
		{
			data=a;
			next=NULL;
		}
		node(int a,node *x)
		{
			data=a;
			next=x;
		}
};
class stack{
	public:
		node *top,*tail;
		stack()
		{
			top=NULL;
			tail=NULL;
		}
		bool isEmpty()
		{
			if (top==NULL)
			return true;
			else
			return false;
		}
		void push(int a)
		{
			if(this->isEmpty()==true)
			{
				top=new node(a,NULL);
				tail=top;
			}
			else
			{
				top=new node(a,top);
			}
		}
		void pop()
		{
			if(this->isEmpty()==true)
			{
				cout<<"Stack Underflow";
			}
			else
			{
				node *n=top;
				top=top->next;
				delete n;
			}
		}
		int peek()
		{
			if(this->isEmpty()==true)
			{
				cout<<"Stack Underflow";
				return -1;
			}
			else
			{
				return top->data;
			}
		}
		void sendstack(stack &s1)
		{
			stack additional;
			while(!s1.isEmpty())
			{
				additional.push(s1.peek());
				s1.pop();
			}
			while(!additional.isEmpty())
			{
				push(additional.peek());
				additional.pop();
			}
			
		}
};
main()
{
	stack s1,s2;
	int element,size1;
	cout<<"Enter size of stack:";
	cin>>size1;
	cout<<"Enter element(s) stack(last entered element will be the top of stack):";
	for(int i=0;i<size1;i++)
	{
		cin>>element;
		s1.push(element);
	}
    s2.sendstack(s1);
    cout<<"Stack2:";
    while(!s2.isEmpty())
    {
    	cout<<s2.peek()<<" ";
    	s2.pop();
	}
}
