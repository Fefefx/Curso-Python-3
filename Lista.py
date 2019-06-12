# -*- coding: utf-8 -*-
minha_lista = ["abacaxi","melancia","abacate"]
minha_lista_2 = [1,2,3,4,5]
minha_lista_3 = ["abacaxi",2,9.89,True]

for item in minha_lista:
	print(item)

tamanho = len(minha_lista)
print("Tamanho da lista: ",tamanho)

#Adiciona um elemento a lista
minha_lista.append("limão")
print(minha_lista)

#A palavra reservada in verifica se um elemento existe na lista
if 3 in minha_lista_2:
	print("3 está na lista")
#A palavra reservada del remove elementos da lista
# Para apagar a lista inteira del nome_da_lista[:]
del minha_lista[2:]
print(minha_lista)

minha_lista_4 =[]
minha_lista_4.append(57)
print(minha_lista_4)