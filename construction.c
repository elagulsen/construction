#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct cardata { char car[20]; char color[20];};

struct cardata example() {
    int r = rand();
    struct cardata new;
    if (r % 4 == 0) strcpy(new.car, "ferrari");
    if (r % 4 == 1) strcpy(new.car, "BMW");
    if (r % 4 == 2) strcpy(new.car, "van");
    if (r % 4 == 3) strcpy(new.car, "lamborghini");
    
    if (r % 5 == 0) strcpy(new.color, "yellow");
    if (r % 5 == 1) strcpy(new.color, "purple");
    if (r % 5 == 2) strcpy(new.color, "white");
    if (r % 5 == 3) strcpy(new.color, "green");
    if (r % 5 == 4) strcpy(new.color, "maroon");
    
    return new;
}


int modify(struct cardata * name, char * attribute, char * value) {
    if (attribute == "color") strcpy( &(*name).color, value);
    else strcpy( &(*name).car, value);
    return 0;
} 

int to_string(struct cardata * name) {
    char str[50] = "";
    strcat(str, "This car is a ");
    strcat(str, name->color);
    strcat(str, " ");
    strcat(str, name->car);
    printf("%s!\n", str);
    return 0;
}

int main() {
    srand( time(NULL));
    
    printf("Instantiating a new random car...\n");
    
    struct cardata carl;
    carl = example();
    
    to_string(&carl);
    
    printf("\nLet's modify this car's value... we want a chartreuse car.\n");

    strcpy(carl.color, "chartreuse");
    to_string(&carl);
    
    printf("\nLet's modify this car's type... we want a pickup truck.\n");
    modify(&carl, "car", "pickup truck");
    
    to_string(&carl);
    printf("\nOkay, perfect. This is the ideal car.\n"); 
    return 0;
}
