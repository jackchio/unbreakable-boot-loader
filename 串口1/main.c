#include"ecbm_reg.h"
#include "intrins.h"    //��Ƭ��C����ʹ�û��ָ���ͷ�ļ���
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<o>ϵͳʱ��Ƶ��ѡ��
//<i>���嵥Ƭ�����е�ʱ��Ƶ�ʣ���λHz����
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
#if     (ECBM_SYSCLK_SETTING == 5529600UL)//����ϵͳʱ����ѡ��ϵ����
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
//<o>������
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
//<o>APP���Ĵ�С
//<i>��λKB���ɸ���ʵ������޸ġ�
//<1-63>
#define APP_SIZE    (62)
#define EEPROM_SIZE_MAX (APP_SIZE*2)
//<q>���ô��ڹ���
#define MUX_FUNCTION_UART (0)
//<e>485���ƹ���
#define UART_485_EN (0)
//<i>��֧��RE��DE�ź���һ����÷���������ʡIO��Ԫ���Ľӷ��ˡ�
//<o>���ƽ�(RE��DE)��Ӧ��port
//<0x80=>P0
//<0x90=>P1
//<0xA0=>P2
//<0xB0=>P3
//<0xC0=>P4
//<0xC8=>P5
//<0xE8=>P6
//<0xF8=>P7
#define UART_485_PORT (0xB0)
//<o>���ƽ�(RE��DE)�Ŷ�Ӧ��pin
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
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*-----------------------------------------BOOT�Ŷ���-----------------------------------------*/
#define BOOT_PIN        P11 //BOOT������ΪP1.1��,��
#define BOOT_RUN_APP    (0) //BOOT��Ϊ�͵�ƽ��ʱ������APP��
#define BOOT_PIN_UPPULL do{P1PU=0x02;}while(0)//��BOOT�ŵ��������衣
#define BOOT_PIN_HIGHZ  do{P1PU=0x00;}while(0)//�ر�BOOT�ŵ��������衣
/*-----------------------------------------APP������-----------------------------------------*/
#define APP_JMP_ADDR    (0x0800)//APP������ת��ַ��
#define APP_ADDR        (APP_JMP_ADDR+0x0200)//APP�������ʼ��ַ��
/*-----------------------------------------��������-----------------------------------------*/
u8 xdata flash_buf[256];
u8  data flash_state,flash_cmd;
bit app_flag;
u8  app_lock;
u16 data data_addr,data_len,data_count,data_n,data_addr_ex,data_buf_point;
#if (UART_485_EN)
    sbit UART_485_IO=(UART_485_PORT+UART_485_PIN);
