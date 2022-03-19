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
        int n; cin>>n; int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        long long s[n];s[0]=a[0];
        for(int i = 1; i<n; i++){
            s[i]=s[i-1]+a[i];
        }
        int cnt=1;
        for(int i = 1; i<=n-1; i++){
            long long temp = s[i-1];
            int in = i-1,c=1; 
            bool detect=true;
            for(int j = i; j<n; j++){
                if(s[j]-s[in]==temp){
                    c++;in=j;
                }
                else if(s[j]-s[in]>temp){
                    detect=false;break;
                }
            }
            if(detect){
                if(in!=n-1){
                    if(s[n-1]-s[in]==temp){
                        cnt=c;break;
                    }
                }
                else{
                    cnt=c;break;
                }
            }
        }
        cout<<n-cnt<<endl;
    }
    return 0;
}