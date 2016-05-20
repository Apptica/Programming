#include<bits/stdc++.h>
using namespace std;
/***********************Copy from here to use KMP on a string*************/
int f[1000];
void preprocess(string s)
	{
		int i,len,j=0;
		f[0] = 0;
		len = s.length();
		for(i=1;i<len;++i)
			{	
				if(s[i]==s[j])
					{
						f[i] = j + 1;
						++j;
					}
				else
					{
						f[i] = 0;
						j=0;
					}
			}
	}

int match(string haystack,string needle)
	{
		int len,len2,i=0,j=0;
		len = haystack.length();
		len2 = needle.length();
		while(i<len)
			{
				if(haystack[i]==needle[j])
					{
						++i;
						++j;
					}
				if(j==len2-1)
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
