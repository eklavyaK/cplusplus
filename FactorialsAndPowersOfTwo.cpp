#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.push_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
const ll x = (ll)pow(10,12);
//algorithm to get the all possible combinations of r elements from the the group of n elements
//function format: Combination(arr, c, 0, n-1, 0, r) ----> c is a vector of size r and arr is vector of all n elements in it
vector<vector<ll>> v;
void Combination(vector<ll> arr,vector<ll> c,int start, int end, int index, int r){
   if(index==r){
      v.push_back(c);
      return;
   }
   for(int i=start; i<=end&&end-i+1>=r-index; i++){
      c[index]=arr[i];
      Combination(arr,c,i+1,end,index+1,r);
   }
}
ll summation(vector<ll> u){
   ll s = 0l;
   for(auto i : u){
      s+=i;
   }
   return s;
}
int main(){
   ios_base::sync_with_stdio(false);
   cout.precision(28);cin.tie(NULL);
   vector<ll> f;
   ll temp = 6;int cnt=3;
   while(temp<=x){
      f.push_back(temp);
      temp*=(++cnt);
   }
   for(int i = 1; i<=12; i++){
      vector<ll> c(i);
      Combination(f,c,0,11,0,i);
	}
	vector<pair<ll,int>> sum;
	for(auto i : v){
		ll sm = summation(i);
		if(sm<=x){
			sum.push_back(make_pair(sm,i.size()));
		}
	}
   sort(sum.begin(),sum.end());
   int tc;cin>>tc;
   while(tc-->0){
      ll n; cin>>n;
      string s = binary(n,40);int k = 0;
      for(int i = 0; i<40; i++){
         if(s[i]=='1')k++;
      }
      for(int i = 0; i<4095 && sum[i].first<=n; i++){
         int c = 0;
         ll h = n-sum[i].first;
         string z = binary(h,40);
         for(int j = 0; j<40; j++){
            if(z[j]=='1')c++;
         }
         if(c+sum[i].second<k){
            k=sum[i].second+c;
         }
      }
      cout<<k<<endl;
   }
   return 0;
}