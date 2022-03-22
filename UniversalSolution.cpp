#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        string s; cin>>s; 
        int n = s.size(), a[3]={0};
        for(int i = 0; i<n; i++){
            if(s[i]=='R')a[1]++;
            else if(s[i]=='P')a[2]++;
            else a[0]++;
        }
        int k = max(a[0],max(a[1],a[2]));
        if(a[0]==k){
            cout<<string(n,'R')<<endl;
        }
        else if(a[1]==k){
            cout<<string(n,'P')<<endl;
        }
        else{
            cout<<string(n,'S')<<endl;
        }
    }
    return 0;
}