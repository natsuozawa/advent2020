import re

lines = []
while True:
  s = input()
  if (s == "-1"):
    break
  lines.append(s)

keys = [s[0:s.find(" bags contain ")] for s in lines] 
m = {k: i for (k, i) in zip(keys, range(len(keys)))}
d = {i: [] for i in range(len(keys))}

for i, l in enumerate(lines):
  q = re.findall(r'\d+', l)
  if len(q) == 0:
    continue
  p = re.findall(r'\w+ \w+ bag', l)[1:]
  d[i] = [(m[s[:-4]], int(k)) for (s, k) in zip(p, q)]

# DFS
def search(i, n):
  ans = 0
  for j, k in d[i]:
    ans += k * n 
    ans += search(j, k * n)
  return ans

print(search(m["shiny gold"], 1))