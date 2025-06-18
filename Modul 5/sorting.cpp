#include <iostream>
#include <functional>
#include <conio.h>
#include <chrono>
#include <string>
#include <iomanip>

using namespace std;

string name = "Hamka Arifani";
string id = "2410817110006";

void timeSort(const function<void()>& sortFunc, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << fixed << setprecision(10);
    cout << sortName << " took " << duration.count() << " seconds\n";
}

void insertionSort(){
    string SortedName=name;
    for (int h=1; h<SortedName.length();h++) {
        int key = SortedName[h];
        int a = h-1;

        while (a>=0 && SortedName[a]>key ){
            SortedName[a+1] = SortedName[a];
            a--;
        }
        SortedName[a+1] = key;
    }
    cout<<SortedName<<endl;
}

void merge(string & str, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string l= str.substr(left, n1);
    string r= str.substr(mid + 1, n2);

    int i=0, j=0, k = left;

    while(i < n1 && j < n2){
        if(l[i]<= r[j]){
            str[k++] = l[i++];
        } else {
            str[k++] = r[j++];
        }
    }

    while (i < n1) {
        str[k++] = l[i++];
    }
    while (j < n2) {
        str[k++] = r[j++];
    }
}

void mergeSortHelper(string & str,int left, int right){
     if (left < right) {
        int mid= left + (right - left)/2;
        mergeSortHelper(str,left, mid);
        mergeSortHelper(str, mid +1, right);
        merge(str, left, mid, right);
     }
}

void mergeSort(){
     string SortedName=name;
     mergeSortHelper(SortedName, 0, SortedName.size() - 1);
     cout<<SortedName<<endl;
}

void shellSort(){
    int n = name.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = name[i];
            int j;
            for (j = i; j >= gap && name[j - gap] > temp; j -= gap) {
                name[j] = name[j - gap];
            }
            name[j] = temp;
        }
    }
    cout << name << endl;
}

void bubbleSort(){
    int h = id.size();

    for(int i = 0; i < h-1; i++){
        for (int k = 0; k < h - i - 1; k++){
            if (id[k] > id[k+1]){
                swap (id[k], id [k+1]);
            }
        }
    } cout<<id<<endl;
}

int partition(string & str, int low, int high){
    int pivot = str[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (str[j] <= pivot){
            i++;
            swap(str[i], str [j]);
        }
    }
    swap(str[i+1], str[high]);
    return i+1;
}

void quickSortHelper(string & str, int low, int high){
    if (low < high) {
        int pi = partition(str, low, high);
        quickSortHelper(str, low, pi - 1);
        quickSortHelper(str, pi + 1, high);
    }
}

void quickSort(){
    string SortedId=id;
    quickSortHelper(SortedId, 0, SortedId.length() - 1);
    cout<<SortedId<<endl;
}

void selectionSort(){
    string SortedId=id;
    int n = SortedId.length();

    for (int i = 0; i < n -1; i++) {
        int minIdx = i;
        for(int j = i +1; j < n; j++) {
            if (SortedId[j] < SortedId[minIdx]) {
                minIdx = j;
            }
        }
        swap(SortedId[i], SortedId[minIdx]);
    }
    cout<<SortedId<<endl;
}


int main(){
    int Menu;
    do {
        cout<<"====================="<<endl;
        cout<<"|------SORTING------|"<<endl;
        cout<<"====================="<<endl;
        cout<<"1. Insertion Sort"<<endl;
        cout<<"2. Merge Sort"<<endl;
        cout<<"3. Shell Sort"<<endl;
        cout<<"4. Quick Sort"<<endl;
        cout<<"5. Buble Sort"<<endl;
        cout<<"6. Selection Sort"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Masukkan Pilihan : ";
        cin>>Menu;

        switch(Menu){
            case 1:
            timeSort(insertionSort, "Insertion Sort");
            break;
            case 2:
            timeSort(mergeSort, "Merge Sort");
            break;
            case 3:
            timeSort(shellSort, "shell Sort");
            break;
            case 4:;
            timeSort(quickSort, "quick Sort");
            break;
            case 5:
            timeSort(bubbleSort, "bubble Sort");
            break;
            case 6:
            timeSort(selectionSort, "selection Sort");
            break;
            default:
            cout<<"\nTerima Kasih"<<endl;
            cout<<"Program was made by Hamka Arifani (2410817110006)"<<endl;
        }
         cout<<"\nPress Any Key to Continue"<<endl;
            getch();
            system("cls");
    } while(Menu < 7);    
    return 0;
}