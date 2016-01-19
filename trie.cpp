#include<bits/stdc++.h>
using namespace std;
struct tree
	{
		tree *left;
		tree *right;
		bool data;
	}*root;
tree *temp;

char s[55];

void insert(int idx,tree **node)
	{
		if(idx == -1)
			return;
		else
			{
				if(*node==NULL)
					{
						*node = new tree;
						if(s[idx]=='0')
							{
								(*node)->data = 0;
							}
						else
							{
								(*node)->data = 1;
							}
						(*node)->left = NULL;
						(*node)->right = NULL;
						if(idx>0)
							{
								if(s[idx-1]=='0')
									insert(idx-1,&((*node)->left));
								else
									insert(idx-1,&((*node)->right));
							}	
					}
				else
					{
						if(idx>0)
						    {
						        if(s[idx-1]=='0')
						            insert(idx-1,&((*node)->left));
						        else
						            insert(idx-1,&((*node)->right));
						    }
	
					}
			}
	}
int search(int idx)
	{
		//print(1);
		if(idx==-1)
			return 1;
		if(temp==NULL)
			{
				//cout<<idx<<"----";
				return 0;
			}
		if(idx==0)
			return 1;
		if(idx>0)
			{
				if(s[idx-1]=='0')
					{
						temp = temp->left;
						return 1&search(idx-1);
					}
				else
					{
						temp = temp->right;
						return 1&search(idx-1);
					}
			}
	}
//I am considering trie for atmost 16 bit numbers in the array
//This program can insert and search a number into the trie
//using namespace std;
int main()
	{
		ios_base::sync_with_stdio(0);
		int t,n,k;
		cout<<"Enter total Elements to insert into the trie:";
		cin>>t;
		bool flag;
				root = new tree;
				root->data = 0;
				root->left=NULL;
				root->right=NULL;
		while(t--)
			{
				
				cin>>n;
				k=-1;
				while(n)
					{
						s[++k] = 48 + n%2;
						n/=2;
					}
				while(k!=16)
					{
						s[++k] = '0';
					}
				s[++k] = '\0';
				flag = false;
				if(s[15]=='0')
					insert(15,&(root->left));
				else
					insert(15,&(root->right));
			}
		cout<<"Enter total elements to search for in the trie:";
		cin>>t;
		while(t--)	
			{
				cin>>n;
				int w;
				k=-1;
				while(n)
				    {
				        s[++k] = 48 + n%2;
				        n/=2;
				    }
				while(k!=16)
				    {
				        s[++k] = '0';
				    }
				s[++k] = '\0';
				//cout<<s<<endl;;
				temp = root;
				if(s[15]=='0')
						temp = root->left;
				else
						temp = root->right;
				w=search(15);
		//		cout<<print(w)<<endl;
				if(w==0)
					cout<<"SORRY NOT FOUND\n";
				else
					cout<<"YEP ME!\n";
			}
		
	}
