int motor = D1;



void setup() {
    pinMode(motor, OUTPUT);
    Spark.function("motor", motorSwitcher);
}



void loop() {

}



int motorSwitcher(String command) {
    
    if (command.equalsIgnoreCase("on")) {
        analogWrite(motor, 90);
        return 1;
    }
    else if (command.equalsIgnoreCase("off")) {
        analogWrite(motor, 0);
        return 2;
    }
    return -1;
}
