#Filter

def pares(i):
    if i % 2 == 0:
        return i

lista = [1,2,3,4,5,6,7,8,9,10]

"""A função filter filtra os elementos de um vetor por meio da condição
expressa em uma função."""

lista_pares = filter(pares,lista)
#Filter retorna um objeto, sendo necessária conversão
print(list(lista_pares))
