#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
typedef long long ll;
typedef long double ld;
using namespace std;
int a[100001]={0};
void Y(){cout<<"YES"<<endl;}
void N(){cout<<"NO"<<endl;}
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int n,k;cin>>n;int s=0,r=0,u=0,y=0;
    while(n--){
        cin>>k;a[k]++;
        if(a[k]==4){s++;r--;}
        else if(a[k]==6){s--;u++;}
        else if(a[k]==2)r++;
        else if(a[k]==8)y++;
    }
    int q;cin>>q;
    while(q--){
        char c;cin>>c;
        if(c=='+'){
            int x;cin>>x;
            a[x]++;
            if(a[x]-1==3){s++;r--;}
            else if(a[x]-1==5){u++;s--;}
            else if(a[x]-1==1)r++;
            else if(a[x]-1==7)y++;
        }
        else{
            int x;cin>>x;
            a[x]--;
            if(a[x]+1==4){s--;r++;}
            else if(a[x]+1==6){u--;s++;}
            else if(a[x]+1==2)r--;
            else if(a[x]+1==8)y--;
        }
        if(y>0)Y();
        else if(s==0 && u==0)N();
        else if(s==1 && u==0){
            if(r>1)Y();
            else N();
        }
        else if(s==0 && u==1){
            if(r>0)Y();
            else N();
        }
        else Y();
    }
    return 0;
}