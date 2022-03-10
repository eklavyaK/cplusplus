#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        long long w,l;cin>>w>>l; int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
        int k,n; cin>>n;for(int i = 0; i<n; i++){cin>>k;if(!a)a=k;}b=k;
        cin>>n;for(int i = 0; i<n; i++){cin>>k;if(!c)c=k;}d=k;
        cin>>n;for(int i = 0; i<n; i++){cin>>k;if(!e)e=k;}f=k;
        cin>>n;for(int i = 0; i<n; i++){cin>>k;if(!g)g=k;}h=k;
        cout<<max(w*max(f-e,h-g),l*max(b-a,d-c))<<endl;
    }
    return 0;
}