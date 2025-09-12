tablero = ["-","-","-","-","-","-","-","-","-"]

ganador = None
def Jugar():
    global ganador
    VerTablero()

    for i in range(5):
        print("Turno del jugador 1 - X")
        valor = "X"
        jugada(valor)
        huboganador()
    
        if ganador != "X" and i < 4:
            for j in range(3):
                    print("Turno del jugadorr 2 - O")
                    valor = "O"
                    jugada(valor)
                    huboganador()

                    if ganador == "O":
                         print("FELICICADES CRACK GANADOR JUGADOR 2" )
                         return
                    break
        elif ganador == "X":
              print("FELICICADES CRACK GANADOR JUGADOR 1" )
              break
            
        else:
            print("EMPATARON" )
            break
                

    
def huboganador():
     global ganador
     ControlVertical()
     ControlHorizonatal()
     ControlDiagonal()
     
     
def ControlHorizonatal():
     global ganador
     if tablero[0] == tablero[1] == tablero[2] !="-":
          ganador = tablero[0]
     elif tablero[3] == tablero[4] == tablero[5] !="-":
          ganador = tablero[3]
     elif tablero[6] == tablero[7] == tablero[8] !="-":
          ganador = tablero[6]

def ControlVertical():
     global ganador
     if tablero[0] == tablero[3] == tablero[6] !="-":
          ganador = tablero[0]
     elif tablero[1] == tablero[4] == tablero[7] !="-":
          ganador = tablero[4]
     elif tablero[2] == tablero[5] == tablero[8] !="-":
          ganador = tablero[2]

def ControlDiagonal():
     global ganador
     if tablero[0] == tablero[4] == tablero[8] !="-":
          ganador = tablero[0]
     elif tablero[2] == tablero[4] == tablero[6] !="-":
          ganador = tablero[4]

     
    
def jugada(valor):

    anoto = False

    while anoto == False:
        posicion = int(input("Eligue la posicion 1 -- 9 "))
        posicion = posicion - 1

        if tablero[posicion] == "-":
          tablero[posicion] = valor
          anoto = True
        else:
            print("Esa posicion de tablero ya esta ocupada!!")
        
        VerTablero()



def VerTablero():
    print("\n")
    print(tablero[0] + " | " + tablero[1] + " | " + tablero[2])
    print(tablero[3] + " | " + tablero[4] + " | " + tablero[5])
    print(tablero[6] + " | " + tablero[7] + " | " + tablero[8])
    print("\n")

Jugar()