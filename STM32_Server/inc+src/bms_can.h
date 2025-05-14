#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// DBC file version
#define VER_BMS_CAN_MAJ (0U)
#define VER_BMS_CAN_MIN (0U)

// include current dbc-driver compilation config
#include "bms_can-config.h"

#ifdef BMS_CAN_USE_DIAG_MONITORS
// This file must define:
// base monitor struct
// function signature for HASH calculation: (@GetFrameHash)
// function signature for getting system tick value: (@GetSystemTick)
#include "canmonitorutil.h"

#endif // BMS_CAN_USE_DIAG_MONITORS


// def @APP_response CAN Message (256  0x100)
#define APP_response_IDE (0U)
#define APP_response_DLC (8U)
#define APP_response_CANID (0x100)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

#else

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} APP_response_t;

// def @APP_Tester_Present CAN Message (257  0x101)
#define APP_Tester_Present_IDE (0U)
#define APP_Tester_Present_DLC (2U)
#define APP_Tester_Present_CANID (0x101)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t APP_tester_debug;                  //      Bits= 8

  uint8_t APP_tester_update;                 //      Bits= 8

#else

  uint8_t APP_tester_debug;                  //      Bits= 8

  uint8_t APP_tester_update;                 //      Bits= 8

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} APP_Tester_Present_t;

// def @APP_State_Machine_Req CAN Message (258  0x102)
#define APP_State_Machine_Req_IDE (0U)
#define APP_State_Machine_Req_DLC (1U)
#define APP_State_Machine_Req_CANID (0x102)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t APP_goto_state : 3;                //      Bits= 3

#else

  uint8_t APP_goto_state;                    //      Bits= 3

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} APP_State_Machine_Req_t;

// def @APP_flag_error CAN Message (272  0x110)
#define APP_flag_error_IDE (0U)
#define APP_flag_error_DLC (8U)
#define APP_flag_error_CANID (0x110)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t APP_flag_undervolt : 1;            //      Bits= 1

  uint8_t APP_flag_overvolt : 1;             //      Bits= 1

  uint8_t APP_flag_scd_error : 1;            //      Bits= 1

  uint8_t APP_flag_highCurrent : 1;          //      Bits= 1

  uint8_t APP_flag_bat_lowTemp : 1;          //      Bits= 1

  uint8_t APP_flag_bat_highTemp : 1;         //      Bits= 1

  uint8_t APP_flag_bms_lowTemp : 1;          //      Bits= 1

  uint8_t APP_flag_bms_highTemp : 1;         //      Bits= 1

#else

  uint8_t APP_flag_undervolt;                //      Bits= 1

  uint8_t APP_flag_overvolt;                 //      Bits= 1

  uint8_t APP_flag_scd_error;                //      Bits= 1

  uint8_t APP_flag_highCurrent;              //      Bits= 1

  uint8_t APP_flag_bat_lowTemp;              //      Bits= 1

  uint8_t APP_flag_bat_highTemp;             //      Bits= 1

  uint8_t APP_flag_bms_lowTemp;              //      Bits= 1

  uint8_t APP_flag_bms_highTemp;             //      Bits= 1

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} APP_flag_error_t;

// def @APP_Version CAN Message (273  0x111)
#define APP_Version_IDE (0U)
#define APP_Version_DLC (5U)
#define APP_Version_CANID (0x111)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t APP_version_major;                 //      Bits= 8

  uint8_t APP_version_minor;                 //      Bits= 8

  uint16_t APP_version_revision;             //      Bits=16

  uint8_t APP_status;                        //      Bits= 8

#else

  uint8_t APP_version_major;                 //      Bits= 8

  uint8_t APP_version_minor;                 //      Bits= 8

  uint16_t APP_version_revision;             //      Bits=16

  uint8_t APP_status;                        //      Bits= 8

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} APP_Version_t;

// def @APP_SYS_Comm_Check CAN Message (288  0x120)
#define APP_SYS_Comm_Check_IDE (0U)
#define APP_SYS_Comm_Check_DLC (3U)
#define APP_SYS_Comm_Check_CANID (0x120)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t APP_Spi_Check : 1;                 //      Bits= 1

  uint8_t APP_I2c_Check : 1;                 //      Bits= 1

  uint8_t APP_Can_Check : 1;                 //      Bits= 1

#else

  uint8_t APP_Spi_Check;                     //      Bits= 1

  uint8_t APP_I2c_Check;                     //      Bits= 1

  uint8_t APP_Can_Check;                     //      Bits= 1

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} APP_SYS_Comm_Check_t;

// def @APP_SYS_Peripheral_Check CAN Message (289  0x121)
#define APP_SYS_Peripheral_Check_IDE (0U)
#define APP_SYS_Peripheral_Check_DLC (7U)
#define APP_SYS_Peripheral_Check_CANID (0x121)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t APP_Afe_Check : 1;                 //      Bits= 1

  uint8_t APP_Gauge_Check : 1;               //      Bits= 1

  uint8_t APP_Eeprom_Check : 1;              //      Bits= 1

  uint8_t APP_Bms_Check : 1;                 //      Bits= 1

  uint8_t APP_Ble_Can_Check : 1;             //      Bits= 1

  uint8_t APP_Fcu_Can_Check : 1;             //      Bits= 1

  uint8_t APP_temp_sens_check : 1;           //      Bits= 1

