#include <iostream>
#include "functions.h"
#include "Utils.h"
#include <climits>
using namespace std;

//����������� ���� ���������� ����� � ���������
bool validateMersen(long long mersenN, int pNumber) {
    if (pNumber <= 1) {
        return false;
    }

    //��� �������� pow �� ���� ������������ �� ������ ������ �����!
    long long mersenFomula = (1LL << pNumber) - 1;
    if (mersenFomula == mersenN) {
        return true;
    }
    return false;
}

//�������� ���� ������� �� ������ � ������
bool isMersenPrime(bool isMersen, bool isNumberPrime) {
    //��������� ���� ������� � ������ � ���� � ������ �����
    if (isNumberPrime && isMersen) {
        return true;
    }
    else {
        return false;
    }
}

//������ �������� ��� ��������� � ������ �����
void showDivisors(long long mersenN) {
    if (mersenN < 2) {
        cout << "No divisors for numbers less or equal to 1" << endl;
        return;
    }
    else  if (isPrime(mersenN)) {
        cout << "Number is Prime" << endl;
        return;
    }

    //��� ��������� � ������ �����
    long long squaredN = sqrt(mersenN);
    long long lastDivisor = 0;
    for (long long i = 2; i <= squaredN; i++) {
        if (mersenN % i == 0) {
            cout << i << " ";
            lastDivisor = i;
        }
    }

    for (long long i = lastDivisor; i > 1; i--) {
        if (i * i == mersenN) {
            continue;
        }
        if (mersenN % i == 0) {
              cout << mersenN / i << " ";
        }
    }

    cout << endl;
}

void showPrimeDivisors(long long mersenN) {

    //���-������� ������ �����
    if (mersenN < 2) {
        cout << "No prime divisors for numbers less or equal to 1" << endl;
        return;
    }

    if (isPrime(mersenN)) {
        long long primesArr[2] = { 1,mersenN };
        cout << primesArr[0] << "\t" << primesArr[1] <<endl;
        return;
    }

    int arrSize = 0;
    bool mersenIsPrime = false;
    long long copy = 0;
    long long mersenNCopy = mersenN;
    //��������� �������� �� ������ ����� ���������� �� �������� �� ���������� �� ����������� �����
    for (long long i = 2; i <= mersenNCopy; i++) {
        //�������� �� �������� �� ������
        if (mersenIsPrime) {
            break;
        }
        //��������� �� ��������� �� ������ ��������
        while (mersenNCopy != 1) {
            if (isPrime(i) && mersenNCopy % i == 0) {
            //�������� �� �� ��������� ���� � ���� �����!������ ��� �� ���� �� 2, �������� �� �� ������ ���� 1 ���!
                if (copy != i) {
                    arrSize++;
                }
                mersenNCopy /= i;
                //�������� ���� ������ ��������� ����� � ������ ���� �� ���� ��, �� �� ��������� ������
                if (isPrime(mersenNCopy) && copy != i) {
                    arrSize++;
                    mersenIsPrime = true;
                    break;
                }
                copy = i;
            }
            else {
                break;
            }
        }
    }

    long long* primesArr = new long long[arrSize];
    int index = 0;
    copy = 0;
    mersenNCopy = mersenN;

    //������� ������ ������ �������� �� ������ � ������;
    for (long long i = 2; i <= mersenNCopy; i++) {

        if (isPrime(mersenNCopy)) {
            break;
        }

        while (mersenNCopy != 1) {
            if (isPrime(i) && mersenNCopy % i == 0) {
                if (copy != i) {
                primesArr[index++] = i;
                }
                mersenNCopy /= i;
        if (isPrime(mersenNCopy) && copy != i) {
            primesArr[index++] = mersenNCopy;
            break;
        }
                copy = i;
            }
            else {
                break;
            }
        }
    }

    for (int i = 0; i < arrSize; i++) {
        cout << primesArr[i] << "\t";
    }

    delete[] primesArr;
    cout << endl;
    return;
}

void mersenNumbersInInterval(long long min, long long max) {

    long long power;
    //���-������� ��������� ����� � 3;
    if (min < 3) {
        min = 3;
    }
    cout << "Mersen numbers in interval: " << min << " - " << max << endl;
    for (long long i = min; i <= max; i++) {
        power = powCount(i + 1);
        //�������� ������� ��������� ����� � ���������
        if (validateMersen(i, power)) {
            for (long long j = i; j <= max; j+=j + 1) {
                cout << j << '\t';
            }
            break;
        }
    }
    cout << endl;
}

void showFirstNMersenNumbers(long long n, long long maxRange) {

    long counter = 0;
    //���������� ������ �� ���������!
    for (long long i = 3; i <= maxRange; i+= i + 1) {
        int pNumber = powCount(i + 1);
        if (validateMersen(i, pNumber)) {
            counter++;
            cout << i << '\t';

            //�������� ���� ������� ������ �� maxRange
            if (i == maxRange && counter != n) {
                cout << "Error - can not show mersen numbers out of maxRange!" << endl;
                return;
            }

            if (counter == n) {
                cout << endl;
                return;
            }
        }
    }
    cout << endl;
}

