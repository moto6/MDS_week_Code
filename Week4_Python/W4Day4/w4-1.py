print("hello")

"""
#ppt2 - 10p
var=3#전역변수
class myclassTest():
	var = 78
	def __init__(self,data): #self는 자기자신, 생성자 매소드임을 표시
		var = 20 #지역변수 생성됬다가 바로 사라짐
		self.mbr = data#인스턴스 변수, 객체와 함께 존재함
	def show_data(self):
		print("self.var:",self.var)



myinst1 = myclassTest(30)
print(myinst1.mbr)
#print(myclassTest.mbr)

print(dir(myclassTest))
print("\n\n\n")
#myinst1.show_data()
print(dir(myinst1))
"""


'''
#ppt2-11p
class Test2():
	var = 78
	def __init__(self, data):
		self.var = data
		print("_init_ self.var :", self.var)
	def method1(self):
		print("method1 Test2.var : ", Test2.var)
		print("method1 self.var : ", self.var)
	@classmethod
	def chage_data(cls,de):
		cls.var = de
'''


'''
calss Test2():
	var = 777
	def method1(self)
		print(var)

	def mks(cls)

inst = Test2()
inst.method1()
'''

'''
#ppt2 12page
#ppt2 - 12
class HouseClass():
	Company = "python Aca"
	def __init__ (self,year,addr,price):#초기화메서드
		self.year = year
		self.addr = addr
		self.price = price

	def show_company(self):
		print(self.Company)

	def Change_company(self,name):
		self.Company = name

	def show_info(self):
		print("""This house was built by {} in {}, address : {}, price : {} """
			.format(HouseClass.Company, self.year, self.addr, self.price))

houseA = HouseClass(2019, "Guro", 34.56)
houseA.show_company()
houseA.Change_company("MDS Academy")
houseA.show_company()
houseA.show_info()
houseB = HouseClass(2020, "pangyo", 999.99)
HouseClass.Company = "Hancommds"
houseB.show_info()
'''

'''
#ppt2 - 13p
class HouseClass():
	Company = "python Factory"
	def __init__ (self,year,addr,price):#초기화메서드
		self.year = year
		self.addr = addr
		self.price = price

	@classmethod
	def show_company(cls):
		print(cls.Company)

	@classmethod
	def Change_company(cls):
		cls.Company = name

	def show_info(self):
		print("""This house was built by {} in {}, address : {}, price : {} """
			.format(HouseClass.Company, self.year, self.addr, self.price))
		
houseA = HouseClass(2019, "Guro", 34.56)
houseA.show_company()
houseA.Change_company("MDS Academy")
houseA.show_company()
houseA.show_info()


houseB = HouseClass(2020, "pangyo", 999.99)
HouseClass.Company = "Hancommds"
houseB.show_info()
'''

#ppt2-14p
class Calculator():
	def __init__(self,mylistdata):
		self.mylist = mylistdata

	def sum(self):
		self.total = 0
		for x in self.mylist:
			self.total += x
		return self.total
	
	def avg(self):
		list_len = len(self.mylist)
		self.avg = self.total/list_len
		return self.avg

cal1 = Calculator([1,2,3,4,5])
print(cal1.sum())
print(cal1.avg())


cal2 = Calculator([6,7,8,9,10])
print(cal2.sum())
print(cal2.avg())



