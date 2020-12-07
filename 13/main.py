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
  p = re.findall(r'\w+ \w+ bag', l)
  for s in p[1:]:
    if s[:-4] == "no other":
      continue
    d[m[s[:-4]]].append(i)

searched = [False for i in range(len(keys))]

# DFS
def search(i):
  if searched[i]:
    return 0
  searched[i] = True
  ans = 1
  for j in d[i]:
    ans += search(j)
  return ans

print(search(m["shiny gold"]) - 1)