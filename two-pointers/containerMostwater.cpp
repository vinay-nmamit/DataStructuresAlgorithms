// container with most water
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int Container(vector<int>& height){
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while(left < right){
        int curArea = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, curArea);

        if(height[left] < height[right]){
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}

int main(){
    int size;
    cout << "enter the size: ";
    cin >> size;
    vector<int> height(size);
    cout << "enter the height: ";
    for(int i = 0; i < size; i++){
        cin >> height[i];
    }

    int result = Container(height);

    cout << "max amount of water the container can store is: " << result;
    return 0;
}