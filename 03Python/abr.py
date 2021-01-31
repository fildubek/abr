import pygame
from pygame.locals import *
import sys
import math
import numpy


width=1000
height=400
Color_screen=(0,0,0)
Color_lines=(255,255,255)
lives = 3
robot = 0
hit = 0
PI = math.pi


#draw robotHead

def robotHead(screen):
	pygame.draw.arc(screen, Color_lines, (850,70,100,90), PI/2, PI, 1)
	pygame.draw.arc(screen, Color_lines, (850,70,100,90), 0, PI/2, 1)
	pygame.draw.arc(screen, Color_lines, (850,75,100,90), PI/2, PI, 1)
	pygame.draw.arc(screen, Color_lines, (850,75,100,90), 0, PI/2, 1)
	#triangle
	pygame.draw.line(screen,Color_lines,(852,120),(900,40))
	pygame.draw.line(screen,Color_lines,(948,120),(900,40))
	pygame.draw.line(screen,Color_lines,(852,120),(948,120))
	#Nose
	pygame.draw.line(screen,Color_lines,(890,120),(890,145))
	pygame.draw.line(screen,Color_lines,(910,120),(910,145))
	pygame.draw.line(screen,Color_lines,(890,145),(910,145))
	#eyes
	pygame.draw.line(screen,Color_lines,(875,120),(875,133))
	pygame.draw.line(screen,Color_lines,(875,133),(890,133))
	pygame.draw.line(screen,Color_lines,(875,127),(890,127))
	pygame.draw.line(screen,Color_lines,(925,120),(925,133))
	pygame.draw.line(screen,Color_lines,(925,133),(910,133))
	pygame.draw.line(screen,Color_lines,(925,127),(910,127))
	#face lines
	pygame.draw.line(screen,Color_lines,(890,145),(865,160))
	pygame.draw.line(screen,Color_lines,(865,160),(854,120))
	pygame.draw.line(screen,Color_lines,(865,160),(865,180))
	pygame.draw.line(screen,Color_lines,(865,160),(850,180))
	pygame.draw.line(screen,Color_lines,(850,180),(850,120))
	pygame.draw.line(screen,Color_lines,(850,180),(950,180))
	pygame.draw.line(screen,Color_lines,(950,180),(950,120))
	pygame.draw.line(screen,Color_lines,(950,180),(935,160))
	pygame.draw.line(screen,Color_lines,(935,160),(910,145))
	pygame.draw.line(screen,Color_lines,(935,160),(935,180))
	pygame.draw.line(screen,Color_lines,(935,160),(946,120))
	#mouth
	pygame.draw.line(screen,Color_lines,(880,160),(920,160))
	pygame.draw.line(screen,Color_lines,(880,160),(880,170))
	pygame.draw.line(screen,Color_lines,(880,170),(920,170))
	pygame.draw.line(screen,Color_lines,(920,170),(920,160))
	pygame.draw.line(screen,Color_lines,(890,165),(910,165))
	#horns
	pygame.draw.line(screen,Color_lines,(850,150),(820,135))
	pygame.draw.line(screen,Color_lines,(820,135),(820,38))
	pygame.draw.line(screen,Color_lines,(820,38),(835,50))
	pygame.draw.line(screen,Color_lines,(835,50),(835,90))
	pygame.draw.line(screen,Color_lines,(835,90),(850,120))
	
	pygame.draw.line(screen,Color_lines,(950,150),(980,135))
	pygame.draw.line(screen,Color_lines,(980,135),(980,38))
	pygame.draw.line(screen,Color_lines,(980,38),(965,50))
	pygame.draw.line(screen,Color_lines,(965,50),(965,90))
	pygame.draw.line(screen,Color_lines,(965,90),(950,120))

# draw the energy bars based on the number of lives	
def energyBars(screen):
    x = 20
    font = pygame.font.Font('Trueno.otf', 24)
    text = font.render('Energy', True, (255, 255, 255))
    screen.blit(text, (845, 205))
    for i in range(0, lives):
        pygame.draw.line(screen,Color_lines,(840+x,250),(840+x,320),25)
        x +=40 
        
#draw the default elements that are same for all the evil Robots
def evilRobotTemplate(screen):
	#Head     
    pygame.draw.arc(screen, Color_lines, (300,70,200,90), PI/2, PI, 1)
    pygame.draw.arc(screen, Color_lines, (300,70,200,90), 0, PI/2, 1)
    pygame.draw.line(screen,Color_lines,(300,110),(300, 250))
    pygame.draw.line(screen,Color_lines,(500,110),(500, 250))
    pygame.draw.arc(screen, Color_lines, (300,200,200,90), PI, 0, 1)
    #Antenna
    pygame.draw.line(screen,Color_lines,(400,70),(400, 40))
    pygame.draw.circle(screen,Color_lines,(400,40), 5)
    
    #call evil robot draw
    if robot == 0:
        evilRobo1(screen)
    if robot == 1:
        evilRobo2(screen)
    if robot == 2:
        evilRobo3(screen)         
    

