// caesarCipher.cpp
// cwh 2017

#include <iostream> //include input output library
#include <string> //include library for dealing with strings (aka words)

using namespace std;

int main()
{
    string input; //declares string variable that you'll type in later
    int length;   //declares an integer variable: length of the string you input

    cout << "enter your phrase to be encrypted: \n";  //prompts you for input
    getline(cin,input); //reads in whatever you type into the terminal

    length = (int)input.length(); //length of word/phrase you entered
    int shift = 10; //this is how many letters you'll shift by
    int count = 0; //declares a starting place (0th letter of the input)

    for (count = 0; count < length; count++) //reads in input 1 letter at a time
    {
       if (isalpha(input[count])) //this code shifts letters but not symbols
       //shifting symbols is easy too, but this code is a simple starting place
       {
           input[count] = tolower(input[count]); //converts all letters to lowercase
           for (int i=0; i<shift;i++) //shift each letter by the number provided
           {
               if (input[count] == 'z') //this line and the line below are to ...
                   input[count] = 'a'; //wrap around the alphabet from z-->a
               else
                   input[count]++; //if you don't hit z, keep shifting
           }
       }
    } //end of loop shifting letters one at a time

    cout << "Results: \n" << input << endl; //display the encrypted message!
return 0; //end of program. lots of people put this as a last line
}
