#include "ecbm_core.h"  //���ؿ⺯����ͷ�ļ���
void main(void){        //main����������ġ�
    system_init();      //ϵͳ��ʼ��������Ҳ�Ǳ���ġ�
    uart_init();        //UART��ʼ��������
    ecbm_stream_init(); //stream��ʼ��������
    gpio_mode(D37,GPIO_OUT);//����D37Ϊ�����
    gpio_mode(D10,GPIO_OUT);//����D10Ϊ�����
    while(1){
        P37=0;      //����͵�ƽ�����ڽ�ʾ�����ء�
        P10=!P10;   //������������ڽ�ʾ����̽ͷ��
        //��������Ĳ��֣�����ʾ��������ʾ������������֤APP�Ѿ��������ˡ�
        ecbm_stream_main();//stream������������ġ�
    }
}
u8 count;//ͳ�Ʊ�����
void (*jmp_boot)(void)=(void(*)(void))(0x022C);//��תBOOT������
void ecbm_stream_user_exe(u8 ch,u8 dat){//�Զ���Э��ӿڡ�
    ch=ch;//��һ�����ڣ������������Ҫ������д��Ϊ�˷�ֹkeil����
    ecbm_stream_strcmp(dat,"update",&count);//�Ƚ�������ȽϽ��յ��������Ƿ��С�update������ַ�����
    if(count==6){//�ַ�������6���ַ���ȫ�ȶ����˾���������ַ����ˡ�
        jmp_boot();//��ת��BOOT��
    }
}