import sys
#32bits version

def gcd(a,b):
	while b: a, b = b, a % b
	return a

def wabbits(a,b):
	x = a-b
	for i in range(a-1,b+1,-1):
		g = gcd(b*(i-(x)),a*(i))
		a = a*(i)/g
		b = b*(i-(x))/g

	g = gcd(a-b,a)
	print str((a-b)/g)+"/"+str(a/g)
	 
while(1):
	try:
		line = sys.stdin.readline().split()
		t = int(line[0])
		p = int(line[1])
		b = int(t-p)
	
		if p < 2: print "0/1"
		else: wabbits(t,b)

	except:
		break