#endif
/*-------------------------------------------------------
������ʼ��������
-------------------------------------------------------*/
void value_init(void){
    flash_state=0;//���������������е�ʱ�򸲸ǻ����㣬�Ͳ��������������ˡ�
    flash_cmd=0;
    data_buf_point=0;
}
/*-------------------------------------------------------
IO��ʼ��������
-------------------------------------------------------*/
void io_init(void){
    BOOT_PIN_UPPULL;//BOOT_IO����������ֹ����̬�¶����ĵ�ƽ���ȶ���
}
/*-------------------------------------------------------
IO��ԭ������
-------------------------------------------------------*/
void io_reset(void){
    BOOT_PIN_HIGHZ;//BOOT_IO�ر���������ֹ���ŵ�APP�����С�
}
/*-------------------------------------------------------
APP��ת������
-------------------------------------------------------*/
void (*jmp_app)(void)=(void(*)(void))(APP_JMP_ADDR);
#if (1)//eeprom�����۵�
/*-------------------------------------------------------
eeprom�رպ�����
-------------------------------------------------------*/
void eeprom_off(void){
    IAP_SET_REG_CONTR(0);       //�ر�IAP���ܡ�
    IAP_CMD_NOP;                //�������Ĵ�����
    IAP_TRIG_CLS;               //��������Ĵ�����
    IAP_SET_REG_ADDR_H8(0xff);  //����ַ���õ���IAP����
    IAP_SET_REG_ADDR_L8(0xff);  //����ַ���õ���IAP����
}
/*-------------------------------------------------------
eeprom��ʼ��������
-------------------------------------------------------*/
void eeprom_init(void){
    IAP_TPS=ECBM_SYSCLK_SETTING/1000000;//STC8G��STC8H��IAPʱ��Ƶ�����á�
    eeprom_off();//�ر�eeprom������Ҫʱ�ٿ�����
}
/*-------------------------------------------------------
eeprom����������
-------------------------------------------------------*/
void eeprom_erase(u16 addr){
    if(data_addr_ex)return;//�����ַ����64KB��ֱ���˳���
    if((addr>=0x0200)&&(addr<APP_ADDR))return;//�����ַ��BOOT����ֱ���˳���
    if(addr>=APP_ADDR)addr-=APP_JMP_ADDR;//�����ַ�����������䣬���ȥIAP��ƫ�����õ������ĵ�ַ��
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);  //ʹ��IAP
    IAP_CMD_ERASE;              //����IAP��������
    IAP_SET_REG_ADDR_HL(addr);  //����IAP��ַ
    IAP_TRIG_ON;                //��������
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    eeprom_off();               //�ر�IAP����
}
/*-------------------------------------------------------
eepromд������
-------------------------------------------------------*/
void eeprom_write(u16 addr,u8 dat){
    if(data_addr_ex)return;//�����ַ����64KB��ֱ���˳���
    if((addr>=0x0200)&&(addr<APP_ADDR))return;//�����ַ��BOOT����ֱ���˳���
    if(addr>=APP_ADDR)addr-=APP_JMP_ADDR;//�����ַ�����������䣬���ȥIAP��ƫ�����õ������ĵ�ַ��
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);  //ʹ��IAP
    IAP_CMD_WRITE;              //����IAPд����
    IAP_SET_REG_ADDR_HL(addr);  //����IAP��ַ
    IAP_SET_REG_DATA(dat);      //дIAP����
    IAP_TRIG_ON;                //��������
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    eeprom_off();               //�ر�IAP����
}
/*-------------------------------------------------------
eeprom��������
-------------------------------------------------------*/
u8 eeprom_read(u16 addr){
    u8 dat_u8;
    if(data_addr_ex)return 0xff;//�����ַ����64KB��ֱ�ӷ���0xff��
    if((addr>=0x0200)&&(addr<APP_ADDR))return 0xff;//�����ַ��BOOT����ֱ�ӷ���0xff��
    if(addr>=APP_ADDR)addr-=APP_JMP_ADDR;//�����ַ�����������䣬���ȥIAP��ƫ�����õ������ĵ�ַ��
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);  //ʹ��IAP
    IAP_CMD_READ;               //����IAP������
    IAP_SET_REG_ADDR_HL(addr);  //����IAP��ַ
    IAP_TRIG_ON;                //��������
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    dat_u8=IAP_GET_REG_DATA;    //��IAP����
    eeprom_off();               //�ر�IAP����
    return dat_u8;
}
#endif
#if (1)//���ڲ����۵�
/*-------------------------------------------------------
���ڳ�ʼ��������
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
        UART_485_IO=0;                  //485������������Ϊ���롣
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
    UART1_SET_MODE_A_8_BAUD;//���ô���Ϊ8λ��У�飬1��ֹͣλ��
    UART1_SET_RXD_ENABLE;   //�������ڽ��ա�
    UART1_SET_CLK_TIMER1;   //���ô���ʱ��ΪTIMER1��
    TIMER1_SET_REG_HL((u16)(65536-(u16)(ECBM_SYSCLK_SETTING/4/ECBM_UART_BAUD_RATE)));//���ò����ʡ�
    TIMER1_SET_MODE_1T;     //�趨��ʱ��1Ϊ1Tģʽ��
    TIMER1_SET_REG_TMOD(0); //�趨��ʱ��1Ϊ16λ�Զ���װ��ʽ��Ŀǰ���������Ѿ������㳣�õĲ������ˡ�
    TIMER1_IT_DISABLE;      //��ֹ��ʱ��1�жϡ�
    TIMER1_POWER_ON;        //������ʱ��1��
}
/*-------------------------------------------------------
���ڷ��ͺ�����
-------------------------------------------------------*/
void uart_char(u8 ch){
    #if   (UART_485_EN)
        UART_485_IO=1;          //��485������������Ϊ�����
    #endif
    UART1_SET_REG_SBUF(ch);     //�������ݡ�
    while(!UART1_GET_TI_FLAG);  //�ȴ�������ɡ�
    UART1_CLR_TI_FLAG;          //���������ɱ�־��
    #if   (UART_485_EN)
        UART_485_IO=0;          //��485������������Ϊ���롣
    #endif
}
/*-------------------------------------------------------
�����ַ������ͺ�����
-------------------------------------------------------*/
void uart_string(u8 * str){
    while(*str){//ѭ��ֱ���ַ���������
        uart_char(*str++);//����һ���ַ���������ָ��ָ����һ���ַ���
    }
}
#endif
u8 app_data_check(void){
    u16 data_c,sector_c;
    u8 res;
    res=0;
    for(sector_c=(APP_JMP_ADDR/512);sector_c<EEPROM_SIZE_MAX;sector_c++){//��ѭ���Ĵ��������������ȫƬ�ռ�Ĵ�С��
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
��������
-------------------------------------------------------*/
void main(void){        //main����������ġ�
    EX_SFR_ENABLE;      //�򿪶���Ĵ�����
    io_init();          //��ʼ��IO��
    eeprom_init();      //��ʼ��EEPROM��
    #if (MUX_FUNCTION_UART)
        value_init();   //��ʼ��������
        uart_init();    //�����е��⣬˵��Ҫ��bootloader����ʼ�����ڡ�
    #endif
    if(*(unsigned char code *)(APP_JMP_ADDR)==0x02){//����ڸ�λ��������ת��䣬˵����APP��
        app_flag=1;     //�ñ�־λΪ1����ȻҲ��������������ϸ�����������APP�Ƿ���ڵ��жϡ�
    }else{              //���������㣬
        app_flag=0;     //�ñ�־λΪ0��
    }
    if((BOOT_PIN==BOOT_RUN_APP)&&(app_flag)){//���BOOT��Ϊ�͵�ƽ����APP��
        io_reset();     //��ԭIO�����á�
        jmp_app();      //��ת��APP��
    }
    EX_SFR_ENABLE;      //�򿪶���Ĵ�����
    #if (MUX_FUNCTION_UART==0)
        value_init();   //��ʼ��������
        uart_init();    //�����е��⣬˵��Ҫ��bootloader����ʼ�����ڡ�
    #endif
    app_lock=app_data_check();
    EA_DISABLE;
    while(1){           //��BootLoader����Ҫ�жϣ�ȫ������ѭ�����ò�ѯ����
        if(UART1_GET_RI_FLAG){//����1�����жϡ�
            UART1_CLR_RI_FLAG;//�������1���ձ�־��
            switch(flash_state){
                //ǰ����״̬�����ж�֡ͷ��AIC��
                case 0:{if(UART1_GET_REG_SBUF=='A'){flash_state=1;}}break;
                case 1:{if(UART1_GET_REG_SBUF=='I'){flash_state=2;}else{flash_state=0;}}break;
                case 2:{if(UART1_GET_REG_SBUF=='C'){flash_state=3;}else{flash_state=0;}}break;
                case 3:{
                    flash_cmd=UART1_GET_REG_SBUF;//֡ͷ������ָ���ָ���������
                    switch(flash_cmd){//���ָ����û�в����ģ���ô��������ִ�С�
                        case 0xEC:{//���ָ�
                            flash_state=0;//״̬�����á�
                            uart_string("AIS");//���ͻظ�֡ͷ��
                            POWER_RESET;//��Ƭ��������
                        }break;
                        case 0xF0:{//��ѯ�ͺ�ָ�
                            flash_state=0;//״̬�����á�
                            uart_string("AIS");//���ͻظ�֡ͷ��
                            uart_char(0xEF);//����ID��
                            uart_char(0x40);//����ID��
                            uart_char(0x11);//����ID   ��         
                        }break;
                        case 0xF1:{//��ѯ״ָ̬�
                            flash_state=0;//״̬�����á�
                            uart_string("AIS");//���ͻظ�֡ͷ��
                            uart_char(0x00);//״̬1��
                            uart_char(0x00);//״̬2��
                            uart_char(0x00);//״̬3��
                        }break;
                        case 0xF4:{//ȫƬ����ָ�
                            flash_state=0;//״̬�����á�
                            for(data_n=0;data_n<EEPROM_SIZE_MAX;data_n++){//��ѭ���Ĵ��������������ȫƬ�ռ�Ĵ�С��
                                eeprom_erase((u16)(data_n*512));//ȫƬ������
                            }
                            app_lock=app_data_check();
                            uart_string("AIS");//���ͻظ�֡ͷ��
                        }break;
                        case 0xF2:case 0xF3:case 0xF5:case 0xF6:case 0xF7:flash_state=4;break;//����Ǵ�������ָ��͵����յ�ַ״̬��
                    }
                }break;
                case 4:case 5:{//STC8�������������64K�����Ը�λ��ַ�൱��û�á�
                    data_addr_ex<<=8;//������װ����Ϊ������λ��������ʱ�򣬼��粻С�������˴���ĵ�ַ������������ݱ��޸Ļ�ʧ��
                    data_addr_ex+=(u16)(UART1_GET_REG_SBUF);
                    flash_state++;
                }break;
                case 6:case 7:{
                    data_addr<<=8;//��װ��λ��ַ
                    data_addr+=(u16)(UART1_GET_REG_SBUF);
                    flash_state++;
                    if(flash_state==8){//����ַ��װ���֮���жϵ�ǰָ���ǲ��������ˡ�����ֻ�е�ַ���������
                        //����3��ָ����ǲ���ֻ�е�ַ�������
                        if(flash_cmd==0xF5){//4K����ָ�
                            flash_state=0;  //״̬�����á�
                            for(data_n=0;data_n<8;data_n++){//4K=4096����4096/512=8��
                                eeprom_erase((u16)(data_addr+(u16)(data_n*512)));
                            }
                            app_lock=app_data_check();
                            uart_string("AIS");//���ͻظ�֡ͷ��
                        }
                        if(flash_cmd==0xF6){//32K����ָ�
                            flash_state=0;  //״̬�����á�
                            for(data_n=0;data_n<64;data_n++){//32K=32768����32768/512=64��
                                eeprom_erase((u16)(data_addr+(u16)(data_n*512)));
                            }
                            app_lock=app_data_check();
                            uart_string("AIS");//���ͻظ�֡ͷ��
                        }
                    }
                }break;
                case 8:case 9:case 10:case 11:{
                    data_len<<=8;//��װ���ݳ��ȡ�
                    data_len+=(u16)(UART1_GET_REG_SBUF);
                    flash_state++;
                    //���ﳤ�ȵ���װ���4��״̬��Ҳ����4���ֽڡ�����STC8��EEPROM���������64K�����Գ������ֻ����64K��
                    //����data_len����Ϊu16������65536�Ĳ��ֻ��������������Ҫ���������ݳ��ȣ����԰�data_len����Ϊu32��
                    if(flash_state==12){//��װ��֮��
                        if(flash_cmd==0xF2){//��ȡ����ָ�
                            flash_state=0;  //״̬�����á�
                            if(app_lock){//���APP�����ұ�����
                                uart_string("AIS");//���ͻظ�֡ͷ��
                                for(data_n=0;data_n<data_len;data_n++){//��APP�������������ʾ��APPLOCK����
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
                            }else{//���û����������ô����������ʾeeprom��������ݡ�
                                uart_string("AIS");//���ͻظ�֡ͷ��
                                for(data_n=0;data_n<data_len;data_n++){
                                    uart_char(eeprom_read(data_addr+data_n));//��eeprom������ͨ�����ڷ��ͳ�ȥ��
                                }
                            }
                        }
                        data_count=0;//�������ݼ�������
                        //��������if�ж�û�д�����˵����0xF3ָ�Ҳ���Ǳ������ָ���ô��������Ҫ��ʼ���������ˡ�
                    }
                }break;
                case 12:{//�������ָ�
                    flash_buf[data_count]=UART1_GET_REG_SBUF;//�������ݵ����档
                    data_count++;//���ݼ�������һ��
                    if(data_count==data_len){//������յ����������ﵽָ��ֵ��
                        flash_state=0;//����״̬����ͨ����Ҫ׼����һ�����ݰ���ֱ��������ϡ�
                        if(app_lock){//���APP�����ұ�����
                            //���������������ʽ����������Ĭ���ǲ�������
                        }else{//��������ڻ���û�б���������б�̡�
                            for(data_n=0;data_n<data_len;data_n++){
                                eeprom_write(data_addr+data_n,flash_buf[data_n]);//�����������д�뵽eeprom��
                            }
                        }
                        uart_string("AIS");//���д����ٻظ���֪ͨ��λ��������һ�����ݰ���
                    }
                }break;
            }
        }
    }
}