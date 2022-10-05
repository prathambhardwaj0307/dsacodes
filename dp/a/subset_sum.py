def subset_sum(arr,s,n):
    for i in range(n+1):
        for j in range(s+1):
            if i==0:
                dp[i][j] = False

            elif j==0:
                dp[i][j] = True

            elif arr[i-1]<=j:
                a = dp[i-1][j-arr[i-1]]
                b = dp[i-1][j]
                dp[i][j] = a or b

            elif arr[i-1]>j:
                dp[i][j] = dp[i-1][j]


    return dp[n][s]


arr = list(map(int,input("Enter the numbers: ").split()))
s = int(input("Enter the sum: "))
n = len(arr)
dp = [[False for i in range(s+1)] for j in range(n+1)]

print(subset_sum(arr,s,n))