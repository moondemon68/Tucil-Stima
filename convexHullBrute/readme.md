# Tucil 1: Convex Hull - Bruteforce

# Description:
Given N points, find the convex hull! Bonus: show the graph using any graphing library.

# What file is the solution?
- spec.cpp --> TC generator (must have tcframe to use)
- solution.cpp --> Solution only (no graph)
- solveNdraw.cpp --> Solution + graph

# How to compile:
1. Make sure you are using linux
2. Install matplotlib-cpp requirements -> sudo apt-get install python-matplotlib python-numpy python2.7-dev
3. g++ -o a solveNdraw.cpp -I/usr/include/python2.7 -lpython2.7

# How to run:
./a

# How to generate testcase yourself:
1. Install tcframe (test it using tcframe --version).
2. Compile solution.cpp and name the program solution
3. tcframe build
4. ./runner