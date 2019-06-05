/**** Compressed Super Node Tree ****/
const int maxn = 100001;
int sz;
int sq_depth[maxn];
int sq_parent[maxn];
bool sq_visit[maxn];
vector<int> sq_graph[maxn];
int sq_LCA[maxn][20];
bool is_supernode[maxn], is_special[maxn], is_first_supernode[maxn];
vector<int> specials, super_nodes, first_supernodes;
int super_parent[maxn];
int which[maxn];//the number of component to which that node belongs if it belongs to a super-node path (-1 for orphaned nodes)
vector<int> which_nodes[maxn];//the nodes that belong to component i

void sq_preprocess_lca(int n)  {
    for(int i = 1; i < 18; i++) {
        for(int j = 1; j <= n; j++) {
            sq_LCA[j][i] = sq_LCA[sq_LCA[j][i - 1]][i - 1];
        }
    }
}

int sq_lca(int u, int v) {
    if (sq_depth[u] < sq_depth[v]) {
        swap(u, v);
    }
    int len = sq_depth[u] - sq_depth[v];
    for (int j = 18; j >= 0; j --) {
        if (len & (1 << j)) {
            u = sq_LCA[u][j];
        }
    }
    if (u == v) {
        return u;
    }
    for (int j = 18; j >= 0; j --) {
        if (sq_LCA[u][j] != sq_LCA[v][j]) {
            u = sq_LCA[u][j];
            v = sq_LCA[v][j];
        }
    }
    return sq_LCA[u][0];
}


void sq_dfs(int node,int p = 0) {
    if(sq_depth[node] % sz == 0) {
        is_special[node] = 1;
        specials.push_back(node);
    }
    for(int i: sq_graph[node]) {
        if(i != p) {
            sq_parent[i] = node;
            sq_LCA[i][0] = node;
            sq_depth[i] = sq_depth[node] + 1;
            sq_dfs(i, node);
        }
    }
}


void build_sqrt_tree(int n) {
    sq_parent[1] = -1;
    specials.clear();
    super_nodes.clear();
    first_supernodes.clear();
    for(int i = 1; i <= n; i++) {
        which[i] = -1;
        is_special[i] = 0;
        is_supernode[i] = 0;
        super_parent[i] = -1;
        sq_visit[i] = 0; 
    }
    sq_dfs(1, 0);
    sq_parent[1] = -1;
    sq_preprocess_lca(n);
    for(int i = 0; i < specials.size(); i++) {
        int cur = sq_parent[specials[i]];
        while(cur != -1) {
            if(is_special[cur]) {
                is_supernode[cur] = 1;
                first_supernodes.push_back(cur);
                is_first_supernode[cur] = 1;
                break;
            }
            cur = sq_parent[cur];
        }
    }
    first_supernodes.push_back(1);
	is_first_supernode[1] = 1;
	is_supernode[1] = 1;
    super_nodes = first_supernodes;
    for(int i = 0; i < first_supernodes.size(); i++) {
        int node = first_supernodes[i];
        if(node == 1)
            continue;
        int cur = sq_parent[node];
        while(is_first_supernode[cur] == 0 && sq_visit[cur] == 0) {
            sq_visit[cur] = 1;
            cur = sq_parent[cur];
        }
        if(is_first_supernode[cur] == 0) {
            is_supernode[cur] = 1;
            super_nodes.push_back(cur);
        }
    }
    bool visit[n + 1] = {0};
    for(int i = 0; i < super_nodes.size(); i++) {
        int node = super_nodes[i];
        if(node == 1 || visit[node] == 1)
            continue;
        visit[node] = 1;
        int cur = node; 
        while(1) {
            which[cur] = i;
            which_nodes[i].push_back(cur);
            cur = sq_parent[cur];
            if(is_supernode[cur] == 1)
                break;
        }
        super_parent[i] = cur;
    }
    /* use this part to prepare the data structure based on the requirement for each component */
    for(int i = 0; i < n; i++) {
        if(which_nodes[i].size() == 0)
            continue;
        sq_ds[i] = hull_optimizer(true);
        for(int node: which_nodes[i]) {
            sq_ds[i].add_line(K[node] , B[node]);
        }
    } 
}

void rebuild_ds(int id) {
    sq_ds[id] = hull_optimizer(true);
    for(int node: which_nodes[id]) {
        sq_ds[id].add_line(K[node] , B[node]);
    }
}

LL sq_query(int id, LL x) { // query the entire block - id
    LL ans = 0;
    ans = sq_ds[id].query(x);
    ans = ans + (x * lazy_K[id]) + lazy_B[id];
    return ans;
}

void sq_update(int id, LL k, LL b) { // update the entire block - id
    lazy_K[id] += k;
    lazy_B[id] += b;
}

LL query_brute(int node, LL x) { // query a particular node
    if(node == 0) {
        return -1000000000000000000LL;
    }
    int id = which[node];
    return (K[node] + lazy_K[id]) * x + (B[node] + lazy_B[id]);
}

void update_brute(int node, LL a, LL b) { // update a particular node
    K[node] += a;
    B[node] += b;
    cur_updates.insert(which[node]);
}

LL sq_query_up(int u,int v,LL x) {
    LL ans = -1000000000000000000LL;
    while(u != v) {
        if(is_supernode[u]) {
            if(sq_depth[super_parent[which[u]]] >= sq_depth[v]) {
                ans = max(ans , sq_query(which[u] , x));
                u = super_parent[which[u]];
            }
            else {
                LL temp = query_brute(u , x);
                ans = max(ans , temp);
                u = sq_parent[u];
            }
        }
        else {
            LL temp = query_brute(u , x);
            ans = max(ans , temp);
            u = sq_parent[u];
        }
    }
    return ans;
}


void sq_update_up(int u,int v,LL a, LL b) {
    while(u != v) {
        if(is_supernode[u]) {
            if(sq_depth[super_parent[which[u]]] >= sq_depth[v]) {
                sq_update(which[u], a, b);
                u = super_parent[which[u]];
            }
            else {
                update_brute(u , a , b);
                u = sq_parent[u];
            }
        }
        else {
            update_brute(u, a, b);
            u = sq_parent[u];
        }
    }
}

LL sq_query(int u,int v,LL x) {
    int lca = sq_lca(u , v);
    LL res = max(sq_query_up(u, lca, x) , sq_query_up(v , lca, x));
    return max(res , query_brute(lca , x));
}

void sq_update(int u,int v, LL x, LL y) {
    int lca = sq_lca(u , v);
    cur_updates.clear();
    sq_update_up(u , lca , x , y);
    sq_update_up(v , lca , x , y);
    update_brute(lca, x , y);
    cur_updates.insert(which[lca]);
    for(int i: cur_updates) {
        if(i != -1) {
            rebuild_ds(i);
        }
    }
}

/**** Implementation ends ****/
