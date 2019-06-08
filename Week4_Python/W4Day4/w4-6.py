'''
f=open('myfile.txt','r+')
f.write("my pythno")
f.close

#
f=open('myfile.txt','r')
myread = f.read()
print(type(myread))
print(myread)
f.close
#

f=open('Testfile1.txt','w')
f.write("""python Programming
	good
	study
	veryvery hit""")
f.close()
#

f=open("Testfile1.txt",'r')
for line in f:
	print(line, end="") #==print(line.strip())
else:
	print('\n')
f.seek(0,0)
print(f.readlines())
f.close()

'''
'''
f = open("")#######
print(f.read())
print(f.tell())
f.seek(0,0)

f.write("ccppccpp")
f.flush()
f.seek(0,0)
'''

##utf-8 encode, decode
mybytes = bytes([236,130,172,235,158,145])
mystr = mybytes.decode("utf-8")
print(mystr)##사랑

mystr = "파이썬 사랑"
mytestbytes = mystr.encode("utf-8")
print("UTF-8 encode:",mytestbytes)
mystr1 = mytestbytes.decode("utf-8")
print("UTF-8 decode:",mystr1)



##
mytext = "python"

f= open("mytext_utf8.txt","wb")
f.write(mytext.encode("utf-8"))
f.close()## 6bytes

f=open("mytext_utf16.txt","wb")
f.write(mytext.encode("utf-16"))
f.close()## 14bytes