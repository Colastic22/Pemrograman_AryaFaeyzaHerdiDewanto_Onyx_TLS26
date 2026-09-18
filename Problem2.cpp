#include <iostream>

using namespace std;

int charToHuruf(char ch) {
    if (ch >= 'a' && ch <= 'z') return ch - 'a' + 1;
    else return ch - 'A' + 1;
}

char hurufToChar(int huruf, bool lowercase) {
    if (lowercase) {
        return huruf + 'a' - 1;
    } else {
        return huruf + 'A' - 1;
    }
}

int hitungPanjang(char arr[]) {
    int panjang = 0;
    while (arr[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

int main() {
    char pesan[1000];
    cout << "Masukkan pesan: ";
    cin >> pesan;

    int panjang = hitungPanjang(pesan);
    char sandi[1000]; 
    int prevChar = 0;

    for (int i = 0; i < panjang; ++i) {
        int ch = charToHuruf(pesan[i]);
        ch += prevChar;

        while (ch > 26) {
            ch -= 26;
        }

        sandi[i] = hurufToChar(ch, pesan[i] >= 'a' && pesan[i] <= 'z');
        
        prevChar = charToHuruf(pesan[i]);
    }
    
    sandi[panjang] = '\0'; 

    cout << "Pesan sandi: " << sandi << endl;

    return 0;
}