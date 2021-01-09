#include <SDL2/SDL.h> 
#include <stdio.h>


const int AMPLITUDE = 12000;
 int SAMPLE_RATE = 44100;
int lives = 3;

void audio_callback(void *user_data, Uint8 *raw_buffer, int bytes)
{
    Sint16 *buffer = (Sint16*)raw_buffer;
    int length = bytes / 2; // 2 bytes per sample for AUDIO_S16SYS
    int sample_nr = 77656;
    

    for(int i = 0; i < length; i++, sample_nr++)
    {
        double time = (double)sample_nr / (double)SAMPLE_RATE;
        buffer[i] = (Sint16)(AMPLITUDE * sin(2.0f * M_PI * 441.0f * time)); // render 441 HZ sine wave
    }
}


// Create message box  with attack options

int attackOptions(){
	     
	   const SDL_MessageBoxButtonData buttons[] = {
       { /* .flags, .buttonid, .text */        0, 0, "Missile 56" },
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Missile 7" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "Missile 9" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 3, "Missile 43" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 4, "Missile 2000" },
    };
    const SDL_MessageBoxColorScheme colorScheme = {
        { /* .colors (.r, .g, .b) */
            /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
            { 0,   0,   0 },
            /* [SDL_MESSAGEBOX_COLOR_TEXT] */
            {   255, 255, 255 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
            { 255, 255, 255 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
            {   0,   0, 0 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
            { 255, 255, 255 }
        }
    };
    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION, /* .flags */
        NULL, /* .window */
        "example message box", /* .title */
        "Target on Enemy. Zoom Factor 10x.\nChoose Correct Missile:", /* .message */
        SDL_arraysize(buttons), /* .numbuttons */
        buttons, /* .buttons */
        &colorScheme /* .colorScheme */
    };
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        SDL_Log("error displaying message box");
        
    }
    // returns what button is pressed
    if (buttonid == -1) {
		  return 99;     
    } 
    else if (buttonid == 0) {
        return 1;
    }
    else if (buttonid == 1) {
        return 2;
    }
    else if (buttonid == 2) {
        return 3;
    }
    else if (buttonid == 3) {
        return 4;
    }
    else{
		return 5;
	}
	return 0;

}


//Draws your Robot head

void drawRobotHead(SDL_Renderer* renderer){
	SDL_RenderDrawLine(renderer, 850, 100, 860, 90);
	SDL_RenderDrawLine(renderer, 860, 90, 880, 80);
	SDL_RenderDrawLine(renderer, 880, 80, 900, 80);
	SDL_RenderDrawLine(renderer, 900, 80, 920, 90);
	SDL_RenderDrawLine(renderer, 920, 90, 930, 100);
	SDL_RenderDrawLine(renderer, 850, 100, 930, 100);
	SDL_RenderDrawLine(renderer, 852, 100, 892, 40);
	SDL_RenderDrawLine(renderer, 928, 100, 892, 40);
	SDL_RenderDrawLine(renderer, 880, 100, 880, 130);
	SDL_RenderDrawLine(renderer, 900, 100, 900, 130);
	SDL_RenderDrawLine(renderer, 880, 130, 900, 130);
	SDL_RenderDrawLine(renderer, 865, 100, 865, 115);
	SDL_RenderDrawLine(renderer, 865, 115, 880, 115);
	SDL_RenderDrawLine(renderer, 915, 100, 915, 115);
	SDL_RenderDrawLine(renderer, 915, 115, 900, 115);
	SDL_RenderDrawLine(renderer, 880, 130, 860, 150);
	SDL_RenderDrawLine(renderer, 900, 130, 920, 150);
	SDL_RenderDrawLine(renderer, 860, 150, 860, 165);
	SDL_RenderDrawLine(renderer, 920, 150, 920, 165);
	SDL_RenderDrawLine(renderer, 860, 165, 920, 165);
	SDL_RenderDrawLine(renderer, 870, 150, 910, 150);
	SDL_RenderDrawLine(renderer, 870, 160, 870, 150);
	SDL_RenderDrawLine(renderer, 870, 160, 910, 160);
	SDL_RenderDrawLine(renderer, 910, 160, 910, 150);
	SDL_RenderDrawLine(renderer, 860, 165, 850, 165);
	SDL_RenderDrawLine(renderer, 850, 165, 850, 100);
	SDL_RenderDrawLine(renderer, 920, 165, 930, 165);
	SDL_RenderDrawLine(renderer, 930, 165, 930, 100);
	SDL_RenderDrawLine(renderer, 850, 165, 860, 150);
	SDL_RenderDrawLine(renderer, 930, 165, 920, 150);
	SDL_RenderDrawLine(renderer, 860, 150, 855, 100);
	SDL_RenderDrawLine(renderer, 920, 150, 925, 100);
	SDL_RenderDrawLine(renderer, 850, 132, 820, 110);
	SDL_RenderDrawLine(renderer, 820, 110, 820, 40);
	SDL_RenderDrawLine(renderer, 820, 40, 835, 50);
	SDL_RenderDrawLine(renderer, 835, 50, 835, 80);
	SDL_RenderDrawLine(renderer, 835, 80, 850, 100);
	SDL_RenderDrawLine(renderer, 930, 132, 960, 110);
	SDL_RenderDrawLine(renderer, 960, 110, 960, 40);
	SDL_RenderDrawLine(renderer, 960, 40, 945, 50);
	SDL_RenderDrawLine(renderer, 945, 50, 945, 80);
	SDL_RenderDrawLine(renderer, 945, 80, 925, 100);
}

//Draws the Live Bars

void drawLiveBars(SDL_Renderer* renderer, int* lives ){
    int x = 0;
	int i;
	int l = *lives;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	 
	 for (i=0; i<l; i++){
		SDL_Rect rect;
		rect.x = 840+x;
		rect.y = 230;
		rect.w = 30;
		rect.h = 90;
		SDL_RenderFillRect(renderer, &rect);
		x+=50;
	 }
}

//Draws Mountain Range

void drawMountainRange(SDL_Renderer* renderer){
	
	SDL_RenderDrawLine(renderer, 0, 90, 35, 35);
	SDL_RenderDrawLine(renderer, 35, 35, 70, 55);
	SDL_RenderDrawLine(renderer, 70, 55, 105, 55);
	SDL_RenderDrawLine(renderer, 105, 55, 125, 35);
	SDL_RenderDrawLine(renderer, 125, 35, 180, 75);
	SDL_RenderDrawLine(renderer, 180, 75, 240, 25);
	SDL_RenderDrawLine(renderer, 240, 25, 330, 25);
	SDL_RenderDrawLine(renderer, 330, 25, 390, 70);
	SDL_RenderDrawLine(renderer, 390, 70, 450, 70);
	SDL_RenderDrawLine(renderer, 450, 70, 570, 40);
	SDL_RenderDrawLine(renderer, 570, 40, 690, 120);
	SDL_RenderDrawLine(renderer, 690, 120, 800, 10);
}


//Draw evil Robots

//Robot 1:

void commonRobotElements(SDL_Renderer* renderer){
	
	SDL_RenderDrawLine(renderer, 400, 140, 500, 140);
	SDL_RenderDrawLine(renderer, 400, 145, 500, 145);
	SDL_RenderDrawLine(renderer, 400, 150, 500, 150);
	SDL_RenderDrawLine(renderer, 200, 340, 450, 65);
	SDL_RenderDrawLine(renderer, 450, 65, 700, 340);
	SDL_RenderDrawLine(renderer, 700, 340, 200, 340);
	SDL_RenderDrawLine(renderer, 430, 180, 470, 180);
	SDL_RenderDrawLine(renderer, 430, 180, 450, 200);
	SDL_RenderDrawLine(renderer, 470, 180, 450, 200);
	
}


void drawEvilRobot1(SDL_Renderer* renderer){
	
	commonRobotElements(renderer);
	SDL_RenderDrawLine(renderer, 390, 230, 410, 230);
	SDL_RenderDrawLine(renderer, 420, 230, 440, 230);
	SDL_RenderDrawLine(renderer, 450, 230, 455, 230);
	SDL_RenderDrawLine(renderer, 465, 230, 470, 230);
	SDL_RenderDrawLine(renderer, 480, 230, 485, 230);
	SDL_RenderDrawLine(renderer, 400, 300, 500, 300);
	SDL_RenderDrawLine(renderer, 400, 330, 500, 330);
	SDL_RenderDrawLine(renderer, 400, 300, 400, 330);
	SDL_RenderDrawLine(renderer, 500, 300, 500, 330);
	
}

//Robot 2:

void drawEvilRobot2(SDL_Renderer* renderer){
	
	commonRobotElements(renderer);
	SDL_RenderDrawLine(renderer, 400, 300, 500, 300);
	SDL_RenderDrawLine(renderer, 400, 330, 500, 330);
	SDL_RenderDrawLine(renderer, 400, 300, 400, 330);
	SDL_RenderDrawLine(renderer, 500, 300, 500, 330);
	SDL_RenderDrawLine(renderer, 400, 315, 500, 315);
	SDL_RenderDrawLine(renderer, 230, 320, 250, 300);
	SDL_RenderDrawLine(renderer, 250, 300, 270, 315);
	SDL_RenderDrawLine(renderer, 270, 315, 290, 300);
	SDL_RenderDrawLine(renderer, 290, 300, 310, 315);
	SDL_RenderDrawLine(renderer, 600, 300, 600, 275);
	SDL_RenderDrawLine(renderer, 600, 275, 620, 275);
	
}

//Robot 3:

void drawEvilRobot3(SDL_Renderer* renderer){
	
	commonRobotElements(renderer);
	
	SDL_RenderDrawLine(renderer, 470, 180, 450, 200);
	SDL_RenderDrawLine(renderer, 400, 300, 500, 300);
	SDL_RenderDrawLine(renderer, 400, 330, 500, 330);
	SDL_RenderDrawLine(renderer, 400, 300, 400, 330);
	SDL_RenderDrawLine(renderer, 500, 300, 500, 330);
	SDL_RenderDrawLine(renderer, 400, 315, 500, 315);
	SDL_RenderDrawLine(renderer, 430, 180, 450, 160);
	SDL_RenderDrawLine(renderer, 470, 180, 450, 160);
	SDL_RenderDrawLine(renderer, 250, 330, 265, 330);
	SDL_RenderDrawLine(renderer, 250, 330, 250, 305);
	SDL_RenderDrawLine(renderer, 300, 330, 285, 305);
	SDL_RenderDrawLine(renderer, 300, 330, 315, 305);
	SDL_RenderDrawLine(renderer, 570, 330, 570, 305);
	
}
 //390

void drawTarget(SDL_Renderer* renderer){
	
	SDL_RenderDrawLine(renderer, 420, 250, 440, 250);
	SDL_RenderDrawLine(renderer, 470, 250, 490, 250);
	SDL_RenderDrawLine(renderer, 455, 230, 455, 210);
	SDL_RenderDrawLine(renderer, 455, 270, 455, 290);
	
}

void success(SDL_Renderer* renderer, int* hit, int* evilRobot, int* attackOption){
	*hit = 0;
	int er = *evilRobot;
	SAMPLE_RATE = 20000;
	SDL_PauseAudio(0);
	SDL_Delay(400); 
	SDL_PauseAudio(1);
	SDL_CloseAudio();
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                         "Success",
                         "Direct hit with correct missile!",
                         NULL);   
	if(er < 2){
		er +=1;
		*evilRobot = er;
		*attackOption = 0;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 800;
		rect.h = 200;
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		if(er == 1){
			drawEvilRobot2(renderer);
		}
		if(er == 2){
			drawEvilRobot3(renderer);
		}
		
	}
	else{
		*attackOption = 99;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                         "Victory",
                         "All enemies in the area were defeated Mission 2 Completed \n Receiving update from headquaters - READY FOR NEXT MISSION ",
                         NULL);   
	}
	
}

