struct Data_Maker{
	long long Seed,a,b,c,MOD;
	long long Random() {
		c++;
		Seed=(Seed*a+b*c)%MOD;
		return Seed;
	}
	int Random_int() {
		int tmp=Random();
		if(Random()&1)tmp*=-1;
		return tmp;
	}
	void MAKE(){
		scanf("%lld%lld%lld%lld%lld",&Seed,&a,&b,&c,&MOD);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				A[i][j]=Random_int();
	}
};
