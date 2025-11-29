import Node

class Stack:
    def __init__(self):
        self.top=None

    def push(self,data):
        node=Node.SNode(data)
        node.next=self.top
        self.top=node
        print(f"Stack Top -> {self.top.data}")

    def pop(self):
        n=self.top
        if n==None:
            print("Stack Empty")
            return None
        else:
            self.top=n.next
            value=n.data
            del n
            print(f"Stack Top -> {self.top.data if self.top!=None else "None"}")
            return value
        
    def display(self):
        if(self.top==None):
            print("Stack empty")
        else:
            while(self.top!=None):
                print(self.top.data)
                self.top=self.top.next
        
        
stack = Stack()
stack.push(10)
stack.push(20)
stack.push(30)
stack.push(40)
stack.push(50)

print("\nPOP from stack")
stack.pop()
stack.pop()
stack.pop()
stack.pop()
stack.pop()

print("\nStack :")
stack.display()
