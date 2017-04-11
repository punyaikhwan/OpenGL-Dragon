# Import a library of functions called 'pygame'
import pygame
 
# Initialize the game engine
pygame.init()
 
# Define some colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
BLUE = (0, 0, 255)
GREEN = (0, 255, 0)
RED = (255, 0, 0)
 
PI = 3.141592653
 
# Set the height and width of the screen
size = (600, 400)
screen = pygame.display.set_mode(size)
 
# Loop until the user clicks the close button.
done = False
clock = pygame.time.Clock()
 
# Loop as long as done == False
while not done:
 
    for event in pygame.event.get():  # User did something
        if event.type == pygame.QUIT:  # If user clicked close
            done = True  # Flag that we are done so we exit this loop
 
    # All drawing code happens after the for loop and but
    # inside the main while not done loop.
 
    # Clear the screen and set the screen background
    screen.fill(RED)

    #draw dragon
    pygame.draw.line(screen, WHITE, [82, 14], [291, 44], 1)
    pygame.draw.line(screen, WHITE, [82, 14], [278, 47], 1)
    pygame.draw.line(screen, WHITE, [79, 69], [278, 47], 1)
    pygame.draw.line(screen, WHITE, [79, 69], [279, 60], 1)
    pygame.draw.line(screen, WHITE, [115, 120], [279, 60], 1)
    pygame.draw.line(screen, WHITE, [115, 120], [286, 76], 1)
    pygame.draw.line(screen, WHITE, [286, 76], [297, 97], 1)
    pygame.draw.arc(screen, WHITE, [259, 97, (369-259), (204-97)], PI/1.7, 3*PI/2, 1)
    pygame.draw.line(screen, WHITE, [314, 202], [397, 219], 1)
    pygame.draw.line(screen, WHITE, [397, 219], [496, 339], 1)
    pygame.draw.line(screen, WHITE, [496, 339], [440, 240], 1)
    pygame.draw.line(screen, WHITE, [440, 240], [550, 300], 1)
    pygame.draw.line(screen, WHITE, [550, 300], [420, 195], 1)
    pygame.draw.arc(screen, WHITE, [320, 97, 2*(420-315), (200-97)], PI/1.2, 3*PI/2, 1)
    pygame.draw.line(screen, WHITE, [335, 125], [315, 76], 1)

    # Go ahead and update the screen with what we've drawn.
    # This MUST happen after all the other drawing commands.
    pygame.display.flip()
 
    # This limits the while loop to a max of 60 times per second.
    # Leave this out and we will use all CPU we can.
    clock.tick(60)
 
# Be IDLE friendly
pygame.quit()

