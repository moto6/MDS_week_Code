class OverloadingTest:
	def __init__(self, tm):
		self.num = tm

	def show_data(self):
		print("self.num :",self.num)

	def __add__(self,de):
		self.num += de

	def __radd__(self,de):
		self.num += de

	def __sub__(self,de):
		self.num -= de

	def __rsub__(self,de):
		self.num -= de


mycls = OverloadingTest(50)
mycls.show_data()

mycls + 30
mycls.show_data()
# 30+mycls의 경우 Cpp에서는 Friends 
# python 에서는 'r' 을 더붙인다 
mycls - 90
mycls.show_data()


30 + mycls # radd
mycls.show_data()


30 - mycls # rsub
mycls.show_data()