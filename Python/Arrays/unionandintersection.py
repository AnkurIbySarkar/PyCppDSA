def findSimilarity(arr1, arr2, n, m):
    common = 0  # Counter for common elements

    # Iterate over elements in arr1
    for i in arr1:
        if i in arr2:  # If the element is found in arr2
            common += 1  # Increment the common counter

    st = set()  # Set to store unique elements

    # Add elements from arr1 to the set
    for i in arr1:
        st.add(i)

    # Add elements from arr2 to the set
    for i in arr2:
        st.add(i)

    return [common, len(st)]  # Return the common count and length of the set


def findSimilarity(arr1, arr2, n, m):
    arr1.sort()  # Sort arr1 in ascending order
    arr2.sort()  # Sort arr2 in ascending order

    i = 0  # Pointer for arr1
    j = 0  # Pointer for arr2

    st = set()  # Set to store unique elements
    common = 0  # Counter for common elements

    # Iterate over arr1 and arr2 using two pointers
    while i < n and j < m:
        if arr1[i] == arr2[j]:  # If elements at the current pointers are the same
            common += 1  # Increment common counter
            st.add(arr1[i])  # Add the common element to the set
            i += 1  # Move the pointer for arr1 forward
            j += 1  # Move the pointer for arr2 forward
        elif arr1[i] < arr2[j]:  # If element in arr1 is smaller
            st.add(arr1[i])  # Add the element to the set
            i += 1  # Move the pointer for arr1 forward
        else:  # If element in arr2 is smaller
            st.add(arr2[j])  # Add the element to the set
            j += 1  # Move the pointer for arr2 forward

    # Handle remaining elements in arr1
    while i < n:
        st.add(arr1[i])
        i += 1

    # Handle remaining elements in arr2
    while j < m:
        st.add(arr2[j])
        j += 1

    return [common, len(st)]  # Return the common count and length of the set


arr1 = [1, 2, 3, 4, 5]
arr2 = [4, 5, 6, 7, 8]

result = findSimilarity(arr1, arr2, len(arr1), len(arr2))
print(result)
