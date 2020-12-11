//Global Variables
var begin = false;
var c = document.getElementById("arena");
var ctx = c.getContext("2d");
var targetX = 390;
var targetY = 200;
var bulletY = 400
var monster = 1;
var lives = 3;


//Listen for key presses
window.addEventListener('keydown', keyControl, true);

// Main game looping function
function draw(){
    ctx.fillStyle = "black";
    ctx.clearRect(0,0, 1200, 300);
    ctx.beginPath();
    ctx.fillRect(0, 0, 1000, 400);
    //Call function for robot head drawing
    robotHead();
    // Draw mountain range in background
    mountainRange();
    targetDraw();
    if(monster == 1){
	monster1();
    }
     if(monster == 2){
	monster2();
    }
     if(monster == 3){
	monster3();
    }
    
    ctx.strokeStyle = 'white';
    ctx.stroke();
    // call draw livebars function
    livebars();
}

//key press listening fuction
function keyControl(evt){
    switch (evt.keyCode) {
        //Press enter to start
        case 13:
		 if(begin===false){
			 init();
             begin = true;
             document.getElementById('story').innerText="|  1. Missle type 3  | | 2."+
             " Missle type 1000  | |3. Missle type 77 | |  4.Missle type 5  |  5. Missle Type 84  |";
		 }
	      document.getElementById('subtitle').innerText="Choose correct missle to destroy the Alien Robot"	 
	break;
	// Key Press 1
	 case 49:
	 	if(begin===true){
	 	  if(monster==1){
	 	  	attack();
	 	  }
	 	  else{
	 	  	damage();
	 	  }
	 	  	
	 	}
 	break
 	// Key Press 2
 	 case 50:
	 	if(begin===true){
	 	  if(monster==3){
	 	  	attack();
	 	  }
	 	  else{
	 	  	damage();
	 	  }
	 	  	
	 	}
 	break
 	// Key Press 3
 	 case 51:
	 	if(begin===true){	 	
	 	  	damage();	 		 	  	
	 	}
 	break
 	// Key Press 4
 	 case 52:
	 	if(begin===true){
	 	  if(monster==2){
	 	  	attack();
	 	  }
	 	  else{
	 	  	damage();
	 	  }
	 	  	
	 	}
 	break
 	// Key Press 5
 	 case 53:
	 	if(begin===true){	 	
	 	  	damage(); 		 	  	
	 	}
 	break
    }

}

// starts the main loop after pressin enter
function init(){
    begin = true;
    game=setInterval(draw, 25);
}

//Draw head of your robot

function robotHead(){
    ctx.moveTo(800, 0);
    ctx.lineTo(800, 200);
    ctx.lineTo(1000, 200);
    ctx.moveTo(900, 100);
    ctx.arc(900, 100, 50, Math.PI, 2 * Math.PI, false);
    ctx.moveTo(850, 100);
    ctx.lineTo(950, 100);
    ctx.moveTo(900, 100);
    ctx.lineTo(950, 100);
    ctx.moveTo(852, 100);
    ctx.lineTo(900, 30);
    ctx.moveTo(948, 100);
    ctx.lineTo(900, 30);
    ctx.moveTo(890, 100);
    ctx.lineTo(890, 130);
    ctx.moveTo(910, 100);
    ctx.lineTo(910, 130);
    ctx.moveTo(890, 130);
    ctx.lineTo(910, 130);
    ctx.moveTo(870, 100);
    ctx.lineTo(870, 115);
    ctx.moveTo(870, 115);
    ctx.lineTo(890, 115);
    ctx.moveTo(930, 100);
    ctx.lineTo(930, 115);
    ctx.moveTo(930, 115);
    ctx.lineTo(910, 115);
    ctx.moveTo(890, 130);
    ctx.lineTo(870, 140);
    ctx.moveTo(870, 140);
    ctx.lineTo(860, 100);
    ctx.moveTo(910, 130);
    ctx.lineTo(930, 140);
    ctx.moveTo(930, 140);
    ctx.lineTo(940, 100);
    ctx.moveTo(930, 140);
    ctx.lineTo(930, 170);
    ctx.moveTo(870, 140);
    ctx.lineTo(870, 170);
    ctx.moveTo(870, 170);
    ctx.lineTo(930, 170);
    ctx.moveTo(885, 150);
    ctx.lineTo(885, 160);
    ctx.moveTo(915, 150);
    ctx.lineTo(915, 160);
    ctx.moveTo(885, 150);
    ctx.lineTo(915, 150);
    ctx.moveTo(885, 160);
    ctx.lineTo(915, 160);
    ctx.moveTo(850, 100);
    ctx.lineTo(850, 170);
    ctx.moveTo(850, 170);
    ctx.lineTo(870, 170);
    ctx.moveTo(950, 100);
    ctx.lineTo(950, 170);
    ctx.moveTo(950, 170);
    ctx.lineTo(930, 170);
    ctx.moveTo(850, 170);
    ctx.lineTo(870, 140);
    ctx.moveTo(950, 170);
    ctx.lineTo(930, 140);
    ctx.moveTo(850, 140);
    ctx.lineTo(815, 110);
    ctx.lineTo(815, 30);
    ctx.lineTo(835, 50);
    ctx.lineTo(835, 80);
    ctx.lineTo(850, 100);
    ctx.moveTo(950, 140);
    ctx.lineTo(985, 110);
    ctx.lineTo(985, 30);
    ctx.lineTo(965, 50);
    ctx.lineTo(965, 80);
    ctx.lineTo(950, 100);
    ctx.moveTo(800, 200);
    ctx.lineTo(800, 400);
}

