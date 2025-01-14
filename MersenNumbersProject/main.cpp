#include <iostream>
#include <cmath>
#include "functions.h"
#include "Utils.h"
using namespace std;

int main() {

    int userInput;
    int minRange = 0;
    long long maxRange = 2305843009213693951;
    long long mersenN = 0;
    cout << "------------------------------------------------------------" << endl;
    cout << "Please choose a function from the list: " << endl;
    cout << "0. Exit" << endl;
    cout << "1. Check if a number is Mersen" << endl;
    cout << "2. Check if Mersen number is Prime" << endl;
    cout << "3. Show all number divisors" << endl;
    cout << "4. Save all prime divisors in an array" << endl;
    cout << "5. A function that stores in an array the difference of the sets of composite divisors of two numbers" << endl;
    cout << "6. Show all Mersen numbers in a range" << endl;
    cout << "7. Show the first 'n' Mersen numbers" << endl;
    cout << "8. Show the first 'n' Mersen prime numbers" << endl;
    cout << "9. Save all Mersen prime numbers in an array in a range" << endl;
    cout << "10. Save the first perfect 'n' Mersen numbers in an array" << endl;
    cout << "------------------------------------------------------------" << endl;
    while (cin >> userInput) {

        switch (userInput) {
        case 0:
            cout << "Exiting..." << endl;
            return 0;
        case 1: {
            long long mersen=  inputMersenNumber(mersenN,minRange,maxRange);
            long long mersenNPlusOne = mersen + 1;
            const int pNumber = powCount(mersenNPlusOne);
            bool isMersen = validateMersen(mersen, pNumber);
            cout << "Is the input number a mersen number: " << isMersen << endl;
            continueOrTerminate();
            break;
        }
        case 2: {
            long long mersen = inputMersenNumber(mersenN, minRange, maxRange);
            long long mersenNPlusOne = mersen + 1;
            const int pNumber = powCount(mersenNPlusOne);
            bool isMersen = validateMersen(mersen, pNumber);
            bool isNumberPrime = isPrime(mersen);
            bool isMersPrime = isMersenPrime(isMersen, isNumberPrime);
            cout << "Is mersen number a prime: " << isMersPrime << endl;
            continueOrTerminate();
            break;
        }
        case 3: {
            long long mersen = inputMersenNumber(mersenN, minRange, maxRange);
            showDivisors(mersen);
            continueOrTerminate();
            break;
        }
        case 4:{
            long long mersen = inputMersenNumber(mersenN, minRange, maxRange);
            showPrimeDivisors(mersen);
            continueOrTerminate();
            break;
        }
        case 5: {
            long long n1 = inputMersenNumber(mersenN, minRange, maxRange);
            long long n2 = inputMersenNumber(mersenN, minRange, maxRange);
            showDifferenceOfDivisorsBtwTwoNumbers(n1, n2);
            continueOrTerminate();
            break;
        }
        case 6: {
            long long minimum = inputMinRange(minRange);
            long long maximum = inputMaxRange(maxRange);
            if (minimum >= maximum) {
                cout << "Error min range must be smaller than max range!" << endl;
                return 1;
            }
            mersenNumbersInInterval(minimum, maximum);
            continueOrTerminate();
            break;
        }
        case 7:{
            long long n = inputMersenNumber(mersenN,minRange,maxRange);
            showFirstNMersenNumbers(n, maxRange);
            continueOrTerminate();
            break;
        }
        case 8: {
            long long n = inputMersenNumber(mersenN, minRange, maxRange);
            showFirstNMersenPrimeNumbers(n, maxRange);
            continueOrTerminate();
            break;
        }
        case 9: {
            long long minimum = inputMinRange(minRange);
            long long maximum = inputMaxRange(maxRange);
            if (minimum >= maximum) {
                cout << "Error min range must be smaller than max range!" << endl;
                return 1;
            }
            mersenPrimeNumbersInInterval(minimum, maximum);
            continueOrTerminate();
            break;
        }
        case 10: {
            long long n = inputMersenNumber(mersenN, minRange, maxRange);
            showFirstNMersenPerfectNumbers(n, maxRange);
            continueOrTerminate();
            break;
        }
        default :
            cout << "Error no such menu exists! Please try again.";
            return 1;
        }
    }
    return 0;
}