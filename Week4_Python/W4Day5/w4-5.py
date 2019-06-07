#ppt2-21~22p 시험 ★★
class mylistclass(list):
	def __init__(self, name):
		self.name = name

	def __add__(self,other):
		mysumlist = []
		mysumlist.extend(self)
		mysumlist.extend(other)
		return mysumlist


	def __sub__(self,other):
		myset1 = set(self)
		myset2 = set(other)
		myres = myset1 - myset2
		return list(myres)

myinst1 = mylistclass("myinst1 data :")
for x in range(1,8):
	myinst1.append(x)
print(myinst1.name, myinst1)

myinst2 = mylistclass("myinst2 data :")
for x in range(3,10):
	myinst2.append(x)
print(myinst2.name, myinst2)

sum_result = myinst1 + myinst2
print("myinst1 + myinst2 :", sum_result)

sub_result = myinst1 - myinst2
print("myinst1 - myinst2 :", sub_result)
