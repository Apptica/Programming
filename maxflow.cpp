//this program calculates maxflow of a graph g
#include<bits/stdc++.h>
using namespace std;
#define V_MAX 100
int parent[V_MAX+1];
queue<int>q;
bool visit[V_MAX+1]={0};
vector<int>graph[V_MAX+1];
int flow[V_MAX+1][V_MAX+1]={0};
bool bfs(int v,int end)
	{
		if(v==end)
			return 1;
		q.pop();//pops out the current vertex as front from the queue initially the pushed vertex is the starting one
		visit[v] = true;//mark the current vertex as the visited one for first time
		//iterator works on address basis
		for(vector<int>::iterator i=graph[v].begin();i!=graph[v].end();++i)
			{
				if((visit[*i]==false)&&(flow[v][*i]>0))
					{
						parent[*i] = v;
						q.push(*i);
					}
			}
		if(!q.empty())
			{
				return bfs(q.front(),end);
			}
		else
				return 0;
	}

int upgrade_path(int start,int end)
	{
		int x,min_edge=INT_MAX,temp=end;
		cout<<endl;
		while(end!=start)
			{
				cout<<end<<"<---";
				x = parent[end];
				min_edge = min(min_edge,flow[x][end]);
				end = x;
			}
		cout<<start<<endl;
		end = temp;
		while(end!=start)
			{
				x = parent[end];
				flow[x][end]-=min_edge;
				flow[end][x]+=min_edge;
				end = x;
			}
		cout<<"flow contributed:"<<min_edge<<endl;
		return min_edge;
	}

int maxflow(int start,int end)
	{
		int ans;
		int flow=0;
		parent[start] = start;
		q.push(start);
		while(bfs(start,end)!=0)
			{
				//cout<<"HELLO";
				flow = upgrade_path(start,end);
				ans = ans + flow;
				memset(visit,0,sizeof(visit));
				while(!q.empty())
					q.pop();
				q.push(start);
				//cout<<flow;
			}
		return ans;
	}
int main()
	{
		ios_base::sync_with_stdio(0);
		int j,v,e,i=0,s,t,f,x,y;
		cout<<"Enter total vertices:";
		cin>>v;
		cout<<"Enter total edges:";
		cin>>e;
		while(i<e)
			{
				cin>>x>>y>>f;
				flow[x][y]=f;
				flow[y][x]=0;
				graph[x].push_back(y);
				graph[y].push_back(x);
				++i;
			}
		cout<<"Enter source and destination:";
		cin>>s>>t;
		cout<<maxflow(s,t);
		/*for(cout<<endl,i=1;i<=v;++i,cout<<endl)
			for(j=1;j<=v;++j)
				cout<<flow[i][j]<<" ";*/
	}
