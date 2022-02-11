#include <ESP32Servo.h> // Используем библиотеку ESP32Servo вместо стандартной Servo

// Объявление сервоприводов
Servo myservo1;
Servo myservo2;

// Константы для работы с сервоприводами
const int servoReadPin = 32; // Изменен пин для считывания аналогового значения, так как A4 может быть не доступен на ESP32
const int threshold = 3400; // Изменен пороговый уровень для соответствия 12-битному АЦП ESP32
const int servo1Pin = 5; // Пин подключения первого сервопривода
const int servo2Pin = 18; // Изменен пин, учитывая доступные пины ESP32
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
  myservo1.attach(servo1Pin, 500, 2400); // Указываем минимальные и максимальные широты импульсов
  myservo2.attach(servo2Pin, 500, 2400); // Для ESP32 может потребоваться настройка широты импульсов
  // Инициализация серийного порта
  Serial.begin(115200); // Изменена скорость для ESP32 для более быстрой передачи данных
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
