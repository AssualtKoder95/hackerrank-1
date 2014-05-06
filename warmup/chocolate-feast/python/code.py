
cases = input()
total = 0

for i in xrange(cases):
    
    case = map(int,raw_input().split())

    n = case[0]
    c = case[1]
    m = case[2]
    	
    # Calculate the number of chocolates that can be bought
    # for the given amount of money
	
    total = wrappers = n / c;

    # Then iteratively trade wrappers for chocolates, topping
    # up the number of wrappers on each pass, uuntil we run 
    # out of wrappers
	
    while wrappers >= m:
	 
	trade = wrappers / m
	total = total + trade
	wrappers = wrappers % m
	wrappers = wrappers + trade

    print total
	