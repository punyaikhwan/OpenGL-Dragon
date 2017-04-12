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
YELLOW = (198,152,57)
 
PI = 3.141592653
 
# Set the height and width of the screen
size = (600, 400)
screen = pygame.display.set_mode(size)
 
# Loop until the user clicks the close button.
done = False
clock = pygame.time.Clock()

# Listof point
pointDragon = [
    [34,41],
    [51,47],
    [61,55],
    [74,65],
    [84,78],
    [93,92],
    [101,110],
    [105,123],
    [108,132],
    [117,120],
    [118,145],
    [128,159],
    [140,169],
    [153,177],
    [170,189],
    [180,196],
    [176,170],
    [172,159],
    [164,145],
    [159,133],
    [157,118],
    [165,105],
    [170,97],
    [185,89],
    [189,80],
    [178,72],
    [174,59],
    [174,45],
    [178,29],
    [184,18],
    [195,5],
    [195,17],
    [195,29],
    [200,42],
    [205,51],
    [217,45],
    [230,47],
    [241,54],
    [248,67],
    [258,57],
    [270,55],
    [277,70],
    [289,66],
    [298,60],
    [307,51],
    [303,68],
    [296,78],
    [284,89],
    [273,93],
    [272,104],
    [270,114],
    [281,124],
    [289,137],
    [283,148],
    [270,162],
    [258,167],
    [246,166],
    [244,178],
    [239,188],
    [229,191],
    [216,187],
    [202,185],
    [203,194],
    [207,203],
    [220,202],
    [234,199],
    [246,195],
    [257,189],
    [269,182],
    [282,169],
    [291,148],
    [291,162],
    [298,151],
    [307,137],
    [318,116],
    [327,118],
    [337,110],
    [351,102],

    [365,96],
    [375,93],
    [369,103],
    [365,119],
    [364,134],
    [365,148],
    [367,163],
    [371,174],
    [378,185],
    [370,189],
    [359,197],
    [347,208],
    [340,222],
    [337,237],
    [336,254],
    [319,254],
    [300,257],
    [286,262],
    [288,270],
    [277,266],
    [276,274],
    [269,271],
    [262,275],
    [256,265],
    [250,257],
    [234,253],
    [237,265],
    [249,273],
    [251,287],
    [263,286],
    [273,293],
    [276,308],
    [273,307],
    [272,349],
    [270,344],
    [283,346],
    [285,358],
    [278,368],
    [271,370],
    [245,369],
    [217,366],
    [205,367],
    [205,379],
    [195,389],
    [184,390], #
    [170,392],
    [157,384],
    [145,372],
    [134,375],
    [128,366],
    [135,356],
    [144,349],
    [138,343],
    [127,343],
    [114,349],
    [100,357],
    [87,364],
    [71,365],
    [58,358],
    [51,343],
    [51,329],
    [48,311],
    [39,316],
    [28,312],
    [24,299],
    [29,283],
    [31,268],
    [43,275],
    [58,281],
    [65,292],
    [61,304],
    [63,311],
    [73,304],
    [71,323],
    [79,331],
    [83,335],
    [84,317],
    [95,322],
    [101,315],
    [101,311],
    [107,298],
    [121,305],
    [132,305],
    [131,291],
    [135,279],
    [141,270],
    [146,262],
    [139,254],
    [134,247],
    [126,250],
    [117,259],
    [104,246],
    [91,238],
    [81,233],
    [67,232],
    [68,215],
    [66,202],
    [62,190],
    [54,180],
    [45,171],
    [30,163],
    [40,143],
    [43,129],
    [44,116],
    [46,100],
    [48,85],
    [46,70],
    [43,57]
    ]

pointMouth = [
    [180,122],
    [190,132],
    [197,140],
    [208,150],
    [219,156],
    [229,160],
    [238,164],
    [235,174],
    [224,175],
    [215,174],
    [205,172],
    [198,165],
    [196,153],
    [194,152]
    ]
    
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
    pygame.draw.polygon(screen, WHITE, pointDragon, 0)
    pygame.draw.polygon(screen, YELLOW, pointMouth, 0)
    '''pygame.draw.line(screen, WHITE, [82, 14], [291, 44], 1)
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
    pygame.draw.line(screen, WHITE, [335, 125], [315, 76], 1)'''

    # Go ahead and update the screen with what we've drawn.
    # This MUST happen after all the other drawing commands.
    pygame.display.flip()
 
    # This limits the while loop to a max of 60 times per second.
    # Leave this out and we will use all CPU we can.
    clock.tick(60)
 
# Be IDLE friendly
pygame.quit()

