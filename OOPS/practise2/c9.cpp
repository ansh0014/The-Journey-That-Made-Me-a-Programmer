#include <iostream>
#include<fstream>
using namespace std;
int main(){
    int num=100;
    ofstream f("data.txt");
    f.write((char*)&num, sizeof(num)); // this will write the binary data of num to the file
    f.close();
    ifstream fi("data.txt");
    int n;
    fi.read((char*)&n, sizeof(n)); // this will read the binary data from the file and store it in n
    cout<<"Number read from file: "<<n<<endl;
    fi.close();
}