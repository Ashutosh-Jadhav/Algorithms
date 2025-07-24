def sum_of_max_times_length(arr):
    n = len(arr)
    next_greater = [n] * n
    prev_greater = [-1] * n

    # Find next greater for each element
    stack = []
    for i in range(n):
        while stack and arr[stack[-1]] < arr[i]:
            idx = stack.pop()
            next_greater[idx] = i
        stack.append(i)

    # Find previous greater or equal for each element
    stack = []
    for i in range(n - 1, -1, -1):
        while stack and arr[stack[-1]] <= arr[i]:
            idx = stack.pop()
            prev_greater[idx] = i
        stack.append(i)

    total = 0
    for i in range(n):
        left = i - prev_greater[i]
        right = next_greater[i] - i
        count = left * right  # number of subarrays where arr[i] is max
        total += arr[i] * count * (left + right - 1) // 2  # average length over all

    return total
