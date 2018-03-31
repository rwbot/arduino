/**Function to send an ultrasonic signal and calculate the distance at that point
 * returns float distance in centimeters (cm)
 */
float sonar(){
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    
    time = pulseIn(echo, HIGH);
    distance = time/58;
    return distance;
} 


