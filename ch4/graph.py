# Alex B

from collections import deque

class Node():
  name = None
  children = None

  def __init__(self, name):
    self.name = name

  def addChild(self, name):
    self.children.append(name)

def isRoute(g, s, d):
  print isRoute.__name__, s, d
  # modified BFS, start from s, if reaching d return
  q = deque()
  visited = set()
  # start with s
  q.append(s); visited.add(s)
  while (len(q) > 0):
    n = q.popleft()
    for f in g[n]:
      if f not in visited:
        visited.add(f)
        if f == d:
          return True
        q.append(f)
  return False

def main():
  graph = {1:{2}, 2:{3, 5}, 3:{2}, 4:{6}, 5:{3}, 6:{4}}
  print isRoute(graph, 1, 5)
  print isRoute(graph, 5, 2)
  print isRoute(graph, 1, 6)
  print isRoute(graph, 6, 4)

if __name__ == "__main__":
  main()
