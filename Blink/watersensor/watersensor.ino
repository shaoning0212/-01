int water_sensor=0;
int val=0;
int watersensor = A0;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  val=analogRead(water_sensor);
  Serial.println(val);

  delay(100);
}