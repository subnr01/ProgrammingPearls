#
#	This python file is used to generated random numbers for program test
#
import random

file = open("testdata.txt", "w")
data = range(10000000)
random.shuffle(data)
for d in data:
	file.write(str(d)+"\n")
file.close()
