# import re
# s=input()

#r = re.fullmatch("(^if\s.*:$|^if\(.+\):$|^if\w.+\w$)",s)
#r = re.fullmatch("(^if\s.*:$|^if\(.+\):$|^if\w.+\w$|^for\s.+:$|for\w.+\w$|^while\s.+:$|^while\w.+\w$)",s)
# r = re.fullmatch("(^if\s.*:$|^if\(.+\):$|^if[^\s\(].+[^:]$)",s)


# if r:
# 	print("Valid")
# else:
# 	print("Invalid")


import re
s = input()

pattern = r"""
(
    ^if\s+.+:$ |   		# if a>b:
    ^if\(.+\):$ |     	# if(a<b):
    ^if[^\s\(].+[^:]$ |	# ifont=apple
    
    ^for\s+.+:$ |   		# for x in fruits:
    ^for\(.+\):$ |  		# for(x in fruits):
    ^for[^\s\(].+[^:]$ |  # foreign=10 

    ^while\s+.+:$ |   	# while True:
    ^while\(.+\):$ | 		# while(True):  
    ^while[^\s\(].+[^:]$  # whiles=5    
)
"""

r = re.fullmatch(pattern, s, re.VERBOSE) # You can use spaces freely. Without VERBOSE, spaces matter.

if r:
    print("Valid")
else:
    print("Invalid")

