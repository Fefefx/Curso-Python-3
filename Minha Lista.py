# -*- coding:utf-8 -*-	

def isEmpty():
	if len(list) == 0:
		return True
	else:
		return False

def validate():
	if isEmpty():
		print("\nNão foi possível realizar a ação. A lista está vazia !")
		return False
	else:
		return True


def createElement():
	answer = "S"
	while answer == "s" or answer == "S":
		data = int(input("Digite um número: "))
		list.append(data)
		answer = input("\nDeseja inserir um novo número[S/n]: ")
	list.sort()

list = []
answer = "S"
while answer == "s" or answer == "S":
	print("\nMenu de opções:\n")
	print("1-Inserir um elemento\n")
	print("2-Remover em fila\n")
	print("3-Remover em pilha\n")
	print("4-Listar elementos em ordem crescente\n")
	print("5-Listar elementos em ordem decrescente\n")
	print("6-Esvaziar a lista\n\n")
	option = int(input("Digite uma opção: "))
	if option == 1:
		createElement()
	elif validate():
		if option == 2:
			del(list[0])
		elif option == 3:
			del(list[len(list)-1])
		elif option == 4:
			print("\nElementos da lista: ",list)
		elif option == 5:
			listDescending = sorted(list, reverse = True)
			print("\nElementos da lista em ordem decrescente: ",listDescending)
		elif option == 6:
			list = []
			print("\nTodos os elementos da lista foram removidos !")
		else:
			print("\nOpção inválida. Tente novamente !\n")
	answer = input("\nDeseja realizar outra ação [S/n]? ")
print("\nPrograma Finalizado !")