import time
start = time.time()

def printAprox(arr): #auxiliar para formatação
    for i in range(len(arr)):
        print("x%s: %.5f\t" % (i+1, arr[i]), end = ' ')
    print("\n")


def metJacobi(matrSist, arrResult, tamanh, aprox=None, \
              maxItera = 100, tolMin = 1e-3):
    
    if aprox is None:
        aprox = [0 for i in range(tamanh)] 
        
    aprox2 = [0 for i in range(tamanh)]
    #dois vetores de aproximações garantem a iteração

    matrAum = matrSist
    arrResultAum = arrResult

    for i in range(tamanh): #Isola cada variável da matriz
        p = matrAum[i][i]
        for j in range(tamanh):
            if p != 0:
                 matrAum[i][j] = -(matrAum[i][j] / float(p))
            if i == j:
                 matrAum[i][j] = 0
        arrResultAum[i] = arrResultAum[i] / float(p)

    sucesso = False
    for x in range(maxItera): #Calcula as aproximações
        print("k=%d" % (x+1))
        if x%2 == 0:
            for i in range(tamanh):
                soma = 0
                for j in range(tamanh):
                    soma += matrAum[i][j] * aprox[j]
                aprox2[i] = soma + arrResultAum[i]
            printAprox(aprox2)
            
            if (max(aprox)!=0) and \
               (abs(max(aprox2) - max(aprox)) / abs(max(aprox))) < tolMin:
                #a tolerância foi atingida
                print("O processo foi bem-sucedido") 
                sucesso = True
                break
            
        else:
            for i in range(tamanh):
                soma = 0
                for j in range(tamanh):
                    soma += matrAum[i][j] * aprox2[j]
                aprox[i] = soma + arrResultAum[i]
            printAprox(aprox)

            if (max(aprox2)!=0) and \
               (abs(max(aprox) - max(aprox2)) / abs(max(aprox2))) < tolMin:
                #a tolerância foi atingida    
                print("O processo foi bem-sucedido") 
                sucesso = True
                break
            
    if not sucesso:
        print("O processo excedeu o numero maximo de iteracoes")




maxItera = 100      #Máximo de Iterações
tolMin = 1e-2       #Tolerancia

#Para Ax = b
matriz = [[ 10,  -1,   2,   0 ],    #A
          [ -1,  11,  -1,   3 ],
          [  2,  -1,  10,  -1 ],
          [  0,   3,  -1,   8 ]]


arrResult = [ 6,  25,  -11,  15 ]   #b

tam = len(arrResult)
aproxIni = [0 for i in range(tam)]      #Vetor de aproximações iniciais


metJacobi(matriz, arrResult, tam, aproxIni, maxItera, tolMin)

end = time.time()
print("Tempo de execucao: {} segundos".format(end-start))