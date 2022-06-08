// Robo India tutorial on Seven Segement Display
// Hardware: NodeMCU



String number; // reads the number from the serial monitor
// declared the output pin of 7 segment with arduino
const int h=0; //DP pin
const int c=2;
const int d=5;
const int e=4;
const int g=15;
const int f=13;
const int a=12;
const int b=14;  
int valid=1; // variable to check its valid umber given by the users or not

void setup() {                
pinMode(a,OUTPUT);  
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT);
pinMode(g,OUTPUT);
pinMode(h,OUTPUT);
Serial.begin(9600); // begin the serial monitor  
}

void loop() {
  // put your main code here, to run repeatedly:
  // ask the user for input 
Serial.println("------------------------------");
Serial.println("Please enter the Hexadecimal number(0-F) to print on 7 segement display" );
Serial.println(">>>");
while (Serial.available()==0){} // checking is there any input is available
number=Serial.readString();     // read the number from the serial monitor

// check the number given by user is single hexadecimal digit only
// if it is not the single digit number it will ask for another number 
if (number.length()>2){
  Serial.println("Please enter the single hexadecimal number");
  valid=0;   // declared that number is not valid to print
  delay(3000);
}
else{
  valid=1;
}

// if the number input is valid then this loop will work and display it
if (valid==1){
number.toUpperCase(); // convert the input number to uppercase
char val=number.charAt(0);// store the number into the char variable 'val'
// check wether input number is valid hexadecimal number(0-F)
if ((val>47 && val<58)||(val>64 & val<71)){//comapre by ASCII values od 0-9 & A-F
  Serial.print("See the display number ");
  Serial.print(val);
  Serial.println(" is printed");
}
else {
  Serial.println("Please enter a hexadecimal number(0-F) ");
  delay(3000);
}
/*Note:-check your 7 segmnet display is common cathode or anode 
 * In Common cathode write digitalWrite to HIGH to turn ON the segment
 * In Common anode write digitalWrite to LOW to turn ON the segment
 */
// comapre the'val' value with ASCII values and will print the number according to it...

//0
if (val==48)
{

digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);
}

//1
 if (val==49)
{
digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
}

//2
if (val==50)
{
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,LOW);
digitalWrite(g,HIGH);
}

//3
if (val==51)
{digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,HIGH);
}

//4
if (val==52)
{
digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

//5
if (val==53)
{
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,LOW);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

//6
if (val==54)
{
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

//7
if (val==55)
{
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
}

//8
if (val==56)
{
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);

}

//9
if (val==57)
{
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,LOW);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

//A
if (val==65)
{
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

//B
if (val==66)
{
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

//C
if (val==67)
{
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);
}

//D
if (val==68)
{
digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,LOW);
digitalWrite(g,HIGH);
}

//E
 if (val==69)
{
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}

//F
if (val==70)
{
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}
delay(3000);
}
}
