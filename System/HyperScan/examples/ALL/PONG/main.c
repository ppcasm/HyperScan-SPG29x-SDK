/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

This is a terrible example of a PONG game, but instead of making it all nice and pretty, I decided it's best to just leave
it as is, since it's only real reason for being included is to give basic examples of very rudimentary functions like writing
to a non page-flipped, static framebuffer, and some examples of how to do some things with controller inputs. 
 
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../../../../SPG290/scorelibs/include/TV/TV.h"
#include "../../../../../SPG290/scorelibs/include/SPG290_Registers.h"
#include "../../../../../SPG290/scorelibs/include/SPG290_Constants.h"
#include "../../../hslibs/include/HS_Controller/HS_Controller.h"

// Stupid Framebuffer
unsigned short *fb = (unsigned short *) 0xA0400000;

// Will you make it fast, slow, who knows?
int ball_speed = 1;
int paddle_speed = 8;

// Change sign for bouncy bally
int ball_movement_x = 1;
int ball_movement_y = 1;

// Current ball position
int cur_ball_x = 40;
int cur_ball_y = 224;

// No page flipping/buffering yet, we use this to erase old ball
int prev_ball_x = 1;
int prev_ball_y = 1;

// Player paddle position
int cur_p1_pos = 200;
int cur_p2_pos = 200;

// No page flipping/buffering yet, so again we use this to erase old paddles
int prev_p1_pos = 1;
int prev_p2_pos = 1;

// Simple ball bitmap
int ball[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
    		 	  {0, 0, 1, 1, 1, 1, 0, 0},
    			  {0, 1, 1, 1, 1, 1, 1, 0},
    			  {0, 1, 1, 1, 1, 1, 1, 0},
    			  {0, 1, 1, 1, 1, 1, 1, 0},
    			  {0, 1, 1, 1, 1, 1, 1, 0},
    			  {0, 0, 1, 1, 1, 1, 0, 0},
    			  {0, 0, 0, 0, 0, 0, 0, 0}};
    			  

void draw_player1(int pos){
	int i,j = 0;
	
	// Lazily erase old paddles
	for(i=0;i<48;i++) {
   	    for(j=0;j<8;j++) {
       	    fb[(prev_p1_pos+i)*640+(16+j)] = 0x0000;
       	}
   	}
    
	// Draw new paddles
    for(i=0;i<48;i++) {
        for(j=0;j<8;j++) {
            fb[(pos+i)*640+(16+j)] = 0x07E0;
        }
    }
    
    // Keep record of previous paddle position so we can erase later
    prev_p1_pos = cur_p1_pos;
}

void draw_player2(int pos){
	int i,j = 0;
	
	// Lazily erase old paddles
	for(i=0;i<48;i++) {
   	    for(j=0;j<8;j++) {
       	    fb[(prev_p2_pos+i)*640+(608+j)] = 0x0000;
       	}
   	}
    
	// Draw new paddles
    for(i=0;i<48;i++) {
        for(j=0;j<8;j++) {
            fb[(pos+i)*640+(608+j)] = 0xF800;
        }
    }
    
    // Keep record of previous paddle position so we can erase later
    prev_p2_pos = cur_p2_pos;
}

void draw_ball(int xx, int yy){
	int i,j = 0;
	
	unsigned short color = 0;

	// Lazily erase old ball
	for(i=0;i<8;i++) {
   	    for(j=0;j<8;j++) {
       	    fb[(prev_ball_y+i)*640+(prev_ball_x*8+j)] = 0x0000;
       	}
   	}

	// Draw new ball
    for(i=0;i<8;i++) {
        for(j=0;j<8;j++) {
        	
        	if(ball[i][j]) color = 0xFFFF; else color = 0x0000;
            fb[(yy+i)*640+(xx*8+j)] = color;
        }
    }
    
    // Keep record of previous ball position so we can erase later
    prev_ball_y = yy;
    prev_ball_x = xx;
}

