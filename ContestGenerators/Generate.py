import webbrowser
import time
import random

A = [[16, 19], [17, 18]]
random.shuffle(A)
P = [A[0][0], A[0][1], 20, 22]
for i in range(0, 4):
	P[i] *= 100
A = [P[0], P[1], P[2]]
random.shuffle(A)
P = [A[0], A[1], A[2], P[3]]

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

G = [0, 4, 5, 6, 7, 8]

random.shuffle(G)

T = [A[G[0]], A[1], A[2], A[3]]

random.shuffle(T)


print("A: ", P[0], T[0]) 
print("B: ", P[1], T[1])
print("C: ", P[2], T[2])
print("D: ", P[3], T[3])


webbrowser.open(f'https://codeforces.com/mashup/new', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={T[0]},{P[0]}-{P[0]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={T[1]},{P[1]}-{P[1]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={T[3]},{P[2]}-{P[2]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={T[2]},{P[3]}-{P[3]}', new = 2)