CLS
SCREEN 2
CLS
lives = 3
robot = 0
REM Loop through the story message until enter is pressed
DO
    CLS
    PRINT "We managed to build our own robot, so now we can fight back"
    PRINT " "
    PRINT "Press ENTER to continue"
    SLEEP 1
LOOP UNTIL INKEY$ = CHR$(13)
DO
    REM DRAW EVERYTHING IN LOOP
    CLS
    REM DRAW GAME SCREEN
    LINE (0, 0)-(610, 180), , B
    LINE (530, 0)-(530, 180)
    LINE (530, 70)-(610, 70), , B
    REM CALL ROBOT HEAD
    robotHead
    LOCATE 22, 2
    PRINT "OPTIONS PLACEMENT"
    SLEEP 1
LOOP UNTIL INKEY$ = CHR$(27)




SUB robotHead
    LINE (550, 30)-(590, 30)
    LINE (550, 30)-(570, 15)
    LINE (590, 30)-(570, 15)
    LINE (565, 30)-(565, 38)
    REM EYES AND NOSE
    LINE (575, 30)-(575, 38)
    LINE (565, 38)-(575, 38)
    LINE (570, 30)-(570, 38)
    LINE (558, 30)-(558, 33)
    LINE (558, 33)-(565, 33)
    LINE (582, 30)-(582, 33)
    LINE (582, 33)-(575, 33)
    REM FACE LINES
    LINE (565, 38)-(555, 42)
    LINE (575, 38)-(585, 42)

    LINE (555, 42)-(555, 47)
    LINE (585, 42)-(585, 47)
    REM MOUTH
    LINE (565, 43)-(575, 43)
    LINE (565, 45)-(575, 45)
    LINE (565, 43)-(565, 45)
    LINE (575, 43)-(575, 45)
    REM FACE LINES
    LINE (555, 47)-(585, 47)
    LINE (555, 47)-(550, 47)
    LINE (575, 47)-(590, 47)
    LINE (550, 47)-(555, 42)
    LINE (590, 47)-(585, 42)

    LINE (550, 47)-(550, 30)
    LINE (590, 47)-(590, 30)

    LINE (552, 30)-(555, 42)
    LINE (588, 30)-(585, 42)




END SUB
