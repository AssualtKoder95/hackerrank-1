
# This problem is simple: scan through the road array and
# determine the minimum value
    
vars = map(int,raw_input().split())

length = vars[0]
cases = vars[1]

road = map(int,raw_input().split())

for i in range(0,cases):
    
    index = map(int,raw_input().split())
    i = index[0]
    j = index[1]
    
    print min(road[i:j+1])
