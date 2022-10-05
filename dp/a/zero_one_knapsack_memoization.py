# recursion and dp used here
# either item is stored in bag or not
# here we use a 2d array which is initialised with -1
# size of 2d array is w+1 by n+1 becoz w and n is changing after each call
# we check after the base condition that if value of particualar block is not equal to -1 then return the value of that block

def knapsack(wt,pr,w,n):
    # base condition
    if n==0 or w==0:
        return 0 #return 0 profit

    if dp[n][w]!=-1:
        return dp[n][w]

    else:

        # if capacity of bag is greater than the current weight of item
        if wt[n-1]<=w:
            dp[n][w] = max(pr[n-1]+knapsack(wt,pr,w-wt[n-1],n-1),knapsack(wt,pr,w,n-1))
            return dp[n][w]

        # if weight of item is more than capacity of bag i.e. it can not come in bag
        else:
            dp[n][w] = knapsack(wt,pr,w,n-1)
            return dp[n][w]

n = int(input("Enter number of items: "))
print("Enter the weights of items: ",end = "")
wt = list(map(int,input().split()))
print("Enter the prices of items: ",end = "")
pr = list(map(int,input().split()))
print("Enter the maximum capacity of bag: ",end="")
w = int(input())

# initialising the 2d array
dp = [[-1 for x in range(w+1)] for y in range(n+1)]

ans = knapsack(wt,pr,w,n)
print(ans)