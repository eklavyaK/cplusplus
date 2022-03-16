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
        string s; cin>>s;int n = s.length();
        vector<int> v,u;int cnt=0;bool temp=true;
        if(s[0]=='1')temp=true;
        else if(s[0]=='0')temp=false;
        else{
            for(int i = 1; i<n; i++){
                if(s[i]!='?'){
                    if(s[i]=='1' && i%2)temp=false;
                    else if(s[i]=='0' && i%2)temp=true;
                    else if(s[i]=='1' && i%2==0)temp=true;
                    else temp=false;
                    break;
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(s[i]=='?'||
            ((s[i]-'0') && temp)||
            (!(s[i]-'0') && !temp)){
                cnt++;
                temp=!temp;
            }
            else{
                v.push_back(cnt);cnt=1;
                if(s[i]=='1')temp=false;
                else temp=true;
                for(int j=i-1;j>=0;j--){
                    if(s[j]!='?')break;
                    cnt++;
                }
                u.push_back(cnt-1);
            }
        }
        v.push_back(cnt);
        long long minus = 0l;
        for(auto i : u){
            minus+=(long long)i*(i-1)/2;
        }
        long long result=n;
        for(auto i : v){
            result+=(long long)i*(i-1)/2;
        }
        cout<<result-minus<<endl;
    }
    return 0;
}