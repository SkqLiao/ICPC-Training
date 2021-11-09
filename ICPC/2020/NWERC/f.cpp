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
const int maxn=2e5+5;
const double inf=1e12;
int pre[maxn],nxt[maxn];
struct node{
	int l,r;
	double t;
	bool operator<(const node&a)const{return t>a.t;}
};

int n;
int a[maxn],x[maxn],v[maxn];

void del(int x){
	if(pre[x]) nxt[pre[x]]=nxt[x];
	if(nxt[x]) pre[nxt[x]]=pre[x];
	pre[x]=nxt[x]=0;
}

bool vis[maxn];

signed main(){
	n=yh();
	rep(i,1,n){
		if(i>1) pre[i]=i-1,nxt[i-1]=i;
		x[i]=yh(),v[i]=yh();
	}
	priority_queue<node>q;
	rep(i,1,n-1){
		if(v[i]>v[i+1]){
			q.push((node){i,i+1,(double)(x[i+1]-x[i])/(v[i]-v[i+1])});
			// cout<<"??? "<<i<<" "<<i+1<<" "<<(double)(x[i+1]-x[i])/(v[i]-v[i+1])<<hvie;
		}
	}
	while(!q.empty()){
		// cout<<"??"<<q.size()<<" "<<hvie;
		int l=q.top().l,r=q.top().r;double t=q.top().t;
		q.pop();
		if(t==inf) continue;
		if(vis[l]||vis[r]){
			// cout<<"vis"<<l<<" "<<r<<endl;
			continue;
		}
		int pl=pre[l],nr=nxt[r];
		vis[l]=vis[r]=1;
		del(l);del(r);
		// cout<<"crash "<<l<<" "<<r<<hvie;
		if(!pl||!nr){
			// cout<<"out"<<" "<<l<<" "<<r<<hvie;
			continue;
		}
		if(v[pl]>v[nr]){
			q.push((node){pl,nr,(double)(x[nr]-x[pl])/(v[pl]-v[nr])});
		}
		else{
		}
	}
	int cnt=0;
	rep(i,1,n)if(!vis[i])cnt++;
	cout<<cnt<<hvie;
	rep(i,1,n)if(!vis[i])cout<<i<<" ";
	cout<<hvie;
	return 0;
}
