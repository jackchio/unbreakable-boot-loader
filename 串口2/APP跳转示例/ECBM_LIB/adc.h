#ifndef _ECBM_ADC_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_ADC_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2023 奈特

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

免责说明：
    本软件库以MIT开源协议免费向大众提供。作者只保证原始版本是由作者在维护修BUG，
其他通过网络传播的版本也许被二次修改过，由此出现的BUG与作者无关。而当您使用原始
版本出现BUG时，请联系作者解决。
                            ***************************
                            * 联系方式 ：进群778916610 *
                            * 若1群满人：进群927297508 *
                            ***************************
------------------------------------------------------------------------------------*/
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<h>通道使能设置
//<i>ADC在转换的时候需要IO是高阻模式，在这里设置使能之后，会在adc_init函数中把相应的IO口设置成高阻模式。
//<i>有些通道可能和某些引脚互相影响，会导致测量结果不准。详情请看STC的数据手册。
//<q>通道0
//<i>STC8A4KxxS2A12_ALL    :P1.0
//<i>STC8A8KxxS4A12_ALL    :P1.0
//<i>STC8A8KxxD4_ALL       :P1.0
//<i>STC8G1Kxx_16PIN_20PIN :P1.0
//<i>STC8G1KxxA_8PIN       :P3.0
//<i>STC8G1KxxT_20PIN      :P1.0
//<i>STC8G2KxxS2_ALL       :P1.0
//<i>STC8G2KxxS4_ALL       :P1.0
//<i>STC8H1Kxx_20PIN       :P1.0
//<i>STC8H1Kxx_32PIN       :P1.0
//<i>STC8H2KxxT_48PIN      :P1.0
//<i>STC8H3KxxS2_48PIN     :P1.0
//<i>STC8H3KxxS4_48PIN     :P1.0
//<i>STC8H8KxxU_48PIN_64PIN:P1.0
#define ECBM_ADC_CH0_EN (0)
//<q>通道1
//<i>STC8A4KxxS2A12_ALL    :P1.1
//<i>STC8A8KxxS4A12_ALL    :P1.1
//<i>STC8A8KxxD4_ALL       :P1.1
//<i>STC8G1Kxx_16PIN_20PIN :P1.1
//<i>STC8G1KxxA_8PIN       :P3.1
//<i>STC8G1KxxT_20PIN      :P1.1
//<i>STC8G2KxxS2_ALL       :P1.1
//<i>STC8G2KxxS4_ALL       :P1.1
//<i>STC8H1Kxx_20PIN       :P1.1
//<i>STC8H1Kxx_32PIN       :P1.1
//<i>STC8H2KxxT_48PIN      :P1.1
//<i>STC8H3KxxS2_48PIN     :P1.1
//<i>STC8H3KxxS4_48PIN     :P1.1
//<i>STC8H8KxxU_48PIN_64PIN:P1.1
#define ECBM_ADC_CH1_EN (0)
//<q>通道2
//<i>STC8A4KxxS2A12_ALL    :P1.2
//<i>STC8A8KxxS4A12_ALL    :P1.2
//<i>STC8A8KxxD4_ALL       :P1.2
//<i>STC8G1Kxx_16PIN_20PIN :P1.2
//<i>STC8G1KxxA_8PIN       :P3.2
//<i>STC8G1KxxT_20PIN      :P5.4
//<i>STC8G2KxxS2_ALL       :P1.2
//<i>STC8G2KxxS4_ALL       :P1.2
//<i>STC8H1Kxx_20PIN       :无
//<i>STC8H1Kxx_32PIN       :P1.2
//<i>STC8H2KxxT_48PIN      :无
//<i>STC8H3KxxS2_48PIN     :P1.2
//<i>STC8H3KxxS4_48PIN     :P1.2
//<i>STC8H8KxxU_48PIN_64PIN:P5.4
#define ECBM_ADC_CH2_EN (0)
//<q>通道3
//<i>STC8A4KxxS2A12_ALL    :P1.3
//<i>STC8A8KxxS4A12_ALL    :P1.3
//<i>STC8A8KxxD4_ALL       :P1.3
//<i>STC8G1Kxx_16PIN_20PIN :P1.3
//<i>STC8G1KxxA_8PIN       :P3.3
//<i>STC8G1KxxT_20PIN      :P1.3
//<i>STC8G2KxxS2_ALL       :P1.3
//<i>STC8G2KxxS4_ALL       :P1.3
//<i>STC8H1Kxx_20PIN       :P3.0
//<i>STC8H1Kxx_32PIN       :P1.3
//<i>STC8H2KxxT_48PIN      :P1.3
//<i>STC8H3KxxS2_48PIN     :无
//<i>STC8H3KxxS4_48PIN     :无
//<i>STC8H8KxxU_48PIN_64PIN:P1.3
#define ECBM_ADC_CH3_EN (0)
//<q>通道4
//<i>STC8A4KxxS2A12_ALL    :P1.4
//<i>STC8A8KxxS4A12_ALL    :P1.4
//<i>STC8A8KxxD4_ALL       :P1.4
//<i>STC8G1Kxx_16PIN_20PIN :P1.4
//<i>STC8G1KxxA_8PIN       :P5.4
//<i>STC8G1KxxT_20PIN      :P1.4
//<i>STC8G2KxxS2_ALL       :P1.4
//<i>STC8G2KxxS4_ALL       :P1.4
//<i>STC8H1Kxx_20PIN       :无
//<i>STC8H1Kxx_32PIN       :P1.4
//<i>STC8H2KxxT_48PIN      :P1.4
//<i>STC8H3KxxS2_48PIN     :无
//<i>STC8H3KxxS4_48PIN     :无
//<i>STC8H8KxxU_48PIN_64PIN:P1.4
#define ECBM_ADC_CH4_EN (0)
//<q>通道5
//<i>STC8A4KxxS2A12_ALL    :P1.5
//<i>STC8A8KxxS4A12_ALL    :P1.5
//<i>STC8A8KxxD4_ALL       :P1.5
//<i>STC8G1Kxx_16PIN_20PIN :P1.5
//<i>STC8G1KxxA_8PIN       :P5.5
//<i>STC8G1KxxT_20PIN      :P1.5
//<i>STC8G2KxxS2_ALL       :P1.5
//<i>STC8G2KxxS4_ALL       :P1.5
//<i>STC8H1Kxx_20PIN       :无
//<i>STC8H1Kxx_32PIN       :P1.5
//<i>STC8H2KxxT_48PIN      :P1.5
//<i>STC8H3KxxS2_48PIN     :无
//<i>STC8H3KxxS4_48PIN     :无
//<i>STC8H8KxxU_48PIN_64PIN:P1.5
#define ECBM_ADC_CH5_EN (0)
//<q>通道6
//<i>STC8A4KxxS2A12_ALL    :P1.6
//<i>STC8A8KxxS4A12_ALL    :P1.6
//<i>STC8A8KxxD4_ALL       :P1.6
//<i>STC8G1Kxx_16PIN_20PIN :P1.6
//<i>STC8G1KxxA_8PIN       :无
//<i>STC8G1KxxT_20PIN      :P1.6
//<i>STC8G2KxxS2_ALL       :P1.6
//<i>STC8G2KxxS4_ALL       :P1.6
//<i>STC8H1Kxx_20PIN       :无
//<i>STC8H1Kxx_32PIN       :P1.6
//<i>STC8H2KxxT_48PIN      :P1.6
//<i>STC8H3KxxS2_48PIN     :P1.6
//<i>STC8H3KxxS4_48PIN     :P1.6
//<i>STC8H8KxxU_48PIN_64PIN:P1.6
#define ECBM_ADC_CH6_EN (0)
//<q>通道7
//<i>STC8A4KxxS2A12_ALL    :P1.7
//<i>STC8A8KxxS4A12_ALL    :P1.7
//<i>STC8A8KxxD4_ALL       :P1.7
//<i>STC8G1Kxx_16PIN_20PIN :P1.7
//<i>STC8G1KxxA_8PIN       :无
//<i>STC8G1KxxT_20PIN      :P1.7
//<i>STC8G2KxxS2_ALL       :P1.7
//<i>STC8G2KxxS4_ALL       :P1.7
//<i>STC8H1Kxx_20PIN       :无
//<i>STC8H1Kxx_32PIN       :P1.7
//<i>STC8H2KxxT_48PIN      :P1.7
//<i>STC8H3KxxS2_48PIN     :P1.7
//<i>STC8H3KxxS4_48PIN     :P1.7
//<i>STC8H8KxxU_48PIN_64PIN:P1.7
#define ECBM_ADC_CH7_EN (0)
//<q>通道8
//<i>STC8A4KxxS2A12_ALL    :P0.0
//<i>STC8A8KxxS4A12_ALL    :P0.0
//<i>STC8A8KxxD4_ALL       :P0.0
//<i>STC8G1Kxx_16PIN_20PIN :P3.0
//<i>STC8G1KxxA_8PIN       :无
//<i>STC8G1KxxT_20PIN      :P3.0
//<i>STC8G2KxxS2_ALL       :P0.0
//<i>STC8G2KxxS4_ALL       :P0.0
//<i>STC8H1Kxx_20PIN       :无
//<i>STC8H1Kxx_32PIN       :P0.0
//<i>STC8H2KxxT_48PIN      :P0.0
//<i>STC8H3KxxS2_48PIN     :P0.0
//<i>STC8H3KxxS4_48PIN     :P0.0
//<i>STC8H8KxxU_48PIN_64PIN:P0.0
#define ECBM_ADC_CH8_EN (0)
//<q>通道9
//<i>STC8A4KxxS2A12_ALL    :P0.1
//<i>STC8A8KxxS4A12_ALL    :P0.1
//<i>STC8A8KxxD4_ALL       :P0.1
//<i>STC8G1Kxx_16PIN_20PIN :P3.1
//<i>STC8G1KxxA_8PIN       :无
//<i>STC8G1KxxT_20PIN      :P3.1
//<i>STC8G2KxxS2_ALL       :P0.1
//<i>STC8G2KxxS4_ALL       :P0.1
//<i>STC8H1Kxx_20PIN       :P3.1
//<i>STC8H1Kxx_32PIN       :P0.1
//<i>STC8H2KxxT_48PIN      :P0.1
//<i>STC8H3KxxS2_48PIN     :P0.1
//<i>STC8H3KxxS4_48PIN     :P0.1
//<i>STC8H8KxxU_48PIN_64PIN:P0.1
#define ECBM_ADC_CH9_EN (0)
//<q>通道10
//<i>STC8A4KxxS2A12_ALL    :P0.2
//<i>STC8A8KxxS4A12_ALL    :P0.2
//<i>STC8A8KxxD4_ALL       :P0.2
//<i>STC8G1Kxx_16PIN_20PIN :P3.2
//<i>STC8G1KxxA_8PIN       :无
//<i>STC8G1KxxT_20PIN      :P3.2
//<i>STC8G2KxxS2_ALL       :P0.2
//<i>STC8G2KxxS4_ALL       :P0.2
//<i>STC8H1Kxx_20PIN       :P3.2
//<i>STC8H1Kxx_32PIN       :P0.2
//<i>STC8H2KxxT_48PIN      :P0.2
//<i>STC8H3KxxS2_48PIN     :P0.2
//<i>STC8H3KxxS4_48PIN     :P0.2
//<i>STC8H8KxxU_48PIN_64PIN:P0.2
#define ECBM_ADC_CH10_EN (0)
//<q>通道11
//<i>STC8A4KxxS2A12_ALL    :P0.3
//<i>STC8A8KxxS4A12_ALL    :P0.3
//<i>STC8A8KxxD4_ALL       :P0.3
//<i>STC8G1Kxx_16PIN_20PIN :P3.3
//<i>STC8G1KxxA_8PIN       :无
//<i>STC8G1KxxT_20PIN      :P3.3
//<i>STC8G2KxxS2_ALL       :P0.3
//<i>STC8G2KxxS4_ALL       :P0.3
//<i>STC8H1Kxx_20PIN       :P3.3
//<i>STC8H1Kxx_32PIN       :P0.3
//<i>STC8H2KxxT_48PIN      :P0.3
//<i>STC8H3KxxS2_48PIN     :P0.3
//<i>STC8H3KxxS4_48PIN     :P0.3
//<i>STC8H8KxxU_48PIN_64PIN:P0.3
#define ECBM_ADC_CH11_EN (0)
//<q>通道12
//<i>STC8A4KxxS2A12_ALL    :P0.4
//<i>STC8A8KxxS4A12_ALL    :P0.4
//<i>STC8A8KxxD4_ALL       :P0.4
//<i>STC8G1Kxx_16PIN_20PIN :P3.4
//<i>STC8G1KxxA_8PIN       :无
//<i>STC8G1KxxT_20PIN      :P3.4
//<i>STC8G2KxxS2_ALL       :P0.4
//<i>STC8G2KxxS4_ALL       :P0.4
//<i>STC8H1Kxx_20PIN       :P3.4
//<i>STC8H1Kxx_32PIN       :无
//<i>STC8H2KxxT_48PIN      :P0.4
//<i>STC8H3KxxS2_48PIN     :P0.4
//<i>STC8H3KxxS4_48PIN     :P0.4
//<i>STC8H8KxxU_48PIN_64PIN:P0.4
#define ECBM_ADC_CH12_EN (0)
//<q>通道13
//<i>STC8A4KxxS2A12_ALL    :P0.5
//<i>STC8A8KxxS4A12_ALL    :P0.5
//<i>STC8A8KxxD4_ALL       :P0.5
//<i>STC8G1Kxx_16PIN_20PIN :P3.5
//<i>STC8G1KxxA_8PIN       :无
//<i>STC8G1KxxT_20PIN      :P3.5
//<i>STC8G2KxxS2_ALL       :P0.5
//<i>STC8G2KxxS4_ALL       :P0.5
//<i>STC8H1Kxx_20PIN       :P3.5
//<i>STC8H1Kxx_32PIN       :无
//<i>STC8H2KxxT_48PIN      :P0.5
//<i>STC8H3KxxS2_48PIN     :P0.5
//<i>STC8H3KxxS4_48PIN     :P0.5
//<i>STC8H8KxxU_48PIN_64PIN:P0.5
#define ECBM_ADC_CH13_EN (0)
//<q>通道14
//<i>STC8A4KxxS2A12_ALL    :P0.6
//<i>STC8A8KxxS4A12_ALL    :P0.6
//<i>STC8A8KxxD4_ALL       :P0.6
//<i>STC8G1Kxx_16PIN_20PIN :P3.6
//<i>STC8G1KxxA_8PIN       :无
//<i>STC8G1KxxT_20PIN      :P3.6
//<i>STC8G2KxxS2_ALL       :P0.6
//<i>STC8G2KxxS4_ALL       :P0.6
//<i>STC8H1Kxx_20PIN       :P3.6
//<i>STC8H1Kxx_32PIN       :无
//<i>STC8H2KxxT_48PIN      :P0.6
//<i>STC8H3KxxS2_48PIN     :P0.6
//<i>STC8H3KxxS4_48PIN     :P0.6
//<i>STC8H8KxxU_48PIN_64PIN:P0.6
#define ECBM_ADC_CH14_EN (0)
//</h>
//<h>ADC参数设置
//<o.0..3>ADC的分频系数
//<6-15>
//<i>该项决定了ADC的转换速度。可以输入0~15，对应1分频到16分频。
//<i>但是实测输入6以下的效果很差。所以限制只能输入6以上的。
//<i>ADC的采样率=SYSCLK/2/分频系数。
//<o.5>ADC的对齐方式
//<0=>左对齐
//<1=>右对齐
//<i>对齐分为左对齐和右对齐两种，下面从两个实例上说明两种对齐的用途。
//<i>左对齐：ADC_RES保存结果的高8位，ADC_RESL保存结果的低4位（对于12位ADC来说）。
//<i>左对齐的布局为[D11 D10 D9 D8 D7 D6 D5 D4][D3 D2 D1 D0 0 0 0 0]，取值范围为0~65520，步进值为16。直接把两个寄存器拼在一起成16位数据的话，使用上会有些不便。
//<i>但是考虑到ADC在转换时，由于电源不稳等原因会引起数据低位波动。如果项目精度要求不是太高却要求数据稳定的话，视情况可以不做软件滤波，直接舍弃低4位即可。
//<i>右对齐：ADC_RES保存结果的高4位（对于12位ADC来说），ADC_RESL保存结果的低8位。
//<i>右对齐的布局为[0 0 0 0 D11 D10 D9 D8][D7 D6 D5 D4 D3 D2 D1 D0]，取值范围为0~4095，步进值为1。
//<i>和左对齐一比较就知道右对齐模式下可以直接把两个寄存器结果拼在一起作为一个16位数据来使用。
#define ECBM_ADC_CFG (47)
//<q>舍弃低位数据
//<i>根据上面的讲解，如果确实需要舍弃低位数据，请勾选此选项，之后adc_read函数就只输出ADC_RES的值，ADC_RESL的值会被舍去。
#define ECBM_ADC_8BIT (0)
//<q>ADC中断
#define ECBM_ADC_IT_EN (0)
//<h>ADC扩展功能
//<i>既然是扩展功能，就说明不是每个型号都有。注意甄别。
//<q>ADC与PWM关联
#define ECBM_ADC_PWM_EN (0)
//<o.4..5>外部IO触发ADC
//<0=>不触发 
//<2=>上升沿触发 
//<3=>下降沿触发 
//<o.0..2>自动转换次数
//<i>可以设置ADC采集一定次数并求平均值之后再触发中断标志位。
//<0=>1次 
//<4=>2次 
//<5=>4次 
//<6=>8次 
//<7=>16次
#define ECBM_ADC_EXCFG (0x00)
//</h>
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-------------------------------------头文件加载-----------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
/*####################################ADC位数解析##################################*/
#if     ((ECBM_MCU&0x0000F0)==0x0000C0)
#   define  ECBM_MCU_ADC_MAX  (4096.0f)
#elif   ((ECBM_MCU&0x0000F0)==0x0000A0)
#   define  ECBM_MCU_ADC_MAX  (1024.0f)
#else
#   define  ECBM_MCU_ADC_MAX  (1.0f)//防止空定义
#endif
/*####################################ADC通道解析##################################*/
#if (ECBM_MCU==0x2405C2)//STC8A4KxxS2A12_ALL
#   define  A00 (0x10)
#   define  A01 (0x11)
#   define  A02 (0x12)
#   define  A03 (0x13)
#   define  A04 (0x14)
#   define  A05 (0x15)
#   define  A06 (0x16)
#   define  A07 (0x17)
#   define  A08 (0x00)
#   define  A09 (0x01)
#   define  A10 (0x02)
#   define  A11 (0x03)
#   define  A12 (0x04)
#   define  A13 (0x05)
#   define  A14 (0x06)
#elif   (ECBM_MCU==0x2805C4)//STC8A8KxxS4A12_ALL 
#   define  A00 (0x10)
#   define  A01 (0x11)
#   define  A02 (0x12)
#   define  A03 (0x13)
#   define  A04 (0x14)
#   define  A05 (0x15)
#   define  A06 (0x16)
#   define  A07 (0x17)
#   define  A08 (0x00)
#   define  A09 (0x01)
#   define  A10 (0x02)
#   define  A11 (0x03)
#   define  A12 (0x04)
#   define  A13 (0x05)
#   define  A14 (0x06)
#elif   (ECBM_MCU==0x2815C4)//STC8A8KxxD4_ALL 
#   define  A00 (0x10)
#   define  A01 (0x11)
#   define  A02 (0x12)
#   define  A03 (0x13)
#   define  A04 (0x14)
#   define  A05 (0x15)
#   define  A06 (0x16)
#   define  A07 (0x17)
#   define  A08 (0x00)
#   define  A09 (0x01)
#   define  A10 (0x02)
#   define  A11 (0x03)
#   define  A12 (0x04)
#   define  A13 (0x05)
#   define  A14 (0x06)
#elif   (ECBM_MCU==0x3103A2)//STC8G1Kxx_16PIN_20PIN 
#   define  A00 (0x10)
#   define  A01 (0x11)
#   define  A02 (0x12)
#   define  A03 (0x13)
#   define  A04 (0x14)
#   define  A05 (0x15)
#   define  A06 (0x16)
#   define  A07 (0x17)
#   define  A08 (0x30)
#   define  A09 (0x31)
#   define  A10 (0x32)
#   define  A11 (0x33)
#   define  A12 (0x34)
#   define  A13 (0x35)
#   define  A14 (0x36)
#elif   (ECBM_MCU==0x3102A1)//STC8G1KxxA_8PIN 
#   define  A00 (0x30)
#   define  A01 (0x31)
#   define  A02 (0x32)
#   define  A03 (0x33)
#   define  A04 (0x54)
#   define  A05 (0x55)
#elif   (ECBM_MCU==0x3103A1)//STC8G1KxxT_20PIN 
#   define  A00 (0x10)
#   define  A01 (0x11)
#   define  A02 (0x54)
#   define  A03 (0x13)
#   define  A04 (0x14)
#   define  A05 (0x15)
#   define  A06 (0x16)
#   define  A07 (0x17)
#   define  A08 (0x30)
#   define  A09 (0x31)
#   define  A10 (0x32)
#   define  A11 (0x33)
#   define  A12 (0x34)
#   define  A13 (0x35)
#   define  A14 (0x36)
#elif   (ECBM_MCU==0x3205A2)//STC8G2KxxS2_ALL 
#   define  A00 (0x10)
#   define  A01 (0x11)
#   define  A02 (0x12)
#   define  A03 (0x13)
#   define  A04 (0x14)
#   define  A05 (0x15)
#   define  A06 (0x16)
#   define  A07 (0x17)
#   define  A08 (0x00)
#   define  A09 (0x01)
#   define  A10 (0x02)
#   define  A11 (0x03)
#   define  A12 (0x04)
#   define  A13 (0x05)
#   define  A14 (0x06)
#elif   (ECBM_MCU==0x3205A4)//STC8G2KxxS4_ALL 
#   define  A00 (0x10)
#   define  A01 (0x11)
#   define  A02 (0x12)
#   define  A03 (0x13)
#   define  A04 (0x14)
#   define  A05 (0x15)
#   define  A06 (0x16)
#   define  A07 (0x17)
#   define  A08 (0x00)
#   define  A09 (0x01)
#   define  A10 (0x02)
#   define  A11 (0x03)
#   define  A12 (0x04)
#   define  A13 (0x05)
#   define  A14 (0x06)
#elif   (ECBM_MCU==0x4103A2)//STC8H1Kxx_20PIN 
#   define  A00 (0x10)
#   define  A01 (0x11)
#   define  A08 (0x30)
#   define  A09 (0x31)
#   define  A10 (0x32)
#   define  A11 (0x33)
#   define  A12 (0x34)
#   define  A13 (0x35)
#   define  A14 (0x36)
#elif   (ECBM_MCU==0x4105A2)//STC8H1Kxx_32PIN  
#   define  A00 (0x10)
#   define  A01 (0x11)
#   define  A02 (0x12)
#   define  A03 (0x13)
#   define  A04 (0x14)
#   define  A05 (0x15)
#   define  A06 (0x16)
#   define  A07 (0x17)
#   define  A08 (0x00)
#   define  A09 (0x01)
#   define  A10 (0x02)
#   define  A11 (0x03)
#elif   (ECBM_MCU==0x4205C4)//STC8H2KxxT_48PIN 
#   define  A00 (0x10)
#   define  A01 (0x11)
#   define  A03 (0x13)
#   define  A04 (0x14)
#   define  A05 (0x15)
#   define  A06 (0x16)
#   define  A07 (0x17)
#   define  A08 (0x00)
#   define  A09 (0x01)
#   define  A10 (0x02)
#   define  A11 (0x03)
#   define  A12 (0x04)
#   define  A13 (0x05)
#   define  A14 (0x06)
#elif   (ECBM_MCU==0x4305C2)//STC8H3KxxS2_48PIN  
#   define  A00 (0x10)
#   define  A01 (0x11)
#   define  A02 (0x12)
#   define  A06 (0x16)
#   define  A07 (0x17)
#   define  A08 (0x00)
#   define  A09 (0x01)
#   define  A10 (0x02)
#   define  A11 (0x03)
#   define  A12 (0x04)
#   define  A13 (0x05)
#   define  A14 (0x06)
#elif   (ECBM_MCU==0x4305C4)//STC8H3KxxS4_48PIN 
#   define  A00 (0x10)
#   define  A01 (0x11)
#   define  A02 (0x12)
#   define  A06 (0x16)
#   define  A07 (0x17)
#   define  A08 (0x00)
#   define  A09 (0x01)
#   define  A10 (0x02)
#   define  A11 (0x03)
#   define  A12 (0x04)
#   define  A13 (0x05)
#   define  A14 (0x06)
#elif   (ECBM_MCU==0x4805C4)//STC8H8KxxU_48PIN_64PIN 
#   define  A00 (0x10)
#   define  A01 (0x11)
#   define  A02 (0x54)
#   define  A03 (0x13)
#   define  A04 (0x14)
#   define  A05 (0x15)
#   define  A06 (0x16)
#   define  A07 (0x17)
#   define  A08 (0x00)
#   define  A09 (0x01)
#   define  A10 (0x02)
#   define  A11 (0x03)
#   define  A12 (0x04)
#   define  A13 (0x05)
#   define  A14 (0x06)
#endif
/*--------------------------------------变量定义-----------------------------------*/
extern float xdata adc_ch15_gxf;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：adc_init
描  述：ADC初始化函数。用于设置ADC工作配置，将相应的IO设置成高阻。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
    adc_init();//初始化ADC
