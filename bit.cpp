//BIT[i] array stores the cumulative sum from the index i to i - (1<<r) + 1 where r is the rightmost set bit in i
void update(int x, int val)  
	{	
    	for(; x <= n; x += x&-x)
        	  BIT[x] += val;
	}	

int query(int x)
	{
     	int sum = 0;
     	for(; x > 0; x -= x&-x)
        	 sum += BIT[x];
     	return sum;
	}
