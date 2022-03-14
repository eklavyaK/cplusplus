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
        int n,k,l; cin>>n; int a[n],b[n];
        cin>>l;a[0]=l;
        for(int i = 1; i<n; i++){cin>>k;if(k<l)l=k;a[i]=l;}
        cin>>l;b[0]=l;
        for(int i = 1; i<n; i++){cin>>k;if(k>l)l=k;b[i]=l;}
        int in = 0,result=-1;
        for(int i = 0; i<n; i++){
            if(a[i]<b[i]){in=i;break;}
        }
        int h=in,s=2*in,t=2*in;
        for(int i=in-1;i>=0;i--){
            if(b[i]<a[in]){if(in<n){in++;continue;}else break;}
            s=min(in+i,s);
        }
        for(int i=h-1;i>=0;i--){
            if(b[h]<a[i]){if(h<n){h++;continue;}else break;}
            t=min(h+i,t);
        }
        cout<<min(s,t)<<endl;
    }
    return 0;
}