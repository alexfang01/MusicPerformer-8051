#include <reg51.h>

// music part
// music button declaration
void delay(unsigned int);
void C4(unsigned int);
void D4(unsigned int);
void E4(unsigned int);
void F4(unsigned int);
void G4(unsigned int);
void A4(unsigned int);
void B4(unsigned int);
void C5(unsigned int);
void auto_song();

sbit mybit = P1^3;
sbit c1 = P3^0;
sbit d = P3^1;
sbit e = P3^2;
sbit f = P3^3;
sbit g = P3^4;
sbit a = P3^5;
sbit b = P3^6;
sbit c = P3^7;
sbit song = P1^6;
sbit led = P1^4;

// motor part
void delay_on0(unsigned int);
void delay_off0(unsigned int);
void delay_on90(unsigned int);
void delay_off90(unsigned int);
	
sbit motor_pin = P1^7;
// LCD part
// Define LCD pins using sbit (bit-addressable)
sbit RS_PIN = P1^0; // Register Select
sbit RW_PIN = P1^1; // Read/Write
sbit E_PIN = P1^2;  // Enable

// Delay function
void delay(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++); // Simple delay loop
}

// Send command to LCD
void lcd_command(unsigned char command) {
    RS_PIN = 0;       // Command mode
    RW_PIN = 0;       // Write mode
    P2 = command;     // Put command on data port
    E_PIN = 1;        // Enable pin high
    delay(1);         // Wait for a short period
    E_PIN = 0;        // Enable pin low
}

// Write data to LCD
void lcd_write_data(unsigned char value) {
    RS_PIN = 1;       // Data mode
    RW_PIN = 0;       // Write mode
    P2 = value;       // Put data on data port
    E_PIN = 1;        // Enable pin high
    delay(1);         // Wait for a short period
    E_PIN = 0;        // Enable pin low
}

// Initialize the LCD
void lcd_init() {
    lcd_command(0x38); // Function set: 8-bit mode, 2-line display
	delay(1);  
    lcd_command(0x0E); // Display ON, cursor OFF
	delay(1);  
    lcd_command(0x01); // Clear display
	delay(1);  
    lcd_command(0x06); // Entry mode: Increment cursor
    delay(1);         // Wait for LCD to initialize
}

// Print string to LCD
void lcd_print(const char *str) {
    while(*str) {
        lcd_write_data(*str++); // Write each character
			delay(1); 
    }
}

// turn motor function
void receive_money(){
		unsigned int i, j;
	
			for(i=0; i< 100; i++){
				//Turn to 0 degree
				motor_pin = 1;
				delay_on0(1);
				motor_pin = 0;
				delay_off0(1);
			}
			for(j=0; j< 100; j++){
				//Turn to 0 degree
				motor_pin = 1;
				delay_on90(1);
				motor_pin = 0;
				delay_off90(1);
			}

}


