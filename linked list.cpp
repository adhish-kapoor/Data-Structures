#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
void push(struct node **headref,int newdata)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=newdata;
	newnode->next=*headref;
	*headref=newnode;
}
void printlist(struct node*n)
{
	while(n!=NULL)
	{
		cout<<n->data<<" ";      
		n=n->next;
	}
}
main()
{
	int n,data;
	struct node *head=NULL;  
	cout<<"How many nodes to enter\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		push(&head,data);
	}
	
	cout<<"Linked list formed is\n";
	printlist(head);
	
}
