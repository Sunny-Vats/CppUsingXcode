//
//  main.cpp
//  MergeSort
//
//  Created by Sunny Vats on 26/03/21.
//

#include <iostream>
using namespace std;

class Sorting {
public:
    void mergeSort( int arr[], int l, int r );
    void merge( int arr[], int l, int m, int r );
    void display( int arr[], int size );
};

void Sorting::mergeSort(int arr[], int l, int r) {      // left = 0, right = 0
    if ( l < r ) {                                      // true
        int m = ( l + r ) / 2;                          // mid = 0
        mergeSort(arr, l, m);                           // left = 0, right = 0
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
void Sorting::merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int arrLeft[n1+1], arrRight[n2+1];
    for( int i = 0; i < n1; i++ ) {
        arrLeft[i] = arr[l + i];
    }
    for( int j = 0; j < n2; j++ ) {
        arrRight[j] = arr[m + j + 1];
    }
    arrLeft[n1] = INT_MAX;          // whenever end of array is encountered
    /**
     * Example:
     * 1 5 ∞     2 3 ∞     first two sorted arrLeft and arrRight with ∞
     * ^            ^            pointing at first index of both arrays
     *  ^          ^            array contains :     1 1 3 2
     *  ^            ^          array contains :     1 2 3 2
     *  ^              ^        array contains :     1 2 3 2
     *  ^              ^        now at this point ∞ is compared with every number in the arrLeft remaining elements and therefore will print entire list:  1 2 3 5
     */
    arrRight[n2] = INT_MAX;
    int i = 0, j = 0;
    for( int k = l; k <= r; k++ ) {
        if( arrLeft[i] <= arrRight[j] ) {
            arr[k] = arrLeft[i];
            i++;
        }
        else {
            arr[k] = arrRight[j];
            j++;
        }
    }
}

void Sorting::display(int arr[], int size) {
    for( int i = 0; i < size; i++ ) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {5,1,3,2,4,6,7,8};
    Sorting obj;
    int len = sizeof(arr)/sizeof(int);  // len = 8
    obj.display(arr, len);
    obj.mergeSort(arr, 0, len - 1);     // l=0 , r=7
    obj.display(arr, len);
    return 0;
}
