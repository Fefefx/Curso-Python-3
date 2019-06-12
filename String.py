# -*- coding: utf-8 -*-
a = "Felipe"
b = " Pardim"
concatenar = a + b
print(concatenar)


# A função len retorna a quantidade de caracteres da String
tamanho = len(concatenar)
print(tamanho)

print(a[0])

"""for i in range(len(concatenar)):
	print(concatenar[i])"""

#imprime os valores da posição 0 até 6
print(concatenar[0:6])

#Strings em Python são Objetos

#A função lower transforma os caracteres em minúsculos
print(concatenar.lower())

#A função upper transforma os caracteres em maiúsculos
print(concatenar.upper())

concatenar = concatenar.upper();

concatenar+="\n"

"""A função strip remove caracteres especias 
   ouespaços do final da String""" 
print(concatenar.strip())

minha_string = "O rato roeu a roupa do rei de Roma"

"""A função split divide uma String e cria uma lista
   a partir de um caracter passado como parâmetro"""
minha_lista = minha_string.split("r")
print(minha_lista)

"""A função find localiza a posição 
   aonde começa uma determinada palavra,
   se ela não encontrar a mesma retorna -1"""
busca = minha_string.find("rei")
print(busca)

print(minha_string[busca:])

#Replace substitui o texto em uma String por outro
minha_string = minha_string.replace("o rei","a rainha")
print(minha_string)