#draw evil Robot 1
def evilRobo1(screen):
	#Eye
    pygame.draw.arc(screen, Color_lines, (370,130,50,30), PI/2, PI, 1)
    pygame.draw.arc(screen, Color_lines, (370,130,50,30), PI, PI/2, 1)
    #Mouth
    pygame.draw.line(screen,Color_lines,(350,230),(440, 230))
	#weakness
    font = pygame.font.Font('Trueno.otf', 18)
    symbol = font.render('20B', True, (255, 255, 255))
    screen.blit(symbol, (380, 80))
	
#draw evil Robot 2
def evilRobo2(screen):
	#Eyes
    pygame.draw.arc(screen, Color_lines, (340,130,50,30), PI/2, PI, 1)
    pygame.draw.arc(screen, Color_lines, (340,130,50,30), PI, PI/2, 1)
    pygame.draw.arc(screen, Color_lines, (420,130,50,30), PI/2, PI, 1)
    pygame.draw.arc(screen, Color_lines, (420,130,50,30), PI, PI/2, 1)
    #Mouth
    pygame.draw.line(screen,Color_lines,(340,230),(460, 230))
    pygame.draw.line(screen,Color_lines,(340,250),(460, 250))
    pygame.draw.line(screen,Color_lines,(340,230),(340, 250))
    pygame.draw.line(screen,Color_lines,(460,230),(460, 250))
	#weakness
    font = pygame.font.Font('Trueno.otf', 18)
    symbol = font.render('. . .  _  _', True, (255, 255, 255))
    screen.blit(symbol, (380, 80))	
    
#draw evil Robot 3
def evilRobo3(screen):
	#Eyes
    pygame.draw.arc(screen, Color_lines, (340,130,50,30), PI/2, PI, 1)
    pygame.draw.arc(screen, Color_lines, (340,130,50,30), PI, PI/2, 1)
    pygame.draw.arc(screen, Color_lines, (420,130,50,30), PI/2, PI, 1)
    pygame.draw.arc(screen, Color_lines, (420,130,50,30), PI, PI/2, 1)
    pygame.draw.circle(screen,Color_lines,(365,145), 5)
    pygame.draw.circle(screen,Color_lines,(445,145), 5)
    #Mouth
    pygame.draw.line(screen,Color_lines,(340,230),(460, 230))
    pygame.draw.line(screen,Color_lines,(340,250),(460, 250))
    pygame.draw.line(screen,Color_lines,(340,230),(340, 250))
    pygame.draw.line(screen,Color_lines,(460,230),(460, 250))
    for i in range(0,120,10):
        pygame.draw.line(screen,Color_lines,(350+i,230),(350+i, 250))
    
	#weakness
    font = pygame.font.Font('Trueno.otf', 18)
    symbol = font.render('00000100', True, (255, 255, 255))
    screen.blit(symbol, (360, 80))	    
    

#draw Mountain Ranage
def mountainRange(screen):
     pygame.draw.line(screen,Color_lines,(0,120),(65, 65))
     pygame.draw.line(screen,Color_lines,(65,65),(120, 35))
     pygame.draw.line(screen,Color_lines,(120,35),(180, 35))
     pygame.draw.line(screen,Color_lines,(180,35),(230, 5))
     pygame.draw.line(screen,Color_lines,(230,5),(320, 80))
     pygame.draw.line(screen,Color_lines,(320,80),(380, 25))
     pygame.draw.line(screen,Color_lines,(380,25),(540, 25))
     pygame.draw.line(screen,Color_lines,(540,25),(600, 90))
     pygame.draw.line(screen,Color_lines,(600,90),(700, 90))
     pygame.draw.line(screen,Color_lines,(700,90),(800, 30))
     
     
# If you choose the corect missile  
def success(screen, font, sound):
    global robot
    global hit
    msg = font.render('Success,', True, (255, 255, 255))
    msg2 = font.render('Direct hit with correct missile!', True, (255, 255, 255))  
    screen.blit(msg,(530, 160))
    screen.blit(msg2,(530, 180))
    pygame.display.flip()  
    sound.play()
    if robot < 2:
        robot +=1
        pygame.time.wait(3000)
        hit = 0   
    else:
        msg3= font.render('Victory', True, (255, 255, 255))
        msg4 = font.render('All enemies in the area were defeated', True, (255, 255, 255))      
        msg5 = font.render('Mission 2 Completed', True, (255, 255, 255))
        msg6 = font.render('Receiving update from headquaters', True, (255, 255, 255))
        msg7 = font.render('READY FOR NEXT MISSION', True, (255, 255, 255))
        screen.blit(msg3,(530, 220))
        screen.blit(msg4,(530, 240))
        screen.blit(msg5,(530, 260))
        screen.blit(msg6,(530, 280))
        screen.blit(msg7,(530, 300))
        pygame.display.flip()
        pygame.time.wait(6000) 
        sys.exit(0)

