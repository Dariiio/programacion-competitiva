# ACCEPTED @implementation

#
def f(x):
	sm = 0
	while(x>0):
		sm += int(x%10)
		x /= 10
	return sm

a = int(input())

while 1:
	if f(a)%4 == 0:
		print(a*2)
		break
	else:
		a += 1