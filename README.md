# 刷不坏的BootLoader

## 项目介绍
早在2020年发布[stc8-bootloader-tiny](https://gitee.com/ecbm/stc8-bootloader-tiny)的时候，有一个问题就摆在了眼前：Bootloader程序该如何保护自己。

很明显stc8-bootloader-tiny项目只要用户擦除了BOOT区，那么BootLoader本体就被干掉了，这个芯片也就是刷死了。后来虽然写出了bootloader_pro，但是总觉得如果这个问题没解决的话，功能再怎么“pro”也是个玩具罢了。

不过天无绝人之路，在研究STC的flash特性过程中发现了关键的两点：

1. **只有带IAP功能的型号，才能在eeprom内执行代码。**
2. **划分到code的部分是没有办法通过IAP操作修改的。**

熟悉STC的都知道，STC单片机的EEPROM其实是用Flash实现的，两者的差别有：

| 储存器的差异 |           FLASH            |            EEPROM            |
| :----------: | :------------------------: | :--------------------------: |
|    写操作    | 按字节操作，只能把1写成0。 | 按字节操作，既能写1也能写0。 |
|    读操作    |        按字节操作。        |         按字节操作。         |
|   擦除操作   | 按扇区操作，只能把0写成1。 | 不需要擦除，直接写就能覆盖。 |

这种差异的原因就不深究了，这里主要是想说CODE区和EEPROM区其实在硬件上都是同一片FLASH。那么理论上我们把代码放到哪个区都应该可以运行。但上面的关键点1告诉我们，对于普通的型号，代码放在EEPROM区是不能运行的。原因同样也不深究了，这个可以得到一个结论：**只有带IAP功能的型号才能使用本Bootloader。**所以如果你是想在普通型号上使用本项目的话，还是趁早打消这个想法吧。

剩下的关键点2就是本项目能成立的核心，在STC-ISP工具（现在叫AIapp-ISP）上设置好EEPROM区的大小之后，芯片内部会自动给IAP寄存器加偏移。比如STC8H8K64U这个型号具有64K的FLASH，如果我划分62K的空间用作EEPROM，那么CODE区就剩下2K。2K=2048=0x0800，也就是说单片机内部会给IAP寄存器加0x0800的偏移，也就是说当你想使用IAP功能操作地址0x0000的时候，实际上是在操作地址0x0800，同理你想用IAP功能操作地址0x0100的时候，实际上是操作地址0x0900，以此类推。这样一来物理地址的0x0000到0x07FF这2K的空间就是IAP功能无法操作到的！同时这个偏移量目前不开放给用户，只能在下载的时候通过STC-ISP工具设置。那么结论立刻就有了：**只要把BootLoader放到CODE区，APP放到EEPROM区。那么APP在运行的时候永远无法修改BootLoader。**

这样一来就还差一个上位机，这不是我擅长的领域，期间也试过XMODEM、SSCOM、正点原子串口助手。但多多少少差点意思。它们在数据的校验以及出错重发上的提示不够明显，很难得知APP的下载是否完整和正确。如果在BootLoader里做计算校验算法的话，会使得BootLoader固件过大。有些型号只有12K的容量，如果BootLoader就占用了4K多，那显然是不可接受的。直到最近，STC推出了**串行FLASH编程器**，里面的【编程】和【校验】一下就解决了APP下载的完整性和正确性问题，虽然这个工具不是为了BootLoader而写，但是不妨碍我们去适配它。于是本项目顺利上线。

## 使用方法

### BOOT固件生成

目前的BootLoader是基于串口1，如果需要走其他串口甚至其他协议（比如IIC）的话，请自行修改代码。

打开keil工程，接着打开main.c文件，左下角会有图形化配置界面的标签：

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/1.png)

这是keil自带的功能，所以必须是在keil里打开才有，用VSCODE打开main.c是没有这个界面的。

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/2.png)

该界面下有一些参数，是为了方便编译给不同项目的时候可以快速选择的：

