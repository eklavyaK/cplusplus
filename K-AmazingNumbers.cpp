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
        int n; cin>>n;
        map<int,pair<int,int>> m; 
        int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        for(int i = 0; i<n; i++){
            if(m.count(a[i])){
                m[a[i]].first=max(m[a[i]].first,i-m[a[i]].second-1);
                m[a[i]].second=i;
            }
            else{
                m[a[i]].first=i;
                m[a[i]].second=i;
            }
        }
        vector<pair<int,int>> v;
        for(auto i : m){
            v.push_back(make_pair(max(i.second.first,n-1-i.second.second),i.first));
        }
        int k = v.size(),p=0;
        sort(v.begin(),v.end());
        for(int i = 1; i<=v[0].first; i++){
            cout<<-1<<' ';p++;
        }
        int r = INT_MAX;
        for(int i = 0; i<k; i++){
            int t = v[i].first;
            for(int j = p+1; j<=t && i; j++){
                cout<<r<<' ';p++;
            }
            r=min(v[i].second,r);
            while(i+1<k && v[i].first==v[i+1].first){
                r=min(r,v[i+1].second);i++;
            }
        }
        for(int i = p+1; i<=n; i++){
            cout<<r<<' ';p++;
        }
        cout<<endl;
    }
    return 0;
}