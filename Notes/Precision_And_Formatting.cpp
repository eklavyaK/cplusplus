#include<iostream>
#include<cmath>
#include<iomanip> //for fixed, showpoint, setw, setprecision

using namespace std;

int main()
{
    //there is no need to include any other library files for precision() function except <iostream>
    cout.precision(50);   //precision function is used to print the number to certain number of digits(after rounding off). here it is 50
    cout<<sqrt(7)<<endl;  
    cout.precision(6);    //precision can be changed at any point in the program and it remains the same till it is again manipulated
    cout<<sqrt(133)<<endl; /*prints: 11.22 -----> notice that precision() funciton sets the number of significant digits (not the no. of 
    digits after the decimal).*/
    cout<<21.02000000<<endl; //precision function() eliminates the trailing and ending zeros after decimal (no of significant digits only)
    cout<<21<<endl;          //works only for floating point values
    cout.precision(3);
    cout<<23432<<endl;       //this clearly proves that precision function works only for floating point values


    //library <iomanip>           setprecision() method is most important method for precision
    cout<<setprecision(6); //works just like precision() function without fixed keyword
    cout<<sqrt(133)<<endl;
    cout<<21.02000000<<endl;  //eliminates the trailing zeros

    cout<<fixed<<setprecision(6); //on addition of fixed, setprecision() method prints the required no. of digits after decimal
    cout<<sqrt(133)<<endl;
    cout<<100.0000000009<<endl;   //on addition of fixed, setprecision() method now doesn't elminate the trailing zeros but keeps 
    //number of digits decimal as we need
    cout<<100.0000009<<endl;      //it round offs the value to required number of decimal digits
    cout<<123<<endl;              //setprecision() method works only in case of floating point values
    cout<<setprecision(1);
    cout<<123<<endl;

    //there are other keywords like showpoint etc but they aren't that useful so we're skipping them for now

    return 0;
}