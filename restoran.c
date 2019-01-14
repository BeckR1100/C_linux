#include <stdio.h>

void  read_menu(FILE *fPtr_menu, int *c1, int *c2, int *c3, double *p1, double *p2, double *p3);
void  read_discount (FILE *fPtr_discount, int *d1, int *d2, int *d3);
int get_menu_choice(int c1, int c2, int c3, double p1, double p2, double p3);
int order_meal(double price_of_food, int c_of_food, int d_percentage, double *money, int *cal);

int main(){

FILE *fPtr_menu, *fPtr_discount;
int c1,c2,c3;
double p1,p2,p3;
int d1,d2,d3;
int d_type, password;
double discount;
int menu, status;
double money;
int cal = 0;

printf("Enter your password user:");
scanf("%d", &password);
if(password == 223311){
    fPtr_menu = fopen("menu.txt", "r");
    fPtr_discount = fopen("discount.txt", "r");
}

read_menu(fPtr_menu, &c1,&c2,&c3,&p1,&p2,&p3);
printf("Our menu variables %d \n",  c1);
printf("Our menu variables %d \n",  c2);
printf("Our menu variables %d \n",  c3);
printf("Our menu variables %lf \n", p1);
printf("Our menu variables %lf \n", p2);
printf("Our menu variables %lf \n", p3);

read_discount(fPtr_discount, &d1,&d2,&d3);
printf("Our discount variables: %d,%d,%d\n", d1,d2,d3 );


printf("Enter your number for discount type\n");
scanf("%d", &d_type);

switch (d_type) {
  case 1: discount = d1; break;
  case 2: discount = d2; break;
  case 3: discount = d3; break;
  default:
  printf("There is not discount type, correct!\n");
}

printf("Our discount type. %lf \n", discount);
scanf("%lf", discount);

menu = get_menu_choice(c1,c2,c3,p1,p2,p3);
printf("Enter number for menu type :\n");

switch (menu) {
  case 1: status = order_meal(p1,c1, discount, &money, &cal); break;
  case 2: status = order_meal(p2,c2, discount, &money, &cal); break;
  case 3: status = order_meal(p3,c3, discount, &money, &cal); break;
  default:
  printf("There is not meal select correct!\n");
}

void  read_menu(FILE *fPtr_menu, int *c1, int *c2, int *c3, double *p1, double *p2, double *p3){
   fscanf(fPtr_menu, "%d",  c1);
   fscanf(fPtr_menu, "%d",  c2);
   fscanf(fPtr_menu, "%d",  c3);
   fscanf(fPtr_menu, "%lf", p1);
   fscanf(fPtr_menu, "%lf", p2);
   fscanf(fPtr_menu, "%lf", p3);
}

void read_discount(FILE *fPtr_discount, int *d1, int *d2, int *d3){
   fscanf(fPtr_discount, "%d", d1);
   fscanf(fPtr_discount, "%d", d2);
   fscanf(fPtr_discount, "%d", d3);
}

int get_menu_choice(int c1, int c2, int c3, double p1, double p2, double p3){
   int choice;
   printf("Enter meal: \n 1-Soup = %2.lf TL \n 2-Cake = %2.lf \n 3-Beef = %2lf \n", p1, p2, p3);
   scanf("%d\n", &choice);
}

int order_meal(double price_of_food, int c_of_food, int d_percentage, double *money, int *cal){
           price_of_food = price_of_food * (100 -d_percentage)/100;
           if(*money > price_of_food){
             //money = money - price_of_food;
             *money -= price_of_food;
             *cal += c_of_food;
           }
     }
}
