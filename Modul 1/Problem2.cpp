#include<iostream>

using namespace std;

struct transportasi{
    char no_kendaraan[20], jenis[20], pemilik[50], alamat[30], kota[30];
};

int main(){
    transportasi kendaraan;
    cout<<"Masukkan Plat Nomor Kendaraan: ";
    cin.getline(kendaraan.no_kendaraan, 20);
    cout<<"Masukkan jenis Kendaraan: ";
    cin.getline(kendaraan.jenis, 20);
    cout<<"Masukkan Nama Pemilik Kendaraan: ";
    cin.getline(kendaraan.pemilik, 50);
    cout<<"Masukkan Alamat: ";
    cin.getline(kendaraan.alamat, 30);
    cout<<"Masukkan kota: ";
    cin.getline(kendaraan.kota, 30);

    cout<<"Plat Nomor Kendaraan: "<<kendaraan.no_kendaraan<<endl;
    cout<<"Jenis Kendaraan: "<<kendaraan.jenis<<endl;
    cout<<"Nama Pemilik: "<<kendaraan.pemilik<<endl;
    cout<<"Alamat: "<<kendaraan.alamat<<endl;
    cout<<"Kota: "<<kendaraan.kota<<endl;
    return 0;
}