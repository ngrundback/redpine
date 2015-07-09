/*HEADER**********************************************************************

Project name 	: Godavari
File Name    	: ganges_channel_prog_val_8111.h
File Description: BBP RF Programming value for RF AL8111

Rev History:
Ver  By    Date       Description
---------------------------------------------------------
1.0        28/05/11   Initial Version. Working in end to end other frequencies
                      are removed
---------------------------------------------------------
 
*END*************************************************************************/
#ifndef RSI_CHAN_PROG_VAL_H
#define RSI_CHAN_PROG_VAL_H

struct scan_programming_seq_t RF_channel_40mhz = {
  168,12,
  {
    /* channel 1 - 2412 MHz */
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000},
    /* channel 2 - 2417 MHz */                         
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000},
    /* channel 3 - 2422 MHz */          
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000},
    /* channel 4 - 2427 MHz */          
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000},
    /* channel 5 - 2432 MHz */          
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000},
    /* channel 6 - 2437 MHz */          
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000},
    /* channel 7 - 2442 MHz */          
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000},
    /* channel 8 - 2447 MHz */          
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000},
    /* channel 9 - 2452 MHz */          
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000},
    /* channel 10 - 2457 MHz */         
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000},
    /* channel 11 - 2462 MHz */         
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000},
    /* channel 12 - 2467 MHz */         
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000},
    /* channel 13 - 2472 MHz */         
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000},
    /* channel 14 - 2484 MHz */         
    {32, 0xBBB8, 0x4D8B, 0x0000, 32, 0x5C20, 0x4C94, 0x0000, 32, 0x5FE0, 0x4C94, 0x0000}
  }
};

