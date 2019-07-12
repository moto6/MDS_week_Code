#ppt2 8p
#swap func
a=10
b=20
def swap_func():
	global a,b
	a,b = b,a
print("a : %d, b: %d" %(a,b))
swap_func()
print("a : %d, b: %d" %(a,b))