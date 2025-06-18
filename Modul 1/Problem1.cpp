#include<iostream>

using namespace std;

struct mhs {
    char nama[20], nim[10], jurusan[2];
    int sks, program;
};

struct mhs bayar[2];

int main(){
    int bts, var, tetap;

    for(int i = 0; i < 2; i++) {
        // Input data
        cout << "\n\n----------------------------------\n";
        cout << "\nNama mhs\t= "; cin.getline(bayar[i].nama, 20);
        cout << "NIM\t\t= "; cin >> bayar[i].nim;
        cout << "Jurusan[TI, PTK]\t= "; cin >> bayar[i].jurusan;

    input:
        cout << "Program[1=D3, 2=S1] = ";
        cin >> bayar[i].program;

        if(bayar[i].program < 1 || bayar[i].program > 2) {
            cout << "Program tidak sesuai\n";
            goto input;
        }

        cout << "Jumlah sks\t= "; cin >> bayar[i].sks;

        if(bayar[i].program == 1) {
            tetap = 500000;
            var = bayar[i].sks * 25000;
        }
        else if(bayar[i].program == 2) {
            tetap = 750000;
            var = bayar[i].sks * 50000;
        }
        cin.ignore();
        cout << endl;

        // Output data
        cout << "\n\n----------------------------------\n";
        cout << " Output ";
        cout << "\n----------------------------------\n";
        cout << "\nNama mhs\t= " << bayar[i].nama;
        cout << "\nNIM\t\t= " << bayar[i].nim;
        cout << "\nJurusan\t\t= " << bayar[i].jurusan;
        cout << "\nProgram\t\t= " << bayar[i].program;
        cout << "\nJumlah sks\t= " << bayar[i].sks;
        cout << "\nSPP tetap\t= " << tetap;
        cout << "\nSPP variabel\t= " << var;
        cout << endl << endl;
    }

    return 0;
}