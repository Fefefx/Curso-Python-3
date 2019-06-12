# -*- coding:utf-8 -*-
lista = []
for i in range(3):
	element = int(input("Digite um número: "))
	lista.append(element)
lista.sort()
print("Elementos da lista: "+str(lista))