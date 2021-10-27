import pygob
import sys 

path = sys.argv[1]
data = open(path, "rb").read()
program = pygob.load(data)

print(program)
