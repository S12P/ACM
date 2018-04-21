import sys

def load():
    while True:
        n = int(next(sys.stdin))
        u = next(sys.stdin)[::-1]
        v = next(sys.stdin)[::-1]
        w = next(sys.stdin)[::-1]

        yield u, v, w



for n, u, v, w in load():
    letters = set()
    values = {}
    used = set()

    # on ajoute toutes les lettres à tester
    for i in u:
        letters.add(i)
    for i in v:
        letters.add(i)
    for i in w:
        letters.add(i)

    def test(k, values,)

    print(test(0, values, letters))