struct programming_seq_t initialize_BB_RF_40Mhz_fr4 = {
 993,10,
{
   {  0x0, //BBP set 1
      120,
        0x0302,0x9FFB,//tx_on, rx_on = 0
        0x0303,0x4100,
        0x0000,0x001F,
        0x0001,0x0800,
        0x0002,0x3600,//powersave off
        0x0003,0x4000, 
        0x0004,0x0000,
        0x0005,0x0007,
        0x0006,0x0032,
        0x0007,0x4911,
        0x0008,0x0096,
        0x0009,0x000A,
        0x000A,0x0000,
        0x000D,0x8214,
        0x000E,0xA498,
        0x000F,0x6A37,
        0x0011,0x0080,
        0x0016,0x0059,
        0x0017,0x3941,
        0x0018,0x0E09,
        0x0019,0x4001,
        0x001A,0x9631,
        0x001B,0x4DDF,
        0x001D,0x00B7,
        0x001E,0x03E8,
        0x001F,0x03E8,
        0x0026,0x0080,
        0x0028,0x820E,
        0x0029,0x0030,
        0x002A,0x3420,
        0x0034,0x0C84,
        0x0035,0x0160,
        0x0036,0x0000,
        0x0037,0x0084,
        0x0038,0x7FE0,
        0x003A,0x0347,
        0x003B,0x8411,
        0x003F,0x1232,
        0x0040,0xE731,
        0x0041,0x006F,
        0x0042,0x0053,
        0x0043,0x80FA,
        0x0045,0x07E6,
        0x0046,0x0680,
        0x0047,0x2D6A,
        0x0048,0x2000,
        0x0049,0x0866,
        0x004B,0x1F63,//lna_settling_time[7:5]=7
        0x004E,0x95FC,
        0x0050,0xDCDC,
        0x0055,0x0594,
        0x0056,0x003B,
        0x0059,0x0037,
        0x005A,0x0037,
        0x005B,0x0037,
        0x005C,0x0000,
        0x005D,0x95C1,
        0x005E,0x0000,
        0x005F,0x0000,
        0x0060,0x0000
   },
   {0x01, 5, 80, //RF set 1
        32, 0xB000, 0x403F, 0x0000, 0,  //100
        32, 0xEE00, 0x5581, 0x0000, 0,  //101
        32, 0x9020, 0x55C0, 0x0000, 0,  //102
        32, 0x2220, 0x4CC0, 0x0000, 0,  //103
        32, 0x4000, 0x40A0, 0x0000, 0,  //104
        32, 0x0000, 0x4040, 0x0000, 0,  //105
        32, 0x0000, 0x40D6, 0x0000, 0,  //106
        //32, 0x4000, 0x417E, 0x0000, 0,  //107 //for Tz=3
        32, 0x4000, 0x4172, 0x0000, 0,  //107
        32, 0x0000, 0x4D35, 0x0000, 0,  //200
        32, 0x0820, 0x4C3F, 0x0000, 0,  //201
        32, 0xC410, 0x4D74, 0x0000, 0,  //202
        32, 0x0000, 0x4DE0, 0x0000, 0,  //203
        32, 0xD000, 0x4E2A, 0x0000, 0,  //204
        //32, 0x7774, 0x4D87, 0x0000, 0,  //Channel-2437
        //32, 0x5C20, 0x4C94, 0x0000, 0,  //Channel-2437
        //32, 0x5FE0, 0x4C94, 0x0000, 150 //Channel-2437
        //32, 0xBBB8, 0x4D8B, 0x0000, 0,  //Channel-2441
        //32, 0x5C20, 0x4C94, 0x0000, 0,  //Channel-2441
        //32, 0x5FE0, 0x4C94, 0x0000, 150	//Channel-2441
        //32, 0xEEEC, 0x4D8A, 0x0000, 0,  //Channel-2441-0.75
        //32, 0x5C20, 0x4C94, 0x0000, 0,  //Channel-2441-0.75
        //32, 0x5FE0, 0x4C94, 0x0000, 150 //Channel-2441-0.75
        //32, 0x4444, 0x4DB4, 0x0000, 0,  //Channel-2449
        //32, 0x9C20, 0x4C94, 0x0000, 0,  //Channel-2449
        //32, 0x9FE0, 0x4C94, 0x0000, 150 //Channel-2449
        32, 0x8888, 0x4DB4, 0x0000, 0,  //Channel-2450-0.75
        32, 0x9C20, 0x4C94, 0x0000, 0,  //Channel-2450-0.75 
        32, 0x9FE0, 0x4C94, 0x0000, 150 //Channel-2450-0.75
        //32, 0x3330, 0x4DBF, 0x0000, 0,  //Channel-2460-0.75
        //32, 0x9C20, 0x4C94, 0x0000, 0,  //Channel-2460-0.75
        //32, 0x9FE0, 0x4C94, 0x0000, 150 //Channel-2460-0.75
        //32, 0x1110, 0x4DB1, 0x0000, 0,  //Channel-2476 
        //32, 0xDC20, 0x4C94, 0x0000, 0,  //Channel-2476
        //32, 0xDFE0, 0x4C94, 0x0000, 150 //Channel-2476
        //32, 0x5554, 0x4DB1, 0x0000, 0,  //Channel-2477-0.75
        //32, 0xDC20, 0x4C94, 0x0000, 0,  //Channel-2477-0.75
        //32, 0xDFE0, 0x4C94, 0x0000, 150 //Channel-2477-0.75
        //32, 0xAAA8, 0x4D8A, 0x0000, 0,  // 2500MHz
        //32, 0xDC20, 0x4C94, 0x0000, 0,  // 2500MHz
        //32, 0xDFE0, 0x4C94, 0x0000, 150 // 2500MHz
        //32, 0x5554, 0x4DB5, 0x0000, 0,  //Channel-2480
        //32, 0xDC20, 0x4C94, 0x0000, 0,  //Channel-2480
        //32, 0xDFE0, 0x4C94, 0x0000, 150 //Channel-2480
        //32, 0x8888, 0x4DB4, 0x0000, 0,  //Channel-2480-0.75
        //32, 0xDC20, 0x4C94, 0x0000, 0,  //Channel-2480-0.75
        //32, 0xDFE0, 0x4C94, 0x0000, 150 //Channel-2480-0.75
   }, 
   {0x0,  //BBP set 2
      112,
        0x006E,0x0000,
        0x006F,0x0000,
        0x007B,0x0000,
        0x008D,0x0000,
        0x008E,0x0000,
        0x0097,0x24F0,
        0x0098,0x0000,
        0x0099,0x24F0,
        0x009A,0x0000,
        0x009B,0x24F0,
        0x009C,0x0000,
        0x009D,0x24F0,
        0x009E,0x0000,
        0x009F,0xED80,
        0x00A0,0xE000,
        0x00A1,0xED80,
        0x00A2,0x2000,
        0x00A3,0x24F0,
        0x00A4,0x0000,
        0x00A5,0xED80,
        0x00A6,0x2000,
        0x00A7,0xED80,
        0x00A8,0xE000,
        0x00A9,0x0000,
        0x00AA,0x000E,
        0x00AB,0x0860,
        0x00AC,0x0000,
        0x00AD,0x0000,
        0x00BE,0xFFFF,
        0x00BF,0x0000,
        0x00C0,0x0000,
        0x00C4,0x00B8,
        0x00C8,0x0000,
        0x0300,0x8333,
        0x0301,0x1240,//hpf_pd_path=0
        0x0304,0x0FF8,
        0x0305,0x00D8,
        0x0306,0x0777,
        0x0307,0x0333,
        0x0308,0x0049,
        0x0309,0x0000,
        0x030A,0x7BDE,
        0x030B,0x0200,
        0x030C,0x01FF,
        0x030D,0x0200,
        0x030E,0x01FF,
        0x030F,0x0000,
        0x0310,0x002A,
        0x0311,0x0000,
        0x0312,0x00D2,
        0x0313,0x0000,
        0x0314,0xE0CF,
        0x0315,0x0000,
        0x0316,0x0000,
        0x0317,0x0000,
        0x0318,0x0000
   },
   {0x01, 5, 90,  //RF set 2
        32, 0x0000, 0x4F40, 0x0000, 0,   //208
        32, 0x7000, 0x4EF5, 0x0000, 0,   //220
        32, 0x000C, 0x4F11, 0x0000, 0,   //221
        32, 0x8000, 0x483E, 0x0000, 0,   //300
        32, 0x0580, 0x4880, 0x0000, 0,   //301
        32, 0x0000, 0x5440, 0x0000, 0,   //302
        32, 0x0000, 0x5480, 0x0000, 0,   //303
        //32, 0x7BD0, 0x54C1, 0x0000, 0,   //304 //2.5MHz Cutoff
        32, 0xFFF0, 0x54C1, 0x0000, 0,   //304 //1.5MHz Cutoff
        32, 0x4C00, 0x5420, 0x0000, 0,   //305
        32, 0x4C00, 0x5420, 0x0000, 0,   //306
        32, 0x1400, 0x5420, 0x0000, 100, //307 //Manual //64 // tuner_mode = 0
        //32, 0x9400, 0x5411, 0x0000, 100, //307 //Manual //35 // tuner_mode = 0
        //32, 0x9400, 0x540C, 0x0000, 100, //307 //Manual //ok 25 //tuner_mode = 0
        //32, 0x1400, 0x5408, 0x0000, 100, //307 //Manual //ok 16 //tuner_mode = 0
        //32, 0x1400, 0x5404, 0x0000, 100, //307 //Manual //ok 8 //tuner_mode = 0
        //32, 0xD400, 0x5411, 0x0000, 100, //307 //Manual //35
        //32, 0xD400, 0x540C, 0x0000, 100, //307 //Manual //ok 25
        //32, 0x5400, 0x5408, 0x0000, 100, //307 //Manual //ok 16
        //32, 0x5400, 0x5404, 0x0000, 100, //307 //Manual //ok 8
        //32, 0x4400, 0x5420, 0x0000, 100, //307 //Auto
        32, 0x2120, 0x485E, 0x0000, 0,   //309
        32, 0x07C0, 0x5682, 0x0000, 0,   //400
        32, 0x0000, 0x447A, 0x0000, 0,   //401
        32, 0x0400, 0x4428, 0x0000, 0,   //402
        32, 0xC620, 0x44F0, 0x0000, 0,   //403
        32, 0x0000, 0x4530, 0x0000, 0,   //404
        32, 0xF800, 0x45C1, 0x0000, 0    //405
   },
   {0x0,  //BBP set 3
      116,
        0x0319,0x0100,
        0x031A,0x0000,
        0x031B,0x0000,
        0x031C,0x0000,
        0x031D,0x0100,
        0x031E,0x0000,
        0x031F,0x0000,
        0x0320,0x0000,
        0x0321,0x0000,
        0x0322,0x0000,
        0x0323,0x22C0,//dc_averaging_count_3step = 1, sat_detect_afe_sel = 0
        //0x0323,0x3AC0,//dc_averaging_count_3step = 1, sat_detect_afe_sel = 3
        //0x0323,0x32C0,//dc_averaging_count_3step = 1, sat_detect_afe_sel = 2
        //0x0323,0x12C0,//dc_averaging_count_3step = 0
        0x0324,0x0000,//prog_delayed_iq=0,dc_averaging_count=0,dc_tracking_enable=0
        0x0325,0x0000,
        0x0326,0x0100,
        0x0327,0x0000,
        0x0328,0x0000,
        0x0329,0x0000,
        0x032A,0x0100,
        0x032B,0x0000,
        0x032C,0x0100,
        0x032D,0x0000,
        0x032E,0x0000,
        0x032F,0x0000,
        0x0330,0x0100,
        0x0331,0x0000,
        0x033C,0x0000,
        0x0348,0x0000,
        0x0349,0x0000,
        0x034A,0x0000,
        0x034B,0x0000,
        0x034C,0x0000,
        0x034D,0x0000,
        0x034E,0x0000,
        0x034F,0x3020,
        0x0350,0x0000,
        0x0351,0x0000,
        0x0352,0x0000,
        0x0353,0x0000,
        0x0100,0x0000,
        0x0101,0x0000,
        0x0102,0x001C,
        0x0103,0x001C,
        0x0104,0x001C,
        0x0105,0x001C,
        0x0106,0x00AA,
        0x0107,0x0007,
        0x0108,0x002A,
        0x0109,0x0063,
        0x010A,0x001C,
        0x010B,0x001C,
        0x010C,0x001C,
        0x010D,0x0000,
        0x010E,0x0010,
        0x010F,0x00FF,
        0x0110,0x00FF,
        0x0111,0x2186,
        0x0112,0x060F,
        0x0113,0x00D0
   },
   {0x01, 5, 105,  //RF set 3
        32, 0x0820, 0x4C3F, 0x0000, 0,   //201
        32, 0x0580, 0x4880, 0x0000, 0,   //301
        32, 0x0800, 0x5622, 0x0000, 0,   //499
        32, 0x0880, 0x5622, 0x0000, 0,   //500
        32, 0x0480, 0x4894, 0x0000, 100, //502
        32, 0x0580, 0x4880, 0x0000, 0,   //301
        32, 0x2480, 0x4982, 0x0000, 0,   //501
        32, 0x0480, 0x4894, 0x0000, 1000, //502
        32, 0x0800, 0x4C3F, 0x0000, 0,   //511
        32, 0x9800, 0x503B, 0x0000, 0,   //601
        32, 0x8400, 0x5043, 0x0000, 0,   //602
        32, 0x0000, 0x5080, 0x0000, 0,   //603
        32, 0xB700, 0x50C0, 0x0000, 0,   //604
        32, 0x0280, 0x5121, 0x0000, 0,   //605
        32, 0x2120, 0x4878, 0x0000, 0,   //606
        32, 0x4000, 0x40A1, 0x0000, 0,   //700
        32, 0x0000, 0x483E, 0x0000, 0,   //701
        32, 0x0000, 0x4478, 0x0000, 0,   //702
        32, 0x8800, 0x503B, 0x0000, 0,   //703
        32, 0x7000, 0x4EF5, 0x0000, 0,   //707
        32, 0x0000, 0x41AE, 0x0000, 0    //TX_Gain //Old
        //32, 0xA000, 0x41BC, 0x0000, 0    //TX_Gain //DRV = 15, VGA = 5
        //32, 0xE000, 0x41BF, 0x0000, 0    //TX_Gain //DRV = 15, VGA = 31
   },
   {0x0,  //BBP set 4
      120,
        //0x0114,0x0818,//lock_out_threshold_low = 12
        0x0114,0x0810,//lock_out_threshold_low = 8
        0x0115,0x94AF,//lock_in_threshold_low_dec_last_steps = 5
        //0x0115,0x80AF,
        0x0116,0x1C00,
        0x0117,0x4800,
        0x0118,0x0000,
        0x011B,0x0000,
        0x011C,0x1818,
        //0x011C,0x1D1D,
        0x011D,0x0016,
        0x011E,0x0004,
        0x011F,0x0014,
        0x0120,0x1212,
        0x0121,0x0007,
        0x0122,0x0010,
        0x0124,0x00FA,
        0x0125,0x0050,
        0x0126,0x0024,
        0x0127,0x0018,
        0x0128,0x0058,
        0x0129,0x0004,
        0x012F,0x0000,
        0x0130,0x0001,
        0x0131,0x0002,
        0x0132,0x0003,
        0x0133,0x004B,
        0x0134,0x903C,
        0x013B,0x01B0,//averaging_selection=2
        0x0140,0x0004,
        0x0141,0x0005,
        0x0142,0x0006,
        0x0143,0x0007,
        0x0149,0x0118,
        0x014A,0x0026,
        0x014C,0x0003,
        0x014E,0x00CC,
        0x0150,0x11FD,
        0x015C,0x03D7,//enable_satdet_afe_search=1
        0x015D,0x0006,
        0x015E,0x5F0E,
        0x015F,0x5009,//averaging_selection_finetune=1
        0x0160,0x000E,
        0x0161,0x0194,
        0x0162,0x0136,
        0x0163,0x00E6,
        0x0164,0x4628,
        0x016E,0x00E4,
        0x016F,0x0000,
        0x0400,0x01F8,
        0x0412,0x0000,
        0x0413,0x00D2,
        0x0450,0x5128,
        0x0451,0x0000,
        0x0452,0x0000,
        0x0453,0x0000,
        0x0800,0x0004,
        0x0801,0x0000,
        0x0802,0x00C0,
        0x0803,0x00DD,
        0x0804,0x005F,
        0x0805,0x0000,
        0x0820,0x0000
   },
   //{0x01, 5, 85,  //RF set 4
   //     32, 0x2000, 0x6832, 0x0000, 0, //RF_LUT_0
   //     32, 0x3000, 0x6872, 0x0000, 0, //RF_LUT_1
   //     32, 0x4000, 0x68B2, 0x0000, 0, //RF_LUT_2
   //     32, 0x5000, 0x68F2, 0x0000, 0, //RF_LUT_3
   //     32, 0x6000, 0x6932, 0x0000, 0, //RF_LUT_4
   //     32, 0x4000, 0x6974, 0x0000, 0, //RF_LUT_5
   //     32, 0x5000, 0x69B4, 0x0000, 0, //RF_LUT_6
   //     32, 0x6000, 0x69F4, 0x0000, 0, //RF_LUT_7
   //     32, 0x4000, 0x6A36, 0x0000, 0, //RF_LUT_8
   //     32, 0x5000, 0x6A76, 0x0000, 0, //RF_LUT_9
   //     32, 0x6000, 0x6AB6, 0x0000, 0, //RF_LUT_10
   //     32, 0x4000, 0x6AF8, 0x0000, 0, //RF_LUT_11
   //     32, 0x5000, 0x6B38, 0x0000, 0, //RF_LUT_12
   //     32, 0x6000, 0x6B78, 0x0000, 0, //RF_LUT_13
   //     32, 0x7000, 0x6BB8, 0x0000, 0, //RF_LUT_14
   //     32, 0x8000, 0x6BF8, 0x0000, 0, //RF_LUT_15
   //     32, 0x9000, 0x6C38, 0x0000, 0  //RF_LUT_16
   //},
   //{0x01, 5, 80,  //RF set 5
   //     32, 0xA000, 0x6C78, 0x0000, 0, //RF_LUT_17
   //     32, 0xB000, 0x6CB8, 0x0000, 0, //RF_LUT_18
   //     32, 0xC000, 0x6CF8, 0x0000, 0, //RF_LUT_19
   //     32, 0xD000, 0x6D38, 0x0000, 0, //RF_LUT_20
   //     32, 0xE000, 0x6D78, 0x0000, 0, //RF_LUT_21
   //     32, 0xF000, 0x6DB8, 0x0000, 0, //RF_LUT_22
   //     32, 0x0000, 0x6DF9, 0x0000, 0, //RF_LUT_23
   //     32, 0x1000, 0x6E39, 0x0000, 0, //RF_LUT_24
   //     32, 0x2000, 0x6E79, 0x0000, 0, //RF_LUT_25
   //     32, 0x3000, 0x6EB9, 0x0000, 0, //RF_LUT_26
   //     32, 0x4000, 0x6EF9, 0x0000, 0, //RF_LUT_27
   //     32, 0x5000, 0x6F39, 0x0000, 0, //RF_LUT_28
   //     32, 0x6000, 0x6F79, 0x0000, 0, //RF_LUT_29
   //     32, 0x7000, 0x6FB9, 0x0000, 0, //RF_LUT_30
   //     32, 0x8000, 0x6FF9, 0x0000, 0, //RF_LUT_31
   //     32, 0x4000, 0x40A5, 0x0000, 0  //800
   //},
   {0x01, 5, 85,  //RF set 4
        32, 0x0000, 0x6802, 0x0000, 0, //RF_LUT_0
        32, 0x1000, 0x6842, 0x0000, 0, //RF_LUT_1
        32, 0x2000, 0x6882, 0x0000, 0, //RF_LUT_2
        32, 0x3000, 0x68C2, 0x0000, 0, //RF_LUT_3
        32, 0x4000, 0x6902, 0x0000, 0, //RF_LUT_4
        32, 0x2000, 0x6944, 0x0000, 0, //RF_LUT_5
        32, 0x3000, 0x6984, 0x0000, 0, //RF_LUT_6
        32, 0x4000, 0x69C4, 0x0000, 0, //RF_LUT_7
        32, 0x2000, 0x6A06, 0x0000, 0, //RF_LUT_8
        32, 0x3000, 0x6A46, 0x0000, 0, //RF_LUT_9
        32, 0x4000, 0x6A86, 0x0000, 0, //RF_LUT_10
        32, 0x2000, 0x6AC8, 0x0000, 0, //RF_LUT_11
        32, 0x3000, 0x6B08, 0x0000, 0, //RF_LUT_12
        32, 0x4000, 0x6B48, 0x0000, 0, //RF_LUT_13
        32, 0x5000, 0x6B88, 0x0000, 0, //RF_LUT_14
        32, 0x6000, 0x6BC8, 0x0000, 0, //RF_LUT_15
        32, 0x7000, 0x6C08, 0x0000, 0  //RF_LUT_16
   },
   {0x01, 5, 80,  //RF set 5
        32, 0x8000, 0x6C48, 0x0000, 0, //RF_LUT_17
        32, 0x9000, 0x6C88, 0x0000, 0, //RF_LUT_18
        32, 0xA000, 0x6CC8, 0x0000, 0, //RF_LUT_19
        32, 0xB000, 0x6D08, 0x0000, 0, //RF_LUT_20
        32, 0xC000, 0x6D48, 0x0000, 0, //RF_LUT_21
        32, 0xD000, 0x6D88, 0x0000, 0, //RF_LUT_22
        32, 0xE000, 0x6DC8, 0x0000, 0, //RF_LUT_23
        32, 0xF000, 0x6E08, 0x0000, 0, //RF_LUT_24
        32, 0x0000, 0x6E49, 0x0000, 0, //RF_LUT_25
        32, 0x1000, 0x6E89, 0x0000, 0, //RF_LUT_26
        32, 0x2000, 0x6EC9, 0x0000, 0, //RF_LUT_27
        32, 0x3000, 0x6F09, 0x0000, 0, //RF_LUT_28
        32, 0x4000, 0x6F49, 0x0000, 0, //RF_LUT_29
        32, 0x5000, 0x6F89, 0x0000, 0, //RF_LUT_30
        32, 0x6000, 0x6FC9, 0x0000, 0, //RF_LUT_31
        32, 0x4000, 0x40A5, 0x0000, 0  //800
   },
   {0x0,    //BBP set 5
      60,
        0x0C04,0xCA4C,
        0x0C05,0x0000,
        0x0C06,0x0680,
        0x0C07,0x0510,
        0x0C08,0x1101,
        0x0C20,0x0041,
        0x0C21,0x3654,
        0x0C22,0x0000,
        0x0C40,0x0000,
        //0x0C41,0xD292,//corr_thrshld = 18
        //0x0C41,0xD494,//corr_thrshld = 20
        0x0C41,0xD696,//corr_thrshld = 22
        //0x0C41,0xD898,//corr_thrshld = 24
        //0x0C41,0xE0A0,//corr_thrshld = 32
        //0x0C41,0xE4A4,//corr_thrshld = 36
        0x0C42,0x0001,
        0x0C43,0x0B00,
        0x0C44,0x0403,
        0x0C45,0x11ED,
        0x0C46,0xC46A,
        0x0C47,0x7158,
        0x0C48,0xAF28,
        0x0C49,0x0005,
        0x0C4A,0x0196,
        0x0C4B,0x0000,
        0x0002,0x0400,//powersave on
        0x0319,0x0100,//IQ Imbalance Values for Tx
        0x031A,0x0000,
        0x0322,0x0000,//IQ Imbalance Compensation Disable
        0x0302,0x9FF8,
        0x0303,0x4100,
        0x0301,0x0040,//U.FL Connector
        //0x0301,0x0060,//On-Chip Antenna
        0x0352,0x0008,//PA_DRV_LSB[3] = 1
        0x0059,0x00FF, //TX POWER
        0x034F,0x3D00 //tx_prog_en[5] = 0
        //0x034F,0x3D20 //tx_prog_en[5] = 1
   }
  }
};

