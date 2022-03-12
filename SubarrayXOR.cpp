#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;
const int mod = 998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n; cin>>n;
        string s; cin>>s;
        long long sum[n];
        long long result = 0l;
        if(s[0]=='1')sum[0]=1l;
        else sum[0]=0l;
        for(int i = 1; i<n; i++){
            if(s[i]=='1'){
                sum[i]=sum[i-1]+i+1;
            }
            else sum[i]=sum[i-1];
        }
        long long r = 1;if(sum[n-1]%2){
            result = 1;
        }
        for(int i = n-2; i>=0; i--){
            r=(r*2)%mod;
            if(sum[i]%2){
                result=(result+r)%mod;
            }
        }
        cout<<result<<endl;;
    }
    return 0;
}