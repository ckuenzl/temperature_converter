#include <stdio.h>
#include <stdbool.h>
#define MAX_INPUT_OPTIONS 4
#define MIN_INPUT_OPTIONS 1
#define TEMP_INPUT_STR "Please enter the temperature input unit! \n\n1: Centigrade \n2: Degree Fahrenheit \n3: Kelvin \n4: Rankine degree \n\n0: End this program \n\nInput: "
#define TEMP_OUTPUT_STR "Please enter the temperature output unit! \n\n1: Centigrade \n2: Degree Fahrenheit \n3: Kelvin \n4: Rankine degree \n\nInput: "

//Main functions
void convert_program();
double temperature_converter(double temperature_input);
double convert_to_centigrade(double temperature_input);
double convert_to_output_unit(double centigrade);
//Util functions
int get_int_input(char *input_txt);
void print_result(double temperature_input, double converted_temperature);
bool input_is_between(int min, int max, int input);
void clear_console();
//Functions to convert temperature units in centigrade
double kelvin_to_centigrade(double kelvin);
double fahrenheit_to_centigrade(double fahrenheit);
double rankine_to_centigrade(double rankine);
//Functions to convert centigrade into other temperature units
double centigrade_to_fahrenheit(double centigrade);
double centigrade_to_kelvin(double centigrade);
double centigrade_to_rankine(double centigrade);

int temperature_input_unit;
int temperature_output_unit;
char *temperature_units[4] = {
    "Centigrade",
    "Fahrenheit",
    "Kelvin",
    "Rankine"
};

int main() {
    clear_console();
    convert_program();
    return 0;
}

void convert_program(){
    int user_input = -1;
    double temperature;
    double converted_temperature;

    while(user_input != 0){

        //Get input temperature unit
        user_input = get_int_input(TEMP_INPUT_STR);
        if(!input_is_between(MIN_INPUT_OPTIONS, MAX_INPUT_OPTIONS, user_input)){
            continue;
        }
        temperature_input_unit = user_input;
        clear_console();

        //Get convertable temperature
        printf("Please enter the temperature: ");
        scanf("%lf", &temperature);
        clear_console();

        //Get output temperature unit
        user_input = get_int_input(TEMP_OUTPUT_STR);
        if(!input_is_between(MIN_INPUT_OPTIONS, MAX_INPUT_OPTIONS, user_input)){
            continue;
        }
        temperature_output_unit = user_input;
        clear_console();

        //Convert
        converted_temperature = temperature_converter(temperature);
        print_result(temperature, converted_temperature);

    }
}

int get_int_input(char *input_txt){
    int input;
    printf(input_txt);
    scanf("%d", &input);
    return input;
}

double temperature_converter(double temperature_input) {
    double centigrade = convert_to_centigrade(temperature_input);
    return convert_to_output_unit(centigrade);
}

double convert_to_centigrade(double temperature_input){
    switch(temperature_input_unit){
        case 1:
            return temperature_input;
            break;
        case 2:
            return fahrenheit_to_centigrade(temperature_input);
            break;
        case 3:
            return kelvin_to_centigrade(temperature_input);
            break;
        case 4:
            return rankine_to_centigrade(temperature_input);
            break;            
    }
    return 0;
}

double convert_to_output_unit(double centigrade) {
    switch(temperature_output_unit){
        case 1:
            return centigrade;
            break;
        case 2:
            return centigrade_to_fahrenheit(centigrade);
            break;
        case 3:
            return centigrade_to_kelvin(centigrade);
            break;
        case 4:
            return centigrade_to_rankine(centigrade);
            break;            
    }
    return 0;
}

double kelvin_to_centigrade(double kelvin) {
    return (kelvin - 273.15);
}

double fahrenheit_to_centigrade(double fahrenheit) {
    return ((fahrenheit - 32.0) / 1.8);
}

double rankine_to_centigrade(double rankine){
    return (rankine - 491.67) * 5 / 9;
}

double centigrade_to_fahrenheit(double centigrade) {
    return (centigrade * 1.8 + 32.0);
}

double centigrade_to_kelvin(double centigrade) {
    return (centigrade + 273.15);
}

double centigrade_to_rankine(double centigrade) {
    return (centigrade + 273.15) * 9 / 5;
}

void print_result(double temperature_input, double converted_temperature) {
    printf("RESULT!\n\n");
    printf("Temperature %.2lf %s converted to %.2lf %s", temperature_input, temperature_units[temperature_input_unit - 1], converted_temperature, temperature_units[temperature_output_unit - 1]);
    printf("\n\n----------\n\n"); 
}

void clear_console() {
    system("@cls||clear");
}

bool input_is_between(int min, int max, int input){
    if( input >= min && input <= max)
    {
        return true;
    }
    return false;
}