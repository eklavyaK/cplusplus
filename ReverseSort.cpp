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
        int n,cnt=0; cin>>n;
        string s; cin>>s;
        int cnt0[n],cnt1[n];
        for(int i = 0; i<n; i++){
            if(s[i]=='1'){
               cnt++;
            }
            cnt1[i]=cnt;
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                cnt++;
            }
            cnt0[i]=cnt;
        }
        vector<int> v; bool t = true;
        for(int i = 0; i<n; i++){
            if(t && cnt1[i]>=cnt0[i]){
                if(cnt1[i]==cnt0[i]){
                    v.push_back(i+1);
                    t=false;continue;
                }
                if(cnt1[i]>cnt0[i]){
                    if(cnt1[i]==1)break;
                    else{
                        t=false;continue;
                    }
                }
            }
            if(t && s[i]=='1'){
                v.push_back(i+1);
            }
            if(!t && s[i]=='0'){
                v.push_back(i+1);
            }
        }
        if(t){
            cout<<0<<endl;
        }
        else{
            cout<<1<<'\n'<<v.size()<<" ";
            for(auto i : v) cout<<i<<" ";cout<<endl;
        }
    }
    return 0;
}