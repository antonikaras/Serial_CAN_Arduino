#ifndef __SERIAL_CAN_MODULE_H__
#define __SERIAL_CAN_MODULE_H__
// ID3 ID2 ID1 ID0 EXT RTR DTA0 DTA1 DTA2 DTA3 DTA4 DTA5 DTA6 DTA7
#include <Arduino.h>
#define uchar unsigned char


#define CAN_RATE_5      1
#define CAN_RATE_10     2
#define CAN_RATE_20     3
#define CAN_RATE_25     4
#define CAN_RATE_31_2   5
#define CAN_RATE_33     6
#define CAN_RATE_40     7
#define CAN_RATE_50     8
#define CAN_RATE_80     9
#define CAN_RATE_83_3   10
#define CAN_RATE_95     11
#define CAN_RATE_100    12
#define CAN_RATE_125    13
#define CAN_RATE_200    14
#define CAN_RATE_250    15
#define CAN_RATE_500    16
#define CAN_RATE_666    17
#define CAN_RATE_1000   18

#define SERIAL_RATE_9600    0
#define SERIAL_RATE_19200   1
#define SERIAL_RATE_38400   2
#define SERIAL_RATE_115200  4

class Stream;
class HardwareSerial;

class Serial_CAN
{
private:
    unsigned char cmdOk(char *cmd);
    unsigned char enterSettingMode();
    unsigned char exitSettingMode();
    void clear();
    void selfBaudRate(unsigned long baud);
    char str_tmp[100];
    HardwareSerial *hardwareSerial = NULL;
    Stream *canSerial = NULL;

public:
    
    void begin(int can_tx, int can_rx, unsigned long baud);
    void begin(HardwareSerial &serial, unsigned long baud);
    unsigned char send(unsigned long id, uchar ext, uchar rtrBit, uchar len, const uchar *buf);
    unsigned char recv(unsigned long *id, uchar *buf);
    
    unsigned char canRate(unsigned char rate);
    unsigned char baudRate(unsigned char rate);
    
    unsigned char setMask(unsigned long *dta);
    unsigned char setFilt(unsigned long *dta);
    
    unsigned char factorySetting();
    void debugMode();

};
#endif