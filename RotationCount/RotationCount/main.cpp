//
//  main.cpp
//  RotationCount
//
//  Created by Sunny Vats on 18/03/21.
//

#include <iostream>
using namespace std;

int findNoOfRotation(int arr[], int leftIndex, int rightIndex) {
    // Condition to check whether there is single element in array
    if( leftIndex == rightIndex ) return leftIndex;
    // Condition to check if array is rotated at all
    if( arr[leftIndex] < arr[rightIndex] ) return leftIndex;
    int mid = ( leftIndex + rightIndex ) / 2;
    // Condition if rotation point found at mid
    if( arr[mid] > arr[leftIndex] && arr[mid+1] < arr[mid] ) return (mid+1);
    // Condition if rotation point found at mid+1
    if( arr[mid] < arr[leftIndex] && arr[mid] < arr[mid-1] ) return mid;
    // Condition if element at mid is greater than element at leftIndex
    if( arr[rightIndex] > arr[mid] )
        return findNoOfRotation(arr, leftIndex, mid-1);
    return findNoOfRotation(arr, mid+1, rightIndex);
}

int main() {
    int arr[] = {3, 4, 5, 5, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << findNoOfRotation(arr, 0, size-1) << endl;
    return 0;
}
