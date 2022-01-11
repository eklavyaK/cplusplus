    for(auto i:vstring) cout<<i<<" "; cout<<endl;
    vstring.erase(vstring.end()-4,vstring.end());  //erase(range of references to be deleted)
    for(auto i:vstring) cout<<i<<" "; cout<<endl<<endl;

    //resizing a vector
    vint.resize(13); //it changes the size of the vector to first 13 elements
    for(auto i:vint) cout<<i<<" "; cout<<endl;
    vint.resize(15,20); //since size of the original vector is 13, to make the size of the vector to 15, 
    //two 20s addec in the end
    for(auto i:vint) cout<<i<<" "; cout<<endl;
    vint.resize(20);
    for(auto i:vint) cout<<i<<" "; cout<<endl; //in case of no value given, default value in case of int vector is 0
    vstring1.resize(10);
    for(auto i:vstring1) cout<<i<<" "; cout<<endl; 
    if(vstring1[9]=="") cout<<"true"<<endl; //in case of no value given, default value in case of string vector is ""

    vstring1.clear(); //clear() method is used to clear everything from the vector
    for(auto i:vstring1) cout<<i<<" "; cout<<endl; 

    //assign() method is used to assign a new vector to a vector
    v.assign(10,25);  //this method assigns vector v as vector with 10 elements all of which are 25
    for(auto i:v) cout<<i<<" "; cout<<endl;
    vint.assign(vint.begin(),vint.end()-5); //in this method a vector is formed by copying the values from th