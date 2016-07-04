LL pow(LL a, LL b,LL m)
	{
		LL x=1,y=a;
		while(b > 0)
			{
				if(b%2 == 1)
					{
						x=(x*y);
						if(x>m) x%=m;
					}
						y = (y*y);
						if(y>m) y%=m;
						b /= 2;
				}
		return x%m;
	}
