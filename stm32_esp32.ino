#include <HardwareSerial.h>

#define UART_TX 17
#define UART_RX 16

HardwareSerial mySerial(1); // UART1

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200, SERIAL_8N1, UART_RX, UART_TX);  // UART1 with custom RX/TX

  Serial.println("Sending message to STM32...");
  //Serial.println("Receiving message form STM32...");
}

void loop() {
  //========== UART Receive ==============
  /*
  if (mySerial.available()) {
    String message = mySerial.readStringUntil('\n'); // Message to receive (must include newline '/n' if STM32 sends it)
    Serial.print("Message reçu de STM32 : ");
    Serial.println(message);
  }
  */
  
  //========== UART Transmit ==============
  String message = "Hello STM32!\n";  // Message to send (must include newline '/n' if STM32 expects it)
  mySerial.print(message);
  Serial.println("Sent: " + message);
  
  delay(1000); // Send every second
}