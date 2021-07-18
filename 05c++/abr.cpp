#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
	int play = 0;
	int robot = 0;
    int lives = 3;
    int victory = 0; 
    sf::RenderWindow window(sf::VideoMode(1080, 800), "Advance Battle Robot Part 5 C++");
    sf::Font font;
    font.loadFromFile("Trueno.otf");
    sf::Text message;
    message.setFont(font);
   
    //Draw Game borders
    sf::RectangleShape arena(sf::Vector2f(1030.f, 600.f));
    arena.setPosition(20.f, 20.f);
    arena.setFillColor(sf::Color(0,0,0));
    arena.setOutlineThickness(4.f);
    arena.setOutlineColor(sf::Color(255,255,255));
    
    //Draw screen seperators
    sf::RectangleShape vSeperator(sf::Vector2f(600.f, 4.f));
    vSeperator.setPosition(900.f, 20.f);
    vSeperator.rotate(90.f);
    sf::RectangleShape hSeperator(sf::Vector2f(150.f, 4.f));
    hSeperator.setPosition(900.f, 200.f);
    
    //Draw Robot Top Head
    sf::CircleShape robotTopHead(50.f, 3);
    robotTopHead.setPosition(920.f, 30.f);
    //Draw Robot Face
    sf::RectangleShape rFace(sf::Vector2f(87.f, 60.f));
    rFace.setPosition(927.f, 105.f);
    rFace.setFillColor(sf::Color(255,255,255));
    //Draw Eye Visor
    sf::RectangleShape eVisor(sf::Vector2f(55.f, 15.f));
    eVisor.setPosition(942.f, 107.f);
    eVisor.setFillColor(sf::Color(255,0,0));
    //Draw Nose
    sf::RectangleShape rNose(sf::Vector2f(25.f, 35.f));
    rNose.setPosition(957.f, 107.f);
    rNose.setFillColor(sf::Color(192,192,192));
    //Draw Mouth
    sf::RectangleShape rMouth(sf::Vector2f(45.f, 15.f));
    rMouth.setPosition(947.f, 147.f);
    rMouth.setFillColor(sf::Color(192,192,192));
    //Draw Face Lines
     sf::RectangleShape topFaceLine(sf::Vector2f(87.f, 5.f));
     topFaceLine.setPosition(927,105);
     topFaceLine.setFillColor(sf::Color(192,192,192));
     
     sf::RectangleShape fromNoseLeftFaceLine(sf::Vector2f(25.f, 5.f));
     fromNoseLeftFaceLine.setPosition(960,142);
     fromNoseLeftFaceLine.setFillColor(sf::Color(192,192,192));
     fromNoseLeftFaceLine.rotate(165.f);
     
     sf::RectangleShape straightDownLeftFaceLine(sf::Vector2f(18.f, 5.f));
     straightDownLeftFaceLine.setPosition(940,147);
     straightDownLeftFaceLine.setFillColor(sf::Color(192,192,192));
     straightDownLeftFaceLine.rotate(90.f);
     
     sf::RectangleShape toTopLeftFaceLine(sf::Vector2f(40.f, 5.f));
     toTopLeftFaceLine.setPosition(936,147);
     toTopLeftFaceLine.setFillColor(sf::Color(192,192,192));
     toTopLeftFaceLine.rotate(255.f);
     
      sf::RectangleShape fromNoseRightFaceLine(sf::Vector2f(25.f, 5.f));
     fromNoseRightFaceLine.setPosition(980,136);
     fromNoseRightFaceLine.setFillColor(sf::Color(192,192,192));
     fromNoseRightFaceLine.rotate(15.f);
     
     sf::RectangleShape straightDownRightFaceLine(sf::Vector2f(21.f, 5.f));
     straightDownRightFaceLine.setPosition(1005,144);
     straightDownRightFaceLine.setFillColor(sf::Color(192,192,192));
     straightDownRightFaceLine.rotate(90.f);
     
     sf::RectangleShape toTopRightFaceLine(sf::Vector2f(40.f, 5.f));
     toTopRightFaceLine.setPosition(1000,144);
     toTopRightFaceLine.setFillColor(sf::Color(192,192,192));
     toTopRightFaceLine.rotate(285.f);
     
     //Horns
     sf::RectangleShape leftHornLeftUp(sf::Vector2f(25.f, 5.f));
     leftHornLeftUp.setPosition(927,105);
     leftHornLeftUp.setFillColor(sf::Color(192,192,192));
     leftHornLeftUp.rotate(250.f);
     
     sf::RectangleShape leftHornUp(sf::Vector2f(25.f, 5.f));
     leftHornUp.setPosition(919,82);
     leftHornUp.setFillColor(sf::Color(192,192,192));
     leftHornUp.rotate(270.f);
     
     sf::RectangleShape leftHornUpLeftShort(sf::Vector2f(25.f, 5.f));
     leftHornUpLeftShort.setPosition(919,59);
     leftHornUpLeftShort.setFillColor(sf::Color(192,192,192));
     leftHornUpLeftShort.rotate(240.f);
     
     sf::RectangleShape leftHornDown(sf::Vector2f(90.f, 5.f));
     leftHornDown.setPosition(910,38);
     leftHornDown.setFillColor(sf::Color(192,192,192));
     leftHornDown.rotate(90.f);
     
     sf::RectangleShape leftHornRight(sf::Vector2f(26.f, 5.f));
     leftHornRight.setPosition(908,123);
     leftHornRight.setFillColor(sf::Color(192,192,192));
     leftHornRight.rotate(30.f);
     
     sf::RectangleShape rightHornRightUp(sf::Vector2f(25.f, 5.f));
     rightHornRightUp.setPosition(1010,105);
     rightHornRightUp.setFillColor(sf::Color(192,192,192));
     rightHornRightUp.rotate(300.f);
     
     sf::RectangleShape rightHornUp(sf::Vector2f(25.f, 5.f));
     rightHornUp.setPosition(1021,85);
     rightHornUp.setFillColor(sf::Color(192,192,192));
     rightHornUp.rotate(270.f);
     
     sf::RectangleShape rightHornUpRightShort(sf::Vector2f(25.f, 5.f));
     rightHornUpRightShort.setPosition(1021,60);
     rightHornUpRightShort.setFillColor(sf::Color(192,192,192));
     rightHornUpRightShort.rotate(300.f);
     
     sf::RectangleShape rightHornDown(sf::Vector2f(90.f, 5.f));
     rightHornDown.setPosition(1040,38);
     rightHornDown.setFillColor(sf::Color(192,192,192));
     rightHornDown.rotate(90.f);
     
     sf::RectangleShape leftHornLeft(sf::Vector2f(30.f, 5.f));
     leftHornLeft.setPosition(1041,125);
     leftHornLeft.setFillColor(sf::Color(192,192,192));
     leftHornLeft.rotate(155.f);
     
     //Displaying Message
     
     message.setString("After our first battle with an alien boss, we moved to a new area. \nPress Enter to Start");
     message.setCharacterSize(24);
     message.setFillColor(sf::Color::Green);
     message.setPosition (20.f, 635.f);
     
   
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		//Put everything on window
        window.clear();
        window.draw(arena);
        window.draw(vSeperator);
        window.draw(hSeperator);
        window.draw(robotTopHead);
        window.draw(rFace);
        window.draw(eVisor);
        window.draw(rNose);
        window.draw(rMouth);
        window.draw(topFaceLine);
        window.draw(fromNoseLeftFaceLine);
        window.draw(straightDownLeftFaceLine);
        window.draw(toTopLeftFaceLine);
        window.draw(fromNoseRightFaceLine);
        window.draw(straightDownRightFaceLine);
        window.draw(toTopRightFaceLine);
        window.draw(leftHornLeftUp);
        window.draw(leftHornUp);
        window.draw(leftHornUpLeftShort);
        window.draw(leftHornDown);
        window.draw(leftHornRight);
        window.draw(rightHornRightUp);
        window.draw(rightHornUp);
        window.draw(rightHornUpRightShort);
        window.draw(rightHornDown);
        window.draw(leftHornLeft);
        
        //Check if keys is pressed to start the game
     
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            play = 1;
            
	 }
	 
	 if (play == 1){
		 
		 sf::Text msgWeakness;
		 msgWeakness.setFont(font);
         if(robot == 0){
            msgWeakness.setString("Weakness Detected: \nOpossite Visor Color");
         }
          if(robot == 1){
            msgWeakness.setString("Weakness Detected: \nOpossite Antenna Color");
         }
          if(robot == 2){
            msgWeakness.setString("Weakness Detected: \nOpossite Mouth Color");
         }
         
		 msgWeakness.setCharacterSize(24);
		 msgWeakness.setFillColor(sf::Color::Green);
		 msgWeakness.setPosition (30.f, 200.f);
		 window.draw(msgWeakness);
		 message.setString("1. Missile Cyan | 2. Missile Black | 3. Missile Green | 4. Missile White | 5. Missile Yellow | 6. Missile Blue \n\nPress Missile Number to Shoot!!! Then press Enter");
		 message.setCharacterSize(20);
         // Draw livebars
         if (lives > 0){
             sf::RectangleShape lBar(sf::Vector2f(20.f, 90.f));
             lBar.setPosition(927.f, 305.f);
             lBar.setFillColor(sf::Color(255,255,255));
             window.draw(lBar);
          }
         if (lives > 1){ 
             sf::RectangleShape lBar2(sf::Vector2f(20.f, 90.f));
             lBar2.setPosition(957.f, 305.f);
             lBar2.setFillColor(sf::Color(255,255,255));
             window.draw(lBar2);
         }
         if (lives > 2){
             sf::RectangleShape lBar3(sf::Vector2f(20.f, 90.f));
             lBar3.setPosition(987.f, 305.f);
             lBar3.setFillColor(sf::Color(255,255,255));
             window.draw(lBar3);
         }
         
         //Evil robot1
         if(robot == 0  && play == 1){
             int go = 1;
             sf::CircleShape robot1(100.f, 3);
             robot1.setPosition(450.f, 200.f);
             window.draw(robot1);
             sf::RectangleShape visor1(sf::Vector2f(50.f, 20.f));
             visor1.setPosition(525.f, 260.f);
             visor1.setFillColor(sf::Color(255,0,0));
             window.draw(visor1);
             
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
                play = 0;
                robot = 1;
               
             }
             
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)
              || sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)){
                 
                  if(lives >0 && play == 1){ 
                        lives -=1;
                        play = 0 ;
                       
                  }
                  else
                  {
                    return 0;   
                  }
            }
         }
         //Evil robot2
         if(robot == 1 && play == 1){
             sf::CircleShape robot2(100.f, 3);
             robot2.setPosition(450.f, 200.f);
             window.draw(robot2);
             sf::RectangleShape visor2(sf::Vector2f(50.f, 20.f));
             visor2.setPosition(525.f, 260.f);
             visor2.setFillColor(sf::Color(255,0,0));
             window.draw(visor2);
             sf::RectangleShape antenna(sf::Vector2f(50.f, 5.f));
             antenna.setPosition(553.f, 156.f);
             antenna.rotate(90.f);
             window.draw(antenna);
             sf::RectangleShape antennaTop(sf::Vector2f(20.f, 15.f));
             antennaTop.setPosition(558.f, 140.f);
             antennaTop.rotate(90.f);
             window.draw(antennaTop);
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
                robot = 2;
                play = 0;
               
             }
             
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)
              || sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)){
                 
                  if(lives >0 && play == 1){ 
                        lives -=1;
                        play = 0 ;
                       
                  }
                  else
                  {
                    return 0;   
                  }
            }
         }
          //Evil robot2
         if(robot == 2 && play == 1){
             sf::CircleShape robot2(100.f, 3);
             robot2.setPosition(450.f, 200.f);
             window.draw(robot2);
             sf::RectangleShape visor2(sf::Vector2f(50.f, 20.f));
             visor2.setPosition(525.f, 260.f);
             visor2.setFillColor(sf::Color(255,0,0));
             window.draw(visor2);
             sf::RectangleShape antenna(sf::Vector2f(50.f, 5.f));
             antenna.setPosition(553.f, 156.f);
             antenna.rotate(90.f);
             window.draw(antenna);
             sf::RectangleShape antennaTop(sf::Vector2f(20.f, 15.f));
             antennaTop.setPosition(558.f, 140.f);
             antennaTop.rotate(90.f);
             window.draw(antennaTop);
             
             sf::RectangleShape mouth(sf::Vector2f(20.f, 25.f));
             mouth.setPosition(561.f, 320.f);
             mouth.rotate(90.f);
             mouth.setFillColor(sf::Color(0,0,255));
             window.draw(mouth);

              
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && victory == 0){
               victory = 1;  
             
             }
             if(victory == 1){
               sf::Text victory;
               victory.setFont(font);  
               victory.setString("Congratulation you \ndefeated all Enemies \nReceiving upgades. \n\nPress Enter to exit"); 
               victory.setCharacterSize(24);
               victory.setFillColor(sf::Color::Green);
               victory.setPosition (30.f, 300.f);
               window.draw(victory);
               if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                   return 0;
               }
             }
             
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)
              || sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)){
                 
                  if(lives >0 && play == 1){ 
                        lives -=1;
                        play = 0 ;
                       
                  }
                  else
                  {
                    return 0;   
                  }
            }
         }
		 
	 }
        
        window.draw(message);
        window.display();
    }

    return 0;
}
