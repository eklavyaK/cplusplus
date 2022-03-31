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

   char c[5];
   for(int i = 0; i<5; i++){
      c[i]=char(65+rand()%26);
   }
   cout<<c<<endl;
   for(int i = 0; i<5; i++){
      cout<<c[i]<<endl;
   }
   return 0;
}