#else

  uint8_t APP_Afe_Check;                     //      Bits= 1

  uint8_t APP_Gauge_Check;                   //      Bits= 1

  uint8_t APP_Eeprom_Check;                  //      Bits= 1

  uint8_t APP_Bms_Check;                     //      Bits= 1

  uint8_t APP_Ble_Can_Check;                 //      Bits= 1

  uint8_t APP_Fcu_Can_Check;                 //      Bits= 1

  uint8_t APP_temp_sens_check;               //      Bits= 1

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} APP_SYS_Peripheral_Check_t;

// def @APP_State CAN Message (304  0x130)
#define APP_State_IDE (0U)
#define APP_State_DLC (1U)
#define APP_State_CANID (0x130)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t APP_Current_State : 3;             //      Bits= 3

#else

  uint8_t APP_Current_State;                 //      Bits= 3

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} APP_State_t;

// def @BMS_Charger_Config CAN Message (881  0x371)
#define BMS_Charger_Config_IDE (0U)
#define BMS_Charger_Config_DLC (8U)
#define BMS_Charger_Config_CANID (0x371)
// signal: @BAT_gauge_vPack_ro
#define BMS_CAN_BAT_gauge_vPack_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_gauge_vPack_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_gauge_vPack_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t Battery_BMS_Cell_Config;           //      Bits= 8

  uint16_t BMS_ID;                           //      Bits=16

  uint16_t BAT_gauge_vPack_ro;               //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_gauge_vPack_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_Gauge_Design_Cap;             //      Bits=16

  uint8_t BAT_gauge_SoC;                     //      Bits= 8 Unit:'%'

#else

  uint8_t Battery_BMS_Cell_Config;           //      Bits= 8

  uint16_t BMS_ID;                           //      Bits=16

  uint16_t BAT_gauge_vPack_ro;               //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_gauge_vPack_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_Gauge_Design_Cap;             //      Bits=16

  uint8_t BAT_gauge_SoC;                     //      Bits= 8 Unit:'%'

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BMS_Charger_Config_t;

// def @Charge_Current_Profile CAN Message (882  0x372)
#define Charge_Current_Profile_IDE (0U)
#define Charge_Current_Profile_DLC (2U)
#define Charge_Current_Profile_CANID (0x372)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint16_t BAT_BMS_Charge_Current;           //      Bits=16

#else

  uint16_t BAT_BMS_Charge_Current;           //      Bits=16

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} Charge_Current_Profile_t;

// def @Charge_Cell_Config CAN Message (884  0x374)
#define Charge_Cell_Config_IDE (0U)
#define Charge_Cell_Config_DLC (2U)
#define Charge_Cell_Config_CANID (0x374)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t Battery_BMS_Cell_Config;           //      Bits= 8

#else

  uint8_t Battery_BMS_Cell_Config;           //      Bits= 8

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} Charge_Cell_Config_t;

// def @BMS_Fet_On CAN Message (885  0x375)
#define BMS_Fet_On_IDE (0U)
#define BMS_Fet_On_DLC (8U)
#define BMS_Fet_On_CANID (0x375)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t Battery_BMS_Cell_Config;           //      Bits= 8

  uint16_t BMS_ID;                           //      Bits=16

  int8_t BMS_Fet_Command;                    //  [-] Bits= 8

#else

  uint8_t Battery_BMS_Cell_Config;           //      Bits= 8

  uint16_t BMS_ID;                           //      Bits=16

  int8_t BMS_Fet_Command;                    //  [-] Bits= 8

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BMS_Fet_On_t;

// def @BMS_Temp_Sensor_Present CAN Message (2093328 0x1ff110)
#define BMS_Temp_Sensor_Present_IDE (1U)
#define BMS_Temp_Sensor_Present_DLC (7U)
#define BMS_Temp_Sensor_Present_CANID (0x1ff110)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t BMS_ambient_temp_sensor_present : 1;    //      Bits= 1

  uint8_t BMS_Fet_temp_sensor_present : 1;        //      Bits= 1

  uint8_t BMS_ext_adc1_temp_sensor_present : 1;   //      Bits= 1

  uint8_t BMS_ext_adc2_temp_sensor_present : 1;   //      Bits= 1

  uint8_t BMS_afe_ts1_temp_sensor_present : 1;    //      Bits= 1

  uint8_t BMS_afe_ts3_temp_sensor_present : 1;    //      Bits= 1

  uint8_t BMS_gauge_temp_sensor_present : 1;      //      Bits= 1

#else

  uint8_t BMS_ambient_temp_sensor_present;        //      Bits= 1

  uint8_t BMS_Fet_temp_sensor_present;            //      Bits= 1

  uint8_t BMS_ext_adc1_temp_sensor_present;       //      Bits= 1

  uint8_t BMS_ext_adc2_temp_sensor_present;       //      Bits= 1

  uint8_t BMS_afe_ts1_temp_sensor_present;        //      Bits= 1

  uint8_t BMS_afe_ts3_temp_sensor_present;        //      Bits= 1

  uint8_t BMS_gauge_temp_sensor_present;          //      Bits= 1

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BMS_Temp_Sensor_Present_t;

