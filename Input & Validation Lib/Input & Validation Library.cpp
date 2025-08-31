#include <iostream>
#include "clsInputValidate.h";
using namespace std;



int main()
{
    cout << clsInputValidate::IsNumberBetween<int>(5, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween<double>(5.5, 1.3, 10.8) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(),
        clsDate(1, 1, 2025),
        clsDate(31, 12, 2025)) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(),
        clsDate(31, 12, 2025),
        clsDate(1, 1, 2025)) << endl;

    cout << "\nPlease Enter a Number: ";
    int x = clsInputValidate::ReadNumber<int>("Invalid Number, Enter again: ");
    cout << "x = " << x;

    cout << "\nPlease Enter a Number between 1 and 5: ";
    int y = clsInputValidate::ReadNumberBetween<int>(1, 5, "Number is not within range, enter again: ");
    cout << "y = " << y;

    cout << "\nPlease Enter a Positive Number: ";
    int z = clsInputValidate::ReadPositiveNumber<int>("Invalid Number, Enter again: ");
    cout << "z = " << z;

    cout << "\nPlease Enter a Double Number: ";
    double a = clsInputValidate::ReadNumber<double>("Invalid Number, Enter again:\n");
    cout << "a = " << a;

    cout << "\nPlease Enter a Double Number between 1 and 5: ";
    double b = clsInputValidate::ReadNumberBetween<double>(1, 5, "Number is not within range, enter again: ");
    cout << "b = " << b << "\n\n";
    
    cout << "\nPlease Enter a Double Positive Number: ";
    double c = clsInputValidate::ReadPositiveNumber<double>("Invalid Number, Enter again: ");
    cout << "c = " << c;

    cout << clsInputValidate::IsValidDate(clsDate(35, 12, 2022)) << endl;


    return 0;
}