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
        int n,k; cin>>n>>k; 
        string a,b;cin>>a>>b;
        vector<int> va(26),vb(26);
        for(int i = 0; i<n; i++){
            va[a[i]-'a']++;
            vb[b[i]-'a']++;
        }
        int cnt = 0;
        for(int i = 0; i<26; i++){
            if(cnt+va[i]<vb[i]){
                cout<<"No"<<endl;goto end;
            }
            else{
                if(va[i]>vb[i] && (va[i]-vb[i])%k==0){
                    cnt+=(va[i]-vb[i]);
                }
                else if(vb[i]>=va[i] && (vb[i]-va[i])%k==0){
                    cnt-=(vb[i]-va[i]);
                }
                else{
                    cout<<"No"<<endl;goto end;
                }
            }
        }
        cout<<"Yes"<<endl; end:;
    }
    return 0;
}