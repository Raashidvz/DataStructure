import re

n = int(input("Enter count : "))
names = [ input() for _ in range(n)]

#s = "\n".join(names)
#print (s)
print()
for x in names:
	k=re.fullmatch("^a.*a$",x,re.IGNORECASE)
	if(k):
		print(x)
