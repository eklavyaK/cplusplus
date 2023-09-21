import webbrowser
import time
import random

P = [8, 9, 10, 11, 12, 13, 14, 15]
for i in range(0, 8):
	P[i] *= 100
random.shuffle(P)

# time limit constraints for problems

# 800, 900 - 3 min
# 1000, 1100 - 7 min
# 1200, 1300 - 11 min
# 1400, 1500 - 15 min
# 1600 - 20 min
# 1700 - 25 min
# 1800 - 30 min
# 1900 - 35 min
# 2000 - 40 min
# 2100 - 50 min
# 2200 - 55 min
# 2300 - 60 min

f = open(r"C:\Users\MY_PC\cp\ContestGenerators\Difficulty.txt", "w")
f.write(f"A: {P[0]}\n") 
f.write(f"B: {P[1]}\n")
f.write(f"C: {P[2]}\n")
f.write(f"D: {P[3]}\n")
f.write(f"E: {P[4]}\n")
f.write(f"F: {P[5]}\n")
f.write(f"G: {P[6]}\n")
f.write(f"H: {P[7]}\n")
f.close()

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


firefox_path = "C:/Program Files/Mozilla Firefox/firefox.exe"

webbrowser.register('firefox', None, webbrowser.BackgroundBrowser(firefox_path))
time.sleep(1)
webbrowser.get('firefox').open(f'https://codeforces.com/mashup/new')
time.sleep(1)
webbrowser.get('firefox').open(f'https://codeforces.com/problemset?tags={P[0]}-{P[0]}')
time.sleep(1)
webbrowser.get('firefox').open(f'https://codeforces.com/problemset?tags={P[1]}-{P[1]}')
time.sleep(1)
webbrowser.get('firefox').open(f'https://codeforces.com/problemset?tags={P[2]}-{P[2]}')
time.sleep(1)
webbrowser.get('firefox').open(f'https://codeforces.com/problemset?tags={P[3]}-{P[3]}')
time.sleep(1)
webbrowser.get('firefox').open(f'https://codeforces.com/problemset?tags={P[4]}-{P[4]}')
time.sleep(1)
webbrowser.get('firefox').open(f'https://codeforces.com/problemset?tags={P[5]}-{P[5]}')
time.sleep(1)
webbrowser.get('firefox').open(f'https://codeforces.com/problemset?tags={P[6]}-{P[6]}')
time.sleep(1)
webbrowser.get('firefox').open(f'https://codeforces.com/problemset?tags={P[7]}-{P[7]}')