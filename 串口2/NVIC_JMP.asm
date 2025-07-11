;============= �û��������� ==============
BOOTLOADER_BASE_ADDR   EQU     0800H    ; �ж���ת����ַ�������޸ģ�
;=======================================
;================ �����ж���ת�� ================
; �жϺ�0 (INT0)
CSEG AT 0003H
    LJMP BOOTLOADER_BASE_ADDR + 0003H

; �жϺ�1 (TIMER0)
CSEG AT 000BH
    LJMP BOOTLOADER_BASE_ADDR + 000BH

; �жϺ�2 (INT1)
CSEG AT 0013H
    LJMP BOOTLOADER_BASE_ADDR + 0013H

; �жϺ�3 (TIMER1)
CSEG AT 001BH
    LJMP BOOTLOADER_BASE_ADDR + 001BH

; �жϺ�4 (UART)
CSEG AT 0023H
    LJMP BOOTLOADER_BASE_ADDR + 0023H

; �жϺ�5 (TIMER2)
CSEG AT 002BH
    LJMP BOOTLOADER_BASE_ADDR + 002BH

; �жϺ�6 (Reserved/Custom)
CSEG AT 0033H
    LJMP BOOTLOADER_BASE_ADDR + 0033H

; �жϺ�7 (Reserved/Custom)
CSEG AT 003BH
    LJMP BOOTLOADER_BASE_ADDR + 003BH

; �жϺ�8 (Reserved/Custom)
CSEG AT 0043H
    LJMP BOOTLOADER_BASE_ADDR + 0043H

; �жϺ�9 (Reserved/Custom)
CSEG AT 004BH
    LJMP BOOTLOADER_BASE_ADDR + 004BH

; �жϺ�10 (Reserved/Custom)
CSEG AT 0053H
    LJMP BOOTLOADER_BASE_ADDR + 0053H

; �жϺ�11 (Reserved/Custom)
CSEG AT 005BH
    LJMP BOOTLOADER_BASE_ADDR + 005BH

; �жϺ�12 (Reserved/Custom)
CSEG AT 0063H
    LJMP BOOTLOADER_BASE_ADDR + 0063H

; �жϺ�13 (Reserved/Custom)
CSEG AT 006BH
    LJMP BOOTLOADER_BASE_ADDR + 006BH

; �жϺ�14 (Reserved/Custom)
CSEG AT 0073H
    LJMP BOOTLOADER_BASE_ADDR + 0073H

; �жϺ�15 (Reserved/Custom)
CSEG AT 007BH
    LJMP BOOTLOADER_BASE_ADDR + 007BH

; �жϺ�16 (Reserved/Custom)
CSEG AT 0083H
    LJMP BOOTLOADER_BASE_ADDR + 0083H

; �жϺ�17 (Reserved/Custom)
CSEG AT 008BH
    LJMP BOOTLOADER_BASE_ADDR + 008BH

; �жϺ�18 (Reserved/Custom)
CSEG AT 0093H
    LJMP BOOTLOADER_BASE_ADDR + 0093H

; �жϺ�19 (Reserved/Custom)
CSEG AT 009BH
    LJMP BOOTLOADER_BASE_ADDR + 009BH

; �жϺ�20 (Reserved/Custom)
CSEG AT 00A3H
    LJMP BOOTLOADER_BASE_ADDR + 00A3H

; �жϺ�21 (Reserved/Custom)
CSEG AT 00ABH
    LJMP BOOTLOADER_BASE_ADDR + 00ABH

; �жϺ�22 (Reserved/Custom)
CSEG AT 00B3H
    LJMP BOOTLOADER_BASE_ADDR + 00B3H

; �жϺ�23 (Reserved/Custom)
CSEG AT 00BBH
    LJMP BOOTLOADER_BASE_ADDR + 00BBH

; �жϺ�24 (Reserved/Custom)
CSEG AT 00C3H
    LJMP BOOTLOADER_BASE_ADDR + 00C3H

; �жϺ�25 (Reserved/Custom)
CSEG AT 00CBH
    LJMP BOOTLOADER_BASE_ADDR + 00CBH

; �жϺ�26 (Reserved/Custom)
CSEG AT 00D3H
    LJMP BOOTLOADER_BASE_ADDR + 00D3H

; �жϺ�27 (Reserved/Custom)
CSEG AT 00DBH
    LJMP BOOTLOADER_BASE_ADDR + 00DBH

; �жϺ�28 (Reserved/Custom)
CSEG AT 00E3H
    LJMP BOOTLOADER_BASE_ADDR + 00E3H

; �жϺ�29 (Reserved/Custom)
CSEG AT 00EBH
    LJMP BOOTLOADER_BASE_ADDR + 00EBH

; �жϺ�30 (Reserved/Custom)
CSEG AT 00F3H
    LJMP BOOTLOADER_BASE_ADDR + 00F3H

