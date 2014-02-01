import sys

def compress(s1):
    prev = s1[0]
    ar = []
    cnt = 0
    for s in s1:
        if prev == s:
            cnt += 1
        else:
            ar.append(prev)
            ar.append(str(cnt))
            cnt = 1
            prev = s
            
    ar.append(prev)
    ar.append(str(cnt))
    ret_cand = ''.join(ar)
    if len(ret_cand) > len(s1):
        return s1
    else:
        return ret_cand
    
print sys.argv[1]
print compress(sys.argv[1])
