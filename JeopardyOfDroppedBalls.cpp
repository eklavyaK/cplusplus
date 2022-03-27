#include<bits/stdc++.h>
#define mod 1000000007ll
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

   int n,m,k,c,r;cin>>n>>m>>k;int a[n+1][m+1];
   for(int i = 1; i<=n; i++){
      for(int j = 1; j<=m; j++){
         cin>>a[i][j];
      }
   }
   while(k--){
      cin>>c;r=1;
      while(r!=n+1){
         if(a[r][c]==2)r++;
         else if(a[r][c]==1){a[r][c]=2;c++;}
         else{a[r][c]=2;c--;}
      }
      cout<<c<<' ';
   }

   return 0;
}