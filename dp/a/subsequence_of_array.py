def subsequence(arr,temp,index):
    if index==len(arr):
        ans.append(temp)
        return

    # take
    subsequence(arr,temp+[arr[index]],index+1)
    
    # not take
    subsequence(arr,temp,index+1)

arr = [3,1,2]
temp,ans = [],[]
subsequence(arr,temp,0)
print(ans)