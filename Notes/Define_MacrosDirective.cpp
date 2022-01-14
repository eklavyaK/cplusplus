#include<iostream>
#include<string>
#define f(n)  for(int i = 0; i<n; i++)  
#define print(s) cout<<(s)             
#define println(s) cout<<(s)<<endl 
#define square(a) a*a 
#define pi 3.141593                                  
#define begin {
#define end }
/* Using define directive we can define literally anything in c++ code which will directly be replaced in the code at the time of 
execution.
we can also define a small function using define keyword which can be observed in this example*/
using namespace std;

int main()
begin
    f(10) cout<<i<<" "; println("\n");
    print("hello world");
    println("");
    println("Hello World");
    println("");

    f(101) print(to_string(i*i)+" ");println("\n");

    println("The value of pi is: "+to_string(pi)+"\n");
    f(10) print((square((i+1))))<<" ";println("\n");
    println((long long int)1111111111111111111);

    return 0;
end
/*Output:

0 1 2 3 4 5 6 7 8 9 

hello world
Hello World

0 1 4 9 16 25 36 49 64 81 100 121 144 169 196 225 256 289 324 361 400 441 484 529 576 625 676 729 784 841 900 961 1024 1089 1156 1225 1296 1369 1444 1521 1600 1681 1764 1849 1936 2025 2116 2209 2304 2401 2500 2601 2704 2809 2916 3025 3136 3249 3364 3481 3600 3721 3844 3969 4096 4225 4356 4489 4624 4761 4900 5041 5184 5329 5476 5625 5776 5929 6084 6241 6400 6561 6724 6889 7056 7225 7396 7569 7744 7921 8100 8281 8464 8649 8836 9025 9216 9409 9604 9801 10000

The value of pi is: 3.141593

1 4 9 16 25 36 49 64 81 100 

1111111111111111111
*/