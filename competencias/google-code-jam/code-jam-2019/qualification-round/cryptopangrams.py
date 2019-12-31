#

#
n = int(input())
is_prime = [1] * (n+1)
is_prime[0] = is_prime[1] = 0

i = 2
while(i<=n):
	if is_prime[i] and i*i <= n:
		j = i * i
		while j <= n:
			is_prime[j] = 0
			j += i
	i += 1


#i = 0
#while(i<n+1):
#	if(is_prime[i]):
#		print(i)
#	i += 1


for i in enumerate(is_prime):
	print(i)

i=0
v = [i*i for i in range(5)]
print(v)