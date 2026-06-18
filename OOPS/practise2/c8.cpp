#include<iostream>
#include<fstream>
using namespace std;
int main(){
    // writing to file
    ofstream f("example.txt");
    f<<"hello world"<<endl;
    f<<"c++ file handling"<<endl;
    // now we add single character
    f.put('A');
    f.close();
    // now we read from file
    ifstream fi("example.txt");
    char ch; 
    fi.get(ch);
    while(!fi.eof()){
        cout<<ch;
        fi.get(ch);
    }
    fi.close();
    // now we read line by line
    ifstream fi2("example.txt");
    string line;
    getline(fi2, line);
    while(!fi2.eof()){
        cout<<line<<endl;
        getline(fi2, line);
    }
    fi2.close();
    // peek function
    ifstream fi3("example.txt");
    cout<<"using peek"<<endl;
    cout<<(char)fi3.peek()<<endl; // this will give the first character of the file without extracting it
    fi3.get(ch);
 // this will extract the first character of the file
cout<<"after extracting the first character: "<<ch<<endl;
fi3.close();
// seek and tell
ifstream fi4("example.txt");
cout<<"current postion"<<endl;
cout<<fi4.tellg()<<endl; // this will give the current position of the file pointer
fi4.seekg(9); // this will move the file pointer to the 9th position
cout<<"current position after seekg(9)"<<endl;
cout<<fi4.tellg()<<endl; // this will give the current position of the file
fi4.get(ch); // this will extract the character at the 9th position
cout<<"character at 9th position: "<<ch<<endl;
fi4.close();

// append 
ofstream f2("example.txt", ios::app); // this will open the file in append mode
f2<<"jagota"<<endl;

f2.close();
ifstream fi5("example.txt");
string data;
while(getline(fi5, data)){
    cout<<data<<endl;
}
fi5.close();
}