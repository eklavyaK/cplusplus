#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;
map<int,queue<int>> m;
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    vector<int> v;
    while(tc-->0){
        int n; cin>>n; int a[n];
        for(int i = 0; i<n; i++)cin>>a[i];
        vector<int> v(n);v[0]=a[0];
        for(int i = 1; i<n; i++){
            if(a[i]>v[i-1]){
                int k = a[i]%v[i-1];
                v[i]=a[i]-k;
            }
            else if(a[i]==v[i-1]){
                v[i]=a[i];
            }
            else{
                v[i]=1;
            }
        }
        for(auto i : v) cout<<i<<" ";cout<<endl;
    }
    return 0;
}