
import sys

"""
Principe du programme : Je crée une liste de sous listes, à l'indice i j'ai les voisins de i+1.
Ensuite j'inverse chaque sous liste avec le programme inverse ie j'ai les non voisins de i et j'essaye de mettre les non voisins au même nombre
en vérifiant qu'ils ne sont pas voisins entre eux.
"""

def inverse(l,visite,N):
	m=[]
	for k in range(N):
		if (k+1 not in l) and (k+1 not in visite):
			m.append(k+1)
	return(m)


def test(l,final, visite,N,nb,L):
	if l==[]:
		for k in range(N):
			if len(L[k])==N-1 and final[k]==0:
				visite.add(k+1)
				final[k]=nb
				return(visite,final)
	visite.add(l[0])
	final[l[0]-1]=nb
	dernier=l[0]-1
	impossible=L[dernier]
	for k in range(1,len(l)):
		if l[k] not in visite and l[k] not in impossible:
			visite.add(l[k])
			final[l[k]-1]=nb
			dernier=l[k]-1
			for k in range(len(L[dernier])):
				impossible.append(L[dernier][k])
	return(visite,final)
def f(final):
	for k in range(len(final)):
		if final[k]==0:
			return(k)


compteur=1
while True:
	try:
		N=int(sys.stdin.readline().split()[0])
	except:
		print("")
		break
	L=[[] for i in range(N)]
	if compteur>2:
		print("")
	while True:
		t=sys.stdin.readline().split("-")
		if t==[""] or t==["\n"]:
			break
		if int(t[1][:-1]) not in L[int(t[0])-1]:
			L[int(t[0])-1].append(int(t[1][:-1]))
		if int(t[0]) not in L[int(t[1][:-1])-1]:
			L[int(t[1][:-1])-1].append(int(t[0]))
	final=[0 for k in range(N)]
	visite=set()
	libre=0
	for k in range(1,5):
		try:
			l=inverse(L[libre],visite,N)
			visite,final=test(l,final,visite,N,k,L)
			libre=f(final)
		except:
			rien=0
	for k in range(len(final)):
		print(k+1,final[k])
	compteur+=1
