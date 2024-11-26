#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>  // For std::max and std::min
using namespace std;

// Find the maximum value in the vector using recursion
double findMax(const vector<double>& a, int lo, int hi) {
    if (lo == hi) {
        return a[lo];
    }
    int mid = (lo + hi) / 2;
    double leftMax = findMax(a, lo, mid);
    double rightMax = findMax(a, mid + 1, hi);
    return max(leftMax, rightMax);
}

// Find the minimum value in the vector using recursion
double findMin(const vector<double>& a, int lo, int hi) {
    if (lo == hi) {
        return a[lo];
    }
    int mid = (lo + hi) / 2;
    double leftMin = findMin(a, lo, mid);
    double rightMin = findMin(a, mid + 1, hi);
    return min(leftMin, rightMin);
}

int main() {
    ifstream inputFile("1input.csv");  // Input CSV file
    ofstream outputFile("output_finances.csv");  // Output CSV file
    vector<double> v;  // Vector to store salaries

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;  // Exit if file cannot be opened
    }

    string line;
    // Write the header for the output file
    outputFile << "Name,Salary,Tax,Home Rent,Bonus\n";

    // Skip the header line in the input file
    getline(inputFile, line);

    // Process each line
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string name, salaryStr;
        
        // Read the name and salary
        getline(ss, name, ',');
        getline(ss, salaryStr, ',');

        // Convert salary to double and store in vector
        double salary = stod(salaryStr);
        v.push_back(salary);

        // Calculate tax, home rent, and bonus
        double tax = 0.10 * salary;
        double homeRent = 0.20 * salary;
        double bonus = 0.15 * salary;

        // Write the results to the output file
        outputFile << name << "," << salary << "," << tax << "," << homeRent 
                   << "," << bonus << "\n";
    }

    inputFile.close();
    outputFile.close();

    cout << "Calculations completed and output saved to 'output_finances.csv'." << endl;

    // Find the minimum and maximum salary using the recursive functions
    if (v.empty()) {
        cout << "No salaries found in the data." << endl;
    } else {
        cout << "Min Salary -> " << findMin(v, 0, v.size() - 1) << endl;
        cout << "Max Salary -> " << findMax(v, 0, v.size() - 1) << endl;
    }

    return 0;
}
