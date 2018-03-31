
/**General function for setting speed
 * @param s accepts int 0 - 255
 * currently hardcoded as 169
 */
void setspeed(int s){
  analogWrite(speedL, s);       
  analogWrite(speedR, s);
}

void setspeedL(int sl){
    analogWrite(speedL, sl);
}

void setspeedR(int sr){
    analogWrite(speedR, sr);
}
