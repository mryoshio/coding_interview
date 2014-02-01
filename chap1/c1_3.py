import sys

def is_random_sorted(s1, s2):
    if sorted(list(s1)) == sorted(list(s2)):
        return True
    else:
        return False

def is_random_sorted2(s1, s2):
    h = {}
    for s in s1:
        if s in h.keys():
            h[s] += 1
        else:
            h[s] = 1
    for s in s2:
        if s in h.keys():
            h[s] -= 1
        else:
            return False
    for v in h.values():
        if v != 0: return False
    return True
            

print "pattern A", is_random_sorted(sys.argv[1], sys.argv[2])
print "pattern B", is_random_sorted2(sys.argv[1], sys.argv[2])
