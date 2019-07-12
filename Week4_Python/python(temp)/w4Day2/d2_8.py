#ppt 35p

a=50;b=70
Max_val = a if a>b else b
print(Max_val)

mylsittest = [x for x in range(1,10)]
print(mylsittest)

mylist = ["짝" if x%2 == 0 else "홀" for x in range (1,10)]
print(mylist)

#244p 10q
templist = ["A" if x%3 == 1 else "C" if x%3 == 0 else "B" for x in range(1,20)]
print(templist)


#231p
for x in range (1,10):
	print()
	for y in range (1,10):
		print("%d*%d=%d\t" %(x, y, x*y), end='')
		
