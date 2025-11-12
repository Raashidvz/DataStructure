import re

num = input("Enter number : ")
x = re.fullmatch("[1-9]{1}[0-9]{9}",num)

if x:
	print("Valid")
else:
	print("Invalid")
