# sorting O(nlogn)
def sort012(arr):
    # Sort the array using built-in sorted function (O(nlogn))
    arr1 = sorted(arr)
    return arr1

# counting


def sort012(arr):
    cnt0, cnt1, cnt2 = 0, 0, 0
    for i in arr:  # Count the occurrences of 0, 1, and 2
        if i == 0:
            cnt0 += 1
        elif i == 1:
            cnt1 += 1
        else:
            cnt2 += 1
    for i in range(cnt0):  # Fill the array with 0s, followed by 1s, and then 2s
        arr[i] = 0
    for i in range(cnt0, cnt0 + cnt1):
        arr[i] = 1
    for i in range(cnt0 + cnt1, cnt0 + cnt1 + cnt2):
        arr[i] = 2

# dutch flag algorithm


def sort012(arr):
    low = 0
    mid = 0
    high = len(arr) - 1
    while mid <= high:
        if arr[mid] == 0:  # If the current element is 0, swap it with the element at the 'low' index
            arr[low], arr[mid] = arr[mid], arr[low]
            low += 1
            mid += 1
        elif arr[mid] == 1:  # If the current element is 1, move to the next element
            mid += 1
        else:  # If the current element is 2, swap it with the element at the 'high' index
            arr[mid], arr[high] = arr[high], arr[mid]
            high -= 1


# Test the function
arr = [0, 2, 1, 2, 0, 1]
sort012(arr)
print(arr)
