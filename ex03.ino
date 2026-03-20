#define LED1  2
#define LED2  5
#define LED3  23

int fre = 10;
int resolution = 8;
unsigned long starttime = 0;

void setup() {
  Serial.begin(115200);
  ledcAttach(LED1, fre, resolution);
  ledcAttach(LED2, fre, resolution);
  ledcAttach(LED3, fre, resolution);
  ledcWrite(LED1, 0);
  ledcWrite(LED2, 0);
  ledcWrite(LED3, 0);
}
void d(int a)
{
  unsigned long now = millis();
  while (1)
  {
    if(millis() - now >= 1000)break;
  }
}
void shortd(void)
{
  unsigned long now = millis();
  while (1)
  {
    if(millis() - now >= 100)break;
  }
}
void longd(void)
{
  unsigned long now = millis();
  while (1)
  {
    if(millis() - now >= 200)break;
  }
}
void longshine(int a, int b, int c)
{
  for(int i=1;i<=3;i++)
  {
    ledcWrite(a,255);
    ledcWrite(b,255);
    ledcWrite(c,255);
    longd();
    ledcWrite(a,0);
    ledcWrite(b,0);
    ledcWrite(c,0);
    longd();
  }
  starttime = millis();
}
void shortshine(int a, int b, int c)
{
  for(int i=1;i<=3;i++)
  {
    ledcWrite(a,255);
    ledcWrite(b,255);
    ledcWrite(c,255);
    shortd();

    ledcWrite(a,0);
    ledcWrite(b,0);
    ledcWrite(c,0);
    shortd();
  }
  starttime = millis();
}

void loop() {
  unsigned long time = millis();
  for(int i=3;i<=5;i++)
  {
    if(i%2!=0) {
      shortshine(LED1, LED2, LED3);
    } else {
      longshine(LED1, LED2, LED3);
    }

    ledcWrite(LED1,0);
    ledcWrite(LED2,0);
    ledcWrite(LED3,0);
    d(100);
  }

  ledcWrite(LED1,0);
  ledcWrite(LED2,0);
  ledcWrite(LED3,0);
  d(1000);
}
