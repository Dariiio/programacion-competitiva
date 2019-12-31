# @dfs and similar

#
n = 0
g = []
def val(a,b):
	if a<0 or b<0 or a>=n or b>=n:
		return False
	else:
		return True

dx = [-1,0,1,0];dy = [0,1,0,-1];vst = []
def dfs(a,b):
	vst[a][b] = 1
	for i in range(4):
		ua, ub = a + dx[i], b + dy[i]
		if val(ua,ub) and vst[ua][ub] == 0 and g[ua][ub] == '1' :
			dfs(ua,ub)
	print(a + b)

n = int(input())
x1, y1 = [int(x) for x in input().split()]
x2, y2 = [int(x) for x in input().split()]
x1 -= 1;y1 -= 1;x2 -= 1;y2 -= 1

for i in range(n):
	g.append(input())

vst = [[0 for i in range(n)] for j in range(n)]

dfs(0,0)

