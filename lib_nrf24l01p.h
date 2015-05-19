#ifndef __FILE_LIB_NRF24L01P_H__
#define __FILE_LIB_NRF24L01P_H__
#include "..\typedef.h"

//**** support functions
extern void hal_nrf24l01p_ce_cs_spi_init();//CE,CS,SPI-3Pin
extern void hal_nrf24l01p_irq_init();
extern void hal_nrf24l01p_ce_Hi();
extern void hal_nrf24l01p_ce_Lo();
extern void hal_nrf24l01p_cs_Hi();
extern void hal_nrf24l01p_cs_Lo();
extern U8 hal_nrf24l01p_spi_rw(U8 x);
extern void delay_more_than_10us();
//****

enum eModeOption{
    PowerDown=0,
    StandbyI,
    TxMode_StandybyI,
    TxMode_StandybyII,
    RxMode
};

enum eRxPipeID{
    Pipe0=0,
    Pipe1,
    Pipe2,
    Pipe3,
    Pipe4,
    Pipe5
};
enum eSwitchOption{
    Disable=0,
    Enable
};
enum ePowerLevel{
    case_Negtive18dBm=0,
    case_Negtive12dBm,
    case_Negtive6dBm,
    case_0dBm
};
enum eSpeedLevel{
    case_1Mbps=0,
    case_2Mbps,
    case_250kbps
};

typedef struct {
    U8 R00_CONFIG;
    U8 R01_EN_AA;
    U8 R02_EN_RXADDR;
    U8 R03_SETUP_AW;
    U8 R04_SETUP_RETR;
    U8 R05_RF_CH;
    U8 R06_RF_SETUP;
    U8 R07_STATUS;
    U8 R08_OBSERVE_TX;
    U8 R09_RPD;
    U8 R0A_RX_ADDR_P0[5];
    U8 R0B_RX_ADDR_P1[5];
    U8 R0C_RX_ADDR_P2;
    U8 R0D_RX_ADDR_P3;
    U8 R0E_RX_ADDR_P4;
    U8 R0F_RX_ADDR_P5;
    U8 R10_TX_ADDR[5];
    U8 R11_RX_PW_P0;
    U8 R12_RX_PW_P1;
    U8 R13_RX_PW_P2;
    U8 R14_RX_PW_P3;
    U8 R15_RX_PW_P4;
    U8 R16_RX_PW_P5;
    U8 R17_FIFO_STATUS;
    U8 R1C_DYNPD;
    U8 R1D_FEATURE;   
}t_nRF24L01p_Regs;

bool nRF24L01p_Init_in_PowerDown();
void nRF24L01p_Set_TxAddr(U8 *addr_5bytes);
void nRF24L01p_Get_TxAddr(U8 *addr_5bytes);
//pipe_num: 0~5
void nRF24L01p_RxPipe(U8 pipe_num, U8 *addr_5bytes, U8 payload_length, enum eSwitchOption pipe_en, enum eSwitchOption AA_en);
void nRF24L01p_cfg_CRC_Disable();
void nRF24L01p_cfg_CRC_One();
void nRF24L01p_cfg_CRC_Two();
void nRF24L01p_cfg_RX_DR_Enable();
void nRF24L01p_cfg_RX_DR_Disable();
void nRF24L01p_cfg_TX_DS_Enable();
void nRF24L01p_cfg_TX_DS_Disable();
void nRF24L01p_cfg_MAX_RT_Enable();
void nRF24L01p_cfg_MAX_RT_Disable();
void nRF24L01p_setup_Power(enum ePowerLevel);
void nRF24L01p_setup_Speed(enum eSpeedLevel);
void nRF24L01p_Mode(enum eModeOption x);
void nRF24L01p_Set_CH(U8 x);
U8   nRF24L01p_Get_CH();

bool nRF24L01p_status_RxFIFO_Empty();
//bool nRF24L01p_status_RxFIFO_Full();
bool nRF24L01p_status_TxFIFO_Empty();
bool nRF24L01p_status_TxFIFO_Full();
bool nRF24L01p_status_RX_DR_Asserted();
bool nRF24L01p_status_TX_DS_Asserted();
bool nRF24L01p_status_MAX_RT_Asserted();
void nRF24L01p_status_RX_DR_Clear();
void nRF24L01p_status_TX_DS_Clear();
void nRF24L01p_status_MAX_RT_Clear();
void nRF24L01p_Get_RxPayload(U8 *buf, U8 len);
void nRF24L01p_Set_TxPayload(U8 *buf, U8 len);
void nRF24L01p_Flush_TX_FIFO();
void nRF24L01p_Flush_RX_FIFO();
//**** Advanced functions. Not necessory.
U8 nRF24L01p_Read(U8 *buf, U8 *pipe_num);
void nRF24L01p_Regs(t_nRF24L01p_Regs *x);
void nRF24L01p_PrintRegs();
/**** code examples
void nRF24L01p_Send(U8 *buf, U8 len){
    nRF24L01p_Mode(StandbyI);
    nRF24L01p_status_TX_DS_Clear();
    nRF24L01p_status_MAX_RT_Clear();
    nRF24L01p_Flush_TX_FIFO();
    nRF24L01p_Set_TxPayload(buf, len);
    nRF24L01p_Mode(TxMode_StandybyI);
    while (nRF24L01p_status_TX_DS_Asserted()==false);
    nRF24L01p_status_TX_DS_Clear();
    nRF24L01p_Mode(RxMode);
}
*/
#endif //__FILE_LIB_NRF24L01P_H__