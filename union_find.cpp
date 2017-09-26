struct node
	{
		LL rank;
		LL parent;	
		LL answer;
		LL sz;
		LL value;
	}s[1000005];
	
LL find_parent(LL x)
	{
		if(s[x].parent!=x)
			{
				s[x].parent = find_parent(s[x].parent);	
			}
		return s[x].parent;
	}
 
LL find_sz(LL node)
	{
		LL par = find_parent(node);
		return s[par].sz;
	}
 
LL find_max(LL node)
	{
		LL par = find_parent(node);
		return s[par].value;
	}

void join(LL x,LL y)
	{
		LL px = find_parent(x);
		LL py = find_parent(y);
		if(px == py)
			return;
		else
			{
				if(s[px].rank>s[py].rank)
					{
						s[py].parent = px;
						s[px].value = max(s[py].value,s[px].value);
						s[px].sz += s[py].sz;
						return;
					}
				if(s[px].rank<s[py].rank)
					{
						s[px].parent = py;
						s[py].value = max(s[px].value,s[py].value);
						s[py].sz += s[px].sz;
						return;
					}	
				if(s[px].rank==s[py].rank)
					{
						s[py].parent = px;
						s[px].rank = s[px].rank + 1;
						s[px].value = max(s[py].value,s[px].value);
						s[px].sz += s[py].sz;
						return;
					}
			}
	}
