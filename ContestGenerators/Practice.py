import webbrowser
import time
import random

PA = random.randint(16, 17) * 100
PB = random.randint(18, 19) * 100
PC = random.randint(20, 20) * 100
PD = random.randint(21, 21) * 100
PE = random.randint(22, 22) * 100
PF = random.randint(23, 23) * 100
PG = random.randint(23, 23) * 100

print("A: ", PA)
print("B: ", PB)
print("C: ", PC)
print("D: ", PD)
print("E: ", PE)
print("F: ", PF)
print("G: ", PG)


webbrowser.open(f'https://codeforces.com/mashup/new', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={PA}-{PA}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={PB}-{PB}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={PC}-{PC}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={PD}-{PD}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={PE}-{PE}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={PF}-{PF}', new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags={PG}-{PG}', new = 2)