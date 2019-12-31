# ACCEPTED @implementation

#
import math as mt

n = int(input())
v = [int(x) for x in input().split()]

n = mt.ceil(n/2)

cntp = 0
cntn = 0
for x in v:
	if x > 0:
		cntp += 1
	elif x < 0:
		cntn += 1

if cntp < n and cntn < n:
	print(0)
elif cntp >= n:
	print(1)
else:
	print(-1)