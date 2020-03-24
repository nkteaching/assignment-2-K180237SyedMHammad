#include <iostream>
using namespace std;
class node
{
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
class linklist
{
	public:
		node *head,*tail;
		linklist()
		{
			head=NULL;
			tail=NULL;
		}
		void insert(int a)
		{
			if(head==NULL)
			{
				head=new node(a,NULL);
				tail=head;
			}
			else if(head==tail)
			{
			    head->next=new node(a,head->next);
			    tail=head->next;
			    tail->next=NULL;
			}
			else
			{
				tail->next=new node(a,tail->next);
				tail=tail->next;
			}
		}
		int function(int count,node *x)
        {       
	        if(x==NULL)
	        {
		        return count;
	        }
	        else
	        {
		        count++;
	            return function(count,x->next);
	        }
	
        }
};

main()
{
	linklist l;
	l.insert(20);
	l.insert(30);
	l.insert(40);
	int x=l.function(0,l.head);
	cout<<x;
}
