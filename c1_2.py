import sys

def rev(s):
    if s == None: return ""
    i = 1 ; ret = []
    while i <= len(s):
        ret.append(s[len(s)-i])
        i += 1
    return "".join(ret)

for i in range(1, len(sys.argv)):
    print rev(sys.argv[i])
