import turtle
import math
import random

def b(myTurtle):
    myTurtle.setheading(270)
    myTurtle.forward(200)
    myTurtle.left(90)
    myTurtle.forward(120)
    myTurtle.left(90)
    myTurtle.forward(100)
    myTurtle.left(90)
    myTurtle.forward(120)
    myTurtle.left(180)
    myTurtle.forward(100)
    myTurtle.left(90)
    myTurtle.forward(100)
    myTurtle.left(90)
    myTurtle.forward(100)

def e(myTurtle):
    myTurtle.setheading(0)
    myTurtle.forward(100)
    myTurtle.right(180)
    myTurtle.forward(100)
    myTurtle.left(90)
    myTurtle.forward(100)
    myTurtle.left(90)
    myTurtle.forward(100)
    myTurtle.right(180)
    myTurtle.forward(100)
    myTurtle.left(90)
    myTurtle.forward(100)
    myTurtle.left(90)
    myTurtle.forward(100)


def n(myTurtle):
    myTurtle.setheading(270)
    myTurtle.forward(200)
    myTurtle.right(180)
    myTurtle.forward(200)
    myTurtle.right(150)
    myTurtle.forward(200*(2/(math.sqrt(3))))
    myTurtle.left(150)
    myTurtle.forward(200)

def t(myTurtle):
    myTurtle.setheading(0)
    myTurtle.forward(120)
    myTurtle.right(180)
    myTurtle.forward(60)
    myTurtle.left(90)
    myTurtle.forward(200)

def r(myTurtle):
    myTurtle.setheading(270)
    myTurtle.forward(200)
    myTurtle.right(180)
    myTurtle.forward(200)
    myTurtle.right(90)
    myTurtle.forward(100)
    myTurtle.right(90)
    myTurtle.forward(100)
    myTurtle.right(90)
    myTurtle.forward(100)
    myTurtle.left(135)
    myTurtle.forward(100*math.sqrt(2))

def u(myTurtle):
    myTurtle.setheading(270)
    myTurtle.forward(200)
    myTurtle.left(90)
    myTurtle.forward(100)
    myTurtle.left(90)
    myTurtle.forward(200)

def word1(myTurtle):
    myTurtle.clear()
    myTurtle.penup()
    myTurtle.setposition(-150,100)
    myTurtle.pendown()
    b(myTurtle)
    myTurtle.penup()
    myTurtle.setposition(0,100)
    myTurtle.pendown()
    e(myTurtle)
    myTurtle.penup()
    myTurtle.setposition(150,100)
    myTurtle.pendown()
    n(myTurtle)

def word2(myTurtle):
    myTurtle.clear()
    myTurtle.penup()
    myTurtle.setposition(-150,100)
    myTurtle.pendown()
    n(myTurtle)
    myTurtle.penup()
    myTurtle.setposition(0,100)
    myTurtle.pendown()
    e(myTurtle)
    myTurtle.penup()
    myTurtle.setposition(150,100)
    myTurtle.pendown()
    t(myTurtle)

def word3(myTurtle):
    myTurtle.clear()
    myTurtle.penup()
    myTurtle.setposition(-150,100)
    myTurtle.pendown()
    r(myTurtle)
    myTurtle.penup()
    myTurtle.setposition(0,100)
    myTurtle.pendown()
    u(myTurtle)
    myTurtle.penup()
    myTurtle.setposition(150,100)
    myTurtle.pendown()
    n(myTurtle)

def word4(myTurtle):
    myTurtle.clear()
    myTurtle.penup()
    myTurtle.setposition(-150,100)
    myTurtle.pendown()
    b(myTurtle)
    myTurtle.penup()
    myTurtle.setposition(0,100)
    myTurtle.pendown()
    u(myTurtle)
    myTurtle.penup()
    myTurtle.setposition(150,100)
    myTurtle.pendown()
    t(myTurtle)

def main():
    myTurtle = turtle.Turtle()

    words = 0
    while True:
        try:
	        words = int(input("How many words would you like to print? "))
	        if words < 1:
		        raise
	        break
        except:
	        print("Invalid input.")
    for x in range(words):
	    word = random.randint(1,4)
	    if word == 1:
		    word1(myTurtle)
	    elif word == 2:
		    word2(myTurtle)
	    elif word == 3:
		    word3(myTurtle)
	    elif word == 4:
		    word4(myTurtle)


if __name__ == '__main__':
    main()
else:
    pass