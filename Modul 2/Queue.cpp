#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define MAX 20

using namespace std;

struct queue{
    int F,R;
    char Q[MAX];
};
void Inisialisasi(queue &q){
    q.F=-1;
    q.R=-1;
}
bool IsFull(queue &q){
    return(q.R == MAX-1);
}
bool IsEmpty(queue &q){
    return (q.R==-1|| q.F > q.R);
}
void Insert(queue &q, int data){
    if (IsFull(q)){
        cout<<"Queue Penuh"<<endl;
    } else {
        if (q.F==-1)q.F=0;
        q.R++;
        q.Q[q.R]= data;
        cout<<"Memasukkan : "<<data<<" pada queue"<<endl;
    }
}
void Cetaklayar(queue &q){
    if (IsEmpty(q)){
        cout<<"Queue Kosong"<<endl;
    } else {
        for (int i=q.F; i<=q.R;i++){
            cout<<"\nQueue ke "<<(i - q.F + 1)<<" = "<<q.Q[i]<<endl;
        }
    }
}
void Delete(queue &q){
    if (IsEmpty(q)){
        cout << "Queue Kosong" << endl;
    } else {
        cout << "Menghapus : " << q.Q[q.F] << endl;
        for (int i = q.F; i < q.R; i++) {
            q.Q[i] = q.Q[i + 1];
        }
        q.R--;
        if (q.R < 0) {
            q.F = q.R = -1;
        }
    }
}
void Reset(queue &q){
    q.F=-1;
    q.R=-1;
    cout<<"Queue telah direset\n";
}
int main(){
    queue q;
    int  PIL;
    char Pilihan[2], huruf;
    Inisialisasi(q);
    do {
        cout<<"QUEUE"<<endl;
        cout<<"=================="<<endl;
        cout<<"1. INSERT"<<endl;
        cout<<"2. DELETE"<<endl;
        cout<<"3. CETAK QUEUE"<<endl;
        cout<<"4. RESET"<<endl;
        cout<<"5. QUIT"<<endl;
        cout<<"PILIHAN : "; cin>>Pilihan;
        PIL=atoi(Pilihan);

        switch (PIL) {
            case 1:
                cout<<"Masukkan Queue: ";
                cin>>huruf;
                Insert(q, huruf);
                break;
            case 2:
                Delete(q);
                break;
            case 3:
                Cetaklayar(q);
                break;
            case 4:
                Reset(q);
                break;
            default:
                cout<<"TERIMA KASIH"<<endl;
                break;
        }
        cout<<"Press any key to continue"<<endl;
        getch();
        system("cls");
    } while (PIL!=5);
    return 0;
}