/*
Saurabh Joshi
IIIT Jabalpur
*/
#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
#define endl "\n"
#define eps 0.00000001
LL pow(LL a,LL b,LL m){LL x=1,y=a;while(b > 0){if(b%2 == 1){x=(x*y);if(x>m) x%=m;}y = (y*y);if(y>m) y%=m;b /= 2;}return x%m;}
LL gcd(LL a,LL b){if(b==0) return a; else return gcd(b,a%b);}
LL gen(LL start,LL end){LL diff = end-start;LL temp = rand()%start;return temp+diff;}
using namespace std;
/******************* Dijkstra Algorithm ElogE ********************/
#define maxn 100000
vector<pair<int , LL> > graph[maxn + 1];
int parent[maxn + 1];
LL d[maxn + 1];
//dijkstra(source , total_nodes)
void dijkstra(int source,int n){
    LL inf = 100000000000000000LL;// (1e+17 default) Check this always before submitting
    d[source] = 0;
    set<pair<LL , int> > s;
    s.insert({d[source] , source});
    for(int i = 1; i <= n; i++){
        if(i != source){
            d[i] = inf;
            s.insert({d[i] , i});
        }
    }
    bool visit[n + 1];
    memset(visit , 0 , sizeof(visit));
    while(s.size()){
        pair<LL , int> node = *s.begin();
        int u = node.second;
        visit[u] = 1;
        s.erase(s.begin());
        for(pair<int , LL> node: graph[u]){
            int v = node.first;;
            LL w = node.second;
            if(visit[v] == 0){
                if(d[u] + w < d[v]){
                    s.erase({d[v] , v});
                    d[v] = d[u] + w;
                    parent[v] = u;
                    s.insert({d[v] , v});
                }
            }
        }
    }

}
/******************* Dijkstra Algorithm ElogE ********************/
int main()
    {
        ios_base::sync_with_stdio(0);
        int n , m, r , x , y;
        cin >> n >> m >> r >> x >> y;
        for(int i = 1; i <= r; i++){
            int u , v;
            LL w;
            cin >> u >> v >> w;
            graph[u].push_back({v , w});
            graph[v].push_back({u , w});
        }
        dijkstra(x , n);
        if(d[y] <= m){
            cout << "alive" << " " << d[y];
        }
        else{
            cout << "died" << endl;
        }
    }
