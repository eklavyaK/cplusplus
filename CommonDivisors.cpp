#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n; cin>>n; long long a[n];
	for(int i = 0; i<n; i++)cin>>a[i];int result = 0;
	long long g = 0;for(int i = 0; i<n; i++) g=gcd(g,a[i]);
	if(g==1) {cout<<1<<endl; exit(0);} int t=sqrt(g); 
	if((long double)sqrt(g)==t) {result++;t--;}
	for(int i = 1; i<=t; i++){
		if(g%i==0) result+=2;
	}
	cout<<result<<endl;
	return 0;
}