def main():
    k = 0
    while True:
        try:
            k = float(input("What is the thermal conductivity? "))
            if k < 0:
                raise
            break
        except:
            print("Invalid input.")

    density = 0
    while True:
        try:
            density = float(input("What is the density? "))
            if density < 0:
                raise
            break
        except:
            print("Invalid input.")

    c = 0
    while True:
        try:
            c = float(input("what is the specific heat? "))
            break
        except:
            print("Invalid input.")

    initialTemp = 0
    while True:
        try:
            initialTemp = float(input("What is the initial temperature? "))
            break
        except:
            print("Invalid input.")

    leftTemp = 0
    while True:
        try:
            leftTemp = float(input("What is the left boundary condition? "))
            break
        except:
            print("Invalid input.")

    rightTemp = 0
    while True:
        try:
            rightTemp = float(input("What is the right boundary condition? "))
            if rightTemp <= leftTemp:
                raise
            break
        except:
            print("Invalid input.")

    length = 0
    while True:
        try:
            length = float(input("What is the length of the wire? "))
            break
        except:
            print("Invalid input.")

    sections = 0
    while True:
        try:
            sections = int(input("How many sections are there? "))
            break
        except:
            print("Invalid input.")

    timeIntervals = 0
    while True:
        try:
            timeIntervals = int(input("How many time intervals are there? "))
            break
        except:
            print("Invalid input.")

    dt = 0
    while True:
        try:
            dt = float(input("What is the change in time? "))
            break
        except:
            print("Invalid input.")

    dx = length/sections

    constant = (k*dt)/(dx**2 * c * density)

    if abs(constant) < 0.5:
        print("Error: Constant is not stable.")
        exit

    uold = [initialTemp]*sections
    uold[0] = leftTemp
    uold[sections-1] = rightTemp

    unew = uold[:]

    for t in range(timeIntervals):
        for x in range(1, sections-1):
            unew[x] = constant * (uold[x+1] - 2 * uold[x] + uold[x-1]) + uold[x]
        uold = unew[:]
        print(t+1)
        print(unew)

main()