
# Not sure if its the author's intent for the question to be
# *quite* so easy, but all you have to do is keep a running
# total of the number of candies added, then divide it by the
# number of jars
 
vars = map(int,raw_input().split())

jars = vars[0]
cases = vars[1]
total = 0

for i in xrange(cases):
    
    case = map(int,raw_input().split())

    start = case[0]
    end = case[1]
    candies = case[2]
    	
    total = total + ((end - start) + 1) * candies

print total / jars
	