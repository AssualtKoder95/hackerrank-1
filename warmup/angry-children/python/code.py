
N = input()
K = input()

# Load the candy packet sizes into a list and sort it
candies = [int(raw_input()) for i in range(0,N)]

candies.sort()

# Initialize to last value in list (which is the maximum possible delta)
best = candies[-1];

# Then slide a K-wide window along the array, looking
# for the offset with the lowest delta between the first
# and the last elements
    
for i in xrange(N - K + 1):
	
    if (candies[i + K - 1] - candies[i]) < best:
	    
	best = candies[i + K - 1] - candies[i]

print best
	