//Draw mountain range

function mountainRange(){
    ctx.moveTo(0, 60);
    ctx.lineTo(15, 35);
    ctx.lineTo(35, 55);
    ctx.lineTo(50, 55);
    ctx.lineTo(65, 40);
    ctx.lineTo(75, 40);
    ctx.lineTo(100, 60);
    ctx.lineTo(120, 35);
    ctx.lineTo(160, 35);
    ctx.lineTo(190, 60);
    ctx.lineTo(230, 60);
    ctx.lineTo(290, 45);
    ctx.lineTo(350, 70);
    ctx.lineTo(400, 30);
    ctx.lineTo(430, 35);
    ctx.lineTo(460, 60);
    ctx.lineTo(500, 60);
    ctx.lineTo(520, 40);
    ctx.lineTo(560, 40);
    ctx.lineTo(600, 65);
    ctx.lineTo(680, 65);
    ctx.lineTo(720, 45);
    ctx.lineTo(790, 45);
    ctx.lineTo(800, 55);
}

// Draw Weapon Target

function targetDraw(){
    ctx.moveTo(targetX, targetY);
    ctx.lineTo(targetX+20, targetY);
    ctx.moveTo(targetX+50, targetY);
    ctx.lineTo(targetX+70, targetY);
    ctx.moveTo(targetX+35, targetY-20);
    ctx.lineTo(targetX+35, targetY-40);
    ctx.moveTo(targetX+35, targetY+20);
    ctx.lineTo(targetX+35, targetY+40);
    ctx.moveTo(targetX+45, targetY);
    ctx.arc(targetX+35, targetY, 10, 0, 2 * Math.PI);
    ctx.arc(targetX+36, targetY, 3, 0, 2 * Math.PI);	
}

//Draw First Evil Robot Head, initialy was going to be a monster

function monster1(){

    ctx.moveTo(150, 80);
    ctx.lineTo(700, 80);
    ctx.lineTo(700, 100);
    ctx.lineTo(150, 100);
    ctx.lineTo(150, 80);
    ctx.moveTo(420, 85);
    ctx.lineTo(425, 85);
    ctx.moveTo(420, 85);
    ctx.lineTo(420, 95);
    ctx.moveTo(200, 100);
    ctx.lineTo(200, 350);
    ctx.lineTo(650, 350);
    ctx.lineTo(650, 100);
    ctx.moveTo(300, 140);
    ctx.lineTo(390, 140);
    ctx.lineTo(390, 195);
    ctx.lineTo(300, 195);
    ctx.lineTo(300, 140);
    ctx.moveTo(550, 140);
    ctx.lineTo(460, 140);
    ctx.lineTo(460, 195);
    ctx.lineTo(550, 195);
    ctx.lineTo(550, 140);
    ctx.moveTo(390, 140);
    ctx.lineTo(390, 100);
    ctx.moveTo(390, 195);
    ctx.lineTo(390, 235);
    ctx.lineTo(460, 235);
    ctx.lineTo(460, 195);
    ctx.moveTo(460, 140);
    ctx.lineTo(460, 100);
    ctx.moveTo(460, 235);
    ctx.lineTo(650, 350);
    ctx.moveTo(390, 235);
    ctx.lineTo(200, 350);
    ctx.moveTo(370, 300);
    ctx.lineTo(480, 300);
    ctx.lineTo(480, 320);
    ctx.lineTo(370, 320);
    ctx.lineTo(370, 300);
    
}

//Draw Second Evil Robot Head, initialy was going to be a monster

