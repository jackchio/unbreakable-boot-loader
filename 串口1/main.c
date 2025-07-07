#include"ecbm_reg.h"
#include "intrins.h"    //单片机C语言使用汇编指令的头文件。
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<o>系统时钟频率选择
//<i>定义单片机运行的时钟频率（单位Hz）。
//<5529600UL => 5.5296M 
//<6000000UL => 6.0000M 
//<11059200UL=>11.0592M 
//<12000000UL=>12.0000M 
//<18432000UL=>18.4320M  
//<20000000UL=>20.0000M 
//<22118400UL=>22.1184M 
//<24000000UL=>24.0000M 
//<26000000UL=>26.0000M
//<27000000UL=>27.0000M
//<30000000UL=>30.0000M 
//<33000000UL=>33.0000M 
//<33177600UL=>33.1776M 
//<35000000UL=>35.0000M 
//<36864000UL=>36.8640M 
//<40000000UL=>40.0000M 
//<44236800UL=>44.2368M 
//<45000000UL=>45.0000M 
//<45158400UL=>45.1584M 
#define ECBM_SYSCLK_SETTING (11059200UL)
#if     (ECBM_SYSCLK_SETTING == 5529600UL)//根据系统时钟来选择系数。
#   define ECBM_EEPROM_WAIT_TIME   (4)
#elif   (ECBM_SYSCLK_SETTING == 6000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (4)
#elif   (ECBM_SYSCLK_SETTING == 11059200UL)
#   define ECBM_EEPROM_WAIT_TIME   (3)
#elif   (ECBM_SYSCLK_SETTING == 12000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (3)
#elif   (ECBM_SYSCLK_SETTING == 18432000UL)
#   define ECBM_EEPROM_WAIT_TIME   (2)
#elif   (ECBM_SYSCLK_SETTING == 20000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (2)
#elif   (ECBM_SYSCLK_SETTING == 22118400UL)
#   define ECBM_EEPROM_WAIT_TIME   (2)
#elif   (ECBM_SYSCLK_SETTING == 24000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (1)
#elif   (ECBM_SYSCLK_SETTING == 26000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (1)
#elif   (ECBM_SYSCLK_SETTING == 27000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (1)
#elif   (ECBM_SYSCLK_SETTING == 30000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 33000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 33177600UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 35000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 36864000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 40000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 44236800UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 45000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 45158400UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#endif
//<o>波特率
//<600=>600 
//<1200=>1200 
//<2400=>2400 
//<4800=>4800 
//<9600=>9600 
//<14400=>14400 
//<19200=>19200 
//<28800=>28800 
//<38400=>38400 
//<57600=>57600 
//<115200=>115200
//<230400=>230400 
//<460800=>460800
#define ECBM_UART_BAUD_RATE (115200)
//<o>APP区的大小
//<i>单位KB，可根据实际情况修改。
//<1-63>
#define APP_SIZE    (62)
#define EEPROM_SIZE_MAX (APP_SIZE*2)
//<q>复用串口功能
#define MUX_FUNCTION_UART (0)
//<e>485控制功能
#define UART_485_EN (0)
//<i>仅支持RE、DE脚焊在一起的用法。这是最省IO和元件的接法了。
//<o>控制脚(RE、DE)对应的port
//<0x80=>P0
//<0x90=>P1
//<0xA0=>P2
//<0xB0=>P3
//<0xC0=>P4
//<0xC8=>P5
//<0xE8=>P6
//<0xF8=>P7
#define UART_485_PORT (0xB0)
//<o>控制脚(RE、DE)脚对应的pin
//<0x00=>0
//<0x01=>1
//<0x02=>2
//<0x03=>3
//<0x04=>4
//<0x05=>5
//<0x06=>6
//<0x07=>7
#define UART_485_PIN  (0x03)
//</e>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-----------------------------------------BOOT脚定义-----------------------------------------*/
#define BOOT_PIN        P11 //BOOT脚设置为P1.1脚,。
#define BOOT_RUN_APP    (0) //BOOT脚为低电平的时候运行APP。
#define BOOT_PIN_UPPULL do{P1PU=0x02;}while(0)//打开BOOT脚的上拉电阻。
#define BOOT_PIN_HIGHZ  do{P1PU=0x00;}while(0)//关闭BOOT脚的上拉电阻。
/*-----------------------------------------APP区定义-----------------------------------------*/
#define APP_JMP_ADDR    (0x0800)//APP程序跳转地址。
#define APP_ADDR        (APP_JMP_ADDR+0x0200)//APP本体的起始地址。
/*-----------------------------------------变量定义-----------------------------------------*/
u8 xdata flash_buf[256];
u8  data flash_state,flash_cmd;
bit app_flag;
u8  app_lock;
u16 data data_addr,data_len,data_count,data_n,data_addr_ex,data_buf_point;
#if (UART_485_EN)
    sbit UART_485_IO=(UART_485_PORT+UART_485_PIN);
