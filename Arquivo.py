# -*- coding: utf-8 -*-

#Abre um arquivo
arquivo = open("arquivo.txt")

#print(arquivo)

#Lê cada uma das linhas e adiciona a uma lista
"""linhas = arquivo.readlines()

for linha in linhas:
	print(linha)"""

"""texto_completo = arquivo.read()

print(texto_completo)"""

"""Manda criar um arquivo no diretório 
   do Script com o nome de arquivo2,
   se já existir apaga e cria novamente.
   Para atualizar use o método a."""
w = open("arquivo.txt","w")

#Escreve os dados no arquivo
w.write("Esse é o meu arquivo")

#Fecha o arquivo
w.close()


