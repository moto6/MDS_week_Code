#num = input("insert INTEGEAR")
#print(num)
#print(type(num))
#num = int(num)
#print(type(num))



myscorelist = [ ["math"], ["English"] ]
print(myscorelist)



print("intsert %s socre!", myscorelist[0])
num = int(input(myscorelist[0]))
myscorelist[0].append(num)
print(myscorelist[0])


print("intsert %s socre!", myscorelist[1])
num = int(input(myscorelist[1]))
myscorelist[1].append(num)
print(myscorelist[1])

myscorelist.append(["korean"])


print("intsert %s socre!", myscorelist[2])
num = int(input(myscorelist[2]))
myscorelist[2].append(num)
print(myscorelist[2])

print("intsert %s socre!", myscorelist[3])
num = int(input(myscorelist[3]))
myscorelist[3].append(num)
print(myscorelist[3])



####
####
sum_data = 0

for data in myscorelist:
	sum_data += data[1]

print(sum_data)
avg = sum_data/3
print("avg : {0:0.4f}".format(avg))
