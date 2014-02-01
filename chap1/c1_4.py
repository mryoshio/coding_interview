import sys

def replace(s1):
    ar = []
    prev_is_empty = False
    for s in s1:
        if s == " ":
            prev_is_empty = True
        else:
            if prev_is_empty:
                ar.append("%20")
                prev_is_empty = False
            ar.append(s)
    if prev_is_empty:
        ar.append("%20")
    return "".join(ar)

print sys.argv[1]
print replace(sys.argv[1])
