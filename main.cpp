#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    const int Max_SIZE = 100;
    int arr1[Max_SIZE], arr2[Max_SIZE];

    int size1, size2;
//    ask user for first size of array
    cout << "enter the first size of array";
    cin >> size1;

    for (int i = 0; i < size1; i++) {
        cin>>arr1[i];
    }

//    ask user for second size of array
    cout << "enter the second size of array";
    cin >> size2;

    for (int i = 0; i < size2; i++) {
        cin>>arr2[i];
    }
    sort(arr1, arr1 + size1);
    sort(arr2, arr2 + size2);
    cout << "sorted 1st array is" << endl;
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << "sorted 1st array is" << endl;
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    if (size1 != size2) {
        cout << "The two arrays are not equal.\n";
    } else {
        bool equal = true;
        for (int i = 0; i < size1; i++) {
            if (arr1[i] != arr2[i]) {
                equal = false;
                break;
            }
        }
        if (equal) {
            cout << "The two arrays are equal.\n";
        } else {
            cout << "The two arrays are not equal.\n";
        }
    }

    return 0;






}