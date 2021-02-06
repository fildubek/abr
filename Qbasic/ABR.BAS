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
    REM DRAW ROBOT HEAD
    LOCATE 22, 2
    PRINT "OPTIONS PLACEMENT"
    SLEEP 1
LOOP UNTIL INKEY$ = CHR$(27)



