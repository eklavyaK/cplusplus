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
        int n,k; cin>>n>>k;int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        vector<int> v;makeset(v,a,n);
        n = v.size();k=min(n,k);
        if(k==1){
            if(v.size()!=1){
                cout<<-1<<endl;
            }
            else{
                cout<<1<<endl;
            }
            continue;
        }
        cout<<(1+ceil((ld)(n-k)/(k-1)))<<endl;
    }
    return 0;
}