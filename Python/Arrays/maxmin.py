def findLargestElement(arr, n):
    """
    Function to find the largest element in an array.
    Parameters:
        - arr: The input array.
        - n: The size of the array.
    Returns:
        The largest element in the array.
    """
    max_element = arr[0]  # Assume the first element is the maximum
    for i in arr:
        if i > max_element:
            max_element = i
    return max_element


def findSmallestElement(arr, n):
    """
    Function to find the smallest element in an array.
    Parameters:
        - arr: The input array.
        - n: The size of the array.
    Returns:
        The smallest element in the array.
    """
    min_element = arr[0]  # Assume the first element is the minimum
    for i in arr:
        if i < min_element:
            min_element = i
    return min_element


arr1 = [2, 5, 1, 3, 0]
n = len(arr1)  # Get the size of the array
maxi = findLargestElement(arr1, n)
mini = findSmallestElement(arr1, n)
print("The largest element in the array is:", maxi)
print("The smallest element in the array is:", mini)


arr2 = [8, 10, 5, 7, 9]
n = len(arr2)  # Get the size of the array
maxi = findLargestElement(arr2, n)
mini = findSmallestElement(arr2, n)
print("The largest element in the array is:", maxi)
print("The smallest element in the array is:", mini)
