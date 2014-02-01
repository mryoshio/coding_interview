
def dup(s)
  i = 0 ; ar = []
  while i < s.size do
    return true if ar.include?(s[i])
    ar.push s[i]
    i += 1
  end
  return false
end

arg = "shibata"
puts dup(arg)

arg = "shimura"
puts dup(arg)
