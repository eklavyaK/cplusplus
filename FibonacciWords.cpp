#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    string s;cin>>s;
    if(s.length()>2){
        int a = s[0]-'A', b = s[1]-'A';
        for(int i = 2; i<s.length(); i++){
            if(s[i]-'A'!=(a+b)%26){
               cout<<"NO"<<endl; goto end;
            }
            int temp = a;a=b;b=(temp+b)%26;
        }
    }
    cout<<"YES"<<endl;
    end:;
    return 0;
}