#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей

int button = 2;

bool button_flag=false;

int delay_c=500;

int player_x=0;
int player_y=1;

int barrier_x=15;
int barrier_y=1;

int points=0;

byte player[8] = {
    0b01110,
    0b01010,
    0b01010,
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b01010
};
byte barrier[8] = {
    0b00100,
    0b00100,
    0b10100,
    0b10101,
    0b10101,
    0b11111,
    0b00100,
    0b00100
};


void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  lcd.home();
  lcd.init();                     
  lcd.backlight();// Включаем подсветку дисплея
  lcd.clear();

  lcd.print("Press button");
  
  while( digitalRead(button) == LOW ){//если кнопка ненажата ...
    
}
  
  lcd.createChar(0, player);
  lcd.createChar(1, barrier);

  //lcd.setCursor(player_x,player_y);
  //lcd.print(0);
  //lcd.setCursor(15,1);
  //lcd.print(1);

lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.clear();
  lcd.setCursor(player_x,player_y);
  lcd.write(0);
  lcd.setCursor(barrier_x--,barrier_y);
  lcd.write(1);

  if(player_x == barrier_x && player_y == barrier_y)
    {

    lcd.clear();
    lcd.print("Game over");
    lcd.setCursor(0,1);
    lcd.print("Press button");
    points=0;

    while( digitalRead(button) == LOW ){//если кнопка ненажата ...
    }
    
    delay(1000);
    lcd.clear();

    }

    if(player_x == barrier_x && player_y != barrier_y)
    {
      points++;
      if(delay_c > 50)
      { 
      delay_c-=50;
    }
    }

    if(barrier_x <=0)
    {
      barrier_x=15;
    }

    if (digitalRead(button) == HIGH && button_flag==false)//если кнопка нажата ...
    {
        player_y=0;
        button_flag=true;
    }
    else
    {
      player_y=1;
      button_flag=false;
    }

    lcd.setCursor(2,0);
    lcd.print(points);

    delay(500); 

    }      
