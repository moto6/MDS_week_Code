def check():
	for x in range(-30, 260):
		for y in range(x,x+1):
			if id(x) == id(y):
				print("%d는 미리 생성된 객체" %x)
			else:
				print("%d는 새로운 객체" %x)
check()