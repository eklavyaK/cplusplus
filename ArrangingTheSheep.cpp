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
        int n; cin>>n; string s; cin>>s;
        long long front[n],back[n],cnt=0;
        if(s[0]=='*'){
            cnt++;
        }
        front[0]=0;
        for(int i = 1; i<n; i++){
            if(s[i]=='*'){
                cnt++;
                front[i]=front[i-1];
            }
            else{
                front[i]=front[i-1]+cnt;
            }
        }
        cnt=0;
        if(s[n-1]=='*'){
            cnt++;
        }
        back[n-1]=0;
        for(int i = n-2; i>=0; i--){
            if(s[i]=='*'){
                cnt++;
                back[i]=back[i+1];
            }
            else{
                back[i]=back[i+1]+cnt;
            }
        }
        long long result = 1e13;
        for(int i = 0; i<n; i++){
            result=min(result,front[i]+back[i]);
        }
        cout<<result<<endl;
    }
    return 0;
}