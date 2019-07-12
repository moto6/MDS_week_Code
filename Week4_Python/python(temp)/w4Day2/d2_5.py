def func1(mylist_arg):
	sum_data=0;
	for x in mylist_arg:
		sum_data +=x
	avg=sum_data/len(mylist_arg)
	return sum_data,avg

mylist = [90,71,83,63,85,63,89]
total_avg = func1(mylist)

print(type(total_avg))
print(total_avg)


#tuple print
mylist = [123,567,89]
mytuple = ("127.0.0.1",65578)
print("client{} is connected".format(mytuple))
print("{}from received data".format(mylist))


#tuple add oper.
mytupledata = (1,2,3)
print(mytupledata)
print(id(mytupledata))



#ppt 32p

#add dic 
mydict_test = {}
mydict_test["A"] = 0;
mydict_test["A"] = 1;
mydict_test["A"] = 2;
print(mydict_test)


#add list
mylist = []
##mylist[0] = 5;
##mylist[1] = 7;
print(mylist)


def encrypt(msg):
	for ch in encbook:
		if ch in encbook:
			msg = msg.replace(ch.encbook[ch])
	return msg
	
encbok{'p':'%','y':'(' , 't':'#' , 'h':'=' , 'o':'@' ,'n':'i' }
res_msg = encrypt("I love python Prog")
print(res_msg)





