import subprocess
import random

arr = []
i = 0
while (i < 100):
	num = random.randint(-2147483648, 2147483647)
	arr.append(str(num))
	i+=1
# print(arr)
execution = subprocess.run(
	["./push_swap.o", *arr],
	text=True,
	capture_output=True
)

s = execution.stdout
print(s)