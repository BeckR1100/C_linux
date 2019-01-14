#include <stdio.h>

#define TRUE 1
#define FALSE 0

void read_menuOne(FILE *fPtr_menuOne, int *z1, int *y1, int *z2, int *y2, int *z3, int *y3);
void read_discOne(FILE *fPtr_discOne, int *m1, int *m2, int *m3);
int  get_menu_choice(int z1, int z2, int z3, int y1, int y2, int y3);
int  order_meal(double price_of_food, int c_of_food, int d_percentage, double *money, double *cal);
void print_state(int report, int food, double money, int cal);

int main(){

    FILE  *fPtr_menuOne, *fPtr_discOne;

    int z1,z2,z3,y1,y2,y3;
    int m1,m2,m3;
    int d_type, disc;
    int name, menu, status;
    double money;
    int cal = 0;
    int food;

    fPtr_menuOne = fopen("menu.txt", "r");
    fPtr_discOne = fopen("discount.txt", "r");

    printf("Enter your name ID number:\n");
    scanf("%d", &name);

    if(name == 11000 || name == 00011){
    read_menuOne(fPtr_menuOne, &z1, &z2, &z3, &y1, &y2,&y3);
    }

    read_discOne(fPtr_discOne, &m1, &m2, &m3);

    printf("Enter your balance:");
    scanf("%lf", &money);

    printf("1.Calorine number: %d Price is %d \n ", z1, y1);
    printf("2.Calorine number: %d Price is %d \n", z2, y2);
    printf("3.Calorine number: %d Price is %d \n", z3, y3);


    printf("1.Discount number: %d\n", m1);
    printf("2.Discount number: %d\n", m2);
    printf("3.Discount number: %d\n", m3);

    printf("Enter disc number: ");
    scanf("%d", &d_type);

    switch (d_type) {
      case 1: disc = m1; break;
      case 2: disc = m2; break;
      case 3: disc = m3; break;
      default:
      printf("Error\n");
    }
    //printf("Our disc number: \n", disc);

    menu = get_menu_choice(z1, z2, z3, y1, y2, y3);
    printf("Selected by user %d \n", menu);

    switch (menu) {
      case 1: status = order_meal(y1, z1, disc, &money, &cal); break;
      case 2: status = order_meal(y2, z2, disc, &money, &cal); break;
      case 3: status = order_meal(y3, z3, disc, &money, &cal); break;
      default:
      printf("Next user...");
    }

    printf("Status is: Nan \n", status);

}

void read_menuOne(FILE *fPtr_menuOne, int *z1, int *y1, int *z2, int *y2, int *z3, int *y3){

  fscanf(fPtr_menuOne, "%d" ,z1);
  fscanf(fPtr_menuOne, "%d", z2);
  fscanf(fPtr_menuOne, "%d", z3);
  fscanf(fPtr_menuOne, "%d", y1);
  fscanf(fPtr_menuOne, "%d", y2);
  fscanf(fPtr_menuOne, "%d", y3);

  return;
}
void read_discOne(FILE *fPtr_discOne, int *m1, int *m2, int *m3){

    fscanf(fPtr_discOne, "%d", m1);
    fscanf(fPtr_discOne, "%d", m2);
    fscanf(fPtr_discOne, "%d", m3);

    return;
}

int get_menu_choice(int z1, int z2, int z3, int y1, int y2, int y3){
    int choice;
    printf("Enter meal:\n 1-Soap(100 cl = %d TL \n 2 - Beef(150 cl) = %d TL \n 3-Cake(200 cl) = %d TL \n 0 - To exit", z1, z2, z3, y1, y2, y3);
    scanf("%d", choice);

    return choice;
}

int  order_meal(double price_of_food, int c_of_food, int d_percentage, double *money, double *cal){
        price_of_food = price_of_food * (100 - d_percentage)/100;
        if(*money >= price_of_food){
            //*money = *money - price_of_food;
            *money -= price_of_food;
            *cal += c_of_food;
            return TRUE;
        }
    return FALSE;
}
void print_state(int report, int food, double money, int cal){
  if(report == 0){
        printf("Your miney is not enought order then food!\n");
        printf("Cal: %d Money: %2lf\n", cal, money);

        return;
  }

  switch (food) {
    case 1: printf("Your ordered soup.\n Cal: %d Money %2lf ", cal, money); break;
    case 2: printf("Your ordered soup.\n Cal: %d Money %2lf ", cal, money); break;
    case 3: printf("Your ordered soup.\n Cal: %d Money %2lf ", cal, money); break;
  }
}
