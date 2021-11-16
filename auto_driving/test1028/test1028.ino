
void setup() {
  remote_setup();
}


void loop() {
 remote_loop();
 motor_loop();
}

void remote_setup() {
  Serial.begin(9600);  
}

void remote_loop() {
  //원격 입력 : 주행과 조항을 위한 모터 제어, 전조등과 후미등을위한 LED제어, 경적을 위한 부저 제어함수
  check_remote_input();   //원격 입력 확인
  distribute_remote_input();   //원격 입력 분배
}

char remote_input;
bool remote_input_changed = false;

void check_remote_input() {
  if(Serial.available()) {  //시리얼 모듈에 도착한 문자의 개수가 1개 이상인지 확인, 문자의 개수 리턴
    char r_data = Serial.read();

    if(r_data != remote_input){
      remote_input = r_data;
      remote_input_changed = true;   //원격 입력 변경
    }
  }
}


 /*SERIAL*/
enum {
  GOFORWARD = 'f',
  GOBACKWARD = 'b',
  TURNLEFT = 'l',
  TURNRIGHT = 'r',
  STOP = 's', 

  //조향
  GOFORWARDLEFT ='g',
  GOFORWARDRIGHT ='i',
  GOBACKWARDLEFT ='h',
  GOBACKWARDRIGHT ='j', 
};


/*BLUETOOTH*/
enum { 
  GOFORWARDBLUETOOTH = 'F',
  GOBACKWARDBLUETOOTH = 'B',
  TURNLEFTBLUETOOTH = 'L',
  TURNRIGHTBLUETOOTH = 'R',
  STOPBLUETOOTH = 'S', 
  GOFORWARDLEFTBLUETOOTH = 'G',
  GOFORWARDRIGHTBLUETOOTH = 'I',
  GOBACKWARDLEFTBLUETOOTH = 'H',
  GOBACKWARDRIGHTBLUETOOTH = 'J',
}; 


/*SPEED*/
enum {
  SPEED_0 = '0',
  SPEED_1 = '1',
  SPEED_2 = '2',
  SPEED_3 = '3',
  SPEED_4 = '4',
  SPEED_5 = '5',
  SPEED_6 = '6',
  SPEED_7 = '7',
  SPEED_8 = '8',
  SPEED_9 = '9',
  SPEED_10 = 'q',   
}; 

#define MAX_SPEED 255
#define MIN_SPEED 0

char driving_action = STOP;
bool driving_action_changed = false;

char driving_speed_input = SPEED_0;
int driving_speed = MIN_SPEED;
bool driving_speed_changed = false;

void distribute_remote_input() {
  if(remote_input_changed) {
    remote_input_changed = false;
  
    // 대문자를 소문자로 변경
    if(remote_input == GOFORWARDBLUETOOTH ||
      remote_input == GOBACKWARDBLUETOOTH ||
      remote_input == TURNLEFTBLUETOOTH ||
      remote_input == TURNRIGHTBLUETOOTH ||
      remote_input == STOPBLUETOOTH ||
      remote_input == GOFORWARDLEFTBLUETOOTH ||
      remote_input == GOFORWARDRIGHTBLUETOOTH ||
      remote_input == GOBACKWARDLEFTBLUETOOTH ||
      remote_input == GOBACKWARDRIGHTBLUETOOTH) {
      remote_input = remote_input - 'A' + 'a';
    }

    if(remote_input == GOFORWARD ||
      remote_input == GOBACKWARD ||
      remote_input == TURNLEFT ||
      remote_input == TURNRIGHT ||
      remote_input == STOP ||
      remote_input == GOFORWARDLEFT ||
      remote_input == GOFORWARDRIGHT ||
      remote_input == GOBACKWARDLEFT ||
      remote_input == GOBACKWARDRIGHT) {
      driving_action = remote_input;
      driving_action_changed = true; 
    } else if(remote_input == SPEED_0 ||
      remote_input == SPEED_1 ||
      remote_input == SPEED_2 ||
      remote_input == SPEED_3 ||
      remote_input == SPEED_4 ||
      remote_input == SPEED_5 ||
      remote_input == SPEED_6 ||
      remote_input == SPEED_7 ||
      remote_input == SPEED_8 ||
      remote_input == SPEED_9 ||
      remote_input == SPEED_10) {
      driving_speed_input = remote_input;
      driving_speed_changed = true;        
    }
  }
}
