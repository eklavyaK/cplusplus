#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        int n,p,k,x,y,t=0; string s;
        cin>>n>>p>>k>>s>>x>>y;
        ll a[k]={0};t=k;
        for(int i = n-1; i>=n-k&&i>=p-1; i--){
            int r = (i-p+1)%k,cnt=1,c=0,b=0;ll temp=0;
            a[--t]+=(ll)y*r;if(s[i]!='1')a[t]+=x;
            vector<pair<int,int>> v;
            for(int j=p-1+r;j<=i-k;j+=k){
                if(s[j]=='0'){
                    c++;
                    v.push_back(make_pair(c,cnt));
                }
                cnt++;
            }
            if(v.size()){
                ll u = c*x;
                for(int j = 0; j<v.size(); j++){
                    u=min(u,(ll)y*v[j].second*k + (ll)(c-v[j].first)*x);
                }
                a[t]+=u;
            }
        }
        cout<<*min_element(a+t,a+k)<<endl;
    }
    return 0;
}