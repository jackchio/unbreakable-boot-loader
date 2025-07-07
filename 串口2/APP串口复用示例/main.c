#include "ecbm_core.h"  //加载库函数的头文件。
void (*uart_send_byte)(u8)=(void(*)(u8))(0x0721);//定义出发送函数，函数指针指向0x0721，同时也标注了本函数有一个参数。
void main(void){        //main函数，必须的。
    system_init();      //系统初始化函数，但是里面没有初始化串口。
    while(1){
        delay_ms(1000); //延时。
        uart_send_byte(0x66);//调用BOOT里面的程序。
    }
}