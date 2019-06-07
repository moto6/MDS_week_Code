#ppt2 19p

class mylistclass():
	def __init__(self,data):
		self.mylistdata = data
	def show_list(self):
		print(self.mylistdata)

	def __sub__(self,other):
		myset1 = set(self.mylistdata)
		myset2 = set(other.mylistdata)

		myres = myset1 - myset2
		return list(myres)

md1 = [1,2,3,4,5]
md2 = [1,2,4,9,7]

inst1 = mylistclass(md1)
inst2 = mylistclass(md2)

inst1.show_list()
inst2.show_list()

result = inst1-inst2

print(" inst1-inst2 : ",result)

print(result)