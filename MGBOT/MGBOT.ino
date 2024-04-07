#include <WiFi.h>
#include "mini.h"

Mini mini = Mini("", 50007);
const char* ssid     = ""; // WiFi SSID общей сети
const char* password = "";    // пароль от WiFi

const char* host = "";   // ip сервера, на котором запущенна программа управления mini
const int httpPort = 50007;           // порт сервера

void setup()
{
    Serial.begin(115200);
    while(!Serial)
    {
      delay(100);
    }

    Serial.println();
    Serial.println("******************************************************");
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    mini.connect();
}

void loop()
{
  /*
  Тут пишем основную часть программы для отправки команд на квадрокоптер,
  используем метод command. Команды, которые можно передавать на квадрокоптер 
  должны быть вида mini.<команда из документации pioneer_sdk>
  */

  mini.command("mini.arm()");
  delay(5000);
  mini.command("mini.disarm()");
  delay(10000);
}