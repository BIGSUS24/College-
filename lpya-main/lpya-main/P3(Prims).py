INF = 999999

N = 5

G = [
        [0, 19, 5, 0, 0],
        [19, 0, 5, 9, 2],       
        [5, 5, 0, 1, 6],
        [0, 9, 1, 0, 1],
        [0, 2, 6, 1, 0]
]


selected_node = [False]*N
selected_node[0] = True
no_edge = 0

print("Edge : Weight\n")

while(no_edge < N-1):
    minimum = INF
    a = 0
    b = 0

    for i in range(N):
        if(selected_node[i]):
            for j in range(N):
                if((not selected_node[j])and(G[i][j] != 0)):
                    if(minimum > G[i][j]):
                        minimum = G[i][j]
                        a = i
                        b = j
                        
    print(f'{a} => {b} : {G[a][b]}')
    no_edge += 1
    selected_node[b] = True

