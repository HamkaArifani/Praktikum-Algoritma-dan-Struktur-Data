#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;


void sequentialSearch(const vector<int> &nums, int target){
    int count = 0;
    vector<int> indices;
    for (int i = 0; i<nums.size(); i++){
        if (nums[i] == target) {
            count++;
            indices.push_back(i);
        }
    }
    if (count == 0){
        cout<<"Angka "<<target<<" tidak ditemukan pada Array"<<endl;
    } else {
        cout<<"Angka "<<target<<" ditemukan sebanyak "<<count<<" kali pada indeks: ";
        for (int idx : indices) cout<<idx<<" ";
        cout<<endl;
    }
}

void binarySearch(const vector<int> &nums, int target){
    int left = 0;
    int right = nums.size()-1;
    while (left<=right){
        int mid = left + (right-left)/2;
        if (nums[mid]== target){
            cout<<"Angka "<<target<<" ditemukan pada indeks: "<<mid<<endl;
            return;
        }else if (nums[mid]<target){
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    cout << "Angka " << target << " tidak ditemukan di array." << endl;
}

void clearScreen(){
    system("cls");
}

void explain(){

cout<<"Perbedaan dari Sequential Searching dan Binary Search adalah :\n";

cout<<"1. Cara Kerja :\n";
cout<<"==Sequential Search==\n";
cout<<"Dalam program ini Sequential bekerja dengan memeriksa ke seluruh isi data dari \n";
cout<<"awal hingga akhir, jika data yang dicari ditemukan maka ia akan mencatat \n";
cout<<"indeksnya dan melanjutkan pencarian sampai semua data selesai ditelusuri. Dan \n";
cout<<"setelahnya semua indeks dengan nilai yang dicari pun akan ditampilkan. \n";

cout<<"==Binary Search==\n";
cout<<"Binary search bekerja mencari data yang ingin ditemukan dengan menggunakan \n";
cout<<"tiga bagian penting yakni left, right, dan mid, dengan nilai tengah atau mid menjadi \n";
cout<<"parameter dalam proses pencarian data. Jika nilai dari mid sama dengan nilai yang ingin dicari\n";
cout<<"maka indeks pertama yang nilainya sama dengan nilai target yang dicari akan dicatat dan ditampilkan.\n";
cout<<"Sementara jika nilai mid lebih kecil dari target maka left akan berpindah ke mid +1\n";
cout<<"atau satu nilai setelah posisi mid sebelumnya, \n";
cout<<"dan jika nilai mid lebih besar dari target maka right akan dipindah ke satu nilai\n";
cout<<"sebelum posisi mid sebelumnya atau mid -1, barulah ketika left atau right baru\n";
cout<<"telah ditetapkan proses pencarian akan terus dilanjutkan hingga nilai mid sama\n";
cout<<" dengan target.\n";

cout<<"2. Big O notation :\n";

cout<<"==Sequential Search==\n";
cout<<"*Time Complexity :\n";
cout<<"a. Best Case : Secara umum adalah O(1) jika ditemukan langsung di urutan \n";
cout<<"pertama dan memang tidak ada lagi, namun jika seperti pada program yang \n";
cout<<"menelusuri 100 data pada vektor, dan semua indeks yang terdapat nilai target akan \n";
cout<<"ditampilkan maka akan menjadi O(N) atau dalam kasus ini O(100).\n";
cout<<"b. Average Case : Secara umum O(N) tetapi tidak sampai akhir data, namun jika \n";
cout<<"dalam kasus ini maka average case tidak berlaku karena memang keseluruhan \n";
cout<<"vektor tetap akan di telusuri.\n";
cout<<"c. Worst Case: Secara umum O(N) dan dalam kasus ini sama saja dengan best case \n";
cout<<"yakni O(100) baik jika data baru ditemukan di ujung ataupun tidak ditemukan \n";
cout<<"sama sekali.\n";
cout<<"*Space Complexity : Secara umum adalah O(1), dan pada kasus ini karena penggunaan \n";
cout<<"vektor maka bisa dimisalkan dengan O(K) dengan K adalah banyaknya indeks yang akan \n";
cout<<"ditampilkan karena nilainya sama, karena prosesnya hanya menggunakan \n";
cout<<"variabel lokal. Namun bisa saja ada kemungkinan terburuk dimana 100 data pada \n";
cout<<"vektor entah bagaimana nilainya sama dan notationnya menjadi O(100).\n";

cout<<"==Binary Search ==\n";
cout<<"*Time Complexity :\n";
cout<<"a. Best Case : O(1) Yakni ketika nilai mid ternyata langsung sama dengan nilai \n";
cout<<"   target pada iterasi pertama.\n";
cout<<"b. Average Case : O(log N) Sempat terjadi lebih dari satu kali iterasi.\n";
cout<<"c. Worst Case: O(log N) Nilai target baru ditemukan di bagian ujung data ketika \n";
cout<<"   iterasi sudah terjadi beberapa kali atau bahkan tidak ditemukan sama sekali\n";
cout<<"*Space Complexity : Jika iteratif seperti pada program ini maka O(1) tapi jika \n";
cout<<" rekursif maka O(log N).\n";

cout<<"3. Initial Requirement :\n";
cout<<"- Sequential Search : Tidak perlu mengurutkan isi dari vector terlebih dahulu.\n";
cout<<"- Binary Search : Isi dari vector perlu diurutkan sebelum proses pencarian.\n";

cout<<"4. Best Usage :\n";
cout<<"==Sequential Search==\n";
cout<<"Sequential search paling bagus digunakan saat data yang akan dicari nilai \n";
cout<<"tertentunya berukuran kecil hingga sedang, karena cara kerja algoritma sequential\n";
cout<<"search adalah mencari data dengan menelusuri keseluruhan data, sehingga akan \n";
cout<<"perlu waktu yang lebih banyak ketika ukuran datanya terlalu besar. Selain itu\n";
cout<<"sequential search juga bagus untuk digunakan pada data yang belum sempat \n";
cout<<"diurutkan karena keseluruhan data memang akan ditelusuri satu-persatu. \n";

cout<<"==Binary Search==\n";
cout<<"Binary search lebih cocok digunakan pada data yang isinya telah diurutkan, karena \n";
cout<<"cara kerja binary search yang menjadikan nilai mid sebagai parameter dalam \n";
cout<<"pencarian, perlu untuk mengetahui apakah nilai mid sudah sama atau belum \n";
cout<<"dengan nilai yang ingin dicari. Binary search juga cocok untuk digunakan pada \n";
cout<<"data yang berukuran besar sekalipun dengan syarat datanya sudah terurut \n";
cout<<"sempurna dari yang kecil hingga yang terbesar.\n";
}


int main() {
    int opt, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums (100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                cout<<"Berikut data 100 angka random dengan nilai antara 1-50: "<<endl;
                for (int i = 0; i < nums.size(); ++i) {
                     cout << "[" << i << "] " << nums[i] << (i + 1 < nums.size() ? ", " : "\n");
                }

                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                sort(nums.begin(), nums.end());
                cout << "Berikut data sebanyak " << size << " angka yang telah diurutkan: " << endl;
                for (int i = 0; i < nums.size(); ++i) {
                    cout << "[" << i << "] " << nums[i]<< (i + 1 < nums.size() ? ", " : "\n");
                }

                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Program was made by Hamka Arifani (2410817110006)" << endl;
                getch();
                clearScreen();
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}