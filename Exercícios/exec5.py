# -*- coding: utf-8 -*-
n1 = float(input("Digite o primeiro número: "))
n2 = float(input("Digite o segundo número: "))
op = input("Digite a operação: ")

if op == "+":
	print("Soma: "+str(n1+n2))
elif op == "-":
	print("Subtração: "+str(n1-n2))
elif op == "*":
	print("Multiplicação: "+str(n1*n2))
elif op == "/":
	print("Divisão: "+str(n1/n2))
elif op == "^":
	print("Exponenciação: "+str(n1**n2))
else:
	print("Operação inválida")
