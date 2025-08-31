#pragma once
#include <iostream>
#include <cstdlib>
#include "clsDate.h"
using namespace std;


class clsUtil
{
public:

    static void Srand()
    {
        static bool IsSeeded = false;

        if (!IsSeeded)
        {
            srand((unsigned)time(NULL));
            IsSeeded = true;
        }
    }

    static int RandomNumber(int From = 1, int To = 1000)
    {
        Srand();
        return rand() % (To - From + 1) + From;
    }

    enum enCharType { SmallLetters = 1, CapitalLetters = 2, SpecialChars = 3, Digits = 4, MixChars = 5 };

    static char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case clsUtil::SmallLetters:
            return char(RandomNumber(97, 122));
            break;

        case clsUtil::CapitalLetters:
            return char(RandomNumber(65, 90));
            break;

        case clsUtil::SpecialChars:
            return char(RandomNumber(33, 47));
            break;

        case clsUtil::Digits:
            return char(RandomNumber(48, 57));
            break;

        case clsUtil::MixChars:
            return char(RandomNumber(33, 126));
            break;

        default:
            return '?';
            break;
        }
    }

    static string GenerateWord(enCharType CharType, short WordLength = 4)
    {
        string Word = "";

        for (short i = 1; i <= WordLength; i++)
        {
            Word += GetRandomCharacter(CharType);
        }

        return Word;
    }

    static string GenerateKey(enCharType CharType)
    {
        string Key = "";

        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4);

        return Key;
    }

    static void GenerateKeys(enCharType CharType, short NumberOfKeys)
    {
        for (short i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "]: ";
            cout << GenerateKey(CharType) << endl;
        }
    }

    template<typename T>
    static void Swap(T& A, T& B)
    {
        T Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate& Date1, clsDate& Date2)
    {
        clsDate::SwapDates(Date1, Date2);
    }

    static void FillArrayWithRandomNumbers(int* arr, short arrLength, int From = 1, int To = 100)
    {
        for (short i = 0; i < arrLength; i++)
        {
            *(arr + i) = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string* arr, short arrLength, enCharType CharType, short WordLength)
    {
        for (short i = 0; i < arrLength; i++)
        {
            *(arr + i) = GenerateWord(CharType, WordLength);
        }
    }

    static void FillArrayWithRandomKeys(string* arr, int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            *(arr + i) = GenerateKey(CharType);
    }


    template<typename T>
    static void ShuffleArray(T* arr, int arrLength)
    {
        for (int i = arrLength - 1; i > 0; i--)
        {
            int j = RandomNumber(0, i);

            Swap(*(arr + i), *(arr + j));
        }
    }

    static string Tabs(short TabsNumber = 3)
    {
        string t = "";

        for (short i = 1; i <= TabsNumber; i++)
        {
            t += "\t";
        }

        return t;
    }

    static string  EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i < Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i < Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;
    }

    static string NumberToText(int Number)
    {
        if (Number < 0)
        {
            return "Minus " + NumberToText(Number * -1);
        }

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billion " + NumberToText(Number % 1000000000);
        }
    }

    static int ExtractDigits(string S1)
    {
        string StrDigits = "";

        for (char C : S1)
        {
            if (isdigit(C))
                StrDigits += C;
        }

        return stoi(StrDigits);
    }

    static string ExtractAlpha(string S1)
    {
        string Alphas = "";

        for (char C : S1)
        {
            if (!isdigit(C))
            {
                Alphas += C;
            }
        }

        return Alphas;
    }
};
