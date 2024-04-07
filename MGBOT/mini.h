#include <WiFi.h>

class Mini
{
  public:
    Mini(){}
    ~Mini(){}

    Mini(const char* ip, int port)
    {
      this->ip = String(ip);
      this->port = port;
    }

    String get_ip()
    {
      return this->ip;
    }

    int get_port()
    {
      return this->port;
    }

    void connect()
    {
      Serial.print("Connect to mini:\n");
      while(!this->client.connect(this->ip.c_str(), this->port))
      {
        Serial.print(".");
        delay(500);
      }
    }

    void command(String cmd)
    {
      this->client.print(cmd);
    }

  private:
    WiFiClient client;
    String ip = "";
    int port = 50007;
};