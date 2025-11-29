import Node

head=None
tail=None
def createNode(value):
	n=Node.Node(value)
	return n
	
def insert(head,node):
	if head==None:
		head=node
		tail=node
	else:
		temp=head
		while(temp.next!=None):
			temp=temp.next
		node.prev=temp	
		temp.next=node
		tail=node
	return head,tail
	
def display(head):
	if(head==None):
		print("Empty List")
		return
	temp=head
	while(temp!=None):
		print(temp.data)
		temp=temp.next
	
	print()
	temp=tail
	while(temp!=None):
		print(temp.data)
		temp=temp.prev
	
	
def palindrome(head,tail):
	h=head	
	t=tail
	s1=""
	while(h!=None):
		s1+=str(h.data)
		h=h.next
	
	s2=""
	while(t!=None):
		s2+=str(t.data)
		t=t.prev
	
	if(s1==s2):
		print("The List is palindrome")
	else:
		print("List is not palindrome")
	
	
	
	
	
l1=createNode(1)
l2=createNode(2)
l3=createNode(3)
l4=createNode(2)
l5=createNode(1)


head,tail=insert(head,l1)
head,tail=insert(head,l2)
head,tail=insert(head,l3)
head,tail=insert(head,l4)
head,tail=insert(head,l5)

display(head)
palindrome(head,tail)

