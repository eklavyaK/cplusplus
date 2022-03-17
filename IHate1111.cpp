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
        int x; cin>>x;
        if(x>=1100){
            cout<<"YES"<<endl;
        }
        else if(x%11==0){
            cout<<"YES"<<endl;
        }
        else if(x<111){
            cout<<"NO"<<endl;
        }
        else if(x%111==0){
            cout<<"YES"<<endl;
        }
        else{
            for(int i = 1; i<10 && 111*i<x; i++){
                if((x-111*i)%11==0){
                    cout<<"YES"<<endl;
                    goto end;
                }
            }
            cout<<"NO"<<endl;
            end:;
        }
    }
    return 0;
}