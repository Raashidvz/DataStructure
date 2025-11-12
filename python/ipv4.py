import re

ip = "0.0.0.0"

octets=ip.split(".")
print(octets)

octet1='254'

x=re.fullmatch("([0-9]|[0-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])",octet1)
if x:
	print("Valid")
else:
	print("Invalid")
