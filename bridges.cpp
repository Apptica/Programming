/*
Saurabh Joshi
IIIT Jabalpur
*/
#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
#define endl "\n"
#define eps 0.00000001
LL pow(LL a,LL b,LL m){ a%=m;LL x=1,y=a;while(b > 0){if(b%2 == 1){x=(x*y);if(x>m) x%=m;}y = (y*y);if(y>m) y%=m;b /= 2;}return x%m;}
LL gcd(LL a,LL b){if(b==0) return a; else return gcd(b,a%b);}
LL gen(LL start,LL end){LL diff = end-start;LL temp = rand()%start;return temp+diff;}
using namespace std;
/****************************************/
//This algorithm finds all the articulation points in a graph and adds them to a set
const int maxn = 100001;
vector<int> graph[maxn];
bool br_visit[maxn + 1];
set<pair<int,int> > bridges;
int br_in[maxn + 1];
int br_low[maxn + 1];
int br_timer = 0;
void br_dfs(int node,int p = -1) {
    br_visit[node] = 1;
    br_in[node] = br_low[node] = ++br_timer;
    for(int i: graph[node]) {
        if(i == p)
            continue;
        if(br_visit[i] == 0) {
            br_visit[i] = 1;
            br_dfs(i, node);
            br_low[node] = min(br_low[node], br_low[i]);
            if(br_low[i] > br_in[node]) {
                bridges.insert({min(node , i) , max(node , i)});
            }
        }
        else {
            br_low[node] = min(br_low[node], br_in[i]);
        }
    }
}

void find_bridges(int n) {
    br_timer = 0;
    bridges.clear();
    for(int i = 1; i <= n; i++)
        br_visit[i] = 0;
    for(int i = 1; i <= n; i++) {
        if(br_visit[i] == 0) {
            br_dfs(i);
        }
    }
}

/****************************************/
int main()	{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, e;
    while(cin >> n >> e) {
        if(n == 0 && e == 0)
            break;
        for(int i = 1; i <= n; i++) 
            graph[i].clear();
        for(int i = 1; i <= e; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        find_bridges(n);
           cout << bridges.size() << endl;
    }
}