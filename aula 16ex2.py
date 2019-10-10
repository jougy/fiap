def maneira1():
    letra = ord(input('insira uma letra: '))
    if letra >= 97 and letra <= 122:
        print('m')
    elif letra >= 65 and letra <= 90:
        print('M')
    else:
        print('valor invalido')
def maneira2():
    letra = input('digite uma letra: ')
    if letra <= 'z' and letra >= 'a':
        print ('m')
    else:
        print('M')