// def @BMS_FAULT_Level CAN Message (2093329 0x1ff111)
#define BMS_FAULT_Level_IDE (1U)
#define BMS_FAULT_Level_DLC (5U)
#define BMS_FAULT_Level_CANID (0x1ff111)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t BMS_fault_lvl0 : 1;                //      Bits= 1

  uint8_t BMS_fault_lvl1 : 1;                //      Bits= 1

  uint8_t BMS_fault_lvl2 : 1;                //      Bits= 1

  uint8_t BMS_fault_lvl3 : 1;                //      Bits= 1

  uint8_t BMS_Fault_none : 1;                //      Bits= 1

#else

  uint8_t BMS_fault_lvl0;                    //      Bits= 1

  uint8_t BMS_fault_lvl1;                    //      Bits= 1

  uint8_t BMS_fault_lvl2;                    //      Bits= 1

  uint8_t BMS_fault_lvl3;                    //      Bits= 1

  uint8_t BMS_Fault_none;                    //      Bits= 1

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BMS_FAULT_Level_t;

// def @BAT_AFE_Fet_Status CAN Message (2093840 0x1ff310)
#define BAT_AFE_Fet_Status_IDE (1U)
#define BAT_AFE_Fet_Status_DLC (6U)
#define BAT_AFE_Fet_Status_CANID (0x1ff310)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t BAT_afe_chg : 1;                   //      Bits= 1

  uint8_t BAT_afe_dsg : 1;                   //      Bits= 1

  uint8_t BAT_afe_pchg : 1;                  //      Bits= 1

  uint8_t BAT_afe_pdsg : 1;                  //      Bits= 1

  uint8_t BAT_afe_dchg : 1;                  //      Bits= 1

  uint8_t BAT_afe_ddsg : 1;                  //      Bits= 1

#else

  uint8_t BAT_afe_chg;                       //      Bits= 1

  uint8_t BAT_afe_dsg;                       //      Bits= 1

  uint8_t BAT_afe_pchg;                      //      Bits= 1

  uint8_t BAT_afe_pdsg;                      //      Bits= 1

  uint8_t BAT_afe_dchg;                      //      Bits= 1

  uint8_t BAT_afe_ddsg;                      //      Bits= 1

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_AFE_Fet_Status_t;

// def @BAT_AFE_Status CAN Message (2094096 0x1ff410)
#define BAT_AFE_Status_IDE (1U)
#define BAT_AFE_Status_DLC (2U)
#define BAT_AFE_Status_CANID (0x1ff410)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t BAT_afe_sleep : 1;                 //      Bits= 1

  uint8_t BAT_afe_deepsleep : 1;             //      Bits= 1

#else

  uint8_t BAT_afe_sleep;                     //      Bits= 1

  uint8_t BAT_afe_deepsleep;                 //      Bits= 1

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_AFE_Status_t;

// def @BAT_GAUGE_Status CAN Message (2094097 0x1ff411)
#define BAT_GAUGE_Status_IDE (1U)
#define BAT_GAUGE_Status_DLC (4U)
#define BAT_GAUGE_Status_CANID (0x1ff411)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t BAT_gauge_fullsleep : 1;           //      Bits= 1

  uint8_t BAT_gauge_sleep : 1;               //      Bits= 1

  uint8_t BAT_gauge_ss : 1;                  //      Bits= 1

  uint8_t BAT_gauge_fas : 1;                 //      Bits= 1

#else

  uint8_t BAT_gauge_fullsleep;               //      Bits= 1

  uint8_t BAT_gauge_sleep;                   //      Bits= 1

  uint8_t BAT_gauge_ss;                      //      Bits= 1

  uint8_t BAT_gauge_fas;                     //      Bits= 1

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_GAUGE_Status_t;

// def @FCU_STATE_REQUEST CAN Message (2094337 0x1ff501)
#define FCU_STATE_REQUEST_IDE (1U)
#define FCU_STATE_REQUEST_DLC (1U)
#define FCU_STATE_REQUEST_CANID (0x1ff501)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t FCU_StateRequest : 3;              //      Bits= 3

#else

  uint8_t FCU_StateRequest;                  //      Bits= 3

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} FCU_STATE_REQUEST_t;

// def @BAT_BMS_Cell_Bal_Status CAN Message (2094352 0x1ff510)
#define BAT_BMS_Cell_Bal_Status_IDE (1U)
#define BAT_BMS_Cell_Bal_Status_DLC (4U)
#define BAT_BMS_Cell_Bal_Status_CANID (0x1ff510)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint16_t BAT_bms_active_cells;             //      Bits=16

  uint16_t BAT_bms_bal_time;                 //      Bits=16 Unit:'Seconds'

#else

  uint16_t BAT_bms_active_cells;             //      Bits=16

  uint16_t BAT_bms_bal_time;                 //      Bits=16 Unit:'Seconds'

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_BMS_Cell_Bal_Status_t;

