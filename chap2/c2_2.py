import sys
from unidirectional_list import make_unidirectional_list, debug_list

def search_k(root, k):
    cur = root
    ar = []
    while cur.next != None:
        ar.append(cur)
        cur = cur.next
    ar.append(cur)
    return ar[len(ar)-k]

k = int(sys.argv[2])
root = make_unidirectional_list(int(sys.argv[1]))
debug_list(root)
node = search_k(root, k)
print "list[-%d] is %d" % (k, node.data)

