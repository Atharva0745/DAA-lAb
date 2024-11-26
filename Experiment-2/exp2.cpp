// Linear Search
#include <bits/stdc++.h>
using namespace std;
// Linear Search
int LinearSearch(vector<int> arr, int key)
{
    int i = 0;
    while (i < arr.size())
    {
        if (arr[i] == key)
        {
            return i;
        }
        i++;
    }
    return -1;
}
int main()
{
    int key, size, a;
    cout << "Enter size";
    cin >> size;
    vector<int> v(size);
    cout << "Enter the key";
    cin >> key;
    cout << "Enter the element";
    for (int i = 0; i < size; i++)
    {
        cin >> a;
        v[i] = a;
    }
    cout << endl;
    cout << "Output--> :" << LinearSearch(v, key);
    return 0;
}