void main(void) {
	
			unsigned int flag_display = 0;
			unsigned int flag_timer = 0;
			c1 = 1; // set as input
			d = 1; // set as input
			e = 1; // set as input
			f = 1; // set as input
			g = 1; // set as input
			a = 1; // set as input
			b = 1; // set as input
			c = 1; // set as input
			motor_pin = 0;
	
			TMOD = 0x01;
			TL0=0x00;  
			TH0=0x00;
			lcd_init(); // Initialize the LCD
			lcd_print("No Performance"); // Print the string
			
		
    while (1) {
				
				if(TF0 == 1){
					flag_timer += 1;
					TF0 = 0;
					TR0 = 1;
				}
				
				// around 4 seconds will indicate music stop and 
				if(flag_timer > 70 && flag_timer < 72){
					lcd_init(); // Initialize the LCD
					lcd_print("Music Stop..."); // Print the string
				}
				
				if(flag_timer > 90){
					lcd_init(); // Initialize the LCD
					lcd_print("Thank you!!"); // Print the string
					flag_display = 0;
					flag_timer = 0;
					TF0 = 0;
					TR0 = 0;
					receive_money();
				}
				
				if(flag_display == 1){
						lcd_init(); // Initialize the LCD
						lcd_print("Music Start!!"); // Print the string
				}
				
				if (song == 0) {
						//reset timer and flag
						TL0=0x00;  
						TH0=0x00;
						TR0 = 1;
						flag_timer = 0;
						lcd_init(); // Initialize the LCD
						lcd_print("Auto Play Song!"); // Print the string
						flag_display += 2;
						auto_song();
				}
				
				if (c1 == 0) {  // Button pressed
						mybit = ~mybit;  // Toggle buzzer
						C4(1);
						//reset timer and flag
						TL0=0x00;  
						TH0=0x00;
						TR0 = 1;
						flag_timer = 0;
						flag_display += 1;
				}
				if (d == 0) {  // Button pressed
						mybit = ~mybit;  // Toggle buzzer
						D4(1);
						TL0=0x00;  
						TH0=0x00;
						TR0 = 1;
						flag_timer = 0;
						flag_display += 1;
				}
				if (e == 0) {  // Button pressed
						mybit = ~mybit;  // Toggle buzzer
						E4(1);
						TL0=0x00;  
						TH0=0x00;
						TR0 = 1;
						flag_timer = 0;
						flag_display += 1;
				}
				if (f == 0) {  // Button pressed
						mybit = ~mybit;  // Toggle buzzer
						F4(1);
						TL0=0x00;  
						TH0=0x00;
						TR0 = 1;
						flag_timer = 0;
						flag_display += 1;
				}
				if (g == 0) {  // Button pressed
						mybit = ~mybit;  // Toggle buzzer
						G4(1);
						TL0=0x00;  
						TH0=0x00;
						TR0 = 1;
						flag_timer = 0;
						flag_display += 1;
				}
				if (a == 0) {  // Button pressed
						mybit = ~mybit;  // Toggle buzzer
						A4(1);
						TL0=0x00;  
						TH0=0x00;
						TR0 = 1;
						flag_timer = 0;
						flag_display += 1;
				}
				if (b == 0) {  // Button pressed
						mybit = ~mybit;  // Toggle buzzer
						B4(1);
						TL0=0x00;  
						TH0=0x00;
						TR0 = 1;
						flag_timer = 0;
						flag_display += 1;
				}
				if (c == 0) {  // Button pressed
						mybit = ~mybit;  // Toggle buzzer
						C5(1);
						TL0=0x00;  
						TH0=0x00;
						TR0 = 1;
						flag_timer = 0;
						flag_display += 1;
				}
    }
}

// button function declaration
void C4(unsigned int itime) {
    unsigned int i, j;
    for (i = 0; i < itime; i++) {
        for (j = 0; j < 216; j++);
    }
}

void D4(unsigned int itime) {
    unsigned int i, j;
    for (i = 0; i < itime; i++) {
        for (j = 0; j < 192; j++);
    }
}

void E4(unsigned int itime) {
    unsigned int i, j;
    for (i = 0; i < itime; i++) {
        for (j = 0; j < 170; j++);
    }
}

void F4(unsigned int itime) {
    unsigned int i, j;
    for (i = 0; i < itime; i++) {
        for (j = 0; j < 160; j++);
    }
}

void G4(unsigned int itime) {
    unsigned int i, j;
    for (i = 0; i < itime; i++) {
        for (j = 0; j < 142; j++);
    }
}

void A4(unsigned int itime) {
    unsigned int i, j;
    for (i = 0; i < itime; i++) {
        for (j = 0; j < 125; j++);
    }
}

void B4(unsigned int itime) {
    unsigned int i, j;
    for (i = 0; i < itime; i++) {
        for (j = 0; j < 113; j++);
    }
}

void C5(unsigned int itime) {
    unsigned int i, j;
    for (i = 0; i < itime; i++) {
        for (j = 0; j < 106; j++);
    }
}

