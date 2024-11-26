#include <bits/stdc++.h>  
using namespace std; 

void SPI_cal(vector<int>& credit, vector<int>& grade, vector<float>& spi) { 
    cout << "Enter number of subjects:" << endl; 
    int n, c, g; 
    cin >> n; 

    int total_credit = 0; 
    for (int i = 0; i < n; i++) { 
        cout << "Enter credit and grade for subject " << i + 1 << endl; 
        cin >> c >> g; 
        grade.push_back(g); 
        credit.push_back(c); 
        total_credit += c; 
    } 

    float sum = 0;  
    for (int i = 0; i < n; i++) { 
        sum += grade[i] * credit[i];  
    } 

    float SPI = sum * 1.0 / total_credit; 
    spi.push_back(SPI); 
    cout << "Your SPI is: " << SPI << endl; 
} 

float CPI_cal(vector<float>& spi) { 
    int n = spi.size(); 
    float sum = 0; 
    for (int i = 0; i < n; i++) {  
        sum += spi[i]; 
    } 

    // Calculate CPI
    float CPI = sum / n; 
    cout << "Your CPI is: " << CPI << endl;  
    return CPI; 
} 

int main() { 
    vector<int> grades; 
    vector<int> credits; 
    vector<float> spi;  // Changed to float to store SPI values accurately

    int n; 
    cout << "Enter number of semesters: "; 
    cin >> n; 

    for (int i = 0; i < n; i++) { 
        SPI_cal(grades, credits, spi); 
    } 

    CPI_cal(spi);  
    return 0; 
}
