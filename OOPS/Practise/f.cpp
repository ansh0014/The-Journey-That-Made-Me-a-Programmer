#include<iostream>
#include<fstream>
using namespace std;

int main() {

    // Step 1: Write to file
    ofstream out("data.txt");
    out << "Hello, World!" << endl;
    out.close();

    // Step 2: Read file
    ifstream in("data.txt");
    string data;

    getline(in, data);
    cout << data << endl;

    // Step 3: Move pointer
    in.clear();
    in.seekg(6);

    cout << "Current position: " << in.tellg() << endl;

    in.close();   // 🔥 close before modifying

    // Step 4: Append to file
    ofstream out2("data.txt", ios::app);
    out2 << "Welcome to file handling in C++!" << endl;
    out2.close();

    // Step 5: Reopen file to read updated content
    ifstream in2("data.txt");

    cout << "\nAfter appending to the file:\n";

    while(getline(in2, data)) {
        cout << data << endl;
    }

    in2.close();

    return 0;
}