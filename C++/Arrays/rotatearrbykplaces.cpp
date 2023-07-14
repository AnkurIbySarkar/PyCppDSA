#include <iostream>
#include <vector>
using namespace std;
void Rotatetoleft(vector<int> &arr, int n, int k)
{
    // Check if the array is empty
    if (n == 0)
        return;

    // Calculate the effective rotation amount
    k = k % n;

    // Check if no rotation is needed
    if (k == n)
        return;

    // Create a temporary vector to store elements to be rotated
    vector<int> temp(k);

    // Copy the first k elements to the temporary vector
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }

    // Shift the remaining elements to the left by k positions
    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }

    // Copy the elements from the temporary vector back to the array
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - (n - k)];
    }
}
void Rotatetoleft(vector<int> &arr, int n, int k)
{
    // Check if the array is empty
    if (n == 0)
        return;

    // Calculate the effective rotation amount
    k = k % n;

    // Check if no rotation is needed
    if (k == n)
        return;

    // Calculate the number of elements to reverse
    int m = n - k;

    // Reverse the entire array
    reverse(arr.begin(), arr.end());

    // Reverse the first m elements
    reverse(arr.begin(), arr.begin() + m);

    // Reverse the remaining elements
    reverse(arr.begin() + m, arr.end());
}
int main()
{
    // Write your code here
    int n;

    cin >> n;

    vector<int> arr;

    int x;

    for (int i = 0; i < n; i++)
    {

        cin >> x;

        arr.push_back(x);
    }
    int k;

    cin >> k;

    Rotatetoleft(arr, n, k);
    for (int i = 0; i < n; i++)

        cout << arr[i] << " ";
    return 0;
}