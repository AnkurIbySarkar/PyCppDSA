def maxSubarraySum(arr, n):

    # Initialize variables
    maxi = float('-inf')

    # Iterate over array elements
    for i in range(0, n):
        sum = 0

        # Calculate sum of subarrays starting from i
        for j in range(i, n):
            sum += arr[j]
            maxi = max(maxi, sum)

        maxi = max(maxi, 0)  # Consider the sum of an empty subarray as 0

    return maxi


def maxSubarraySum(arr, n):

    # Initialize variables
    # Variable to store the maximum subarray sum encountered so far
    maxi = float('-inf')
    sum = 0  # Variable to keep track of the current sum of subarray elements

    # Iterate over array elements
    for i in range(0, n):
        sum += arr[i]  # Add the current element to the sum
        maxi = max(maxi, sum)  # Update the maximum subarray sum if necessary

        if sum < 0:
            sum = 0  # If the sum becomes negative, reset it to 0
        if maxi < 0:
            maxi = 0  # If the maximum sum becomes negative, reset it to 0

    return maxi  # Return the maximum subarray sum


arr = [-2, 3, -1, 5, 4, -7]
n = len(arr)

maxSum = maxSubarraySum(arr, n)
print("Maximum subarray sum:", maxSum)
