#include<iostream>
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
				return -1;
			}
			else
			{
				return top->data;
			}
		}
		void addinglargenumber(stack &s,stack &d)
		{
			stack s1,s2;
			while(!s.isEmpty())
			{
				s1.push(s.peek());
				s.pop();
			}
			while(!d.isEmpty())
			{
				s2.push(d.peek());
				d.pop();
			}
			int carry=0;
			while(!s1.isEmpty() || !s2.isEmpty())
			{
				
				if(s1.peek()==-1 || s2.peek()==-1)
				{
					break;
				}
				carry=carry+s1.peek()+s2.peek();
				if(carry>9)
				{
					int mod;
					mod=carry%10;
					carry=carry/10;
					push(mod);
				}
				else
				{
					push(carry);
					carry=0;
				}
				s1.pop();
				s2.pop();
			}
			if(!s1.isEmpty() && s2.isEmpty())
			{
				while(!s1.isEmpty())
				{
					carry=carry+s1.peek();
					if(carry>9)
				    {   
					    int mod;
					    mod=carry%10;
					    carry=carry/10;
					    push(mod);
				    }
				    else
				    {
					    push(carry);
					    carry=0;
				    }
				    s1.pop();
				}
				
			}
			if(s1.isEmpty() && !s2.isEmpty())
			{
				while(!s2.isEmpty())
				{
					carry=carry+s2.peek();
					if(carry>9)
				    {
					    int mod;
					    mod=carry%10;
					    carry=carry/10;
					    push(mod);
				    }
				    else
				    {
					    push(carry);
					    carry=0;
				    }
				    s2.pop();
				}
			}
			if(carry!=0)
			{
				push(carry);
			}
		}
};
main()
{
	stack s1,s2,result;
	int num1,num2;
	cout<<"Enter first number:";
	cin>>num1;
	cout<<"Enter second number:";
	cin>>num2;
	while(num1!=0)
	{
		int rem;
		rem=num1%10;
		s1.push(rem);
		num1=num1/10;
	}
	while(num2!=0)
	{
		int rem;
		rem=num2%10;
		s2.push(rem);
		num2=num2/10;
	}
	result.addinglargenumber(s1,s2);
	cout<<"Sum=";
	while(!result.isEmpty())
	{
		cout<<result.peek();
		result.pop();
	}
}
