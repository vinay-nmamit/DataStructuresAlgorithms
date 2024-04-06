// 1137. Nth tribonacchi number

#include <iostream>
using namespace std;

int tribonachhi(int n){
    int arr[38] = {0, 1, 1};
    for(int i = 3; i < sizeof(arr)/sizeof(int); i++){
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }   
    return arr[n];
}


int main(){
    int x;
    cin >> x;
    int result = tribonachhi(x);
    cout << result << endl;
    return 0;
}