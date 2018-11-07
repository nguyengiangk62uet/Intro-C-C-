#include <iostream>
#include <string.h>
using namespace std;

void convertToHex(int n) {
    int so = n;
    int i = 0;
    char s[100];
    while (n != 0) {
        int temp = n % 16;
        n /= 16;
        if (temp > 9) {
            s[i++] = (char)(temp + 55);
        } else {
            s[i++] = (char)(temp + 48);
        }
    }
    s[i] = '\0'; // Xoa ki tu cuoi
    cout << "\nConvert " << so << " to Hexa: \n";
    for (int j = i - 1; j >= 0; j--) {
        cout << s[j];
    }
}

void convertToBin(int n) {
    int bin[100];
    int i = 0;
    int so = n;
    while (n != 0) {
        int temp = n % 2;
        n /= 2;
        bin[i++] = temp;
    }
    cout << "Convert " << so << " to Binary: \n";
    for (int j = i - 1; j >= 0; j--) {
        cout << bin[j];
    }
}

int main() {
    int n;
    cout << "Input Decima: \n";
    cin >> n;
    convertToBin(n);
    convertToHex(n);
    return 0;
}