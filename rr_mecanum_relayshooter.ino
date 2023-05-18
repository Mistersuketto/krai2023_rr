//==================================================================================================== mecanum
// variabel kecepatan arah x, y dan kecepatan rotasi
int Vx1;
int Vx2;

int Vy1;
int Vy2;

int Vw1;
int Vw2;

// masukan pada pin PWM
// motor1
#define R1_PWM 11
#define L1_PWM 10

// motor2
#define R2_PWM 9
#define L2_PWM 8

// motor3
#define R3_PWM 7
#define L3_PWM 6

// motor4
#define R4_PWM 5
#define L4_PWM 4
//==================================================================================================== kendali mecanum

//==================================================================================================== relay shooter
// variabel shooter
int shooton;
int shootoff;

// masukan pada pin relay
#define in_rly 19
//==================================================================================================== kendali relay shooter

void setup() {
  //==================================================================================================== memanggil fungsi serial
  Serial.begin(9600);

  //==================================================================================================== fungsi serial print untuk kendali mecanum
  Serial.println("1. Vx+");
  Serial.println("2. Vx-");
  Serial.println("3. Vy+");
  Serial.println("4. Vy-");
  Serial.println("5. Vx+ Vy+");
  Serial.println("6. Vx- Vx-");
  Serial.println("7. Vx- Vy+");
  Serial.println("8. Vx+ Vy-");
  Serial.println("9. Vw+");
  Serial.println("10. Vw-");
  //==================================================================================================== fungsi serial print untuk kendali mecanum

  //==================================================================================================== fungsi serial print untuk kendali relay shooter
  Serial.println(" ");
  Serial.println("11. shooter off");
  Serial.println("12. shooter on");
  //==================================================================================================== fungsi serial print untuk kendali relay shooter

  //==================================================================================================== inisialisasi pin PWM sebagai OUTPUT
  // motor1
  pinMode (R1_PWM, OUTPUT);
  pinMode (L1_PWM, OUTPUT);

  // motor2
  pinMode (R2_PWM, OUTPUT);
  pinMode (L2_PWM, OUTPUT);

  // motor3
  pinMode (R3_PWM, OUTPUT);
  pinMode (L3_PWM, OUTPUT);

  // motor4
  pinMode (R4_PWM, OUTPUT);
  pinMode (L4_PWM, OUTPUT);
  //==================================================================================================== inisialisasi pin PWM sebagai OUTPUT

  //==================================================================================================== inisialisasi pin input relay sebagai OUTPUT
  pinMode (in_rly, OUTPUT);
  //==================================================================================================== inisialisasi pin input relay sebagai OUTPUT
  
}

