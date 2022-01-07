#include<iostream>
#include<fstream>
/*Files used for input/output file operations in c++ are
1. fstreambase -------->base class
2. ifstream -------> derived from fstreambase is used to read the file without affecting the existing data
3. ofstream -------> derived from fstreambase is used to open the file to write new data to it by erasinng all the existing
*/
using namespace std;
int main()
{                   /**One thing to note that if there is no file in the given location then compiler creates a new file of given name**/

    ofstream out ("C:/Users/MY PC/c++/Notes/InputOutputFile.txt");  //we have created a object of ofstream which will write to the specified path
    //as soon as compiler excutes this statement it opens the file in the given location and it remains open till it's closed
    //so whatever we want to write in the file we can write it almost same as we print data on the console. But once we close the file
    //and open it again to write, the whole existing data will be gone and new data will be written from the beginning
    string sout = "", sin = "";
    for(int i = 0; i<10 ;i++)
        out<<"Eklavya Kumar"<<endl; //we can write same as we do in the console
    for(int i = 0; i<10; i++)
        sout = sout + "I am Eklavya Kumar.\n"; //we can also store everything to write in a string and print it in the file at once
    out<<endl;
    out<<sout;  //we can see that when we perform this operation the previous data is not lost because file is already open and it'll will write
    out<<endl;  //the data fromm where cursor is present
    out<<sout;  
    out.close();  //here we have closed the file if we open it again for writing. The whole data will be erased and new data will be written
    ifstream in ("C:/Users/MY PC/c++/Notes/InputOutputFile.txt"); //ifstream is used to read the data from given path similar to reading 
    //done from the console
    in>>sin; //this reads everything before first \n (or enter ) or whitespace
    cout<<sin<<endl;
    getline(in, sin);  //this getline() reads everything from the position to the end end of the line and places the cursor to the next line
    cout<<sin<<endl;
    for(int i = 0; i<32; i++)
    {
        getline(in, sin);
        cout<<sin<<endl;
    }
    in.close();    //this closes the reader
    return 0;
}
/*Please run the below code to understand the getline and >> for I/O of a file:
```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream out("C:/Users/MY PC/c++/Notes/InputOutputFile.txt");
    out<<5<<endl;
    out<<7<<" "<<10<<endl;
    for(int i = 0; i<10; i++)
    {
        if(i%2==0)
        out<<i+1<<endl;
        else out<<"Eklavya Kumar"<<endl;
    }
    out.close();
    ifstream in("C:/Users/MY PC/c++/Notes/InputOutputFile.txt");
    string s = ""; int n,
    sum = 0;
    for(int i = 0; i<13; i++)
    {
        if(i<3)
        {in>>n; sum = sum + n;}
        else if(i%2==1){in>>n; sum = sum + n;}
        else {getline(in,s);getline(in,s); cout<<s<<endl;}
    }
    cout<<sum;
    return 0;
}
``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
*/