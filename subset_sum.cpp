#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
#define reset(a) memset(a,0,sizeof(a))
#define rep(i,j,k) for(i=j;i<=k;++i)
#define per(i,j,k) for(i=j;i>=k;--i)
#define endl "\n"
#define print(a,start,end) for(i=start;i<=end;++i) cout<<a[i]<<" "; cout<<endl;
using namespace std;
bool dp[2][1005];
int check(int);
int a[1005],n;
int main()
    {
        int i,sum;
        ios_base::sync_with_stdio(0);
        cin>>n;
        rep(i,1,n)
            {
                cin>>a[i];
            }
        cin>>sum;
        if(check(sum)==1)
            cout<<"Yeah! the sum exists"<<endl;
        else
            cout<<"Sorry!"<<endl;
    }
    
int check(int sum)
    {
        int flag=1;
        int i,j=0;
        print(a,1,n);
        rep(i,0,sum)
            {
                dp[0][i]=1;
                dp[1][i]=0;
            }
        rep(i,1,n)
            {
                rep(j,0,sum)
                    {
                        if(dp[1-flag][j]==1)
                            {
                                dp[flag][j]=1;
                            }
                        else
                            {
                                if(j>=a[i])
                                    {
                                        if(dp[1-flag][j-a[i]]==1)
                                            dp[flag][j]=1;
                                    }
                            }
                    }
                 flag = 1-flag;
            }
        if(n%2==0)
            {
                return dp[0][sum];
            }
        else
                return dp[1][sum];
    }
