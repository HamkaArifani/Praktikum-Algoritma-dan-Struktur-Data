#include<iostream>

using namespace std;

struct problem3{
    char huruf;
    char kata[20];
    int angka;
};

int main(){
    problem3 Tulisan;
    cout<<"Masukkan sebuah huruf: ";cin>>Tulisan.huruf;cin.ignore();
    cout<<"Masukkan sebuah kata: ";cin.getline(Tulisan.kata,20);
    cout<<"Masukkan angka: ";cin>>Tulisan.angka;
    cout<<"Huruf yang Anda masukkan adalah "<<Tulisan.huruf<<endl;
    cout<<"Kata yang Anda masukkan adalah "<<Tulisan.kata<<endl;
    cout<<"Angka yang Anda masukkan adalah "<<Tulisan.angka<<endl;
    return 0;
}