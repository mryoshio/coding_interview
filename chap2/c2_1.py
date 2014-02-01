import sys
from unidirectional_list import make_unidirectional_list, debug_list

def del_dup(r):
    prev = cur = r
    h = { prev.data : True }
    while cur.next != None:
        cur = cur.next
        if cur.data in h.keys():
            prev.next = None
        else:
            h[cur.data] = True
            prev.next = cur
            prev = cur
    return r

root = make_unidirectional_list(int(sys.argv[1]))
debug_list(root)
root = del_dup(root)
debug_list(root)
