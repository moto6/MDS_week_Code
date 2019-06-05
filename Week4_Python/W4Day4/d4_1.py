"""
while True:
	minput = input("반지름 입력 :")
	if minput == "end":
			break
	else:
		myradious = float(minput)
	print("myradious : ",myradious)
	circle_area = myradious*myradious*3.14
	circle_len = 2*3.14*myradious
	print("area : ",circle_area)
	print("len : ",circle_len)
"""


listsr = []
listsr[0] = 'A'
mystrdata = '#S45CD!k2D23@@'
mylistdata = []
for ch in mystrdata:
	if ch >= 'a' and ch <= 'z':
		mylistdata.append(ch)
	elif ch >= 'A' and ch <= 'Z':
		mylistdata.append(ch)

print(mylistdata)
mystr_cov = "".join(mylistdata)
print(mystr_cov)