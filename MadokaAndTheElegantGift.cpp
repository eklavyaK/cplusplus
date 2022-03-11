#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.precision(28);cin.tie(NULL);
	int tc;cin>>tc;
	while(tc-->0)
	{
		int n,m,detect = 0; cin>>n>>m; string s[n];
		for(int i = 0; i<n; i++)cin>>s[i];
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(s[i][j]=='0'){
					int count = 0;
					if(i-1>=0){
						if(s[i-1][j]=='1')count++;
					}
					if(i-1>=0 && j-1>=0){
						if(s[i-1][j-1]=='1')count++;
					}
					if(j-1>=0){
						if(s[i][j-1]=='1')count++;
					}
					if(count==3){detect = 1;break;}

					count=0;
					if(i-1>=0){
						if(s[i-1][j]=='1')count++;
					}
					if(i-1>=0 && j+1<m){
						if(s[i-1][j+1]=='1')count++;
					}
					if(j+1<m){
						if(s[i][j+1]=='1')count++;
					}
					if(count==3){detect = 1;break;}

					count=0;
					if(i+1<n){
						if(s[i+1][j]=='1')count++;
					}
					if(i+1<n && j+1<m){
						if(s[i+1][j+1]=='1')count++;
					}
					if(j+1<m){
						if(s[i][j+1]=='1')count++;
					}
					if(count==3){detect = 1;break;}
					
					count=0;
					if(i+1<n){
						if(s[i+1][j]=='1')count++;
					}
					if(j-1>=0){
						if(s[i][j-1]=='1')count++;
					}
					if(j-1>=0 && i+1<n){
						if(s[i+1][j-1]=='1')count++;
					}
					if(count==3){detect = 1;break;}
				}
			}
		}
		if(detect) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}