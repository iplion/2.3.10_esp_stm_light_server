#include <WiFi.h>
#include "driver/uart.h"
//#include "driver/gpio.h"
#include "lib/html.h"
#include "lib/uart.h"

#include "lib/wifi.h"
//#define WIFISSID "YourNet"
//#define WIFIPASS "YourPass"

bool led_state  = false;
uint8_t LED = 23;


WiFiServer server(80);

const uart_port_t uart_num = UART_NUM_2;
char writeBuf[44];
uint16_t counter = 0;
int8_t onLevel = -1, offLevel = -1, currentLevel = -1;
uint8_t dataBuf[24];
uint8_t dataLength;

void setup()
{
    Serial.begin(115200);
    delay(2000);
    WiFi.begin(WIFISSID,WIFIPASS);
    while(WiFi.status() != wl_status_t::WL_CONNECTED){
        Serial.print(".");
        delay(1000);
    }  
    Serial.println("\n\rConnected");
    Serial.println(WiFi.localIP());
    //pinMode(LED, OUTPUT);
    //digitalWrite(LED,LOW);
    server.begin();

    uart_config_t uart_config = {
      .baud_rate = 1200,
      .data_bits = UART_DATA_8_BITS,
      .parity = UART_PARITY_DISABLE,
      .stop_bits = UART_STOP_BITS_1,
      .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
      .rx_flow_ctrl_thresh = 122,
    };
    // Configure UART parameters
    ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
    // Set UART pins(TX: IO4, RX: IO5, RTS: IO18, CTS: IO19)
    ESP_ERROR_CHECK(uart_set_pin(UART_NUM_2, 17, 16, \
                                 UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
    // Setup UART buffered IO with event queue
    const int uart_buffer_size = (1024 * 2);
    QueueHandle_t uart_queue;
    // Install UART driver using an event queue here
    ESP_ERROR_CHECK(uart_driver_install(UART_NUM_2, uart_buffer_size, \
                                        uart_buffer_size, 10, &uart_queue, 0));
}
void loop()
{
    WiFiClient client = server.available();

    if (client){
        while(client.connected()){
            if (client.available()){    
                //client.println(HTML_PAGE);
                String line = client.readStringUntil('\n');
                Serial.print(line);
                
                if(line.indexOf("GET / ") >= 0){
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-type:text/html");
                    client.println("Connection: close");
                    client.println(); 
                    Serial.println("Send OK");
                    client.println(HTML_PAGE);    
                } else if (line.indexOf("POST /currlightlevel ") >= 0){
                    dataLength = dataCreate(writeBuf, GET_CURR_LIGHT_LEVEL, 0);
                    uart_write_bytes(uart_num, (const char*)writeBuf, dataLength);
                    if (uart_read_bytes(uart_num, dataBuf, 1, 200) != -1) {
                      if ((uart_read_bytes(uart_num, (dataBuf+1), (dataBuf[0]+1), 200) != -1) && (dataDecrypt((char*)dataBuf) == CURR_LIGHT_LEVEL)) {
                        Serial.printf("\ndataBuf(CURR) = OK; b0=%d;b1=%d;b2=%d;b3=%d;\n", dataBuf[0], dataBuf[1], dataBuf[2], dataBuf[3]);
                        client.print(dataBuf[2]);
                      } else {
                        Serial.printf("\nfrom stm data1: no data;\n");
                        client.print("...");
                      }
                    } else {
                      Serial.printf("\nfrom stm data0: no data;\n");
                      client.print("...");
                    }
                    Serial.println("\ntransived: POST /currlightlevel");
                } else if (line.indexOf("POST /currledstate ") >= 0){
                    dataLength = dataCreate(writeBuf, GET_LED_STATE, 0);
                    uart_write_bytes(uart_num, (const char*)writeBuf, dataLength);
                    if (uart_read_bytes(uart_num, dataBuf, 1, 200) != -1) {
                      if ((uart_read_bytes(uart_num, (dataBuf+1), (dataBuf[0]+1), 200) != -1) && (dataDecrypt((char*)dataBuf) == CURR_LED_STATE)) {
                        Serial.printf("\ndataBuf(LED) = OK; b0=%d;b1=%d;b2=%d;b3=%d;\n", dataBuf[0], dataBuf[1], dataBuf[2], dataBuf[3]);
                        client.print(dataBuf[2]);
                      } else {
                        Serial.printf("\nfrom stm data1: no data;\n");
                        client.print("...");
                      }
                    } else {
                      Serial.printf("\nfrom stm data0: no data;\n");
                      client.print("...");
                    }
                    Serial.println("\ntransived: POST /currledstate");
                } else if (line.indexOf("POST /onlightlevel ") >= 0){
                    dataLength = dataCreate(writeBuf, GET_ON_LIGHT_LEVEL, 0);
                    uart_write_bytes(uart_num, (const char*)writeBuf, dataLength);
                    if (uart_read_bytes(uart_num, dataBuf, 1, 200) != -1) {
                      if ((uart_read_bytes(uart_num, (dataBuf+1), (dataBuf[0]+1), 200) != -1) && (dataDecrypt((char*)dataBuf) == ON_LIGHT_LEVEL)) {
                        Serial.printf("\ndataBuf(ON) = OK; b0=%d;b1=%d;b2=%d;b3=%d;\n", dataBuf[0], dataBuf[1], dataBuf[2], dataBuf[3]);
                        client.print(dataBuf[2]);
                      } else {
                        Serial.printf("\nfrom stm data1(ON): no data;\n");
                        client.print("...");
                      }
                    } else {
                      Serial.printf("\nfrom stm data0(ON): no data;\n");
                      client.print("...");
                    }
                    Serial.println("\ntransived: POST /onlightlevel");
                } else if (line.indexOf("POST /offlightlevel ") >= 0){
                    dataLength = dataCreate(writeBuf, GET_OFF_LIGHT_LEVEL, 0);
                    uart_write_bytes(uart_num, (const char*)writeBuf, dataLength);
                    if (uart_read_bytes(uart_num, dataBuf, 1, 200) != -1) {
                      if ((uart_read_bytes(uart_num, (dataBuf+1), (dataBuf[0]+1), 200) != -1) && (dataDecrypt((char*)dataBuf) == OFF_LIGHT_LEVEL)) {
                        Serial.printf("\ndataBuf(OFF) = OK; b0=%d;b1=%d;b2=%d;b3=%d;\n", dataBuf[0], dataBuf[1], dataBuf[2], dataBuf[3]);
                        client.print(dataBuf[2]);
                      } else {
                        Serial.printf("\nfrom stm data1(OFF): no data;\n");
                        client.print("...");
                      }
                    } else {
                      Serial.printf("\nfrom stm data0(OFF): no data;\n");
                      client.print("...");
                    }
                    Serial.println("\ntransived: POST /offlightlevel");
                } else if (line.indexOf("POST /setlevels") >= 0){
                    Serial.printf("\ntransived: POST /setlevels");
                    uint8_t i = 0;
                    while (line[i++] != '?') {}
                    uint8_t level = line[i++] - 48;
                    while (line[i] != '?') {
                      level = (level * 10) + (line[i++] - 48);
                    }
                    Serial.printf("\nPOST /setlevels, ON = %u", level);
                    dataLength = dataCreate(writeBuf, ON_LIGHT_LEVEL, level);
                    uart_write_bytes(uart_num, (const char*)writeBuf, dataLength);
                    if (uart_read_bytes(uart_num, dataBuf, 1, 200) != -1) {
                      if ((uart_read_bytes(uart_num, (dataBuf+1), (dataBuf[0]+1), 200) != -1) && (dataDecrypt((char*)dataBuf) == DATA_OK)) {
                        Serial.print("\ndataOK");
                        client.print(level);
                      } else {
                        Serial.printf("\nfrom stm data1(OFF): no data;\n");
                        client.print("...");
                      }
                    } else {
                      Serial.printf("\nfrom stm data0(OFF): no data;\n");
                      client.print("...");
                    }

                    level = line[++i] - 48;
                    while (line[++i] != '?') {
                      level = (level * 10) + (line[i] - 48);
                    }
                    Serial.printf("\nPOST /setlevels, OFF = %u", level);
                    dataLength = dataCreate(writeBuf, OFF_LIGHT_LEVEL, level);
                    uart_write_bytes(uart_num, (const char*)writeBuf, dataLength);
                    if (uart_read_bytes(uart_num, dataBuf, 1, 200) != -1) {
                      if ((uart_read_bytes(uart_num, (dataBuf+1), (dataBuf[0]+1), 200) != -1) && (dataDecrypt((char*)dataBuf) == DATA_OK)) {
                        Serial.print("\ndataOK");
                        client.print(level);
                      } else {
                        Serial.printf("\nfrom stm data1(OFF): no data;\n");
                        client.print("...");
                      }
                    } else {
                      Serial.printf("\nfrom stm data0(OFF): no data;\n");
                      client.print("...");
                    }
                    Serial.printf("\ntransived: POST /setlevels, l = %u", level);
                } else if (line.indexOf("POST /flash ") >= 0) {
                    dataLength = dataCreate(writeBuf, BOOTLOADER, 0);
                    uart_write_bytes(uart_num, (const char*)writeBuf, dataLength);
                    uint8_t counter = 10;
                    while ((uart_read_bytes(uart_num, dataBuf, 1, 1000) != -1)
                            && (--counter)) {
                      Serial.println("while (uart_read_bytes(uart_num, dataBuf, 1, 1000) != -1)");
                      if ((uart_read_bytes(uart_num, (dataBuf+1), (dataBuf[0]+1), 200) != -1) 
                          && (dataDecrypt((char*)dataBuf) == BOOTLOADER)) {
                        break;
                      }
                    }
                    uint8_t flashStatus = DATA_ERROR;
                    if (counter) {
                      Serial.println(" if (counter) 2");
                      while ((client.available() > 0)
                            && (counter)
                            && (flashStatus != CRITICAL_ERROR)
                            && (flashStatus != FLASH_DONE)) {
                        line = client.readStringUntil('\n');
                        if (line[0] == ':') {
                          counter = 10;
                          do { //((flashStatus == DATA_ERROR) && (--counter));
                            //Serial.println("do {uart_write_bytes(uart_num, (const char*)line.c_str(), line.length())");
                            uart_write_bytes(uart_num, (const char*)line.c_str(), line.length());
                            if (uart_read_bytes(uart_num, dataBuf, 1, 2000) != -1) {
                              if (uart_read_bytes(uart_num, (dataBuf+1), (dataBuf[0]+1), 2000)) {
                                flashStatus = (dataDecrypt((char*)dataBuf));
                                if ((flashStatus != DATA_OK)
                                    && (flashStatus != CRITICAL_ERROR)
                                    && (flashStatus != FLASH_DONE)) {
                                  flashStatus = DATA_ERROR;
                                } else counter = 10; //если данные = DATA_OK, обновляем counter
                              } else flashStatus = DATA_ERROR;
                            } else flashStatus = DATA_ERROR;
                            Serial.printf("\ndataDecrypt = %d\n", flashStatus);
                          } while ((flashStatus == DATA_ERROR)
                                   && (--counter));
                          if (counter) Serial.println(line);
                          else {
                            Serial.println("(---error--- COUNTER 2");
                          }
                        } //if ':'
                      } //while ((client.available() > 0) && (counter)) {
                    } // if (counter)
                    if (flashStatus == FLASH_DONE) { 
                      Serial.println("----------HTML_OK---------");
                      client.print(HTML_OK);
                    } else {
                      Serial.println("*********HTML_ERROR**********");
                      client.print(HTML_ERROR);
                    }

                } else {
                    client.println(HTML_PAGE);    
                    Serial.println("Send OK 2");                  
                }
                Serial.println("\n-end char c 2-");
                break;                
            }
            //Serial.println("\n-end char c 3-");
        }
        client.stop();
        Serial.println("Client disconnected");
    }

    //test_str++;
}    