- 系统时钟频率选择：这个不用解释太多，单片机运行在多少频率就填多少。由于本BootLoader在下载时不会去调节主频，因此最好是能和APP运行的主频统一！大家平时习惯了STC-ISP工具在下载时调主频，可能会在这一不留意出问题。
- 波特率：基于串口的都需要填这个。如果是其他协议，那么此设置无效。
- APP区的大小：主要涉及【全片擦除】指令，最好如实填写。当前BOOT本体占用1.5K，跳转表0.5K，如果是STC8H8K64U就是64-1.5-0.5=62K。该选项的单位是K。

另一些参数，由于各种原因不适合也没办法做在图形化配置界面，还得回到普通的文本编辑界面去改：

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/3.png)

在大约第49行开始，可以看到BOOT脚定义和APP区定义。

```c
/*-----------------------------------------BOOT脚定义-----------------------------------------*/
#define BOOT_PIN        P11 //BOOT脚设置为P1.1脚,。
#define BOOT_RUN_APP    (0) //BOOT脚为低电平的时候运行APP。
#define BOOT_PIN_UPPULL do{P1PU=0x02;}while(0)//打开BOOT脚的上拉电阻。
#define BOOT_PIN_HIGHZ  do{P1PU=0x00;}while(0)//关闭BOOT脚的上拉电阻。
/*-----------------------------------------APP区定义-----------------------------------------*/
#define APP_JMP_ADDR    (0x0800)//APP程序跳转地址。
#define APP_ADDR        (APP_JMP_ADDR+0x0200)//APP本体的起始地址。
```

- BOOT_PIN：该IO的电平状况会决定上电是执行BootLoader还是APP。
- BOOT_RUN_APP：设置为0的时候代表低电平的时候运行APP，设置为1的时候代表低电平的时候运行APP。可以自由的根据硬件来选择。
- BOOT_PIN_UPPULL和BOOT_PIN_HIGHZ：由于STC8后期的芯片默认都是高阻，如果BOOT_PIN没有外接电阻，那么电平可能会不稳定，通过这两个语句来打开和关闭内部的上拉电阻可以杜绝不稳定的电平。

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/4.png)

设置上拉电阻的代码不需要死记硬背，在STC-ISP工具里可以轻松复制出来。

而在APP区定义里，只需要注意一个参数就行了。就是APP_JMP_ADDR。不管你有没有修改本项目的代码，只要编译后的大小不超过2K就行了。但是keil在处理保留地址的时候，不会统计到code大小，所以不能直接看keil的编译结果。可以通过STC-ISP打开编译后的HEX，看程序文件那里的代码长度不超过0x0800就可以不改APP_JMP_ADDR参数。

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/5.png)

而APP_ADDR是固定在APP_JMP_ADDR往后0x0200的，这个参数是不能改的，要改只改APP_JMP_ADDR。

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/6.png)

另外如果真的要改APP_JMP_ADDR的话，还要去NVIC_JMP.asm，把第二行的0800H也改了。要改就同时改这两个地方。

这些参数都设置好后按F7编译一遍，在Objects文件夹的那个bootloader.hex文件就是BOOT固件了。

### APP端设置

首先来认识一下地址分配的情况，认真地理解好地址分配的原理有助于对自己的项目进行客制化修改：

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/7.png)

可以看到，由于51内核的天生缺陷，中断的跳转代码一定得在扇区0，也就是0x0000~0x01FF这个区间。于是我们这样处理：

- 已知BOOT占用不到1.5K，那么就分3个扇区（扇区1.2.3既地址0x0200~0x07FF）用于存放BOOT固件。
- 将IAP的操作范围设定到从第4扇区开始，也就是示意图中的黑框，它代表着IAP功能可以对这些扇区进行擦除和读写。因此物理扇区4就是IAP操作扇区0，也就是说当你用IAP功能操作0x0000这个地址的时候，实际上是在操作物理地址0x0800。
- 将APP的程序地址设置为从第5扇区也就是0x0A00开始。
- 在下载时，由BOOT程序将APP的跳转部分从扇区0移动至扇区4。而APP本体则原封不动直接照搬。

