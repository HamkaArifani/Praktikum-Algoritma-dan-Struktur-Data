#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define MAX 20

using namespace std;

struct stack {
    int data[MAX];
    int atas;
};
stack Tumpuk;
void init(){
    Tumpuk.atas=-1;
}
int kosong(){
    if (Tumpuk.atas ==-1)
        return 1;
    else 
        return 0;
}
int penuh() {
    if (Tumpuk.atas == MAX-1)
        return 1;
    else
        return 0;
}

void input(int data) {
    if (kosong() == 1) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack ";
    }
    else if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack ";
    }
    else
        cout << "Tumpukan Penuh";
}
void hapus() {
    if (kosong() == 0) {
        cout << "Data Teratas Sudah Terambil";
        Tumpuk.atas--;
    }
    else
        cout << "Data Kosong";
}

void tampil() {
    if (kosong() == 0) {
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "\nTumpukan Ke " << i << " = "
                 << Tumpuk.data[i];
        }
    }
    else
        cout << "Tumpukan Kosong";
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong";
}
int main(){
    int Pilihan, Nilai;
    init();
    do {
        
        cout << "=== PROGRAM STACK DENGAN ARRAY ===\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. CETAK STACK\n";
        cout << "4. RESET\n";
        cout << "5. EXIT\n";
        cout << "Pilihan = ";
        cin >> Pilihan;

        switch (Pilihan) {
        case 1:
            cout << "Masukkan Data: ";
            cin >> Nilai;
            input(Nilai);
            break;
        case 2:
            hapus();
            break;
        case 3:
            tampil();
            break;
        case 4:
            bersih();
            break;
        case 5:
            cout << "Terima Kasih!\n";
            break;
        default:
            cout << "Pilihan Tidak Valid!\n";
        }

        cout << "\nPress any key to continue...";
        getch();
        system("cls");
    } while (Pilihan != 5);
    return 0;
}