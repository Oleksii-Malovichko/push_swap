import random

numbers = random.sample(range(-1000, 1001), 500)

result = ' '.join(map(str, numbers))

print(result)