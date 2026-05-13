import heapq

N = 3

# Goal state
goal = [[1,2,3],
        [4,5,6],
        [7,8,0]]


def calculate_heuristic(mat):
    count = 0
    for i in range(N):
        for j in range(N):
            if(mat[i][j] != 0 and mat[i][j] != goal[i][j]):
                count += 1

    return count

def is_goal(mat):
    return mat == goal

def solve_astar(start,x,y):
    visited = set()
    pq = []
    h = calculate_heuristic(start)
    heapq.heappush(pq,(h,0,start,x,y))
    row = [1,0,-1,0]
    col = [0,1,0,-1]

    while pq:
        f,cost,mat,x,y = heapq.heappop(pq)

        mat_tuple = tuple(tuple(row) for row in mat)

        if mat_tuple in visited:
            continue
            
        visited.add(mat_tuple)

        if is_goal(mat):
            print(f'Goal state reached sucessfully with cost : {cost}')
            return
        
        for i in range(4):
            newX = x + row[i]
            newY = y + col[i]

            if ((0 <= newX < N)and(0 <= newY < N)):
                new_mat = [r[:] for r in mat]
                new_mat[x][y],new_mat[newX][newY] = new_mat[newX][newY],new_mat[x][y]

                new_tuple = tuple(tuple(r) for r in new_mat)

                if new_tuple not in visited:
                    h = calculate_heuristic(new_mat)
                    g = cost + 1
                    heapq.heappush(pq,(g+h,g,new_mat,newX,newY))

    print("Solution not found !")

start = [[1, 2, 3],
         [5, 6, 0],
         [7, 8, 4]]

x, y = 1, 2  # blank position

solve_astar(start, x, y)