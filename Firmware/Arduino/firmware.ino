#include <Servo.h>

// Объявление сервоприводов
Servo myservo1;
Servo myservo2;

// Константы для работы с сервоприводами
const int servoReadPin = A4; // Пин для считывания аналогового значения
const int threshold = 850; // Пороговое значение для активации сервоприводов
const int servo1Pin = 5; // Пин подключения первого сервопривода
const int servo2Pin = 6; // Пин подключения второго сервопривода
const int position1 = 0; // Позиция сервопривода 1
const int position2 = 90; // Позиция сервопривода 2

// Функция для перемещения сервоприводов в заданные позиции с задержками
void moveServos(int pos1, int pos2, unsigned long delayBefore, unsigned long delayAfter) {
  delay(delayBefore);
  myservo1.write(pos1);
  myservo2.write(pos2);
  delay(delayAfter);
}

void setup() {
  // Прикрепление сервоприводов к пинам
  myservo1.attach(servo1Pin);
  myservo2.attach(servo2Pin);
  // Инициализация серийного порта
  Serial.begin(9600);
}

void loop() {
  // Чтение значения с аналогового пина
  int val = analogRead(servoReadPin);
  Serial.println(val); // Вывод прочитанного значения в серийный порт

  // Проверка, превышает ли прочитанное значение порог
  if (val > threshold) {
    // Последовательное выполнение действий с сервоприводами с задержками
    moveServos(position1, position1, 0, 240);
    moveServos(position2, position2, 0, 1000);

    moveServos(position1, position1, 405, 0);
    moveServos(position2, position2, 0, 1000);

    moveServos(position1, position1, 425, 0);
    moveServos(position2, position2, 0, 1000);

    moveServos(position1, position1, 400, 0);
    moveServos(position2, position2, 0, 1000);

    moveServos(position1, position1, 385, 0);
    moveServos(position2, position2, 0, 1000);
  }
}
