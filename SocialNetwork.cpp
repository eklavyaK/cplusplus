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
    int n, d; cin>>n>>d;
    int a[n],b[n];
    for(int i = 0; i<d; i++){
        cin>>a[i]>>b[i];
    }
    int z = n;
    for(int j = 0; j<d; j++){
    int result=1,cnt=0,c=0;
    map<int,int> mx_el;
    map<int,int> m;
    for(int i = 0; i<=j; i++){
        if(m.count(a[i]) && m.count(b[i])){
            if(m[a[i]]==m[b[i]]){
                c++;
            }
            else{
                int l = m[b[i]];
                int r = m[a[i]];
                for(auto o : m){
                    if(o.second==l){
                        m[o.first]=r;
                    }
                }
                mx_el[r]+=(1+mx_el[l]);
                result=max(mx_el[r],result);
                mx_el.erase(l);
            }
        }
        else if(m.count(a[i])){
            m[b[i]]=m[a[i]];
            mx_el[m[a[i]]]++;
            result=max(mx_el[m[a[i]]],result);
        }
        else if(m.count(b[i])){
            m[a[i]]=m[b[i]];
            mx_el[m[b[i]]]++;
            result=max(mx_el[m[a[i]]],result);
        }
        else{
            cnt++;
            m[a[i]]=cnt;
            m[b[i]]=cnt;
            mx_el[cnt]=1;
        }
    }
    if(c==0){
        cout<<result<<endl;
        continue;
    }
    vector<int> v;
    for(auto t : mx_el){
        v.push_back(t.second);
    }
    n=mx_el.size();
    sort(v.begin(),v.end(),greater<int>());
    for(int i = 1; i<n && c>0; i++){
        result+=(v[i]+1);c--;
    }
    if(c>0){
        if(c<z-result-1){
            cout<<result+c<<endl;
        }
        else{
            for(;j<d; j++){
                cout<<z-1<<endl;
            }
        }
    }
    else cout<<result<<endl;
    }
    return 0;
}