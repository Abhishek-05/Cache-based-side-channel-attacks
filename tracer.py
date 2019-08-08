import os
import matplotlib.pyplot as plt

squarex = []
squarey = []
with open('t2.txt') as input_file:
	for i,line in enumerate(input_file):
		a,b = line.split(",")
		squarex.append(a)
		squarey.append(b)

multx = []
multy = []
with open('t3.txt') as input_file:
	for i,line in enumerate(input_file):
		a,b = line.split(",")
		multx.append(a)
		multy.append(b)

plt.plot(squarex,squarey,label="square",marker= "*")
plt.plot(multx,multy,label="multiply",marker= "*")
plt.show()

# string = ''

# i = j = k = 0

# L = square

# R = mult

# arr = []

#         # Copy data to temp arrays L[] and R[] 
# while i < len(L) and j < len(R): 
# 	if L[i] < R[j]:
# 		arr[k] = 1
# 		i+=1
# 	else:
# 		arr[k] = 0
# 		j+=1
# 		k+=1
          
#         # Checking if any element was left 
# while i < len(L):
# 	arr[k] = 1
# 	i+=1
# 	k+=1
          
# while j < len(R):
# 	arr[k] = 0
# 	j+=1
# 	k+=1

# for i in range(0,len(arr)) :
# 	if i == len(arr)-1 :
# 		break
# 	else :
# 		if arr[i] == 1 and arr[i+1] == 0