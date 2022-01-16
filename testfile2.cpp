#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s = "123";
    cout<<to_string(s[0]+s[1]+s[2]-144);
    return 0;
}