// def @BAT_BMS_OvrVIEW CAN Message (2094608 0x1ff610)
#define BAT_BMS_OvrVIEW_IDE (1U)
#define BAT_BMS_OvrVIEW_DLC (2U)
#define BAT_BMS_OvrVIEW_CANID (0x1ff610)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t BAT_bms_StateReqSrc;               //      Bits= 8

  uint8_t BAT_bms_PackState;                 //      Bits= 8

#else

  uint8_t BAT_bms_StateReqSrc;               //      Bits= 8

  uint8_t BAT_bms_PackState;                 //      Bits= 8

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_BMS_OvrVIEW_t;

// def @BAT_BMS_ExtTemp CAN Message (2094609 0x1ff611)
#define BAT_BMS_ExtTemp_IDE (1U)
#define BAT_BMS_ExtTemp_DLC (8U)
#define BAT_BMS_ExtTemp_CANID (0x1ff611)
// signal: @BAT_bms_afe_temp1_ro
#define BMS_CAN_BAT_bms_afe_temp1_ro_CovFactor (0.010000)
#define BMS_CAN_BAT_bms_afe_temp1_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.010000)) )
#define BMS_CAN_BAT_bms_afe_temp1_ro_fromS(x) ( (((x) * (0.010000)) + (0.000000)) )
// signal: @BAT_bms_afe_temp2_ro
#define BMS_CAN_BAT_bms_afe_temp2_ro_CovFactor (0.010000)
#define BMS_CAN_BAT_bms_afe_temp2_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.010000)) )
#define BMS_CAN_BAT_bms_afe_temp2_ro_fromS(x) ( (((x) * (0.010000)) + (0.000000)) )

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint16_t BAT_bms_afe_temp1_ro;             //      Bits=16 Factor= 0.010000        Unit:'*C'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_bms_afe_temp1_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_bms_afe_temp2_ro;             //      Bits=16 Factor= 0.010000        Unit:'*C'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_bms_afe_temp2_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  int16_t BAT_bms_ext_temp1;                 //  [-] Bits=16

  int16_t BAT_bms_ext_temp2;                 //  [-] Bits=16

#else

  uint16_t BAT_bms_afe_temp1_ro;             //      Bits=16 Factor= 0.010000        Unit:'*C'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_bms_afe_temp1_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_bms_afe_temp2_ro;             //      Bits=16 Factor= 0.010000        Unit:'*C'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_bms_afe_temp2_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  int16_t BAT_bms_ext_temp1;                 //  [-] Bits=16

  int16_t BAT_bms_ext_temp2;                 //  [-] Bits=16

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_BMS_ExtTemp_t;

// def @BAT_BMS_IntTemp CAN Message (2094610 0x1ff612)
#define BAT_BMS_IntTemp_IDE (1U)
#define BAT_BMS_IntTemp_DLC (4U)
#define BAT_BMS_IntTemp_CANID (0x1ff612)
// signal: @BAT_bms_ambient_temp_ro
#define BMS_CAN_BAT_bms_ambient_temp_ro_CovFactor (0.010000)
#define BMS_CAN_BAT_bms_ambient_temp_ro_toS(x) ( (int16_t) (((x) - (0.000000)) / (0.010000)) )
#define BMS_CAN_BAT_bms_ambient_temp_ro_fromS(x) ( (((x) * (0.010000)) + (0.000000)) )
// signal: @BAT_bms_fets_temp_ro
#define BMS_CAN_BAT_bms_fets_temp_ro_CovFactor (0.010000)
#define BMS_CAN_BAT_bms_fets_temp_ro_toS(x) ( (int16_t) (((x) - (0.000000)) / (0.010000)) )
#define BMS_CAN_BAT_bms_fets_temp_ro_fromS(x) ( (((x) * (0.010000)) + (0.000000)) )

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  int16_t BAT_bms_ambient_temp_ro;           //  [-] Bits=16 Factor= 0.010000        Unit:'*C'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_bms_ambient_temp_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  int16_t BAT_bms_fets_temp_ro;              //  [-] Bits=16 Factor= 0.010000       

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_bms_fets_temp_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#else

  int16_t BAT_bms_ambient_temp_ro;           //  [-] Bits=16 Factor= 0.010000        Unit:'*C'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_bms_ambient_temp_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  int16_t BAT_bms_fets_temp_ro;              //  [-] Bits=16 Factor= 0.010000       

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_bms_fets_temp_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_BMS_IntTemp_t;

// def @BAT_BMS_Charger_Load_Status CAN Message (2094613 0x1ff615)
#define BAT_BMS_Charger_Load_Status_IDE (1U)
#define BAT_BMS_Charger_Load_Status_DLC (2U)
#define BAT_BMS_Charger_Load_Status_CANID (0x1ff615)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t APP_bms_load_detect : 1;           //      Bits= 1

  uint8_t APP_bms_charger_detect : 1;        //      Bits= 1

#else

  uint8_t APP_bms_load_detect;               //      Bits= 1

  uint8_t APP_bms_charger_detect;            //      Bits= 1

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_BMS_Charger_Load_Status_t;