int main()
{
	int nExitCode = 0;
	/************************************************************************/
	/*   TODO: add your code here                                           */
	/************************************************************************/

	/* Initalize Mattel HyperScan controller interface */
	HS_Controller_Init();
	
	/*
		Set TV output up with RGB565 color scheme and make set all framebuffers
		to stupid framebuffer address, TV_Init will select the first framebuffer
		as default.
	*/
	TV_Init(RESOLUTION_640_480, COLOR_RGB565, 0xA0400000, 0xA0400000, 0xA0400000);

	TV_Print(fb, 29, 2, "HyperScan PONG - ppcasm");
	TV_Print(fb, 18, 3, "Join the Discord: https://discord.gg/rHh2nW9sue");
	TV_Print(fb, 29, 28, "Press SELECT to restart");

	// Player scores
	char p1_score[4];
	char p2_score[4];

	// Initialize player scores schema
	p1_score[0] = '0';
	p1_score[1] = '0';
	p1_score[2] = 0;
	p2_score[0] = '0';
	p2_score[1] = '0';
	p2_score[2] = 0;
	
	while(1){
		HS_Controller_Read();
		
		// Make right trigger speed up ball and left trigger slow it down :p
		if((controller[hs_controller_1].input.joystick_y != 0xFF) & (controller[hs_controller_1].input.joystick_x != 0xFF) & (controller[hs_controller_1].input.rt)){
			ball_speed += 1;
			if(ball_speed >= 4) ball_speed = 4;
		}
		if((controller[hs_controller_1].input.joystick_y != 0xFF) & (controller[hs_controller_1].input.joystick_x != 0xFF) & (controller[hs_controller_1].input.lt)){
			ball_speed -= 1;
			if(ball_speed <= 1) ball_speed = 1;
		}
		
		// Make right shoulder speed up paddles and left trigger slow them down :p
		if((controller[hs_controller_1].input.joystick_y != 0xFF) & (controller[hs_controller_1].input.joystick_x != 0xFF) & (controller[hs_controller_1].input.rs)){
			paddle_speed += 1;
			if(paddle_speed >= 16) paddle_speed = 16;
		}
		if((controller[hs_controller_1].input.joystick_y != 0xFF) & (controller[hs_controller_1].input.joystick_x != 0xFF) & (controller[hs_controller_1].input.ls)){
			paddle_speed -= 1;
			if(paddle_speed <= 1) paddle_speed = 1;
		}
		
				// Make right trigger speed up ball and left trigger slow it down :p
		if((controller[hs_controller_2].input.joystick_y != 0xFF) & (controller[hs_controller_2].input.joystick_x != 0xFF) & (controller[hs_controller_2].input.rt)){
			ball_speed += 1;
			if(ball_speed >= 4) ball_speed = 4;
		}
		if((controller[hs_controller_2].input.joystick_y != 0xFF) & (controller[hs_controller_2].input.joystick_x != 0xFF) & (controller[hs_controller_2].input.lt)){
			ball_speed -= 1;
			if(ball_speed <= 1) ball_speed = 1;
		}
		
		// Make right shoulder speed up paddles and left trigger slow them down :p
		if((controller[hs_controller_2].input.joystick_y != 0xFF) & (controller[hs_controller_2].input.joystick_x != 0xFF) & (controller[hs_controller_2].input.rs)){
			paddle_speed += 1;
			if(paddle_speed >= 16) paddle_speed = 16;
		}
		if((controller[hs_controller_2].input.joystick_y != 0xFF) & (controller[hs_controller_2].input.joystick_x != 0xFF) & (controller[hs_controller_2].input.ls)){
			paddle_speed -= 1;
			if(paddle_speed <= 1) paddle_speed = 1;
		}
		
		if((controller[hs_controller_1].input.joystick_y != 0xFF) & (controller[hs_controller_1].input.joystick_x != 0xFF) & (controller[hs_controller_1].input.select)){
			cur_ball_x = 40;
			cur_ball_y = 224;
			ball_movement_x = 1;
			ball_movement_y = 1;
			ball_speed = 1;
			cur_p1_pos = 200;
			cur_p2_pos = 200;
			paddle_speed = 8;
		
			goto *0xa0091000;
		}
		
		if((controller[hs_controller_2].input.joystick_y != 0xFF) & (controller[hs_controller_2].input.joystick_x != 0xFF) & (controller[hs_controller_2].input.select)){
			cur_ball_x = 40;
			cur_ball_y = 224;
			ball_movement_x = 1;
			ball_movement_y = 1;
			ball_speed = 1;
			cur_p1_pos = 200;
			cur_p2_pos = 200;
			paddle_speed = 8;
		
			goto *0xa0091000;
		}
		
		//TV_PrintHex(fb, 35, 4, cur_ball_x);
		//TV_PrintHex(fb, 35, 5, cur_ball_y);
		//TV_PrintHex(fb, 35, 6, cur_p1_pos);
		
		// Check and handle bouncing off the boundaries, scores, etc
		if(((cur_ball_x <= 2+ball_speed) & (cur_ball_y >= cur_p1_pos-4)) & ((cur_ball_x <= 2+ball_speed) & (cur_ball_y < cur_p1_pos+49)))	ball_movement_x = ball_speed;
		
		if(((cur_ball_x >= 76-ball_speed) & (cur_ball_y >= cur_p2_pos-4)) & ((cur_ball_x >= 76-ball_speed) & (cur_ball_y < cur_p2_pos+49))) ball_movement_x = -ball_speed;
		
        if(cur_ball_x <= ball_speed){
        	if(p2_score[1] >= '8'){
				// Player2 Wins
				ball_movement_x = 0;
				ball_movement_y = 0;
				TV_Print(fb, 33, 15, "PLAYER 2 WINS!");
        	}
        	else{
        		p2_score[1] = p2_score[1] + 1;
        		ball_movement_x = ball_speed;
        	}
        }
        if(cur_ball_x >= 0x4E - ball_speed){
        	if(p1_score[1] >= '8'){
				// Player1 Wins
				ball_movement_x = 0;
				ball_movement_y = 0;
				TV_Print(fb, 33, 15, "PLAYER 1 WINS!");
        	}
        	else{
        		p1_score[1] = p1_score[1] + 1;
        		ball_movement_x = -ball_speed;
        	}
        }
        
		if(cur_ball_y <= 64) ball_movement_y = ball_speed;
		if(cur_ball_y >= 440) ball_movement_y = -ball_speed;
		draw_ball(cur_ball_x+=ball_movement_x, cur_ball_y+=ball_movement_y);
		
		if((controller[hs_controller_1].input.joystick_y != 0xFF) & (controller[hs_controller_1].input.joystick_x != 0xFF) & (controller[hs_controller_1].input.joystick_y <= 0x60)){
			
			if(cur_p1_pos >= 392) cur_p1_pos = 392; else cur_p1_pos+=paddle_speed;
		}
		
		if((controller[hs_controller_1].input.joystick_y != 0xFF) & (controller[hs_controller_1].input.joystick_x != 0xFF) & (controller[hs_controller_1].input.joystick_y >= 0xA0)){
			if(cur_p1_pos <= 64) cur_p1_pos = 64; else cur_p1_pos-=paddle_speed;
		}
		
		if((controller[hs_controller_2].input.joystick_y != 0xFF) & (controller[hs_controller_2].input.joystick_x != 0xFF) & (controller[hs_controller_2].input.joystick_y <= 0x60)){
			
			if(cur_p2_pos >= 392) cur_p2_pos = 392; else cur_p2_pos+=paddle_speed;
		}
		
		if((controller[hs_controller_2].input.joystick_y != 0xFF) & (controller[hs_controller_2].input.joystick_x != 0xFF) & (controller[hs_controller_2].input.joystick_y >= 0xA0)){
			if(cur_p2_pos <= 64) cur_p2_pos = 64; else cur_p2_pos-=paddle_speed;
		}
		draw_player1(cur_p1_pos);
		draw_player2(cur_p2_pos);
		
		TV_Print(fb, 0, 28, "Player1:");
		TV_Print(fb, 9, 28, p1_score); 
		TV_Print(fb, 69 , 28, "Player2:");
		TV_Print(fb, 78, 28, p2_score);
	}
		
	return nExitCode;
}
