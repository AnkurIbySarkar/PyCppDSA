#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
pair<int, int> findSimilarity(vector<int> arr1, vector<int> arr2, int n, int m)
{
    int cnt = 0;   // Counter for common elements
    set<int> st;   // Set to store unique elements
    set<int> val2; // Set to store elements of arr2

    // Insert elements of arr2 into val2 set
    for (int i = 0; i < m; i++)
    {
        val2.insert(arr2[i]);
    }

    // Check for common elements between arr1 and arr2
    for (int i = 0; i < n; i++)
    {
        if (val2.find(arr1[i]) != val2.end()) // If element is found in val2 set
        {
            cnt++; // Increment common counter
        }
    }

    // Insert elements of arr1 into st set
    for (auto i : arr1)
    {
        st.insert(i);
    }

    // Insert elements of arr2 into st set
    for (auto i : arr2)
    {
        st.insert(i);
    }

    return {cnt, st.size()}; // Return the count of common elements and the size of the set
}

pair<int, int> findSimilarity(vector<int> arr1, vector<int> arr2, int n, int m)
{
    int cnt = 0;                    // Counter for common elements
    sort(arr1.begin(), arr1.end()); // Sort arr1 in ascending order
    sort(arr2.begin(), arr2.end()); // Sort arr2 in ascending order

    int i = 0, j = 0;
    vector<int> Union; // Vector to store unique elements

    // Merge the arrays while removing duplicates
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j] && (Union.empty() || Union.back() != arr1[i]))
        {
            Union.push_back(arr1[i]); // Add common element to Union vector
            cnt++;                    // Increment common count
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            if (Union.empty() || Union.back() != arr1[i])
                Union.push_back(arr1[i]); // Add element from arr1 to Union vector
            i++;
        }
        else
        {
            if (Union.empty() || Union.back() != arr2[j])
                Union.push_back(arr2[j]); // Add element from arr2 to Union vector
            j++;
        }
    }

    // Add remaining elements from arr1 to Union vector
    while (i < n)
    {
        if (Union.empty() || Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }

    // Add remaining elements from arr2 to Union vector
    while (j < m)
    {
        if (Union.empty() || Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }

    return {cnt, Union.size()}; // Return the count of common elements and the size of the Union vector
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {4, 5, 6, 7, 8};

    pair<int, int> result = findSimilarity(arr1, arr2, arr1.size(), arr2.size());
    cout << "Intersection: " << result.first << endl;
    cout << "Union: " << result.second << endl;

    return 0;
}