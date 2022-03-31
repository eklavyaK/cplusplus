#include<cstdio>  /********************************scanf and printf**********************************/
using namespace std;

/* I/O using scanf and printf is slower than cout and cin. 

% is a notation which is followed by a specifier which denotes the type of value to will be it take 

delimiter of scanf is same as >> operator, which is whitespace and enter pressing*/

int main()
{
    int a; float f; char s[10] ,s1[10]; double d; char c; long long ll; long double ld; //in c programming we declare strings as 
    //character arrays which are mutable
    scanf("%i",&a);                             //i is specifier which used to indicate a integer input
    printf("The value Entered is: %i\n",a);     //to print a integer value we use i specifier
    scanf("%f",&f);                             //f is specifier which used to indicate a float input
    printf("The value Entered is: %f\n",f);     //to print a float value we use f specifier
    scanf("%s",&s);                             //s is a specifier which is used to indicate a character stream in input
    printf("The value Entered is: %s\n",s);     //to print a string value(or character array) we use s specifier
    scanf("%s",&s1);                            
    printf("The value Entered is: %s\n",s1);
    scanf("%s",&c);                             //to get a input of a single character we use s specifier, it takes a single character from input stream
    printf("The value Entered is: %c\n",c);     //to print a character value we use c specifier
    scanf("%lf",&d);                            //to get a double input we use lf (long float) specifier 
    printf("The value Entered is: %lf\n",d);    //to print a double we use lf specifier
    scanf("%lli",&ll);                          //to get a long long int input we use lli specifier
    printf("The value Entered is: %lli\n",ll);  //to print a long long int value we use lli specifier
    scanf("%Lf",&ld);                           //to get a long double input we use Lf specifier, 
    printf("The value Entered is: %Lf\n",ld);   //to print a long double value we use Lf specifier

    printf("\n");
    
    scanf("%i%f%s%lf%s",&a,&f,&s,&d,&c);        //way of taking multiple inputs in one line
    printf("Integer is: %i\nFloat is: %f\nString: %s\nDouble is: %lf\nCharacter is: %c",a,f,s,d,c); //printing output using multiple variables
    
    return 0; 
}
/*
````````````````````````````````````````````````````
Input:
````````````````````````````````````````````````````
23423432
9879.989322
eklavya kumar B 2989324.899892 98237498071298
92387982.998923423

2342398 
65776.8768 eklavyakumar 23998932.989324 S
````````````````````````````````````````````````````
Output:
````````````````````````````````````````````````````
The value Entered is: 23423432
The value Entered is: 9879.989258
The value Entered is: eklavya
The value Entered is: kumar
The value Entered is: B
The value Entered is: 2989324.899892
The value Entered is: 98237498071298
The value Entered is: 92387982.998923

Integer is: 2342398
Float is: 32882.378906
String: eklavyakumar
Double is: 23998932.989324
Character is: S
```````````````````````````````````````````````````
*/