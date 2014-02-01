import random

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
    def append_to_tail(self, d):
        end = Node(d)
        n = self
        while n.next != None:
            n = n.next
        n.next = end

def make_unidirectional_list(l):
    root = Node(random.randint(0, 10))
    for i in range(1, l):
        root.append_to_tail(random.randint(0, 10))
    return root

def debug_list(r):
    n = r
    ar = []
    while n.next != None:
        ar.append(n.data)
        n = n.next
    ar.append(n.data)
    print ar
