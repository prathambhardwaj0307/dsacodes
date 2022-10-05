def fun(index,arr,dp):
    if index==0:
        return arr[index]

    if index==-1:
        return 0

    if(dp[index]==-1):

        # if taking the index element then add it and move 2 index back as do not have to add adjacent elements
        take = arr[index]+fun(index-2,arr,dp)

        # if not taking the element at index then just add 0 to it and move one index backs
        nottake = 0+fun(index-1,arr,dp)
        dp[index] = max(take,nottake)
    
    return dp[index]

arr=[1,2,3,1]
n=len(arr)
dp = [-1 for _ in range(n)]
print(fun(n-1,arr,dp))

arr=[2,1,4,9]
n=len(arr)
dp = [-1 for _ in range(n)]
print(fun(n-1,arr,dp))