// AUTO PLAY MUSIC
void auto_song(){
	unsigned int i;
// 	crotchet for C4
//	for(i=0; i< 258; i++){
//		mybit = ~mybit;
//		C4(1);
//	}

// 	crotchet for D4
//	for(i=0; i< 290; i++){
//		mybit = ~mybit;
//		D4(1);
//	}
	
// 	crotchet for E4
//	for(i=0; i< 328; i++){
//		mybit = ~mybit;
//		E4(1);
//	}
	
// 	crotchet for F4
//	for(i=0; i< 348; i++){
//		mybit = ~mybit;
//		F4(1);
//	}

// 	crotchet for G4
//	for(i=0; i< 392; i++){
//		mybit = ~mybit;
//		G4(1);
//	}

// 	crotchet for A4
//	for(i=0; i< 445; i++){
//		mybit = ~mybit;
//		A4(1);
//	}

// 	crotchet for B4
//	for(i=0; i< 493; i++){
//		mybit = ~mybit;
//		B4(1);
//	}

// 	crotchet for C5
//	for(i=0; i< 525; i++){
//		mybit = ~mybit;
//		C5(1);
//	}
	
	for(i=0; i< 392; i++){
		mybit = ~mybit;
		G4(1);
	}
	led = 1;
	for(i=0; i< 2000; i++); // delay for note stop
	for(i=0; i< 392; i++){
		mybit = ~mybit;
		G4(1);
	}
	led = 0;
	for(i=0; i< 2000; i++);
	for(i=0; i< 392; i++){
		mybit = ~mybit;
		G4(1);
	}
	led = 1;
	for(i=0; i< 2000; i++);
	for(i=0; i< 290; i++){
		mybit = ~mybit;
		D4(1);
	}
	led = 0;
	for(i=0; i< 2000; i++);
	
	for(i=0; i< 328; i++){
		mybit = ~mybit;
		E4(1);
	}
	led = 1;
	for(i=0; i< 2000; i++);
	for(i=0; i< 328; i++){
		mybit = ~mybit;
		E4(1);
	}
	led = 0;
	for(i=0; i< 2000; i++);
	for(i=0; i< 580; i++){
		mybit = ~mybit;
		D4(1);
	}
	led = 1;
	for(i=0; i< 2000; i++);

	for(i=0; i< 493; i++){
		mybit = ~mybit;
		B4(1);
	}
	led = 0;
	for(i=0; i< 2000; i++);
	for(i=0; i< 493; i++){
		mybit = ~mybit;
		B4(1);
	}
	led = 1;
	for(i=0; i< 2000; i++);
	for(i=0; i< 445; i++){
		mybit = ~mybit;
		A4(1);
	}
	led = 0;
	for(i=0; i< 2000; i++);
	for(i=0; i< 445; i++){
		mybit = ~mybit;
		A4(1);
	}
	led = 1;
	for(i=0; i< 2000; i++);
	
	for(i=0; i< 1176; i++){
		mybit = ~mybit;
		G4(1);
	}
	led = 0;
	for(i=0; i< 2000; i++);
	
	for(i=0; i< 290; i++){
		mybit = ~mybit;
		D4(1);
	}
	led = 1;
	for(i=0; i< 2000; i++);
	for(i=0; i< 392; i++){
		mybit = ~mybit;
		G4(1);
	}
	led = 0;
	for(i=0; i< 2000; i++);
	for(i=0; i< 392; i++){
		mybit = ~mybit;
		G4(1);
	}
	led = 1;
	for(i=0; i< 2000; i++);
	for(i=0; i< 392; i++){
		mybit = ~mybit;
		G4(1);
	}
	led = 0;
	for(i=0; i< 2000; i++);
	
	for(i=0; i< 290; i++){
		mybit = ~mybit;
		D4(1);
	}
	led = 1;
	for(i=0; i< 2000; i++);
	for(i=0; i< 328; i++){
		mybit = ~mybit;
		E4(1);
	}
	led = 0;
	for(i=0; i< 2000; i++);
	for(i=0; i< 328; i++){
		mybit = ~mybit;
		E4(1);
	}
	led = 1;
	for(i=0; i< 2000; i++);
	for(i=0; i< 580; i++){
		mybit = ~mybit;
		D4(1);
	}
	led = 0;
	for(i=0; i< 2000; i++);
	
	for(i=0; i< 493; i++){
		mybit = ~mybit;
		B4(1);
	}
	led = 1;
	for(i=0; i< 2000; i++);
	for(i=0; i< 493; i++){
		mybit = ~mybit;
		B4(1);
	}
	led = 0;
	for(i=0; i< 2000; i++);
	for(i=0; i< 445; i++){
		mybit = ~mybit;
		A4(1);
	}
	led = 1;
	for(i=0; i< 2000; i++);
	for(i=0; i< 445; i++){
		mybit = ~mybit;
		A4(1);
	}
	led = 0;
	for(i=0; i< 2000; i++);
	
	for(i=0; i< 1176; i++){
		mybit = ~mybit;
		G4(1);
	}
	led = 1;
	for(i=0; i< 2000; i++);
	
}

// motor function
// 2227 magic number for both loop sum
void delay_on0(unsigned int itime)
{
   unsigned int i, j;
	for(i=0; i<itime; i++){
		for(j=0; j<54; j++);
	}
}

void delay_off0(unsigned int itime)
{
   unsigned int i, j;
	for(i=0; i<itime; i++){
		for(j=0; j<2173; j++);
	}
}
void delay_on90(unsigned int itime)
{
   unsigned int i, j;
	for(i=0; i<itime; i++){
		for(j=0; j<173; j++);
	}
}

void delay_off90(unsigned int itime)
{
   unsigned int i, j;
	for(i=0; i<itime; i++){
		for(j=0; j<2054; j++);
	}
}


