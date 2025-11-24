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
	
	
#def palindrome(head):
		
	
	
	
	
	
l1=createNode(1)
l2=createNode(2)
l3=createNode(3)
l4=createNode(4)
l5=createNode(5)


head,tail=insert(head,l1)
head,tail=insert(head,l2)
head,tail=insert(head,l3)
head,tail=insert(head,l4)
head,tail=insert(head,l5)

display(head)

#l1=Node.Node(1)
#l1=Node.Node(2)
#l1=Node.Node(3)
#l1=Node.Node(2)
#l1=Node.Node(1)


