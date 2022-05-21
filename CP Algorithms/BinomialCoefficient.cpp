/*

Calculation of binomial coefficient by this method is most optimized. The time complexity is O(n*log(n)).

We use the Fermat's Little Theorem to calculate the modular inverse of the factorial in the denominator.

Application of Fermat's Little Theorem:

    we know a^(p-1) % p = 1 % p, where 'a' is a positive integer and p is prime which is not a divisor of 'a'.

    so we can write a^(p-2) % p = a^(-1) % p, this is the modular inverse of a with p.

Note: There is also another way to calculate the binomial coefficient when 'n' is small. The method is to 
do prime factorisation of the numerator and denominator and store the count of each prime number separately
in a map. Then subtract the count of a prime in denominator by numerator(numerator will always have higher
or equal count than denominator). Now you get the prime factorisation of the binomial coefficient so the 
product of the primes will give the result.

*/
/*****************************************BINOMIAL COEFFECIENT************************************************************/
#include<bits/stdc++.h>
#define mod1 1000000007ll
typedef long long ll;
using namespace std;

ll power(ll a, ll n){
    a%=mod1;
    if(n==0) return 1; 
    ll k = power(a,n/2);
    if(n%2){return (((k*k)%mod1)*a)%mod1;}
    else{return ((k*k)%mod1);}
}
ll factorial(ll n){
    ll ans = 1;
    for(int i=2;i<=n;i++){
        ans=(ans*i)%mod1;
    }
    return ans;
}
ll modularInverse(ll a, ll p){
    return power(a,p-2); //(a^(-1))%p
}
ll binomialCoefficient(ll n, ll r){
    return (((factorial(n) * modularInverse(factorial(r),mod1))%mod1) * modularInverse(factorial(n-r),mod1))%mod1;
}
int main(){
    int n,r;
    cin>>n>>r;
    cout<<binomialCoefficient(n,r)<<endl;
}
/*********************************************************************************************************************************/