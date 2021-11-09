#include<bits/stdc++.h>
using namespace std;
#define read yh
#define int long long
#define hvie '\n'
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
int yh(){
	int ret=0;char c=getchar();int f=0;
	while(!isdigit(c)) {if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){ret=ret*10+c-'0';c=getchar();}
	return f?-ret:ret;
}
const int N=1205;

int n;
int d[N];
int t[4][N],dis[4][N];

signed main(){
	n=read();
	for(int i=1;i<=n;++i) d[i]=d[i+n]=d[i+2*n]=read();
	for(int j=1;j<=3;++j) 
	{
		for(int i=1;i<=n;++i) t[j][i]=t[j][i+n]=t[j][i+n*2]=read();
		for(int i=1;i<=3*n;++i) dis[j][i]=t[j][i]+d[i]+dis[j][i-1];
	}
	for(int i=1;i<=n;++i)
	{
		int p=i;
		for(int j=i+1;j<i+n;++j)
		{
			bool fg=1;
			for(int k=j;k<i+n;++k)
			{
				if(dis[1][k-1]-dis[1][i-1]<dis[2][k-1]-dis[2][j-1]+t[2][k]) 
				{
					fg=0;
					break;
				}
			}
			if(fg) 
			{
				p=j;
				break;
			}
		}
		if(p==i) continue;
		int q=p;
		for(int j=p+1;j<i+n;++j)
		{
			bool fg=1;
			for(int k=j;k<p+n;++k)
			{
				if(dis[2][k-1]-dis[2][p-1]<dis[3][k-1]-dis[3][j-1]+t[3][k]) 
				{
					fg=0;
					break;
				}
			}
			if(fg) 
			{
				q=j;
				break;
			}
		}
		if(q==p) continue;
		//printf("maybe:%d %d %d\n",i,p,q);
		bool fg=1;
		for(int k=i;k<i+n;++k)
		{
			if(dis[3][k+n-1]-dis[3][q-1]<dis[1][k-1]-dis[1][i-1]+t[1][k])
			{
				fg=0;
				break;
			}
		}
		if(!fg) continue;
		if(q-i+1>n) continue;
		printf("%lld %lld %lld\n",i,(p-1)%n+1,(q-1)%n+1);
		return 0;
	}

	for(int i=1;i<=3*n;++i) swap(t[2][i],t[3][i]),swap(dis[2][i],dis[3][i]);

	for(int i=1;i<=n;++i)
	{
		int p=i;
		for(int j=i+1;j<i+n;++j)
		{
			bool fg=1;
			for(int k=j;k<i+n;++k)
			{
				if(dis[1][k-1]-dis[1][i-1]<dis[2][k-1]-dis[2][j-1]+t[2][k]) 
				{
					fg=0;
					break;
				}
			}
			if(fg) 
			{
				p=j;
				break;
			}
		}
		if(p==i) continue;
		int q=p;
		for(int j=p+1;j<i+n;++j)
		{
			bool fg=1;
			for(int k=j;k<p+n;++k)
			{
				if(dis[2][k-1]-dis[2][p-1]<dis[3][k-1]-dis[3][j-1]+t[3][k]) 
				{
					fg=0;
					break;
				}
			}
			if(fg) 
			{
				q=j;
				break;
			}
		}
		if(q==p) continue;
		//printf("maybe:%d %d %d\n",i,p,q);
		bool fg=1;
		for(int k=i;k<i+n;++k)
		{
			if(dis[3][k+n-1]-dis[3][q-1]<dis[1][k-1]-dis[1][i-1]+t[1][k])
			{
				fg=0;
				break;
			}
		}
		if(!fg) continue;
		if(q-i+1>n) continue;
		printf("%lld %lld %lld\n",i,(q-1)%n+1,(p-1)%n+1);
		return 0;
	}
	puts("impossible");
	return 0;
}