; �жϺ�31 (Reserved/Custom)
CSEG AT 00FBH
    LJMP BOOTLOADER_BASE_ADDR + 00FBH

; �жϺ�32 (Reserved/Custom)
CSEG AT 0103H
    LJMP BOOTLOADER_BASE_ADDR + 0103H

; �жϺ�33 (Reserved/Custom)
CSEG AT 010BH
    LJMP BOOTLOADER_BASE_ADDR + 010BH

; �жϺ�34 (Reserved/Custom)
CSEG AT 0113H
    LJMP BOOTLOADER_BASE_ADDR + 0113H

; �жϺ�35 (Reserved/Custom)
CSEG AT 011BH
    LJMP BOOTLOADER_BASE_ADDR + 011BH

; �жϺ�36 (Reserved/Custom)
CSEG AT 0123H
    LJMP BOOTLOADER_BASE_ADDR + 0123H

; �жϺ�37 (Reserved/Custom)
CSEG AT 012BH
    LJMP BOOTLOADER_BASE_ADDR + 012BH

; �жϺ�38 (Reserved/Custom)
CSEG AT 0133H
    LJMP BOOTLOADER_BASE_ADDR + 0133H

; �жϺ�39 (Reserved/Custom)
CSEG AT 013BH
    LJMP BOOTLOADER_BASE_ADDR + 013BH

; �жϺ�40 (Reserved/Custom)
CSEG AT 0143H
    LJMP BOOTLOADER_BASE_ADDR + 0143H

; �жϺ�41 (Reserved/Custom)
CSEG AT 014BH
    LJMP BOOTLOADER_BASE_ADDR + 014BH

; �жϺ�42 (Reserved/Custom)
CSEG AT 0153H
    LJMP BOOTLOADER_BASE_ADDR + 0153H

; �жϺ�43 (Reserved/Custom)
CSEG AT 015BH
    LJMP BOOTLOADER_BASE_ADDR + 015BH

; �жϺ�44 (Reserved/Custom)
CSEG AT 0163H
    LJMP BOOTLOADER_BASE_ADDR + 0163H

; �жϺ�45 (Reserved/Custom)
CSEG AT 016BH
    LJMP BOOTLOADER_BASE_ADDR + 016BH

; �жϺ�46 (Reserved/Custom)
CSEG AT 0173H
    LJMP BOOTLOADER_BASE_ADDR + 0173H

; �жϺ�47 (Reserved/Custom)
CSEG AT 017BH
    LJMP BOOTLOADER_BASE_ADDR + 017BH

; �жϺ�48 (Reserved/Custom)
CSEG AT 0183H
    LJMP BOOTLOADER_BASE_ADDR + 0183H

; �жϺ�49 (Reserved/Custom)
CSEG AT 018BH
    LJMP BOOTLOADER_BASE_ADDR + 018BH

; �жϺ�50 (Reserved/Custom)
CSEG AT 0193H
    LJMP BOOTLOADER_BASE_ADDR + 0193H

; �жϺ�51 (Reserved/Custom)
CSEG AT 019BH
    LJMP BOOTLOADER_BASE_ADDR + 019BH

; �жϺ�52 (Reserved/Custom)
CSEG AT 01A3H
    LJMP BOOTLOADER_BASE_ADDR + 01A3H

; �жϺ�53 (Reserved/Custom)
CSEG AT 01ABH
    LJMP BOOTLOADER_BASE_ADDR + 01ABH

; �жϺ�54 (Reserved/Custom)
CSEG AT 01B3H
    LJMP BOOTLOADER_BASE_ADDR + 01B3H

; �жϺ�55 (Reserved/Custom)
CSEG AT 01BBH
    LJMP BOOTLOADER_BASE_ADDR + 01BBH

; �жϺ�56 (Reserved/Custom)
CSEG AT 01C3H
    LJMP BOOTLOADER_BASE_ADDR + 01C3H

; �жϺ�57 (Reserved/Custom)
CSEG AT 01CBH
    LJMP BOOTLOADER_BASE_ADDR + 01CBH

; �жϺ�58 (Reserved/Custom)
CSEG AT 01D3H
    LJMP BOOTLOADER_BASE_ADDR + 01D3H

; �жϺ�59 (Reserved/Custom)
CSEG AT 01DBH
    LJMP BOOTLOADER_BASE_ADDR + 01DBH

; �жϺ�60 (Reserved/Custom)
CSEG AT 01E3H
    LJMP BOOTLOADER_BASE_ADDR + 01E3H

; �жϺ�61 (Reserved/Custom)
CSEG AT 01EBH
    LJMP BOOTLOADER_BASE_ADDR + 01EBH

; �жϺ�62 (Reserved/Custom)
CSEG AT 01F3H
    LJMP BOOTLOADER_BASE_ADDR + 01F3H

; �жϺ�63 (Reserved/Custom)
CSEG AT 01FBH
    LJMP BOOTLOADER_BASE_ADDR + 01FBH
END