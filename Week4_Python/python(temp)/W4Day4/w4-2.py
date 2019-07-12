class Accout():
	
	def __init__(self, money):
		self.balance = money
	
	def deposit(self, money):
		self.balance += money

	def withdraw(self, money)
		self.balance -= money

	def show_Account(self):
		print("balance : {}원".format(self.balance))


class fixed_Accent(Accout):
	def deposit(self, money):
		self.balance += money*1.07

	def withdraw(self, money):
		self.balance -= money+10