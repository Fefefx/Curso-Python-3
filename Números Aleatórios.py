#-*- coding:utf-8 -*-
import random

#Força a bilbioteca random a dar sempre o mesmo resultado
#random.seed(1)

#Gera uma número aleatório dentro de um determinado valor
numero = random.randint(0,10)
print(numero)

lista = [6,45,9]
#Escolhe um elemento aleatório de uma lista
numero = random.choice(lista)
print(numero)
