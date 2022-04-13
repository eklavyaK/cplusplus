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
        ll sum = 0;
        int n,k; cin>>n;int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
            sum+=a[i];
        }
        vector<int> v(n,-1);
        for(int i = 0; i<n-1; i++){
            cin>>k;--k;v[k]++;
            cin>>k;--k;v[k]++;
        }
        vector<pair<int,int>> c;
        for(int i = 0; i<n; i++){
            if(v[i]>0){
                c.push_back(
                    make_pair(
                        a[i],v[i]
                    )
                );
            }
        }
        sort(c.begin(),c.end());
        cout<<sum<<' ';
        int cnt = c.size()-1;
        for(int i = 0; i<n-2; i++){
            if(c[cnt].second==0)cnt--;
            sum+=c[cnt].first;c[cnt].second--;
            cout<<sum<<' ';
        }
        cout<<endl;
    }
    return 0;
}