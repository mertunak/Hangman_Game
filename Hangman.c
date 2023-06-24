#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define LENGTH 100

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void delay(int);

int main(int argc, char *argv[]) {
	
	char answer[LENGTH], guess[LENGTH], theme[LENGTH], wrongLetters[6] = {'\0', '\0', '\0', '\0', '\0', '\0'}, tmpChar, userCharInput, player[2][9] = {"Player 1", "Player2"};
	int i, j, numOfCorrectLetters, totalNumOfCorrectLetters, letterNum, wordNum, roundNum, guessCount, menuControl = 1, gameControl ,roundControl, isGameOver, menuInput, whosTurn, hangman;
	
	
	
	
	while(menuControl){
		
		system("cls");
		
		printf("\t\tADAM ASMACA OYUNUNA HOSGELDINIZ\n\n");

		printf(" Arkadasinla Oyna => 1\n");
		printf(" Cikis Yap => 0\n\n");
		printf(" Lutfen seciminizi yapiniz: ");
		scanf("%d", &menuInput);
		getchar();
		
		if(menuInput == 0){
			
			menuControl = 0;
			printf("\n Oyundan cikis yapiliyor...\n\n\n");
			
			delay(2);
			
			system("cls");
			
			for (i = 3; i >= 0; i--) {																		
        		
        		if(i == 3){
        			
        			printf(" __________\n|          |\n|  O   	O  |\n|     D    |\n|  -____-  |\n|          |\n \\________/");
				} else if(i == 2){
					
					system("cls");
					printf(" __________\n|          |\n|  __  __  |\n|     D    |\n|  ______  |\n|          |\n \\________/");
				} else if(i == 1){
					
					system("cls");
					printf(" __________\n|          |\n|  __  __  |\t\t HUUUUU\n|     D    |\t\t   BB\n|  _----_  |\n|          |\n \\________/");
				}
        		delay(1);	
    		}
    		
    		system("cls");
		} else if(menuInput == 1){
			
			gameControl = 1;
			roundControl = 1;
			whosTurn = 0;
			
			system("cls");
			
			printf("\n OYUN BASLATILIYOR...");
			printf("\n OYUN MODU: ARKADASINLA OYNA");
			
			delay(2);
			
			
			while(gameControl){
				
				for(i = 0; i<LENGTH; i++){
		
					answer[i] = '\0';
					guess[i] = '\0';
					theme[i] = '\0';
				}
				
				system("cls");
				
				printf(" Oyun Sirasi: %s", player[whosTurn]);
				
				printf("\n\n Lutfen sectiginiz kelimenin temasini giriniz.");
				printf("\n Tema: ");
				scanf("%[^\n]s", theme);
				getchar();
					
				printf("\n Lutfen sectiginiz kelimeyi giriniz.");
				printf("\n Kelime: ");
				scanf("%[^\n]s", answer);
				getchar();
				
				for(i = strlen(answer) - 1; i >= 0; i--){
					
					answer[2*i] = answer[i];
				}
				
				for(i = 1; i < (2*strlen(answer) - 1); i += 2){
					
					answer[i] = ' ';
				}
				
				i = 0;
				letterNum = 0;
				
				while(answer[i] != '\0'){
					
					if(answer[i] == ' '){
						
						guess[i] = ' ';
					}else{
						
						letterNum++;
						guess[i] = '_';
					}
					
					i++;
				}
				
				whosTurn = !whosTurn;
				
				hangman = 6;
				isGameOver = 1;
				j = 0;
				while((hangman > 0) && isGameOver){
					
					system("cls");
					printf(" Oyun Sirasi: %s", player[whosTurn]);
					printf("\n\n Tema: %s\n\n", theme);
					printf(" Denenen kelimeler: ");
					
					i = 0;
					while(wrongLetters[i] != '\0'){
						
						printf("%c ", wrongLetters[i]);
						i++;
					}
					
					printf("\n\n");
					
					showHangman(hangman);
					
					printf("\n\n\t\t%s", guess);
					printf("\n\n Lutfen kontrol etmek istediginiz harfi giriniz: ");
					scanf("%c", &tmpChar);
					getchar();
					
					i = 0;
					
					numOfCorrectLetters = 0;
					while(answer[i] != '\0'){
					
						if(tmpChar == answer[i]){
						
							numOfCorrectLetters++;
							totalNumOfCorrectLetters++;
							guess[i] = answer[i];
						}
						
						i++;
					}
				
					if(totalNumOfCorrectLetters == letterNum){
						
						isGameOver = 0;
					}
				
					if(numOfCorrectLetters == 0){
					
						wrongLetters[j] = tmpChar;
						j++;
						hangman--;
					}

				}
				
				system("cls");
				
				printf(" Denenen harfler: ");
				
				i = 0;
				while(wrongLetters[i] != '\0'){
						
					printf("%c ", wrongLetters[i]);
					i++;
				}
					
				printf("\n\n");
				
				showHangman(hangman);
				printf("\n\n\t\t%s", answer);
				printf("\n\n");
				
				if(isGameOver == 0){
					
					printf(" Oyunu Kazanan: %s", player[whosTurn]);
				}else{
					
					printf(" Oyunu Kazanan: %s", player[!whosTurn]);
				}	
				
				printf("\n\n Oynamaya devam etmek istiyormusunuz? Y/N\n ");
				scanf("%c", &userCharInput);
				getchar();
				
				if(userCharInput == 'N'){
					
					gameControl = 0;
				}else if(userCharInput == 'Y'){
					
					system("cls");
					printf(" Yeni tur basliyor...");
					delay(1);
				}
			
			}
			
			system("cls");
			printf(" Anamenuye donuluyor...");
			delay(1);
				
		} else {
			
			printf("\n HATALI DEGER GIRDINIZ!!!\n");
			printf(" Lutfen ana menude gordugunuz degerlerden birini giriniz.\n\n");
			delay(2);
			system("cls");
		}
	}
	
	return 0;
}

