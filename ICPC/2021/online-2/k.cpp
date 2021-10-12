#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;i++)
#define dwn(i,a,b) for(int i=(a),i##end=(b);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define hvie '\n'
typedef long long ll;
typedef pair<int,int> pii;

int yh(){
    int ret=0,f=0;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
    while(isdigit(c)){ret=ret*10+(c^48);c=getchar();}
    return f?-ret:ret;
}
#define int long long
const int mod=998244353;
int n,m;
int a[25][25];
int dp[25][1<<20|7];
int inv[2025];
int sum[25][1<<20|7];
int mul(int x,int y){return (ll)x*y%mod;}
int b[1<<20|7];
int bts[1<<20|7][22],tot[1<<20|7];
int ans[25][25];
vector<int>stas[25];
signed main(){
	inv[1]=1;
	for(int i=2;i<=2005;i++) inv[i]=(mod-(ll)(mod/i)*inv[mod%i]%mod)%mod;
	for(int i=0;i<=20;i++) b[1<<i]=i;
	n=yh();
	rep(i,0,n-1) rep(j,0,n-1){
		a[i][j]=yh();
	}
	
	int mask=(1<<n)-1;
	rep(i,0,mask){
		stas[__builtin_popcount(i)].pb(i);
	}
	for(int i=0;i<n;i++){
		rep(j,0,mask)if(!(j&(1<<i))){
			bts[j|(1<<i)][++tot[j|(1<<i)]]=i;
		}
	}

	rep(i,0,n-1){
		sum[i][0]=0;
		rep(s,1,mask){
			sum[i][s]=sum[i][s^(s&-s)]+a[i][b[s&-s]];
		}
	}

	dp[0][mask]=1;
	rep(i,0,n-1){
		for(int s:stas[n-i])
		if(dp[i][s]){
			rep(k,1,tot[s]){
				int j=bts[s][k];
				(dp[i+1][s^(1<<j)]+=mul(dp[i][s],mul(a[i][j],inv[sum[i][s]])))%=mod;
			}
		}
	}

	rep(i,0,n-1){
		for(int s:stas[n-i]){
			rep(k,1,tot[s]){
				int j=bts[s][k];
				(ans[i][j]+=mul(dp[i][s],mul(a[i][j],inv[sum[i][s]])))%=mod;
			}
		}
	}
	rep(i,0,n-1){
		rep(j,0,n-1){
			cout<<ans[i][j];
			if(j<n-1)cout<<' ';
		}
		if(i<n-1) cout<<hvie;
	}

    return 0;
}
/*
3
19 26 8
17 19 49
100 1 7

*/
