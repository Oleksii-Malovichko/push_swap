import random

numbers = random.sample(range(-1000, 1001), 1000)

result = ' '.join(map(str, numbers))

print(result)