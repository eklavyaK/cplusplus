#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;
    int tc;cin>>tc;
    while(tc-->0){
        int n;cin>>n;
        string s; cin>>s;
        int cnt = 0;
        char ans1[n],ans2[n];
        if(s[0]=='0'||s[n-1]=='0'){
            N();continue;
        }
        bool sup = true;
        vector<int> v;
        for(int i = 0; i<n; i++){
            if(s[i]=='1'){
                cnt++;
                v.push_back(i);
            }
            else{
                ans1[i]=sup?'(':')';
                ans2[i]=sup?')':'(';
                sup=!sup;
            }
        }
        if(cnt%2){
            N();continue;
        }
        int k = 0;
        while(cnt!=0){
            if(k%2){
                ans1[v[v.size()-1-k/2]]=')';
                ans2[v[v.size()-1-k/2]]=')';
                cnt--;k++;
            }
            else{
                ans1[v[k/2]]='(';
                ans2[v[k/2]]='(';
                cnt--;k++;
            }
        }
        Y();
        for(int i = 0; i<n; i++)cout<<ans1[i];cout<<endl;
        for(int i = 0; i<n; i++)cout<<ans2[i];cout<<endl;
    }
    return 0;
}