#include <Servo.h>
int val;
int x=50;
int j=0;
Servo fy;
Servo sj;
Servo ym;
Servo fx;
void setup()
{ 
  pinMode(13,1);
  digitalWrite(13,0);
  fy.attach(10); 
  sj.attach(11); 
  ym.attach(6); 
  fx.attach(5); 
  //////////////////////////////////
  Serial.begin(9600);
  fy.write(90);
  sj.write(90);
  ym.write(50);
  fx.write(130); 
  delay(5000);  
  attachInterrupt(0, diaoXian, CHANGE);
}

void loop()
{
  if(Serial.available())
  { 
    digitalWrite(13,1);
    val=Serial.read(); 
    if(val=='1')
    {
      qiangun();
    }  
    /////
    if(val=='2')
    {
      hougun();
    }
    /////
    if(val=='3')
    {
      zuogun();
    }
    /////
    if(val=='4')
    {
      yougun();
    }
    if(val=='0')
    {
      xuantin(); 
    }
    if(val=='6')
    {
      start();
    }
    if(val=='7')
    {
      stopp();
    }    
  }
  else {
    digitalWrite(13,0);
  }
}
void xuantin()
{
  fy.write(90);//小前大后滚动
  sj.write(90);//小左大右滚动
  ym.write(x+j);//油门
  fx.write(90); //方向
  delay(10);
}
void qiangun()
{
  fy.write(75);//小前大后滚动
  sj.write(90);//小左大右滚动
  ym.write(x+j);//油门
  fx.write(90); //方向
  delay(10);
}
void hougun()
{
  fy.write(105);//小前大后滚动
  sj.write(90);//小左大右滚动
  ym.write(x+j);//油门
  fx.write(90); //方向
  delay(10);
}
void zuogun()
{
  fy.write(90);//小前大后滚动
  sj.write(75);//小左大右滚动
  ym.write(x+j);//油门
  fx.write(90); //方向
  delay(10);
}
void yougun()
{
  fy.write(90);//小前大后滚动
  sj.write(105);//小左大右滚动
  ym.write(x+j);//油门
  fx.write(90); //方向
  delay(10);
}
void start()
{

  j=j+1;
  delay(10);


}
void stopp()
{

  j=j-1;
  delay(10);
}
void diaoXian()
{
  ym.write(50);//油门
  delay(3000);
 // ym.write(50);
}






