#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        int n;cin>>n;
        int a[n];
        for(int i = 0; i<n; i++)cin>>a[i];
        long long s=0;
        for(int i = 0; i<n; i++){
            s+=a[i];
        }
        int k = *max_element(a,a+n);
        cout<<max(s/(n-1)+(s%(n-1)?1:0),(long long)k)*(n-1)-s<<endl;
    }
    return 0;
}