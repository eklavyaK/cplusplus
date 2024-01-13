import webbrowser
import time
import random

P = [1600, 1700, 1800, 1900, 2000]

# 800, 900 - 3 min
# 1000, 1100 - 6 min
# 1200, 1300 - 9 min
# 1400, 1500 - 15 min
# 1600 - 20 min
# 1700 - 25 min
# 1800 - 30 min
# 1900 - 35 min
# 2000 - 40 min
# 2100 - 50 min
# 2200 - 55 min
# 2300 - 60 min



#     0         1         2      3            4                5               6                     7                   8

A = ["math", "graphs", "trees", "dp", "binary%20search", "probabilities", "number%20theory", "divide%20and%20conquer", "strings"]

G = [0, 1, 2, 3, 4, 5, 6, 7, 8]

random.shuffle(G)

T = [A[G[0]], A[G[1]], A[G[2]], A[G[3]], A[G[4]]]

random.shuffle(T)


# print("A: ", P[0], T[0]) 
# print("B: ", P[1], T[1])
# print("C: ", P[2], T[2])
# print("D: ", P[3], T[3])


webbrowser.open(f'https://codeforces.com/mashup/new', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={T[0]},{P[0]}-{P[0]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={T[1]},{P[1]}-{P[1]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={T[2]},{P[2]}-{P[2]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={T[3]},{P[3]}-{P[3]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={T[4]},{P[4]}-{P[4]}', new = 2)