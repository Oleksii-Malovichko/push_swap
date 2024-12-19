import random

numbers = random.sample(range(-1000, 1001), 15)

result = ' '.join(map(str, numbers))

print(result)