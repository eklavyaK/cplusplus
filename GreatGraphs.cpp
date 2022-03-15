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
        int n; cin>>n; int a[n+1]; long long sum[n+1],tl=0l;
        for(int i = 1; i<=n; i++)cin>>a[i];
        sort(a+1,a+n+1);for(int i = 1; i<=n-1; i++){
            tl+=(a[i+1]-a[i]);
        } 
        sum[n]=0;int track = 1;
        for(int i=n-1;i>=1;i--){
            sum[i]=sum[i+1]+(long long)(track++)*abs(a[i+1]-a[i]);
        }
        for(int i = 1; i<=n; i++){
            tl-=sum[i];
        }
        cout<<tl<<endl;
    }
    return 0;
}