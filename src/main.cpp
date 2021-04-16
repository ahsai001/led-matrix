#include <Arduino.h>

//required by DMD
#include <SPI.h>

#include <DMD2.h>

//font loading
#include <fonts/Droid_Sans_12.h>
#include <fonts/SystemFont5x7.h>
#include <angka6x13.h>
#include <Verdana10.h>
#include <TimesNewRoman10.h>
#include <SegoePrint10.h>
#include <ShortStack10.h>
#include <Distro12.h>
#include <CourierNew10.h>
#include <ArialBlack10.h>
#include <angka.h>
#include <angka_2.h>


//define dimension of panel
#define DISPLAY_COL_NUM 2
#define DISPLAY_ROW_NUM 1

SoftDMD dmd(DISPLAY_COL_NUM,DISPLAY_ROW_NUM);

DMD_TextBox clockBox(dmd, 0,0,15,16);
DMD_TextBox clockBox2(dmd, 17,0,15,16);
DMD_TextBox infoBox(dmd, 32,0,32,8);
DMD_TextBox infoBox2(dmd, 32,8,32,8);

//clock without RTC
int h = 23;
int m = 59;
int s = 30;
const int hs = 2; 
const int ms = 3;
int state1 = 0;
int state2 = 0;

void print_center(SoftDMD &dmd, DMD_TextBox &box,uint32_t box_width, const char * text,const uint8_t *font){
  unsigned int length = dmd.stringWidth(text,font);
  float centerX = (box_width - length)/2;
  box.clear();
  dmd.selectFont(font);
  box.print(text);
  box.scrollX(centerX);

  
  print_debug("kata : ");
  println_debug(text);
  print_debug("length : ");
  println_debug(length);
  print_debug("centerX : ");
  println_debug(centerX);
  
}


void print_time(){
    dmd.selectFont(angka6x13);
    clockBox.clear();
    clockBox2.clear();
    if(h < 10){
      clockBox.print("0");
    }
    clockBox.print(h);
    if(m < 10){
      clockBox2.print("0");
    }
    clockBox2.print(m);
}

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  dmd.setBrightness(80);
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

void print_debug(const char * msg){
  //Serial.print(msg);
}

void print_debug(int n, int base = 10){
  //Serial.print(n, base);
}

void println_debug(const char * msg){
  //Serial.println(msg);
}

void println_debug(int n, int base = 10){
  //Serial.println(n, base);
}

// time var
uint32_t t_now, t_clock_beat_last_updated = 0, t_clock_tick_last_updated = 0, t_jws_last_updated = 0;
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
    }
    if (m == 60)
    {
      m = 0;
      h = h + 1;
    }
    if (h == 24)
    {
      h = 0;
    }
    
    print_debug("jam :");
    print_debug(h);
    print_debug(" - ");
    print_debug(m);
    print_debug(" - ");
    print_debug(s);
    println_debug(" ");
    
    print_time();
    
    /*
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
    */
  }

  if(t_now - t_clock_beat_last_updated >= 500){
    t_clock_beat_last_updated = t_now;
    dmd.drawFilledBox(14,5,15,6, GRAPHICS_XOR);
    dmd.drawFilledBox(14,9,15,10, GRAPHICS_XOR);
    println_debug("jam beat");
  }

  if(t_now - t_jws_last_updated >= 5000){
    t_jws_last_updated = t_now;
    println_debug("jws");
    print_center(dmd,infoBox, dmd.width/2,infoString[step], angka_2);
    print_center(dmd,infoBox2, dmd.width/2,info2String[step], System5x7);
    step++;
    if(step >= sizeof(infoString)/sizeof(infoString[0])){
      step = 0;
    }
  }
}