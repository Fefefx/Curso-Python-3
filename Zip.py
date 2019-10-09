#Zip

lista1 = [1,2,3,4,5]
lista2 = ["abacate","bola","cachorro","dinheiro","elefante"]
lista3 = ["R$2,00","R$5,00","Dispenso dá muito gasto","Está difícil obter","é o tamanho das minhas contas"]

# A função zip concatena várias listas em uma só
for numero,nome,texto in zip(lista1,lista2,lista3):
    print(numero,nome,texto)