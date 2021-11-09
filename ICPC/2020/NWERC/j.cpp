#include<bits/stdc++.h>
using namespace std;
#define double long double
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
const int maxn=4e5+5;
const double inf=1e12;
int n,m;
int to[maxn],nxt[maxn],h[maxn],en=0;
set<int>no,yes;
void addedge(int x,int y){
	to[++en]=y;
	nxt[en]=h[x];
	h[x]=en;
}
bool vis[maxn];
int path[maxn];
#define y to[i]
void dfs(int x,int dep){
	vis[x]=1;
	no.erase(x);
	path[dep]=x;
	if(no.size()==yes.size()){
		cout<<dep<<" "<<no.size()<<hvie;
		rep(i,1,dep) cout<<path[i]<<" ";puts("");	
		for(int i:no) cout<<i<<" ";puts("");
		for(int i: yes) cout<<i<<" ";puts("");
		exit(0);
	}
	for(int i=h[x];i;i=nxt[i]){
		if(!vis[y]){
			vis[y]=1;
			dfs(y,dep+1);
		}
	}
	yes.insert(x);
	// cout<<no.size()<<" ~ "<<yes.size()<<hvie;
	if(no.size()==yes.size()){
		cout<<dep-1<<" "<<no.size()<<hvie;
		rep(i,1,dep-1) cout<<path[i]<<" ";puts("");	
		for(int i:no) cout<<i<<" ";puts("");
		for(int i: yes) cout<<i<<" ";puts("");
		exit(0);
	}
}
#undef y

signed main(){
	n=yh();
	m=yh();
	rep(i,1,m){int x=yh(),y=yh();addedge(x,y);addedge(y,x);}
	rep(i,1,n)no.insert(i);
	dfs(1,1);
	assert(0);
	return 0;
}
