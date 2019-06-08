import copy
mylist1 = [1,2,3,4,5]
mylist2 = copy.copy(mylist1)
print("mylist1 : ",id(mylist1) )
print("mylist2 : ",id(mylist2) )

print("\n\n")
mylist1 = [1,2,3,4,5]
mylist2 = copy.deepcopy(mylist1)
print("mylist1 : ",id(mylist1) )
print("mylist2 : ",id(mylist2) )


print("\n\n")
my_temper = ['temperature',[11,13,15,10]]
my_0405_temper = copy.copy(my_temper)
print("First my_temper : ",my_temper)
print("First 0405_temp : ",my_0405_temper)
my_temper[1].insert(0,9);del my_temper[1][-1]

print("donot my_temper : ",my_temper)
print("after 0405_temp : ",my_0405_temper)



#ppt27p

#list sort method
mylistdata = [4,5,8,2,9]
mylistdata.sort()
print(mylistdata)
mylistdata.reverse()
print(mylistdata)

#list sort func
mylistdata = [4,5,8,2,9]
mylistdata2 = sorted(mylistdata)
print(mylistdata)
print(mylistdata2)

#join
mylistdata = ["Time","is","Gold"]
res= "".join(mylistdata)
print(res)


#ppt 28p

myscorelist = [ ["math",89], ["English"] ]
print(myscorelist)
myscorelist[1].append(95)
print(myscorelist)

myscorelist.append(["korean"])
print(myscorelist)
myscorelist[2].append(79)
print(myscorelist)

####
####
sum_data = 0

for data in myscorelist:
	sum_data += data[1]

print(sum_data)
avg = sum_data/3
print("avg : {0:0.4f}".format(avg))