// def @BAT_AFE_vBRICK_A CAN Message (2094864 0x1ff710)
#define BAT_AFE_vBRICK_A_IDE (1U)
#define BAT_AFE_vBRICK_A_DLC (8U)
#define BAT_AFE_vBRICK_A_CANID (0x1ff710)
// signal: @BAT_afe_vBrick01_ro
#define BMS_CAN_BAT_afe_vBrick01_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick01_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick01_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )
// signal: @BAT_afe_vBrick02_ro
#define BMS_CAN_BAT_afe_vBrick02_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick02_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick02_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )
// signal: @BAT_afe_vBrick03_ro
#define BMS_CAN_BAT_afe_vBrick03_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick03_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick03_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )
// signal: @BAT_afe_vBrick04_ro
#define BMS_CAN_BAT_afe_vBrick04_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick04_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick04_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint16_t BAT_afe_vBrick01_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick01_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick02_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick02_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick03_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick03_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick04_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick04_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#else

  uint16_t BAT_afe_vBrick01_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick01_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick02_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick02_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick03_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick03_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick04_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick04_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_AFE_vBRICK_A_t;

// def @BAT_AFE_vBRICK_B CAN Message (2094865 0x1ff711)
#define BAT_AFE_vBRICK_B_IDE (1U)
#define BAT_AFE_vBRICK_B_DLC (8U)
#define BAT_AFE_vBRICK_B_CANID (0x1ff711)
// signal: @BAT_afe_vBrick05_ro
#define BMS_CAN_BAT_afe_vBrick05_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick05_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick05_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )
// signal: @BAT_afe_vBrick06_ro
#define BMS_CAN_BAT_afe_vBrick06_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick06_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick06_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )
// signal: @BAT_afe_vBrick07_ro
#define BMS_CAN_BAT_afe_vBrick07_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick07_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick07_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )
// signal: @BAT_afe_vBrick08_ro
#define BMS_CAN_BAT_afe_vBrick08_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick08_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick08_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint16_t BAT_afe_vBrick05_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick05_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick06_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick06_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick07_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick07_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick08_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick08_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#else

  uint16_t BAT_afe_vBrick05_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick05_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick06_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick06_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick07_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick07_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick08_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick08_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_AFE_vBRICK_B_t;

// def @BAT_AFE_vBRICK_C CAN Message (2094866 0x1ff712)
#define BAT_AFE_vBRICK_C_IDE (1U)
#define BAT_AFE_vBRICK_C_DLC (8U)
#define BAT_AFE_vBRICK_C_CANID (0x1ff712)
// signal: @BAT_afe_vBrick09_ro
#define BMS_CAN_BAT_afe_vBrick09_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick09_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick09_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )
// signal: @BAT_afe_vBrick10_ro
#define BMS_CAN_BAT_afe_vBrick10_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick10_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick10_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )
// signal: @BAT_afe_vBrick11_ro
#define BMS_CAN_BAT_afe_vBrick11_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick11_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick11_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )
// signal: @BAT_afe_vBrick12_ro
#define BMS_CAN_BAT_afe_vBrick12_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick12_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick12_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint16_t BAT_afe_vBrick09_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick09_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick10_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick10_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick11_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick11_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick12_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick12_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#else

  uint16_t BAT_afe_vBrick09_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick09_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick10_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick10_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick11_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick11_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick12_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick12_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_AFE_vBRICK_C_t;

// def @BAT_AFE_vBRICK_D CAN Message (2094867 0x1ff713)
#define BAT_AFE_vBRICK_D_IDE (1U)
#define BAT_AFE_vBRICK_D_DLC (8U)
#define BAT_AFE_vBRICK_D_CANID (0x1ff713)
// signal: @BAT_afe_vBrick13_ro
#define BMS_CAN_BAT_afe_vBrick13_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick13_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick13_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )
// signal: @BAT_afe_vBrick14_ro
#define BMS_CAN_BAT_afe_vBrick14_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick14_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick14_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )
// signal: @BAT_afe_vBrick15_ro
#define BMS_CAN_BAT_afe_vBrick15_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick15_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick15_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )
// signal: @BAT_afe_vBrick16_ro
#define BMS_CAN_BAT_afe_vBrick16_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_afe_vBrick16_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_afe_vBrick16_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint16_t BAT_afe_vBrick13_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick13_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick14_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick14_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick15_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick15_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick16_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick16_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#else

  uint16_t BAT_afe_vBrick13_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick13_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick14_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick14_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick15_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick15_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vBrick16_ro;              //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vBrick16_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_AFE_vBRICK_D_t;

