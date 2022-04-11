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
        int n; cin>>n; int a[n]; ll sum = 0;
        for(int i = 0; i<n; i++)cin>>a[i];
        for(int i = 0; i<n; i++){
            sum+=a[i];
        }
        bool detect = true;
        ll k = *max_element(a,a+n);
        ll c1=0,c2=0;
        vector<int> v1,v2;
        for(int i = 0; i<n; i++){
            int d = k-a[i];
            if(d==0)continue;
            else{
                int q = d/3;
                int r = d%3;
                c1+=q;c2+=q;
                if(r==1){
                    v1.push_back(q+1);
                    v2.push_back(q);
                    c1++;
                }
                else if(r==2){
                    v1.push_back(q);
                    v2.push_back(q+1);
                    c2++;
                }
                else{
                    v1.push_back(q);
                    v2.push_back(q);
                }
            }
        }
        int c=v1.size();
        if(c1-c2>1)
        for(int i = 0; i<c && c1-c2>1; i++){
            if(v1[i]>1){
                v1[i]-=2;
                c1-=2;c2++;
                i--;
            }
        }
        else if(c2-c1>1)
        for(int i = 0; i<c && c2-c1>1; i++){
            if(v2[i]>0){
                v2[i]--;
                c1+=2;c2--;
                i--;
            }
        }
        ll result = 0;
        if(c1>c2)result=1+(ll)(c1-1)*2;
        else{
            result = c2*2;
        }
        c1=0,c2=0;k++;
        vector<int> v11,v22;
        for(int i = 0; i<n; i++){
            int d = k-a[i];
            if(d==0)continue;
            else{
                int q = d/3;
                int r = d%3;
                c1+=q;c2+=q;
                if(r==1){
                    v11.push_back(q+1);
                    v22.push_back(q);
                    c1++;
                }
                else if(r==2){
                    v11.push_back(q);
                    v22.push_back(q+1);
                    c2++;
                }
                else{
                    v11.push_back(q);
                    v22.push_back(q);
                }
            }
        }
        c=v11.size();
        if(c1-c2>1)
        for(int i = 0; i<c && c1-c2>1; i++){
            if(v11[i]>1){
                v11[i]-=2;
                c1-=2;c2++;
                i--;
            }
        }
        else if(c2-c1>1)
        for(int i = 0; i<c && c2-c1>1; i++){
            if(v22[i]>0){
                v22[i]--;
                c1+=2;c2--;
                i--;
            }
        }
        if(c1>c2)result=min(result,1+(ll)(c1-1)*2);
        else{
            result=min(c2*2,result);
        }
        cout<<result<<endl;
    }
    return 0;
}