APP的工程可以按照正常的创建方法建好，然后设置程序的偏移，当前BOOT固件占用了0x0000~0x07FF，0x0800~0x09FF要预留给跳转，所以APP的工程要从0x0A00开始。如下图所示，如果对BOOT固件进行了修改导致BOOT固件变大，也只需要按上面说的原理改动成合适的值就行。

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/8.png)

至此就OK了，剩下该怎么用就还是怎么用，和平时的开发是一样的。只不过要记得要用内部EEPROM的话，注意避开APP本体的部分，选择没有代码的空余位置来做EEPROM。

### BOOT安装方式

BOOT有两种安装方式，一种是单独安装，一种是和APP一起安装。两者各有优点，各有应用场景，下面一一说明。

#### 单独安装

单独安装就像平时下载程序一样的操作方法

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/10.png)

点击【打开程序文件】，选择Objects文件夹里的bootloader.hex文件。然后选择好主频和EEPROM大小，这两点要和BootLoader工程里的设置一样。然后就点【下载/编程】就好了。

#### 和APP一起安装

量产的时候，如果先下载BOOT再下载APP的话，任务量就是双倍了。此时可以把BOOT程序和APP程序先打包在一起，就可以一起下载了。

打开仓库里的“合并工具V1.1.html”，最好用最新版的网页浏览器打开。打开之后看到如下界面：

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/9.png)

点击BootLoader固件的【选HEX】，选择BootLoader.hex。点击APP固件的【选HEX】，选择你的项目编译出来的HEX，这里为了举例，我也编译了一个测试用的APP.HEX。

选择好两个HEX之后，点击【开始合并处理】，文件合并之后会自动转换成BIN文件。接着会弹出保存框，选择好保存的位置和文件名点【保存】就好了。

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/12.png)

下载的时候，用STC-ISP工具打开这个BIN文件，会弹出文件大小超过程序区范围。别担心，本来咱就是想把APP部分放到EEPROM的，这样的提示和操作对于我们而言不算是报错。然后就按正常的下载步骤下载就OK了。

### APP更新（使用《串口Flash编程器》）

APP除了可以和BOOT一起下载进单片机以外，自然也是可以用上位机更新的。上位机用的是STC-ISP自带的FLASH编程工具，如图所示打开：

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/13.png)

打开工具之后，选好串口号和波特率就可以开始通信了。

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/14.png)

可以先点【读取ID】，这样FLASH器件会自动选择到【W25Q10】（其实这个型号也不够小，它有128K而STC8最多只有64K，哪天出了64K的型号，我再更新仓库了）。起始地址保持0x000000不变，目标区域也选择部分扇区，区域大小由APP的大小决定，选择一个合适的就行。

接着点击【打开文件】，选择APP的BIN文件。HEX转换BIN文件的方法就是前面提到的工具：

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/15.png)

打开文件之后，点【自动】，把里面的步骤全都选中：

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/16.png)

接着点运行等待每一步走完，最后校验通过就大功告成了。

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/17.png)

### APP保护

可能眼尖的朋友也发现了，这个工具是可以读数据的，那么APP有没有会被读取的风险呢？

答案是没有的。因为BOOT程序做过处理，只有当前下载的时候才可读取，这是为了校验数据。之后只要单片机重启一次，APP会立即上锁，点【读取数据】只能读到这样的提示：

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/18.png)

所以在你更新APP之后，在交付产品之前重启一下单片机就可以了。

### APP更新（使用《串口升级工具》）

自从上次群友反馈蓝牙下载大概率会失败的问题。我意识到串口Flash编程器在传输超时判断方面可能有点苛刻了。看来自制上位机是必然的了。经过一段时间的研究和编写，最终得到串口升级工具V1.0，如下图所示：

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/26.png)

使用说明几乎都写在软件上了，嫌字太多可以抬手先来点【清空】。然后选择串口、波特率后点【连接】。

关于第2点，只要你是直接用的本项目BootLoader，那占用就是2K了。如果你自己魔改了很多，就自行计算一下。

