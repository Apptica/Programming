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
bool ap_visit[maxn + 1];
set<int> articulation_points;
int ap_in[maxn + 1];
int ap_low[maxn + 1];
int ap_timer = 0;
void ap_dfs(int node,int p = -1) {
    ap_visit[node] = 1;
    ap_in[node] = ap_low[node] = ++ap_timer;
    int children = 0;
    for(int i: graph[node]) {
        if(i == p)
            continue;
        if(ap_visit[i] == 0) {
            ap_visit[i] = 1;
            ap_dfs(i, node);
            ap_low[node] = min(ap_low[node], ap_low[i]);
            if(ap_low[i] >= ap_in[node] && p != -1)
                articulation_points.insert(node);
            ++children;
        }
        else {
            ap_low[node] = min(ap_low[node], ap_in[i]);
        }
    }
    if(p == -1 && children > 1)
        articulation_points.insert(node);
}

void find_articulation_points(int n) {
    ap_timer = 0;
    articulation_points.clear();
    for(int i = 1; i <= n; i++)
        ap_visit[i] = 0;
    for(int i = 1; i <= n; i++) {
        if(ap_visit[i] == 0) {
            ap_dfs(i);
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
        find_articulation_points(n);
        cout << articulation_points.size() << endl;
    }
}