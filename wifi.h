#include <WiFi.h>

#define WIFI_SSID "ziroom1601"
#define WIFI_PASSWORD "4001001234"
//#define WIFI_SSID "rigongyizu"
//#define WIFI_PASSWORD "xiaozu100000"

#define NTP_SERVER "ntp.aliyun.com"
#define TIME_ZONE_OFFSET_SECONDS 8 * 60 *60
#define DAY_LIGHT_OFFSET_SECONDS 0

void wifiStartUp() {
  //connect to WiFi
  Serial.printf("Connecting to %s ", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" CONNECTED");

  configTime(TIME_ZONE_OFFSET_SECONDS, DAY_LIGHT_OFFSET_SECONDS, NTP_SERVER);

  delay(5000);

  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void getCurrentTime(char* s) {
  time_t now;
  char strftime_buf[64];
  struct tm timeinfo;

  time(&now);
  // 将时区设置为中国标准时间
  setenv("TZ", "CST-8", 1);
  tzset();

  localtime_r(&now, &timeinfo);
  strftime(strftime_buf, sizeof(strftime_buf), "%F %H:%M", &timeinfo);

  Serial.println(timeinfo.tm_year);

  strcpy(s, strftime_buf);
}
