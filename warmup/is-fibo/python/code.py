
# There are less than 50 fibonacci numbers under 10^10 but potentially
# up to 10,000 numbers to test. So by far the most efficient way to solve
# this problem is to create a LUT of all fibonacci numbers under 10^10
# and check against it
    
fib = [1]
previous = 0
current = 1

while current < 1e10:
    
    fib.append(current)
    
    next = previous + current
    previous = current
    current = next

    
T = input()

for i in xrange(T):
    
    N = input()
    
    if N in fib:
        print 'IsFibo'
	
    else:
        print 'IsNotFibo'