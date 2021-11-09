#include<bits/stdc++.h>
using namespace std;
#define read yh
#define hvie '\n'
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
int yh(){
	int ret=0;char c=getchar();int f=0;
	while(!isdigit(c)) {if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){ret=ret*10+c-'0';c=getchar();}
	return f?-ret:ret;
}
const int N=1e5+5;
int a[N],n;
int main(){
	n=yh();
	rep(i,1,n) a[i]=yh();
	sort(a+1,a+1+n);
	int m=(1+n)/2;
	int tot=0,L=m,R=m;
	while(tot<n){
		cout<<a[L--];
		if(++tot==n) break;
		else cout<<" ";
		cout<<a[++R];
		if(++tot==n) break;
		else cout<<" ";
	}
	cout<<hvie;
	return 0;
}
