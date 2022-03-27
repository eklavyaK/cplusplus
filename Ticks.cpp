#include<bits/stdc++.h>
#define mod 1000000007ll
#define parameters int i,int j,int n, int m,int k,string s[]
#define pass i,j,n,m,k,s
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
bool execute_right(parameters){
	int x=0,y=0,cnt=0;bool detect = false;
	while(i+x<n && j+y<m){
		if(s[i+x][j+y]=='*'){
			cnt++;
			if(cnt>k){
				int r=i+x-1,c=j+y+1,cn=0;
				while(r>=0 && c<m){
					if(s[r][c]=='*'){
						c++;r--;cn++;
					}
					else break;
				}
				if(cn>=cnt-1){
					detect=true;
					break;
				}
			}
			x++,y++;
		}
		else break;
	}
	return detect;
}
bool execute_left(parameters){
	int x=0,y=0,cnt=0;bool detect = false;
	while(i+x<n && j-y>=0){
		if(s[i+x][j-y]=='*'){
			cnt++;
			if(cnt>k){
				int r=i+x-1,c=j-y-1,cn=0;
				while(r>=0 && c>=0){
					if(s[r][c]=='*'){
						cn++;r--;c--;
					}
					else break;
				}
				if(cn>=cnt-1){
					detect=true;
					break;
				}
			}
			x++,y++;
		}
		else break;
	}
	return detect;
}
bool execute_tip(parameters){
	int cnt = 0;
	for(int x = k; x>=1 && i-x>=0 && j-x>=0 && j+x<m; x--){
		if(s[i-x][j-x]=='*'&&s[i-x][j+x]=='*'){
			cnt++;
		}
		else break;
	}
	return cnt==k?true:false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.precision(28);cin.tie(NULL);
	int tc;cin>>tc;int d=0;
	while(tc-->0){d++;
		int n,m,k; cin>>n>>m>>k;
		string s[n];bool detect=false;
		for(int i = 0; i<n; i++){
			cin>>s[i];
		}
		if(k==0){Y();continue;}
		if(s[n-1][m-1]=='*'||s[n-1][0]=='*'){
			N();continue;
		}
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(s[i][j]=='*'){
					detect = false;
					if(j==0){
						if(execute_right(pass)){
							detect=true;
						}
					}
					else if(j==m-1){
						if(execute_left(pass)){
							detect=true;
						}
					}
					else if(i==0){
						if(execute_right(pass)||execute_left(pass)){
							detect=true;
						}
					}
					else{
						if(i==n-1 || (s[i+1][j+1]!='*'&&s[i+1][j-1]!='*')){
							if(execute_tip(pass)){
								detect =true;
							}
						}
						else if((s[i+1][j+1]=='*' && s[i-1][j-1]=='*')||(s[i-1][j+1]=='*' && s[i+1][j-1]=='*')){
							continue;
						}
						else if(s[i-1][j+1]!='*' && s[i-1][j-1]!='*'){
							if(execute_right(pass)||execute_left(pass)){
								detect=true;
							}
						}
						else if(s[i-1][j+1]!='*'){
							if(execute_left(pass)){
								detect=true;
							}
						}
						else if(s[i-1][j-1]!='*'){
							if(execute_right(pass)){
								detect=true;
							}
						}
					}
					if(!detect){
						N();goto end;
					}
				}
			}
		}
		Y();end:;
	}
	return 0;
}
