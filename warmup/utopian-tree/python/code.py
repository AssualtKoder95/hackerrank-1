
from sys import argv

cases = input()

for i in range(0, cases):
    
    n = input()
    
    total = 1
    cycle = 0

    while cycle < n:
	
	if cycle % 2 == 0:
	    total = total * 2
	else:
	    total = total + 1
	    
	cycle = cycle + 1
	
    print total