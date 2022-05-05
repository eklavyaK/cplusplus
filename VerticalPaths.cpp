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
        int n; cin>>n; int a[n+1];
        for(int i = 1; i<=n; i++){
            cin>>a[i];
        }
        int root;
        vector<int> v(n+1);
        vector<int> c(n+1);
        for(int i = 1; i<=n; i++){
            if(a[i]==i){
                root = i;
                break;
            }
        }
        for(int i = 1; i<=n; i++){
            if(i!=root)v[a[i]]++;
        }
        queue<int> q;
        for(int i = 1; i<=n; i++){
            if(v[i]==0){
                q.push(i);
            }
        }
        cout<<q.size()<<endl;
        while(!q.empty()){
            vector<int> print;
            int k = q.front();q.pop();
            while(c[k]==0){
                print.push_back(k);
                c[k]=1;k=a[k];
            }
            n = print.size();
            cout<<n<<endl;
            for(int i=n-1;i>=0;i--){
                cout<<print[i]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}