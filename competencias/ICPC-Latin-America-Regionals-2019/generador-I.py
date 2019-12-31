
f =  open("caso.txt","w")
f.write("1001 1000 \n")
print(1001, 1000)

for i in range(1,1001):
	#print(1000,end=" ")
	f.write("1000 ")
	for j in range(1000):
		#print(i+1,end=" ")
		a = i+1
		f.write(str(a) + " ")
	#print()
	f.write("\n")

