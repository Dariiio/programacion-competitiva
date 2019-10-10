import os
'''
Este programa horrible busca problemas que coinciden con
un determinado tag
Si es horrible 
'''


def buscar_tag(archivo):
	''' recibe un archivo. Devuelve una lista de string '''
	f = open(archivo,"r")
	s = f.readline(); tags = []; tag = ""; i = 0
	while(i < len(s)):
		if s[i] == '@':
			i += 1
			while(i < len(s) and s[i] != '@' and s[i] != '\n'):
				tag += s[i];i += 1
			tags.append(tag)
			tag = ""
		else: i += 1
	f.close()
	return tags

def es_archivo_valido(nombre):
	n = len(nombre)
	if nombre[n-1] == 'p' and nombre[n-2] == 'p' and nombre[n-3] == 'c' and nombre[n-4] == '.':
		return True
	else:
		return False

def machear_tag(tg):
	''' Recibe un string. Devuelve una lista de string '''
	raiz = "."; directorios = []
	for path, subdirList, fileList in os.walk(raiz):
		for fnombre in fileList:
			if es_archivo_valido(fnombre):
				if tg in buscar_tag(path+"/"+fnombre):
					directorios.append(path + "/" + fnombre)
	return directorios
	

while 1:
	s = input("Buscar tag: ")
	ans = machear_tag(s)
	if ans:
		for e in ans:
			print(e)
	else:
		print("no se encontro ningun archivo con ese tag")
