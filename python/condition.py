import re
s=input()

#r = re.fullmatch("(^if\s.*:$|^if\(.+\):$|^if\w.+\w$)",s)
#r = re.fullmatch("(^if\s.*:$|^if\(.+\):$|^if\w.+\w$|^for\s.+:$|for\w.+\w$|^while\s.+:$|^while\w.+\w$)",s)
r = re.fullmatch("(^if\s.*:$|^if\(.+\):$|^if[^\s\(].+[^:]$)",s)


if r:
	print("Valid")
else:
	print("Invalid")
	