//BBP is powered off and RF supply are present
//Note: Some SOC Registers have to be programmed to maintain the following signals to AFE/RF
// (1)  tx_on = 0
// (2)  rx_on = 0;
// (3)  adc_en = 0;
// (4)  dac_en = 0;
// (5)  aux_dac_en = 0;
// (6)  aux_adc_en = 0;
// (7)  aux_adc_sel = 0;
// (8)  gain0 = 0;
// (9)  dec8_1 = 0;
// (10) enctr0_1 = 0;
// (11) enctr1_1 = 0;
// (12) enctr2_1 = 0;
// (13) endiff_1 = 0;
// (14) envbg_1 = 0;
// (15) envrf_1 = 0;
// (16) envcm_1 = 0;
// (17) enib_1 = 0;
struct programming_seq_t RF_sleep_seq = {
  13,1,
  {
    {0x01, 5, 10,
        32, 0x1000, 0x4000, 0x0000, 0,
        32, 0x0000, 0x5580, 0x0000, 0
    }
  }
};

//BBP is powered up and RF supply are present (rf calibration is retained)
struct programming_seq_t RF_wakeup_seq_fr4 = {
  117,3,
  {
    {0x0, 96,
        0x0302,0x8FFB,//tx_on, rx_on = 0
        0x0303,0x4100,
        0x0002,0x3600,//powersave off
        0x0003,0x4000, 
        0x0005,0x0007,
        0x0017,0x3D51,//upper_lower_pd_var[0] = 1
        0x0018,0x0F09,//upper_lower_pd_var[0] = 1
        0x001B,0x4DDF,
        0x0029,0x0030,
        0x002A,0x3000,
        0x003A,0x0347,
        0x003B,0x8411,
        0x0040,0xE731,
        0x0041,0x006F,
        0x0042,0x0053,
        0x0045,0x07E6,
        0x0049,0x0866,
        0x0055,0x0594,
        0x0059,0x0037,
        0x00BE,0xFFFF,
        0x00BF,0x0000,
        0x00C4,0x00B8,
        0x0300,0x8333,
        0x0306,0x0777,//ADC enable = 3, DAC enable = 1
        0x0307,0x0333,//AUX DAC enable = 1, AUX ADC enable = 1, AUX ADC sel = 0
        0x0308,0x0049,//loopadc = 0,gain0 = 1,dec8 = 0
        0x0309,0x0000,//enctr0 = 0,enctr1 = 0,enctr2 = 0
        0x030A,0x7BDE,//endiff = 0,envbg = 1,envrf = 1,envcm = 1,enib = 1
        0x0311,0x0070,//hardware_afe_control=1
        0x0314,0xE0CF,
        0x034F,0x3CE0,
        0x0111,0x298A,
        0x0112,0x088C,
        0x0113,0x00C8,
        0x0114,0x0916,
        0x011B,0x0000,
        0x0125,0x0032,
        0x015E,0x5F0E,
        0x0162,0x0136,
        0x0163,0x00E6,
        0x0C07,0x0910,
        0x0C49,0x0005,
        0x0002,0x0400,//powersave on
        0x0319,0x0100,//IQ Imbalance Values for Tx
        0x031A,0x0000,
        0x0322,0x0000,//IQ Butterfly enable
        0x0301,0x0061,//ant_sel_ctrl = 3
        0x034F,0x3D80 //tx_prog_en = 0
    },	
    {0x01, 5, 10,
        32, 0xB000, 0x403F, 0x0000, 0,
        32, 0x5E00, 0x559D, 0x0000, 100
    },
    {0x0, 4,
        0x0302,0x8FF8,//tx_on, rx_on in RTL control
        0x0303,0x4100
    }	
  }
};

