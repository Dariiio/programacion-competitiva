# ACCEPTED @math

# https://codeforces.com/contest/1196/problem/A

q = int(input())

for x in range(q):
	a,b,c = [int(x) for x in input().split()]
	print((a+b+c)//2)
