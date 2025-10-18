// Binary Search in C++
// This program performs binary search on a sorted array entered by the user.

#include <iostream>
using namespace std;

// Function to perform Binary Search
int binarySearch(int arr[], int target, int first, int last) {
    while (first <= last) {
        int mid = first + (last - first) / 2; 

        if (arr[mid] == target)
            return mid;  // Found the element

        else if (arr[mid] < target)
            first = mid + 1;  // Search right half

        else
            last = mid - 1;   // Search left half
    }

    return -1;  // Element not found
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    int result = binarySearch(arr, target, 0, n - 1);

    if (result == -1)
        cout << "Element not found." << endl;
    else
        cout << "Element found at index " << result << "." << endl;

    return 0;
}
