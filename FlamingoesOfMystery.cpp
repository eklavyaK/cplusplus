#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int n,temp; cin>>n;
    int total;vector<int> v(n);
    cout<<'?'<<' '<<1<<' '<<n<<endl<<flush;
    cin>>total;int k = total;
    for(int i = 2; i<n; i++){
        cout<<'?'<<' '<<i<<' '<<n<<endl<<flush;
        cin>>temp;
        v[i-2]=k-temp;
        k=temp;
    }
    cout<<'?'<<' '<<1<<' '<<n-1<<endl<<flush;
    int x; cin>>x;
    v[n-1]=total-x;
    v[n-2]=temp-v[n-1];
    cout<<'!'<<' ';for(auto i : v){
        cout<<i<<' ';
    }
    return 0;
}