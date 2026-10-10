#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
		
	Node(int val)
	{
		data=val;
		next=NULL;
	}
};

class List
{
	
	Node* head;
	Node* tail;
	
public:
	List()
	{
		head=tail=NULL;
	}
	
	void pushfront(int val)
	{
		Node* newNode=new Node(val);
		
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
		newNode->next=head;
		head=newNode;
		}
	}
	
	void reverse()
	{
		Node* prev=NULL;
		Node* curr=head;
		Node* next=NULL;
		
		while(curr!=NULL)
		{
			next=curr->next;
			curr->next=prev;
			
			prev=curr;
			curr=next;
		}
		head = prev;
	}
	
	void print()
	{
		Node *temp=head;
		
		while(temp!=NULL)
		{
		cout<<temp->data<<"->";
		temp=temp->next;
		}
		cout<<"NULL\n";
	}

};

int main()
{
	List l1;
	
	l1.pushfront(2);
	l1.pushfront(4);
	l1.pushfront(6);
	l1.pushfront(8);
	
	l1.reverse();
	
	l1.print();

}
