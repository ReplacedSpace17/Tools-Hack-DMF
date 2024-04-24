#include <WiFi.h>

const char* ssid = "TuSSID";           // Nombre de tu red WiFi
const char* password = "TuClave";      // Contraseña de tu red WiFi

const char* host = "api.ejemplo.com";  // Dominio de la API
const int port = 80;                   // Puerto HTTP (usualmente 80 para HTTP)

void setup() {
  Serial.begin(115200);

  // Conectar a la red WiFi
  WiFi.begin(ssid, password);
  Serial.print("Conectando a la red WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Conexión WiFi establecida.");
}

void loop() {
  // Creamos un objeto de cliente WiFi para la comunicación HTTP
  WiFiClient client;
  
  // Conectamos al servidor HTTP
  if (!client.connect(host, port)) {
    Serial.println("Error al conectar al servidor HTTP.");
    return;
  }
  
  // Creamos la solicitud HTTP
  String url = "/endpoint";  // Ruta del endpoint de la API
  String request = "GET " + url + " HTTP/1.1\r\n" +
                   "Host: " + host + "\r\n" +
                   "Connection: close\r\n\r\n";
  
  // Enviamos la solicitud HTTP al servidor
  client.print(request);
  Serial.println("Solicitud enviada.");

  // Esperamos la respuesta del servidor
  while (client.connected()) {
    if (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
  }

  // Cerramos la conexión
  client.stop();

  // Esperamos antes de enviar la siguiente solicitud
  delay(5000);  // Espera 5 segundos entre cada solicitud
}
