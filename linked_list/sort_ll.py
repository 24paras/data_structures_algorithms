# sort a linked list using merge sort method

class Node:
  def __init__(self, data):
    self.data = data
    self.next = None

class LinkedList:
  def __init__(self):
    self.head = None

  def printList(self):
    temp = self.head
    while (temp):
      print (temp.data)
      temp = temp.next

  def midNode(self):
    temp = self.head
    slow, fast =  temp, temp
    while (fast != None and fast.next != None):
       slow = slow.next
       fast = fast.next.next
    return slow 

if __name__ =='__main__':
  
  llist = LinkedList()
  llist.head = Node(1)
  second = Node(2)
  third = Node(3)
  llist.head.next = second
  second.next = third
  #llist.printList()
  #print(llist.midNode().data)
  
