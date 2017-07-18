//codeforces 427C
#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
#define reset(a) memset(a,0,sizeof(a))
#define rep(i,j,k) for(i=j;i<=k;++i)
#define per(i,j,k) for(i=j;i>=k;--i)
#define print(a,start,end) for(i=start;i<=end;++i) cout<<a[i];
#define endl "\n"
#define inf 100000000000000
LL pow(LL a,LL b,LL m){LL x=1,y=a;while(b > 0){if(b%2 == 1){x=(x*y);if(x>m) x%=m;}y = (y*y);if(y>m) y%=m;b /= 2;}return x%m;}
LL gcd(LL a,LL b){if(b==0) return a; else return gcd(b,a%b);}
LL gen(LL start,LL end){LL diff = end-start;LL temp = rand()%start;return temp+diff;}
using namespace std;
int x = 0;
LL a[300001];
vector<int> graph[300001];
int u[300001];
int v[300001];
bool visit[300001] = {0};
vector<int> nodes;
void dfs(int node)
	{
		visit[node] = 1;
		vector<int>::iterator it = graph[node].begin();
		while(it != graph[node].end())
			{
				if(visit[*it] == 0)
					{
						visit[*it] = 1;
						dfs(*it);
					}
				++it;
			}
		nodes.push_back(node);//in the end time order for each node	
	}
LL ans = 1000000000000000000;
int dfs2(int node)
	{
		visit[node] = 1;
		vector<int>::iterator it = graph[node].begin();
		while(it != graph[node].end())
			{
				if(visit[*it] == 0)
					{	
						visit[*it] = 1;
						dfs2(*it);
					}
				++it;
			}
		if(ans > a[node])
			{
				x = 1;
			}
		else if(ans == a[node])
			{
				++x;
			}
		ans = min(ans , a[node]);
	}

int main()
	{
		int n;
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++)
			scanf("%lld" , &a[i]);
		int m;
		cin >> m;
		for(int i = 1 ; i <= m ; i++)
			{
				scanf("%d%d", &u[i] , &v[i]);
				graph[u[i]].push_back(v[i]);
			}
		//count strongly connected components
		for(int i = 1 ; i <= n ; i++)
			{
				if(visit[i] == 0)
					dfs(i);
			}
		for(int i = 1 ; i <= n ; i++) graph[i].clear();
		for(int i = 1 ; i <= m ; i++)//the transpose graph
			{
				graph[v[i]].push_back(u[i]);
			}
		LL ans1 = 1 , ans2 = 0;
		memset(visit , 0 , sizeof(visit));
		for(int i = (nodes.size()) - 1 ; i >= 0 ; i--)
			{
				if(visit[nodes[i]] == 0)
					{
					 	x = 0;
						ans  = inf;
						visit[nodes[i]] = 1;
						dfs2(nodes[i]);
						ans2 += ans;
						ans1 *= x;		
						if(ans1 >= M) ans1 %= M;
						//cout << ans << endl;
					}
			}
		cout << ans2 << " " << ans1 << endl;
	}
