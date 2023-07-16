from typing import List


def minimizeIt(A: List[int], K: int) -> int:
    n = len(A)
    A.sort()

    mini = A[0]
    maxi = A[n - 1]
    ans = A[n - 1] - A[0]

    for i in range(1, n):
        if A[i] - K < 0:
            continue

        maxi = max(A[i - 1] + K, A[n - 1] - K)
        mini = min(A[0] + K, A[i] - K)

        ans = min(ans, maxi - mini)

    return ans


print(minimizeIt([10, 7, 3, 6, 4, 8, 1], 2))
