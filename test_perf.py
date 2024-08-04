
a = 0
for i in range(1000000):
    a = (65537 * a) % 512 + i

print(a)