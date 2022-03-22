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
        long long n; cin>>n;
        long long result = 0l;
        bool k = true;
        while(n>0){
            if(n%2==0){
                if((n/2)%2==0){
                    if(n==4){
                        n/=2;
                        if(k)result+=n;
                        k=!k;
                    }
                    else{
                        n--;
                        if(k)result++;
                        k=!k;
                    }
                }
                else{
                    n/=2;
                    if(k)result+=n;
                    k=!k;
                }
            }
            else{
                n--;
                if(k)result++;
                k=!k;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}