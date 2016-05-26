void bfs(int v)
	{
		q.pop();
		visit[v] = true;
		for(vector<int>::iterator i=graph[v].begin();i!=graph[v].end();++i)
			{
				if(visit[*i]==false)
					{
						q.push(*i);
						parent[*i] = v;
					}
			}
		if(!q.empty())
			{
				bfs(q.front());
			}
	}
