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
/********************** copy from here to use scc ***********************/
//scc[1..scc_cnt] stores all the components
//label[i] is the component id of i^th node 
const int max_nodes = 100001;
vector<int> graph[max_nodes];
vector<int> graph_t[max_nodes];
vector<int> scc[max_nodes];
int label[max_nodes];
int scc_cnt = 0;
vector<int> order;
bool scc_visit[max_nodes];
void scc_dfs_1(int node) {
    scc_visit[node] = 1;
    for(int i: graph[node]) {
        if(scc_visit[i] == 0) {
            scc_visit[i] = 1;
            scc_dfs_1(i);
        }
    }
    order.push_back(node);
}

void scc_dfs_2(int node) {
    scc_visit[node] = 1;
    label[node] = scc_cnt;
    scc[scc_cnt].push_back(node);
    for(int i: graph_t[node]) {
        if(scc_visit[i] == 0) {
            scc_visit[i] = 1;
            scc_dfs_2(i);
        }
    }
}

void find_scc(int n) {
    order.clear();
    for(int i = 1; i <= n; i++) {
        scc_visit[i] = 0;
        graph_t[i].clear();
    }
    for(int i = 1; i <= n; i++) {
        if(scc_visit[i] == 0)
            scc_dfs_1(i);
    }
    for(int i = 1; i <= n; i++) {
        for(int v: graph[i]) {
            graph_t[v].push_back(i);
        }
    }
    reverse(order.begin(), order.end());
    for(int i = 1; i <= n; i++)
        scc_visit[i] = 0;
    for(int i = 0; i < order.size(); i++) {
        if(scc_visit[order[i]] == 0) {
            ++scc_cnt;
            scc_visit[order[i]] = 1;
            scc_dfs_2(order[i]);
        }
    }
}

/********************** :) ***********************/

int main()	{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, e;
    cin >> n >> e;
    for(int i = 1; i <= e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    find_scc(n);
}