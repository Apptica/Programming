#include<bits/stdc++.h>
using namespace std;
/***********************************/
int dp[1001]={0};
int idx[1001]={0};//to store the maximum helping index
int lis(string s)
	{
		int ans=0,temp;
		int i,j;
		for(i=0;i<s.length();i++)
			{
				idx[i] = i;
				dp[i] = 1;
				for(j=0;j<i;++j)
					{
						if(s[i]>=s[j])
							{
								if(1+dp[j]>=dp[i])
									{
										idx[i]=j;
										dp[i] = 1 + dp[j];
									}
							}
					}
				if(dp[i]>dp[ans])
					ans = i;
					
			}
		temp = dp[ans];
		while(1)
			{
				cout<<s[ans];
				if(dp[ans]==1)
					break;
				ans = idx[ans];
			}
		cout<<endl;
		return temp;
	}
/***********************************/
int main()
	{
		string s;
		cin>>s;
		cout<<lis(s);
	}