void showFirstNMersenPrimeNumbers(long long n, long long maxRange) {

    long counter = 0;
    for (long long i = 3; i <= maxRange; i+= i + 1) {
        long long pNumber = powCount(i + 1);
        bool isMersen = validateMersen(i, pNumber);
        bool primeNumber = false;
        //�������� ���� 1 ����� � ��������� � ������
        if (isMersen) {
            primeNumber = isPrime(i);
        }
        if (isMersenPrime(isMersen, primeNumber)) {
            counter++;
            cout << i << '\t';

            //�������� ���� ������� ������ �� maxRange
            if (i == maxRange && counter != n) {
                cout << "Error - can not show mersen numbers out of maxRange!" << endl;
                return;
            }

            if (counter == n) {
                cout << endl;
                return;
            }
        }
    }
    cout << endl;
}

void mersenPrimeNumbersInInterval(long long min, long long max) {
    long long power;
    bool isMersen;
    bool isNumberPrime;
    cout << "Mersen prime numbers in interval: " << min << " - " << max << endl;
    int arrSize = 0;
    for (long long i = min; i <= max; i++) {
        power = powCount(i + 1);
        isMersen = validateMersen(i, power);
        isNumberPrime = isPrime(i);

        if (isMersenPrime(isMersen, isNumberPrime)) {
            for (long long j = i; j <= max; j += j + 1) {
                if (isPrime(j)) {
                    arrSize++;
                }
            }
            break;
        }
    }

    long long* mersenPrimesArr = new long long[arrSize];
    int index = 0;
    //������� ������ ������ ������o�� ����� � ��������� � ������;
    for (long long i = min; i <= max; i++) {
        power = powCount(i + 1);
        isMersen = validateMersen(i, power);
        isNumberPrime = isPrime(i);

        if (isMersenPrime(isMersen, isNumberPrime)) {
            for (long long j = i; j <= max; j += j + 1) {
                if (isPrime(j)) {
                    mersenPrimesArr[index++] = j;
                }
            }
            break;
        }
    }
    for (int i = 0; i < arrSize; i++) {
        cout << mersenPrimesArr[i] << "\t";
    }

    delete[] mersenPrimesArr;
    cout << endl;
}

void showFirstNMersenPerfectNumbers(long long n, long long maxRange) {
    //�������� ����� � 2664208113044663506143305730492770368 � � ��-������ �� long long
    if (n > 8) {
        cout << "Error only first 8 mersen perfect numbers fit inside range" << endl;
        return;
    }

    long long perfectN;
    int arrSize = 0;
    for (long long i = 3; i <= maxRange; i+= i + 1) {
        long long pNumber = powCount(i + 1);
        bool isMersen = validateMersen(i, pNumber);
        bool primeNumber = false;
        if (isMersen) {
            primeNumber = isPrime(i);
        }

        if (isMersenPrime(isMersen, primeNumber)) {
            arrSize++;
            if (arrSize == n) {
                break;
            }
        }
    }

    long long* perfectArr = new long long[arrSize];
    int index = 0;
    //������� ������ ��������� ����� �� ������ � ������;
    for (long long i = 3; i <= maxRange; i+= i + 1) {
        long long pNumber = powCount(i + 1);
        bool isMersen = validateMersen(i, pNumber);
        bool primeNumber = false;
        if (isMersen) {
            primeNumber = isPrime(i);
        }
        if (isMersenPrime(isMersen, primeNumber)) {
            perfectN = i * (1LL << pNumber - 1);
            perfectArr[index++] = perfectN;

            if (index == n) {
                break;
            }
        }
    }
    for (int i = 0; i < arrSize; i++) {
        cout << perfectArr[i] << "\t";
    }
    delete[] perfectArr;
    cout << endl;
    return;
}

void showDifferenceOfDivisorsBtwTwoNumbers(long long n1, long long n2) {
    int arrSize1 = 0, arrSize2 = 0, resultSize = 0;
    //��������� 2�� ������ � ����������
    long long* arr1 = saveDivisorsInArr(n1, arrSize1);
    if (arrSize1 == 0) {
        cout << "Array1 has no members!Result is empty array!" << endl;
        delete[] arr1;
        return;
    }

    long long* arr2 = saveDivisorsInArr(n2, arrSize2);
    if (arrSize2 == 0) {
        //��������� ��������� �� 2�� ������
        for (int i = 0; i < arrSize1; i++) {
            cout << arr1[i] << "\t";
        }
        delete[] arr1;
        delete[] arr2;
        return;
    }

    int bitMaskSize = arrSize1;
    long long* bitMask = new long long[bitMaskSize];

    for (int i = 0; i < arrSize1; i++) {
        long long target = arr1[i];
        for (int j = 0; j < arrSize2; j++) {
            if (target == arr2[j]) {
                bitMask[i] = 1;
                break;
            }
            else if (j == arrSize2 - 1) {
                bitMask[i] = 0;
                resultSize++;
            }
        }
    }
    if (resultSize == 0) {
        cout << "Set has no members! Empty set!" << endl;
        return;
    }

    //��������� � ��������� ��������� �� 2�� ������ � ����� �����
    long long* result = new long long[resultSize];
    int index = 0;
    for (int i = 0; i < bitMaskSize; i++) {
        if (bitMask[i] == 0) {
            result[index++] = arr1[i];
        }
    }

    //��������� ��������� �� 2�� ������
    for (int i = 0; i < resultSize; i++) {
        cout << result[i] << "\t";
    }

    delete[] arr1;
    delete[] arr2;
    delete[] bitMask;
    delete[] result;
}