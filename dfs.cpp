void dfs(int v,int parent)
	{
	  visit[*i] = true;
		for(vector<int>::iterator i=graph[v].begin();i!=graph[v].end();++i)
			{
				if(visit[*i]==false)
					{
						dfs(*i,v);
					}
			}
	}