#endif
/*-------------------------------------------------------
变量初始化函数。
-------------------------------------------------------*/
void value_init(void){
    flash_state=0;//其他变量会在运行的时候覆盖或清零，就不用在这里清零了。
    flash_cmd=0;
    data_buf_point=0;
}
/*-------------------------------------------------------
IO初始化函数。
-------------------------------------------------------*/
void io_init(void){
    BOOT_PIN_UPPULL;//BOOT_IO打开上拉，防止高阻态下读到的电平不稳定。
}
/*-------------------------------------------------------
IO还原函数。
-------------------------------------------------------*/
void io_reset(void){
    BOOT_PIN_HIGHZ;//BOOT_IO关闭上拉，防止干扰到APP的运行。
}
/*-------------------------------------------------------
APP跳转函数。
-------------------------------------------------------*/
void (*jmp_app)(void)=(void(*)(void))(APP_JMP_ADDR);
#if (1)//eeprom部分折叠
/*-------------------------------------------------------
eeprom关闭函数。
-------------------------------------------------------*/
void eeprom_off(void){
    IAP_SET_REG_CONTR(0);       //关闭IAP功能。
    IAP_CMD_NOP;                //清除命令寄存器。
    IAP_TRIG_CLS;               //清除触发寄存器。
    IAP_SET_REG_ADDR_H8(0xff);  //将地址设置到非IAP区域。
    IAP_SET_REG_ADDR_L8(0xff);  //将地址设置到非IAP区域。
}
/*-------------------------------------------------------
eeprom初始化函数。
-------------------------------------------------------*/
void eeprom_init(void){
    IAP_TPS=ECBM_SYSCLK_SETTING/1000000;//STC8G和STC8H的IAP时钟频率设置。
    eeprom_off();//关闭eeprom，等需要时再开启。
}
/*-------------------------------------------------------
eeprom擦除函数。
-------------------------------------------------------*/
void eeprom_erase(u16 addr){
    if(data_addr_ex)return;//如果地址超过64KB，直接退出。
    if((addr>=0x0200)&&(addr<APP_ADDR))return;//如果地址在BOOT区，直接退出。
    if(addr>=APP_ADDR)addr-=APP_JMP_ADDR;//如果地址在正常的区间，则减去IAP的偏移量得到真正的地址。
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);  //使能IAP
    IAP_CMD_ERASE;              //设置IAP擦除命令
    IAP_SET_REG_ADDR_HL(addr);  //设置IAP地址
    IAP_TRIG_ON;                //触发命令
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    eeprom_off();               //关闭IAP功能
}
/*-------------------------------------------------------
eeprom写函数。
-------------------------------------------------------*/
void eeprom_write(u16 addr,u8 dat){
    if(data_addr_ex)return;//如果地址超过64KB，直接退出。
    if((addr>=0x0200)&&(addr<APP_ADDR))return;//如果地址在BOOT区，直接退出。
    if(addr>=APP_ADDR)addr-=APP_JMP_ADDR;//如果地址在正常的区间，则减去IAP的偏移量得到真正的地址。
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);  //使能IAP
    IAP_CMD_WRITE;              //设置IAP写命令
    IAP_SET_REG_ADDR_HL(addr);  //设置IAP地址
    IAP_SET_REG_DATA(dat);      //写IAP数据
    IAP_TRIG_ON;                //触发命令
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    eeprom_off();               //关闭IAP功能
}
/*-------------------------------------------------------
eeprom读函数。
-------------------------------------------------------*/
u8 eeprom_read(u16 addr){
    u8 dat_u8;
    if(data_addr_ex)return 0xff;//如果地址超过64KB，直接返回0xff。
    if((addr>=0x0200)&&(addr<APP_ADDR))return 0xff;//如果地址在BOOT区，直接返回0xff。
    if(addr>=APP_ADDR)addr-=APP_JMP_ADDR;//如果地址在正常的区间，则减去IAP的偏移量得到真正的地址。
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);  //使能IAP
    IAP_CMD_READ;               //设置IAP读命令
    IAP_SET_REG_ADDR_HL(addr);  //设置IAP地址
    IAP_TRIG_ON;                //触发命令
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    dat_u8=IAP_GET_REG_DATA;    //读IAP数据
    eeprom_off();               //关闭IAP功能
    return dat_u8;
}
#endif
#if (1)//串口部分折叠
/*-------------------------------------------------------
串口初始化函数。
-------------------------------------------------------*/
void uart_init(void){
    #if   (UART_485_EN)
        #if   (UART_485_PIN==0)
            #define PIN2IO (0x01)
        #elif (UART_485_PIN==1)
            #define PIN2IO (0x02)
        #elif (UART_485_PIN==2)
            #define PIN2IO (0x04)
        #elif (UART_485_PIN==3)
            #define PIN2IO (0x08)
        #elif (UART_485_PIN==4)
            #define PIN2IO (0x10)
        #elif (UART_485_PIN==5)
            #define PIN2IO (0x20)
        #elif (UART_485_PIN==6)
            #define PIN2IO (0x40)
        #elif (UART_485_PIN==7)
            #define PIN2IO (0x80)
        #endif
        UART_485_IO=0;                  //485控制引脚设置为输入。
        #if   (UART_485_PORT==0x80)
            P0M0|=PIN2IO; P0M1&=~PIN2IO; 
        #elif (UART_485_PORT==0x90)
            P1M0|=PIN2IO; P1M1&=~PIN2IO;
        #elif (UART_485_PORT==0xA0)
            P2M0|=PIN2IO; P2M1&=~PIN2IO;
        #elif (UART_485_PORT==0xB0)
            P3M0|=PIN2IO; P3M1&=~PIN2IO;
        #elif (UART_485_PORT==0xC0)
            P4M0|=PIN2IO; P4M1&=~PIN2IO;
        #elif (UART_485_PORT==0xC8)
            P5M0|=PIN2IO; P5M1&=~PIN2IO;
        #elif (UART_485_PORT==0xE8)
            P6M0|=PIN2IO; P6M1&=~PIN2IO;
        #elif (UART_485_PORT==0xF8)
            P7M0|=PIN2IO; P7M1&=~PIN2IO;
        #endif
    #endif        
    UART1_SET_MODE_A_8_BAUD;//设置串口为8位无校验，1个停止位。
    UART1_SET_RXD_ENABLE;   //启动串口接收。
    UART1_SET_CLK_TIMER1;   //设置串口时钟为TIMER1。
    TIMER1_SET_REG_HL((u16)(65536-(u16)(ECBM_SYSCLK_SETTING/4/ECBM_UART_BAUD_RATE)));//设置波特率。
    TIMER1_SET_MODE_1T;     //设定定时器1为1T模式，
    TIMER1_SET_REG_TMOD(0); //设定定时器1为16位自动重装方式，目前这样设置已经能满足常用的波特率了。
    TIMER1_IT_DISABLE;      //禁止定时器1中断。
    TIMER1_POWER_ON;        //启动定时器1。
}
/*-------------------------------------------------------
串口发送函数。
-------------------------------------------------------*/
void uart_char(u8 ch){
    #if   (UART_485_EN)
        UART_485_IO=1;          //将485控制引脚设置为输出。
    #endif
    UART1_SET_REG_SBUF(ch);     //发送数据。
    while(!UART1_GET_TI_FLAG);  //等待发送完成。
    UART1_CLR_TI_FLAG;          //清除发送完成标志。
    #if   (UART_485_EN)
        UART_485_IO=0;          //将485控制引脚设置为输入。
    #endif
}
/*-------------------------------------------------------
串口字符串发送函数。
-------------------------------------------------------*/
void uart_string(u8 * str){
    while(*str){//循环直至字符串结束，
        uart_char(*str++);//发送一个字符，并增加指针指向下一个字符。
    }
}
#endif
u8 app_data_check(void){
    u16 data_c,sector_c;
    u8 res;
    res=0;
    for(sector_c=(APP_JMP_ADDR/512);sector_c<EEPROM_SIZE_MAX;sector_c++){//该循环的次数就是上面填的全片空间的大小。
        for(data_c=0;data_c<512;data_c++){
            if(*(unsigned char code *)(sector_c*512+data_c)!=0xFF){
                res++;
                break;
            }
        }
    }
    return res;
}
/*-------------------------------------------------------
主函数。
-------------------------------------------------------*/
void main(void){        //main函数，必须的。
    EX_SFR_ENABLE;      //打开额外寄存器。
    io_init();          //初始化IO。
    eeprom_init();      //初始化EEPROM。
    #if (MUX_FUNCTION_UART)
        value_init();   //初始化变量。
        uart_init();    //能运行到这，说明要跑bootloader。初始化串口。
    #endif
    if(*(unsigned char code *)(APP_JMP_ADDR)==0x02){//如果在该位置上有跳转语句，说明有APP。
        app_flag=1;     //置标志位为1。当然也可以设立更加详细的条件来达成APP是否存在的判断。
    }else{              //条件不满足，
        app_flag=0;     //置标志位为0。
    }
    if((BOOT_PIN==BOOT_RUN_APP)&&(app_flag)){//如果BOOT脚为低电平且有APP，
        io_reset();     //还原IO的设置。
        jmp_app();      //跳转到APP。
    }
    EX_SFR_ENABLE;      //打开额外寄存器。
    #if (MUX_FUNCTION_UART==0)
        value_init();   //初始化变量。
        uart_init();    //能运行到这，说明要跑bootloader。初始化串口。
    #endif
    app_lock=app_data_check();
    EA_DISABLE;
    while(1){           //本BootLoader不需要中断，全部在主循环里用查询法。
        if(UART1_GET_RI_FLAG){//串口1接收中断。
            UART1_CLR_RI_FLAG;//清掉串口1接收标志。
            switch(flash_state){
                //前三个状态用于判断帧头的AIC。
                case 0:{if(UART1_GET_REG_SBUF=='A'){flash_state=1;}}break;
                case 1:{if(UART1_GET_REG_SBUF=='I'){flash_state=2;}else{flash_state=0;}}break;
                case 2:{if(UART1_GET_REG_SBUF=='C'){flash_state=3;}else{flash_state=0;}}break;
                case 3:{
                    flash_cmd=UART1_GET_REG_SBUF;//帧头过后是指令，将指令存起来。
                    switch(flash_cmd){//如果指令是没有参数的，那么可以立即执行。
                        case 0xEC:{//标记指令。
                            flash_state=0;//状态机重置。
                            uart_string("AIS");//发送回复帧头。
                            POWER_RESET;//单片机重启。
                        }break;
                        case 0xF0:{//查询型号指令。
                            flash_state=0;//状态机重置。
                            uart_string("AIS");//发送回复帧头。
                            uart_char(0xEF);//厂商ID。
                            uart_char(0x40);//类型ID。
                            uart_char(0x11);//容量ID   。         
                        }break;
                        case 0xF1:{//查询状态指令。
                            flash_state=0;//状态机重置。
                            uart_string("AIS");//发送回复帧头。
                            uart_char(0x00);//状态1。
                            uart_char(0x00);//状态2。
                            uart_char(0x00);//状态3。
                        }break;
                        case 0xF4:{//全片擦除指令。
                            flash_state=0;//状态机重置。
                            for(data_n=0;data_n<EEPROM_SIZE_MAX;data_n++){//该循环的次数就是上面填的全片空间的大小。
                                eeprom_erase((u16)(data_n*512));//全片擦除。
                            }
                            app_lock=app_data_check();
                            uart_string("AIS");//发送回复帧头。
                        }break;
                        case 0xF2:case 0xF3:case 0xF5:case 0xF6:case 0xF7:flash_state=4;break;//如果是带参数的指令，就到接收地址状态。
                    }
                }break;
                case 4:case 5:{//STC8的最大容量就是64K，所以高位地址相当于没用。
                    data_addr_ex<<=8;//这里组装它是为了在上位机操作的时候，假如不小心输入了错误的地址，不会造成数据被修改或丢失。
                    data_addr_ex+=(u16)(UART1_GET_REG_SBUF);
                    flash_state++;
                }break;
                case 6:case 7:{
                    data_addr<<=8;//组装低位地址
                    data_addr+=(u16)(UART1_GET_REG_SBUF);
                    flash_state++;
                    if(flash_state==8){//当地址组装完毕之后，判断当前指令是不是满足了“参数只有地址”的情况。
                        //以下3个指令就是参数只有地址的情况。
                        if(flash_cmd==0xF5){//4K擦除指令。
                            flash_state=0;  //状态机重置。
                            for(data_n=0;data_n<8;data_n++){//4K=4096，而4096/512=8。
                                eeprom_erase((u16)(data_addr+(u16)(data_n*512)));
                            }
                            app_lock=app_data_check();
                            uart_string("AIS");//发送回复帧头。
                        }
                        if(flash_cmd==0xF6){//32K擦除指令。
                            flash_state=0;  //状态机重置。
                            for(data_n=0;data_n<64;data_n++){//32K=32768，而32768/512=64。
                                eeprom_erase((u16)(data_addr+(u16)(data_n*512)));
                            }
                            app_lock=app_data_check();
                            uart_string("AIS");//发送回复帧头。
                        }
                    }
                }break;
                case 8:case 9:case 10:case 11:{
                    data_len<<=8;//组装数据长度。
                    data_len+=(u16)(UART1_GET_REG_SBUF);
                    flash_state++;
                    //这里长度的组装横跨4个状态，也就是4个字节。但是STC8的EEPROM最大容量是64K，所以长度最大只能是64K。
                    //所以data_len定义为u16，大于65536的部分会溢出冲掉。如果想要完整的数据长度，可以把data_len定义为u32。
                    if(flash_state==12){//组装好之后
                        if(flash_cmd==0xF2){//读取数据指令。
                            flash_state=0;  //状态机重置。
                            if(app_lock){//如果APP存在且被锁，
                                uart_string("AIS");//发送回复帧头。
                                for(data_n=0;data_n<data_len;data_n++){//在APP锁定的情况下显示“APPLOCK”。
                                    switch((data_addr+data_n)&0x07){
                                        case 0:uart_char('A');break;
                                        case 1:uart_char('P');break;
                                        case 2:uart_char('P');break;
                                        case 3:uart_char('L');break;
                                        case 4:uart_char('O');break;
                                        case 5:uart_char('C');break;
                                        case 6:uart_char('K');break;
                                        case 7:uart_char(app_lock);break;
                                    }
                                }
                            }else{//如果没有锁定，那么就是正常显示eeprom里面的内容。
                                uart_string("AIS");//发送回复帧头。
                                for(data_n=0;data_n<data_len;data_n++){
                                    uart_char(eeprom_read(data_addr+data_n));//将eeprom的内容通过串口发送出去。
                                }
                            }
                        }
                        data_count=0;//重置数据计数器。
                        //如果上面的if判断没有触发，说明是0xF3指令，也就是编程数据指令，那么接下来就要开始接收数据了。
                    }
                }break;
                case 12:{//编程数据指令。
                    flash_buf[data_count]=UART1_GET_REG_SBUF;//接收数据到缓存。
                    data_count++;//数据计数器加一。
                    if(data_count==data_len){//如果接收的数据数量达到指定值，
                        flash_state=0;//重置状态机，通常是要准备下一个数据包，直至接收完毕。
                        if(app_lock){//如果APP存在且被锁，
                            //这里可以用其他方式来反馈，但默认是不做处理。
                        }else{//如果不存在或者没有被锁，则进行编程。
                            for(data_n=0;data_n<data_len;data_n++){
                                eeprom_write(data_addr+data_n,flash_buf[data_n]);//将缓存的数据写入到eeprom。
                            }
                        }
                        uart_string("AIS");//完成写入后再回复，通知上位机发送下一个数据包。
                    }
                }break;
            }
        }
    }
}