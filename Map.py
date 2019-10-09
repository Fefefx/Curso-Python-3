#Map

def dobro(x):
    return x*2

valor = [1,2,3,4,5]

#A função map aplica uma função a cada elemento de uma lista e retorna um objeto
valor_dobrado = map(dobro,valor)

"""for v in valor_dobrado:
    print(v)"""

valor_dobrado = list(valor_dobrado)
print(valor_dobrado)