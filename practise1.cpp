#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<vector<int>> arrays;

    for(int i = 0; i < n; i++){
        int size;
        cin >> size;

        vector<int> current_array;
         for(int j = 0; i < size; j++){
            int element;
            cin >> element;
            current_array.push_back(element);
         }

         arrays.push_back(current_array);

         for(int i = 0; i < q; i++){
            int array_index, element_index;
            cin >> array_index >> element_index;

            int value = arrays[array_index][element_index];

            cout << value << endl;

            return 0;
         }
    }
}