#200P
A={1,2,3,4,5}
B={4,5,6,7,8,9}
print(A|B)
print(A&B)
print(A-B)
print(B-A)
print(A^B)


#203p
my_card = {1,99,37,7,8,823,123,34,73,29}
print(my_card)
print(sorted(my_card))
#print(my_card)
card_list = list(my_card)
card_list.sort()
print(card_list)




#PPT 34P
mystr1 = "python is simple"
mystr2 = "apple is delicious"
mystr3 = "programming"

myset1 = set(mystr1)
myset2 = set(mystr2)
myset3 = set(mystr3)
myset_res = myset1 & myset2 & myset3
print(myset_res)