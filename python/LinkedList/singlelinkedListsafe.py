import Node

head=None
def createNode(value):
	n=Node.Node(value)
	return n
	
def insert(head,node):
	if head==None:
		head=node
	else:
		temp=head
		while(temp.next!=None):
			temp=temp.next
		temp.next=node
	return head
def display(head):
	if(head==None):
		print("Empty List")
		return
	temp=head
	while(temp!=None):
		print(temp.data)
		temp=temp.next
	
def palindrome(head):
		
	
	
	
	
	
l1=createNode(1)
l2=createNode(2)
l3=createNode(3)
l4=createNode(2)
l5=createNode(1)


head=insert(head,l1)
head=insert(head,l2)
head=insert(head,l3)
head=insert(head,l4)
head=insert(head,l5)

display(head)

#l1=Node.Node(1)
#l1=Node.Node(2)
#l1=Node.Node(3)
#l1=Node.Node(2)
#l1=Node.Node(1)