void failed(SDL_Renderer* renderer, int* hit, int* lives, int* attackOption){
	*hit = 0;
	SDL_PauseAudio(0); 
	SDL_Delay(1000); 
	SDL_PauseAudio(1);
	SDL_CloseAudio();
	int l = *lives; 
            
	if(l >0){
		l -=1;
		*lives = l;
		*attackOption = 0;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_Rect rect;
		rect.x = 800;
		rect.y = 200;
		rect.w = 200;
		rect.h = 200;
		SDL_RenderFillRect(renderer, &rect);
		drawLiveBars(renderer, lives);
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
							 "Failed",
							 "Wrong Missile! \n You got hit by an counter attack!",
							 NULL);   
	}
	else{
		*attackOption = 99;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
							 "Dead",
							 "You got hit too many times, you are dead!",
							 NULL);   
	}

}


// Draws everything on Screen

void draw(SDL_Renderer* renderer, int* lives, int* evilRobot, int* hit, int* attackOption){
	int er = *evilRobot;
	int h = *hit;
	//arena
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, 800, 0, 800, 400);
	SDL_RenderDrawLine(renderer, 800, 200, 1000, 200);
	
	//call robotHead
	drawRobotHead(renderer);
	
	//call liveBars()
	
	drawLiveBars(renderer, lives);
	
	//call mountain Range
	
	drawMountainRange(renderer);
	//call evil Robots
	if(er == 0){
		drawEvilRobot1(renderer);
	}
	if(er== 1){
		drawEvilRobot2(renderer);
	}
	if(er == 2){
		drawEvilRobot3(renderer);
	}
	
	//call Target
	
	drawTarget(renderer);
	
	if(h == 1){
		success(renderer, hit, evilRobot,  attackOption);
	}
	
	if(h == -1){
		failed(renderer, hit, lives, attackOption);
	}
	
	SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[])
{ 
  int attackOption = 0;
  int evilRobot = 0;
  int lives = 3;
  int hit = 0;
  int x = 0;
  int sample_nr = 0;
	
		
  if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(1000, 400, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;
          
			 if(SDL_Init(SDL_INIT_AUDIO) != 0) SDL_Log("Failed to initialize SDL: %s", SDL_GetError());	
            // Intro message before game starts
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                         "Story",
                         "It all begun 5 years ago, robots appeared the sky out of now here and attacked. \nEarth tried to defend itself but we lost. \nSo we went into hidding in nuclear bunkers.  \n \nINFO:  | | | 3 Bars on the right are your Energy.",
                         NULL);   
				             
		
            while (!done) {			
                  SDL_Event event;
                
				  //Main scenes
				  
				  //Audio
				  SDL_AudioSpec want;
				  want.freq = SAMPLE_RATE; // number of samples per second
				  want.format = AUDIO_U8; // sample type (here: signed short i.e. 16 bit)
				  want.channels = 1; // only one channel
				  want.samples = 2048; // buffer-size
				  want.callback = audio_callback; // function SDL calls periodically to refill the buffer
				  want.userdata = &sample_nr; // counter, keeping track of current sample number

				 SDL_AudioSpec have;
				 if(SDL_OpenAudio(&want, &have) != 0) SDL_LogError(SDL_LOG_CATEGORY_AUDIO, "Failed to open audio: %s", SDL_GetError());
				 if(want.format != have.format) SDL_LogError(SDL_LOG_CATEGORY_AUDIO, "Failed to get the desired AudioSpec");
				
				 // draw everything
				 draw(renderer, &lives, &evilRobot, &hit, &attackOption);
				 
				 // call attack option when no attack is choosen
				 
				 if(attackOption == 0){
					attackOption = attackOptions();	
				 }
				 if(attackOption == 99){
					done = SDL_TRUE;
				 }
				
				 if(evilRobot == 0){
					 if(attackOption == 2){
						 hit = 1;
					 }
					 else{
						 hit = -1;
					 }
				 }
				
				 if(evilRobot == 1){
					 if(attackOption == 4){
						 hit = 1;
					 }
					 else{
						 hit = -1;
					 }
				 }
				
				 if(evilRobot == 2){
					 if(attackOption == 1){
						 hit = 1;
					 }
					 else{
						 hit = -1;
					 }
				 }
				
                 SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                 SDL_RenderClear(renderer);

                
                 while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                }
            }
        }

        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;

} 
