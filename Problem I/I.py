import sys

def build_col(s):
	#retorna equacao de coluna(auxiliar de build)
	sout = ""
	for k in list(s[:-1]): sout += "+" + k
	sout += "=" + s[-1]
	return sout


def build(table):
	#retorna equacao de colunas
	final = ""
	x = len(table[0])-1
	for i in range(x,-1,-1):
		out = ""
		for k in table: out += k[i]
		final += build_col(out.replace(" ",""))
	return final


def solver(string, k):
	#resolucao
	global count
	
	if (len(string) == 0 and k == 0):
		count += 1
		output()
		return 0

	l = ord(string[0])
	f = ord(string[1])
	
	if l == 43:
		if asc[f] >= 0: solver(string[2:], k+asc[f])
		else:
			for i in xrange(first[f],10):
				if pick[i] != 1:
					pick[i] = 1
					asc[f] = i
					solver(string[2:], k+i)
					pick[i] = 0
					asc[f] = -1
	elif l == 61:
		i = k%10
		
		if asc[f] >= 0: 
			if asc[f] == i: solver(string[2:], k/10)
		else:
			 if (pick[i] != 1 and i >= first[f]):
				pick[i] = 1 
				asc[f] = i
				solver(string[2:], k/10)
				pick[i] = 0
				asc[f] = -1


def output():
	#construcao de output
	aux = ''
	for l in letters:
		aux += l+"="+str(asc[ord(l)])+" "
	out.append(aux.strip())


def puzzle(n):
	#inicializar puzzle
	global asc,first,pick,count,letters
	table = []

	for i in xrange(n):
		palavra = sys.stdin.readline().rstrip()
		palavra = list(palavra)
		table.append(palavra)

	#pick[]
	pick = [0]*10

	#asc[]
	asc = [-2]*255
	aux = ''
	for y in table: aux +=''.join(y).strip()

	#letters[]
	letters = sorted(list(set(list(aux))))
	l = [ord(x) for x in letters]
	for y in l: asc[y] = -1
	#for i in xrange(48,58): asc[i]=i-48

	#first[]
	first = [0]*255
	for y in table: first[ord(''.join(y).strip()[0])] = 1

	print asc
	
	#run
	count = 0
	eq = build(table)
	solver(eq,0)

	if count == 0: print "No solution!"
	
#input
blank = 0
while True:
	l = sys.stdin.readline().rstrip()
	if l == "": break
	if blank != 0: print
	n,m = map(int,l.split())
	
	out = []	
	puzzle(n)
	for item in sorted(out): print item
	blank = 1
