def rotatebyk(arr, k, n):
    # Check if the array is empty
    if n == 0:
        return

    # Calculate the effective rotation amount
    k = k % n

    # Check if no rotation is needed
    if k == n:
        return

    temp = arr[:k]  # Create a temporary list to store elements to be rotated

    for i in range(k, n):
        # Shift the remaining elements to the left by k positions
        arr[i - k] = arr[i]

    for i in range(n - k, n):
        # Copy the elements from the temporary list back to the array
        arr[i] = temp[i - (n - k)]


def rotatebyk(arr, k, n):
    # Reverse the entire array
    arr.reverse()

    # Reverse the first portion of the array up to index n - k
    arr[:n - k] = arr[:n - k][::-1]

    # Reverse the remaining portion of the array from index n - k to the end
    arr[n - k:] = arr[n - k:][::-1]


# Get input values
n = int(input("Enter the size of the array: "))
arr = list(int(i) for i in input().split())
k = int(input("Enter the rotation amount: "))

# Call the rotatebyk function
rotatebyk(arr, k, n)

# Print the resulting array
print(*arr)
