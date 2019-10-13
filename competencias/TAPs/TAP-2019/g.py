#ACCEPTED @greedy

#https://codeforces.com/group/YjFmW2O15Q/contest/102363
n = int(input())
v = [int(x) for x in input().split()]

a = v[0];v.pop(0)

v.sort()

while(len(v)>0 and a>0):
	if v[0] == 1:
		v.pop(0)
		a -= len(v)
	else:
		a -= (len(v)*v[0])-1
		v.pop(0)
		
if a <= 0:
	print("NO")
else:
	print("SI")