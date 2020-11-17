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