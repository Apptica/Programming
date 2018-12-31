int max_up[100001][20];
int dp[100001][20];
int depth[100001];
vector<pair<int,int> > graph[1000001];
int n;//This n needs to be set for the particular testcase
int query(int u , int v)    {
    assert(u <= n && v <= n);
    if(depth[u] < depth[v])    {
        swap(u , v);
    }
    int ans = 0;
    int len = depth[u] - depth[v];
    for(int j = 18; j >= 0; j--)    {
        if(len & (1 << j))  {
            ans = max(ans , max_up[u][j]);
            u = dp[u][j];
        }
    }
    if(u == v)  {
        return ans;
    }
    for(int j = 18; j >= 0; j--)    {
        if(dp[u][j] != dp[v][j])    {
            ans = max(ans , max_up[u][j]);
            ans = max(ans , max_up[v][j]);
            u = dp[u][j];
            v = dp[v][j];
        }
    }
    ans = max(ans , max_up[v][0]);
    ans = max(ans , max_up[u][0]);
    return ans;

}

void pre_process(int n)  {
    for(int i = 1; i < 18; i++) {
        for(int j = 1; j <= n; j++) {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
            max_up[j][i] = max(max_up[j][i - 1] , max_up[dp[j][i - 1]][i - 1]);
        }
    }
}

void dfs(int node,int p = -1)  {
    if(p != -1) {
        depth[node] = depth[p] + 1;
    }
    for(pair<int,int> temp: graph[node])    {
        int v = temp.first;
        int w = temp.second;
        if(v != p){
            dp[v][0] = node;
            max_up[v][0] = w;
            dfs(v , node);
        }
    }
}
