#include "game.h" 

int keyControl(){
	char temp = getch();
	
	if(temp == 'w' || temp == 'W'){
		return UP;
	} else if(temp == 'a' || temp == 'A'){
		return LEFT;
	} else if(temp == 's' || temp == 'S'){
		return DOWN;
	} else if(temp == 'd' || temp == 'D'){
		return RIGHT;
	} else if(temp == ' '){
		return SUBMIT;
	}
}

void titleDraw(){
	printf("\n\n\n\n");
    printf("    #####       #       #       #    #####      #####   #####      #      #####   ##### \n");
    printf("    #          # #      # #    ##    #          #         #       # #     #   #     #   \n");
    printf("    # ###     #####     #  # #  #    #####      #####     #      #####    #####     #   \n");
    printf("    #   #    #     #    #   #   #    #              #     #     #     #   # #       #   \n");
    printf("    #####    #     #    #   #   #    #####      #####     #     #     #   #   ##    #   \n");
    return 0;
} 

int menuDraw(){
	int x = 24; 
	int y = 12;
	gotoxy(x-2, y);   
	printf(">");
	gotoxy(x, y+1);
	printf("");
	gotoxy(x, y+2);
	printf(" ");
	while(1){   
		int n = keyControl();  
		switch(n){
			case UP: {  
				if(y > 12){  
					gotoxy(x-2, y);   
					printf(" "); 
					gotoxy(x-2, --y); 
					printf(">");  
				}
				break;
			}
				
			case DOWN: {
				if(y < 14) { 
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, ++y);
					printf(">");
				}
				break;
			}
			
			case SUBMIT: {
				return y-12; 
				 
			}
		}
	}
} 

void infoDraw(){
	system("cls");  
	printf("\n\n");
	printf("                        [control]\n\n");
	printf("                    move key: W, A, S, D\n");
	printf("                    select: space bar\n\n\n\n\n\n\n");
	
	while(1){
		if(keyControl() == SUBMIT){
			break;
		}
	}
}


