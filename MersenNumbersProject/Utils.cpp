#include <iostream>
#include <climits>
using namespace std;

void continueOrTerminate() {
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "Continue or press 0 to exit: " << endl;
    cout << "-----------------------------" << endl;
    return;
}

//�������� ������� �� ��������, � ������ p
int powCount(long long mersenNPlusOne) {
    int count = 0;

    while (mersenNPlusOne != 1) {
        if (mersenNPlusOne % 2 != 0) {
            return 0;
        }
        mersenNPlusOne /= 2;
        count++;
    }
    return count;
}

//�������� ���� ���� ����� � ������
bool isPrime(long long mersenN) {
    //���-������� ������ �����
    if (mersenN == 2) {
        return true;
    }

    if (mersenN < 2 || mersenN % 2 == 0) {
        return false;
    }

    //���������� ������� �����, ������ ���������� ����
    long long squaredN = sqrt(mersenN);
    for (long long i = 3; i <= squaredN; i += 2) {
        if (mersenN % i == 0) {
            return false;
        }
    }
    return true;
}
//�������� �� ������� �����
long long inputMersenNumber(long long mersenN, int minRange, long long maxRange) {
    cout << "Please input a number: ";
    cin >> mersenN;
    while (cin.fail() || mersenN < minRange || mersenN > maxRange) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number!" << endl;
        cout << "Please try again (0; 2305843009213693951): ";
        cin >> mersenN;
    }
    return mersenN;
}
//�������� �� ������� minRange
long long inputMinRange(int minRange) {
    long long min;
    cout << "Please input min range(min >= 0): ";
    cin >> min;
    while (cin.fail() || min < minRange) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number!" << endl;
        cout << "Please try again (min >= 0): ";
        cin >> min;
    }
    return min;
}
//�������� �� ������� maxRange
long long inputMaxRange(long long maxRange) {
    long long max;
    cout << "Please input max range(max <= 2305843009213693951): ";
    cin >> max;
    while (cin.fail() || max > maxRange) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number!" << endl;
        cout << "Please try again (max <= 2305843009213693951): ";
        cin >> max;
    }
    return max;
}

long long* saveDivisorsInArr(long long n, int& arrSize) {
    //������� �� 4
    if (n < 3) {
        cout << "No composite divisors for number: " << n << endl;
        arrSize = 0;
        long long* emptyArr = new long long[arrSize];
        return emptyArr;
    }

    if (isPrime(n)) {
        cout << "Error " << n << " is Prime!It has no composite divisors!" << endl;
        arrSize = 0;
        long long* emptyArr = new long long[arrSize];
        return emptyArr;
    }

    long long nCopy = n;
    //��������� �������� �� ������ ����� ���������� �� �������� �� ���������� �� ����������� �����
    for (long long i = 2; i <= nCopy; i++) {
        if (!isPrime(i) && nCopy % i == 0) {
            arrSize++;
        }
    }

    long long* compositeArr = new long long[arrSize];
    int index = 0;
    nCopy = n;

    //������� ������ �������� �������� � ������;
    for (long long i = 2; i <= nCopy; i++) {
        if (!isPrime(i) && nCopy % i == 0) {
            compositeArr[index++] = i;
        }
    }

    return compositeArr;
}
