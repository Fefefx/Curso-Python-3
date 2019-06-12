import random

def geraListaInteiro(tam):
	Lista = []
	for i in range(tam):
		Lista.append(random.randint(0,tam))
	return Lista

