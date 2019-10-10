# ACCEPTED @brute force@implementation

#https://codeforces.com/contest/1228/problem/A

l, r = [int(x) for x in input().split()]

def f(x):
	used = [0]*15
	while(x>1):
		d = int(x%10)
		if used[d] == 0:
			used[d] = 1
		else:
			return False
		x = x/10
	return True

x = l
ans = -1
while( x<= r):
	if f(x):
		ans = x
		break
	x += 1

print(ans)
