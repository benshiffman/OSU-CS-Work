import random
from random import randint

#board1 is the game board which is displayed to the user, board2 uses the inverse coordinates of board1 and simplifies win-checking
board1 = [[" "," "," "] , [" "," "," "] , [" "," "," "]]
board2 = [[" "," "," "] , [" "," "," "] , [" "," "," "]]

#takes board1, flips it, and copies it to board2
def copyBoards():
    for y in range(3):
        for x in range(3):
            board2[x][y] = board1[y][x]

#prints a pretty board!
def printBoard():
    print(" " + board1[0][0] + " | " + board1[0][1] + " | " + board1[0][2] + " ")
    print("-----------")
    print(" " + board1[1][0] + " | " + board1[1][1] + " | " + board1[1][2] + " ")
    print("-----------")
    print(" " + board1[2][0] + " | " + board1[2][1] + " | " + board1[2][2] + " ")

#asks the user(s) if they want to play single player (vs cpu) or multiplayer
def mode():
    singleOrMulti = 0
    while True:
        try: 
            singleOrMulti = int(input("Would you like to play with 1 or 2 players? "))
            if singleOrMulti < 1 or singleOrMulti > 2: raise
            break
        except: print("Invalid input.")
    return singleOrMulti

#takes in either an X or O, and checks if there are three Xs or Os in a row, depending on whose turn it is
def checkWin(t):
    tlist = [t,t,t]
    testlist = ["","",""]

    #checks if full rows or columns are win-worthy
    for x in range(3):
        if board1[x] == tlist: return True
        if board2[x] == tlist: return True

    #checks one diagonal
    for x in range(3): testlist[x] = board1[x][x]
    if testlist == tlist: return True

    #checks the other diagonal
    for x in range(3): testlist[x] = board1[x][2-x]
    if testlist == tlist: return True
    
    return False

#asks user for a number 0 through 2, and only accepts correct inputs
def getValidCoord():
    coord = 0
    while True:
        try:
            coord = int(input("Enter number 0-2: "))
            if coord < 0 or coord > 2: raise
            break
        except: print("Invalid input.")
    return coord

#asks user(s) who goes first, only accepts correct inputs
def getValidPlayerChoice():
    choice = ""
    while True:
        try:
            choice = str(input("Who goes first, (X) or (O)? "))
            if choice != "X" and choice != "O": raise
            break
        except: print("Invalid input.")
    return choice

#called after every turn, changes between X and O
def playerChange(player):
    if player == "X": return "O"
    return "X"

#calls getValidCoord() for row and column, then makes sure that spot isn't taken
def humanTurn(player):
    print(player + "'s turn. Enter row first, then column. ")
    row = 0
    column = 0

    #checks spot to see if it is taken
    while True:
        row = getValidCoord()
        column = getValidCoord()
        if board1[row][column] == " ": break
        else: print("That spot is already taken. Enter different coordinates.")

    board1[row][column] = player

#handles the computer's turn in a 1-player game; row and column choices are randomly generated until a spot is found that isn't taken
def cpuTurn(player):
    print(player + "'s turn.")
    row = 0
    column = 0

    #checks if spot is taken
    while True:
        row = randint(0,2)
        column = randint(0,2)
        if board1[row][column] == " ": break

    board1[row][column] = player

#handles a single player game (alternating between user and cpu) through 9 turns; if no wins happen, a tie is called
def singleplayer():
    player = getValidPlayerChoice()
    for turn in range(9):
        if turn % 2 == 0:
            humanTurn(player)
        else: cpuTurn(player)
        copyBoards()
        printBoard()
        if checkWin(player):
            print(player + "'s win!")
            exit()
        player = playerChange(player)
    print("Tie.")

#handles a multiplayer game between two users for 9 turns; if no wins happen, a tie is called
def multiplayer():
    player = getValidPlayerChoice()
    for turn in range(9):
        humanTurn(player)
        copyBoards()
        printBoard()
        if checkWin(player): 
            print(player + "'s win!")
            exit()
        player = playerChange(player)
    print("Tie.")

def main():
    printBoard()
    gamemode = mode()
    if gamemode == 1:
        singleplayer()
    elif gamemode == 2:
        multiplayer()

main()