//BBP is logical powered off(Under soft reset and clock is gated) and RF supply are present
struct programming_seq_t RF_sleep_seq_logical = {
  31,2,
  {
    {0x0, 16,
        0x0306,0x0000,//ADC enable = 0, DAC enable = 0
        0x0307,0x0000,//AUX DAC enable = 0, AUX ADC enable = 0, AUX ADC sel = 0
        0x0308,0x0000,//loopadc = 0,gain0 = 0,dec8 = 0
        0x0309,0x0000,//enctr0 = 0,enctr1 = 0,enctr2 = 0
        0x030A,0x0000,//endiff = 0,envbg = 0,envrf = 0,envcm = 0,enib = 0
        0x0311,0x0000,//hardware_afe_control=0
        0x0302,0xFFFF,
        0x0303,0x0004
    },	
    {0x01, 5, 10,
        32, 0x1000, 0x4000, 0x0000, 0,
        32, 0x0000, 0x5580, 0x0000, 0
    }
  }
};

//BBP is logical powered up and RF supply are present (rf calibration is retained)
struct programming_seq_t RF_wakeup_seq_fr4_logical = {
  31,2,
  {
    {0x01, 5, 10,
        32, 0xB000, 0x403F, 0x0000, 0,
        32, 0x5E00, 0x559D, 0x0000, 100
    },
    {0x0, 16,
        0x0306,0x0777,//ADC enable = 3, DAC enable = 1
        0x0307,0x0333,//AUX DAC enable = 1, AUX ADC enable = 1, AUX ADC sel = 0
        0x0308,0x0049,//loopadc = 0,gain0 = 1,dec8 = 0
        0x0309,0x0000,//enctr0 = 0,enctr1 = 0,enctr2 = 0
        0x030A,0x7BDE,//endiff = 0,envbg = 1,envrf = 1,envcm = 1,enib = 1
        0x0311,0x0070,//hardware_afe_control=1
        0x0302,0x8FF8,//tx_on, rx_on in RTL control
        0x0303,0x4100
    }	
  }
};


