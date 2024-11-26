#include <bits/stdc++.h>
using namespace std;

// Function to merge two halves and count cross inversions
int mergeAndCount(vector<pair<int, int>>& students, int left, int mid, int right) {
    int inversions = 0;
    
    // Create temporary arrays to hold the left and right subarrays
    vector<pair<int, int>> leftSubarray(students.begin() + left, students.begin() + mid + 1);
    vector<pair<int, int>> rightSubarray(students.begin() + mid + 1, students.begin() + right + 1);
    
    int i = 0, j = 0, k = left;

    // Merge the two subarrays back into the original array
    while (i < leftSubarray.size() && j < rightSubarray.size()) {
        // If the left element is smaller or equal, no inversion
        if (leftSubarray[i].first <= rightSubarray[j].first) {
            students[k++] = leftSubarray[i++];
        } else {
            // There is an inversion, all elements left in the leftSubarray form inversions
            students[k++] = rightSubarray[j++];
            inversions += (leftSubarray.size() - i);  // All remaining elements in the leftSubarray are greater
        }
    }

    // Copy remaining elements of leftSubarray, if any
    while (i < leftSubarray.size()) {
        students[k++] = leftSubarray[i++];
    }

    // Copy remaining elements of rightSubarray, if any
    while (j < rightSubarray.size()) {
        students[k++] = rightSubarray[j++];
    }

    return inversions;
}

// Function to use Merge Sort and count inversions
int mergeSortAndCount(vector<pair<int, int>>& students, int left, int right) {
    int inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort and count inversions in the left half
        inversions += mergeSortAndCount(students, left, mid);

        // Recursively sort and count inversions in the right half
        inversions += mergeSortAndCount(students, mid + 1, right);

        // Merge the two halves and count cross inversions
        inversions += mergeAndCount(students, left, mid, right);
    }
    return inversions;
}

int main() {
    // Example input: 100 pairs of (first_year_course_code, second_year_course_code)
    // For the sake of the example, we only fill a few pairs
    vector<pair<int, int>> students = {
        {101, 102}, {103, 101}, {104, 103}, {105, 101}, {106, 106},
        {107, 104}, {108, 107}, {109, 105}, {110, 103}, {111, 108},
        // Add remaining students here (total 100 pairs in real input)
    };
    
    // Total inversion count
    int totalInversions = mergeSortAndCount(students, 0, students.size() - 1);
    
    // Output the result
    cout << "Total number of inversions: " << totalInversions << endl;

    // Optionally, you can print the sorted array to see the result
    cout << "Sorted Students List (by first year course code):\n";
    for (const auto& student : students) {
        cout << student.first << ", " << student.second << endl;
    }

    return 0;
}
