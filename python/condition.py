import re
s=input()

#r = re.fullmatch("(^if[\(|\s].+:$|^if[a-zA-Z0-9\_].*[a-zA-Z0-9\_)",s)
#r = re.fullmatch("(^if[\s|\(].*:$|^if[\w]).+[\w]$",s)
#r = re.fullmatch("(^if\s.*:$|^if\(.+\):$|^if\w.+\w$)",s)
r = re.fullmatch("(^if\s.*:$|^if\(.+\):$|^if\w.+\w$|^for\s.+:$|for\w.+\w$|^while\s.+:$|^while\w.+\w$)",s)
if r:
	print("Valid")
else:
	print("Invalid")
	
