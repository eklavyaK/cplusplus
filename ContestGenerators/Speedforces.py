import webbrowser
import time
import random

P = [8, 9, 10, 11, 12, 13, 14, 15]
for i in range(0, 8):
	P[i] *= 100
random.shuffle(P)


print("A: ", P[0])
print("B: ", P[1])
print("C: ", P[2])
print("D: ", P[3])
print("E: ", P[4])
print("F: ", P[5])
print("G: ", P[6])
print("H: ", P[7])

webbrowser.open(f'https://codeforces.com/mashup/new', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={P[0]}-{P[0]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={P[1]}-{P[1]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={P[2]}-{P[2]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={P[3]}-{P[3]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={P[4]}-{P[4]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={P[5]}-{P[5]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={P[6]}-{P[6]}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={P[7]}-{P[7]}', new = 2)