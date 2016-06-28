//Segment tree with range minimum query
//For every node least index of the minimum element will be returned
//Point update and Range Query

#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
#define reset(a) memset(a,0,sizeof(a))
#define rep(i,j,k) for(i=j;i<=k;++i)
#define per(i,j,k) for(i=j;i>=k;--i)
#define print(a,start,end) for(i=start;i<=end;++i) cout<<a[i];
#define endl "\n"
using namespace std;
int A[100001];
int tree[500001]={0};

void segmenttree(int node, int i, int j) 
{
	if(i > j) 
		return;
	
	if(i == j) 
		{ 
			tree[node] = i; 
			return;
		}
	
	segmenttree(node*2, i, (i+j)/2); 
	segmenttree(node*2+1, 1+(i+j)/2, j); 
	
	if(A[tree[node*2]]<=A[tree[2*node+1]])
		{
			tree[node] =  tree[2*node];
		}
	else
		{
			tree[node] =  tree[2*node+1];
		}
} 

int getmin(int node, int a, int b, int i, int j) 
	{
		if(a > b || a > j || b < i) return 0 ; // Out of range 
		if(a >= i && b <= j) // Current segment is totally within range [i, j]
			{
				return tree[node];
			}
		int q1 = getmin(node*2, a, (a+b)/2, i, j); // Query left child
		int q2 = getmin(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
		 
		if(A[q1]<=A[q2])
			{
				return q1;
			}
		else
			{
				return q2;
			}
	} 
	
void update(int node, int i, int j,int k) 
{
	if(i > j||j<k||i>k) 
		return;
	if(i == j)//point update 
		{ 
			tree[node] = k; 
			return;
		}
	update(node*2, i, (i+j)/2,k); 
	update(node*2+1, 1+(i+j)/2, j,k); 
	
	if(A[tree[node*2]]>A[tree[2*node+1]])
		{
			tree[node] =  tree[2*node];
		}
	else if(A[tree[node*2]]==A[tree[2*node+1]])
		{
			tree[node] = min(tree[2*node],tree[2*node+1]);
		}
	else
		{
			tree[node] =  tree[2*node+1];
		}
}

void preprocess()
	{		
		A[0] = INT_MAX;
	}

int main()
    {
		preprocess();
        ios_base::sync_with_stdio(0);
    	int i,n,x,val,q,type;
		cin>>n;
		rep(i,1,n)
			{
				cin>>A[i];
			}
		segmenttree(1,1,n);
		cin>>q;
		while(q--)
			{
				cin>>type;
				if(type==0)
					{
						cin>>x>>val;
						A[x] = val;
						update(1, 1, n, x);
					}
				else
					{
						cin>>x>>val;
						//int idx = 1;
						int idx = getmin(1,1,n,x,val);
						cout<<idx<<" "<<A[idx]<<endl;
					}
			}
	}
