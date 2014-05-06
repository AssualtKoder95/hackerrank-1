
import sys

cases = input()

for i in range(0, cases):
    
    digits = input()

    # This problem follows a simple numeric progression. Just write
    # out the series of numbers and the relationships are easy to spot
    
    if digits < 9:
	
	if digits == 3:
	    sys.stdout.write("555")
	    
	elif digits == 5:
	    sys.stdout.write("33333")
	    
	elif digits == 6:
	    sys.stdout.write("555555")
	    
	elif digits == 8:	    
	    sys.stdout.write("55533333")
	    
	else:
	    sys.stdout.write("-1")
	    
    else:
	
	remainder = digits - 9
	
	if remainder % 3 == 0:
	    threes = 0
	    
	elif remainder % 3 == 1:
	    threes = 10
	    
	elif remainder % 3 == 2:
	    threes = 5
	    
	fives = digits - threes
	
	for i in range(0,digits):
	    
	    if i < fives:		
		sys.stdout.write("5")	
		
	    else:
		sys.stdout.write("3")
		
    sys.stdout.write("\n")