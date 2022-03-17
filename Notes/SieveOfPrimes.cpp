#include <bits/stdc++.h>
using namespace std;

/*from 1 to 100000 (1 lakh) there are 9592 prime numbers, these primes numbers can divide each and every composite number from 1 to
10000000000 (10^10)*/
vector<int> v; // this is the global array declared which will store all the primes from t to u (both included)
int counter;   // this is the actual number of primes stored in the array a after sieve is called using limits
int sieve(int t, int u)
{
	if(t>u||u<2){
		cout<<"Check the order of the range limits and make sure range contains at least one prime number."<<endl;
		return 0;
	}
	if(t<=1) t=2;
	int range=(u-t+1);
	vector<int> primes(range);
	int c = 0;
	for(int cnt=2; cnt<u; cnt++){
		int start=pow(cnt, 2);
		if(start>u) break;
		if(start<t){
			if (((float)t/cnt)==(t/cnt)) c=(t/cnt);
			else c=(t/cnt)+1;
			while(cnt*c<=u){
				if(primes[cnt*c-t]!=1) primes[cnt*c-t]=1;
				c++;
			}
		}
		else{
			c=cnt;
			while(cnt*c<=u){
				if(primes[cnt*c-t]!=1) primes[cnt*c-t]=1;
				c++;
			}
		}
	}
	for(int i=t; i<=u; i++){
		if(primes[i-t]!=1){
			v.emplace_back(i);
			counter++;
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int range_begin,range_end;
	cin>>range_begin>>range_end;
	sieve(range_begin,range_end);
	for (int i=0; i<counter;i++)cout<<v[i]<<" ";
	return 0;
}