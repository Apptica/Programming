#include<bits/stdc++.h>
using namespace std;
/***********************Copy from here to use KMP on a string*************/
int f[1000];
void preprocess(string s)
	{
		int i,len;
		f[0] = 0;
		f[1] = 0;
		len = s.length();
		for(i=2;i<len;++i)
			{	
				if(s[i]==s[f[i-1]])
					{
						f[i] = f[i-1] + 1;
					}
				else
					{
						f[i] = 0;
					}
			}
	}

int match(string haystack,string needle)
	{
		int len,len2,i,j;
		len = haystack.length();
		len2 = needle.length();
		while(i<len)
			{
				if(haystack[i]==needle[j])
					{
						++i;
						++j;
					}
				if(j==len2)
					{
						return 1;
					}
				if(haystack[i]!=needle[j]&&i<len)
					{
						if(j!=0)
							{
								j = f[j-1];
							}
						else	
							++i;
					}
			}
		return 0;
	}
/*************************************************************************/
int main()
	{
		int i;
		string s,t;
		cout<<"Enter haystack string:";
		cin>>s;
		cout<<"Enter needle:";
		cin>>t;
		preprocess(t);
		for(i=0;i<t.length();++i)
			cout<<f[i]<<" ";
		cout<<"\n";
		//my f stores the preprocessed KMP function
		cout<<"Status : "<<match(s,t)<<endl;
	}
