
# Its a trivial mathematical progression. Just (n / 2) * 2, or if it doesn't
# divide evenly (n/2) * ((n/2) + 1)
 
T = input()

for i in xrange(T):
    
    n = input()
    
    a = b = (n / 2)
    
    if n % 2:
        b = b + 1
	
    print a * b
	