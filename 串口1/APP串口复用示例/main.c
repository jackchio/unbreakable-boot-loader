#include "ecbm_core.h"  //���ؿ⺯����ͷ�ļ���
void (*uart_send_byte)(u8)=(void(*)(u8))(0x0721);//��������ͺ���������ָ��ָ��0x0721��ͬʱҲ��ע�˱�������һ��������
void main(void){        //main����������ġ�
    system_init();      //ϵͳ��ʼ����������������û�г�ʼ�����ڡ�
    while(1){
        delay_ms(1000); //��ʱ��
        uart_send_byte(0x66);//����BOOT����ĳ���
    }
}