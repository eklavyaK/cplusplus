#include<bits/stdc++.h>
using namespace std;
int m,sz[200100],qc[200100],cn,s[200100];
vector<int>g[200100];
bool ans[201000],vis[200100];
struct qq{int v,w;};
vector<qq>G[201000];
int bel[200100];
bool tt;
void dfs(int x){
	for(int &i=bel[x];i<G[x].size();i++)if(!vis[G[x][i].w])vis[G[x][i].w]=1,ans[G[x][i].w]=tt,tt^=1,dfs(G[x][i].v);
}
int main(){
	cin>>m;
	for(int i=1;i<=m;i++){
		scanf("%d",&sz[i]);
		for(int j=0,x;j<sz[i];j++)scanf("%d",&x),g[i].push_back(x),qc[++cn]=x;
	}
	sort(qc+1,qc+cn+1);cn=unique(qc+1,qc+cn+1)-qc-1;
	for(int i=1;i<=m;i++)for(int j=0;j<sz[i];j++)g[i][j]=lower_bound(qc+1,qc+cn+1,g[i][j])-qc,s[g[i][j]]++;
	for(int i=1;i<=cn;i++)if(s[i]&1)return puts("NO"),0;
	int sb=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<sz[i];j++)sb++,G[i].push_back((qq){g[i][j]+m,sb}),G[g[i][j]+m].push_back((qq){i,sb});
	for(int i=1;i<=m+cn;i++)dfs(i);
	sb=0;
	puts("YES");
	for(int i=1;i<=m;i++){
		for(int j=0;j<sz[i];j++)
			sb++,printf("%c",ans[sb]?'R':'L');
		puts("");
	}
	return 0;
}