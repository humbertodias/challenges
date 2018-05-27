final = ""
while True:
    a = [int(i) for i in raw_input().split()]
    if a == [0, 0, 0]:
        print final[:len(final)-2]
        break
    qtdPerolas = a[0]
    qtdAlunos = a[1]
    qtdRespostas = a[2]
    perolas = []
    vetorMaiores = []
    corteMaior = -1
    for i in xrange(qtdPerolas):
        perolas.append(raw_input())
    for i in xrange(qtdAlunos):
        nome = raw_input()
        contPerolas = 0
        resposta = ""
        for j in xrange(qtdRespostas):
            resposta += raw_input() + " "
        for perola in perolas:
            if perola in resposta:
                contPerolas+=1
        if contPerolas > corteMaior:
            vetorMaiores = [nome]
            corteMaior = contPerolas
        elif contPerolas == corteMaior:
            vetorMaiores.append(nome)
    vetorMaiores.sort()
    iAnt = "lulz"
    for i in vetorMaiores:
        if i != iAnt:
            final += i + ", "
        iAnt = i