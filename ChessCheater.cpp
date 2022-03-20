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
        int n,k;string s; cin>>n>>k>>s;
        vector<int> v;int l=0,r=-1;
        for(l = 0; l<n; l++){
            if(s[l]=='W'){
                for(r=n-1;r>=l;r--){
                    if(s[r]=='W'){
                        break;
                    }
                }
                break;
            }
        }
        if(r==-1){
            if(k>0){
                cout<<1+(k-1)*2<<endl;
            }
            else{
                cout<<0<<endl;
            }
            continue;
        }
        else if(r==l){
            cout<<min(k,n-1)*2+1<<endl;
            continue;
        }
        int count = 0;
        for(int i = l; i<=r; i++){
            if(s[i]=='L'){
                int cnt = 1;
                while(i+1<n && s[i+1]==s[i]){
                    i++;cnt++;
                }
                v.push_back(cnt);
            }
            else count++;
        }
        int g = v.size()+1,sum=k;
        sort(v.begin(),v.end());
        for(auto i : v){
            if(k-i>=0){
                k-=i;
                g--;
            }
            else break;
        }
        int result = min(sum+count,n)*2-g;
        cout<<result<<endl;
        end:;
    }
    return 0;
}