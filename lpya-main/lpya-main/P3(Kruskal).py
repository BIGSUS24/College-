class Graph:
    def __init__(self,vertices):
        self.v = vertices
        self.graph = []

    def add_edge(self,u,v,w):
        self.graph.append([u,v,w])

    def find(self,parent,i):
        if(parent[i] == i):
            return i
        return self.find(parent,parent[i])

    def union(self,parent,rank,x,y):
        xroot = self.find(parent,x)
        yroot = self.find(parent,y)

        if(rank[xroot] > rank[yroot]):
            parent[yroot] = xroot
        elif(rank[yroot] > rank[xroot]):
            parent[xroot] = yroot
        else:
            parent[yroot] = xroot
            rank[xroot] += 1

    def kruskal(self):
        index = 0
        edge_count = 0
        result = []
        rank = []
        parent = []

        self.graph = sorted(self.graph ,key= lambda item:item[2])

        for node in range(self.v):
            parent.append(node)
            rank.append(0)

        while(edge_count < self.v - 1):
            u,v,w = self.graph[index]
            index += 1 
            x = self.find(parent,u)
            y = self.find(parent,v)

            if(x != y):
                result.append([u,v,w])
                edge_count += 1
                self.union(parent,rank,x,y)

        print("Edges in MST")
        for u,v,w in result:
            print(f'{u}=>{v} : {w}')

g = Graph(4)
g.add_edge(0, 1, 10)
g.add_edge(0, 2, 6)
g.add_edge(0, 3, 5)
g.add_edge(1, 3, 15)
g.add_edge(2, 3, 4)

g.kruskal()