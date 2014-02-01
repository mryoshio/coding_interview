
def dup(arg):
    ar = []
    for c in arg:
        if c in ar: return True
        ar.append(c)
    return False

arg = "shibata"
print dup(arg)

arg = "shimura"
print dup(arg)
