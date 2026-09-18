#include <iostream>
using namespace std;

int main(){
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;

    int hitungan = 1;
    bool* bertahan = new bool[N+1];
    int jumlah_bertahan = N;

    for (int i = 1; i <= N; i++) {
        bertahan[i] = true;
    }

    cout << "Yang tereliminasi: ";

    while (jumlah_bertahan > 1) {
        for (int i = 1; i <= N; i++) {
            if (bertahan[i]== false) {
                continue;
            }
            
            if (hitungan == K) {
                bertahan[i] = false;
                cout << i << " ";
                jumlah_bertahan--;
                hitungan = 1;
                
                if (i % 2 == 0) {
                    K += 2;
                } else {
                    K -= 1;
                }

                if (K < 2) {
                    K = 2;
                }
            } else {
                hitungan++;
            }
        }
    }

    cout << endl;

    cout << "Yang bertahan: ";
    for (int i = 1; i <= N; i++) {
        if (bertahan[i] == true) {
            cout << i << " ";
            break;
        }
    }

    delete[] bertahan;

    return 0;
}