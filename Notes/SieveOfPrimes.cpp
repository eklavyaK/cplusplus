#include<bits/stdc++.h>
using namespace std;

/*from 1 to 100000 (1 lakh) there are 9592 prime numbers, these primes numbers can divide each and every composite number from 1 to
10000000000 (10^10)*/


vector<int> v; //this the global array declared which will store all the primes from
int counter; //this is the actual number of primes stored in the array a after sieve is called using limits

int sieve(int lim1, int lim2)
{
	if(lim1<=1)
		lim1=2;
	if(lim2<=1)
		lim2=2;
	int range = lim2-lim1+1;
	if(range<1) {cout<<"Not a valid range!!"<<endl;return 0;}
	else{
	vector<int> primes(range);
	int multiplier = 0;
	for(int count = 2; count<lim2; count++)
	{
		int start = pow(count, 2);
		if(start>lim2) break;
		if(start<lim1)
		{
			if((float)lim1/count==lim1/count)
				multiplier = lim1/count;
			else multiplier = lim1/count + 1;
			while(count*multiplier<=lim2)
			{if(primes[count*multiplier-lim1]!=1) primes[count*multiplier-lim1]=1; multiplier++;}
		}
		else
		{
			multiplier = count;
			while(count*multiplier<=lim2)
			{if(primes[count*multiplier-lim1]!=1) primes[count*multiplier-lim1]=1; multiplier++;}
		}
	}
	for(int i = lim1;i<=lim2;i++)
		if(primes[i-lim1]!=1){
			v.emplace_back(i);counter++;
		}
	return 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int start_limit,end_limit;
	cin>>start_limit>>end_limit;
	sieve(start_limit, end_limit);
	for(int i = 0; i<counter; i++) cout<<v[i]<<" ";

	return 0;
}