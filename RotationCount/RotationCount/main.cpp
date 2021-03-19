//
//  main.cpp
//  RotationCount
//
//  Created by Sunny Vats on 18/03/21.
//

#include <iostream>
using namespace std;

int findNoOfRotation(int arr[], int left, int right) {
    int count=0;
    if(arr[right] > arr[left] )
        return left;
    if(arr[right] == arr[left])
        return left;
    int mid = (left + right) / 2;
    if(arr[right] < arr[left] && arr[right+1] > arr[mid]) {
        return right;
    }
    else
        findNoOfRotation(arr, 0, mid-1);
    return count;
}

int main() {
    int arr[] = {15, 18, 2, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << findNoOfRotation(arr, 0, size-1) << endl;
    return 0;
}
