# média, mediana, moda
#Importa todos os recursos da biblioteca statistics
#from statistics import *

#Calcula a média dos elementos de uma lista
#mean(lista)

#Calcula a mediana dos elementos da lista
#median(lista)

#Calcula a moda da lista
#mode(lista)

def media(lista):
	media = sum(lista)/float(len(lista))
	return media

def mediana(lista):
	lista_ordenada = sorted(lista)
	t = len(lista_ordenada)
	if t%2==0:
		mediana = (lista_ordenada[int(t/2)] + lista_ordenada[int((t/2)-1)])/2
	else:
		mediana = lista_ordenada[int(t/2)]
	return mediana

def moda(lista):
	lista_dic = {}
	for l in lista:
		if l not in lista_dic:
			lista_dic[l] = 1
		else:
			lista_dic[l] += 1
	print(lista_dic)
	maior_repeticao = max(lista_dic.values())
	for i in lista_dic:
		if lista_dic[i] == maior_repeticao:
			moda = i
	return moda
			




