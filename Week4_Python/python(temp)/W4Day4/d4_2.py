"""
import sys

def func():
	#print("val : ",val)
	num = "progg"
	print(sys.getrefcount(num))
	print("num :",num)
	print(locals())
	return num

num=30
print(type(num))
func()
print("num :",num)
print(locals())

##################################

def sum(mydata):
	sunn=0
	print("in func : ",mydata)
	for x in mydata:
		sunn += x
	return sunn	

total = 0
mylist = [5,6,7,8,9]
total = sum(mylist)
print(mylist)
print(total)

"""


'''
#ppt2 2p
def evenprint(n,step=1):
	x=1
	while x <= n:
		if x%2 == 0:
			print(x)
		x += step
evenprint(10)
'''

######################################
"""
def argsfunc (*args):
	i=0
	for x in args:
		i+=1
	print("num of insu:%d"%i)
	print(args)
	print(args[0])
	print(args[2])
	print(args[1])

def dictsfunc(**dicts):
	i = 0
	for x in dicts.keys():
		i+=1
	print("dicts의 인수 갯수 %d"%i)
	print(dicts)


argsfunc(1,99,[2,4])
dictsfunc(a=1,b=2,c=3)

"""


def mysum_func(mul, *args):
	cnt = 0
	tuple_len = len(args)
	while cnt < tuple_len:
		print("{}".format(mul *args[cnt]))
		cnt += 1

res = mysum_func(5,1,2,3,4,5)