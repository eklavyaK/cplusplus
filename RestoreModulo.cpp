#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        int n; cin>>n; int a[n];
        map<int,int> m;
        for(int i = 0; i<n; i++)cin>>a[i];
        for(int i = 1; i<n; i++){
            m[a[i]-a[i-1]]=1;
        }
        if(m.size()==0){
            cout<<0<<endl;
        }
        else if(m.size()==1){
            cout<<0<<endl;
        }
        else{
            vector<int> v;
            int r = INT_MAX;
            map<int,int>::iterator it = m.begin();
            int k = it->first; it++;
            if(k==0){cout<<-1<<endl;goto end;}
            for(;it!=m.end(); it++){
                int t = abs(it->first-k);
                v.push_back(t);
                r = min(r,t);
                k=it->first;
                if(k==0){cout<<-1<<endl;goto end;}
            }
            for(int i = 0; i<n; i++){
                if(r<=a[i]){
                    cout<<-1<<endl;
                    goto end;
                }
            }
            for(int i = 0; i<v.size(); i++){
                if(v[i]%r){
                    cout<<-1<<endl;
                    goto end;
                }
            }
            if(a[0]>a[1]){
                cout<<r<<' '<<a[1]+r-a[0]<<endl;
            }
            else{
                cout<<r<<' '<<a[1]-a[0]<<endl;
            }
        }
        end:;
    }
    return 0;
}