/* copy and paste the below lines into command prompt

cd Notes
g++ Strings.cpp
a
when will pandemic end
no third wave

*/

//strings in c++ are basically stringbuilder version of java
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	//declaration
	string str;
	string s(7,'s');
	string t = "What it the password";
	cout<<s<<endl;            //prints: sssssss
	cout<<t<<endl;            //prints: what is the password
	
	//taking string inputs
	string input="come",input2="";
	cout<<input<<endl;         //prints: come
	cin>>str;
	cin>>input;                //cin takes only the first word as input (in other words, everything before space or enter key)
	cin>>input2;               //input: hellow, how are you?
	cout<<str<<endl;           //prints: hellow,    
	cout<<input<<endl;         //prints: how
	cout<<input2<<endl;        //prints: are
	//to take a complete line as input i.e. before the first enter key - we use getline method
	getline(cin, input);       //takes everything from the position of the cursor to the end of the line or the pressing of enter key
	//Note that after cin taken the input in the input2 variable it left the cursor on the same so after pressing the enter key input variable in getline() method takes only "\n"
	//so to take the input from fresh line we must take a dummy input with getline. then take the input in actual variable.
	//if we give input as: what is the password  ------- variable str will have "what",input will have "is", input will have "the", then again input will have " password", note there
    //is space before input because cin left the cursor just after word "the"
	cout<<input<<endl;
	
	//input: "when will pandemic end please do it soon\n"answer the question"
	string c;
	getline(cin,c);
	cout<<c<<endl; 
	//c prints: "answer the question"
	//input prints: " end please do it soon"
	
	//methods on string
	string s1 ="Messi",s2="Ronaldo";
	cout<<s1+" "+s2<<endl;  //prints: Messi Ronaldo
	//adding 2 strings
	string s3 = s1+ " " +s2;
	//string x = s1+ " "+23;   //like java we cannot add anything to string using just double quotes, inorder to add a integer we must
	//first convert to string using to_string();
	string x = s1+ " "+to_string(23);cout<<x<<endl;
	cout<<s3<<endl;          //prints: Messi Ronaldo
	s3.append(s1);
	cout<<s3<<endl;       //prints: Messi RonaldoMessi
	
	//obtaining a character from string: string in c++ is basically is a character array. we can treat it as a character array
	cout<<s3[2]<<endl;   //prints: s
	cout<<s.at(2)<<endl;  //prints: s       at function performs the same task this can also be used to set character at a index in string 
	//s.at(2) = 'r';
	//cout<<s.at(2)<<endl;  /prints: r
	
	s3.clear();          //clear() method is used to empty the string
	cout<<s3<<endl;//prints nothing
	
	cout<<s3.empty()<<endl;    //empty() function checks whether string is empty or not but prints 1 or 0 (true or false respectively) but can also be used as boolean statement
	cout<<s1.empty()<<endl;     //prints: 0        means false
	if(s3.empty())
		cout<<"s3 is empty"<<endl;    //prints: s3 is empty
	
	//comparing strings
	s1 = "abc";
	s2 = "xyz";
	s3 = "acu";
	cout<<s1.compare(s2)<<endl;       //prints: negative number because s1 is lexicographically smaller than s2
	cout<<s2.compare(s3)<<endl;       //prints: positve number because s2 is lexicographically greater than s3
	cout<<s1.compare(s1)<<endl;       //prints: 0 becaause both are equal
	
	string r = "elephantandwhale";
	//erasing a chunk of string
	r.erase(8,3);                    //here 8 denotes the index from where removal starts and 3 denotes the number of characters to be removed
	cout<<r<<endl;                   //prints: elephantwhale
	//finding a chunk of string
	int k = r.find("whale");         //returns the index fromm the where the given string starts
	cout<<k<<endl;                   //prints: 8
	k = r.find("whele");             //returns -1 if it's not present
	cout<<k<<endl;                   //prints: -1       
	//inserting
	r.insert(8,"and");               //insert() method inserts the string where the first index of the given string will on the index 8 existing characters will be shifted
	cout<<r<<endl;                   //prints: elephantandwhale
	//length
	k = r.length();                 
	cout<<k<<endl;                   //prints: 16
	k = r.size();
	cout<<k<<endl;                   //prints: 16
	//getting a substring
	s = r.substr(11,5);              //substr() here is bit different from java, 11 is the index from where substring starts and is the length of substring
	cout<<s<<endl;                   //prints: whale
	
	//conversion to and from other types
	s = "3242";
	k = stoi(s);                    //stoi(string) function is used to convert string to integer
	cout<<k+2<<endl;                //prints: 3244
	s = to_string(k);               //to_string(integer) method converts integer or anything(except char) to string
	cout<<s+"9878"<<endl;           //prints: 32449878
	cout<<to_string(23408.093)+" okay"<<endl;       //prints: 23408.093000 okay
	cout<<to_string(342344324509)+" okay"<<endl;    //prints: 342344324509 okay
	cout<<to_string('t')+" okay"<<endl;             //prints: 116 okay                  it gets the integer value(ascii) of 't' then converts it to string
	
	//sorting a string----> for that we must include <algorithm> file
	sort(r.begin(),r.end());        //sort(string.begin(),string.end()) method sorts the string from beginning to end, where string.begin() is the beginning iterator of the string
	//and string.end() is the ending iterator of the string
	cout<<r<<endl;                  //prints: aaadeeehhllnnptw
	
	//case conversion
	//we use transform() method for case conversion
	transform(r.begin(),r.end(),r.begin(),::toupper);//prints: AAADEEEHHLLNNPTW
	//here first r.begin() is the beginning iterator of the string and r.end() is the ending iterator of the string and second 
	//r.begin() denotes that we are converting the string from beginning and toupper denotes the case to which it's been converted
	cout<<r<<endl;
	transform(r.begin(),r.end(),r.begin(),::tolower);//prints: aaadeeehhllnnptw
	cout<<r<<endl;
	
	//sorting the string according to its greater integer
	s = "099878934098";
	sort(s.begin(),s.end(),greater<int>());      //this greater<int> commands the compiler on the basis of which string should be sorted, here it is sorted on the basis of 
	//the ascii values of the characters which is more clearly visible in next sortings
	cout<<s<<endl;                               //prints: 999988874300
	s = "234 239 89 92 98 980 8678";
	sort(s.begin(),s.end(),greater<int>());
	cout<<s<<endl;                               //prints: 9999988888764332220                                   
	//space has the smallest ascii value so it is at last which is isn't noticeable
	s = "234 239 (*^&*%*()*^&^% 89 askdf 92 98 sdkjl 980 <>?>}{8678";
	sort(s.begin(),s.end(),greater<int>());
	cout<<s<<endl;                               //prints: }{sslkkjfdda^^^?>><9999988888764332220****)((&&%%
	
	return 0;
}
/*Output:
sssssss
What it the password
come
when will pandemic end
when
will
pandemic
 end
no third wave
no third wave
Messi Ronaldo
Messi 23
Messi Ronaldo
Messi RonaldoMessi
s
s

1
0
s3 is empty
-1
1
0
elephantwhale
8
-1
elephantandwhale
16
16
whale
3244
32429878
23408.093000 okay
342344324509 okay
116 okay
aaadeeehhllnnptw
AAADEEEHHLLNNPTW
aaadeeehhllnnptw
999988874300
9999988888764332220
}{sslkkjfdda^^^?>><9999988888764332220****)((&&%%
*/