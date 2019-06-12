# -*- coding: utf-8 -*-
a = float(input("Digite o valor de a: "))
b = float(input("Digite o valor de b: "))
c = float(input("Digite o valor de c: "))

delta = (b**2) - (4*a*c)

#Outro jeito de calcular raíz

#from math import sqrt

#sqr(delta)

raiz = delta**(1/2)
x1 = ((-b) + raiz)/(2*a)
x2 = ((-b) - raiz)/(2*a)

print("Delta: "+str(delta))
print("Raíz: "+str(raiz))
print("X1: "+str(x1))
print("X2: "+str(x2))