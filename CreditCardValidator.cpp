#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


bool isNumber(const string& s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}


int main()
{
    string ccNumber;

    cout << "This program uses the Luhn Algorigthm to validate a CC number." << endl;
    cout << "Enter 'exit' to quit." << endl;

    while (true) {

        cout << "Please enter a CC number to validate: ";
        cin >> ccNumber;

        if (ccNumber == "exit")
            break;

        else if (!isNumber(ccNumber)) {
            cout << "Bad input! ";
            continue;
        }

        int len = ccNumber.length();
        int doubleEvenSum = 0;

     
        /*
        * step 1, multiplying by 2 all digits of even placed digit, starting from 
        * the right. If the result is in 2 digits(result > 9) add the sum of both 
        * digits to obtain a single digit number. Finally, sum all the answers to 
        * obtain 'doubleEvenSum'.
        */

        for (int i = len - 2; i >= 0; i = i - 2) {
            int dbl = ((ccNumber[i] - 48) * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }

        // Step 2 is to add every odd placed digit from the right to the value
        // 'doubleEvenSum'.

        for (int i = len - 1; i >= 0; i = i - 2) {
            doubleEvenSum += (ccNumber[i] - 48);
        }

        // Step 3 is to check if the final 'doubleEvenSum' is a multiple of 10.
        // If yes, it is a valid CC number. Otherwise, not.

        cout << (doubleEvenSum % 10 == 0 ? "Valid!" : "Invalid!") << endl;

        continue;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
