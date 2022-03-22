#include<bits/stdc++.h>
typedef long long ll;
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        queue<ll> q;ll s=0l;
        int n,k; cin>>n;
        map<ll,int> m;
        for(int i = 0; i<n; i++){
            cin>>k;m[k]++;s+=k;
        }
        q.push(s);int cnt = 1;
        while(!q.empty()){
            ll r = q.front();
            q.pop();
            if(m[r]){
                m[r]--;
            }
            else{
                cnt++;
                q.push(r/2);
                q.push(r/2+r%2);
                if(cnt>n){
                    cout<<"NO"<<endl;
                    goto end;
                }
            }
        }
        cout<<"YES"<<endl;
        end:;
    }
    return 0;
}