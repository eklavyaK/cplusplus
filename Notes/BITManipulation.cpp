 #include <iostream>
 #include <string>
 #include <bitset>
 #include <cmath>
 using namespace std;
 
 //convert a number to binary we use this bitset<lengthOfBinaryString>(numberWhoseBinaryIsToBeObtained).to_string();
 
 int main()
 {
	//to find the bit at a particular index in the binary form of the number we make a binary number of same length having all zeros except the at that position and take &
	//ex:-
	string s = bitset<8>(5).to_string();          //binary of 5 is 00000101
	cout<<(((int)s[5] - 48)&1)<<endl;             //prints: 1
	//we can also use leftshift operator to position 1
	if(stoi(s)&(1<<2)!=0)
		cout<<1<<endl;
	else cout<<0<<endl;
	//to set a bit a particular index we use OR operation with 2^(position)
	s = bitset<8>(stoi(s)|(int)pow(2,3)).to_string();
	cout<<s<<endl;                  //prints: 01101101
	//we can also use leftshift operator
	string st = bitset<8>(stoi(s)|(1<<3)).to_string();
	cout<<st<<endl;                 //prints: 00101101    this output is different than previous because s has been modified after the operation
	//xor operator(^) gives result as 1 for two different bits and if both are same then gives 0
	//we can do bit manipulation using these basic concepts
	
	return 0;
 }
	