youChosePoorly = "Your indecisiveness will not be tolerated. You have failed miserably, challenger."

red_or_blue = str(input("Welcome to the Maze, challenger. Would you like to enter through the (blue) door or the (red) door? "))

if red_or_blue == "red":
    left_or_right = str(input("You open the red door and find a small room with two glasses on a table. The (left) one is filled with a mirror-like liquid and the (right) one is filled with a concoction black as night. You must drink from one of the glasses, but which one? "))

    if left_or_right == "left":
        print("You take a draw from the left glass. Reality collapses in on itself and you are consumed by the void left behind. Thank you for participating, challenger.")

    elif left_or_right == "right":
        print("You take a draw from the right glass. Your nightmare fades away and you wake in a bright room. You have succeeded, challenger. Enjoy your victory now before you are tested again.")
        
    else:
        print(youChosePoorly)

elif red_or_blue == "blue":
    climb_or_repel = str(input("You open the blue door and are presented with a rope and a wall that seems to continue forever in every direction. Do you (climb) up the wall or (repel) to find the bottom? "))

    if climb_or_repel == "climb":
        walk_or_leap = str(input("You climb until your arms and legs nearly give out, but you reach the top of the wall. Do you (walk) along the top towards the faint light in the distance or do you take a (leap) of faith over the other side towards the whispers in the dark below? "))

        if walk_or_leap == "walk":
            print("You walk along the wall until the light becomes a searing beam that rips through you as if you weren’t there at all. Thank you for participating, challenger.")

        elif walk_or_leap == "leap":
            print("You take the leap and after falling for what seems like an eternity, your descent is halted by an updraft that carries you to a lone platform. You have done well, challenger. The next stage awaits.")

        else:
            print(youChosePoorly)
    
    elif climb_or_repel == "repel":
        print("You repel down the wall but never reach the bottom. The rope is cut by an unseen assailant from above and you fall into the void. Thank you for participating, challenger.")

    else:
        print(youChosePoorly)

else:
    print(youChosePoorly)