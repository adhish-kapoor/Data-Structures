#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[1000010];
ll tree[1000010];
ll lazy[1000010];
void build(ll node,ll low,ll high)
{
    if(low>high)
    return;
    if(low==high)
    {
        tree[node]=a[low];
        return;
    }
    ll mid=(low+high)/2;
    build(2*node,low,mid);
    build(2*node+1,mid+1,high);
    tree[node]=min(tree[2*node],tree[2*node+1]);
}
void update(ll node,ll low,ll high,ll l,ll r,ll val)
{
    if(lazy[node]!=0)
    {
        
        tree[node]+=lazy[node];
        if(low!=high)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l>high||r<low)      //no overlap
    return;
    if(low>=l&&high<=r) //total overlap
    {
    tree[node]+=val;
    lazy[2*node]+=val;
    lazy[2*node+1]+=val;
    return;
    }                             //partial overlap
    ll mid=(low+high)/2;
    update(2*node,low,mid,l,r,val);
    update(2*node+1,mid+1,high,l,r,val);
    tree[node]=min(tree[2*node],tree[2*node+1]);
}
ll query(ll node,ll low,ll high,ll l,ll r)
{
    if(lazy[node]!=0)
    {
        
        tree[node]+=lazy[node];
        if(low!=high)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l>high||r<low)    //no overlap
    return INT_MAX;
     if(low>=l&&high<=r) //total overlap
     return tree[node];
                             //partial overlap
     ll mid=(low+high)/2;
    ll p=query(2*node,low,mid,l,r);
    ll q=query(2*node+1,mid+1,high,l,r);
    return min(p,q);
}
int main() {
	ll n,q,i,val,type,l,r;
	cin>>n>>q;
	for(i=0;i<n;i++)
	cin>>a[i];
	build(1,0,n-1);
	while(q--)
	{
	    cin>>type>>l>>r;
	    if(type==1)
	    {
	        cin>>val;
	        update(1,0,n-1,l-1,r-1,val);  //to add val in given range
	    }
	    else if(type==2)
	    {
	       ll mn=query(1,0,n-1,l-1,r-1); //to find minimum in given range
	       cout<<mn<<endl;
	    }
	}
}
