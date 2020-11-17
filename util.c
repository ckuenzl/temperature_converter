#include <stdbool.h>

int get_int_input(char *input_txt){
    int input;
    printf(input_txt);
    scanf("%d", &input);
    return input;
}

void clear_console() {
    //This function clears your console on Unix, Mac or Windows
    system("@cls||clear");
}

bool input_is_between(int min, int max, int input){
    if( input >= min && input <= max)
    {
        return true;
    }
    return false;
}