关于第3点，那个算法指的是《[串口1APP跳转示例](https://gitee.com/ecbm/unbreakable-boot-loader/tree/master/串口1/APP跳转示例)》和《[串口2APP跳转示例](https://gitee.com/ecbm/unbreakable-boot-loader/tree/master/串口2/APP跳转示例)》里面提到的通过判断字符串“update”然后跳转到BOOT模式的算法。和上位机说的一样，提示失败不代表不能用，可能是已经进入BOOT模式了，最后以【测试】反馈的结果为准。

![27](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/27.png)

最后点击下载，先擦除再烧录，最后验证。流程走完后如图所示。这就已经下载成功了。

另外关于这个文件大小问题，就是下图红框的位置：

![28](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/28.png)

假如你的单片机有62K的空间，但是你APP只有5K多，那么可以把红框内的值改到比APP大小略大点。比如图中APP只有5097字节，然后我选择了5.5K缓存。这样做的好处就是下载更快了，毕竟擦除5.5K肯定比擦除62K快嘛。但是除非你能保证5.5K~62K这个空间内全是0xFF，否则结果一定是验证失败：

![29](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/29.png)

注意这不是下载出了问题，而是触发了注入保护。为了防止别有用心之人，通过注入一个读取flash的小固件把剩下的固件读出来。BootLoader只有在判断全片都被擦除的时候才会关闭保护。举个具体的例子：假如你的固件是42K，别人想通过注入一个5.5K的固件读取5.5K~42K的数据。再注入一个5.5K的固件读取0K~36.5K的数据，然后组合成原版的42K固件。为了防止这种手段，只要是没有全片擦除，读出来的只有APPLOCK：

![30](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/30.png)

而这就是验证失败的直接原因，验证的原理就是把写入的部分读出来和下载文件比较，现在读出来的只有APPLOCK几个字，自然验证失败。

另外，还是接上面的例子，你的APP占用了5.5K，你想把剩下的5.5~62K的空间当eeprom来存东西，如果你还是把缓存设置成5.5K的话，结果也会是一样的报错。毕竟5.5K~62K这个地址里面的数据不是全FF的。如果你确实需要确认APP是正确的被下载到单片机里，那么只有舍弃便利，老老实实将缓存设置成62K。虽然时间长了点，但是可以看到校验结果。对于远距离的无线更新或者强干扰环境下的更新来说尤为重要，可能一个0xF1传过去就变成了0xA3呢。

### APP跳转BOOT

若产品外壳不能打开，但具备蓝牙或者其他无线通信设备，亦可通过在APP内判断更新指令，然后跳转到BOOT。

首先得知道，该跳到BOOT固件的什么位置。打开keil并编译，然后点开调试功能（就是一个放大镜，里面有个d的图标）。

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/20.png)

找到跳转APP后面的那句代码，比如图中的212行。当APP判断不满足的时候，就会从这里开始执行。因此只要在APP里跳转到这个位置，就相当于进入BootLoader了。

选中该行，在上面的汇编窗口可以看到这句代码所在的位置是地址0x0229。所以在APP端可以这样写：

```c
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
void (*jmp_boot)(void)=(void(*)(void))(0x0229);//跳转BOOT函数。
void ecbm_stream_user_exe(u8 ch,u8 dat){//自定义协议接口。
    ch=ch;//就一个串口，这个参数不需要，这样写是为了防止keil报错。
    ecbm_stream_strcmp(dat,"update",&count);//比较组件，比较接收的数据里是否有“update”这个字符串。
    if(count==6){//字符串口有6个字符，全比对上了就是有这个字符串了。
        jmp_boot();//跳转到BOOT。
    }
}
```

先用通用句式，填上地址0x0229：

```c
void (*jmp_boot)(void)=(void(*)(void))(0x0229);//跳转BOOT函数。
```

然后建立一个条件去执行就可以跳转到BootLoader了。实例中是用了stream框架，开了对比组件，判断串口是否有输入字符串“update”，只有串口收到这个字符串就会跳转到BootLoader。

### APP调用BOOT里的函数

为了完成指定的功能，BootLoader的体积总会优化到一个不能再优化的程度。再优化下去会影响功能的执行，但在此之上还可以用点小花招——复用BOOT的函数=减少APP的代码量=减少整体代码量=能写更多业务代码≈BOOT占用减少。

