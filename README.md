# MGBOT - PIONEER

![схема взаимодействия](https://github.com/shvecov-coder/mgbottopioneer/blob/main/img/shema.png)

---

![run](https://github.com/shvecov-coder/mgbottopioneer/blob/main/img/mgbotpioneer.gif?raw=true)

---

1. Необходимо построить одну локальную сеть для подключения мини, динамика и сервера
2. Включите квадрокоптер и подключитесь к нему через приложение Geoscan Jump
3. Подключите квадрокоптер к общей WiFi сети. После подключения вы будете знать ip квадрокоптера в сети.
4. В программе сервера укажите ip квадрокоптера при создании экземпляра класса mini
5. Подключите сервер к общей с квадрокоптером WiFi сети и запустите программу.
(для запуска потребуется установка библиотеки pioneer-sdk)
6. Можно перейти к программированию динамики.
```
Mini mini = Mini("", 50007);
const char* ssid     = ""; // WiFi SSID общей сети
const char* password = "";    // пароль от WiFi

const char* host = "";   // ip сервера, на котором запущенна программа управления mini
const int httpPort = 50007;           // порт сервера
```
Пустые строки необходимо заполнить данными:
Mini(<ip квадрокоптера>, 50007)
ssid - имя WiFi сети
password - пароль от WiFi сети
host - ip сервера на котором запущенна программа для обработки команд (узнать ip можно в консоли командой ipconfig)
Команды передаются на квадрокоптер через метод command в виде mini.<команда из документации pioneer_sdk>