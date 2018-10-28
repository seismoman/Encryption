// xorEncryption.cpp
// 18-May-2017

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    string input, output, normal, cipher;   //declares these vars upfront
    cout << "enter a word or phrase to encrypt: \n";
    getline(cin,input); //uses getline because we want it to accept non-letters & non-numbers like "space"

    //this will be used to xor the original string
    cout << "enter a cipher character or string: \n";
    getline(cin,cipher);
    int r = cipher.size();

    int run = 0;
    for (int i = 0; i < r; i++){ //builds running sum of all cipher char ascii values up to index=r
        char var = cipher[i];
        run = run + int(var);
    }

    int master = sqrt (run); //builds master as nearest int to sqrt of running ascii sum

    //xor operation done here
    for(int i = 0; i < input.size(); i++){
        output += input[i] ^ (master+i)%25;
        }

    cout << "\n here is the encrypted output: \n" << output << "\n";

    //deëncryption takes place here, xor is bidirectional by definition
    for(int i = 0; i < input.size(); i++){
        normal += output[i] ^ (master+i)%25;
    }

    cout << "\n here is that phrase deëncrypted: \n" << normal << "\n";

    cin.get();
    return 0;

}
