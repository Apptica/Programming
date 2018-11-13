//mst using kruskals algorithm
#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
#define reset(a) memset(a,0,sizeof(a))
#define rep(i,j,k) for(i=j;i<=k;++i)
#define per(i,j,k) for(i=j;i>=k;--i)
#define print(a,start,end) for(i=start;i<=end;++i) cout<<a[i];
#define endl "\n"
#define mp make_pair
using namespace std;
vector < int > tree[1001];
vector < pair < pair < int, int > , int > > V;
vector < pair < pair < int, int > , int > > ::iterator it;
bool cmp(pair < pair < int, int > , int > a, pair < pair < int, int > , int > b) {
  if (a.second < b.second)
    return 1;
  return 0;
}
struct node {
  int rank;
  int parent;
}
s[1005];

int find_parent(int x) {
  if (s[x].parent != x) {
    s[x].parent = find_parent(s[x].parent);
  }
  return s[x].parent;
}

void join(int x, int y) {
  int px = find_parent(x);
  int py = find_parent(y);
  if (px == py)
    return;
  else {
    if (s[px].rank > s[py].rank) {
      s[py].parent = px;
      return;
    }
    if (s[px].rank < s[py].rank) {
      s[px].parent = py;
      return;
    }
    if (s[px].rank == s[py].rank) {
      s[py].parent = px;
      s[px].rank = s[px].rank + 1;
      return;
    }
  }
}
int main() {
  int n, e, u, v, w, cost = 0, i;
  ios_base::sync_with_stdio(0);
  cin >> n >> e;
  rep(i, 1, n) {
    s[i].parent = i;
    s[i].rank = 0;
  }
  while (e--) {
    cin >> u >> v >> w;
    V.push_back(mp(mp(u, v), w));
  }
  sort(V.begin(), V.end(), cmp);
  it = V.begin();
  while (it != V.end()) {
    u = ( * it).first.first;
    v = ( * it).first.second;
    if (find_parent(u) != find_parent(v)) {
      join(u, v);
      tree[u].push_back(v);
      tree[v].push_back(u);
      cost = cost + ( * it).second;
    }
    it++;
  }
  cout << cost << endl;
}
