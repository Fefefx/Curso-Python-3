#Em Python uma função é definida pela palavra def
def soma(x,y):
	return x+y

def multiplicacao(x,y):
	return x*y

s = soma(2,3)
print("Soma:",s)

m = multiplicacao(3,4)
print("multiplicação:",m)

# O escopo das funções deve ser definido antes da invocação 
print(soma(s,m))