struct programming_seq_t RF_power_val_set = {
  41,2,
  {
    /* MCS7 MCS6 MCS5 MCS4 MCS3 MCS2 MCS1 MCS0  54  48   36   24   18   12   11   9    6    5.5  2    1 */
    {0x53,0x53,0x57,0x5D,0x5D,0x5D,0x5D,0x5D,0x53,0x57,0x5D,0x5D,0x5D,0x5D,0x5D,0x5D,0x5D,0x5D,0x5D,0x5D},
    {0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x34,0x39,0x3E,0x3F,0x3D,0x3F,0x3F,0x3D,0x3D,0x3D}
  }
};

struct scan_programming_seq_t RF_channel_20mhz = {};
struct scan_programming_seq_t RF_channel_44mhz = {};
struct scan_programming_seq_t RF_channel_26mhz = {};
struct scan_programming_seq_t RF_channel_13mhz = {};
struct scan_programming_seq_t RF_channel_19p2mhz = {};
struct programming_seq_t initialize_BB_RF_20Mhz = {};
struct programming_seq_t initialize_BB_RF_20Mhz_fr4 = {};
struct programming_seq_t initialize_BB_RF_13Mhz = {};
struct programming_seq_t initialize_BB_RF_13Mhz_fr4 = {};
struct programming_seq_t initialize_BB_RF_26Mhz = {};
struct programming_seq_t initialize_BB_RF_26Mhz_fr4 = {};
struct programming_seq_t initialize_BB_RF_44Mhz = {};
struct programming_seq_t initialize_BB_RF_44Mhz_fr4 = {};
struct programming_seq_t initialize_BB_RF_19p2Mhz = {};
struct programming_seq_t initialize_BB_RF_19p2Mhz_fr4 = {};
struct programming_seq_t initialize_BB_RF_40Mhz = {};
struct programming_seq_t RF_wakeup_seq = {};

#endif
