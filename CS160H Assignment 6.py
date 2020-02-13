def f1(x):
    return 10*(x**2)
def f2(x):
    return 2*(x**2)-5
def f3(x):
    return x+20

def summation(f, a, b):
    sum = 0
    for x in range(a, b+1):
        sum += f(x)
    return sum
        
def integration(f, a, b, method, n):
    width = (b-a)/n
    sum = 0
    if method == "t":
        for x in range(n):
            sum += width*((f(a+(x*width))+f(a+((x+1)*width)))/2)
    elif method == "r":
        for x in range(n):
            sum += width*f(a+(x*width))
    return sum


print("Functions:")
print("f1(x)=10x^2")
print("f2(x)=2x^2-5")
print("f3(x)=x+20")

cont = "y"
while cont == "y":
    function = 0
    while True:
        try:
            function = int(input("Which function would you like to use? 1 for f1, 2 for f2, 3 for f3: "))
            if function > 3 or function < 1:
                raise
            break
        except:
            print("Invalid input.")

    calculation = ""
    while True:
        try:
            calculation = str(input("Would you like to (i)ntegrate or take a (s)ummation? "))
            if calculation != "i" and calculation != "s":
                raise
            break
        except:
            print("Invalid input.")

    steps = 0
    if calculation == "i":
        while True:
            try:
                steps = int(input("How many rectangles or trapezoids would you like to use? (must be at least 1): "))
                if steps < 1:
                    raise
                break
            except:
                print("Invalid input.")

    rectOrTrap = ""
    if calculation == "i":
        while True:
            try:
                rectOrTrap = str(input("Would you like to use the (r)ectangle or (t)rapezoid method? "))
                if rectOrTrap != "r" and rectOrTrap != "t":
                    raise
                break
            except:
                print("Invalid input.")

    lower = 0
    while True:
        try:
            lower = int(input("Enter lower limit as an integer: "))
            break
        except:
            print("Invalid input.")

    upper = 0
    while True:
        try:
            upper = int(input("Enter upper limit as an integer (must be greater than lower limit): "))
            if upper <= lower:
                raise
            break
        except:
            print("Invalid input.")

    if calculation == "s":
        if function == 1:
            print(str(summation(f1, lower, upper)))
        elif function == 2:
            print(str(summation(f2, lower, upper)))
        elif function == 3:
            print(str(summation(f3, lower, upper)))
    elif calculation == "i":
        if function == 1:
            print(str(integration(f1, lower, upper, rectOrTrap, steps)))
        elif function == 2:
            print(str(integration(f2, lower, upper, rectOrTrap, steps)))
        elif function == 3:
            print(str(integration(f3, lower, upper, rectOrTrap, steps)))

    cont = str(input("Would you like to continue? y for yes: "))