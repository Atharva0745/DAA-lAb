#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the maximum value for the fractional knapsack problem
double fractionalKnapsack(vector<int>& weights, vector<int>& values, vector<int>& shelfLife, int capacity) {
    // Error handling for invalid inputs
    if (weights.size() != values.size() || values.size() != shelfLife.size()) {
        cout << "Error: All input vectors (weights, values, shelfLife) must have the same size." << endl;
        return -1;  // Return an error code
    }
    if (capacity < 0) {
        cout << "Error: Capacity cannot be negative." << endl;
        return -1;  // Return an error code
    }
    
    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] < 0 || values[i] < 0 || shelfLife[i] < 0) {
            cout << "Error: Weights, values, and shelf life must be non-negative." << endl;
            return -1;  // Return an error code
        }
    }

    // Vector to store items with (shelfLife/value, weight, value)
    vector<pair<double, pair<int, int>>> items;
    int n = weights.size();

    // Calculate shelfLife/value ratio and store it with corresponding weight and value
    for (int i = 0; i < n; i++) {
        // Prevent division by zero for value
        if (values[i] == 0) {
            cout << "Error: Values cannot be zero as it results in undefined ratio." << endl;
            return -1;  // Return an error code
        }
        double ratio = static_cast<double>(shelfLife[i]) / values[i];
        items.push_back({ratio, {weights[i], values[i]}});
    }

    // Sort items based on the shelfLife/value ratio in descending order
    sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });

    double currentWeight = 0;
    double currentValue = 0;

    // Iterate over the sorted items
    for (int i = 0; i < items.size(); i++) {
        int w = items[i].second.first;
        int v = items[i].second.second;

        // If adding the whole item does not exceed capacity, add it
        if (currentWeight + w <= capacity) {
            currentWeight += w;
            currentValue += v;
        } 
        // Else add the fraction of the remaining capacity and break
        else {
            double remain = capacity - currentWeight;
            currentValue += v * (remain / w);
            break;
        }
    }

    return currentValue;
}

int main() {
    vector<int> weights = {10, 20, 30};     // Example weights
    vector<int> values = {60, 100, 120};    // Example values
    vector<int> shelfLife = {2, 3, 5};      // Example shelf lives
    int capacity = -12;                      // Example capacity

    double maxValue = fractionalKnapsack(weights, values, shelfLife, capacity);
    if (maxValue != -1) {  // Check if an error code was returned
        cout << "Maximum value in knapsack: " << maxValue << endl;
    } else {
        cout << "Failed to calculate the maximum value due to input errors." << endl;
    }

    return 0;
}

