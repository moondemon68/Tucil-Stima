import os
import heapq
from copy import deepcopy
import time

puzzle = []
# puzzle awal
pq = []     
# priority queue yang isinya tuple <cost, distanceFromRoot, node, moves, puzzle>. 
visited = []
# berisi state puzzle yang sudah pernah dikunjungi
nodeNumber = 2  
# nomor node yang akan diambil anak baru
di = [-1, 0, 1, 0]
# list movement up/down
dj = [0, 1, 0, -1]
# list movement left/right
move = ['u', 'r', 'd', 'l']
# list movement

# Solve puzzle yang sudah dijamin ada solusinya.
# Param: puzzle
# Return: langkah untuk mencapai solusi
def solve(puzzle):
    heapq.heappush(pq, (countCostG(puzzle), 0, 1, '', puzzle))
    if (isSolution(puzzle)):
        return ''
    while pq:
        currentState = heapq.heappop(pq)
        moves = currentState[3]
        currentPuzzle = currentState[4]
        visited.append(deepcopy(currentPuzzle))
        if (isSolution(currentPuzzle)):
            return moves
        childStates = generateChild(currentState)
        for child in childStates:
            heapq.heappush(pq, deepcopy(child))

# Cari lokasi angka 16
# Param: puzzle
# Return: koordinat i, j
def find16(puzzle):
    findi = 0
    findj = 0
    for i in range(4):
        for j in range(4):
            if (puzzle[i][j] == 16):
                findi = i
                findj = j
    return findi, findj

# Generate semua anak dari state sekarang.
# Param: state sekarang
# Return: list berisi state yang puzzlenya belum pernah dikunjungi
def generateChild(currentState):
    global nodeNumber
    childStates = []
    distanceFromRoot = currentState[1] + 1
    moves = currentState[3]
    puzzle = currentState[4]

    findi, findj = find16(puzzle)
    
    # Gerak ke 4 arah bila memungkinkan
    for i in range(4):
        newi = findi + di[i]
        newj = findj + dj[i]
        if (newi >= 0 and newi <= 3 and newj >= 0 and newj <= 3):
            puzzle[findi][findj], puzzle[newi][newj] = puzzle[newi][newj], puzzle[findi][findj]
            if (puzzle not in visited):
                cost = countCostG(puzzle) + distanceFromRoot
                childStates.append((cost, distanceFromRoot, nodeNumber, moves + move[i], deepcopy(puzzle)))
                nodeNumber += 1
            puzzle[findi][findj], puzzle[newi][newj] = puzzle[newi][newj], puzzle[findi][findj]
    
    return childStates

# Menghitung inversi dari suatu puzzle
# Mengoutputkan hasil dari fungsi KURANG setiap i
# Param: puzzle
# Return: jumalh inversi dari suatu puzzle
def countInversions(puzzle):
    total = 0
    kurang = [0 for x in range(16)]
    for i in range(4):
        for j in range(4):
            for k in range(4):
                for l in range(4):
                    if (puzzle[k][l] < puzzle[i][j] and k*4+l > i*4+j):
                        kurang[puzzle[i][j] - 1] += 1
    total = 0
    for i in range(16):
        total += kurang[i]
        print("KURANG(" + str(i + 1) + ") = " + str(kurang[i]))
    return total

# Menghitung cost G dari suatu puzzle
# Cost G adalah banyaknya ubin tidak kosong yang tidak terdapat pada susunan akhir
# Param: puzzle
# Return: Cost G
def countCostG(puzzle):
    count = 0
    for i in range(4):
        for j in range(4):
            if (puzzle[i][j] != i*4+j+1 and puzzle[i][j] != 16):
                count += 1
    return count 

# Membaca input dari suatu file
# Param: nama file
def readInput(filename):
    with open(filename) as f:
        for line in f:
            lineNumbers = list(map(int, line.split()))
            puzzle.append(lineNumbers)

# Mengoutputkan puzzle ke layar
# Param: puzzle
def printPuzzle(puzzle):
    print("============")
    for i in range(4):
        for j in range(4):
            print('{:<3}'.format(puzzle[i][j]), end = "")
        print()
    print("============")

# Menentukan apakah suatu puzzle merupakan solusi
# Param: puzzle
# Return: True bila puzzle merupakan solusi, False bila tidak
def isSolution(puzzle):
    return countCostG(puzzle) == 0

# Mencari nilai X dari suatu puzzle
# Param: puzzle
# Return: 1 bila angka 16 terletak pada posisi ganjil, 0 bila genap
def X(puzzle):
    findi = 0
    findj = 0
    for i in range(4):
        for j in range(4):
            if (puzzle[i][j] == 16):
                findi = i
                findj = j
    return (findi + findj) % 2

# Menunjukkan matriks langkah demi langkah dari awal ke solusi
# Param: moves
def showSteps(moves):
    global puzzle
    print("Steps: ")
    printPuzzle(puzzle)
    count = 1
    for m in moves:
        print("Step " + str(count) + " => " + m)
        count += 1
        x = move.index(m)
        findi, findj = find16(puzzle)
        newi = findi + di[x]
        newj = findj + dj[x]
        puzzle[findi][findj], puzzle[newi][newj] = puzzle[newi][newj], puzzle[findi][findj]
        printPuzzle(puzzle)
        

if (__name__ == "__main__"):    
    dirname = os.path.dirname(__file__)
    filename = input("Masukkan file input: ")
    readInput(os.path.join(dirname, filename))
    printPuzzle(puzzle)
    inversion = countInversions(puzzle) + X(puzzle)
    print("SUM(KURANG) + X =", inversion)
    if (inversion % 2 == 1):
        print("Tidak ada solusi.")
    else:
        start = time.perf_counter()
        moves = solve(puzzle)
        end = time.perf_counter()
        print("Moves: ", moves)
        showSteps(moves)
        print("Execution time: ", end - start, " sec")
        print("Jumlah simpul yang dibangkitkan: ", nodeNumber)