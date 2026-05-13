import heapq

def dijkstras(graph,start):
    distances = {node:float("inf") for node in graph}
    distances[start] = 0

    pq = [(0,start)]

    while pq:
        current_distance, current_node = heapq.heappop(pq)
        for neighbour,weight in graph[current_node].items():
            distance = current_distance + weight
            if(distance < distances[neighbour]):
                distances[neighbour] = distance
                heapq.heappush(pq,(distance,neighbour))

    return distances

graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

print(dijkstras(graph, 'A'))