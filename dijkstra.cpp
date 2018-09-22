void dijkstra()
	{
		for(int i = 1; i <= n ; i++)
			dist[i] = 1000000000000000LL;
		set<pair<LL,int> > s;
		dist[1] = 0;
		s.insert(make_pair(0LL , 1));
		for(int i = 2; i <= n; i++)
			{
				s.insert(make_pair(1000000000000000LL, i));
			}
		while(s.size())
			{
				pair<LL,int> node = *s.begin();
				int u = node.second;
				s.erase(s.begin());
				visit[u] = 1;
				for(pair<int,int> node2 : graph[u])
					{
						int v = node2.first;
						if(visit[v] == 1)
							continue;
						int w = node2.second;
						if(dist[v] > dist[u] + w)
							{
                parent[v] = u;
								s.erase(s.find(make_pair(dist[v] , v)));
								s.insert(make_pair(dist[u] + w , v));
								dist[v] = dist[u] + w;
							}
					}
			}
	}
