/********** Max flow E * MaxFlow complexity implementation **********/
/*
    The code can be optimized by intelligently cleaned 
*/
#define maxn 100
int cap[maxn + 1][maxn + 1];
vector<int> graph[maxn + 1];
vector<pair<int,int> > edges;
bool flag = 0;
bool visit[maxn + 1];
void find_augmented(int cur, int t){
    if(cur == t){
         flag = 1;
         return;
    }
    for(int i: graph[cur]){
        if(visit[i] == 0){
            if(cap[cur][i] > 0){
                edges.push_back({cur , i});
                visit[i] = 1;
                find_augmented(i , t);
                if(flag == 1){
                    break;
                }
                edges.pop_back();
            }
        }
    }
    return;
}
 
int update_augmented(){
    int mcap = cap[edges.back().first][edges.back().second];
    for(int i = 0;i < edges.size(); i++){
        mcap = min(mcap , cap[edges[i].first][edges[i].second]);
    }
    for(int i = 0; i < edges.size(); i++){
        cap[edges[i].first][edges[i].second] -= mcap;
        cap[edges[i].second][edges[i].first] += mcap;
    }
    return mcap;
}
 
int maxflow(int n,int s,int t){
    int ans = 0;
    memset(visit , 0 , sizeof(visit));
    edges.clear();
    while(1){
        flag = 0;
        find_augmented(s , t);
        if(flag == 0)
            break;
        ans += update_augmented();
        memset(visit , 0 , sizeof(visit));
        edges.clear();
    }
    return ans;
}
 /********** Max flow E * MaxFlow complexity implementation **********/
