def letterCounts(names):
    letters = []
    counts = []
    for name in names:
        for char in name:
            if letters.count(char) == 0:
                letters.append(char)
                counts.append(0)
            counts[letters.index(char)] += 1
    return letters, counts

def lengthComparison(list1, list2):
    return len(list1) == len(list2)

def listSum(list):
    sum = 0
    for num in list:
        sum += num
    return sum

def listAvg(list):
    if len(list) > 0:
        return listSum(list)/len(list)

def sumComparison(list1, list2):
    return listSum(list1) != listSum(list2)

def commonNumbers(list1, list2):
    commonNums = []
    for num1 in list1:
        for num2 in list2:
            if num1 == num2:
                commonNums.append(num1)
    return commonNums

def main():
    namesList = []
    while True:
        try:
            name = input("Enter a name (must use only lowercase letters) or 'exit' to stop: ")
            if name == "exit":
                break
            for char in name:
                if ord(char) < ord("a") or ord(char) > 122:
                    raise
            namesList.append(name)
        except:
            print("Invalid input.")

    letters, counts = letterCounts(namesList)
    if len(namesList) > 0:
        print("Letters totals in your list of names:")
    for x in range(len(letters)):
        print(letters[x] + ": " + str(counts[x]))

    numList1 = []
    numList2 = []
    while True:
        try:
            number = int(input("Enter an integer for list 1 (non-integer to stop): "))
            numList1.append(number)
        except:
            break

    while True:
        try:
            number = int(input("Enter an integer for list 2 (non-integer to stop): "))
            numList2.append(number)
        except:
            break

    print("Are lists the same length? " + str(lengthComparison(numList1, numList2)))
    
    print("Sum of list 1: " + str(listSum(numList1)))
    print("Sum of list 2: " + str(listSum(numList2)))

    print("Average of list 1: " + str(listAvg(numList1)))
    print("Average of list 2: " + str(listAvg(numList2)))

    print("Are the sums of the lists different? " + str(sumComparison(numList1, numList2)))

    commonNums = commonNumbers(numList1, numList2)
    if len(commonNums) > 0:
        print("Common numbers between lists:")
        for num in commonNums:
            print(num)

main()