// def @BAT_AFE_Current CAN Message (2094869 0x1ff715)
#define BAT_AFE_Current_IDE (1U)
#define BAT_AFE_Current_DLC (4U)
#define BAT_AFE_Current_CANID (0x1ff715)
// signal: @BAT_afe_CC2_current_ro
#define BMS_CAN_BAT_afe_CC2_current_ro_CovFactor (0.010000)
#define BMS_CAN_BAT_afe_CC2_current_ro_toS(x) ( (int16_t) (((x) - (0.000000)) / (0.010000)) )
#define BMS_CAN_BAT_afe_CC2_current_ro_fromS(x) ( (((x) * (0.010000)) + (0.000000)) )
// signal: @BAT_afe_CC3_current_ro
#define BMS_CAN_BAT_afe_CC3_current_ro_CovFactor (0.010000)
#define BMS_CAN_BAT_afe_CC3_current_ro_toS(x) ( (int16_t) (((x) - (0.000000)) / (0.010000)) )
#define BMS_CAN_BAT_afe_CC3_current_ro_fromS(x) ( (((x) * (0.010000)) + (0.000000)) )

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  int16_t BAT_afe_CC2_current_ro;            //  [-] Bits=16 Factor= 0.010000        Unit:'A'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_CC2_current_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  int16_t BAT_afe_CC3_current_ro;            //  [-] Bits=16 Factor= 0.010000        Unit:'A'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_CC3_current_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#else

  int16_t BAT_afe_CC2_current_ro;            //  [-] Bits=16 Factor= 0.010000        Unit:'A'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_CC2_current_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  int16_t BAT_afe_CC3_current_ro;            //  [-] Bits=16 Factor= 0.010000        Unit:'A'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_CC3_current_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_AFE_Current_t;

// def @BAT_GAUGE_OvrVIEW CAN Message (2095120 0x1ff810)
#define BAT_GAUGE_OvrVIEW_IDE (1U)
#define BAT_GAUGE_OvrVIEW_DLC (6U)
#define BAT_GAUGE_OvrVIEW_CANID (0x1ff810)
// signal: @BAT_gauge_remainingCap_ro
#define BMS_CAN_BAT_gauge_remainingCap_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_gauge_remainingCap_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_gauge_remainingCap_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint8_t BAT_gauge_SoC;                     //      Bits= 8 Unit:'%'

  uint8_t BAT_gaige_SoH;                     //      Bits= 8 Unit:'%'

  uint16_t BAT_gauge_cycleCount;             //      Bits=16 Unit:'Cycles'

  uint16_t BAT_gauge_remainingCap_ro;        //      Bits=16 Factor= 0.001000        Unit:'AH'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_gauge_remainingCap_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#else

  uint8_t BAT_gauge_SoC;                     //      Bits= 8 Unit:'%'

  uint8_t BAT_gaige_SoH;                     //      Bits= 8 Unit:'%'

  uint16_t BAT_gauge_cycleCount;             //      Bits=16 Unit:'Cycles'

  uint16_t BAT_gauge_remainingCap_ro;        //      Bits=16 Factor= 0.001000        Unit:'AH'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_gauge_remainingCap_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_GAUGE_OvrVIEW_t;

// def @BAT_GAUGE_ViT CAN Message (2095136 0x1ff820)
#define BAT_GAUGE_ViT_IDE (1U)
#define BAT_GAUGE_ViT_DLC (6U)
#define BAT_GAUGE_ViT_CANID (0x1ff820)
// signal: @BAT_gauge_vPack_ro
#define BMS_CAN_BAT_gauge_vPack_ro_CovFactor (0.001000)
#define BMS_CAN_BAT_gauge_vPack_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.001000)) )
#define BMS_CAN_BAT_gauge_vPack_ro_fromS(x) ( (((x) * (0.001000)) + (0.000000)) )
// signal: @BAT_gauge_iPack_ro
#define BMS_CAN_BAT_gauge_iPack_ro_CovFactor (0.010000)
#define BMS_CAN_BAT_gauge_iPack_ro_toS(x) ( (int16_t) (((x) - (0.000000)) / (0.010000)) )
#define BMS_CAN_BAT_gauge_iPack_ro_fromS(x) ( (((x) * (0.010000)) + (0.000000)) )
// signal: @BAT_gauge_tPack_ro
#define BMS_CAN_BAT_gauge_tPack_ro_CovFactor (0.010000)
#define BMS_CAN_BAT_gauge_tPack_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.010000)) )
#define BMS_CAN_BAT_gauge_tPack_ro_fromS(x) ( (((x) * (0.010000)) + (0.000000)) )

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint16_t BAT_gauge_vPack_ro;               //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_gauge_vPack_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  int16_t BAT_gauge_iPack_ro;                //  [-] Bits=16 Factor= 0.010000        Unit:'A'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_gauge_iPack_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_gauge_tPack_ro;               //      Bits=16 Factor= 0.010000        Unit:'*C'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_gauge_tPack_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#else

  uint16_t BAT_gauge_vPack_ro;               //      Bits=16 Factor= 0.001000        Unit:'Volts'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_gauge_vPack_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  int16_t BAT_gauge_iPack_ro;                //  [-] Bits=16 Factor= 0.010000        Unit:'A'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_gauge_iPack_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_gauge_tPack_ro;               //      Bits=16 Factor= 0.010000        Unit:'*C'

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_gauge_tPack_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_GAUGE_ViT_t;

// def @BAT_GAUGE_Cap CAN Message (2095152 0x1ff830)
#define BAT_GAUGE_Cap_IDE (1U)
#define BAT_GAUGE_Cap_DLC (6U)
#define BAT_GAUGE_Cap_CANID (0x1ff830)

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint16_t BAT_Gauge_DSG_Time;               //      Bits=16

  uint16_t BAT_Gauge_CHG_Time;               //      Bits=16

  uint16_t BAT_Gauge_Design_Cap;             //      Bits=16

