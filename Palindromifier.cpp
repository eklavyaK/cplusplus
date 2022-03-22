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
    string s; cin>>s;cout<<3<<endl;
    int k,n = s.length();k=n;
    cout<<'L'<<' '<<2<<endl;n++;
    cout<<'R'<<' '<<2<<endl;n+=(n-2);
    cout<<'R'<<' '<<n-1<<endl;
    return 0;
}