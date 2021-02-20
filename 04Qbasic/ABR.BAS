CLS
SCREEN 2
CLS
lives = 3
robot = 0
missile = 0
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
    BEEP
    REM DRAW GAME SCREEN
    LINE (0, 0)-(610, 180), , B
    LINE (530, 0)-(530, 180)
    LINE (530, 70)-(610, 70), , B
    REM WRITE INFO TEXT
    LOCATE 3, 45
    PRINT "AREA LEADER"
    REM CALL ROBOT HEAD
    robotHead
    REM CALL LIVEBRARS
    liveBars (lives)
    REM CALL GRID
    grid
    REM CALL EVIL ROBOT BOSS
    robotBoss (robot)
    REM CALL MISSILE OPTIONS
    missile = missileOptions
    IF robot = 0 THEN
        IF missile = 5 THEN
            robot = success(robot)
        ELSE
            lives = failure(lives)
        END IF

    ELSEIF robot = 1 THEN
        IF missile = 2 THEN
            robot = success(robot)
        ELSE
            lives = failure(lives)
        END IF
    ELSE
        IF missile = 6 THEN
            robot = success(robot)
        ELSE
            lives = failure(lives)
        END IF
    END IF

    SLEEP 5

LOOP UNTIL INKEY$ = CHR$(27)


FUNCTION missileOptions
    LOCATE 20, 4
    PRINT "1. MISSILE RED | 2. MISSILE BLACK | 3. MISSILE SILVER"
    LOCATE 21, 4
    PRINT "4. MISSILE GREEN | 5. MISSILE BLUE | 6. MISSILE YELLOW"
    LOCATE 22, 4
    INPUT "Enter a Missile: ", missile
    missileOptions = missile
END FUNCTION


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
    REM HORNS
    LINE (550, 40)-(537, 24)
    LINE (537, 24)-(537, 15)
    LINE (537, 15)-(546, 20)
    LINE (546, 20)-(546, 24)
    LINE (546, 24)-(550, 30)

    LINE (590, 40)-(603, 24)
    LINE (603, 24)-(603, 15)
    LINE (603, 15)-(594, 20)
    LINE (594, 20)-(594, 24)
    LINE (594, 24)-(590, 30)
END SUB

SUB liveBars (lives)
    x = 0
    FOR i = 0 TO lives - 1
        LOCATE 12, 70
        PRINT "LIVES"
        LINE (545 + x, 110)-(555 + x, 150), , B
        PAINT (546 + x, 111), 3, 3
        x = x + 20
    NEXT i
END SUB

SUB grid
    x = 0
    x2 = 0
    FOR i = 0 TO 10
        LINE (10 + x, 150)-(30 + x - x2, 75)
        LINE (490 - x, 150)-(470 - x + x2, 75)
        x = x + 20
        x2 = x2 + 1
    NEXT i

    LINE (230, 150)-(230, 75)
    LINE (250, 150)-(250, 75)
    LINE (270, 150)-(270, 75)

    x = 0
    y = 0
    FOR j = 0 TO 4
        LINE (10 + x, 150 - y)-(490 - x, 150 - y)
        x = x + 5
        y = y + 19

    NEXT j

END SUB

SUB robotBoss (robot)

    IF robot = 0 THEN
        LOCATE 5, 4
        PRINT "WEAKNESS DETECTED"
        LOCATE 6, 4
        PRINT "0, 0, 255"
    END IF

    IF robot = 1 THEN
        LOCATE 5, 4
        PRINT "NEW WEAKNESS DETECTED"
        LOCATE 6, 4
        PRINT "#000000"
    END IF
    IF robot = 2 THEN
        LOCATE 5, 4
        PRINT "NEW WEAKNESS DETECTED"
        LOCATE 6, 4
        PRINT "0%, 0%, 100%, 0%"
    END IF



    LINE (200, 10)-(240, 5)
    LINE -(280, 10)
    LINE -(280, 30)
    LINE -(240, 25)
    LINE -(200, 30)
    LINE -(200, 10)
    LINE (200, 30)-(200, 50)
    LINE -(220, 55)
    LINE -(220, 70)
    LINE (280, 30)-(280, 50)
    LINE -(260, 55)
    LINE -(260, 70)
    LINE (210, 35)-(225, 35)
    LINE -(218, 40)
    LINE -(210, 35)
    LINE (270, 35)-(255, 35)
    LINE -(262, 40)
    LINE -(270, 35)
    LINE (235, 30)-(235, 45)
    LINE -(245, 45)
    LINE -(245, 30)
    REM FACE LINES
    LINE (235, 45)-(230, 55)
    LINE -(200, 40)
    LINE (230, 55)-(230, 70)
    LINE (245, 45)-(250, 55)
    LINE -(280, 40)
    LINE (250, 55)-(250, 70)
    REM MOUTH
    LINE (233, 62)-(247, 62)
    LINE -(250, 65)
    LINE (233, 62)-(230, 65)

END SUB

FUNCTION success (robot)
    SOUND 70, 10
    IF robot < 2 THEN
        robot = robot + 1
        LOCATE 5, 40
        PRINT "DIRECT HIT!"
    ELSE
        LOCATE 5, 40
        PRINT "DIRECT HIT! CONGRATULATIONS"
        LOCATE 6, 40
        PRINT "AREA LEADER DEFEATED,"
        LOCATE 7, 40
        PRINT "RECEIVING UPGRADES"
        SLEEP 3000
        SYSTEM
    END IF
    success = robot
END FUNCTION

FUNCTION failure (lives)
    SOUND 300, 10
    LOCATE 5, 40
    PRINT "WRONG MISSILE,"
    LOCATE 6, 40
    PRINT "COUNTER HIT DAMAGE"
    IF lives > 0 THEN
        lives = lives - 1
    ELSE
        LOCATE 5, 40
        PRINT "LOST ALL YOUR LIVES"
        LOCATE 6, 40
        PRINT "YOU HAVE BEEN DEFEATED,"
        SLEEP 3000
        SYSTEM
    END IF
    failure = lives
END FUNCTION









