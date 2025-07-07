#include "ecbm_core.h"  //加载库函数的头文件。
void main(void){        //main函数，必须的。
    system_init();      //系统初始化函数，也是必须的。
    uart_init();        //UART初始化函数。
    ecbm_stream_init(); //stream初始化函数。
    gpio_mode(D37,GPIO_OUT);//配置D37为输出。
    gpio_mode(D10,GPIO_OUT);//配置D10为输出。
    while(1){
        P37=0;      //输出低电平，用于接示波器地。
        P10=!P10;   //输出方波，用于接示波器探头。
        //运行上面的部分，会在示波器上显示方波，用来佐证APP已经在运行了。
        ecbm_stream_main();//stream主函数，必须的。
    }
}
u8 count;//统计变量。
void (*jmp_boot)(void)=(void(*)(void))(0x022C);//跳转BOOT函数。
void ecbm_stream_user_exe(u8 ch,u8 dat){//自定义协议接口。
    ch=ch;//就一个串口，这个参数不需要，这样写是为了防止keil报错。
    ecbm_stream_strcmp(dat,"update",&count);//比较组件，比较接收的数据里是否有“update”这个字符串。
    if(count==6){//字符串口有6个字符，全比对上了就是有这个字符串了。
        jmp_boot();//跳转到BOOT。
    }
}