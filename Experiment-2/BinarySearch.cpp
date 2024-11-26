//binary Search
#include <bits/stdc++.h>
using namespace std;

// Binary Search Function
int BinarySearch(const vector<int>& arr, int key) {
    int f = 0;
    int b = arr.size() - 1;
    int mid;
    
    while (f <= b) {
        mid = (f + b) / 2;
        if (arr[mid] == key) {
            return mid;  // Return index if found
        } else if (arr[mid] < key) {
            f = mid + 1;  // Search in the right half
        } else {
            b = mid - 1;  // Search in the left half
        }
    }
    
    return -1;  // Key not found
}

int main() {
    int key, size, a;
    
    // Input array size
    cout << "Enter size of the array: ";
    cin >> size;
    
    vector<int> v(size);
    
    // Input the key to be searched
    cout << "Enter the key to search: ";
    cin >> key;
    
    // Input array elements
    cout << "Enter the elements of the array (must be sorted): ";
    for (int i = 0; i < size; i++) {
        cin >> a;
        v[i] = a;
    }
    
    // Ensure the array is sorted
    sort(v.begin(), v.end());

    // Perform binary search
    int result = BinarySearch(v, key);
    
    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    } else {
        cout << "Key not found" << endl;
    }

    return 0;
}
