from collections import deque

def dfs(vertex,graph,visited):
    visited.add(vertex)
    print("Visited : ",vertex)

    for neighbour in graph[vertex]:
        if neighbour not in visited:
            dfs(neighbour,graph,visited)

def bfs(start,graph):
    visited = set()
    queue = deque([start])
    visited.add(start)

    while queue:
        vertex = queue.popleft()
        print("Visited : ",vertex)

        for neighbour in graph[vertex]:
            if neighbour not in visited:
                queue.append(neighbour)
                visited.add(neighbour)

# Graph (Adjacency List)
graph = {
    0: [1, 2],
    1: [0, 3],
    2: [0, 3],
    3: [1, 2]
}

print("DFS Traversal : \n")
dfs(0,graph,set())

print("BFS Traversal : \n")
bfs(0,graph)