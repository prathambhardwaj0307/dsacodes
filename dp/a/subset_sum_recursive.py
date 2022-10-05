# def subset_sum(arr,s,n):
#     if s==0:
#         return True

#     if n==0:
#         return False

#     if arr[n-1]<=s:
#         a = subset_sum(arr,s-arr[n-1],n-1)
#         b = subset_sum(arr,s,n-1)
#         return subset_sum(arr,s-arr[n-1],n-1) or subset_sum(arr,s,n-1)

#     else:
#         return subset_sum(arr,s,n-1)


# arr = list(map(int,input("Enter the elements: ").split()))
# s = int(input("Enter the sum: "))
# n = len(arr)
# print(subset_sum(arr,s,n))

n = 298111
s = str(n)

while(len(s)!=1):
    temp = 0
    for i in s:
        temp+=int(i)

    s = str(temp)

print(s)