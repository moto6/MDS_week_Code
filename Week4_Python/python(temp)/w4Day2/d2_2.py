mylistsrc = [3,6,9]
print(mylistsrc)
print("mylistsrc id : ", id(mylistsrc))
mylistsrc.extend([200,300])
print(mylistsrc)
print("mylistsrc id : ", id(mylistsrc))
print("same obj!!!! \r\r\r")



mylistsrc = [3,6,9]
print(mylistsrc)
print("mylistsrc : ", id(mylistsrc))
mylistsrc.insert(len(mylistsrc),[200,300])
print(mylistsrc)
print("mylistsrc : ",id(mylistsrc))


#sort list
print("\r\r\rsort lsit")

mylistdata = [4,5,8,2,9]
mylistdata2 = sorted(mylistdata)
print(mylistdata)
print(mylistdata2)



#Join Method application
print("\r\r\rJoin Method")
mylistdata = [ "Time" , "is" , "Gold" ]
res = "".join(mylistdata)
print(res)


#p143
mylist = [1,2,3,4,5]
mylist.insert(0,-77)
print(mylist)


mylist.insert(1,0)
print(mylist)

mylist.insert(-1,100)
print(mylist)

mylist.insert(len(mylist),1000)
print(mylist)