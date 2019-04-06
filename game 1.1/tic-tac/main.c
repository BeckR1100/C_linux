#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch1, ch2;
    int z1,z2,position,move=1,x=0,y=0,count=0,c=1,d=0,a[8],k=0;
    int flag=1,i,j;

    for(i=0; i<9; i++){
        a[i]=3;
        printf("Welcome to game TIC-TAC\n");
       // printf("for reference to players \n");
        printf("_________________________ \n");
        printf("---a[0]---a[1]---a[2]---  \n");
        printf("________________________  \n");
        printf("---a[3]---a[4]---a[5]---  \n");
        printf("________________________  \n");
        printf("---a[6]---a[7]---a[8]---  \n");
        printf("________________________  \n");
    }

    while(flag=1){

        printf("Enter X or O for Player1 \n");
        scanf("%c", &ch1);
        if(ch1=='X' || ch1=='x' || ch1=='O' || ch1=='o'){
            flag=0;
        }else{
            flag=1;
            printf("Invalid choice!!");
        }
    }

    if(ch1=='X' || ch1=='x'){
        ch2='O';
    }else{
        ch2=='X';
    }

    printf("Player 2 choice is %c \n", ch2);
    if(ch1=='X' || ch1=='x'){
    z1=1;
    z2=0;
    }else{
    z1=0;
    z2=1;
    }
    while(move<3){
        count=0;
        if(move==1){
          printf("Player1 Enter the position \n");
          scanf("%d", &position);

          if(a[position]==3){
            a[position]=z1;
            k=0;
            for(i=0; i<3; j++){
                for(j=0; j<3; j++){
                    if(a[k]==3)
                    printf("\t-");
                    if(a[k]==1)
                    printf("\tX");
                    if(a[k]==0)
                    printf("\tO");
                    k++;
                }
                printf("\n");
            }
            if((a[0]==z1 && a[1]==z1 && a[2]==z1)||(a[3]==z1 && a[4]==z1 && a[5]==z1) || (a[6]==z1 && a[7]==z1 && a[8]==z1)){
                printf("Player1 wins \n");
                x=1;
                printf("Thank you for olayer this game \n");
                move = 3;
                break;

            }else{
                move=2;
                printf("This pleace is not empty. Please give another position \n");
                move=1;
            }

            for(i=0; i<9; i++){
                if(a[i]==3)
                count++;
            }
            if(count==0){
                move=3;
                break;
            }
            if(move==2){
                printf("Player2 Enter position \n");
                scanf("%d",&position);

                if(a[position]==3){
                    a[position]=z2;
                    k=0;
                    for(i=0; i<3; i++){
                        for(j=0; j<3; j++){
                            if(a[k]==3)
                            printf("\t-");
                            else if(a[k]==1)
                            printf("\tX");
                            else
                            printf("\tO");
                            k++;
                        }

                        printf("\n");
                    }
                    if((a[0]==z2 && a[1]==z2 && a[2]==z2)||(a[3]==z2 && a[4]==z2 && a[5]==z2) || (a[6]==z2 && a[7]==z2 && a[8]==z2)){

                        printf("player2 wins \n");
                        y=1;
                        printf("Thank you  for playing this");
                        move=3;
                        break;
                    }else{
                        move=1;
                        printf("This place is not empty. Please other position \n");
                        move=2;
                    }
                }

                if(x!=1 && y!=1){
                    printf("Drow Match \n");
                    printf("Thank you for playing this game \n");

                }


            }
          }
      }
    }
}
