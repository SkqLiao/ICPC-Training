#include<bits/stdc++.h>
using namespace std;
#define read yh
#define hvie '\n'
int yh(){
	int ret=0;char c=getchar();int f=0;
	while(!isdigit(c)) {if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){ret=ret*10+c-'0';c=getchar();}
	return f?-ret:ret;
}
const int N=1e5+5;
char s[N],t[N];
map<char,int>mp;
int main(){
	gets(s);
	gets(t);
	int n=strlen(s),m=strlen(t);
	int j=0;
	for(int i=0;i<n;){
		int ir=i,jr=j;
		while(ir<n-1 && s[ir+1]==s[i]) ++ir;
		while(jr<m-1 && t[jr+1]==t[j]) ++jr;
		//printf("%d %d %d %d\n",i,ir,j,jr);
		int ci=ir-i+1,cj=jr-j+1;
		if(ci!=cj) mp[s[i]]=1;
		i=ir+1;j=jr+1;
	}
	for(auto v:mp) putchar(v.first);

	return 0;
}
