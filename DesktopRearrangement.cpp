#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n,m,q; cin>>n>>m>>q;
	vector<string> s(n);
	for(int i=0;i<n;i++)cin>>s[i];
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='*')cnt++;
		}
	}
	int x = cnt/n, y = cnt%n;
	if(!y)y=n-1,x--;
	else y--;
	int in = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(s[j][i]=='*'){
				in++;
			}
			if(j==y && i==x){i=m;break;}
		}
	}
	while(q--){
		int r,c; 
		cin>>r>>c;
		r--; c--;
		if(s[r][c]=='*'){
			if(s[y][x]=='*')in--;
			if(!y)y=n-1,x--;
			else y--;
			s[r][c]='.'; cnt--;
			if(c*n+r<=x*n+y)in--;
			cout<<cnt-in<<endl;
		}
		else{
			if(y==n-1)y=0,x++;
			else y++;
			if(s[y][x]=='*')in++;
			s[r][c]='*'; cnt++;
			if(c*n+r<=x*n+y)in++;
			cout<<cnt-in<<endl;
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t=1; while(t--)code();
	return 0;
}