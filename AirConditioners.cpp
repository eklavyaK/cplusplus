#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
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
	int tc;cin>>tc;
	while(tc-->0){
		int n,k; cin>>n>>k;
		int a[k+2],t[k+2];
		for(int i = 1; i<=k; i++){
			cin>>a[i];
		}
		for(int i = 1; i<=k; i++){
			cin>>t[i];
		}
		vector<pair<int,int>> v(k+1);
		for(int i = 1; i<=k; i++){
			v[i].first=a[i];
			v[i].second=t[i];
		}
		sort(v.begin(),v.end());
		vector<pair<int,int>> u,c;
		int temp = v[k].first+v[k].second,cnt=1;
		u.push_back(make_pair(v[k].first,v[k].second));
		for(int i = k-1; i>=1; i--){
			if(v[i].first+v[i].second<temp){
				temp=v[i].first+v[i].second;cnt++;
				u.push_back(make_pair(v[i].first,v[i].second));
			}
		}
		for(int i=cnt-1;i>=0;i--){
			c.push_back(make_pair(u[i].first,u[i].second));
		}
		int track = 0,r=0;
		for(int i = 1; i<=n; i++){
			if(r<track){
				if(track<cnt && 
				c[track].second+c[track].first-i<c[r].second+abs(c[r].first-i)){
					cout<<c[track].second+c[track].first-i<<" ";r=track;
				}
				else cout<<c[r].second+abs(c[r].first-i)<<" ";
				if(i==c[track].first)track++;
			}
			else{
				cout<<c[track].second+c[track].first-i<<" ";
				if(i==c[track].first)track++;
			}
		}
		cout<<endl;
	}
	return 0;
}