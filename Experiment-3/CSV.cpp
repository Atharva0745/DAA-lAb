#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>
using namespace std;

// Function to generate a random name
string generateRandomName() {
    vector<string> firstNames = {"John", "Jane", "Alex", "Emily", "Chris", "Katie", "Michael", "Sarah", 
                                 "David", "Laura"};
    vector<string> lastNames = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Miller", "Davis", 
                                "Garcia", "Wilson", "Martinez"};
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> firstNameDist(0, firstNames.size() - 1);
    uniform_int_distribution<> lastNameDist(0, lastNames.size() - 1);
    
    string firstName = firstNames[firstNameDist(gen)];
    string lastName = lastNames[lastNameDist(gen)];
    
    return firstName + " " + lastName;
}

// Function to generate a random salary between 10,000 and 100,000
int generateRandomSalary() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> salaryDist(10000, 100000);
    
    return salaryDist(gen);
}

int main() {
    // Open the file for writing
    ofstream file("5input.csv");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Write the header
    file << "Name,Salary\n";

    // Generate and write 2000 records
    for (int i = 0; i < 2000; ++i) {
        string name = generateRandomName();
        int salary = generateRandomSalary();
        file << name << "," << salary << "\n";
    }

    file.close();
    cout << "CSV file created successfully!" << endl;
    
    return 0;
}