void delay(int number_of_seconds)
{

    int milli_seconds = 1000 * number_of_seconds;
  
    clock_t start_time = clock();
  
    while (clock() < start_time + milli_seconds);
}

void showHangman(int hangman){
	
	switch(hangman){
						
		case 6: printf(" ________\n| 	 |\n|\n|\n|\n|\n|\n|"); break;
		case 5: printf(" ________\n| 	 |\n|	 O\n|\n|\n|\n|\n|"); break;
		case 4: printf(" ________\n| 	 |\n|	 O\n|	 |\n|\n|\n|\n|"); break;
		case 3: printf(" ________\n| 	 |\n|	 O\n|	/|\n|\n|\n|\n|"); break;
		case 2: printf(" ________\n| 	 |\n|	 O\n|	/|\\\n|\n|\n|\n|"); break;
		case 1: printf(" ________\n| 	 |\n|	 O\n|	/|\\\n|	/\n|\n|\n|"); break;
		case 0: printf(" ________\n| 	 |\n|	 O\n|	/|\\\n|	/ \\\n|\n|\n|"); break;
	}
}

/*

00

 __________
|		   |
|  O   	O  |
|	  D	   |	printf(" __________\n|          |\n|  O   	O  |\n|     D    |\n|  -____-  |\n|          |\n \\________/");
|  -____-  |	printf(" __________\n|          |\n|  __  __  |\n|     D    |\n|  ______  |\n|          |\n \\________/");
|	 	   |
 \________/




1
 ____
| 	 |
|	 O
|	/|\		printf(" ________\n| 	 |\n|	 O\n|	/|\\\n|	/\n|\n|\n|");
|	/ 
|

2
 ____
| 	 |
|	 O
|	/|\		printf(" ________\n| 	 |\n|	 O\n|	/|\\\n|\n|\n|\n|");
|	
|

3
 ____
| 	 |
|	 O
|	/|		printf(" ________\n| 	 |\n|	 O\n|	/|\n|\n|\n|\n|");
|
|

4
 ____
| 	 |
|	 O
|	 |		printf(" ________\n| 	 |\n|	 O\n|	 |\n|\n|\n|\n|");
|
|

5
 ____
| 	 |
|	 O
|			printf(" ________\n| 	 |\n|	 O\n|\n|\n|\n|\n|");
|
|

6
 ____
| 	 |
|
|			printf(" ________\n| 	 |\n|\n|\n|\n|\n|\n|");
|
|

0
 ____
| 	 |
|	 O
|	/|\		printf(" ________\n| 	 |\n|	 O\n|	/|\\\n|	/ \\\n|\n|\n|");
|	/ \
|

*/
