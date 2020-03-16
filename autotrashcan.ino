/*
Designed by CanIT
https://canduino.kr
*/
#include <Servo.h>   // 서보모터 라이브러리 삽입 (IDE 내장 라이브러리)

Servo myservo;  // myservo 객체 생성

int trigPin = 4;   // 초음파센서 Trig 연결핀
int echoPin = 3;   // 초음파센서 Echo 연결핀

int pwmPin = 6;   // 서보모터 pwm 연결핀 (보통 주황색 선이지만 제조사마다 다를 수 있음)

int standard = 10;    // 초음파센서 기준 반응 거리

void setup() {
  // 핀모드를 설정합니다.
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myservo.attach(pwmPin);  // 서보모터 핀 세팅
}

void loop() {
  // 초음파센서로 거리를 측정합니다.
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  int distance = pulseIn(echoPin, HIGH) / 58;   // cm로 변환하기 위해 58로 나눔

  // 측정된 거리가 기준 거리보다 작으면 서보모터 작동
  // 아닐시 서보모터 원위치
  if (distance < standard) {
    myservo.write(180);
  } else {
    myservo.write(0);
  }
}
