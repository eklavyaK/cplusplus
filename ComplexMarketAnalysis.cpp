#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;
vector<int> v; // this the global array declared which will store all the primes from
int counter;   // this is the actual number of primes stored in the array a after sieve is called using limits

int sieve(int lim1, int lim2)
{
	if (lim1 > lim2 || lim2 < 2)
	{
		cout << "Not a valid range!!" << endl;
		return 0;
	}
	else
	{
		if (lim1 <= 1)
			lim1 = 2;
		int range = lim2 - lim1 + 1;
		vector<int> primes(range);
		int multiplier = 0;
		for (int count = 2; count < lim2; count++)
		{
			int start = pow(count, 2);
			if (start > lim2)
				break;
			if (start < lim1)
			{
				if ((float)lim1 / count == lim1 / count)
					multiplier = lim1 / count;
				else
					multiplier = lim1 / count + 1;
				while (count * multiplier <= lim2)
				{
					if (primes[count * multiplier - lim1] != 1)
						primes[count * multiplier - lim1] = 1;
					multiplier++;
				}
			}
			else
			{
				multiplier = count;
				while (count * multiplier <= lim2)
				{
					if (primes[count * multiplier - lim1] != 1)
						primes[count * multiplier - lim1] = 1;
					multiplier++;
				}
			}
		}
		for (int i = lim1; i <= lim2; i++)
			if (primes[i - lim1] != 1)
			{
				v.emplace_back(i);
				counter++;
			}
		return 0;
	}
}
bool check_prime(int n){
	int detect = true;
	for(int i = 0; i<counter && n>v[i]; i++){
		if(n%v[i]==0){detect = false;break;}
	}
	return detect;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int tc;cin>>tc;
	sieve(1,1000);
	while(tc-->0)
	{
		int n,e; long long count=0; cin>>n>>e;
		int a[n]; vector<int> v;
		for(int i = 0; i<n; i++){
			cin>>a[i];
			if((a[i]-1) && check_prime(a[i]))
				v.emplace_back(i);
		}
		for(int i = 0; i<v.size(); i++){
			int cnta=0,cntb=0,k=1,in = v[i];
			while(in-(cnta+1)*e>=0 && a[in-(cnta+1)*e]==1)cnta++;
			while(in+(cntb+1)*e<n && a[in+(cntb+1)*e]==1)cntb++;
			if(cnta>0 && cntb>0){
				int t = min(cnta,cntb); 
				count += (long long)(t+2)*(t+1)/2-1+(long long)abs(cnta-cntb)*(t+1)+(long long)t*(t+1)/2;
			}
			else if(cnta>0 || cntb>0){
				int t = max(cnta,cntb);
				count+=t;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}