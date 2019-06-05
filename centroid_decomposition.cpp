set<int> graph[maxn];
int subtree_sz[maxn];
int cur_sz = 0;
void dfs(int node,int p = -1) {
    subtree_sz[node] = 1;
    for(int i: graph[node]) {
        if(i != p) {
            dfs(i , node);
            subtree_sz[node] += subtree_sz[i];
        }
    }
}

int get_center(int node, int p) {
    for(int i: graph[node]) {
        if(i != p) {
            if(subtree_sz[i] > cur_sz / 2)
                return get_center(i , node);
        }
    }
    return node;
}

int find_centroid(int node) {
    dfs(node);
    cur_sz = subtree_sz[node];
    return get_center(node, -1);
}
