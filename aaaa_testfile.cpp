#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
//algorithm to get the all possible combinations of r elements from the the group of n elements
//function format: Combination(arr, c, 0, n-1, 0, r) ----> c is a vector of size r and arr is vector of all n elements in it
vector<vector<int>> v;
void Combination(vector<int> arr,vector<int> c,int start, int end, int index, int r){
	   if(index==r){
			  v.push_back(c);
			  return;
	   }
	   for(int i=start; i<=end&&end-i+1>=r-index; i++){
			  c[index]=arr[i];
			  Combination(arr,c,i+1,end,index+1,r);
	   }
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.precision(28);cin.tie(NULL);
	vector<int> arr(5);
	for(int i = 1; i<=5; i++){
		arr[i-1]=i;
	}
	for(int i = 1; i<=5; i++){
		vector<int> c(i);
		Combination(arr,c,0,4,0);
	}
	for(auto i : 

	return 0;
}