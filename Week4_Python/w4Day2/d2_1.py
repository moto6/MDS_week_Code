mylist = [3.14, 5, "python", [100,200,300], ["Good","progg"]]
print(mylist[0])
print(mylist[1])
print(mylist[2][0])
print(mylist[3][1])
print(mylist[4][1])
print(mylist[4][0][3])

mystr = "python"
print(id(mystr))

mystr = mystr.capitalize()
print(id(mystr))



mylistsrc = [3,6,9]
mylistadd = mylistsrc + [20]
print(mylistadd)
print("mylistsrc :" ,id(mylistsrc))
print("mylistadd :" ,id(mylistadd))