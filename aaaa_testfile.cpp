#include<bits/stdc++.h>
#define mod 1000000007ll
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.precision(28);cin.tie(NULL);
	int n,m,q,c; cin>>n>>m>>q; int a[n+1][m+1];
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cin>>c;a[i][j]=-c;
		}
	}
	for(int j = 1; j<=m; j++){
		int k = 0;
		for(int i=n;i>=1;i--){
			if(a[i][j]!=-2){
				k=i;
			}
			else{
				a[i][j]=k;
			}
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	while(q--){
		cin>>c;int r = 1;
		int next = a[r][c];
		while(next!=0){
			if(next<0){
				if(r!=n){
					if(a[r+1][c]<0){
						a[r][c]=r+1;
					}
					else a[r][c]=a[r+1][c];int k = r;
					while(k-1>=1 && a[k-1][c]>=0){
						a[k-1][c]=a[k--][c];
					}
				}
				else a[r][c]=0;
				if(next==-1){
					c+=1;
				}
				else if(next==-3){
					c-=1;
				}
			}
			else{
				r=next;
			}
			next=a[r][c];
			for(int i = 1; i<=n; i++){
				for(int j = 1; j<=m; j++){
					cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		cout<<c<<" ";
	}
	return 0;
}