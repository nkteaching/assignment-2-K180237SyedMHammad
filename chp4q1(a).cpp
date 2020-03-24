#include <iostream>
using namespace std;
//question1(a)
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
		void reverseStack(stack &otherStack)
		{
			if(otherStack.isEmpty()!=true)
			{
				while(otherStack.isEmpty()!=true)
				{
					otherStack.pop();
				}
			}
			while(isEmpty()!=true)
			{
				otherStack.push(peek());
				pop();
			}
		
		}
};
main()
{
	stack s1,s2,s3;
	int element,size1,size2;
	cout<<"Enter size of stack:";
	cin>>size1;
	cout<<"Enter element(s) stack(last entered element will be the top of stack):";
	for(int i=0;i<size1;i++)
	{
		cin>>element;
		s1.push(element);
	}
	cout<<endl;	
	//additional stacks
	s1.reverseStack(s2);
	s2.reverseStack(s3);
	s3.reverseStack(s1);
	cout<<"STACK1 after using two additional stacks:";
	while(s1.isEmpty()!=true)
	{
		cout<<s1.peek()<<" ";
		s1.pop();
	}
}
