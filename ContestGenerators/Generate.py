import random

PA = random.randint(12, 13) * 100
PB = random.randint(14, 15) * 100
PC = random.randint(16, 18) * 100
PD = random.randint(19, 21) * 100
PE = random.randint(22, 22) * 100

print("A:",PA)
print("B:",PB)
print("C:",PC)
print("D:",PD)
print("E:",PE)

import webbrowser
import time

webbrowser.open(f'https://codeforces.com/mashups',new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags=data%20structures,{PA}-{PA}',new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags=data%20structures,{PB}-{PB}',new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags=data%20structures,{PC}-{PC}',new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags=data%20structures,{PD}-{PD}',new = 2)
time.sleep(1)
webbrowser.open(f'https://codeforces.com/problemset?tags=data%20structures,{PE}-{PE}',new = 2)