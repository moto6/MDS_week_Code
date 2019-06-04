#capitalize method 
mystr = 'python'
print(mystr.capitalize())


#center
menu_start = "menu title"
print(menu_start.center(30,'#'))


#count() 
mystr = """Time it like Gold.
Time is Like an arrow
study Time is import."""
print(mystr.count("Time"))


#join()
mylist = ["Beautiful!", "Explicit!", "Simple!", "Complex!"]
mystrjoin = '/'.join(mylist)
print(mystrjoin)

#splict()
mysplitlist = mystrjoin.split('/')
print("split!!")
print(mysplitlist)
print("========")


#replace
msg = "time is gold"
print(msg)
msg = msg.replace("gold", "arrow")
print(msg)
msg = msg.replace('i', '%')
print(msg)


#[n:] and [:n] 
pin_number = "990415-1234112"
yymmdd = pin_number[:6]
print(yymmdd)
number_id = pin_number[7:]
print(number_id)

if pin_number[7] == '1':
	print("MAN")
else:
	print("WON")

