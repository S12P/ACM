import sys

def entre(m):
	compteur=0
	for line in sys.stdin:
		for var in line.split():
			if len(m[compteur])>=n:
				compteur+=1
			m[compteur].append(int(var))
	return(m)



while(True):
	try:
		n=int(sys.stdin.readline().split()[0])
	except:
		break
	m=[[] for i in range(n)]
	m_somme=[[0 for i in range(n+1)] for i in range(n)]
	m_=[0 for i in range(n+1)]
	mini=-127
	m=entre(m)
	for i in range(n):
		for j in range(1,n+1):
			m_somme[i][j]=m_somme[i][j-1]+m[i][j-1]
	for i in range(n):
		for j in range(i,n):
			for k in range(n):
				m_[k+1]=max(m_somme[k][j+1]-m_somme[k][i]+m_[k],m_somme[k][j+1]-m_somme[k][i])
				mini=max(mini,m_[k+1])
	print(mini)