# If you choose the wrong missile     
def failed(screen, font, sound, frequency_l, frequency_r):
     global lives
     global hit
     frequency_l = 50
     frequency_r = 10     
     msg = font.render('Wrong Missile!', True, (255, 255, 255))
     msg2 = font.render('You got hit by an counter attack!', True, (255, 255, 255))
     screen.blit(msg,(530, 160))
     screen.blit(msg2,(530, 180))
     pygame.display.flip()
     sound.play()
     if lives > 0:
        lives -=1
        pygame.time.wait(3000)
        hit = 0
     else:
        msg3 = font.render('You got hit too many times', True, (255, 255, 255))
        msg4 = font.render('you are dead!', True, (255, 255, 255))
        screen.blit(msg3,(530, 220))
        screen.blit(msg4,(530, 240))
        pygame.display.flip()
        pygame.time.wait(5000) 
        sys.exit(0)
		 		 
     
    
#draw game Arena		    
def arena(screen, font, events, sound, frequency_l, frequency_r):
    pygame.draw.line(screen,Color_lines,(800,0),(800,400))
    pygame.draw.line(screen,Color_lines,(800,200),(1000,200))
    robotHead(screen)
    energyBars(screen)
    evilRobotTemplate(screen)
    mountainRange(screen)
    global hit
    if robot == 0:
        if events.type == pygame.KEYDOWN:
           if events.key == pygame.K_3:
              hit = 1
           if events.key == pygame.K_1 or events.key == pygame.K_2 or events.key == pygame.K_4 or events.key == pygame.K_5 or events.key == pygame.K_6:
               hit = -1
    if robot == 1:
        if events.type == pygame.KEYDOWN:
           if events.key == pygame.K_4:
              hit = 1
           if events.key == pygame.K_1 or events.key == pygame.K_2 or events.key == pygame.K_3 or events.key == pygame.K_5 or events.key == pygame.K_6:
               hit = -1
    if robot == 2:
        if events.type == pygame.KEYDOWN:
           if events.key == pygame.K_6:
              hit = 1
           if events.key == pygame.K_1 or events.key == pygame.K_2 or events.key == pygame.K_4 or events.key == pygame.K_5 or events.key == pygame.K_3:
               hit = -1                                           
    options = font.render('1. Missile 432, | 2. Missile 900 | 3.Missile 523 | 4. Missile 3 | 5.Missile 900 | 6. Missile 4', True, (255, 255, 255))
    screen.blit(options,(100, 340))
    info =  font.render('Enemy view zoom factor 10x', True, (255, 255, 255))
    screen.blit(info,(300, 310))
    if hit == 1:
        success(screen, font, sound)
    if hit == -1:
        failed(screen, font, sound, frequency_l, frequency_r)
		
def main():
    play = False
    bits = 16
    pygame.mixer.pre_init(44100, -bits, 2)
    pygame.init()
    screen=pygame.display.set_mode((width,height), pygame.HWSURFACE | pygame.DOUBLEBUF)
    #sound
    duration = 1.0 
    frequency_l = 140
    frequency_r = 250
    sample_rate = 44100
    n_samples = int(round(duration*sample_rate))
    buf = numpy.zeros((n_samples, 2), dtype = numpy.int16)
    max_sample = 2**(bits - 1) - 1
    for s in range(n_samples):
       t = float(s)/sample_rate
       buf[s][0] = int(round(max_sample*math.sin(2*math.pi*frequency_l*t)))
       buf[s][1] = int(round(max_sample*0.5*math.sin(2*math.pi*frequency_r*t)))
    sound = pygame.sndarray.make_sound(buf)
    #graphics and fonts   
    screen.fill(Color_screen)
    font = pygame.font.Font('Trueno.otf', 14)
    mainText = font.render('After going into hidding, mankind did not give up.', True, (255, 255, 255))
    mainText2 = font.render('We studied the defeated Robots and discovered weaknesses.', True, (255, 255, 255))
    screen.blit(mainText, (250, 340))
    screen.blit(mainText2, (250, 360))
    pygame.display.flip()
    while True:
        for events in pygame.event.get():
            if events.type == pygame.KEYDOWN:
               if events.key == pygame.K_RETURN:
                  play = True
            if play == True:
               screen.fill(Color_screen)
               arena(screen, font, events, sound, frequency_l, frequency_r)
               pygame.display.flip()
            if events.type == QUIT:
               sys.exit(0)
main()
