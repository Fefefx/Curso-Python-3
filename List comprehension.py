# list comprehension

x = [1,2,3,4,5]

# Sem List comprehension
"""y = []

for i in x:
    y.append(i**2)"""

# Com List comprehension
# y = [valor laço condição]

y = [i**2 for i in x]
z = [i for i in x if i%2==1]

print(x)
print(y)
print(z)