#include <Arduino.h>
/*
  Quick demo of major drawing operations on a single DMD
 */

//required by DMD
#include <SPI.h>

#include <DMD2.h>

//font loading
#include <fonts/Droid_Sans_12.h>
#include <fonts/SystemFont5x7.h>
#include <angka6x13.h>
#include <Verdana10.h>


//define dimension of panel
#define DISPLAY_COL_NUM 2
#define DISPLAY_ROW_NUM 1

SoftDMD dmd(DISPLAY_COL_NUM,DISPLAY_ROW_NUM);

DMD_TextBox clockBox(dmd, 0,0,15,16);
DMD_TextBox clockBox2(dmd, 18,0,15,16);
DMD_TextBox infoBox(dmd, 32,0,32,8);
DMD_TextBox infoBox2(dmd, 32,8,32,8);

//clock without RTC
int h = 22;
int m = 48;
int s = 0;
const int hs = 2;
const int ms = 3;
int state1 = 0;
int state2 = 0;

void centerInBox(SoftDMD &dmd, DMD_TextBox &box,uint32_t box_width, const char * text,const uint8_t *font){
  unsigned int length = dmd.stringWidth(text,font);
  float centerX = (box_width - length)/2;
  box.clear();
  dmd.selectFont(font);
  box.print(text);
  box.scrollX(centerX);

  Serial.print("kata : ");
  Serial.println(text);
  Serial.print("length : ");
  Serial.println(length);
  Serial.print("centerX : ");
  Serial.println(centerX);
}


void print_time(){
    dmd.selectFont(angka6x13);
    clockBox.print(h);
    clockBox2.print(m);
}

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  dmd.setBrightness(30);
  dmd.begin();
}

void hours_tuning(){
  h = h + 1;
  if (h == 24) h = 0;
}

void minutes_tuning(){
  s = 0;
  m = m + 1;
}

// time var
uint32_t t_now, t_clock_beat_last_updated, t_clock_tick_last_updated, t_jws_last_updated;
const char * info2String[] = {"SUBUH",
                          "ZUHUR",
                          "ASHAR",
                          "MGHRB",
                          "ISYA"};
const char * infoString[] = {"04:40",
                          "12:10",
                          "15:20",
                          "18:10",
                          "19:15"};
uint8_t step = 0;

// the loop routine runs over and over again forever:
void loop() {
  t_now = millis();

  if(t_now - t_clock_tick_last_updated >= 1000){
    t_clock_tick_last_updated = t_now;
    s = s + 1;
    if (s == 60)
    {
      s = 0;
      m = m + 1;
      print_time();
    }
    if (m == 60)
    {
      m = 0;
      h = h + 1;
      print_time();
    }
    if (h == 24)
    {
      h = 0;
      print_time();
    }
    

    state1 = digitalRead(hs);
    if (state1 == 0)
    {
      hours_tuning();
    }
    state2 = digitalRead(ms);
    if (state2 == 0)
    {
      minutes_tuning();
    }
  }

  if(t_now - t_clock_beat_last_updated >= 500){
    t_clock_beat_last_updated = t_now;
    dmd.drawFilledBox(15,5,16,6, GRAPHICS_XOR);
    dmd.drawFilledBox(15,9,16,10, GRAPHICS_XOR);
  }

  if(t_now - t_jws_last_updated >= 3000){
    t_jws_last_updated = t_now;
    centerInBox(dmd,infoBox, dmd.width/2,infoString[step], Verdana10);
    centerInBox(dmd,infoBox2, dmd.width/2,info2String[step], SystemFont5x7);
    step++;
    if(step >= sizeof(infoString)/sizeof(infoString[0])){
      step = 0;
    }
  }
}