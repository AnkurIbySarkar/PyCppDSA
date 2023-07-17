#include <iostream>
#include <climits>
#include <vector>
using namespace std;
// recursion
// Recursive function to find the minimum number of jumps
//  Returns -1 if the last index is unreachable
int minimumJumpsRecursive(vector<int> &arr, int n, int pos)
{
    // Base case: If the current position is the last index, no jumps are needed
    if (pos == n - 1)
        return 0;

    // If the current position is unreachable, return -1
    if (arr[pos] == 0)
        return -1;

    int minJumps = INT_MAX;

    // Recursively try all possible jumps from the current position
    for (int i = 1; i <= arr[pos] && pos + i < n; i++)
    {
        int jumps = minimumJumpsRecursive(arr, n, pos + i);
        if (jumps != -1)
            minJumps = min(minJumps, jumps + 1);
    }

    return minJumps == INT_MAX ? -1 : minJumps;
}

// Wrapper function that calls the recursive function
int minimumJumps(vector<int> &arr, int n)
{
    // Call the recursive function with the initial position 0
    int minJumps = minimumJumpsRecursive(arr, n, 0);

    // Return -1 if the minimum jumps is not possible, else return the minimum jumps
    return minJumps == INT_MAX ? -1 : minJumps;
}
// memoization
int helper(vector<int> &arr, int n, int pos, vector<int> &dp)
{
    // Base case: If the current position is the last index, no jumps are needed
    if (pos == n - 1)
        return 0;

    // If the current position is unreachable, return -1
    if (arr[pos] == 0)
        return -1;

    // If the result for the current position is already calculated, return it
    if (dp[pos] != -1)
        return dp[pos];

    int minJumps = INT_MAX;

    // Recursively try all possible jumps from the current position
    for (int i = 1; i <= arr[pos] && pos + i < n; i++)
    {
        int jumps = helper(arr, n, pos + i, dp);
        if (jumps != -1)
            minJumps = min(minJumps, jumps + 1);
    }

    // Store the calculated result in the DP table for future use
    return dp[pos] = (minJumps == INT_MAX) ? -1 : minJumps;
}

// Wrapper function that calls the helper function
int minimumJumps(vector<int> &arr, int n)
{
    // Create a DP table to store intermediate results
    vector<int> dp(n, -1);

    // Call the helper function with the initial position 0 and DP table
    int minJumps = helper(arr, n, 0, dp);

    // Return -1 if the minimum jumps is not possible, else return the minimum jumps
    return (minJumps == INT_MAX) ? -1 : minJumps;
}

// tabulation
int minimumJumps(vector<int> &arr, int n)
{
    // Create a DP table to store the minimum jumps required to reach each index
    vector<int> dp(n, INT_MAX);

    // Initialize the base case: no jumps are needed to reach the first index
    dp[0] = 0;

    // Traverse through each index starting from the second index
    for (int i = 1; i < n; i++)
    {
        // Check all possible previous indices that can jump to the current index
        for (int j = 0; j < i; j++)
        {
            // If the previous index is reachable and its minimum jumps value is valid
            if (j + arr[j] >= i && dp[j] != INT_MAX)
            {
                // Update the minimum jumps required to reach the current index
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    // Return -1 if the last index is unreachable, else return the minimum jumps required to reach it
    return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
}

int minimumJumps(vector<int> &arr, int n)
{
    if (n <= 1)
        return 0;

    int maxReach = arr[0]; // Maximum reachable index from the current position
    int steps = arr[0];    // Steps remaining at the current position
    int jumps = 1;         // Minimum jumps required

    for (int i = 1; i < n; i++)
    {
        if (steps == 0)
            return -1; // Return -1 if the current position is unreachable

        if (i == n - 1)
            return jumps; // Return the minimum jumps required

        maxReach = max(maxReach, i + arr[i]);
        steps--;

        if (steps == 0)
        {
            jumps++;

            if (i >= maxReach)
                return -1; // Return -1 if the current position is unreachable

            steps = maxReach - i;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {0, 1, 2, 3, 4};
    int n = arr.size();
    int result = minimumJumps(arr, n);
    cout << "Result: " << result << endl;
    return 0;
}