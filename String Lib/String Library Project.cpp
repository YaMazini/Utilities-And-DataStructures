#include <iostream>
#include <vector>
#include "clsString.h";
using namespace std;


int main()
{
    clsString String;
    String.Value = "Yahya Mazini";
    cout << String.Value << endl;

    cout << String.CountLetters() << endl;
    cout << clsString::CountLetters("Apah") << endl;

    cout << String.CountVowels() << endl;
    cout << clsString::CountVowels("Apah") << endl;



    return 0;
}