创建日期：2019-7-31
修改记录：
2019-8-5：增加了中断使能和中断优先级设置。
2021-6-10：新增STC8A8K64D4。
-------------------------------------------------------*/
extern void adc_init(void);
/*-------------------------------------------------------
函数名：adc_read
描  述：查询法读取AD值函数。用于把某通道对应的IO口电压值转换成AD值。
输  入：
    ch      要读取的通道号，可输入0~15。
输  出：无
返回值：
    该通道的AD值。可返回8位数据或者12位数据，看具体设置。
创建者：奈特
调用例程：
    val=adc_read(0);//读取通道0的AD值。
创建日期：2019-7-31
修改记录：
2020-07-28：只保留一个函数
-------------------------------------------------------*/
extern u16 adc_read(u8 ch);
/*-------------------------------------------------------
函数名：adc_read_start
描  述：ADC转换开始函数（中断法）。用于开启对某通道对应的IO口电压的转换。该函数只开始一次转换，并不会马上得到结果。
输  入：
    ch      要读取的通道号，可输入0~15。
输  出：无
返回值：无
创建者：奈特
调用例程：
    adc_read_start(0);//准备读取通道0的AD值。在中断函数中读取ADC转换结果。
创建日期：2019-8-5
修改记录：
-------------------------------------------------------*/
extern void adc_read_start(u8 ch);
/*-------------------------------------------------------
函数名：adc_read_it
描  述：中断法读取AD值函数。在ADC中断中调用本函数，可得到ADC转换的结果。转换的通道用adc_read_start函数设置。
输  入：无
输  出：无
返回值：
    该通道的AD值
创建者：奈特
调用例程：
    //本函数是放在中断函数中的。
    void adc_it_fun() ADC_FUN   //ADC中断函数
    {
        ADC_CLS_IT;             //清除对应的中断标志位。
        val=adc_read_it();      //读取转换后的AD值。
    }
创建日期：2019-8-5
修改记录：
2020-07-28：只保留一个函数
-------------------------------------------------------*/
extern u16 adc_read_it(void);
/*-------------------------------------------------------
函数名：adc_voltage
描  述：读取电压函数。用于读取某通道对应的IO口电压值。
输  入：
    ch      要读取的通道号，可输入0~15。
    vref    adc的vref电压，最好实测得到。
输  出：无
返回值：
    该通道的电压值
创建者：奈特
调用例程：
    val=adc_voltage(0,3.299);//读取通道0的电压值，vref是3.299V。
创建日期：2019-7-31
修改记录：
-------------------------------------------------------*/
extern float adc_voltage(u8 ch,float vref);
/*-------------------------------------------------------
函数名：adc_it_start
描  述：开启ADC中断函数。用于打开ADC的中断。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
    adc_it_start();//开启ADC的中断。
创建日期：2019-8-5
修改记录：
-------------------------------------------------------*/
extern void adc_it_start(void);
/*-------------------------------------------------------
函数名：adc_it_stop
描  述：关闭ADC中断函数。用于关闭ADC的中断。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：
    adc_it_stop();//关闭ADC的中断。
创建日期：2019-8-5
修改记录：
-------------------------------------------------------*/
extern void adc_it_stop(void);
/*-------------------------------------------------------
函数名：adc_read_vref
描  述：ADC读取Vref函数。
输  入：无
输  出：无
返回值：
    Vref的电压值，单位V。
创建者：奈特
调用例程：无
创建日期：2019-8-5
修改记录：
-------------------------------------------------------*/
extern float adc_read_vref(void);
/*-------------------------------------------------------
函数名：adc_it_callback
描  述：ADC中断回调函数。当ADC转换完毕时执行。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2022-2-7
修改记录：
-------------------------------------------------------*/
extern void adc_it_callback(void);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。