复用函数很简单，首先是复用初始化函数：在这里选择之后，原本的【检查APP】——【初始化串口】——【BOOT功能主体】就会变成【初始化串口】——【检查APP】——【BOOT功能主体】。

![24](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/24.png)

虽然只是简单的挪动函数位置，但是它却代表了两种思想。第一种思想是BOOT和APP分离，主打的是运行BootLoader时不会对APP造成任何影响。第二种思想是BOOT和APP联动，主打的就是两者配合工作，两者是有重要联系的。

既然本段的目的就是为了复用函数减少APP代码量，那么看看接下来的操作吧：

![21](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/21.png)

还是用之前的方法，进入调试模式看到代码和对应的汇编。然后看到调用uart_char函数的位置，从汇编中可以得知该函数的位置是0x0721。于是在APP端这样写：

```c
#include "ecbm_core.h"  //加载库函数的头文件。
void (*uart_send_byte)(u8)=(void(*)(u8))(0x0721);//定义出发送函数，函数指针指向0x0721，同时也标注了本函数有一个参数。
void main(void){        //main函数，必须的。
    system_init();      //系统初始化函数，但是里面没有初始化串口。
    while(1){
        delay_ms(1000); //延时。
        uart_send_byte(0x66);//调用BOOT里面的程序。
    }
}
```

因为在BootLoader那已经初始化串口了，所以APP端不需要再进行初始化了。同时还能直接调用BOOT里面的串口发送函数。按照上面的安装步骤把上面的代码编译下载进去，可以在串口助手那里看到：

![23](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/23.png)

那么这样调用法和原本那种定义函数的调用法有多大的性能差异呢？

通过打开调用的汇编，我们可以看到在正常的传参（MOV R7）和调用（LCALL）之外，还多了红框里的代码。

![22](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/22.png)

STC声称现在是1T指令，那么每次调用函数就只多8T的时间，对于常用的11.0592MHz而言大约耗时约 0.723微秒。体积上节约了初始化函数（40字节）、发送函数（12字节）。看上去节约的不多，那是因为这个BootLoader还是太简单。

如果把485控制做进去呢？

如果把CAN作为通信协议呢？

如果是通过IIC来更新APP呢？

如果是在BootLoader里面放了一套加密解密算法呢？

大家学会了这套调用方法后，可以自由地发挥自己想象把这个功能发挥到极致。

### 彩蛋：485控制

这是一个锦上添花的功能，某些产品对外的接口除了电源就只有一个485接口，这种情况下要下载就不得不考虑485芯片的流向控制了。

![25](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/25.png)

只要勾选了【485控制功能】再选对引脚，那么发送和接收都自动带上485流向控制。不过需要注意的是，这里默认硬件上是把RE和DE两个脚短路在一起的接法，如果不是这种接法就需要微调一下代码。

### 彩蛋：BOOT文件标识

当不同的项目应用了不同的主频时，或者有些项目用到IIC来更新APP的时候，可能一个文件夹下会出现多个BOOT固件，那么给这些固件一个功能上的标识也是必要的。

为此我也做了这个小工具，只要用最新的网页浏览器打开“固件信息编辑工具.html”，就能看到如下界面：

![](https://gitee.com/ecbm/unbreakable-boot-loader/raw/master/%E5%9B%BE%E7%89%87%E7%B4%A0%E6%9D%90/19.png)

选择一个BOOT固件（BIN格式的，如何HEX转BIN可以参考本文“APP更新”那段），接着就可以在文本框内输入任意的信息，不超过160字节即可。比如图中就是简要的标识了该固件版本是1.0.0；BOOT脚是P1.0且接地的时候跑APP，接VCC时跑BootLoader；接口用的是串口1且IO口在P30和P31，波特率115200；同时该固件用于STC8H8K64U且单片机工作在11.0592MHz上。

当输入完之后，记得点【保存修改】。这样下次打开这个BIN文件的时候，这些信息就能直接看到啦。