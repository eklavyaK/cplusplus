/* Sieve of Eratosthenes is a method which is used to find all the prime numbers in a given range(range limits inclusive). We mark the numbers which are divisible by a number before.
First we select a number starting from lowest prime number 2 then we start marking its multiples starting from it's square. we do this for all successive elements till the square of a unmarked
number exceeds the highest number of the range*/
#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
int form_allprimesinrange(int lim1, int lim2)
{
	if(lim1<=1)
		lim1=2;
	int range = lim2-lim1+1;
	if(range<1) {cout<<"not a valid range"<<endl;return 0;}
	else{
	int primes[range]={0};
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
		if(primes[i-lim1]!=1)
			prime.emplace_back(i);
	return 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    form_allprimesinrange(2,100001);
    int tc; cin>>tc;while(tc--)
    {
        long long n; cin>>n; pair<int,int> p; 
        for(int i = 0; i<9592; i++) 
        {
            int count = 0; long long temp = n;
            while(temp>0 && !(temp%prime[i])){count++;temp/=prime[i];}
            if(count>p.first) {p.first=count;p.second=prime[i];}
        }
        cout.precision(11); if(p.first==0) {cout<<1<<endl<<n<<endl;continue;}
        cout<<p.first--<<endl;for(int i = 0; i<p.first; i++) cout<<p.second<<" ";cout<<n/(pow(p.second,p.first))<<endl;
    }
}