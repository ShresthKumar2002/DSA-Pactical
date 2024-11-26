#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Calculate the middle index to avoid overflow

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;  // Target found, return index
        else if (arr[mid] < target)
            left = mid + 1;  // Ignore left half
        else
            right = mid - 1;  // Ignore right half
    }
    
    return -1;  // Target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout<< "Enter the target ";
    cin>>target;

    int result = binarySearch(arr, size, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}