void loop() {
  //==================================================================================================== logika kendali mecanum
  Serial.println(" ");
  Serial.println("Pilih gerakan robot:");
  while (Serial.available() == 0){}

  int pilihgerakan = Serial.parseInt();

  switch (pilihgerakan) {
    case 1:
      // gerakan robot Vx+
      Serial.print("gerak kanan (Vx+)");
      // motor1
      analogWrite (R1_PWM, 60);
      analogWrite (L1_PWM, 0);

      // motor2
      analogWrite (R2_PWM, 60);
      analogWrite (L2_PWM, 0);
    
      // motor3
      analogWrite (R3_PWM, 0);
      analogWrite (L3_PWM, 60);
    
      // motor4
      analogWrite (R4_PWM, 0);
      analogWrite (L4_PWM, 60);
    
      delay(5000);
      break;
//======================================================== case1_Vx+

    case 2:
      // gerakan robot Vx-
      Serial.print("gerak kiri (Vx-)");
      // motor1
      analogWrite (R1_PWM, 0);
      analogWrite (L1_PWM, 60);
    
      // motor2
      analogWrite (R2_PWM, 0);
      analogWrite (L2_PWM, 60);
    
      // motor3
      analogWrite (R3_PWM, 60);
      analogWrite (L3_PWM, 0);
    
      // motor4
      analogWrite (R4_PWM, 60);
      analogWrite (L4_PWM, 0);
    
      delay(5000);
      break;
//======================================================== case2_Vx-

     case 3:
      // gerakan robot Vy+
      Serial.print("gerak maju (Vy+)");
      // motor1
      analogWrite (R1_PWM, 60);
      analogWrite (L1_PWM, 0);
    
      // motor2
      analogWrite (R2_PWM, 0);
      analogWrite (L2_PWM, 60);
    
      // motor3
      analogWrite (R3_PWM, 0);
      analogWrite (L3_PWM, 60);
    
      // motor4
      analogWrite (R4_PWM, 60);
      analogWrite (L4_PWM, 0);
    
      delay(5000);
      break;
//======================================================== case3_Vy+

     case 4:
      // gerakan robot Vy-
      Serial.print("gerak mundur (Vy-)");
      // motor1
      analogWrite (R1_PWM, 0);
      analogWrite (L1_PWM, 60);
    
      // motor2
      analogWrite (R2_PWM, 60);
      analogWrite (L2_PWM, 0);
    
      // motor3
      analogWrite (R3_PWM, 60);
      analogWrite (L3_PWM, 0);
    
      // motor4
      analogWrite (R4_PWM, 0);
      analogWrite (L4_PWM, 60);
    
      delay(5000);
      break;
//======================================================== case4_Vy-

     case 5:
      // gerakan robot Vx+ Vy+
      Serial.print("gerak serong kanan maju (Vx+ Vy+)");
      // motor1
      analogWrite (R1_PWM, 60);
      analogWrite (L1_PWM, 0);
    
      // motor2
      analogWrite (R2_PWM, 0);
      analogWrite (L2_PWM, 0);
    
      // motor3
      analogWrite (R3_PWM, 0);
      analogWrite (L3_PWM, 60);
    
      // motor4
      analogWrite (R4_PWM, 0);
      analogWrite (L4_PWM, 0);
    
      delay(5000);
      break;
//======================================================== case5_Vx+_Vy+

     case 6:
      // gerakan robot Vx- Vy-
      Serial.print("gerak serong kiri mundur (Vx- Vy-)");
      // motor1
      analogWrite (R1_PWM, 0);
      analogWrite (L1_PWM, 60);
    
      // motor2
      analogWrite (R2_PWM, 0);
      analogWrite (L2_PWM, 0);
    
      // motor3
      analogWrite (R3_PWM, 60);
      analogWrite (L3_PWM, 0);
    
      // motor4
      analogWrite (R4_PWM, 0);
      analogWrite (L4_PWM, 0);
    
      delay(5000);
      break;
//======================================================== case6_Vx-_Vy-

     case 7:
      // gerakan robot Vx- Vy+
      Serial.print("gerak serong kiri maju (Vx- Vy+)");
      // motor1
      analogWrite (R1_PWM, 0);
      analogWrite (L1_PWM, 0);
    
      // motor2
      analogWrite (R2_PWM, 0);
      analogWrite (L2_PWM, 60);
    
      // motor3
      analogWrite (R3_PWM, 0);
      analogWrite (L3_PWM, 0);
    
      // motor4
      analogWrite (R4_PWM, 60);
      analogWrite (L4_PWM, 0);
    
      delay(5000);
      break;
//======================================================== case7_Vx-_Vy+

     case 8:
      // gerakan robot Vx+ Vy-
      Serial.print("gerak serong kanan mundur (Vx+ Vy-)");
      // motor1
      analogWrite (R1_PWM, 0);
      analogWrite (L1_PWM, 0);
    
      // motor2
      analogWrite (R2_PWM, 60);
      analogWrite (L2_PWM, 0);
    
      // motor3
      analogWrite (R3_PWM, 0);
      analogWrite (L3_PWM, 0);
    
      // motor4
      analogWrite (R4_PWM, 0);
      analogWrite (L4_PWM, 60);
    
      delay(5000);
      break;
//======================================================== case8_Vx+_Vy-

     case 9:
      // gerakan robot Vw+
      Serial.print("gerak rotasi cw (Vw+)");
      // motor1
      analogWrite (R1_PWM, 0);
      analogWrite (L1_PWM, 60);
    
      // motor2
      analogWrite (R2_PWM, 0);
      analogWrite (L2_PWM, 60);
    
      // motor3
      analogWrite (R3_PWM, 0);
      analogWrite (L3_PWM, 60);
    
      // motor4
      analogWrite (R4_PWM, 0);
      analogWrite (L4_PWM, 60);
    
      delay(5000);
      break;
//======================================================== case9_Vw+

     case 10:
      // gerakan robot Vw-
      Serial.print("gerak rotasi ccw (Vw-)");
      // motor1
      analogWrite (R1_PWM, 60);
      analogWrite (L1_PWM, 0);
    
      // motor2
      analogWrite (R2_PWM, 60);
      analogWrite (L2_PWM, 0);
    
      // motor3
      analogWrite (R3_PWM, 60);
      analogWrite (L3_PWM, 0);
    
      // motor4
      analogWrite (R4_PWM, 60);
      analogWrite (L4_PWM, 0);
    
      delay(5000);
      break;
//======================================================== case10_Vw-

    default:
      Serial.println(" ");
      Serial.println("janji robotnya jadi!!");
      
  }
  //==================================================================================================== logika kendali mecanum

  //==================================================================================================== logika kendali relay
  Serial.println(" ");
  Serial.println("Pilih kondisi shooter:");
  while (Serial.available() == 1){}

  int penembak = Serial.parseInt ();

  switch (penembak) {
  
    case 11:
    // reload ring
    Serial.print ("shooter off");

    // relay mati
    digitalWrite (in_rly, HIGH);

    break;
    //=============================== case1_menembak ring

    case 12:
    // melempar ring
    Serial.print ("shooter on");

    // relay mendapat sinyal input
    digitalWrite (in_rly, LOW);

    break;
    //=============================== case2_reload ring

   default:
    Serial.println (" ");
    Serial.println ("janji robotnya jadi!!");
    
  }

}
