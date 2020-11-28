void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);  
}
float a = 0.9913;
float b = 0.9996;
float x = 1;
float xant = 1;
float y = 0;
float yant = 0.05128;

void loop()
{
  x = 1;
  y = b*yant + 0.05128*x - 0.05128*a*xant;
  xant = x;
  yant = y;
  Serial.println(y);  
}
