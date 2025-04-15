#include <Arduino.h>
#include <LiquidCrystal.h>

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);


// Animation state: {x, y, custom byte ID}
int ani_state[18][3] = 
{ 
  {0, 1, 4},
  {0, 1, 5},
  {0, 0, 0},
  {1, 0, 1},
  {2, 0, 2},
  {3, 1, 3},
  {4, 1, 4},
  {5, 1, 5},
  {6, 0, 0},
  {7, 0, 1},
  {8, 0, 2},
  {9, 1, 3},
  {10, 1, 4},
  {11, 1, 5},
  {12, 0, 0},
  {13, 0, 1},
  {14, 0, 2},
  {15, 1, 3}

};

// Define custom sine wave characters
void create_sine_chars()
{
  byte part1[8] =
{
  0b00000,
  0b00000,
  0b00001,
  0b00010,
  0b00100,
  0b01000,
  0b01000,
  0b10000
};

byte part2[8] =
{
  0b00000,
  0b01110,
  0b10001,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
byte part3[8] =
{
  0b00000,
  0b00000,
  0b10000,
  0b01000,
  0b00100,
  0b00010,
  0b00010,
  0b00001
  };

byte part4[8] =
{
  0b10000,
  0b01000,
  0b01000,
  0b00100,
  0b00010,
  0b00001,
  0b00000,
  0b00000
};

byte part5[8] =
{
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte part6[8] =
{
  0b00001,
  0b00010,
  0b00010,
  0b00100,
  0b01000,
  0b10000,
  0b00000,
  0b00000
};
  // Load the custom character into the LCD
	lcd.createChar(0, part1);
  lcd.createChar(1, part2);
  lcd.createChar(2, part3);
  lcd.createChar(3, part4);
  lcd.createChar(4, part5);
  lcd.createChar(5, part6);

}

// Render and animate the sine wave
void sinewave(LiquidCrystal lcd,int speed = 100)
{

lcd.clear();

  // Render the sine wave on the screen
  for (size_t i = 2; i < 18; i++)
  {
    lcd.setCursor(ani_state[i][0], ani_state[i][1]);
	  lcd.write(byte(ani_state[i][2]));
  }

  // Save the first element to wrap it around
  int btye_id = ani_state[0][2];
  int col = ani_state[0][1];

  // Shift all elements to the left
  for (size_t i = 0; i < 17; i++)

  {
    // switch out the col and btye id for the next btye and col in the list 
    ani_state[i][2] = ani_state[i + 1][2];
    ani_state[i][1] = ani_state[i + 1][1];

  }

  // Wrap the first element to the end
  ani_state[17][2] = btye_id;
  ani_state[17][1] = col;
  
  // Delay for animation speed
	delay(speed);

}

void setup() 
{
  // Initialize the LCD with 16 columns and 2 rows
	lcd.begin(16, 2);
  
  // Load custom sine wave characters
  create_sine_chars();

	// Clears the LCD screen
	lcd.clear();
}

void loop() 
{
  // run sine wave animation
  sinewave(lcd, 300);
  
}