#else

  uint16_t BAT_Gauge_DSG_Time;               //      Bits=16

  uint16_t BAT_Gauge_CHG_Time;               //      Bits=16

  uint16_t BAT_Gauge_Design_Cap;             //      Bits=16

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_GAUGE_Cap_t;

// def @BAT_AFE_Debug_Data CAN Message (2095376 0x1ff910)
#define BAT_AFE_Debug_Data_IDE (1U)
#define BAT_AFE_Debug_Data_DLC (6U)
#define BAT_AFE_Debug_Data_CANID (0x1ff910)
// signal: @BAT_afe_vStack_ro
#define BMS_CAN_BAT_afe_vStack_ro_CovFactor (0.010000)
#define BMS_CAN_BAT_afe_vStack_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.010000)) )
#define BMS_CAN_BAT_afe_vStack_ro_fromS(x) ( (((x) * (0.010000)) + (0.000000)) )
// signal: @BAT_afe_vPack_ro
#define BMS_CAN_BAT_afe_vPack_ro_CovFactor (0.010000)
#define BMS_CAN_BAT_afe_vPack_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.010000)) )
#define BMS_CAN_BAT_afe_vPack_ro_fromS(x) ( (((x) * (0.010000)) + (0.000000)) )
// signal: @BAT_afe_vLdPin_ro
#define BMS_CAN_BAT_afe_vLdPin_ro_CovFactor (0.010000)
#define BMS_CAN_BAT_afe_vLdPin_ro_toS(x) ( (uint16_t) (((x) - (0.000000)) / (0.010000)) )
#define BMS_CAN_BAT_afe_vLdPin_ro_fromS(x) ( (((x) * (0.010000)) + (0.000000)) )

typedef struct
{
#ifdef BMS_CAN_USE_BITS_SIGNAL

  uint16_t BAT_afe_vStack_ro;                //      Bits=16 Factor= 0.010000       

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vStack_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vPack_ro;                 //      Bits=16 Factor= 0.010000       

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vPack_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vLdPin_ro;                //      Bits=16 Factor= 0.010000       

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vLdPin_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#else

  uint16_t BAT_afe_vStack_ro;                //      Bits=16 Factor= 0.010000       

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vStack_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vPack_ro;                 //      Bits=16 Factor= 0.010000       

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vPack_phys;
#endif // BMS_CAN_USE_SIGFLOAT

  uint16_t BAT_afe_vLdPin_ro;                //      Bits=16 Factor= 0.010000       

#ifdef BMS_CAN_USE_SIGFLOAT
  sigfloat_t BAT_afe_vLdPin_phys;
#endif // BMS_CAN_USE_SIGFLOAT

#endif // BMS_CAN_USE_BITS_SIGNAL

#ifdef BMS_CAN_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // BMS_CAN_USE_DIAG_MONITORS

} BAT_AFE_Debug_Data_t;

// Function signatures

