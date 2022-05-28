#define DATA_ERROR 0x0
#define DATA_OK 0x5
#define CRITICAL_ERROR 0xf
#define FLASH_DONE 0xe
#define GET_CURR_LIGHT_LEVEL 0x1
#define GET_ON_LIGHT_LEVEL 0x2
#define GET_OFF_LIGHT_LEVEL 0x3
#define GET_LED_STATE 0x4
#define BOOTLOADER 0x9
#define CURR_LIGHT_LEVEL 0x11
#define ON_LIGHT_LEVEL 0x12
#define OFF_LIGHT_LEVEL 0x13
#define CURR_LED_STATE 0x14

uint8_t dataCreate(char* buf, uint8_t dataType, uint8_t data2send) {
  *(buf+1) = dataType;
  if (dataType >> 4) {
    *(buf) = 2;
    *(buf+2) = data2send;
    *(buf+3) = (2 + dataType + data2send);
    return 4;
  } else {
    *(buf) = 1;
    *(buf+2) = (1 + dataType);
    return 3;
  }
}

uint8_t dataDecrypt(char* buf) {
  uint16_t dataSum = 0;
  uint8_t i;
  for (i = 0; i <= buf[0]; i++) {
    dataSum += buf[i];
  }
  if (dataSum == buf[i]) {
    return buf[1];
  } else return DATA_ERROR;
}

/* расшифровываем HEX-строку
 *  :LLAAAATTDD...CC
 *  LL - длина DD
 *  AAAA - адрес
 *  TT - тип данных в строке
 *  DD - данные
 *  CC - crc
 */

typedef struct {
  uint8_t dataSize;
  uint16_t address;
  uint8_t dataType;
  uint8_t buf[16];
} HEXData;

uint8_t chars2int(char *buf) { //возвращает int из 2-х char
  uint8_t result;
  if (*buf >= '0' && *buf <= '9') {
    result = (*buf - '0');
  } else if (*buf >= 'A' && *buf <= 'F') {
    result = (*buf - 'A' + 10);
  } else return 0;
  buf++;
  result <<= 4;
  if (*buf >= '0' && *buf <= '9') {
    result += (*buf - '0');
  } else if (*buf >= 'A' && *buf <= 'F') {
    result += (*buf - 'A' + 10);
  } else return 0;
  return result;
}

uint8_t dataHEXDecrypt32BitBuf(HEXData *hex, char *buf, uint8_t dataLength) {
  hex->dataSize = dataLength;
  uint32_t crc = dataLength;
  buf += 3; //сдвигаем buf на начало адреса
  hex->address = chars2int(buf);
  crc += hex->address;
  hex->address <<= 8;
  buf += 2;
  hex->address += chars2int(buf);
  crc += hex->address;
  buf += 2;
  hex->dataType = chars2int(buf);
  crc += hex->dataType;
  buf += 2;
  /*if (hex->dataType == 0) {
    for (int i = 0; i < dataLength; i+=4) {
      for (int j = 3; j >= 0; j--) {
        hex->buf[i+j] = chars2int(buf);
        crc += hex->buf[i+j];
        buf += 2;
      }
    }
  }
  else {*/
    for (int i = 0; i < dataLength; i++) {
      hex->buf[i] = chars2int(buf);
      crc += hex->buf[i];
      buf += 2;
    }
  //}
  crc = (((crc ^ 0xff) + 1) & 0xff);
  if (crc - chars2int(buf)) return DATA_ERROR;
  else return DATA_OK;
}
