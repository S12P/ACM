import sys

line = next(sys.stdin)
dico = {}

def load():
    while True:
        yield next(sys.stdin)

while line != "\n":
    eng, alien = line.split(" ")
    dico[alien] = eng
    line = next(sys.stdin)

for w in load():
    if w in dico.keys():
        print(dico[w])
    else:
        print("eh")