uint32_t Unpack_APP_response_bms_can(APP_response_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_APP_response_bms_can(APP_response_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_APP_response_bms_can(APP_response_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_Tester_Present_bms_can(APP_Tester_Present_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_APP_Tester_Present_bms_can(APP_Tester_Present_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_APP_Tester_Present_bms_can(APP_Tester_Present_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_State_Machine_Req_bms_can(APP_State_Machine_Req_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_APP_State_Machine_Req_bms_can(APP_State_Machine_Req_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_APP_State_Machine_Req_bms_can(APP_State_Machine_Req_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_flag_error_bms_can(APP_flag_error_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_APP_flag_error_bms_can(APP_flag_error_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_APP_flag_error_bms_can(APP_flag_error_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_Version_bms_can(APP_Version_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_APP_Version_bms_can(APP_Version_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_APP_Version_bms_can(APP_Version_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_SYS_Comm_Check_bms_can(APP_SYS_Comm_Check_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_APP_SYS_Comm_Check_bms_can(APP_SYS_Comm_Check_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_APP_SYS_Comm_Check_bms_can(APP_SYS_Comm_Check_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_SYS_Peripheral_Check_bms_can(APP_SYS_Peripheral_Check_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_APP_SYS_Peripheral_Check_bms_can(APP_SYS_Peripheral_Check_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_APP_SYS_Peripheral_Check_bms_can(APP_SYS_Peripheral_Check_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_State_bms_can(APP_State_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_APP_State_bms_can(APP_State_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_APP_State_bms_can(APP_State_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BMS_Charger_Config_bms_can(BMS_Charger_Config_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BMS_Charger_Config_bms_can(BMS_Charger_Config_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BMS_Charger_Config_bms_can(BMS_Charger_Config_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_Charge_Current_Profile_bms_can(Charge_Current_Profile_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_Charge_Current_Profile_bms_can(Charge_Current_Profile_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_Charge_Current_Profile_bms_can(Charge_Current_Profile_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_Charge_Cell_Config_bms_can(Charge_Cell_Config_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_Charge_Cell_Config_bms_can(Charge_Cell_Config_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_Charge_Cell_Config_bms_can(Charge_Cell_Config_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BMS_Fet_On_bms_can(BMS_Fet_On_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BMS_Fet_On_bms_can(BMS_Fet_On_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BMS_Fet_On_bms_can(BMS_Fet_On_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BMS_Temp_Sensor_Present_bms_can(BMS_Temp_Sensor_Present_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BMS_Temp_Sensor_Present_bms_can(BMS_Temp_Sensor_Present_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BMS_Temp_Sensor_Present_bms_can(BMS_Temp_Sensor_Present_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BMS_FAULT_Level_bms_can(BMS_FAULT_Level_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BMS_FAULT_Level_bms_can(BMS_FAULT_Level_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BMS_FAULT_Level_bms_can(BMS_FAULT_Level_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_Fet_Status_bms_can(BAT_AFE_Fet_Status_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_AFE_Fet_Status_bms_can(BAT_AFE_Fet_Status_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_AFE_Fet_Status_bms_can(BAT_AFE_Fet_Status_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_Status_bms_can(BAT_AFE_Status_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_AFE_Status_bms_can(BAT_AFE_Status_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_AFE_Status_bms_can(BAT_AFE_Status_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_GAUGE_Status_bms_can(BAT_GAUGE_Status_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_GAUGE_Status_bms_can(BAT_GAUGE_Status_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_GAUGE_Status_bms_can(BAT_GAUGE_Status_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_FCU_STATE_REQUEST_bms_can(FCU_STATE_REQUEST_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_FCU_STATE_REQUEST_bms_can(FCU_STATE_REQUEST_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FCU_STATE_REQUEST_bms_can(FCU_STATE_REQUEST_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_BMS_Cell_Bal_Status_bms_can(BAT_BMS_Cell_Bal_Status_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_BMS_Cell_Bal_Status_bms_can(BAT_BMS_Cell_Bal_Status_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_BMS_Cell_Bal_Status_bms_can(BAT_BMS_Cell_Bal_Status_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_BMS_OvrVIEW_bms_can(BAT_BMS_OvrVIEW_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_BMS_OvrVIEW_bms_can(BAT_BMS_OvrVIEW_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_BMS_OvrVIEW_bms_can(BAT_BMS_OvrVIEW_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_BMS_ExtTemp_bms_can(BAT_BMS_ExtTemp_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_BMS_ExtTemp_bms_can(BAT_BMS_ExtTemp_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_BMS_ExtTemp_bms_can(BAT_BMS_ExtTemp_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_BMS_IntTemp_bms_can(BAT_BMS_IntTemp_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_BMS_IntTemp_bms_can(BAT_BMS_IntTemp_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_BMS_IntTemp_bms_can(BAT_BMS_IntTemp_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_BMS_Charger_Load_Status_bms_can(BAT_BMS_Charger_Load_Status_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_BMS_Charger_Load_Status_bms_can(BAT_BMS_Charger_Load_Status_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_BMS_Charger_Load_Status_bms_can(BAT_BMS_Charger_Load_Status_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_vBRICK_A_bms_can(BAT_AFE_vBRICK_A_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_AFE_vBRICK_A_bms_can(BAT_AFE_vBRICK_A_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_AFE_vBRICK_A_bms_can(BAT_AFE_vBRICK_A_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_vBRICK_B_bms_can(BAT_AFE_vBRICK_B_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_AFE_vBRICK_B_bms_can(BAT_AFE_vBRICK_B_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_AFE_vBRICK_B_bms_can(BAT_AFE_vBRICK_B_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_vBRICK_C_bms_can(BAT_AFE_vBRICK_C_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_AFE_vBRICK_C_bms_can(BAT_AFE_vBRICK_C_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_AFE_vBRICK_C_bms_can(BAT_AFE_vBRICK_C_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_vBRICK_D_bms_can(BAT_AFE_vBRICK_D_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_AFE_vBRICK_D_bms_can(BAT_AFE_vBRICK_D_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_AFE_vBRICK_D_bms_can(BAT_AFE_vBRICK_D_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_Current_bms_can(BAT_AFE_Current_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_AFE_Current_bms_can(BAT_AFE_Current_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_AFE_Current_bms_can(BAT_AFE_Current_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_GAUGE_OvrVIEW_bms_can(BAT_GAUGE_OvrVIEW_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_GAUGE_OvrVIEW_bms_can(BAT_GAUGE_OvrVIEW_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_GAUGE_OvrVIEW_bms_can(BAT_GAUGE_OvrVIEW_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_GAUGE_ViT_bms_can(BAT_GAUGE_ViT_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_GAUGE_ViT_bms_can(BAT_GAUGE_ViT_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_GAUGE_ViT_bms_can(BAT_GAUGE_ViT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_GAUGE_Cap_bms_can(BAT_GAUGE_Cap_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_GAUGE_Cap_bms_can(BAT_GAUGE_Cap_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_GAUGE_Cap_bms_can(BAT_GAUGE_Cap_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_Debug_Data_bms_can(BAT_AFE_Debug_Data_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef BMS_CAN_USE_CANSTRUCT
uint32_t Pack_BAT_AFE_Debug_Data_bms_can(BAT_AFE_Debug_Data_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BAT_AFE_Debug_Data_bms_can(BAT_AFE_Debug_Data_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // BMS_CAN_USE_CANSTRUCT

#ifdef __cplusplus
}
#endif