#ifndef _SPG290_REGISTERS_H
#define _SPG290_REGISTERS_H

#define HS_LEDS(value) (*P_CSI_GPIO_SETUP = (0x1FFE0000+(value<<5)))

typedef volatile unsigned int UV32;

//**************************************************************//
//                        CKG & PLL                             //
//**************************************************************//
#define P_CLK_CPU_SEL                       (UV32*)0x88210004
#define P_CLK_AHB_CONF                      (UV32*)0x88210008
#define P_CLK_AHB_SEL                       (UV32*)0x8821000C
#define P_CLK_PLLV_CONF                     (UV32*)0x882100B4
#define P_CLK_PLLV_SEL                      (UV32*)0x882100B8
#define P_CLK_PLLAU_CONF                    (UV32*)0x882100bc
#define P_CLK_32K_CONF                      (UV32*)0x88210114
#define P_PLLV_STABLE_TIME                  (UV32*)0x88210104
#define P_BUFCTRL_CLK_CONF                  (UV32*)0x882100C8
//**************************************************************//
//                           GPIO                               //
//**************************************************************//
#define P_GPIO_CLK_CONF                     (UV32*)0x882100FC
#define P_IOA_GPIO_SETUP                    (UV32*)0x88200038
#define P_IOB_GPIO_SETUP                    (UV32*)0x8820004C
#define P_IOB_GPIO_INPUT                    (UV32*)0x88200070
#define P_IOA_GPIO_INPUT                    (UV32*)0x88200074
#define P_IOA_GPIO_INT                      (UV32*)0x88200090
//**************************************************************//
//                           SFTCFG                             //
//**************************************************************//
#define P_ROMCSN_INTERFACE_SEL              (UV32*)0x88200004
#define P_DRAM_INTERFACE_SEL                (UV32*)0x88200008
#define P_DRAM_GPIO_SETUP                   (UV32*)0x88200050
#define P_DRAM_GPIO_INPUT                   (UV32*)0x88200070
#define P_CLK_CPU2MPEG4_SEL                 (UV32*)0x882000C0
//**************************************************************//
//                            WDOG                              //
//**************************************************************//
#define P_WDOG_CLK_CONF                     (UV32*)0x88210084
#define P_WDOG_RESET_STATUS                 (UV32*)0x882100E8
#define P_WDOG_MODE_CTRL                    (UV32*)0x88170000
#define P_WDOG_CYCLE_SETUP                  (UV32*)0x88170004
#define P_WDOG_CLR_COMMAND                  (UV32*)0x88170008
//**************************************************************//
//                          Sleep-Wakeup                        //
//**************************************************************//
#define P_SLEEP_MODE_CTRL                   (UV32*)0x88210000
#define P_SLEEP_CLK_SEL                     (UV32*)0x882100DC
#define P_WAKEUP_KEYC_SEL                   (UV32*)0x88200008
#define P_WAKEUP_KEYC_CLR                   (UV32*)0x882100C0
//**************************************************************//
//                            INT                               //
//**************************************************************//
#define P_INT_CLK_CONF                      (UV32*)0x882100D0
#define P_INT_REQ_STATUS1                   (UV32*)0x880a0000
#define P_INT_REQ_STATUS2                   (UV32*)0x880a0004
#define P_INT_GROUP_PRI                     (UV32*)0x880a0008
#define P_INT_GROUP0_PRI                    (UV32*)0x880a0010
#define P_INT_GROUP1_PRI                    (UV32*)0x880a0014
#define P_INT_GROUP2_PRI                    (UV32*)0x880a0018
#define P_INT_GROUP3_PRI                    (UV32*)0x880a001C
#define P_INT_MASK_CTRL1                    (UV32*)0x880a0020
#define P_INT_MASK_CTRL2                    (UV32*)0x880a0024
//**************************************************************//
//                              MIU                             //
//**************************************************************//
#define P_MIU_CLK_CONF                      (UV32*)0x88210010
#define P_MIU_SDRAM_POWER                   (UV32*)0x8807005C
#define P_MIU_SDRAM_SETUP1                  (UV32*)0x88070060
#define P_MIU_SDRAM_SETUP2                  (UV32*)0x88070094
#define P_MIU_SDRAM_SETUP3                  (UV32*)0x88230060
#define P_MIU_SDRAM_STATUS                  (UV32*)0x8807006C
//**************************************************************//
//                            APBDMA                            //
//**************************************************************//
#define P_DMA_CLK_CONF                      (UV32*)0x88210058
#define P_DMA_BUSY_STATUS                   (UV32*)0x88080000
#define P_DMA_INT_STATUS                    (UV32*)0x88080004
#define P_DMA_AHB_SA0BA                     (UV32*)0x88080008
#define P_DMA_AHB_SA1BA                     (UV32*)0x8808000C
#define P_DMA_AHB_SA2BA                     (UV32*)0x88080010
#define P_DMA_AHB_SA3BA                     (UV32*)0x88080014
#define P_DMA_AHB_EA0BA                     (UV32*)0x88080018
#define P_DMA_AHB_EA1BA                     (UV32*)0x8808001C
#define P_DMA_AHB_EA2BA                     (UV32*)0x88080020
#define P_DMA_AHB_EA3BA                     (UV32*)0x88080024
#define P_DMA_APB_SA0                       (UV32*)0x88080028
#define P_DMA_APB_SA1                       (UV32*)0x8808002C
#define P_DMA_APB_SA2                       (UV32*)0x88080030
#define P_DMA_APB_SA3                       (UV32*)0x88080034
#define P_DMA_AHB_SA0BB                     (UV32*)0x8808004C
#define P_DMA_AHB_SA1BB                     (UV32*)0x88080050
#define P_DMA_AHB_SA2BB                     (UV32*)0x88080054
#define P_DMA_AHB_SA3BB                     (UV32*)0x88080058
#define P_DMA_AHB_EA0BB                     (UV32*)0x8808005C
#define P_DMA_AHB_EA1BB                     (UV32*)0x88080060
#define P_DMA_AHB_EA2BB                     (UV32*)0x88080064
#define P_DMA_AHB_EA3BB                     (UV32*)0x88080068
#define P_DMA_CHANNEL0_CTRL                 (UV32*)0x8808006C
#define P_DMA_CHANNEL1_CTRL                 (UV32*)0x88080070
#define P_DMA_CHANNEL2_CTRL                 (UV32*)0x88080074
#define P_DMA_CHANNEL3_CTRL                 (UV32*)0x88080078
#define P_DMA_CHANNEL_RESET                 (UV32*)0x8808007C
//**************************************************************//
//                           ADC                                //
//**************************************************************//
#define P_ADC_CLK_CONF                      (UV32*)0x882100AC
#define P_ADC_CLK_SEL                       (UV32*)0x882100B0
#define P_ADC_GPIO_SETUP                    (UV32*)0x88200048
#define P_ADC_GPIO_INPUT                    (UV32*)0x88200078
#define P_ADC_GPIO_INT                      (UV32*)0x8820009C
#define P_ADC_AINPUT_CTRL                   (UV32*)0x88200054
#define P_ADC_MIC_CTRL1                     (UV32*)0x881a0000
#define P_ADC_MIC_GAIN                      (UV32*)0x881a0004
#define P_ADC_SAMPLE_CLK                    (UV32*)0x881a0008
#define P_ADC_SAMPLE_HOLD                   (UV32*)0x881a000c
#define P_ADC_MIC_CTRL2                     (UV32*)0x881a0010
#define P_ADC_INT_STATUS                    (UV32*)0x881a0014
#define P_ADC_MANUAL_DATA                   (UV32*)0x881a0018
#define P_ADC_AUTO_DATA                     (UV32*)0x881a001c
#define P_ADC_MIC_DATA                      (UV32*)0x881a0020
//**************************************************************//
//                           DAC                                //
//**************************************************************//
#define P_DAC_BUFFER_SA                     (UV32*)0x88070054
#define P_DAC_CLK_CONF                      (UV32*)0x8821003C
#define P_DAC_FIFOBA_LOW                    (UV32*)0x88051080
#define P_DAC_FIFOBA_HIGH                   (UV32*)0x88051084
#define P_DAC_SAMPLE_CLK                    (UV32*)0x88051064
#define P_DAC_INT_STATUS                    (UV32*)0x88051088
#define P_DAC_MODE_CTRL1                    (UV32*)0x88051474
#define P_DAC_MODE_CTRL2                    (UV32*)0x88051034
#define P_DAC_OUTPUT_CH0                    (UV32*)0x88051040
#define P_DAC_OUTPUT_CH1                    (UV32*)0x88051044
//**************************************************************//
//                              Timer                           //
//**************************************************************//
#define P_TIMER_CLK_SEL                     (UV32*)0x882100E4
#define P_TIMER_INTERFACE_SEL               (UV32*)0x88200010
#define P_TIMER0_CLK_CONF                   (UV32*)0x8821006C
#define P_TIMER0_MODE_CTRL                  (UV32*)0x88160000
#define P_TIMER0_CCP_CTRL                   (UV32*)0x88160004
#define P_TIMER0_PRELOAD_DATA               (UV32*)0x88160008
#define P_TIMER0_CCP_DATA                   (UV32*)0x8816000C
#define P_TIMER0_COUNT_DATA                 (UV32*)0x88160010
#define P_TIMER1_CLK_CONF                   (UV32*)0x88210070
#define P_TIMER1_MODE_CTRL                  (UV32*)0x88161000
#define P_TIMER1_CCP_CTRL                   (UV32*)0x88161004
#define P_TIMER1_PRELOAD_DATA               (UV32*)0x88161008
#define P_TIMER1_CCP_DATA                   (UV32*)0x8816100C
#define P_TIMER1_COUNT_DATA                 (UV32*)0x88161010
#define P_TIMER2_CLK_CONF                   (UV32*)0x88210074
#define P_TIMER2_MODE_CTRL                  (UV32*)0x88162000
#define P_TIMER2_CCP_CTRL                   (UV32*)0x88162004
#define P_TIMER2_PRELOAD_DATA               (UV32*)0x88162008
#define P_TIMER2_CCP_DATA                   (UV32*)0x8816200C
#define P_TIMER2_COUNT_DATA                 (UV32*)0x88162010
#define P_TIMER3_CLK_CONF                   (UV32*)0x88210078
#define P_TIMER3_MODE_CTRL                  (UV32*)0x88163000
#define P_TIMER3_CCP_CTRL                   (UV32*)0x88163004
#define P_TIMER3_PRELOAD_DATA               (UV32*)0x88163008
#define P_TIMER3_CCP_DATA                   (UV32*)0x8816300C
#define P_TIMER3_COUNT_DATA                 (UV32*)0x88163010
#define P_TIMER4_CLK_CONF                   (UV32*)0x8821007C
#define P_TIMER4_MODE_CTRL                  (UV32*)0x88164000
#define P_TIMER4_CCP_CTRL                   (UV32*)0x88164004
#define P_TIMER4_PRELOAD_DATA               (UV32*)0x88164008
#define P_TIMER4_CCP_DATA                   (UV32*)0x8816400C
#define P_TIMER4_COUNT_DATA                 (UV32*)0x88164010
#define P_TIMER5_CLK_CONF                   (UV32*)0x88210080
#define P_TIMER5_MODE_CTRL                  (UV32*)0x88165000
#define P_TIMER5_CCP_CTRL                   (UV32*)0x88165004
#define P_TIMER5_PRELOAD_DATA               (UV32*)0x88165008
#define P_TIMER5_CCP_DATA                   (UV32*)0x8816500C
#define P_TIMER5_COUNT_DATA                 (UV32*)0x88165010
//**************************************************************//
//                           RTC                                //
//**************************************************************//
#define P_RTC_CLK_CONF                      (UV32*)0x88210088
#define P_RTC_TIME_SEC                      (UV32*)0x88166000
#define P_RTC_TIME_MIN                      (UV32*)0x88166004
#define P_RTC_TIME_HOUR                     (UV32*)0x88166008
#define P_RTC_ALM_SEC                       (UV32*)0x8816600C
#define P_RTC_ALM_MIN                       (UV32*)0x88166010
#define P_RTC_ALM_HOUR                      (UV32*)0x88166014
#define P_RTC_MODE_CTRL                     (UV32*)0x88166018
#define P_RTC_INT_STATUS                    (UV32*)0x8816601C
//**************************************************************//
//                           TMB                                //
//**************************************************************//
#define P_TMB_CLK_CONF                      (UV32*)0x882100E0
#define P_TMB_MODE_CTRL                     (UV32*)0x88166020
#define P_TMB_INT_STATUS                    (UV32*)0x88166024
#define P_TMB_RESET_COMMAND                 (UV32*)0x88166028
//**************************************************************//
//                           UART                               //
//**************************************************************//
#define P_UART_CLK_CONF                     (UV32*)0x8821005C
#define P_UART_INTERFACE_SEL                (UV32*)0x88200000
#define P_UART_GPIO_SETUP                   (UV32*)0x88200040
#define P_UART_GPIO_INPUT                   (UV32*)0x88200074
#define P_UART_GPIO_INT                     (UV32*)0x88200094
#define P_UART_MODE_CTRL                    (UV32*)0x88150008
#define P_UART_BAUDRATE_SETUP               (UV32*)0x8815000C
#define P_UART_TXRX_STATUS                  (UV32*)0x88150010
#define P_UART_ERR_STATUS                   (UV32*)0x88150004
#define P_UART_TXRX_DATA                    (UV32*)0x88150000
#define P_UART_WAKEUP_STATUS                (UV32*)0x88210110
//**************************************************************//
//                           SPI                                //
//**************************************************************//
#define P_SPI_CLK_CONF                      (UV32*)0x88210098
#define P_SPI_INTERFACE_SEL                 (UV32*)0x882000A4
#define P_SPI_MODE_CTRL                     (UV32*)0x88110000
#define P_SPI_TX_STATUS                     (UV32*)0x88110004
#define P_SPI_TX_DATA                       (UV32*)0x88110008
#define P_SPI_RX_STATUS                     (UV32*)0x8811000C
#define P_SPI_RX_DATA                       (UV32*)0x88110010
#define P_SPI_TXRX_STATUS                   (UV32*)0x88110014
//**************************************************************//
//                           I2C                                //
//**************************************************************//
#define P_I2C_CLK_CONF                      (UV32*)0x88210094
#define P_I2C_INTERFACE_SEL                 (UV32*)0x88200004
#define P_I2C_GPIO_SETUP                    (UV32*)0x88200044
#define P_I2C_GPIO_INPUT                    (UV32*)0x88200074
#define P_I2C_GPIO_INT                      (UV32*)0x88200098
#define P_I2C_MODE_CTRL                     (UV32*)0x88130020
#define P_I2C_INT_STATUS                    (UV32*)0x88130024
#define P_I2C_RATE_SETUP                    (UV32*)0x88130028
#define P_I2C_SLAVE_ADDR                    (UV32*)0x8813002C
#define P_I2C_DATA_ADDR                     (UV32*)0x88130030
#define P_I2C_TX_DATA                       (UV32*)0x88130034
#define P_I2C_RX_DATA                       (UV32*)0x88130038
//**************************************************************//
//                           SIO                                //
//**************************************************************//
#define P_SIO_INTERFACE_SEL                 (UV32*)0x88200004
#define P_JTAG_GPIO_SETUP                   (UV32*)0x88200034
#define P_JTAG_GPIO_INPUT                   (UV32*)0x88200070
#define P_JTAG_GPIO_INT                     (UV32*)0x8820008C
#define P_SIO_CLK_CONF                      (UV32*)0x882100A0
#define P_SIO_MODE_CTRL                     (UV32*)0x88120000
#define P_SIO_AUTO_CTRL                     (UV32*)0x88120004
#define P_SIO_DATA_ADDR                     (UV32*)0x88120008
#define P_SIO_TXRX_DATA                     (UV32*)0x8812000C
//**************************************************************//
//                           SD Card                            //
//**************************************************************//
#define P_SD_INTERFACE_SEL                  (UV32*)0x882000A4
#define P_SD_CLK_CONF                       (UV32*)0x882100A4
#define P_SD_MODE_CTRL                      (UV32*)0x88180018
#define P_SD_INT_CTRL                       (UV32*)0x8818001C
#define P_SD_INT_STATUS                     (UV32*)0x88180014
#define P_SD_COMMAND_SETUP                  (UV32*)0x88180008
#define P_SD_ARGUMENT_DATA                  (UV32*)0x8818000C
#define P_SD_RESPONSE_DATA                  (UV32*)0x88180010
#define P_SD_TX_DATA                        (UV32*)0x88180000
#define P_SD_RX_DATA                        (UV32*)0x88180004
//**************************************************************//
//                              NAND                            //
//**************************************************************//
#define P_NAND_INTERFACE_SEL                (UV32*)0x882000A4
#define P_NAND_GPIO_SETUP                   (UV32*)0x8820002C
#define P_NAND_GPIO_PULL                    (UV32*)0x88200030
#define P_NAND_GPIO_INPUT                   (UV32*)0x8820006C
#define P_NAND_GPIO_INT                     (UV32*)0x88200088
#define P_NAND_CLK_CONF                     (UV32*)0x882100A8
#define P_NAND_INT_CTRL                     (UV32*)0x88190014
#define P_NAND_MODE_CTRL                    (UV32*)0x88190000
#define P_NAND_CLE_COMMAND                  (UV32*)0x88190004
#define P_NAND_ALE_ADDR                     (UV32*)0x88190008
#define P_NAND_TX_DATA                      (UV32*)0x8819000C
#define P_NAND_RX_DATA                      (UV32*)0x88190010
#define P_NAND_INT_STATUS                   (UV32*)0x88190018
#define P_NAND_ECC_TRUELP                   (UV32*)0x8819001C
#define P_NAND_ECC_TRUECP                   (UV32*)0x88190020
#define P_NAND_ECC_CMPLP                    (UV32*)0x88190024
#define P_NAND_ECC_CMPCP                    (UV32*)0x88190028
#define P_NAND_ECC_STATUS                   (UV32*)0x8819002C
#define P_NAND_ECC_CTRL                     (UV32*)0x88190030
//**************************************************************//
//                              NOR                             //
//**************************************************************//
#define P_NOR_COMMAND_CTRL                  (UV32*)0x880700BC
#define P_NOR_BANK_SETUP                    (UV32*)0x880700C4
//**************************************************************//
//                           LCD                                //
//**************************************************************//
#define P_TFT_MODE_CTRL                     (UV32*)0x88040000
#define P_TFT_DATA_FMT                      (UV32*)0x88040004
#define P_TFT_HOR_ACT                       (UV32*)0x88040008
#define P_TFT_HOR_FRONT                     (UV32*)0x8804000C
#define P_TFT_HOR_BACK                      (UV32*)0x88040010
#define P_TFT_HOR_SYNC                      (UV32*)0x88040014
#define P_TFT_VER_ACT                       (UV32*)0x88040018
#define P_TFT_VER_FRONT                     (UV32*)0x8804001C
#define P_TFT_VER_BACK                      (UV32*)0x88040020
#define P_TFT_VER_SYNC                      (UV32*)0x88040024
#define P_TFT_FRAME_FMT1                    (UV32*)0x88040028
#define P_TFT_ROW_START                     (UV32*)0x8804002C
#define P_TFT_COL_START                     (UV32*)0x88040030
#define P_TFT_COL_WIDTH                     (UV32*)0x88040034
#define P_TFT_DUMMY_WIDTH                   (UV32*)0x88040038
#define P_TFT_BUFFER_STATUS                 (UV32*)0x8804003C
#define P_TFT_DATA_SEQ                      (UV32*)0x88040040
#define P_TFT_INT_STATUS                    (UV32*)0x88040050
#define P_TFT_FRAME_FMT2                    (UV32*)0x880400A0
#define P_LCD_CLK_CONF                      (UV32*)0x88210034
#define P_LCD_CLK_SEL                       (UV32*)0x88210038
#define P_LCD_INTERFACE_SEL                 (UV32*)0x88200000
#define P_LCD_BUFFER_SA1                    (UV32*)0x8807000C
#define P_LCD_BUFFER_SA2                    (UV32*)0x88070010
#define P_LCD_BUFFER_SA3                    (UV32*)0x88070014
#define P_LCD_BUFFER_SEL                    (UV32*)0x88090024
#define P_TFT_GPIO_DATA                     (UV32*)0x88200014
#define P_TFT_GPIO_OUTPUTEN                 (UV32*)0x88200018
#define P_TFT_GPIO_PULLUP                   (UV32*)0x8820001C
#define P_TFT_GPIO_PULLDOWN                 (UV32*)0x88200020
#define P_TFT_GPIO_INPUT                    (UV32*)0x88200064
#define P_TFT_GPIO_INT                      (UV32*)0x88200080
#define P_STN_MODE_CTRL                     (UV32*)0x88041000
#define P_STN_PIXEL_CLK                     (UV32*)0x88041004
#define P_STN_SEGMENT_NUM                   (UV32*)0x88041008
#define P_STN_COMMON_NUM                    (UV32*)0x8804100C
#define P_STN_ROW_START                     (UV32*)0x88041010
#define P_STN_COL_START                     (UV32*)0x88041014
#define P_STN_DUMMY_WIDTH                   (UV32*)0x88041018
#define P_STN_LINE_COUNT                    (UV32*)0x8804101C
#define P_STN_DATA_FMT                      (UV32*)0x88041020
#define P_STN_BUFFER_STATUS                 (UV32*)0x88041024
#define P_STN_FRAME_FMT1                    (UV32*)0x88041028
#define P_STN_DATA_SEQ                      (UV32*)0x8804102C
#define P_STN_FRAME_FMT2                    (UV32*)0x880410A0
//**************************************************************//
//                              other                           //
//**************************************************************//
#define P_LVR_RESET_CTRL                    (UV32*)0x882100C4
//**************************************************************//
//                               CSI                            //
//**************************************************************//
#define P_CSI_CLK_CONF                      (UV32*)0x88210018
#define P_CSI_CLK_SEL                       (UV32*)0x8821001C
#define P_CSI_INTERFACE_SEL                 (UV32*)0x88200000
#define P_CSI_PROBE_SEL                     (UV32*)0x88200004
#define P_CSI_GPIO_SETUP                    (UV32*)0x88200024
#define P_CSI_GPIO_PULL                     (UV32*)0x88200028
#define P_CSI_GPIO_INPUT                    (UV32*)0x88200068
#define P_CSI_GPIO_INT                      (UV32*)0x88200084
#define P_CSI_TG_CTRL                       (UV32*)0x88000000
#define P_CSI_LINE_START                    (UV32*)0x88000004
#define P_CSI_WINDOW_START                  (UV32*)0x88000008
#define P_CSI_WINDOW_END                    (UV32*)0x8800000c
#define P_CSI_BACKGROUND_COLOR              (UV32*)0x88000010
#define P_CSI_TOP_DETECT                    (UV32*)0x88000014
#define P_CSI_BOTTOM_DETECT                 (UV32*)0x88000018
#define P_CSI_TRANSPARENT_COLOR             (UV32*)0x8800001C
#define P_CSI_BUFFER_SA1                    (UV32*)0x88000020
#define P_CSI_BUFFER_SA2                    (UV32*)0x88000024
#define P_CSI_BUFFER_SA3                    (UV32*)0x88000028
#define P_CSI_BUFFER_SEL                    (UV32*)0x88090008
#define P_CSI_CAPTURE_CTRL                  (UV32*)0x8800002C
#define P_CSI_MD_CTRL                       (UV32*)0x88000030
#define P_CSI_RECOGNITION_SA                (UV32*)0x88000034
#define P_CSI_POSITION_SETUP                (UV32*)0x88000038
#define P_CSI_CLASSIFICATION_SA             (UV32*)0x8800003C
#define P_CSI_COLOR_TABLE1                  (UV32*)0x88000040
#define P_CSI_COLOR_TABLE2                  (UV32*)0x88000044
#define P_CSI_COLOR_TABLE3                  (UV32*)0x88000048
#define P_CSI_COLOR_TABLE4                  (UV32*)0x8800004C
#define P_CSI_DETECT_REGION1                (UV32*)0x88000050
#define P_CSI_DETECT_REGION2                (UV32*)0x88000054
#define P_CSI_DETECT_REGION3                (UV32*)0x88000058
#define P_CSI_THRESHOLD_SETUP               (UV32*)0x8800005C
#define P_CSI_CUT_SETUP                     (UV32*)0x88000060
#define P_CSI_CAPTURE_COLORVALUE            (UV32*)0x88000074
#define P_CSI_INT_CTRL                      (UV32*)0x88000078
#define P_CSI_INT_STATUS                    (UV32*)0x8800007C
#define P_CSI_FRAMELOSS_INT                 (UV32*)0x88090028
#define P_CSI_Y2R_FACTOR1                   (UV32*)0x880000E8
#define P_CSI_Y2R_FACTOR2                   (UV32*)0x880000EC
#define P_CSI_Y2R_FACTOR3                   (UV32*)0x880000F0
#define P_CSI_R2Y_FACTOR1                   (UV32*)0x880000F4
#define P_CSI_R2Y_FACTOR2                   (UV32*)0x880000F8
#define P_CSI_R2Y_FACTOR3                   (UV32*)0x880000FC
//**************************************************************//
//                               TV                             //
//**************************************************************//
#define P_TV_CLK_CONF                       (UV32*)0x88210030
#define P_TV_INTERFACE_SEL                  (UV32*)0x88200000
#define P_TV_MODE_CTRL                      (UV32*)0x88030000
#define P_TV_SATURATION_SETUP               (UV32*)0x88030004
#define P_TV_HUE_SETUP                      (UV32*)0x88030008
#define P_TV_FADE_SETUP                     (UV32*)0x8803000C
#define P_TV_FILTER_SEL                     (UV32*)0x88030010
#define P_TV_LINE_COUNT                     (UV32*)0x88030020
#define P_TV_LIGHTGUN_SEL                   (UV32*)0x88200010
#define P_TV_LIGHTGUN_CTRL                  (UV32*)0x8803002C
#define P_TV_LIGHTGUN0_X                    (UV32*)0x88030030
#define P_TV_LIGHTGUN0_Y                    (UV32*)0x88030034
#define P_TV_LIGHTGUN1_X                    (UV32*)0x88030038
#define P_TV_LIGHTGUN1_Y                    (UV32*)0x8803003C
#define P_TV_INT_CTRL                       (UV32*)0x88030040
#define P_TV_VIDEODAC_CTRL                  (UV32*)0x88030050
#define P_TV_BUFFER_SA1                     (UV32*)0x88070000
#define P_TV_BUFFER_SA2                     (UV32*)0x88070004
#define P_TV_BUFFER_SA3                     (UV32*)0x88070008
#define P_TV_BUFFER_SEL                     (UV32*)0x88090020
#define P_TV_FRAME_COUNT                    (UV32*)0x88090034
//**************************************************************//
//                               LDM                            //
//**************************************************************//
#define P_LDM_CLK_CONF                      (UV32*)0x882100CC
#define P_LDM_MODE_CTRL                     (UV32*)0x880C0000
#define P_LDM_INT_STATUS                    (UV32*)0x880C0004
#define P_LDM_MIU_SA                        (UV32*)0x880C0008
#define P_LDM_MIU_EA                        (UV32*)0x880C000C
#define P_LDM_START_ADDR                    (UV32*)0x880C0010
#define P_LDM_END_ADDR                      (UV32*)0x880C0014
//**************************************************************//
//                              BLNDMA                          //
//**************************************************************//
#define P_BLNDMA_CLK_CONF                   (UV32*)0x88210050
#define P_BLNDMA_SOURCEA_SA                 (UV32*)0x880D0000
#define P_BLNDMA_SOURCEB_SA                 (UV32*)0x880D0004
#define P_BLNDMA_DESTINATION_SA             (UV32*)0x880D0008
#define P_BLNDMA_WIDTH_HEIGHT               (UV32*)0x880D000C
#define P_BLNDMA_FILL_PATTERN               (UV32*)0x880D0010
#define P_BLNDMA_MODE_CTRL1                 (UV32*)0x880D0014
#define P_BLNDMA_INT_STATUS                 (UV32*)0x880D0018
#define P_BLNDMA_ALPHA_VALUE                (UV32*)0x880D001C
#define P_BLNDMA_FILTER_PATTERN             (UV32*)0x880D0020
#define P_BLNDMA_ADDR_MODE                  (UV32*)0x880D0024
#define P_BLNDMA_MODE_CTRL2                 (UV32*)0x880D0028
#define P_BLNDMA_SOURCEA_BA                 (UV32*)0x880D0030
#define P_BLNDMA_SOURCEA_OA                 (UV32*)0x880D0034
#define P_BLNDMA_SOURCEA_BACKGROUND         (UV32*)0x880D0038
#define P_BLNDMA_SOURCEB_BA                 (UV32*)0x880D0040
#define P_BLNDMA_SOURCEB_OA                 (UV32*)0x880D0044
#define P_BLNDMA_SOURCEB_BACKGROUND         (UV32*)0x880D0048
#define P_BLNDMA_DESTINATION_BA             (UV32*)0x880D0050
#define P_BLNDMA_DESTINATION_OA             (UV32*)0x880D0054
#define P_BLNDMA_DESTINATION_BACKGROUND     (UV32*)0x880D0058
//**************************************************************//
//                               I2S                            //
//**************************************************************//
#define P_I2S_CLK_CONF                      (UV32*)0x8821008C
#define P_I2S_CLK_SEL                       (UV32*)0x88210090
#define P_I2S_INTERFACE_SEL                 (UV32*)0x88200004
#define P_I2S_MODE_CTRL                     (UV32*)0x88140000
#define P_I2S_MASTER_SETUP                  (UV32*)0x88140004
#define P_I2S_INT_STATUS                    (UV32*)0x88140008
#define P_I2S_FIFO_STATUS                   (UV32*)0x8814000C
#define P_I2S_RX_DATA                       (UV32*)0x88140010
//**************************************************************//
//                               USB                            //
//**************************************************************//
#define P_USB_CLK_CONF                      (UV32*)0x88210064
#define P_USB_WAKEUP_CTRL                   (UV32*)0x882100F4
#define P_USB_WAKEUP_STATUS                 (UV32*)0x88210110
#define P_USB_INTERFACE_SEL                 (UV32*)0x8820000C
#define P_USB_GPIO_SETUP                    (UV32*)0x8820003C
#define P_USB_GPIO_INPUT                    (UV32*)0x88200074
#define P_USB_GPIO_INT                      (UV32*)0x882000A0
//**************************************************************//
//                           USB Device                         //
//**************************************************************//
#define P_USBD_MODE_CTRL1                   (UV32*)0x881B00C0
#define P_USBD_MODE_CTRL2                   (UV32*)0x881B00C4
#define P_USBD_MODE_CTRL3                   (UV32*)0x881B015C
#define P_USBD_DMAINT_STATUS                (UV32*)0x881B0164
#define P_USBD_POWER_CTRL                   (UV32*)0x881B00C8
#define P_USBD_EP0_DATA                     (UV32*)0x881B00CC
#define P_USBD_BULKIN_DATA                  (UV32*)0x881B00D0
#define P_USBD_BULKOUT_DATA                 (UV32*)0x881B00D4
#define P_USBD_INTIN_DATA                   (UV32*)0x881B00D8
#define P_USBD_NULL_PACKET                  (UV32*)0x881B0160
#define P_USBD_EP_EVENT                     (UV32*)0x881B00DC
#define P_USBD_INT_STATUS1                  (UV32*)0x881B00E0
#define P_USBD_INT_CTRL                     (UV32*)0x881B00E4
#define P_USBD_INT_STATUS2                  (UV32*)0x881B00E8
#define P_USBD_COMMANDINT_CTRL              (UV32*)0x881B00EC
#define P_USBD_COMMANDINT_STATUS            (UV32*)0x881B00F0
#define P_USBD_EP_AUTOSET                   (UV32*)0x881B00F4
#define P_USBD_EP_SETSTALL                  (UV32*)0x881B00F8
#define P_USBD_EP_BUFFERCLR                 (UV32*)0x881B00FC
#define P_USBD_EP_EVENTCLR                  (UV32*)0x881B0100
#define P_USBD_EP0_WRITECOUNT               (UV32*)0x881B0104
#define P_USBD_BULKOUT_WRITECOUNT           (UV32*)0x881B0108
#define P_USBD_EP0_BUFFERSEL                (UV32*)0x881B010C
#define P_USBD_BULKIN_BUFFERSEL             (UV32*)0x881B0110
#define P_USBD_BULKOUT_BUFFERSEL            (UV32*)0x881B0114
#define P_USBD_EP0_BMREQUESTTYPE            (UV32*)0x881B0118
#define P_USBD_EP0_BREQUEST                 (UV32*)0x881B011C
#define P_USBD_EP0_WVALUE                   (UV32*)0x881B0120
#define P_USBD_EP0_WINDEX                   (UV32*)0x881B0124
#define P_USBD_EP0_WLENGTH                  (UV32*)0x881B0128
#define P_USBD_DMA_WRITECOUNT               (UV32*)0x881B0140
#define P_USBD_DMA_ACKCOUNT                 (UV32*)0x881B0144
#define P_USBD_EP_STALL                     (UV32*)0x881B0150
//**************************************************************//
//                           USB Host                           //
//**************************************************************//
#define P_USBH_MODE_CTRL                    (UV32*)0x881C0000
#define P_USBH_TIMING_SETUP                 (UV32*)0x881C0004
#define P_USBH_TXRX_DATA                    (UV32*)0x881C0008
#define P_USBH_TRANSFER_MODE                (UV32*)0x881C000C
#define P_USBH_DEVICE_ADDR                  (UV32*)0x881C0010
#define P_USBH_DEVICE_EP                    (UV32*)0x881C0014
#define P_USBH_TX_COUNT                     (UV32*)0x881C0018
#define P_USBH_RX_COUNT                     (UV32*)0x881C001C
#define P_USBH_FIFOIN_POINTER               (UV32*)0x881C0020
#define P_USBH_FIFOOUT_POINTER              (UV32*)0x881C0024
#define P_USBH_AUTOIN_COUNT                 (UV32*)0x881C0028
#define P_USBH_AUTOOUT_COUNT                (UV32*)0x881C002C
#define P_USBH_AUTO_TRANSFER                (UV32*)0x881C0030
#define P_USBH_MODE_STATUS                  (UV32*)0x881C0034
#define P_USBH_INT_STATUS                   (UV32*)0x881C0038
#define P_USBH_INT_CTRL                     (UV32*)0x881C003C
#define P_USBH_SOFT_RESET                   (UV32*)0x881C0044
#define P_USBH_INACK_COUNT                  (UV32*)0x881C005C
#define P_USBH_OUTACK_COUNT                 (UV32*)0x881C0060
#define P_USBH_RESETACK_COUNT               (UV32*)0x881C0064
#define P_USBH_D_READBACK                   (UV32*)0x881C006C
//**************************************************************//
//                            MPEG4                             //
//**************************************************************//
#define P_MPEG4_CLK_CONF                    (UV32*)0x882100EC
#define P_MPEG4_CLK_SEL                     (UV32*)0x882100F0
#define P_MPEG4_SOFT_RESET                  (UV32*)0x88220080
#define P_MPEG4_WIDTH_LOW                   (UV32*)0x88220000
#define P_MPEG4_WIDTH_HIGH                  (UV32*)0x88220004
#define P_MPEG4_HEIGHT_LOW                  (UV32*)0x88220008
#define P_MPEG4_HEIGHT_HIGH                 (UV32*)0x8822000C
#define P_MPEG4_HOROFFSET_LOW               (UV32*)0x88220010
#define P_MPEG4_HOROFFSET_HIGH              (UV32*)0x88220014
#define P_MPEG4_VEROFFSET_LOW               (UV32*)0x88220018
#define P_MPEG4_VEROFFSET_HIGH              (UV32*)0x8822001C
#define P_MPEG4_DECWIDTH_LOW                (UV32*)0x88220100
#define P_MPEG4_DECWIDTH_HIGH               (UV32*)0x88220104
#define P_MPEG4_DECHEIGHT_LOW               (UV32*)0x88220108
#define P_MPEG4_DECHEIGHT_HIGH              (UV32*)0x8822010C
#define P_MPEG4_FRAMEBUFFER_HSIZE           (UV32*)0x88070090
#define P_MPEG4_RAWBUFFER_SA1               (UV32*)0x88070070
#define P_MPEG4_RAWBUFFER_SA2               (UV32*)0x88070074
#define P_MPEG4_RAWBUFFER_SA3               (UV32*)0x88070078
#define P_MPEG4_RAWBUFFER_SEL               (UV32*)0x88090044
#define P_MPEG4_WRITEBUFFER_SA1             (UV32*)0x8807007C
#define P_MPEG4_WRITEBUFFER_SA2             (UV32*)0x88070080
#define P_MPEG4_WRITEBUFFER_SA3             (UV32*)0x88070084
#define P_MPEG4_WRITEBUFFER_SEL             (UV32*)0x88090048
#define P_MPEG4_REFBUFFER_SEL               (UV32*)0x88090050
#define P_MPEG4_VLCBUFFER_SA1               (UV32*)0x88070088
#define P_MPEG4_VLCBUFFER_SA2               (UV32*)0x8807008C
#define P_MPEG4_VLCBUFFER_SEL               (UV32*)0x88090054
#define P_MPEG4_VLCOFFSET_SALOW             (UV32*)0x88220020
#define P_MPEG4_VLCOFFSET_SAMID             (UV32*)0x88220024
#define P_MPEG4_VLCOFFSET_SAHIGH            (UV32*)0x88220028
#define P_MPEG4_DECVLCOFFSET_SALOW          (UV32*)0x88220110
#define P_MPEG4_DECVLCOFFSET_SAMID          (UV32*)0x88220114
#define P_MPEG4_DECVLCOFFSET_SAHIGH         (UV32*)0x88220118
#define P_MPEG4_YUV_SEL                     (UV32*)0x8822004C
#define P_MPEG4_MODE_CTRL1                  (UV32*)0x88220050
#define P_MPEG4_MODE_CTRL2                  (UV32*)0x88220054
#define P_MPEG4_MODE_CTRL3                  (UV32*)0x88220064
#define P_MPEG4_COMPRESS_CTRL               (UV32*)0x882200A0
#define P_MPEG4_SRAM_EN                     (UV32*)0x882206F8
#define P_MPEG4_TSRAM_CTRL                  (UV32*)0x882207E0
#define P_MPEG4_BUFFER_CTRL                 (UV32*)0x88220084
#define P_MPEG4_YUV_MODE                    (UV32*)0x882200C8
#define P_MPEG4_INT_CTRL                    (UV32*)0x882200D0
#define P_MPEG4_INT_STATUS                  (UV32*)0x882200D4
#define P_MPEG4_MATCHCODE_CTRL              (UV32*)0x88220648
#define P_MPEG4_MATCH_CODE1                 (UV32*)0x8822064C
#define P_MPEG4_MATCH_CODE2                 (UV32*)0x88220650
#define P_MPEG4_MATCH_CODE3                 (UV32*)0x88220654
#define P_MPEG4_MATCH_CODE4                 (UV32*)0x88220658
#define P_MPEG4_MATCHCODE_OFFSET            (UV32*)0x8822065C
#define P_MPEG4_H263_CTRL                   (UV32*)0x882207C8
#define P_MPEG4_H263_STRUCTURE              (UV32*)0x882207CC
#define P_MPEG4_IFRAME_QSCALE               (UV32*)0x88220640
#define P_MPEG4_PFRAME_QSCALE               (UV32*)0x88220644
#define P_MPEG4_VLCSIZE_LOW                 (UV32*)0x882206C8
#define P_MPEG4_VLCSIZE_MID                 (UV32*)0x882206CC
#define P_MPEG4_VLCSIZE_HIGH                (UV32*)0x882206D0
#define P_MPEG4_HOR_SCALE                   (UV32*)0x88220058
#define P_MPEG4_VER_SCALE                   (UV32*)0x8822005C
#define P_MPEG4_PFRAME_NUMBER               (UV32*)0x88220060
#define P_MPEG4_FRAME_MODE                  (UV32*)0x88220088
#define P_MPEG4_PFRAME_MONITER              (UV32*)0x882200A4
#define P_MPEG4_QTABLE1_START               (UV32*)0x88220400
#define P_MPEG4_QTABLE1_END                 (UV32*)0x882204FC
#define P_MPEG4_QTABLE2_START               (UV32*)0x88220500
#define P_MPEG4_QTABLE2_END                 (UV32*)0x882205FC
#define P_MPEG4_QTABLE_INDEX                (UV32*)0x88220600
#define P_MPEG4_QTABLE_CTRL                 (UV32*)0x88220604
#define P_MPEG4_QTABLE_SRAM                 (UV32*)0x88220608
#define P_MPEG4_JFIF_COMPATIBLE             (UV32*)0x88220610
#define P_MPEG4_TRUNCATE_CTRL               (UV32*)0x88220614
#define P_MPEG4_VLC_BIT                     (UV32*)0x88220618
#define P_MPEG4_JFIF_END                    (UV32*)0x8822061C
#define P_MPEG4_RESETMCU_LOW                (UV32*)0x88220620
#define P_MPEG4_RESETMCU_HIGH               (UV32*)0x88220624
#define P_MPEG4_VOPTIMEINC_SEL              (UV32*)0x88220660
#define P_MPEG4_MS_COUNT                    (UV32*)0x88220664
#define P_MPEG4_MS_EXTRAEN                  (UV32*)0x88220668
#define P_MPEG4_VOPTIMEINC_RESLOW           (UV32*)0x88220680
#define P_MPEG4_VOPTIMEINC_RESHIGH          (UV32*)0x88220684
#define P_MPEG4_VOPTIMEINC_UNITLOW          (UV32*)0x88220688
#define P_MPEG4_VOPTIMEINC_UNITHIGH         (UV32*)0x8822068C
#define P_MPEG4_VOPTIMEINC_LENGTH           (UV32*)0x88220690
#define P_MPEG4_HUFFMAN_START               (UV32*)0x88220800
#define P_MPEG4_HUFFMAN_END                 (UV32*)0x882208FC
#define P_MPEG4_LUMDCCODE_START             (UV32*)0x88220800
#define P_MPEG4_LUMDCCODE_END               (UV32*)0x8822085C
#define P_MPEG4_LUMOFFSET_SA                (UV32*)0x88220860
#define P_MPEG4_LUMOFFSET_EA                (UV32*)0x8822087C
#define P_MPEG4_LUMHUFFMANTABLE_START       (UV32*)0x88220880
#define P_MPEG4_LUMHUFFMANTABLE_END         (UV32*)0x8822089C
#define P_MPEG4_LUMACHUFFMANTABLE_START     (UV32*)0x88220980
#define P_MPEG4_LUMACHUFFMANTABLE_END       (UV32*)0x882209DC
#define P_MPEG4_LUMACHUFFMANOFFSET_SA       (UV32*)0x882209E0
#define P_MPEG4_LUMACHUFFMANOFFSET_EA       (UV32*)0x88220A34
#define P_MPEG4_CHROMDCCODE_START           (UV32*)0x882208C0
#define P_MPEG4_CHROMDCCODE_END             (UV32*)0x8822091C
#define P_MPEG4_CHROMOFFSET_SA              (UV32*)0x88220920
#define P_MPEG4_CHROMOFFSET_EA              (UV32*)0x8822093C
#define P_MPEG4_CHROMHUFFMANTABLE_START     (UV32*)0x88220940
#define P_MPEG4_CHROMHUFFMANTABLE_END       (UV32*)0x8822095C
#define P_MPEG4_CHROMACHUFFMANTABLE_START   (UV32*)0x88220A40
#define P_MPEG4_CHROMACHUFFMANTABLE_END     (UV32*)0x88220A90
#define P_MPEG4_CHROMACHUFFMANOFFSET_SA     (UV32*)0x88220AA0
#define P_MPEG4_CHROMACHUFFMANOFFSET_EA     (UV32*)0x88220AF4
//**************************************************************//
//                            DRAM                              //
//**************************************************************//
#define P_DRAM_INTERFACE_SEL                (UV32*)0x88200008
#define P_DRAM_GPIO_SETUP                   (UV32*)0x88200050
#define P_DRAM_GPIO_INPUT                   (UV32*)0x88200070

#endif  //_SPG290_REGISTERS_H