function monster2(){
    targetY = 270;	
    ctx.moveTo(150, 80);
    ctx.lineTo(700, 80);
    ctx.lineTo(700, 100);
    ctx.lineTo(150, 100);
    ctx.lineTo(150, 80);
    ctx.moveTo(200, 100);
    ctx.lineTo(200, 350);
    ctx.lineTo(650, 350);
    ctx.lineTo(650, 100);
    ctx.moveTo(300, 140);
    ctx.lineTo(390, 140);
    ctx.lineTo(390, 195);
    ctx.lineTo(300, 195);
    ctx.lineTo(300, 140);
    ctx.moveTo(550, 140);
    ctx.lineTo(460, 140);
    ctx.lineTo(460, 195);
    ctx.lineTo(550, 195);
    ctx.lineTo(550, 140);
    ctx.moveTo(390, 140);
    ctx.lineTo(390, 100);
    ctx.moveTo(390, 195);
    ctx.lineTo(390, 235);
    ctx.lineTo(460, 235);
    ctx.lineTo(460, 195);
    ctx.moveTo(460, 140);
    ctx.lineTo(460, 100);
    ctx.moveTo(460, 235);
    ctx.lineTo(650, 350);
    ctx.moveTo(390, 235);
    ctx.lineTo(200, 350);
    ctx.moveTo(370, 300);
    ctx.lineTo(480, 300);
    ctx.lineTo(480, 320);
    ctx.lineTo(370, 320);
    ctx.lineTo(370, 300);
    ctx.moveTo(390, 100);
    ctx.lineTo(425, 235);
    ctx.moveTo(460, 100);
    ctx.lineTo(425, 235);
    ctx.moveTo(345, 140);
    ctx.lineTo(345, 195);
    ctx.moveTo(515, 140);
    ctx.lineTo(515, 195);
    
}

//Draw Third Evil Robot Head, initialy was going to be a monster

function monster3(){
    targetY = 200;	
    ctx.moveTo(150, 80);
    ctx.lineTo(700, 80);
    ctx.lineTo(700, 100);
    ctx.lineTo(150, 100);
    ctx.lineTo(150, 80);
    ctx.moveTo(200, 100);
    ctx.lineTo(200, 350);
    ctx.lineTo(650, 350);
    ctx.lineTo(650, 100);
    ctx.moveTo(300, 140);
    ctx.lineTo(390, 140);
    ctx.lineTo(390, 195);
    ctx.lineTo(300, 195);
    ctx.lineTo(300, 140);
    ctx.moveTo(550, 140);
    ctx.lineTo(460, 140);
    ctx.lineTo(460, 195);
    ctx.lineTo(550, 195);
    ctx.lineTo(550, 140);
    ctx.moveTo(390, 140);
    ctx.lineTo(390, 100);
    ctx.moveTo(390, 195);
    ctx.lineTo(390, 235);
    ctx.lineTo(460, 235);
    ctx.lineTo(460, 195);
    ctx.moveTo(460, 140);
    ctx.lineTo(460, 100);
    ctx.moveTo(460, 235);
    ctx.lineTo(650, 350);
    ctx.moveTo(390, 235);
    ctx.lineTo(200, 350);
    ctx.moveTo(370, 300);
    ctx.lineTo(480, 300);
    ctx.lineTo(480, 320);
    ctx.lineTo(370, 320);
    ctx.lineTo(370, 300);
    ctx.moveTo(345, 140);
    ctx.lineTo(345, 195);
    ctx.moveTo(515, 140);
    ctx.lineTo(515, 195); 
    ctx.moveTo(315, 280); 
    ctx.lineTo(535, 280);
    ctx.moveTo(190, 370); 
    ctx.lineTo(190, 350);
    ctx.lineTo(200, 350);
}


// Draw livebars 

function livebars(){
     var lPosition = 0;
    for (var i=0; i<=lives; i++){
        ctx.fillRect(780+lPosition, 250, 20, 50);
        ctx.fillStyle = "white";
        ctx.stroke();
        lPosition += 40;
    }
}

//called when player is damaged

function damage(){
  //generate sound effect
  var context = new (window.AudioContext || window.webkitAudioContext)();
  var os = context.createOscillator();  
  os.type = 'square';
  os.frequency.value = 50;
  os.connect(context.destination);
  os.start();  
  os.stop(context.currentTime + 0.5);

  //handle lives
  if(lives > 0){
  	lives -= 1
  	ctx.fillRect(0, 0, 1200, 400);
        ctx.fillStyle = "white";
        ctx.stroke(); 	
  }
  else{
  	begin = 0;
  	 document.getElementById('subtitle').innerText="You got destroyed, refresh to restart the game"
  	  document.getElementById('story').innerText=" GAME OVER "	
  }
	
}

//called by successful attack
function attack(){
	//generate sound effect
	var context = new (window.AudioContext || window.webkitAudioContext)();
	var os = context.createOscillator();  
	os.type = 'sine';
	os.frequency.value = 100;
	os.connect(context.destination);
	os.start();  
	os.stop(context.currentTime + 0.5);
	
	//screen shacking effect
	document.getElementById("arena").style.marginLeft = "20%";
	setTimeout(() => {  document.getElementById("arena").style.marginLeft = "0"; }, 500);

	//Next Robot
	if(monster < 3){
		setTimeout(() => {  monster += 1; }, 500);
	}
	else{
		//Ends a Victorious Game
		document.getElementById('subtitle').innerText="All enemies in the area were defeated Mission 1 Completed"
  	  	document.getElementById('story').innerText=" Receiving update from headquaters - READY FOR NEXT MISSION  "	
		monster = 0;
		begin = false;
	}	
}










