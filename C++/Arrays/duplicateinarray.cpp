#include <iostream>
#include <climits>
#include <vector>
using namespace std;
// Approach 1: Nested Loops
int findDuplicate(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                // Found a duplicate number
                return arr[i];
            }
        }
    }
    // No duplicate found
    return -1;
}

// Approach 2: Counting using Array
int findDuplicate(vector<int> &arr)
{
    int n = arr.size();
    vector<int> cnt(n, 0); // Array to count occurrences
    for (int i = 0; i < n; i++)
    {
        cnt[arr[i]]++; // Count occurrences of each number
    }
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] > 1)
        {
            // Found a duplicate number
            return i;
        }
    }
    // No duplicate found
    return -1;
}

// Approach 3: Bitwise XOR
int findDuplicate(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i]; // Calculate XOR of all elements
    }
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ i; // XOR with indices
    }
    // Result is the XOR of the duplicate number and indices
    return ans;
}
int main()
{
    // Example test case
    vector<int> arr = {1, 2, 3, 4, 4};
    int result = findDuplicate(arr);
    cout << "Duplicate number: " << result << endl;

    return 0;
}