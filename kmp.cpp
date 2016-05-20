#include<bits/stdc++.h>
using namespace std;
/***********************Copy from here to use KMP on a string*************/
int f[1000]={0};
void preprocess(string s)
	{
		int i=1,len,j=0;//j is the counter that is used to fill the f values
		f[0] = 0;//f[0] has to be zero always as no proper prefix and suffix exists
		len = s.length();
		while(i<len)
			{	
				if(s[i]==s[j])//in case the characters are succesfully matching in a sequence
					{
						f[i] = j + 1;
						++j;
						++i;
					}
				else
					{
						if(j==0)//if the suffix is dismatched to the first character of prefix
							{
								f[i] = 0;
								j=0;
								++i;
							}
						else//look if there may be chance that any sub suffix would be matching to some previous j
							{
								j = f[j-1];
							}
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
