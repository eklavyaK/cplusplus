#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;
const int mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        int n,k; cin>>n; int cnt[32]={0}; string s[n];
        for(int i = 0; i<n; i++){cin>>k;s[i]=binary(k,32);}
        for(int i = 0; i<n; i++){
            for(int j = 0; j<32; j++){
                if(s[i][j]=='1'){
                    cnt[j]++;
                }
            }
        }
        vector<int> in;
        for(int i = 0; i<32; i++){
            if(cnt[i]!=n)in.push_back(i);
        }
        int t = in.size();
        long long x=0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<t; j++){
                if(s[i][in[j]]=='1'){
                    goto end;
                }
            }
            x++;end:;
        }
        if(x>1){
            long long result = 1l;
            for(int i = 2; i<=n-2; i++){
                result=(result*i)%mod;
            }
            result = (result*x)%mod;
            result = (result*(x-1))%mod;
            cout<<result<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}