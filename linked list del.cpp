#include <bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    node *link;
}*start,*temp,*temp2;

void del(node *temp,int pos)
{
    if(pos==1)
    {
        start=temp->link;
        free(temp);
    }
    else{
    for(int i=0;i<pos-2;i++)
    temp=temp->link;
    node* tobdel=temp->link;
    free(tobdel);
    temp->link=temp->link->link;
    
    }
}
int main() {
	cout<<"Enter no. of elements\n";
	int n,pos;
	cin>>n;
	cout<<"Enter position to be deleted\n";
	cin>>pos;
	for(int i=0;i<n;i++)
	{
	    temp=(node*)malloc(sizeof(node));
	    cin>>temp->info;
	    temp->link=NULL;
	    if(i==0)
	    {
	        start=temp;
	        temp2=temp;
	    }
	    else
	    {
	        temp2->link=temp;
	        temp2=temp;
	    }
	}
	temp=start;
	del(temp,pos);
	temp=start;
	while(temp!=NULL)
	{
	    cout<<temp->info<<" ";
	    temp=temp->link;
	}
}
