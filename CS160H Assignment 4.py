
def programmerCalculator():
    decimal = int(input("Enter a decimal number greater or equal to zero: "))
    while decimal < 0:
        decimal = int(input("Invalid input. Enter a decimal number greater than or equal to zero: "))
    
    if decimal == 0:
        print("Zero in binary is zero... duh!")
        return

    bitFound = False
    bits = 0
    while bitFound == False:
        if 2**(bits) > decimal:
            bitFound = True
        else:
            bits += 1

    binary = []
    for x in range(bits):
        binary.append(0)
        #print("appended")
        #print(len(binary))

    quotient = decimal
    for x in range(bits):
        binary[bits-x-1] = quotient % 2
        quotient = int(quotient/2)

    binaryString = ""
    for x in range(bits):
        binaryString = binaryString + str(binary[x])

    print(str(decimal) + " in binary is " + binaryString)

def scientificCalculator():
    operator = str(input("Which operator would you like to use, +, -, *, /, or ** ? "))
    while operator != "+" and operator != "-" and operator != "*" and operator != "/" and operator != "**":
        operator = str(input("Invalid input. Which operator would you like to use, +, -, *, /, or ** ? "))

    firstNum = float(input("Enter first number (can be float): "))
    secondNum = float(input("Enter second number (can be float): "))

    solution = 0

    if operator == "+":
        solution = firstNum+secondNum
    elif operator == "-":
        solution = firstNum-secondNum
    elif operator == "*":
        solution = firstNum*secondNum
    elif operator == "/":
        solution = firstNum/secondNum
    elif operator == "**":
        solution = firstNum**secondNum

    print(str(firstNum) + operator + str(secondNum) + "=" + str(solution))
        
wantsToContinue = "y"
while wantsToContinue == "y":
    whichCalc = str(input("Which calculator would you like to use, (p)rogrammer or (s)cientific? "))
    while whichCalc != "p" and whichCalc != "s":
        whichCalc = str(input("Invalid input. Which calculator would you like to use, (p)rogrammer or (s)cientific? "))

    if whichCalc == "p":
        repeatProg = "y"
        while repeatProg == "y":
            programmerCalculator()
            repeatProg = str(input("Would you like to make another conversion with this calculator? y/n: "))
        

    elif whichCalc == "s":
        repeatSci = "y"
        while repeatSci == "y":
            scientificCalculator()
            repeatSci = str(input("Would you like to make another calculation with this calculator? y/n: "))
    
    wantsToContinue = str(input("Would you like to use a different calculator? y/n: "))