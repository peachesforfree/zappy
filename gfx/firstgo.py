from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLE import *
from OpenGL.GLUT import *
import pygame
from pygame.locals import *
import sys

#def game_loop:
#   while still connected to server
#       parse commands into queue
#           possible commands pick up, die, turn, move foreward, broadcast, drop
#       set players move location/action
#
#
#
#

class Game:
    #LOC is current location
    loc_x = 0
    loc_y = 0
    loc_z = 0
    #MOVE is the gain in speed goin that direction
    x_move = 0
    y_move = 0
    z_move = 0
    #BOARD game baord width and hight
    board_x = 0
    board_y = 0
    game_speed = 0
    #direction speed, how fast to move foreward
    direction_speed = 2
    def __init__(self, bx, by, sp):
        self.board_x = bx
        self.board_y = by
        self.game_speed = sp
    
    def Translate(x, y, z):
        trans_x = x
        trans_y = y
        trans_z = z

def Keyboard_Event(game, event):
    if event.type == pygame.QUIT or (event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE):
        pygame.quit()
        quit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                game.x_move = game.direction_speed
            if event.key == pygame.K_RIGHT:
                game.x_move = -1 * game.direction_speed
            if event.key == pygame.K_UP:
                game.y_move = -1 * game.direction_speed
            if event.key == pygame.K_DOWN:
                game.y_move = game.direction_speed

    if event.type == pygame.KEYUP:
        if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
            game.x_move = 0
        if event.key == pygame.K_UP or event.key == pygame.K_DOWN:
            game.y_move = 0

def Mouse_Event(game, event):
    if event.type == pygame.MOUSEBUTTONDOWN:
        print event.button
        if event.button == 4:
            game.Translate(0, 0, .25)
        if event.button == 5:
            game.Translate(0, 0, -.25)

def display_start():
    #start window display with ip entry
    print "stuff"

class Window:
    max_distance = 100
    window_x = 0
    window_y = 0
    def __init__(self, game, win_x = 800, win_y = 600):
        pygame.init()
        self.window_x = win_x
        self.window_y = win_y
        pygame.display.set_mode((self.window_x, self.window_y), DOUBLEBUF|OPENGL)
        gluPerspective(60, (self.window_x/self.window_y), 0.1, self.max_distance)
        glTranslatef(0, 0, -40)

def init_game(x, y, speed):
    #Initialize game, window, and connection
    connected = False
    game = Game(x, y, 5)
    window = Window(game, 1600, 1200)


    #BEWLOW: User input, clicks, buttons, and typing
    while True:
        for event in pygame.event.get():
            Keyboard_Event(game, event)
            Mouse_Event(game, event)          
        # if connected == False #not connection:
        #     connected = display_start()
            
            
            #init game board
                #make resources
            #init players
    
        # game logic and rendering takes place here
    


    #Below: Rendering logic and object manipulation
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
    glTranslatef(game.Translate.trans_x, game.Translate.trans_y, game.Translate.trans_z)
    
    pygame.display.flip()




def main():
    del sys.argv[0]
    if len(sys.argv) == 3:
        init_game(int(sys.argv[0]), int(sys.argv[1]), int(sys.argv[2]))
    pygame.quit()
    quit()

if __name__== "__main__":
  main()