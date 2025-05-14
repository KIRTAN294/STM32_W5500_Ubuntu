#include "bms_can.h"


#ifdef BMS_CAN_USE_DIAG_MONITORS
// Function prototypes to be called each time CAN frame is unpacked
// FMon function may detect RC, CRC or DLC violation
#include "bms_can-fmon.h"

#endif // BMS_CAN_USE_DIAG_MONITORS


uint32_t Unpack_APP_response_bms_can(APP_response_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < APP_response_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_APP_response_bms_can(&_m->mon1, APP_response_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return APP_response_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_APP_response_bms_can(APP_response_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < APP_response_DLC) && (i < 8); cframe->Data[i++] = 0);


  cframe->MsgId = APP_response_CANID;
  cframe->DLC = APP_response_DLC;
  cframe->IDE = APP_response_IDE;
  return APP_response_CANID;
}

#else

uint32_t Pack_APP_response_bms_can(APP_response_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < APP_response_DLC) && (i < 8); _d[i++] = 0);


  *_len = APP_response_DLC;
  *_ide = APP_response_IDE;
  return APP_response_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_Tester_Present_bms_can(APP_Tester_Present_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->APP_tester_debug = (_d[0] & (0xFFU));
  _m->APP_tester_update = (_d[1] & (0xFFU));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < APP_Tester_Present_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_APP_Tester_Present_bms_can(&_m->mon1, APP_Tester_Present_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return APP_Tester_Present_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_APP_Tester_Present_bms_can(APP_Tester_Present_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < APP_Tester_Present_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->APP_tester_debug & (0xFFU));
  cframe->Data[1] |= (_m->APP_tester_update & (0xFFU));

  cframe->MsgId = APP_Tester_Present_CANID;
  cframe->DLC = APP_Tester_Present_DLC;
  cframe->IDE = APP_Tester_Present_IDE;
  return APP_Tester_Present_CANID;
}

#else

uint32_t Pack_APP_Tester_Present_bms_can(APP_Tester_Present_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < APP_Tester_Present_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->APP_tester_debug & (0xFFU));
  _d[1] |= (_m->APP_tester_update & (0xFFU));

  *_len = APP_Tester_Present_DLC;
  *_ide = APP_Tester_Present_IDE;
  return APP_Tester_Present_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_State_Machine_Req_bms_can(APP_State_Machine_Req_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->APP_goto_state = (_d[0] & (0x07U));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < APP_State_Machine_Req_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_APP_State_Machine_Req_bms_can(&_m->mon1, APP_State_Machine_Req_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return APP_State_Machine_Req_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_APP_State_Machine_Req_bms_can(APP_State_Machine_Req_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < APP_State_Machine_Req_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->APP_goto_state & (0x07U));

  cframe->MsgId = APP_State_Machine_Req_CANID;
  cframe->DLC = APP_State_Machine_Req_DLC;
  cframe->IDE = APP_State_Machine_Req_IDE;
  return APP_State_Machine_Req_CANID;
}

#else

uint32_t Pack_APP_State_Machine_Req_bms_can(APP_State_Machine_Req_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < APP_State_Machine_Req_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->APP_goto_state & (0x07U));

  *_len = APP_State_Machine_Req_DLC;
  *_ide = APP_State_Machine_Req_IDE;
  return APP_State_Machine_Req_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_flag_error_bms_can(APP_flag_error_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->APP_flag_undervolt = (_d[0] & (0x01U));
  _m->APP_flag_overvolt = (_d[1] & (0x01U));
  _m->APP_flag_scd_error = (_d[2] & (0x01U));
  _m->APP_flag_highCurrent = (_d[3] & (0x01U));
  _m->APP_flag_bat_lowTemp = (_d[4] & (0x01U));
  _m->APP_flag_bat_highTemp = (_d[5] & (0x01U));
  _m->APP_flag_bms_lowTemp = (_d[6] & (0x01U));
  _m->APP_flag_bms_highTemp = (_d[7] & (0x01U));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < APP_flag_error_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_APP_flag_error_bms_can(&_m->mon1, APP_flag_error_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return APP_flag_error_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_APP_flag_error_bms_can(APP_flag_error_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < APP_flag_error_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->APP_flag_undervolt & (0x01U));
  cframe->Data[1] |= (_m->APP_flag_overvolt & (0x01U));
  cframe->Data[2] |= (_m->APP_flag_scd_error & (0x01U));
  cframe->Data[3] |= (_m->APP_flag_highCurrent & (0x01U));
  cframe->Data[4] |= (_m->APP_flag_bat_lowTemp & (0x01U));
  cframe->Data[5] |= (_m->APP_flag_bat_highTemp & (0x01U));
  cframe->Data[6] |= (_m->APP_flag_bms_lowTemp & (0x01U));
  cframe->Data[7] |= (_m->APP_flag_bms_highTemp & (0x01U));

  cframe->MsgId = APP_flag_error_CANID;
  cframe->DLC = APP_flag_error_DLC;
  cframe->IDE = APP_flag_error_IDE;
  return APP_flag_error_CANID;
}

#else

uint32_t Pack_APP_flag_error_bms_can(APP_flag_error_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < APP_flag_error_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->APP_flag_undervolt & (0x01U));
  _d[1] |= (_m->APP_flag_overvolt & (0x01U));
  _d[2] |= (_m->APP_flag_scd_error & (0x01U));
  _d[3] |= (_m->APP_flag_highCurrent & (0x01U));
  _d[4] |= (_m->APP_flag_bat_lowTemp & (0x01U));
  _d[5] |= (_m->APP_flag_bat_highTemp & (0x01U));
  _d[6] |= (_m->APP_flag_bms_lowTemp & (0x01U));
  _d[7] |= (_m->APP_flag_bms_highTemp & (0x01U));

  *_len = APP_flag_error_DLC;
  *_ide = APP_flag_error_IDE;
  return APP_flag_error_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_Version_bms_can(APP_Version_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->APP_version_major = (_d[0] & (0xFFU));
  _m->APP_version_minor = (_d[1] & (0xFFU));
  _m->APP_version_revision = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  _m->APP_status = (_d[4] & (0xFFU));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < APP_Version_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_APP_Version_bms_can(&_m->mon1, APP_Version_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return APP_Version_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_APP_Version_bms_can(APP_Version_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < APP_Version_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->APP_version_major & (0xFFU));
  cframe->Data[1] |= (_m->APP_version_minor & (0xFFU));
  cframe->Data[2] |= (_m->APP_version_revision & (0xFFU));
  cframe->Data[3] |= ((_m->APP_version_revision >> 8) & (0xFFU));
  cframe->Data[4] |= (_m->APP_status & (0xFFU));

  cframe->MsgId = APP_Version_CANID;
  cframe->DLC = APP_Version_DLC;
  cframe->IDE = APP_Version_IDE;
  return APP_Version_CANID;
}

#else

uint32_t Pack_APP_Version_bms_can(APP_Version_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < APP_Version_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->APP_version_major & (0xFFU));
  _d[1] |= (_m->APP_version_minor & (0xFFU));
  _d[2] |= (_m->APP_version_revision & (0xFFU));
  _d[3] |= ((_m->APP_version_revision >> 8) & (0xFFU));
  _d[4] |= (_m->APP_status & (0xFFU));

  *_len = APP_Version_DLC;
  *_ide = APP_Version_IDE;
  return APP_Version_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_SYS_Comm_Check_bms_can(APP_SYS_Comm_Check_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->APP_Spi_Check = (_d[0] & (0x01U));
  _m->APP_I2c_Check = (_d[1] & (0x01U));
  _m->APP_Can_Check = (_d[2] & (0x01U));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < APP_SYS_Comm_Check_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_APP_SYS_Comm_Check_bms_can(&_m->mon1, APP_SYS_Comm_Check_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return APP_SYS_Comm_Check_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_APP_SYS_Comm_Check_bms_can(APP_SYS_Comm_Check_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < APP_SYS_Comm_Check_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->APP_Spi_Check & (0x01U));
  cframe->Data[1] |= (_m->APP_I2c_Check & (0x01U));
  cframe->Data[2] |= (_m->APP_Can_Check & (0x01U));

  cframe->MsgId = APP_SYS_Comm_Check_CANID;
  cframe->DLC = APP_SYS_Comm_Check_DLC;
  cframe->IDE = APP_SYS_Comm_Check_IDE;
  return APP_SYS_Comm_Check_CANID;
}

#else

uint32_t Pack_APP_SYS_Comm_Check_bms_can(APP_SYS_Comm_Check_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < APP_SYS_Comm_Check_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->APP_Spi_Check & (0x01U));
  _d[1] |= (_m->APP_I2c_Check & (0x01U));
  _d[2] |= (_m->APP_Can_Check & (0x01U));

  *_len = APP_SYS_Comm_Check_DLC;
  *_ide = APP_SYS_Comm_Check_IDE;
  return APP_SYS_Comm_Check_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_SYS_Peripheral_Check_bms_can(APP_SYS_Peripheral_Check_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->APP_Afe_Check = (_d[0] & (0x01U));
  _m->APP_Gauge_Check = (_d[1] & (0x01U));
  _m->APP_Eeprom_Check = (_d[2] & (0x01U));
  _m->APP_Bms_Check = (_d[3] & (0x01U));
  _m->APP_Ble_Can_Check = (_d[4] & (0x01U));
  _m->APP_Fcu_Can_Check = (_d[5] & (0x01U));
  _m->APP_temp_sens_check = (_d[6] & (0x01U));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < APP_SYS_Peripheral_Check_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_APP_SYS_Peripheral_Check_bms_can(&_m->mon1, APP_SYS_Peripheral_Check_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return APP_SYS_Peripheral_Check_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_APP_SYS_Peripheral_Check_bms_can(APP_SYS_Peripheral_Check_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < APP_SYS_Peripheral_Check_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->APP_Afe_Check & (0x01U));
  cframe->Data[1] |= (_m->APP_Gauge_Check & (0x01U));
  cframe->Data[2] |= (_m->APP_Eeprom_Check & (0x01U));
  cframe->Data[3] |= (_m->APP_Bms_Check & (0x01U));
  cframe->Data[4] |= (_m->APP_Ble_Can_Check & (0x01U));
  cframe->Data[5] |= (_m->APP_Fcu_Can_Check & (0x01U));
  cframe->Data[6] |= (_m->APP_temp_sens_check & (0x01U));

  cframe->MsgId = APP_SYS_Peripheral_Check_CANID;
  cframe->DLC = APP_SYS_Peripheral_Check_DLC;
  cframe->IDE = APP_SYS_Peripheral_Check_IDE;
  return APP_SYS_Peripheral_Check_CANID;
}

#else

uint32_t Pack_APP_SYS_Peripheral_Check_bms_can(APP_SYS_Peripheral_Check_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < APP_SYS_Peripheral_Check_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->APP_Afe_Check & (0x01U));
  _d[1] |= (_m->APP_Gauge_Check & (0x01U));
  _d[2] |= (_m->APP_Eeprom_Check & (0x01U));
  _d[3] |= (_m->APP_Bms_Check & (0x01U));
  _d[4] |= (_m->APP_Ble_Can_Check & (0x01U));
  _d[5] |= (_m->APP_Fcu_Can_Check & (0x01U));
  _d[6] |= (_m->APP_temp_sens_check & (0x01U));

  *_len = APP_SYS_Peripheral_Check_DLC;
  *_ide = APP_SYS_Peripheral_Check_IDE;
  return APP_SYS_Peripheral_Check_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_APP_State_bms_can(APP_State_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->APP_Current_State = (_d[0] & (0x07U));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < APP_State_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_APP_State_bms_can(&_m->mon1, APP_State_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return APP_State_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_APP_State_bms_can(APP_State_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < APP_State_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->APP_Current_State & (0x07U));

  cframe->MsgId = APP_State_CANID;
  cframe->DLC = APP_State_DLC;
  cframe->IDE = APP_State_IDE;
  return APP_State_CANID;
}

#else

uint32_t Pack_APP_State_bms_can(APP_State_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < APP_State_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->APP_Current_State & (0x07U));

  *_len = APP_State_DLC;
  *_ide = APP_State_IDE;
  return APP_State_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BMS_Charger_Config_bms_can(BMS_Charger_Config_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->Battery_BMS_Cell_Config = (_d[0] & (0xFFU));
  _m->BMS_ID = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->BAT_gauge_vPack_ro = ((_d[4] & (0xFFU)) << 8) | (_d[3] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_gauge_vPack_phys = (sigfloat_t)(BMS_CAN_BAT_gauge_vPack_ro_fromS(_m->BAT_gauge_vPack_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_Gauge_Design_Cap = ((_d[6] & (0xFFU)) << 8) | (_d[5] & (0xFFU));
  _m->BAT_gauge_SoC = (_d[7] & (0xFFU));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BMS_Charger_Config_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BMS_Charger_Config_bms_can(&_m->mon1, BMS_Charger_Config_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BMS_Charger_Config_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BMS_Charger_Config_bms_can(BMS_Charger_Config_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BMS_Charger_Config_DLC) && (i < 8); cframe->Data[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_gauge_vPack_ro = BMS_CAN_BAT_gauge_vPack_ro_toS(_m->BAT_gauge_vPack_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  cframe->Data[0] |= (_m->Battery_BMS_Cell_Config & (0xFFU));
  cframe->Data[1] |= (_m->BMS_ID & (0xFFU));
  cframe->Data[2] |= ((_m->BMS_ID >> 8) & (0xFFU));
  cframe->Data[3] |= (_m->BAT_gauge_vPack_ro & (0xFFU));
  cframe->Data[4] |= ((_m->BAT_gauge_vPack_ro >> 8) & (0xFFU));
  cframe->Data[5] |= (_m->BAT_Gauge_Design_Cap & (0xFFU));
  cframe->Data[6] |= ((_m->BAT_Gauge_Design_Cap >> 8) & (0xFFU));
  cframe->Data[7] |= (_m->BAT_gauge_SoC & (0xFFU));

  cframe->MsgId = BMS_Charger_Config_CANID;
  cframe->DLC = BMS_Charger_Config_DLC;
  cframe->IDE = BMS_Charger_Config_IDE;
  return BMS_Charger_Config_CANID;
}

#else

uint32_t Pack_BMS_Charger_Config_bms_can(BMS_Charger_Config_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BMS_Charger_Config_DLC) && (i < 8); _d[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_gauge_vPack_ro = BMS_CAN_BAT_gauge_vPack_ro_toS(_m->BAT_gauge_vPack_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  _d[0] |= (_m->Battery_BMS_Cell_Config & (0xFFU));
  _d[1] |= (_m->BMS_ID & (0xFFU));
  _d[2] |= ((_m->BMS_ID >> 8) & (0xFFU));
  _d[3] |= (_m->BAT_gauge_vPack_ro & (0xFFU));
  _d[4] |= ((_m->BAT_gauge_vPack_ro >> 8) & (0xFFU));
  _d[5] |= (_m->BAT_Gauge_Design_Cap & (0xFFU));
  _d[6] |= ((_m->BAT_Gauge_Design_Cap >> 8) & (0xFFU));
  _d[7] |= (_m->BAT_gauge_SoC & (0xFFU));

  *_len = BMS_Charger_Config_DLC;
  *_ide = BMS_Charger_Config_IDE;
  return BMS_Charger_Config_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_Charge_Current_Profile_bms_can(Charge_Current_Profile_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_BMS_Charge_Current = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < Charge_Current_Profile_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_Charge_Current_Profile_bms_can(&_m->mon1, Charge_Current_Profile_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return Charge_Current_Profile_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_Charge_Current_Profile_bms_can(Charge_Current_Profile_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < Charge_Current_Profile_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->BAT_BMS_Charge_Current & (0xFFU));
  cframe->Data[1] |= ((_m->BAT_BMS_Charge_Current >> 8) & (0xFFU));

  cframe->MsgId = Charge_Current_Profile_CANID;
  cframe->DLC = Charge_Current_Profile_DLC;
  cframe->IDE = Charge_Current_Profile_IDE;
  return Charge_Current_Profile_CANID;
}

#else

uint32_t Pack_Charge_Current_Profile_bms_can(Charge_Current_Profile_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < Charge_Current_Profile_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->BAT_BMS_Charge_Current & (0xFFU));
  _d[1] |= ((_m->BAT_BMS_Charge_Current >> 8) & (0xFFU));

  *_len = Charge_Current_Profile_DLC;
  *_ide = Charge_Current_Profile_IDE;
  return Charge_Current_Profile_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_Charge_Cell_Config_bms_can(Charge_Cell_Config_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->Battery_BMS_Cell_Config = (_d[0] & (0xFFU));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < Charge_Cell_Config_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_Charge_Cell_Config_bms_can(&_m->mon1, Charge_Cell_Config_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return Charge_Cell_Config_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_Charge_Cell_Config_bms_can(Charge_Cell_Config_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < Charge_Cell_Config_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->Battery_BMS_Cell_Config & (0xFFU));

  cframe->MsgId = Charge_Cell_Config_CANID;
  cframe->DLC = Charge_Cell_Config_DLC;
  cframe->IDE = Charge_Cell_Config_IDE;
  return Charge_Cell_Config_CANID;
}

#else

uint32_t Pack_Charge_Cell_Config_bms_can(Charge_Cell_Config_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < Charge_Cell_Config_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->Battery_BMS_Cell_Config & (0xFFU));

  *_len = Charge_Cell_Config_DLC;
  *_ide = Charge_Cell_Config_IDE;
  return Charge_Cell_Config_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BMS_Fet_On_bms_can(BMS_Fet_On_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->Battery_BMS_Cell_Config = (_d[0] & (0xFFU));
  _m->BMS_ID = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->BMS_Fet_Command = (_d[3] & (0xFFU));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BMS_Fet_On_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BMS_Fet_On_bms_can(&_m->mon1, BMS_Fet_On_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BMS_Fet_On_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BMS_Fet_On_bms_can(BMS_Fet_On_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BMS_Fet_On_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->Battery_BMS_Cell_Config & (0xFFU));
  cframe->Data[1] |= (_m->BMS_ID & (0xFFU));
  cframe->Data[2] |= ((_m->BMS_ID >> 8) & (0xFFU));
  cframe->Data[3] |= (_m->BMS_Fet_Command & (0xFFU));

  cframe->MsgId = BMS_Fet_On_CANID;
  cframe->DLC = BMS_Fet_On_DLC;
  cframe->IDE = BMS_Fet_On_IDE;
  return BMS_Fet_On_CANID;
}

#else

uint32_t Pack_BMS_Fet_On_bms_can(BMS_Fet_On_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BMS_Fet_On_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->Battery_BMS_Cell_Config & (0xFFU));
  _d[1] |= (_m->BMS_ID & (0xFFU));
  _d[2] |= ((_m->BMS_ID >> 8) & (0xFFU));
  _d[3] |= (_m->BMS_Fet_Command & (0xFFU));

  *_len = BMS_Fet_On_DLC;
  *_ide = BMS_Fet_On_IDE;
  return BMS_Fet_On_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BMS_Temp_Sensor_Present_bms_can(BMS_Temp_Sensor_Present_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BMS_ambient_temp_sensor_present = (_d[0] & (0x01U));
  _m->BMS_Fet_temp_sensor_present = (_d[1] & (0x01U));
  _m->BMS_ext_adc1_temp_sensor_present = (_d[2] & (0x01U));
  _m->BMS_ext_adc2_temp_sensor_present = (_d[3] & (0x01U));
  _m->BMS_afe_ts1_temp_sensor_present = (_d[4] & (0x01U));
  _m->BMS_afe_ts3_temp_sensor_present = (_d[5] & (0x01U));
  _m->BMS_gauge_temp_sensor_present = (_d[6] & (0x01U));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BMS_Temp_Sensor_Present_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BMS_Temp_Sensor_Present_bms_can(&_m->mon1, BMS_Temp_Sensor_Present_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BMS_Temp_Sensor_Present_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BMS_Temp_Sensor_Present_bms_can(BMS_Temp_Sensor_Present_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BMS_Temp_Sensor_Present_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->BMS_ambient_temp_sensor_present & (0x01U));
  cframe->Data[1] |= (_m->BMS_Fet_temp_sensor_present & (0x01U));
  cframe->Data[2] |= (_m->BMS_ext_adc1_temp_sensor_present & (0x01U));
  cframe->Data[3] |= (_m->BMS_ext_adc2_temp_sensor_present & (0x01U));
  cframe->Data[4] |= (_m->BMS_afe_ts1_temp_sensor_present & (0x01U));
  cframe->Data[5] |= (_m->BMS_afe_ts3_temp_sensor_present & (0x01U));
  cframe->Data[6] |= (_m->BMS_gauge_temp_sensor_present & (0x01U));

  cframe->MsgId = BMS_Temp_Sensor_Present_CANID;
  cframe->DLC = BMS_Temp_Sensor_Present_DLC;
  cframe->IDE = BMS_Temp_Sensor_Present_IDE;
  return BMS_Temp_Sensor_Present_CANID;
}

#else

uint32_t Pack_BMS_Temp_Sensor_Present_bms_can(BMS_Temp_Sensor_Present_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BMS_Temp_Sensor_Present_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->BMS_ambient_temp_sensor_present & (0x01U));
  _d[1] |= (_m->BMS_Fet_temp_sensor_present & (0x01U));
  _d[2] |= (_m->BMS_ext_adc1_temp_sensor_present & (0x01U));
  _d[3] |= (_m->BMS_ext_adc2_temp_sensor_present & (0x01U));
  _d[4] |= (_m->BMS_afe_ts1_temp_sensor_present & (0x01U));
  _d[5] |= (_m->BMS_afe_ts3_temp_sensor_present & (0x01U));
  _d[6] |= (_m->BMS_gauge_temp_sensor_present & (0x01U));

  *_len = BMS_Temp_Sensor_Present_DLC;
  *_ide = BMS_Temp_Sensor_Present_IDE;
  return BMS_Temp_Sensor_Present_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BMS_FAULT_Level_bms_can(BMS_FAULT_Level_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BMS_fault_lvl0 = (_d[0] & (0x01U));
  _m->BMS_fault_lvl1 = (_d[1] & (0x01U));
  _m->BMS_fault_lvl2 = (_d[2] & (0x01U));
  _m->BMS_fault_lvl3 = (_d[3] & (0x01U));
  _m->BMS_Fault_none = (_d[4] & (0x01U));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BMS_FAULT_Level_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BMS_FAULT_Level_bms_can(&_m->mon1, BMS_FAULT_Level_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BMS_FAULT_Level_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BMS_FAULT_Level_bms_can(BMS_FAULT_Level_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BMS_FAULT_Level_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->BMS_fault_lvl0 & (0x01U));
  cframe->Data[1] |= (_m->BMS_fault_lvl1 & (0x01U));
  cframe->Data[2] |= (_m->BMS_fault_lvl2 & (0x01U));
  cframe->Data[3] |= (_m->BMS_fault_lvl3 & (0x01U));
  cframe->Data[4] |= (_m->BMS_Fault_none & (0x01U));

  cframe->MsgId = BMS_FAULT_Level_CANID;
  cframe->DLC = BMS_FAULT_Level_DLC;
  cframe->IDE = BMS_FAULT_Level_IDE;
  return BMS_FAULT_Level_CANID;
}

#else

uint32_t Pack_BMS_FAULT_Level_bms_can(BMS_FAULT_Level_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BMS_FAULT_Level_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->BMS_fault_lvl0 & (0x01U));
  _d[1] |= (_m->BMS_fault_lvl1 & (0x01U));
  _d[2] |= (_m->BMS_fault_lvl2 & (0x01U));
  _d[3] |= (_m->BMS_fault_lvl3 & (0x01U));
  _d[4] |= (_m->BMS_Fault_none & (0x01U));

  *_len = BMS_FAULT_Level_DLC;
  *_ide = BMS_FAULT_Level_IDE;
  return BMS_FAULT_Level_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_Fet_Status_bms_can(BAT_AFE_Fet_Status_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_afe_chg = (_d[0] & (0x01U));
  _m->BAT_afe_dsg = (_d[1] & (0x01U));
  _m->BAT_afe_pchg = (_d[2] & (0x01U));
  _m->BAT_afe_pdsg = (_d[3] & (0x01U));
  _m->BAT_afe_dchg = (_d[4] & (0x01U));
  _m->BAT_afe_ddsg = (_d[5] & (0x01U));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_AFE_Fet_Status_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_AFE_Fet_Status_bms_can(&_m->mon1, BAT_AFE_Fet_Status_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_AFE_Fet_Status_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_AFE_Fet_Status_bms_can(BAT_AFE_Fet_Status_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_Fet_Status_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->BAT_afe_chg & (0x01U));
  cframe->Data[1] |= (_m->BAT_afe_dsg & (0x01U));
  cframe->Data[2] |= (_m->BAT_afe_pchg & (0x01U));
  cframe->Data[3] |= (_m->BAT_afe_pdsg & (0x01U));
  cframe->Data[4] |= (_m->BAT_afe_dchg & (0x01U));
  cframe->Data[5] |= (_m->BAT_afe_ddsg & (0x01U));

  cframe->MsgId = BAT_AFE_Fet_Status_CANID;
  cframe->DLC = BAT_AFE_Fet_Status_DLC;
  cframe->IDE = BAT_AFE_Fet_Status_IDE;
  return BAT_AFE_Fet_Status_CANID;
}

#else

uint32_t Pack_BAT_AFE_Fet_Status_bms_can(BAT_AFE_Fet_Status_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_Fet_Status_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->BAT_afe_chg & (0x01U));
  _d[1] |= (_m->BAT_afe_dsg & (0x01U));
  _d[2] |= (_m->BAT_afe_pchg & (0x01U));
  _d[3] |= (_m->BAT_afe_pdsg & (0x01U));
  _d[4] |= (_m->BAT_afe_dchg & (0x01U));
  _d[5] |= (_m->BAT_afe_ddsg & (0x01U));

  *_len = BAT_AFE_Fet_Status_DLC;
  *_ide = BAT_AFE_Fet_Status_IDE;
  return BAT_AFE_Fet_Status_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_Status_bms_can(BAT_AFE_Status_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_afe_sleep = (_d[0] & (0x01U));
  _m->BAT_afe_deepsleep = (_d[1] & (0x01U));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_AFE_Status_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_AFE_Status_bms_can(&_m->mon1, BAT_AFE_Status_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_AFE_Status_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_AFE_Status_bms_can(BAT_AFE_Status_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_Status_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->BAT_afe_sleep & (0x01U));
  cframe->Data[1] |= (_m->BAT_afe_deepsleep & (0x01U));

  cframe->MsgId = BAT_AFE_Status_CANID;
  cframe->DLC = BAT_AFE_Status_DLC;
  cframe->IDE = BAT_AFE_Status_IDE;
  return BAT_AFE_Status_CANID;
}

#else

uint32_t Pack_BAT_AFE_Status_bms_can(BAT_AFE_Status_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_Status_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->BAT_afe_sleep & (0x01U));
  _d[1] |= (_m->BAT_afe_deepsleep & (0x01U));

  *_len = BAT_AFE_Status_DLC;
  *_ide = BAT_AFE_Status_IDE;
  return BAT_AFE_Status_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_GAUGE_Status_bms_can(BAT_GAUGE_Status_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_gauge_fullsleep = (_d[0] & (0x01U));
  _m->BAT_gauge_sleep = (_d[1] & (0x01U));
  _m->BAT_gauge_ss = (_d[2] & (0x01U));
  _m->BAT_gauge_fas = (_d[3] & (0x01U));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_GAUGE_Status_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_GAUGE_Status_bms_can(&_m->mon1, BAT_GAUGE_Status_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_GAUGE_Status_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_GAUGE_Status_bms_can(BAT_GAUGE_Status_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_GAUGE_Status_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->BAT_gauge_fullsleep & (0x01U));
  cframe->Data[1] |= (_m->BAT_gauge_sleep & (0x01U));
  cframe->Data[2] |= (_m->BAT_gauge_ss & (0x01U));
  cframe->Data[3] |= (_m->BAT_gauge_fas & (0x01U));

  cframe->MsgId = BAT_GAUGE_Status_CANID;
  cframe->DLC = BAT_GAUGE_Status_DLC;
  cframe->IDE = BAT_GAUGE_Status_IDE;
  return BAT_GAUGE_Status_CANID;
}

#else

uint32_t Pack_BAT_GAUGE_Status_bms_can(BAT_GAUGE_Status_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_GAUGE_Status_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->BAT_gauge_fullsleep & (0x01U));
  _d[1] |= (_m->BAT_gauge_sleep & (0x01U));
  _d[2] |= (_m->BAT_gauge_ss & (0x01U));
  _d[3] |= (_m->BAT_gauge_fas & (0x01U));

  *_len = BAT_GAUGE_Status_DLC;
  *_ide = BAT_GAUGE_Status_IDE;
  return BAT_GAUGE_Status_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_FCU_STATE_REQUEST_bms_can(FCU_STATE_REQUEST_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->FCU_StateRequest = (_d[0] & (0x07U));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FCU_STATE_REQUEST_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FCU_STATE_REQUEST_bms_can(&_m->mon1, FCU_STATE_REQUEST_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return FCU_STATE_REQUEST_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_FCU_STATE_REQUEST_bms_can(FCU_STATE_REQUEST_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < FCU_STATE_REQUEST_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->FCU_StateRequest & (0x07U));

  cframe->MsgId = FCU_STATE_REQUEST_CANID;
  cframe->DLC = FCU_STATE_REQUEST_DLC;
  cframe->IDE = FCU_STATE_REQUEST_IDE;
  return FCU_STATE_REQUEST_CANID;
}

#else

uint32_t Pack_FCU_STATE_REQUEST_bms_can(FCU_STATE_REQUEST_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < FCU_STATE_REQUEST_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->FCU_StateRequest & (0x07U));

  *_len = FCU_STATE_REQUEST_DLC;
  *_ide = FCU_STATE_REQUEST_IDE;
  return FCU_STATE_REQUEST_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_BMS_Cell_Bal_Status_bms_can(BAT_BMS_Cell_Bal_Status_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_bms_active_cells = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->BAT_bms_bal_time = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_BMS_Cell_Bal_Status_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_BMS_Cell_Bal_Status_bms_can(&_m->mon1, BAT_BMS_Cell_Bal_Status_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_BMS_Cell_Bal_Status_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_BMS_Cell_Bal_Status_bms_can(BAT_BMS_Cell_Bal_Status_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_BMS_Cell_Bal_Status_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->BAT_bms_active_cells & (0xFFU));
  cframe->Data[1] |= ((_m->BAT_bms_active_cells >> 8) & (0xFFU));
  cframe->Data[2] |= (_m->BAT_bms_bal_time & (0xFFU));
  cframe->Data[3] |= ((_m->BAT_bms_bal_time >> 8) & (0xFFU));

  cframe->MsgId = BAT_BMS_Cell_Bal_Status_CANID;
  cframe->DLC = BAT_BMS_Cell_Bal_Status_DLC;
  cframe->IDE = BAT_BMS_Cell_Bal_Status_IDE;
  return BAT_BMS_Cell_Bal_Status_CANID;
}

#else

uint32_t Pack_BAT_BMS_Cell_Bal_Status_bms_can(BAT_BMS_Cell_Bal_Status_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_BMS_Cell_Bal_Status_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->BAT_bms_active_cells & (0xFFU));
  _d[1] |= ((_m->BAT_bms_active_cells >> 8) & (0xFFU));
  _d[2] |= (_m->BAT_bms_bal_time & (0xFFU));
  _d[3] |= ((_m->BAT_bms_bal_time >> 8) & (0xFFU));

  *_len = BAT_BMS_Cell_Bal_Status_DLC;
  *_ide = BAT_BMS_Cell_Bal_Status_IDE;
  return BAT_BMS_Cell_Bal_Status_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_BMS_OvrVIEW_bms_can(BAT_BMS_OvrVIEW_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_bms_StateReqSrc = (_d[0] & (0xFFU));
  _m->BAT_bms_PackState = (_d[1] & (0xFFU));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_BMS_OvrVIEW_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_BMS_OvrVIEW_bms_can(&_m->mon1, BAT_BMS_OvrVIEW_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_BMS_OvrVIEW_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_BMS_OvrVIEW_bms_can(BAT_BMS_OvrVIEW_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_BMS_OvrVIEW_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->BAT_bms_StateReqSrc & (0xFFU));
  cframe->Data[1] |= (_m->BAT_bms_PackState & (0xFFU));

  cframe->MsgId = BAT_BMS_OvrVIEW_CANID;
  cframe->DLC = BAT_BMS_OvrVIEW_DLC;
  cframe->IDE = BAT_BMS_OvrVIEW_IDE;
  return BAT_BMS_OvrVIEW_CANID;
}

#else

uint32_t Pack_BAT_BMS_OvrVIEW_bms_can(BAT_BMS_OvrVIEW_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_BMS_OvrVIEW_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->BAT_bms_StateReqSrc & (0xFFU));
  _d[1] |= (_m->BAT_bms_PackState & (0xFFU));

  *_len = BAT_BMS_OvrVIEW_DLC;
  *_ide = BAT_BMS_OvrVIEW_IDE;
  return BAT_BMS_OvrVIEW_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_BMS_ExtTemp_bms_can(BAT_BMS_ExtTemp_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_bms_afe_temp1_ro = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_bms_afe_temp1_phys = (sigfloat_t)(BMS_CAN_BAT_bms_afe_temp1_ro_fromS(_m->BAT_bms_afe_temp1_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_bms_afe_temp2_ro = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_bms_afe_temp2_phys = (sigfloat_t)(BMS_CAN_BAT_bms_afe_temp2_ro_fromS(_m->BAT_bms_afe_temp2_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_bms_ext_temp1 = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  _m->BAT_bms_ext_temp2 = ((_d[7] & (0xFFU)) << 8) | (_d[6] & (0xFFU));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_BMS_ExtTemp_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_BMS_ExtTemp_bms_can(&_m->mon1, BAT_BMS_ExtTemp_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_BMS_ExtTemp_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_BMS_ExtTemp_bms_can(BAT_BMS_ExtTemp_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_BMS_ExtTemp_DLC) && (i < 8); cframe->Data[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_bms_afe_temp1_ro = BMS_CAN_BAT_bms_afe_temp1_ro_toS(_m->BAT_bms_afe_temp1_phys);
  _m->BAT_bms_afe_temp2_ro = BMS_CAN_BAT_bms_afe_temp2_ro_toS(_m->BAT_bms_afe_temp2_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  cframe->Data[0] |= (_m->BAT_bms_afe_temp1_ro & (0xFFU));
  cframe->Data[1] |= ((_m->BAT_bms_afe_temp1_ro >> 8) & (0xFFU));
  cframe->Data[2] |= (_m->BAT_bms_afe_temp2_ro & (0xFFU));
  cframe->Data[3] |= ((_m->BAT_bms_afe_temp2_ro >> 8) & (0xFFU));
  cframe->Data[4] |= (_m->BAT_bms_ext_temp1 & (0xFFU));
  cframe->Data[5] |= ((_m->BAT_bms_ext_temp1 >> 8) & (0xFFU));
  cframe->Data[6] |= (_m->BAT_bms_ext_temp2 & (0xFFU));
  cframe->Data[7] |= ((_m->BAT_bms_ext_temp2 >> 8) & (0xFFU));

  cframe->MsgId = BAT_BMS_ExtTemp_CANID;
  cframe->DLC = BAT_BMS_ExtTemp_DLC;
  cframe->IDE = BAT_BMS_ExtTemp_IDE;
  return BAT_BMS_ExtTemp_CANID;
}

#else

uint32_t Pack_BAT_BMS_ExtTemp_bms_can(BAT_BMS_ExtTemp_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_BMS_ExtTemp_DLC) && (i < 8); _d[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_bms_afe_temp1_ro = BMS_CAN_BAT_bms_afe_temp1_ro_toS(_m->BAT_bms_afe_temp1_phys);
  _m->BAT_bms_afe_temp2_ro = BMS_CAN_BAT_bms_afe_temp2_ro_toS(_m->BAT_bms_afe_temp2_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  _d[0] |= (_m->BAT_bms_afe_temp1_ro & (0xFFU));
  _d[1] |= ((_m->BAT_bms_afe_temp1_ro >> 8) & (0xFFU));
  _d[2] |= (_m->BAT_bms_afe_temp2_ro & (0xFFU));
  _d[3] |= ((_m->BAT_bms_afe_temp2_ro >> 8) & (0xFFU));
  _d[4] |= (_m->BAT_bms_ext_temp1 & (0xFFU));
  _d[5] |= ((_m->BAT_bms_ext_temp1 >> 8) & (0xFFU));
  _d[6] |= (_m->BAT_bms_ext_temp2 & (0xFFU));
  _d[7] |= ((_m->BAT_bms_ext_temp2 >> 8) & (0xFFU));

  *_len = BAT_BMS_ExtTemp_DLC;
  *_ide = BAT_BMS_ExtTemp_IDE;
  return BAT_BMS_ExtTemp_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_BMS_IntTemp_bms_can(BAT_BMS_IntTemp_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_bms_ambient_temp_ro = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_bms_ambient_temp_phys = (sigfloat_t)(BMS_CAN_BAT_bms_ambient_temp_ro_fromS(_m->BAT_bms_ambient_temp_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_bms_fets_temp_ro = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_bms_fets_temp_phys = (sigfloat_t)(BMS_CAN_BAT_bms_fets_temp_ro_fromS(_m->BAT_bms_fets_temp_ro));
#endif // BMS_CAN_USE_SIGFLOAT

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_BMS_IntTemp_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_BMS_IntTemp_bms_can(&_m->mon1, BAT_BMS_IntTemp_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_BMS_IntTemp_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_BMS_IntTemp_bms_can(BAT_BMS_IntTemp_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_BMS_IntTemp_DLC) && (i < 8); cframe->Data[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_bms_ambient_temp_ro = BMS_CAN_BAT_bms_ambient_temp_ro_toS(_m->BAT_bms_ambient_temp_phys);
  _m->BAT_bms_fets_temp_ro = BMS_CAN_BAT_bms_fets_temp_ro_toS(_m->BAT_bms_fets_temp_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  cframe->Data[0] |= (_m->BAT_bms_ambient_temp_ro & (0xFFU));
  cframe->Data[1] |= ((_m->BAT_bms_ambient_temp_ro >> 8) & (0xFFU));
  cframe->Data[2] |= (_m->BAT_bms_fets_temp_ro & (0xFFU));
  cframe->Data[3] |= ((_m->BAT_bms_fets_temp_ro >> 8) & (0xFFU));

  cframe->MsgId = BAT_BMS_IntTemp_CANID;
  cframe->DLC = BAT_BMS_IntTemp_DLC;
  cframe->IDE = BAT_BMS_IntTemp_IDE;
  return BAT_BMS_IntTemp_CANID;
}

#else

uint32_t Pack_BAT_BMS_IntTemp_bms_can(BAT_BMS_IntTemp_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_BMS_IntTemp_DLC) && (i < 8); _d[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_bms_ambient_temp_ro = BMS_CAN_BAT_bms_ambient_temp_ro_toS(_m->BAT_bms_ambient_temp_phys);
  _m->BAT_bms_fets_temp_ro = BMS_CAN_BAT_bms_fets_temp_ro_toS(_m->BAT_bms_fets_temp_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  _d[0] |= (_m->BAT_bms_ambient_temp_ro & (0xFFU));
  _d[1] |= ((_m->BAT_bms_ambient_temp_ro >> 8) & (0xFFU));
  _d[2] |= (_m->BAT_bms_fets_temp_ro & (0xFFU));
  _d[3] |= ((_m->BAT_bms_fets_temp_ro >> 8) & (0xFFU));

  *_len = BAT_BMS_IntTemp_DLC;
  *_ide = BAT_BMS_IntTemp_IDE;
  return BAT_BMS_IntTemp_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_BMS_Charger_Load_Status_bms_can(BAT_BMS_Charger_Load_Status_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->APP_bms_load_detect = (_d[0] & (0x01U));
  _m->APP_bms_charger_detect = (_d[1] & (0x01U));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_BMS_Charger_Load_Status_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_BMS_Charger_Load_Status_bms_can(&_m->mon1, BAT_BMS_Charger_Load_Status_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_BMS_Charger_Load_Status_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_BMS_Charger_Load_Status_bms_can(BAT_BMS_Charger_Load_Status_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_BMS_Charger_Load_Status_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->APP_bms_load_detect & (0x01U));
  cframe->Data[1] |= (_m->APP_bms_charger_detect & (0x01U));

  cframe->MsgId = BAT_BMS_Charger_Load_Status_CANID;
  cframe->DLC = BAT_BMS_Charger_Load_Status_DLC;
  cframe->IDE = BAT_BMS_Charger_Load_Status_IDE;
  return BAT_BMS_Charger_Load_Status_CANID;
}

#else

uint32_t Pack_BAT_BMS_Charger_Load_Status_bms_can(BAT_BMS_Charger_Load_Status_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_BMS_Charger_Load_Status_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->APP_bms_load_detect & (0x01U));
  _d[1] |= (_m->APP_bms_charger_detect & (0x01U));

  *_len = BAT_BMS_Charger_Load_Status_DLC;
  *_ide = BAT_BMS_Charger_Load_Status_IDE;
  return BAT_BMS_Charger_Load_Status_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_vBRICK_A_bms_can(BAT_AFE_vBRICK_A_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_afe_vBrick01_ro = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick01_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick01_ro_fromS(_m->BAT_afe_vBrick01_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vBrick02_ro = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick02_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick02_ro_fromS(_m->BAT_afe_vBrick02_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vBrick03_ro = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick03_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick03_ro_fromS(_m->BAT_afe_vBrick03_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vBrick04_ro = ((_d[7] & (0xFFU)) << 8) | (_d[6] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick04_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick04_ro_fromS(_m->BAT_afe_vBrick04_ro));
#endif // BMS_CAN_USE_SIGFLOAT

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_AFE_vBRICK_A_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_AFE_vBRICK_A_bms_can(&_m->mon1, BAT_AFE_vBRICK_A_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_AFE_vBRICK_A_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_AFE_vBRICK_A_bms_can(BAT_AFE_vBRICK_A_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_vBRICK_A_DLC) && (i < 8); cframe->Data[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick01_ro = BMS_CAN_BAT_afe_vBrick01_ro_toS(_m->BAT_afe_vBrick01_phys);
  _m->BAT_afe_vBrick02_ro = BMS_CAN_BAT_afe_vBrick02_ro_toS(_m->BAT_afe_vBrick02_phys);
  _m->BAT_afe_vBrick03_ro = BMS_CAN_BAT_afe_vBrick03_ro_toS(_m->BAT_afe_vBrick03_phys);
  _m->BAT_afe_vBrick04_ro = BMS_CAN_BAT_afe_vBrick04_ro_toS(_m->BAT_afe_vBrick04_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  cframe->Data[0] |= (_m->BAT_afe_vBrick01_ro & (0xFFU));
  cframe->Data[1] |= ((_m->BAT_afe_vBrick01_ro >> 8) & (0xFFU));
  cframe->Data[2] |= (_m->BAT_afe_vBrick02_ro & (0xFFU));
  cframe->Data[3] |= ((_m->BAT_afe_vBrick02_ro >> 8) & (0xFFU));
  cframe->Data[4] |= (_m->BAT_afe_vBrick03_ro & (0xFFU));
  cframe->Data[5] |= ((_m->BAT_afe_vBrick03_ro >> 8) & (0xFFU));
  cframe->Data[6] |= (_m->BAT_afe_vBrick04_ro & (0xFFU));
  cframe->Data[7] |= ((_m->BAT_afe_vBrick04_ro >> 8) & (0xFFU));

  cframe->MsgId = BAT_AFE_vBRICK_A_CANID;
  cframe->DLC = BAT_AFE_vBRICK_A_DLC;
  cframe->IDE = BAT_AFE_vBRICK_A_IDE;
  return BAT_AFE_vBRICK_A_CANID;
}

#else

uint32_t Pack_BAT_AFE_vBRICK_A_bms_can(BAT_AFE_vBRICK_A_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_vBRICK_A_DLC) && (i < 8); _d[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick01_ro = BMS_CAN_BAT_afe_vBrick01_ro_toS(_m->BAT_afe_vBrick01_phys);
  _m->BAT_afe_vBrick02_ro = BMS_CAN_BAT_afe_vBrick02_ro_toS(_m->BAT_afe_vBrick02_phys);
  _m->BAT_afe_vBrick03_ro = BMS_CAN_BAT_afe_vBrick03_ro_toS(_m->BAT_afe_vBrick03_phys);
  _m->BAT_afe_vBrick04_ro = BMS_CAN_BAT_afe_vBrick04_ro_toS(_m->BAT_afe_vBrick04_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  _d[0] |= (_m->BAT_afe_vBrick01_ro & (0xFFU));
  _d[1] |= ((_m->BAT_afe_vBrick01_ro >> 8) & (0xFFU));
  _d[2] |= (_m->BAT_afe_vBrick02_ro & (0xFFU));
  _d[3] |= ((_m->BAT_afe_vBrick02_ro >> 8) & (0xFFU));
  _d[4] |= (_m->BAT_afe_vBrick03_ro & (0xFFU));
  _d[5] |= ((_m->BAT_afe_vBrick03_ro >> 8) & (0xFFU));
  _d[6] |= (_m->BAT_afe_vBrick04_ro & (0xFFU));
  _d[7] |= ((_m->BAT_afe_vBrick04_ro >> 8) & (0xFFU));

  *_len = BAT_AFE_vBRICK_A_DLC;
  *_ide = BAT_AFE_vBRICK_A_IDE;
  return BAT_AFE_vBRICK_A_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_vBRICK_B_bms_can(BAT_AFE_vBRICK_B_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_afe_vBrick05_ro = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick05_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick05_ro_fromS(_m->BAT_afe_vBrick05_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vBrick06_ro = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick06_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick06_ro_fromS(_m->BAT_afe_vBrick06_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vBrick07_ro = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick07_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick07_ro_fromS(_m->BAT_afe_vBrick07_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vBrick08_ro = ((_d[7] & (0xFFU)) << 8) | (_d[6] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick08_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick08_ro_fromS(_m->BAT_afe_vBrick08_ro));
#endif // BMS_CAN_USE_SIGFLOAT

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_AFE_vBRICK_B_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_AFE_vBRICK_B_bms_can(&_m->mon1, BAT_AFE_vBRICK_B_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_AFE_vBRICK_B_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_AFE_vBRICK_B_bms_can(BAT_AFE_vBRICK_B_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_vBRICK_B_DLC) && (i < 8); cframe->Data[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick05_ro = BMS_CAN_BAT_afe_vBrick05_ro_toS(_m->BAT_afe_vBrick05_phys);
  _m->BAT_afe_vBrick06_ro = BMS_CAN_BAT_afe_vBrick06_ro_toS(_m->BAT_afe_vBrick06_phys);
  _m->BAT_afe_vBrick07_ro = BMS_CAN_BAT_afe_vBrick07_ro_toS(_m->BAT_afe_vBrick07_phys);
  _m->BAT_afe_vBrick08_ro = BMS_CAN_BAT_afe_vBrick08_ro_toS(_m->BAT_afe_vBrick08_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  cframe->Data[0] |= (_m->BAT_afe_vBrick05_ro & (0xFFU));
  cframe->Data[1] |= ((_m->BAT_afe_vBrick05_ro >> 8) & (0xFFU));
  cframe->Data[2] |= (_m->BAT_afe_vBrick06_ro & (0xFFU));
  cframe->Data[3] |= ((_m->BAT_afe_vBrick06_ro >> 8) & (0xFFU));
  cframe->Data[4] |= (_m->BAT_afe_vBrick07_ro & (0xFFU));
  cframe->Data[5] |= ((_m->BAT_afe_vBrick07_ro >> 8) & (0xFFU));
  cframe->Data[6] |= (_m->BAT_afe_vBrick08_ro & (0xFFU));
  cframe->Data[7] |= ((_m->BAT_afe_vBrick08_ro >> 8) & (0xFFU));

  cframe->MsgId = BAT_AFE_vBRICK_B_CANID;
  cframe->DLC = BAT_AFE_vBRICK_B_DLC;
  cframe->IDE = BAT_AFE_vBRICK_B_IDE;
  return BAT_AFE_vBRICK_B_CANID;
}

#else

uint32_t Pack_BAT_AFE_vBRICK_B_bms_can(BAT_AFE_vBRICK_B_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_vBRICK_B_DLC) && (i < 8); _d[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick05_ro = BMS_CAN_BAT_afe_vBrick05_ro_toS(_m->BAT_afe_vBrick05_phys);
  _m->BAT_afe_vBrick06_ro = BMS_CAN_BAT_afe_vBrick06_ro_toS(_m->BAT_afe_vBrick06_phys);
  _m->BAT_afe_vBrick07_ro = BMS_CAN_BAT_afe_vBrick07_ro_toS(_m->BAT_afe_vBrick07_phys);
  _m->BAT_afe_vBrick08_ro = BMS_CAN_BAT_afe_vBrick08_ro_toS(_m->BAT_afe_vBrick08_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  _d[0] |= (_m->BAT_afe_vBrick05_ro & (0xFFU));
  _d[1] |= ((_m->BAT_afe_vBrick05_ro >> 8) & (0xFFU));
  _d[2] |= (_m->BAT_afe_vBrick06_ro & (0xFFU));
  _d[3] |= ((_m->BAT_afe_vBrick06_ro >> 8) & (0xFFU));
  _d[4] |= (_m->BAT_afe_vBrick07_ro & (0xFFU));
  _d[5] |= ((_m->BAT_afe_vBrick07_ro >> 8) & (0xFFU));
  _d[6] |= (_m->BAT_afe_vBrick08_ro & (0xFFU));
  _d[7] |= ((_m->BAT_afe_vBrick08_ro >> 8) & (0xFFU));

  *_len = BAT_AFE_vBRICK_B_DLC;
  *_ide = BAT_AFE_vBRICK_B_IDE;
  return BAT_AFE_vBRICK_B_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_vBRICK_C_bms_can(BAT_AFE_vBRICK_C_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_afe_vBrick09_ro = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick09_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick09_ro_fromS(_m->BAT_afe_vBrick09_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vBrick10_ro = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick10_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick10_ro_fromS(_m->BAT_afe_vBrick10_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vBrick11_ro = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick11_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick11_ro_fromS(_m->BAT_afe_vBrick11_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vBrick12_ro = ((_d[7] & (0xFFU)) << 8) | (_d[6] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick12_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick12_ro_fromS(_m->BAT_afe_vBrick12_ro));
#endif // BMS_CAN_USE_SIGFLOAT

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_AFE_vBRICK_C_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_AFE_vBRICK_C_bms_can(&_m->mon1, BAT_AFE_vBRICK_C_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_AFE_vBRICK_C_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_AFE_vBRICK_C_bms_can(BAT_AFE_vBRICK_C_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_vBRICK_C_DLC) && (i < 8); cframe->Data[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick09_ro = BMS_CAN_BAT_afe_vBrick09_ro_toS(_m->BAT_afe_vBrick09_phys);
  _m->BAT_afe_vBrick10_ro = BMS_CAN_BAT_afe_vBrick10_ro_toS(_m->BAT_afe_vBrick10_phys);
  _m->BAT_afe_vBrick11_ro = BMS_CAN_BAT_afe_vBrick11_ro_toS(_m->BAT_afe_vBrick11_phys);
  _m->BAT_afe_vBrick12_ro = BMS_CAN_BAT_afe_vBrick12_ro_toS(_m->BAT_afe_vBrick12_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  cframe->Data[0] |= (_m->BAT_afe_vBrick09_ro & (0xFFU));
  cframe->Data[1] |= ((_m->BAT_afe_vBrick09_ro >> 8) & (0xFFU));
  cframe->Data[2] |= (_m->BAT_afe_vBrick10_ro & (0xFFU));
  cframe->Data[3] |= ((_m->BAT_afe_vBrick10_ro >> 8) & (0xFFU));
  cframe->Data[4] |= (_m->BAT_afe_vBrick11_ro & (0xFFU));
  cframe->Data[5] |= ((_m->BAT_afe_vBrick11_ro >> 8) & (0xFFU));
  cframe->Data[6] |= (_m->BAT_afe_vBrick12_ro & (0xFFU));
  cframe->Data[7] |= ((_m->BAT_afe_vBrick12_ro >> 8) & (0xFFU));

  cframe->MsgId = BAT_AFE_vBRICK_C_CANID;
  cframe->DLC = BAT_AFE_vBRICK_C_DLC;
  cframe->IDE = BAT_AFE_vBRICK_C_IDE;
  return BAT_AFE_vBRICK_C_CANID;
}

#else

uint32_t Pack_BAT_AFE_vBRICK_C_bms_can(BAT_AFE_vBRICK_C_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_vBRICK_C_DLC) && (i < 8); _d[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick09_ro = BMS_CAN_BAT_afe_vBrick09_ro_toS(_m->BAT_afe_vBrick09_phys);
  _m->BAT_afe_vBrick10_ro = BMS_CAN_BAT_afe_vBrick10_ro_toS(_m->BAT_afe_vBrick10_phys);
  _m->BAT_afe_vBrick11_ro = BMS_CAN_BAT_afe_vBrick11_ro_toS(_m->BAT_afe_vBrick11_phys);
  _m->BAT_afe_vBrick12_ro = BMS_CAN_BAT_afe_vBrick12_ro_toS(_m->BAT_afe_vBrick12_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  _d[0] |= (_m->BAT_afe_vBrick09_ro & (0xFFU));
  _d[1] |= ((_m->BAT_afe_vBrick09_ro >> 8) & (0xFFU));
  _d[2] |= (_m->BAT_afe_vBrick10_ro & (0xFFU));
  _d[3] |= ((_m->BAT_afe_vBrick10_ro >> 8) & (0xFFU));
  _d[4] |= (_m->BAT_afe_vBrick11_ro & (0xFFU));
  _d[5] |= ((_m->BAT_afe_vBrick11_ro >> 8) & (0xFFU));
  _d[6] |= (_m->BAT_afe_vBrick12_ro & (0xFFU));
  _d[7] |= ((_m->BAT_afe_vBrick12_ro >> 8) & (0xFFU));

  *_len = BAT_AFE_vBRICK_C_DLC;
  *_ide = BAT_AFE_vBRICK_C_IDE;
  return BAT_AFE_vBRICK_C_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_vBRICK_D_bms_can(BAT_AFE_vBRICK_D_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_afe_vBrick13_ro = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick13_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick13_ro_fromS(_m->BAT_afe_vBrick13_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vBrick14_ro = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick14_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick14_ro_fromS(_m->BAT_afe_vBrick14_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vBrick15_ro = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick15_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick15_ro_fromS(_m->BAT_afe_vBrick15_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vBrick16_ro = ((_d[7] & (0xFFU)) << 8) | (_d[6] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick16_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vBrick16_ro_fromS(_m->BAT_afe_vBrick16_ro));
#endif // BMS_CAN_USE_SIGFLOAT

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_AFE_vBRICK_D_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_AFE_vBRICK_D_bms_can(&_m->mon1, BAT_AFE_vBRICK_D_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_AFE_vBRICK_D_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_AFE_vBRICK_D_bms_can(BAT_AFE_vBRICK_D_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_vBRICK_D_DLC) && (i < 8); cframe->Data[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick13_ro = BMS_CAN_BAT_afe_vBrick13_ro_toS(_m->BAT_afe_vBrick13_phys);
  _m->BAT_afe_vBrick14_ro = BMS_CAN_BAT_afe_vBrick14_ro_toS(_m->BAT_afe_vBrick14_phys);
  _m->BAT_afe_vBrick15_ro = BMS_CAN_BAT_afe_vBrick15_ro_toS(_m->BAT_afe_vBrick15_phys);
  _m->BAT_afe_vBrick16_ro = BMS_CAN_BAT_afe_vBrick16_ro_toS(_m->BAT_afe_vBrick16_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  cframe->Data[0] |= (_m->BAT_afe_vBrick13_ro & (0xFFU));
  cframe->Data[1] |= ((_m->BAT_afe_vBrick13_ro >> 8) & (0xFFU));
  cframe->Data[2] |= (_m->BAT_afe_vBrick14_ro & (0xFFU));
  cframe->Data[3] |= ((_m->BAT_afe_vBrick14_ro >> 8) & (0xFFU));
  cframe->Data[4] |= (_m->BAT_afe_vBrick15_ro & (0xFFU));
  cframe->Data[5] |= ((_m->BAT_afe_vBrick15_ro >> 8) & (0xFFU));
  cframe->Data[6] |= (_m->BAT_afe_vBrick16_ro & (0xFFU));
  cframe->Data[7] |= ((_m->BAT_afe_vBrick16_ro >> 8) & (0xFFU));

  cframe->MsgId = BAT_AFE_vBRICK_D_CANID;
  cframe->DLC = BAT_AFE_vBRICK_D_DLC;
  cframe->IDE = BAT_AFE_vBRICK_D_IDE;
  return BAT_AFE_vBRICK_D_CANID;
}

#else

uint32_t Pack_BAT_AFE_vBRICK_D_bms_can(BAT_AFE_vBRICK_D_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_vBRICK_D_DLC) && (i < 8); _d[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vBrick13_ro = BMS_CAN_BAT_afe_vBrick13_ro_toS(_m->BAT_afe_vBrick13_phys);
  _m->BAT_afe_vBrick14_ro = BMS_CAN_BAT_afe_vBrick14_ro_toS(_m->BAT_afe_vBrick14_phys);
  _m->BAT_afe_vBrick15_ro = BMS_CAN_BAT_afe_vBrick15_ro_toS(_m->BAT_afe_vBrick15_phys);
  _m->BAT_afe_vBrick16_ro = BMS_CAN_BAT_afe_vBrick16_ro_toS(_m->BAT_afe_vBrick16_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  _d[0] |= (_m->BAT_afe_vBrick13_ro & (0xFFU));
  _d[1] |= ((_m->BAT_afe_vBrick13_ro >> 8) & (0xFFU));
  _d[2] |= (_m->BAT_afe_vBrick14_ro & (0xFFU));
  _d[3] |= ((_m->BAT_afe_vBrick14_ro >> 8) & (0xFFU));
  _d[4] |= (_m->BAT_afe_vBrick15_ro & (0xFFU));
  _d[5] |= ((_m->BAT_afe_vBrick15_ro >> 8) & (0xFFU));
  _d[6] |= (_m->BAT_afe_vBrick16_ro & (0xFFU));
  _d[7] |= ((_m->BAT_afe_vBrick16_ro >> 8) & (0xFFU));

  *_len = BAT_AFE_vBRICK_D_DLC;
  *_ide = BAT_AFE_vBRICK_D_IDE;
  return BAT_AFE_vBRICK_D_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_Current_bms_can(BAT_AFE_Current_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_afe_CC2_current_ro = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_CC2_current_phys = (sigfloat_t)(BMS_CAN_BAT_afe_CC2_current_ro_fromS(_m->BAT_afe_CC2_current_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_CC3_current_ro = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_CC3_current_phys = (sigfloat_t)(BMS_CAN_BAT_afe_CC3_current_ro_fromS(_m->BAT_afe_CC3_current_ro));
#endif // BMS_CAN_USE_SIGFLOAT

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_AFE_Current_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_AFE_Current_bms_can(&_m->mon1, BAT_AFE_Current_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_AFE_Current_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_AFE_Current_bms_can(BAT_AFE_Current_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_Current_DLC) && (i < 8); cframe->Data[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_CC2_current_ro = BMS_CAN_BAT_afe_CC2_current_ro_toS(_m->BAT_afe_CC2_current_phys);
  _m->BAT_afe_CC3_current_ro = BMS_CAN_BAT_afe_CC3_current_ro_toS(_m->BAT_afe_CC3_current_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  cframe->Data[0] |= (_m->BAT_afe_CC2_current_ro & (0xFFU));
  cframe->Data[1] |= ((_m->BAT_afe_CC2_current_ro >> 8) & (0xFFU));
  cframe->Data[2] |= (_m->BAT_afe_CC3_current_ro & (0xFFU));
  cframe->Data[3] |= ((_m->BAT_afe_CC3_current_ro >> 8) & (0xFFU));

  cframe->MsgId = BAT_AFE_Current_CANID;
  cframe->DLC = BAT_AFE_Current_DLC;
  cframe->IDE = BAT_AFE_Current_IDE;
  return BAT_AFE_Current_CANID;
}

#else

uint32_t Pack_BAT_AFE_Current_bms_can(BAT_AFE_Current_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_Current_DLC) && (i < 8); _d[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_CC2_current_ro = BMS_CAN_BAT_afe_CC2_current_ro_toS(_m->BAT_afe_CC2_current_phys);
  _m->BAT_afe_CC3_current_ro = BMS_CAN_BAT_afe_CC3_current_ro_toS(_m->BAT_afe_CC3_current_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  _d[0] |= (_m->BAT_afe_CC2_current_ro & (0xFFU));
  _d[1] |= ((_m->BAT_afe_CC2_current_ro >> 8) & (0xFFU));
  _d[2] |= (_m->BAT_afe_CC3_current_ro & (0xFFU));
  _d[3] |= ((_m->BAT_afe_CC3_current_ro >> 8) & (0xFFU));

  *_len = BAT_AFE_Current_DLC;
  *_ide = BAT_AFE_Current_IDE;
  return BAT_AFE_Current_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_GAUGE_OvrVIEW_bms_can(BAT_GAUGE_OvrVIEW_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_gauge_SoC = (_d[0] & (0xFFU));
  _m->BAT_gaige_SoH = (_d[1] & (0xFFU));
  _m->BAT_gauge_cycleCount = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  _m->BAT_gauge_remainingCap_ro = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_gauge_remainingCap_phys = (sigfloat_t)(BMS_CAN_BAT_gauge_remainingCap_ro_fromS(_m->BAT_gauge_remainingCap_ro));
#endif // BMS_CAN_USE_SIGFLOAT

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_GAUGE_OvrVIEW_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_GAUGE_OvrVIEW_bms_can(&_m->mon1, BAT_GAUGE_OvrVIEW_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_GAUGE_OvrVIEW_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_GAUGE_OvrVIEW_bms_can(BAT_GAUGE_OvrVIEW_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_GAUGE_OvrVIEW_DLC) && (i < 8); cframe->Data[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_gauge_remainingCap_ro = BMS_CAN_BAT_gauge_remainingCap_ro_toS(_m->BAT_gauge_remainingCap_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  cframe->Data[0] |= (_m->BAT_gauge_SoC & (0xFFU));
  cframe->Data[1] |= (_m->BAT_gaige_SoH & (0xFFU));
  cframe->Data[2] |= (_m->BAT_gauge_cycleCount & (0xFFU));
  cframe->Data[3] |= ((_m->BAT_gauge_cycleCount >> 8) & (0xFFU));
  cframe->Data[4] |= (_m->BAT_gauge_remainingCap_ro & (0xFFU));
  cframe->Data[5] |= ((_m->BAT_gauge_remainingCap_ro >> 8) & (0xFFU));

  cframe->MsgId = BAT_GAUGE_OvrVIEW_CANID;
  cframe->DLC = BAT_GAUGE_OvrVIEW_DLC;
  cframe->IDE = BAT_GAUGE_OvrVIEW_IDE;
  return BAT_GAUGE_OvrVIEW_CANID;
}

#else

uint32_t Pack_BAT_GAUGE_OvrVIEW_bms_can(BAT_GAUGE_OvrVIEW_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_GAUGE_OvrVIEW_DLC) && (i < 8); _d[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_gauge_remainingCap_ro = BMS_CAN_BAT_gauge_remainingCap_ro_toS(_m->BAT_gauge_remainingCap_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  _d[0] |= (_m->BAT_gauge_SoC & (0xFFU));
  _d[1] |= (_m->BAT_gaige_SoH & (0xFFU));
  _d[2] |= (_m->BAT_gauge_cycleCount & (0xFFU));
  _d[3] |= ((_m->BAT_gauge_cycleCount >> 8) & (0xFFU));
  _d[4] |= (_m->BAT_gauge_remainingCap_ro & (0xFFU));
  _d[5] |= ((_m->BAT_gauge_remainingCap_ro >> 8) & (0xFFU));

  *_len = BAT_GAUGE_OvrVIEW_DLC;
  *_ide = BAT_GAUGE_OvrVIEW_IDE;
  return BAT_GAUGE_OvrVIEW_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_GAUGE_ViT_bms_can(BAT_GAUGE_ViT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_gauge_vPack_ro = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_gauge_vPack_phys = (sigfloat_t)(BMS_CAN_BAT_gauge_vPack_ro_fromS(_m->BAT_gauge_vPack_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_gauge_iPack_ro = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_gauge_iPack_phys = (sigfloat_t)(BMS_CAN_BAT_gauge_iPack_ro_fromS(_m->BAT_gauge_iPack_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_gauge_tPack_ro = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_gauge_tPack_phys = (sigfloat_t)(BMS_CAN_BAT_gauge_tPack_ro_fromS(_m->BAT_gauge_tPack_ro));
#endif // BMS_CAN_USE_SIGFLOAT

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_GAUGE_ViT_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_GAUGE_ViT_bms_can(&_m->mon1, BAT_GAUGE_ViT_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_GAUGE_ViT_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_GAUGE_ViT_bms_can(BAT_GAUGE_ViT_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_GAUGE_ViT_DLC) && (i < 8); cframe->Data[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_gauge_vPack_ro = BMS_CAN_BAT_gauge_vPack_ro_toS(_m->BAT_gauge_vPack_phys);
  _m->BAT_gauge_iPack_ro = BMS_CAN_BAT_gauge_iPack_ro_toS(_m->BAT_gauge_iPack_phys);
  _m->BAT_gauge_tPack_ro = BMS_CAN_BAT_gauge_tPack_ro_toS(_m->BAT_gauge_tPack_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  cframe->Data[0] |= (_m->BAT_gauge_vPack_ro & (0xFFU));
  cframe->Data[1] |= ((_m->BAT_gauge_vPack_ro >> 8) & (0xFFU));
  cframe->Data[2] |= (_m->BAT_gauge_iPack_ro & (0xFFU));
  cframe->Data[3] |= ((_m->BAT_gauge_iPack_ro >> 8) & (0xFFU));
  cframe->Data[4] |= (_m->BAT_gauge_tPack_ro & (0xFFU));
  cframe->Data[5] |= ((_m->BAT_gauge_tPack_ro >> 8) & (0xFFU));

  cframe->MsgId = BAT_GAUGE_ViT_CANID;
  cframe->DLC = BAT_GAUGE_ViT_DLC;
  cframe->IDE = BAT_GAUGE_ViT_IDE;
  return BAT_GAUGE_ViT_CANID;
}

#else

uint32_t Pack_BAT_GAUGE_ViT_bms_can(BAT_GAUGE_ViT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_GAUGE_ViT_DLC) && (i < 8); _d[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_gauge_vPack_ro = BMS_CAN_BAT_gauge_vPack_ro_toS(_m->BAT_gauge_vPack_phys);
  _m->BAT_gauge_iPack_ro = BMS_CAN_BAT_gauge_iPack_ro_toS(_m->BAT_gauge_iPack_phys);
  _m->BAT_gauge_tPack_ro = BMS_CAN_BAT_gauge_tPack_ro_toS(_m->BAT_gauge_tPack_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  _d[0] |= (_m->BAT_gauge_vPack_ro & (0xFFU));
  _d[1] |= ((_m->BAT_gauge_vPack_ro >> 8) & (0xFFU));
  _d[2] |= (_m->BAT_gauge_iPack_ro & (0xFFU));
  _d[3] |= ((_m->BAT_gauge_iPack_ro >> 8) & (0xFFU));
  _d[4] |= (_m->BAT_gauge_tPack_ro & (0xFFU));
  _d[5] |= ((_m->BAT_gauge_tPack_ro >> 8) & (0xFFU));

  *_len = BAT_GAUGE_ViT_DLC;
  *_ide = BAT_GAUGE_ViT_IDE;
  return BAT_GAUGE_ViT_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_GAUGE_Cap_bms_can(BAT_GAUGE_Cap_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_Gauge_DSG_Time = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->BAT_Gauge_CHG_Time = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  _m->BAT_Gauge_Design_Cap = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_GAUGE_Cap_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_GAUGE_Cap_bms_can(&_m->mon1, BAT_GAUGE_Cap_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_GAUGE_Cap_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_GAUGE_Cap_bms_can(BAT_GAUGE_Cap_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_GAUGE_Cap_DLC) && (i < 8); cframe->Data[i++] = 0);

  cframe->Data[0] |= (_m->BAT_Gauge_DSG_Time & (0xFFU));
  cframe->Data[1] |= ((_m->BAT_Gauge_DSG_Time >> 8) & (0xFFU));
  cframe->Data[2] |= (_m->BAT_Gauge_CHG_Time & (0xFFU));
  cframe->Data[3] |= ((_m->BAT_Gauge_CHG_Time >> 8) & (0xFFU));
  cframe->Data[4] |= (_m->BAT_Gauge_Design_Cap & (0xFFU));
  cframe->Data[5] |= ((_m->BAT_Gauge_Design_Cap >> 8) & (0xFFU));

  cframe->MsgId = BAT_GAUGE_Cap_CANID;
  cframe->DLC = BAT_GAUGE_Cap_DLC;
  cframe->IDE = BAT_GAUGE_Cap_IDE;
  return BAT_GAUGE_Cap_CANID;
}

#else

uint32_t Pack_BAT_GAUGE_Cap_bms_can(BAT_GAUGE_Cap_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_GAUGE_Cap_DLC) && (i < 8); _d[i++] = 0);

  _d[0] |= (_m->BAT_Gauge_DSG_Time & (0xFFU));
  _d[1] |= ((_m->BAT_Gauge_DSG_Time >> 8) & (0xFFU));
  _d[2] |= (_m->BAT_Gauge_CHG_Time & (0xFFU));
  _d[3] |= ((_m->BAT_Gauge_CHG_Time >> 8) & (0xFFU));
  _d[4] |= (_m->BAT_Gauge_Design_Cap & (0xFFU));
  _d[5] |= ((_m->BAT_Gauge_Design_Cap >> 8) & (0xFFU));

  *_len = BAT_GAUGE_Cap_DLC;
  *_ide = BAT_GAUGE_Cap_IDE;
  return BAT_GAUGE_Cap_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT

uint32_t Unpack_BAT_AFE_Debug_Data_bms_can(BAT_AFE_Debug_Data_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->BAT_afe_vStack_ro = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vStack_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vStack_ro_fromS(_m->BAT_afe_vStack_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vPack_ro = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vPack_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vPack_ro_fromS(_m->BAT_afe_vPack_ro));
#endif // BMS_CAN_USE_SIGFLOAT

  _m->BAT_afe_vLdPin_ro = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vLdPin_phys = (sigfloat_t)(BMS_CAN_BAT_afe_vLdPin_ro_fromS(_m->BAT_afe_vLdPin_ro));
#endif // BMS_CAN_USE_SIGFLOAT

#ifdef BMS_CAN_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BAT_AFE_Debug_Data_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BAT_AFE_Debug_Data_bms_can(&_m->mon1, BAT_AFE_Debug_Data_CANID);
#endif // BMS_CAN_USE_DIAG_MONITORS

  return BAT_AFE_Debug_Data_CANID;
}

#ifdef BMS_CAN_USE_CANSTRUCT

uint32_t Pack_BAT_AFE_Debug_Data_bms_can(BAT_AFE_Debug_Data_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_Debug_Data_DLC) && (i < 8); cframe->Data[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vStack_ro = BMS_CAN_BAT_afe_vStack_ro_toS(_m->BAT_afe_vStack_phys);
  _m->BAT_afe_vPack_ro = BMS_CAN_BAT_afe_vPack_ro_toS(_m->BAT_afe_vPack_phys);
  _m->BAT_afe_vLdPin_ro = BMS_CAN_BAT_afe_vLdPin_ro_toS(_m->BAT_afe_vLdPin_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  cframe->Data[0] |= (_m->BAT_afe_vStack_ro & (0xFFU));
  cframe->Data[1] |= ((_m->BAT_afe_vStack_ro >> 8) & (0xFFU));
  cframe->Data[2] |= (_m->BAT_afe_vPack_ro & (0xFFU));
  cframe->Data[3] |= ((_m->BAT_afe_vPack_ro >> 8) & (0xFFU));
  cframe->Data[4] |= (_m->BAT_afe_vLdPin_ro & (0xFFU));
  cframe->Data[5] |= ((_m->BAT_afe_vLdPin_ro >> 8) & (0xFFU));

  cframe->MsgId = BAT_AFE_Debug_Data_CANID;
  cframe->DLC = BAT_AFE_Debug_Data_DLC;
  cframe->IDE = BAT_AFE_Debug_Data_IDE;
  return BAT_AFE_Debug_Data_CANID;
}

#else

uint32_t Pack_BAT_AFE_Debug_Data_bms_can(BAT_AFE_Debug_Data_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; (i < BAT_AFE_Debug_Data_DLC) && (i < 8); _d[i++] = 0);

#ifdef BMS_CAN_USE_SIGFLOAT
  _m->BAT_afe_vStack_ro = BMS_CAN_BAT_afe_vStack_ro_toS(_m->BAT_afe_vStack_phys);
  _m->BAT_afe_vPack_ro = BMS_CAN_BAT_afe_vPack_ro_toS(_m->BAT_afe_vPack_phys);
  _m->BAT_afe_vLdPin_ro = BMS_CAN_BAT_afe_vLdPin_ro_toS(_m->BAT_afe_vLdPin_phys);
#endif // BMS_CAN_USE_SIGFLOAT

  _d[0] |= (_m->BAT_afe_vStack_ro & (0xFFU));
  _d[1] |= ((_m->BAT_afe_vStack_ro >> 8) & (0xFFU));
  _d[2] |= (_m->BAT_afe_vPack_ro & (0xFFU));
  _d[3] |= ((_m->BAT_afe_vPack_ro >> 8) & (0xFFU));
  _d[4] |= (_m->BAT_afe_vLdPin_ro & (0xFFU));
  _d[5] |= ((_m->BAT_afe_vLdPin_ro >> 8) & (0xFFU));

  *_len = BAT_AFE_Debug_Data_DLC;
  *_ide = BAT_AFE_Debug_Data_IDE;
  return BAT_AFE_Debug_Data_CANID;
}

#endif // BMS_CAN_USE_CANSTRUCT
