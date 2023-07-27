// 1. Masukan Library untuk DHT
#include <DHT.h>
#include <DHT_U.h>
// 2. definisikan pin DHTnya
int mrh = 2;
int kng = 3;
int hju = 4;
int dhtpin = 5;
// 3. definisikkan tipe DHT apakah DHT11 atau DHT12 
#define tipenyadht DHT11
// 4. inisialiasi sensor DHT
DHT dht(dhtpin, tipenyadht);

void setup() {
  // put your setup code here, to run once:
  // 5. aktifkan setup awal DHT
  pinMode(mrh, OUTPUT);
  pinMode(kng, OUTPUT);
  pinMode(hju, OUTPUT);
  
  dht.begin();
  Serial.begin(9600); //baud 9600
  delay(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 6. ambil data-data dari sensor (kelembapan + suhu-celcius)
  float h = dht.readHumidity();
  // Read temperature as celcius
  float t = dht.readTemperature();


  Serial.print("Suhu=");  //kirim serial "Suhu"
  Serial.print(t);     //kirim serial nilai suhu
  Serial.println("C");    //kirim serial "C" Celcius 
  Serial.print("Humi=");  //kirim serial "Humi"
  Serial.print(h);     //kirim serial nilai kelembaban
  Serial.println("%RH");  //kirim serial "%RH"

  delay(1000);

  if (t < 30){
    digitalWrite(mrh, HIGH);
    digitalWrite(kng, LOW);
    digitalWrite(hju, LOW);
  }

  if (t = 30){
    digitalWrite(mrh, LOW);
    digitalWrite(kng, HIGH);
    digitalWrite(hju, LOW);
  }

  if (t > 3){
    digitalWrite(mrh, LOW);
    digitalWrite(kng, LOW);
    digitalWrite(hju, HIGH);
  }
}

