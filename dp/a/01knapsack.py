def fun(t,time,points,n):
    if n==0 or t==0:
        return 0
    if (time[n-1]>t):
        return fun(t,time,points,n-1)
    else:
        return max(points[n-1]+fun(t-time[n-1], time, points, n-1),fun(t,time,points,n-1))

n=int(input())
t = int(input())
points = list(map(int,input().split()))
time = list(map(int,input().split()))
n = len(time)
print(fun(t,time,points, n))