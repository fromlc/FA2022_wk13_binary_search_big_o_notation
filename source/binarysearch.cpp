
/*
 * binarysearch.cpp
 *
 *  Created on: Jun 29, 2012
 *      Author: Derek
 *
 *  Example of the binary search algorithm
 * 
 *  From YouTube video: https://youtu.be/vohuRrwbTT4
 *  Original code on pastebin: https://pastebin.com/fsmGF1hp
 */

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
// iterative binary search for int array
// 
// size parameter is the number of ints in passed array[]
//------------------------------------------------------------------------------
int binarySearch(int array[], int size, int searchValue) {
    int low = 0;
    int high = size - 1;

    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        int midValue = array[mid];

        if(searchValue == midValue) {
            return mid;     // found! at index mid
        }
        else if (searchValue > midValue) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;  // not found
}

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    int a[] = { 12, 22, 34, 47, 55, 67, 82, 98 };

    cout << "Numbers in array: ";
    for (int i : a) {
        cout << i << ' ';
    }
    cout << '\n';

    int userValue;

    cout << "\nEnter an integer: " << endl;
    cin >> userValue;

    int result = binarySearch(a, 8, userValue);

    if(result >= 0) {
        cout << "The number " << a[result] << " was found at the"
                " element with index " << result << endl;
    }
    else {
        cout << "The number " << userValue << " was not found. " << endl;
    }

    return 0;
}