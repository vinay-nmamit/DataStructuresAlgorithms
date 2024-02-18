#include <iostream>
using namespace std;

void reverseArray(int arr[], int size){
    int revaArr[size];
    for(int i = 0; i < size; i++){
        revaArr[i] = arr[size-i-1];
    }
    cout << "reversd array: ";
    for(int i = 0; i < size; i++){
        cout << revaArr[i] << " ";
    }
}

int main(){
    int size;
    cin >> size;
    int originalArr[size];
    for(int i = 0; i < size; i++){
        cin >> originalArr[i];
    }

    reverseArray(originalArr, size);

}