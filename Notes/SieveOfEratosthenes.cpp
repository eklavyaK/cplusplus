/* Sieve of Eratosthenes is a method which is used to find all the prime numbers in a given range(range limits inclusive). We mark the numbers which are divisible by a number before.
First we select a number starting from lowest prime number 2 then we start marking its multiples starting from it's square. we do this for all successive elements till the square of a unmarked
number exceeds the highest number of the range*/
#include<iostream>
#include<cmath>
using namespace std;
int print_allprimesinrange(int lim1, int lim2)
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
			cout<<i<<" ";
	return 0;
	}
}
int main()
{
	int range_startlimit, range_endlimit;
	cin>>range_startlimit>>range_endlimit;
	return print_allprimesinrange(range_startlimit,range_endlimit);
}