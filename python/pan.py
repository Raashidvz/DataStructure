import re

pan = input("Enter PAN Number : ")
x = re.fullmatch("[a-zA-Z]{5}[0-9]{4}[a-zA-Z]{1}", pan)

if x:
	print("Valid")
else:
	print("Invalid")
