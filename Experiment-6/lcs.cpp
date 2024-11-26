#include <bits/stdc++.h> 
using namespace std; 
 
string LCS(string X, string Y) 
{ 
    int m = X.size(); 
    int n = Y.size(); 
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); 
 
    X = '0' + X; 
    Y = '0' + Y; 
 
    for (int i = 1; i <= m; i++) 
    { 
        for (int j = 1; j <= n; j++) 
        { 
            if (X[i] == Y[j]) 
            { 
                dp[i][j] = dp[i - 1][j - 1] + 1; 
            } 
            else 
            { 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
            } 
        } 
    } 
 
    string ans = ""; 
    int i = m, j = n; 
    while (i > 0 && j > 0) 
    { 
        if (X[i] == Y[j]) 
        { 
            ans = string(1, X[i]) + ans; 
            i--; 
            j--; 
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) 
        { 
            i--; 
        } 
        else 
        { 
            j--; 
        } 
    } 
 
    return ans; 
} 
 
int main() 
{ 
    vector<string> v; 
    int st; 
    cout << "Give the number of strings as input: "; 
    cin >> st; 
 
    if (st <= 0) 
    { 
        cout << "No strings provided." << endl; 
        return 0; 
    } 
 
    cout << "Enter the strings:" << endl; 
    for (int i = 0; i < st; i++) 
    { 
        string s; 
        cin >> s; 
        v.push_back(s); 
    } 
 
    string ans = v[0]; 
    for (int i = 1; i < st; i++) 
    { 
        ans = LCS(ans, v[i]); 
    } 
 
    cout << "Longest Common Subsequence: " << ans << endl; 
    return 0; 
} 