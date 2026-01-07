const int button =6;

const int G = 3;
const int B = 4;
const int R = 5;

int buttonstate = 0 ;
int color = 0 ;
bool buttonpress = false;
String currentcolor = "led";

void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT);
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int buttonstate = digitalRead(button);

  Serial.print("Current Color; ");
  Serial.println(currentcolor);
  if (buttonstate == HIGH){
    Serial.print("Btn Pressed!");
  }
if (buttonstate == HIGH && !buttonpress) {
  color=color+1;
  buttonpress = true;
 }
 if (buttonstate == LOW && buttonpress) {
  buttonpress = false;
 }
if(color == 0){
  //White
  currentcolor="White";
  digitalWrite(R,LOW);
  digitalWrite(B,LOW);
  digitalWrite(G,LOW);
}
else if(color == 1){
  //Blue
  currentcolor="Blue";
  digitalWrite(R,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(G,HIGH);
}
else if(color == 2){
  //Purple
   currentcolor="Purple";
  digitalWrite(R,LOW);
  digitalWrite(B,LOW);
  digitalWrite(G,HIGH);
}
else if(color == 3){
  //Red
    currentcolor="Red";
  digitalWrite(R,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(G,HIGH);
}
else if(color == 4){
  color=0;
}
}