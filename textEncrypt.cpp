#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;

int main() {

    ifstream inFile;   //i=input, fstream = filestream
    string ifilename, cipher, ofilename, output;
    int i, master, run, r;
    fstream outFile;

    cout << "enter the name of the file to read encrypt\n";
    getline(cin,ifilename);
    inFile.open(ifilename);

    //Check for errors
    if (!inFile.is_open()) {    //use parentheses () bc it's a function
        cerr << "Error opening file. File does not exist" << endl;
        exit(1);
    }

//set up xor encryption algorithm
    cipher = "hellomynameis";
    r = cipher.size();

    run = 0;
    for (i = 0; i < r; i++){ //builds running sum of all cipher char ascii values up to index=r
        char var = cipher[i];
        run = run + int(var);
    }
    master = sqrt (run); //builds master as nearest int to sqrt of running ascii sum

    inFile.open(ifilename, ios::in);
    string input((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    //xor operation done here
    for(i = 0; i < input.size(); i++){
        output += input[i] ^ (master+i)%25;
        }

    //Create output file
    cout << "enter name of output file: \n";
    getline(cin,ofilename);
    outFile.open(ofilename, ios_base::out);

    outFile.write(output.c_str(),output.size());

    outFile.close();

    return 0;
}
