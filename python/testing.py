import sys

def main():
	if len(sys.argv) <= 1:
		return
	
	filename = sys.argv[1].strip()
	
	f = open(filename)
	
	for line in f:

		strC = line.split('|')
		s1 = strC[0].strip()
		s2 = strC[1].strip()
		
		i = 0
		dislocat = 0
		numMis =0
		for c2 in s2:
			if i >= len(s1):
				numMis += 1
				i += 1
				continue
			c1 = s1[i]
			
			if c1 != c2:
				if c2 in s1[i:] :
					pos = s1[i:].index(c2)
					if pos != (i + dislocat):
						newDislocate = pos - i - dislocat
						if newDislocate != dislocat: numMis += 1
						dislocat = newDislocate
				else: numMis += 1
			i += 1
		if numMis == 0: print("Done")
		elif numMis <=2: print("Low")
		else: print("Critical")
	f.close()

main()