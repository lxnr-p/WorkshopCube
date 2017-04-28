
Servo myservo;

//int pos = 0;
int motor = D0;


void setup() {
    Particle.function("servo", servo);
    myservo.attach(D3);
    myservo.write(75);
    pinMode(motor, OUTPUT);
    Spark.function("motor", motorSwitcher);
}



int servo(String command) { 
    if(command == "gauche") {  //pour droite sur la page web              
        myservo.write(85);     // augmenter la valeur pour augmenter la rotation
        delay(0);
        Particle.publish("gauche", "ok");
        delay(4000);
        myservo.write(75);
        return 1;
    }
    
    if(command == "droite") {  //pour gauche sur la page web
        myservo.write(65);     // diminuer la valeur pour augmenter la rotation
        delay(0);
        Particle.publish("gauche", "ok");
        delay(4000);
        myservo.write(75);
        return 2;
    }
}



int motorSwitcher(String command) {
    
    if (command.equalsIgnoreCase("on")) {
        digitalWrite(motor, HIGH);
        delay(3000);
        digitalWrite(motor, LOW);
        digitalWrite(D7, HIGH);
        return 1;
    }
    //else if (command.equalsIgnoreCase("off")) {
      //  digitalWrite(motor, LOW);
        //return 2;
   //}
    //return -1;
}



void loop() {

}
