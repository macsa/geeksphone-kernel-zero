/* Copyright (c) 2009, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#include "ov2659.h"


static const struct ov2659_i2c_reg_conf const init_tbl[] = {
    //800*600 30fps    
	{0x0103,0x01, BYTE_LEN, 0},
	{0x3000,0x0f, BYTE_LEN, 0},
	{0x3001,0xff, BYTE_LEN, 0},
	{0x3002,0xff, BYTE_LEN, 0},
	{0x0100,0x01, BYTE_LEN, 0},
	{0x3633,0x3d, BYTE_LEN, 0},
	{0x3620,0x02, BYTE_LEN, 0},
	{0x3631,0x11, BYTE_LEN, 0},
	{0x3612,0x04, BYTE_LEN, 0},
	{0x3630,0x20, BYTE_LEN, 0},
	{0x4702,0x02, BYTE_LEN, 0},
	{0x370c,0x34, BYTE_LEN, 0},
	{0x3004,0x10, BYTE_LEN, 0},
	{0x3005,0x18, BYTE_LEN, 0},
	{0x3800,0x00, BYTE_LEN, 0},
	{0x3801,0x00, BYTE_LEN, 0},
	{0x3802,0x00, BYTE_LEN, 0},
	{0x3803,0x00, BYTE_LEN, 0},
	{0x3804,0x06, BYTE_LEN, 0},
	{0x3805,0x5f, BYTE_LEN, 0},
	{0x3806,0x04, BYTE_LEN, 0},
	{0x3807,0xb7, BYTE_LEN, 0},
	{0x3808,0x03, BYTE_LEN, 0},
	{0x3809,0x20, BYTE_LEN, 0},
	{0x380a,0x02, BYTE_LEN, 0},
	{0x380b,0x58, BYTE_LEN, 0},
	{0x380c,0x05, BYTE_LEN, 0},
	{0x380d,0x14, BYTE_LEN, 0},
	{0x380e,0x02, BYTE_LEN, 0},
	{0x380f,0x68, BYTE_LEN, 0},
	{0x3811,0x08, BYTE_LEN, 0},
	{0x3813,0x02, BYTE_LEN, 0},
	{0x3814,0x31, BYTE_LEN, 0},
	{0x3815,0x31, BYTE_LEN, 0},
	{0x3a02,0x02, BYTE_LEN, 0},
	{0x3a03,0x68, BYTE_LEN, 0},
	{0x3a08,0x00, BYTE_LEN, 0},
	{0x3a09,0x5c, BYTE_LEN, 0},
	{0x3a0a,0x00, BYTE_LEN, 0},
	{0x3a0b,0x4d, BYTE_LEN, 0},
	{0x3a0d,0x08, BYTE_LEN, 0},
	{0x3a0e,0x06, BYTE_LEN, 0},
	{0x3a14,0x02, BYTE_LEN, 0},
	{0x3a15,0x28, BYTE_LEN, 0},
	{0x3623,0x00, BYTE_LEN, 0},
	{0x3634,0x76, BYTE_LEN, 0},
	{0x3701,0x44, BYTE_LEN, 0},
	{0x3702,0x18, BYTE_LEN, 0},
	{0x3703,0x24, BYTE_LEN, 0},
	{0x3704,0x24, BYTE_LEN, 0},
	{0x3705,0x0c, BYTE_LEN, 0},
	{0x3820,0x81, BYTE_LEN, 0},
	{0x3821,0x01, BYTE_LEN, 0},
	{0x370a,0x52, BYTE_LEN, 0},
	{0x4608,0x00, BYTE_LEN, 0},
	{0x4609,0x80, BYTE_LEN, 0},
	{0x4300,0x30, BYTE_LEN, 0},
	{0x5086,0x02, BYTE_LEN, 0},
	{0x5000,0xfb, BYTE_LEN, 0},
	{0x5001,0x1f, BYTE_LEN, 0},
	{0x5002,0x00, BYTE_LEN, 0},
	{0x5025,0x0e, BYTE_LEN, 0},
	{0x5026,0x18, BYTE_LEN, 0},
	{0x5027,0x34, BYTE_LEN, 0},
	{0x5028,0x4c, BYTE_LEN, 0},
	{0x5029,0x62, BYTE_LEN, 0},
	{0x502a,0x74, BYTE_LEN, 0},
	{0x502b,0x85, BYTE_LEN, 0},
	{0x502c,0x92, BYTE_LEN, 0},
	{0x502d,0x9e, BYTE_LEN, 0},
	{0x502e,0xb2, BYTE_LEN, 0},
	{0x502f,0xc0, BYTE_LEN, 0},
	{0x5030,0xcc, BYTE_LEN, 0},
	{0x5031,0xe0, BYTE_LEN, 0},
	{0x5032,0xee, BYTE_LEN, 0},
	{0x5033,0xf6, BYTE_LEN, 0},
	{0x5034,0x11, BYTE_LEN, 0},

	  
	{0x5070,0x1c, BYTE_LEN, 0},
	{0x5071,0x5b, BYTE_LEN, 0},
	{0x5072,0x05, BYTE_LEN, 0},
	{0x5073,0x20, BYTE_LEN, 0},
	{0x5074,0x94, BYTE_LEN, 0},
	{0x5075,0xb4, BYTE_LEN, 0},
	{0x5076,0xb4, BYTE_LEN, 0},
	{0x5077,0xaf, BYTE_LEN, 0},
	{0x5078,0x05, BYTE_LEN, 0},
	{0x5079,0x98, BYTE_LEN, 0},
	{0x507a,0x21, BYTE_LEN, 0}, 
	 
	 
	{0x5035,0x6a, BYTE_LEN, 0},
	{0x5036,0x11, BYTE_LEN, 0},
	{0x5037,0x92, BYTE_LEN, 0},
	{0x5038,0x21, BYTE_LEN, 0},
	{0x5039,0xe1, BYTE_LEN, 0},
	{0x503a,0x01, BYTE_LEN, 0},
	{0x503c,0x05, BYTE_LEN, 0},
	{0x503d,0x08, BYTE_LEN, 0},
	{0x503e,0x08, BYTE_LEN, 0},
	{0x503f,0x64, BYTE_LEN, 0},
	{0x5040,0x58, BYTE_LEN, 0},
	{0x5041,0x2a, BYTE_LEN, 0},
	{0x5042,0xc5, BYTE_LEN, 0},
	{0x5043,0x2e, BYTE_LEN, 0},
	{0x5044,0x3a, BYTE_LEN, 0},
	{0x5045,0x3c, BYTE_LEN, 0},
	{0x5046,0x44, BYTE_LEN, 0},
	{0x5047,0xf8, BYTE_LEN, 0},
	{0x5048,0x08, BYTE_LEN, 0},
	{0x5049,0x70, BYTE_LEN, 0},
	{0x504a,0xf0, BYTE_LEN, 0},
	{0x504b,0xf0, BYTE_LEN, 0},


	{0x500c,0x03, BYTE_LEN, 0},
	{0x500d,0x20, BYTE_LEN, 0},
	{0x500e,0x02, BYTE_LEN, 0},
	{0x500f,0x5c, BYTE_LEN, 0},
	{0x5010,0x48, BYTE_LEN, 0},
	{0x5011,0x00, BYTE_LEN, 0},
	{0x5012,0x66, BYTE_LEN, 0},
	{0x5013,0x03, BYTE_LEN, 0},
	{0x5014,0x30, BYTE_LEN, 0},
	{0x5015,0x02, BYTE_LEN, 0},
	{0x5016,0x7c, BYTE_LEN, 0},
	{0x5017,0x40, BYTE_LEN, 0},
	{0x5018,0x00, BYTE_LEN, 0},
	{0x5019,0x66, BYTE_LEN, 0},
	{0x501a,0x03, BYTE_LEN, 0},
	{0x501b,0x10, BYTE_LEN, 0},
	{0x501c,0x02, BYTE_LEN, 0},
	{0x501d,0x7c, BYTE_LEN, 0},
	{0x501e,0x3a, BYTE_LEN, 0},
	{0x501f,0x00, BYTE_LEN, 0},
	{0x5020,0x66, BYTE_LEN, 0},
	{0x506e,0x44, BYTE_LEN, 0},
	{0x5064,0x08, BYTE_LEN, 0},
	{0x5065,0x10, BYTE_LEN, 0},
	{0x5066,0x12, BYTE_LEN, 0},
	{0x5067,0x02, BYTE_LEN, 0},
	{0x506c,0x08, BYTE_LEN, 0},
	{0x506d,0x10, BYTE_LEN, 0},
	{0x506f,0xa6, BYTE_LEN, 0},
	{0x5068,0x08, BYTE_LEN, 0},
	{0x5069,0x10, BYTE_LEN, 0},
	{0x506a,0x04, BYTE_LEN, 0},
	{0x506b,0x12, BYTE_LEN, 0},
	{0x507e,0x50, BYTE_LEN, 0},
	{0x507f,0x50, BYTE_LEN, 0},
	{0x507b,0x02, BYTE_LEN, 0},
	{0x507a,0x01, BYTE_LEN, 0},
	{0x5084,0x0c, BYTE_LEN, 0},
	{0x5085,0x3e, BYTE_LEN, 0},
	{0x5005,0x80, BYTE_LEN, 0},

	{0x3a0f,0x30, BYTE_LEN, 0},
	{0x3a10,0x28, BYTE_LEN, 0},
	{0x3a1b,0x32, BYTE_LEN, 0},
	{0x3a1e,0x26, BYTE_LEN, 0},

	{0x3a11,0x60, BYTE_LEN, 0},
	{0x3a1f,0x14, BYTE_LEN, 0},

	{0x5060,0x69, BYTE_LEN, 0},
	{0x5061,0x7d, BYTE_LEN, 0},
	{0x5062,0x7d, BYTE_LEN, 0},
	{0x5063,0x69, BYTE_LEN, 0},

	//{0x3003,0x80, BYTE_LEN, 0},
	//{0x3004,0x10, BYTE_LEN, 0},
	//{0x3005,0x18, BYTE_LEN, 0},
	//{0x3006,0x0d, BYTE_LEN, 0},


	{0x3a19,0x38, BYTE_LEN, 0},
	{0x4009,0x06, BYTE_LEN, 0},
	{0x5025,0xc , BYTE_LEN, 0},
	{0x5026,0x18, BYTE_LEN, 0},
	{0x5027,0x30, BYTE_LEN, 0},
	{0x5028,0x47, BYTE_LEN, 0},
	{0x5029,0x59, BYTE_LEN, 0},
	{0x502a,0x69, BYTE_LEN, 0},
	{0x502b,0x76, BYTE_LEN, 0},
	{0x502c,0x7f, BYTE_LEN, 0},
	{0x502d,0x89, BYTE_LEN, 0},
	{0x502e,0x98, BYTE_LEN, 0},
	{0x502f,0xa6, BYTE_LEN, 0},
	{0x5030,0xb3, BYTE_LEN, 0},
	{0x5031,0xc8, BYTE_LEN, 0},
	{0x5032,0xd9, BYTE_LEN, 0},
	{0x5033,0xea, BYTE_LEN, 0},
	{0x5034,0x1d, BYTE_LEN, 0},

	{0x5035,0x6a,BYTE_LEN, 0},
	{0x5036,0x11,BYTE_LEN, 0},
	{0x5037,0x92,BYTE_LEN, 0},
	{0x5038,0x21,BYTE_LEN, 0},
	{0x5039,0xe1,BYTE_LEN, 0},
	{0x503a,0x01,BYTE_LEN, 0},
	{0x503c,0x05,BYTE_LEN, 0},
	{0x503d,0x08,BYTE_LEN, 0},
	{0x503e,0x08,BYTE_LEN, 0},
	{0x503f,0x64,BYTE_LEN, 0},
	{0x5040,0x58,BYTE_LEN, 0},
	{0x5041,0x2a,BYTE_LEN, 0},
	{0x5042,0xc5,BYTE_LEN, 0},
	{0x5043,0x2e,BYTE_LEN, 0},
	{0x5044,0x3a,BYTE_LEN, 0},
	{0x5045,0x3c,BYTE_LEN, 0},
	{0x5046,0x44,BYTE_LEN, 0},
	{0x5047,0xf8,BYTE_LEN, 0},
	{0x5048,0x08,BYTE_LEN, 0},
	{0x5049,0x70,BYTE_LEN, 0},
	{0x504a,0xf0,BYTE_LEN, 0},
	{0x504b,0xf0,BYTE_LEN, 0},
	    
	{0x506e,0x00,BYTE_LEN, 0},
	{0x5064,0x08,BYTE_LEN, 0},
	{0x5065,0x10,BYTE_LEN, 0},
	{0x5066,0x12,BYTE_LEN, 0},
	{0x5067,0x02,BYTE_LEN, 0},
	{0x506c,0x08,BYTE_LEN, 0},
	{0x506d,0x10,BYTE_LEN, 0},
	{0x506e,0x46,BYTE_LEN, 0}, 
	{0x506f,0x1f,BYTE_LEN, 0}, 
	           
	    
	{0x5000,0xfb,BYTE_LEN, 0},
	{0x500c,0x03,BYTE_LEN, 0},
	{0x500d,0x20,BYTE_LEN, 0},
	{0x500e,0x02,BYTE_LEN, 0},
	{0x500f,0x78,BYTE_LEN, 0},
	{0x5010,0x2e,BYTE_LEN, 0},
	{0x5011,0x00,BYTE_LEN, 0},
	{0x5012,0x66,BYTE_LEN, 0},
	{0x5013,0x03,BYTE_LEN, 0},
	{0x5014,0x30,BYTE_LEN, 0},
	{0x5015,0x02,BYTE_LEN, 0},
	{0x5016,0x7c,BYTE_LEN, 0},
	{0x5017,0x28,BYTE_LEN, 0},
	{0x5018,0x00,BYTE_LEN, 0},
	{0x5019,0x66,BYTE_LEN, 0},
	{0x501a,0x03,BYTE_LEN, 0},
	{0x501b,0x10,BYTE_LEN, 0},
	{0x501c,0x02,BYTE_LEN, 0},
	{0x501d,0x7c,BYTE_LEN, 0},
	{0x501e,0x25,BYTE_LEN, 0},
	{0x501f,0x00,BYTE_LEN, 0},
	{0x5020,0x66,BYTE_LEN, 0},
	    
	    
	{0x5000,0xfb,BYTE_LEN, 0},
	{0x500c,0x03,BYTE_LEN, 0}, 
	{0x500d,0x20,BYTE_LEN, 0},
	{0x500e,0x02,BYTE_LEN, 0},
	{0x500f,0x68,BYTE_LEN, 0},
	{0x5010,0x58,BYTE_LEN, 0},
	{0x5011,0x00,BYTE_LEN, 0},
	{0x5012,0x66,BYTE_LEN, 0},
	    
	    
	{0x5013,0x03,BYTE_LEN, 0},
	{0x5014,0x30,BYTE_LEN, 0},
	{0x5015,0x02,BYTE_LEN, 0},
	{0x5016,0x60,BYTE_LEN, 0},
	{0x5017,0x50,BYTE_LEN, 0},
	{0x5018,0x00,BYTE_LEN, 0},
	{0x5019,0x66,BYTE_LEN, 0},
	    
	    
	    
	{0x501a,0x03,BYTE_LEN, 0},
	{0x501b,0x10,BYTE_LEN, 0},
	{0x501c,0x02,BYTE_LEN, 0},
	{0x501d,0x68,BYTE_LEN, 0},
	{0x501e,0x4a,BYTE_LEN, 0},
	{0x501f,0x00,BYTE_LEN, 0},
	{0x5020,0x66,BYTE_LEN, 0},
	    
	{0x5025,0xc ,BYTE_LEN, 0},
	{0x5027,0x30,BYTE_LEN, 0}, 
	{0x5028,0x47,BYTE_LEN, 0}, 
	{0x5029,0x59,BYTE_LEN, 0}, 
	{0x502a,0x69,BYTE_LEN, 0}, 
	{0x502b,0x76,BYTE_LEN, 0}, 
	{0x502c,0x7f,BYTE_LEN, 0}, 
	{0x502d,0x89,BYTE_LEN, 0}, 
	{0x502e,0x98,BYTE_LEN, 0}, 
	{0x502f,0xa6,BYTE_LEN, 0}, 
	{0x5030,0xb3,BYTE_LEN, 0}, 
	{0x5031,0xc8,BYTE_LEN, 0}, 
	{0x5032,0xd9,BYTE_LEN, 0}, 
	{0x5033,0xea,BYTE_LEN, 0}, 
	{0x5034,0x1d,BYTE_LEN, 0},
	    
	    
	{0x5035,0x6a,BYTE_LEN, 0},  
	{0x5036,0x11,BYTE_LEN, 0},  
	{0x5037,0x92,BYTE_LEN, 0},  
	{0x5038,0x21,BYTE_LEN, 0},  
	{0x5039,0xe1,BYTE_LEN, 0},  
	{0x503a,0x01,BYTE_LEN, 0},  
	{0x503c,0x05,BYTE_LEN, 0},  
	{0x503d,0x08,BYTE_LEN, 0},  
	{0x503e,0x08,BYTE_LEN, 0},  
	{0x503f,0x64,BYTE_LEN, 0},  
	{0x5040,0x58,BYTE_LEN, 0},  
	{0x5041,0x2a,BYTE_LEN, 0},  
	{0x5042,0xc5,BYTE_LEN, 0},  
	{0x5043,0x2e,BYTE_LEN, 0},  
	{0x5044,0x3a,BYTE_LEN, 0},  
	{0x5045,0x3c,BYTE_LEN, 0},  
	{0x5046,0x44,BYTE_LEN, 0},  
	{0x5047,0xf8,BYTE_LEN, 0},  
	{0x5048,0x08,BYTE_LEN, 0},  
	{0x5049,0x70,BYTE_LEN, 0},  
	{0x504a,0xf0,BYTE_LEN, 0},  
	{0x504b,0xf0,BYTE_LEN, 0}, 
/*
	{0x5001,0x1f,BYTE_LEN, 0},
	{0x507b,0x02,BYTE_LEN, 0},	
    {0x507e,0x40,BYTE_LEN, 0},    
	{0x4300,0x32,BYTE_LEN, 0},//add
    {0x507f,0x40,BYTE_LEN, 0},  //50-48
    {0x3406,0x00,BYTE_LEN, 0}  //50-48
  */  
};  
    
static const struct ov2659_i2c_reg_conf const preview_tbl[] = {
    //800*600 30fps    
	{0x0103,0x01, BYTE_LEN, 0},
	{0x3000,0x0f, BYTE_LEN, 0},
	{0x3001,0xff, BYTE_LEN, 0},
	{0x3002,0xff, BYTE_LEN, 0},
	{0x0100,0x01, BYTE_LEN, 0},
	{0x3633,0x3d, BYTE_LEN, 0},
	{0x3620,0x02, BYTE_LEN, 0},
	{0x3631,0x11, BYTE_LEN, 0},
	{0x3612,0x04, BYTE_LEN, 0},
	{0x3630,0x20, BYTE_LEN, 0},
	{0x4702,0x02, BYTE_LEN, 0},
	{0x370c,0x34, BYTE_LEN, 0},
	{0x3004,0x10, BYTE_LEN, 0},
	{0x3005,0x18, BYTE_LEN, 0},
	{0x3800,0x00, BYTE_LEN, 0},
	{0x3801,0x00, BYTE_LEN, 0},
	{0x3802,0x00, BYTE_LEN, 0},
	{0x3803,0x00, BYTE_LEN, 0},
	{0x3804,0x06, BYTE_LEN, 0},
	{0x3805,0x5f, BYTE_LEN, 0},
	{0x3806,0x04, BYTE_LEN, 0},
	{0x3807,0xb7, BYTE_LEN, 0},
	{0x3808,0x03, BYTE_LEN, 0},
	{0x3809,0x20, BYTE_LEN, 0},
	{0x380a,0x02, BYTE_LEN, 0},
	{0x380b,0x58, BYTE_LEN, 0},
	{0x380c,0x05, BYTE_LEN, 0},
	{0x380d,0x14, BYTE_LEN, 0},
	{0x380e,0x02, BYTE_LEN, 0},
	{0x380f,0x68, BYTE_LEN, 0},
	{0x3811,0x08, BYTE_LEN, 0},
	{0x3813,0x02, BYTE_LEN, 0},
	{0x3814,0x31, BYTE_LEN, 0},
	{0x3815,0x31, BYTE_LEN, 0},
	{0x3a02,0x02, BYTE_LEN, 0},
	{0x3a03,0x68, BYTE_LEN, 0},
	{0x3a08,0x00, BYTE_LEN, 0},
	{0x3a09,0x5c, BYTE_LEN, 0},
	{0x3a0a,0x00, BYTE_LEN, 0},
	{0x3a0b,0x4d, BYTE_LEN, 0},
	{0x3a0d,0x08, BYTE_LEN, 0},
	{0x3a0e,0x06, BYTE_LEN, 0},
	{0x3a14,0x02, BYTE_LEN, 0},
	{0x3a15,0x28, BYTE_LEN, 0},
	{0x3623,0x00, BYTE_LEN, 0},
	{0x3634,0x76, BYTE_LEN, 0},
	{0x3701,0x44, BYTE_LEN, 0},
	{0x3702,0x18, BYTE_LEN, 0},
	{0x3703,0x24, BYTE_LEN, 0},
	{0x3704,0x24, BYTE_LEN, 0},
	{0x3705,0x0c, BYTE_LEN, 0},
	{0x3820,0x81, BYTE_LEN, 0},
	{0x3821,0x01, BYTE_LEN, 0},
	{0x370a,0x52, BYTE_LEN, 0},
	{0x4608,0x00, BYTE_LEN, 0},
	{0x4609,0x80, BYTE_LEN, 0},
	{0x4300,0x32, BYTE_LEN, 0},
	{0x5086,0x02, BYTE_LEN, 0},
	{0x5000,0xfb, BYTE_LEN, 0},
	//{0x5001,0x1f, BYTE_LEN, 0},
	{0x5002,0x00, BYTE_LEN, 0},
	{0x5025,0x0e, BYTE_LEN, 0},
	{0x5026,0x18, BYTE_LEN, 0},
	{0x5027,0x34, BYTE_LEN, 0},
	{0x5028,0x4c, BYTE_LEN, 0},
	{0x5029,0x62, BYTE_LEN, 0},
	{0x502a,0x74, BYTE_LEN, 0},
	{0x502b,0x85, BYTE_LEN, 0},
	{0x502c,0x92, BYTE_LEN, 0},
	{0x502d,0x9e, BYTE_LEN, 0},
	{0x502e,0xb2, BYTE_LEN, 0},
	{0x502f,0xc0, BYTE_LEN, 0},
	{0x5030,0xcc, BYTE_LEN, 0},
	{0x5031,0xe0, BYTE_LEN, 0},
	{0x5032,0xee, BYTE_LEN, 0},
	{0x5033,0xf6, BYTE_LEN, 0},
	{0x5034,0x11, BYTE_LEN, 0},

	  
	{0x5070,0x1c, BYTE_LEN, 0},
	{0x5071,0x5b, BYTE_LEN, 0},
	{0x5072,0x05, BYTE_LEN, 0},
	{0x5073,0x20, BYTE_LEN, 0},
	{0x5074,0x94, BYTE_LEN, 0},
	{0x5075,0xb4, BYTE_LEN, 0},
	{0x5076,0xb4, BYTE_LEN, 0},
	{0x5077,0xaf, BYTE_LEN, 0},
	{0x5078,0x05, BYTE_LEN, 0},
	{0x5079,0x98, BYTE_LEN, 0},
	{0x507a,0x21, BYTE_LEN, 0}, 
	 
	 
	{0x5035,0x6a, BYTE_LEN, 0},
	{0x5036,0x11, BYTE_LEN, 0},
	{0x5037,0x92, BYTE_LEN, 0},
	{0x5038,0x21, BYTE_LEN, 0},
	{0x5039,0xe1, BYTE_LEN, 0},
	{0x503a,0x01, BYTE_LEN, 0},
	{0x503c,0x05, BYTE_LEN, 0},
	{0x503d,0x08, BYTE_LEN, 0},
	{0x503e,0x08, BYTE_LEN, 0},
	{0x503f,0x64, BYTE_LEN, 0},
	{0x5040,0x58, BYTE_LEN, 0},
	{0x5041,0x2a, BYTE_LEN, 0},
	{0x5042,0xc5, BYTE_LEN, 0},
	{0x5043,0x2e, BYTE_LEN, 0},
	{0x5044,0x3a, BYTE_LEN, 0},
	{0x5045,0x3c, BYTE_LEN, 0},
	{0x5046,0x44, BYTE_LEN, 0},
	{0x5047,0xf8, BYTE_LEN, 0},
	{0x5048,0x08, BYTE_LEN, 0},
	{0x5049,0x70, BYTE_LEN, 0},
	{0x504a,0xf0, BYTE_LEN, 0},
	{0x504b,0xf0, BYTE_LEN, 0},


	{0x500c,0x03, BYTE_LEN, 0},
	{0x500d,0x20, BYTE_LEN, 0},
	{0x500e,0x02, BYTE_LEN, 0},
	{0x500f,0x5c, BYTE_LEN, 0},
	{0x5010,0x48, BYTE_LEN, 0},
	{0x5011,0x00, BYTE_LEN, 0},
	{0x5012,0x66, BYTE_LEN, 0},
	{0x5013,0x03, BYTE_LEN, 0},
	{0x5014,0x30, BYTE_LEN, 0},
	{0x5015,0x02, BYTE_LEN, 0},
	{0x5016,0x7c, BYTE_LEN, 0},
	{0x5017,0x40, BYTE_LEN, 0},
	{0x5018,0x00, BYTE_LEN, 0},
	{0x5019,0x66, BYTE_LEN, 0},
	{0x501a,0x03, BYTE_LEN, 0},
	{0x501b,0x10, BYTE_LEN, 0},
	{0x501c,0x02, BYTE_LEN, 0},
	{0x501d,0x7c, BYTE_LEN, 0},
	{0x501e,0x3a, BYTE_LEN, 0},
	{0x501f,0x00, BYTE_LEN, 0},
	{0x5020,0x66, BYTE_LEN, 0},
	{0x506e,0x44, BYTE_LEN, 0},
	{0x5064,0x08, BYTE_LEN, 0},
	{0x5065,0x10, BYTE_LEN, 0},
	{0x5066,0x12, BYTE_LEN, 0},
	{0x5067,0x02, BYTE_LEN, 0},
	{0x506c,0x08, BYTE_LEN, 0},
	{0x506d,0x10, BYTE_LEN, 0},
	{0x506f,0xa6, BYTE_LEN, 0},
	{0x5068,0x08, BYTE_LEN, 0},
	{0x5069,0x10, BYTE_LEN, 0},
	{0x506a,0x04, BYTE_LEN, 0},
	{0x506b,0x12, BYTE_LEN, 0},
	//x507e,0x50, BYTE_LEN, 0},
	//x507f,0x50, BYTE_LEN, 0},
	//0x507b,0x02, BYTE_LEN, 0},
	{0x507a,0x01, BYTE_LEN, 0},
	{0x5084,0x0c, BYTE_LEN, 0},
	{0x5085,0x3e, BYTE_LEN, 0},
	{0x5005,0x80, BYTE_LEN, 0},

	{0x3a0f,0x30, BYTE_LEN, 0},
	{0x3a10,0x28, BYTE_LEN, 0},
	{0x3a1b,0x32, BYTE_LEN, 0},
	{0x3a1e,0x26, BYTE_LEN, 0},

	{0x3a11,0x60, BYTE_LEN, 0},
	{0x3a1f,0x14, BYTE_LEN, 0},

	{0x5060,0x69, BYTE_LEN, 0},
	{0x5061,0x7d, BYTE_LEN, 0},
	{0x5062,0x7d, BYTE_LEN, 0},
	{0x5063,0x69, BYTE_LEN, 0},

	//{0x3003,0x80, BYTE_LEN, 0},
	//{0x3004,0x10, BYTE_LEN, 0},
	//{0x3005,0x18, BYTE_LEN, 0},
	//{0x3006,0x0d, BYTE_LEN, 0},


	{0x3a19,0x38, BYTE_LEN, 0},
	{0x4009,0x06, BYTE_LEN, 0},
	{0x5025,0xc , BYTE_LEN, 0},
	{0x5026,0x18, BYTE_LEN, 0},
	{0x5027,0x30, BYTE_LEN, 0},
	{0x5028,0x47, BYTE_LEN, 0},
	{0x5029,0x59, BYTE_LEN, 0},
	{0x502a,0x69, BYTE_LEN, 0},
	{0x502b,0x76, BYTE_LEN, 0},
	{0x502c,0x7f, BYTE_LEN, 0},
	{0x502d,0x89, BYTE_LEN, 0},
	{0x502e,0x98, BYTE_LEN, 0},
	{0x502f,0xa6, BYTE_LEN, 0},
	{0x5030,0xb3, BYTE_LEN, 0},
	{0x5031,0xc8, BYTE_LEN, 0},
	{0x5032,0xd9, BYTE_LEN, 0},
	{0x5033,0xea, BYTE_LEN, 0},
	{0x5034,0x1d, BYTE_LEN, 0},

	{0x5035,0x6a,BYTE_LEN, 0},
	{0x5036,0x11,BYTE_LEN, 0},
	{0x5037,0x92,BYTE_LEN, 0},
	{0x5038,0x21,BYTE_LEN, 0},
	{0x5039,0xe1,BYTE_LEN, 0},
	{0x503a,0x01,BYTE_LEN, 0},
	{0x503c,0x05,BYTE_LEN, 0},
	{0x503d,0x08,BYTE_LEN, 0},
	{0x503e,0x08,BYTE_LEN, 0},
	{0x503f,0x64,BYTE_LEN, 0},
	{0x5040,0x58,BYTE_LEN, 0},
	{0x5041,0x2a,BYTE_LEN, 0},
	{0x5042,0xc5,BYTE_LEN, 0},
	{0x5043,0x2e,BYTE_LEN, 0},
	{0x5044,0x3a,BYTE_LEN, 0},
	{0x5045,0x3c,BYTE_LEN, 0},
	{0x5046,0x44,BYTE_LEN, 0},
	{0x5047,0xf8,BYTE_LEN, 0},
	{0x5048,0x08,BYTE_LEN, 0},
	{0x5049,0x70,BYTE_LEN, 0},
	{0x504a,0xf0,BYTE_LEN, 0},
	{0x504b,0xf0,BYTE_LEN, 0},
	    
	{0x506e,0x00,BYTE_LEN, 0},
	{0x5064,0x08,BYTE_LEN, 0},
	{0x5065,0x10,BYTE_LEN, 0},
	{0x5066,0x12,BYTE_LEN, 0},
	{0x5067,0x02,BYTE_LEN, 0},
	{0x506c,0x08,BYTE_LEN, 0},
	{0x506d,0x10,BYTE_LEN, 0},
	{0x506e,0x46,BYTE_LEN, 0}, 
	{0x506f,0x1f,BYTE_LEN, 0}, 
	           
	    
	{0x5000,0xfb,BYTE_LEN, 0},
	{0x500c,0x03,BYTE_LEN, 0},
	{0x500d,0x20,BYTE_LEN, 0},
	{0x500e,0x02,BYTE_LEN, 0},
	{0x500f,0x78,BYTE_LEN, 0},
	{0x5010,0x2e,BYTE_LEN, 0},
	{0x5011,0x00,BYTE_LEN, 0},
	{0x5012,0x66,BYTE_LEN, 0},
	{0x5013,0x03,BYTE_LEN, 0},
	{0x5014,0x30,BYTE_LEN, 0},
	{0x5015,0x02,BYTE_LEN, 0},
	{0x5016,0x7c,BYTE_LEN, 0},
	{0x5017,0x28,BYTE_LEN, 0},
	{0x5018,0x00,BYTE_LEN, 0},
	{0x5019,0x66,BYTE_LEN, 0},
	{0x501a,0x03,BYTE_LEN, 0},
	{0x501b,0x10,BYTE_LEN, 0},
	{0x501c,0x02,BYTE_LEN, 0},
	{0x501d,0x7c,BYTE_LEN, 0},
	{0x501e,0x25,BYTE_LEN, 0},
	{0x501f,0x00,BYTE_LEN, 0},
	{0x5020,0x66,BYTE_LEN, 0},
	    
	    
	{0x5000,0xfb,BYTE_LEN, 0},
	{0x500c,0x03,BYTE_LEN, 0}, 
	{0x500d,0x20,BYTE_LEN, 0},
	{0x500e,0x02,BYTE_LEN, 0},
	{0x500f,0x68,BYTE_LEN, 0},
	{0x5010,0x58,BYTE_LEN, 0},
	{0x5011,0x00,BYTE_LEN, 0},
	{0x5012,0x66,BYTE_LEN, 0},
	    
	    
	{0x5013,0x03,BYTE_LEN, 0},
	{0x5014,0x30,BYTE_LEN, 0},
	{0x5015,0x02,BYTE_LEN, 0},
	{0x5016,0x60,BYTE_LEN, 0},
	{0x5017,0x50,BYTE_LEN, 0},
	{0x5018,0x00,BYTE_LEN, 0},
	{0x5019,0x66,BYTE_LEN, 0},
	    
	    
	    
	{0x501a,0x03,BYTE_LEN, 0},
	{0x501b,0x10,BYTE_LEN, 0},
	{0x501c,0x02,BYTE_LEN, 0},
	{0x501d,0x68,BYTE_LEN, 0},
	{0x501e,0x4a,BYTE_LEN, 0},
	{0x501f,0x00,BYTE_LEN, 0},
	{0x5020,0x66,BYTE_LEN, 0},
	    
	{0x5025,0xc ,BYTE_LEN, 0},
	{0x5027,0x30,BYTE_LEN, 0}, 
	{0x5028,0x47,BYTE_LEN, 0}, 
	{0x5029,0x59,BYTE_LEN, 0}, 
	{0x502a,0x69,BYTE_LEN, 0}, 
	{0x502b,0x76,BYTE_LEN, 0}, 
	{0x502c,0x7f,BYTE_LEN, 0}, 
	{0x502d,0x89,BYTE_LEN, 0}, 
	{0x502e,0x98,BYTE_LEN, 0}, 
	{0x502f,0xa6,BYTE_LEN, 0}, 
	{0x5030,0xb3,BYTE_LEN, 0}, 
	{0x5031,0xc8,BYTE_LEN, 0}, 
	{0x5032,0xd9,BYTE_LEN, 0}, 
	{0x5033,0xea,BYTE_LEN, 0}, 
	{0x5034,0x1d,BYTE_LEN, 0},
	    
	    
	{0x5035,0x6a,BYTE_LEN, 0},  
	{0x5036,0x11,BYTE_LEN, 0},  
	{0x5037,0x92,BYTE_LEN, 0},  
	{0x5038,0x21,BYTE_LEN, 0},  
	{0x5039,0xe1,BYTE_LEN, 0},  
	{0x503a,0x01,BYTE_LEN, 0},  
	{0x503c,0x05,BYTE_LEN, 0},  
	{0x503d,0x08,BYTE_LEN, 0},  
	{0x503e,0x08,BYTE_LEN, 0},  
	{0x503f,0x64,BYTE_LEN, 0},  
	{0x5040,0x58,BYTE_LEN, 0},  
	{0x5041,0x2a,BYTE_LEN, 0},  
	{0x5042,0xc5,BYTE_LEN, 0},  
	{0x5043,0x2e,BYTE_LEN, 0},  
	{0x5044,0x3a,BYTE_LEN, 0},  
	{0x5045,0x3c,BYTE_LEN, 0},  
	{0x5046,0x44,BYTE_LEN, 0},  
	{0x5047,0xf8,BYTE_LEN, 0},  
	{0x5048,0x08,BYTE_LEN, 0},  
	{0x5049,0x70,BYTE_LEN, 0},  
	{0x504a,0xf0,BYTE_LEN, 0},  
	{0x504b,0xf0,BYTE_LEN, 0}, 
    

///////////////////////////////////////////////////////
	 {0x3005,0x18,BYTE_LEN, 0},
	 {0x3807,0xb7,BYTE_LEN, 0},
	 {0x3808,0x03,BYTE_LEN, 0},
	 {0x3809,0x20,BYTE_LEN, 0},
	 {0x380a,0x02,BYTE_LEN, 0},
	 {0x380b,0x58,BYTE_LEN, 0},
	 {0x380c,0x05,BYTE_LEN, 0},
	 {0x380d,0x14,BYTE_LEN, 0},
	 {0x380e,0x02,BYTE_LEN, 0},
	 {0x380f,0x68,BYTE_LEN, 0},
	 {0x3811,0x08,BYTE_LEN, 0},
	 {0x3813,0x02,BYTE_LEN, 0},
	 {0x3814,0x31,BYTE_LEN, 0},
	 {0x3815,0x31,BYTE_LEN, 0},
	 {0x3a02,0x02,BYTE_LEN, 0},
	 {0x3a03,0x68,BYTE_LEN, 0},
	 {0x3a09,0x5c,BYTE_LEN, 0},
	 {0x3a0b,0x4d,BYTE_LEN, 0},
	 {0x3a14,0x02,BYTE_LEN, 0},
	 {0x3a15,0x28,BYTE_LEN, 0},
	 {0x3634,0x76,BYTE_LEN, 0},
	 {0x3702,0x18,BYTE_LEN, 0},
 	 {0x3703,0x24,BYTE_LEN, 0},
	 {0x3704,0x24,BYTE_LEN, 0},
	 {0x3705,0x0c,BYTE_LEN, 0},
	 {0x3820,0x81,BYTE_LEN, 0},
	 {0x3821,0x01,BYTE_LEN, 0},
	 {0x370a,0x52,BYTE_LEN, 0},

	 {0x506e,0x46,BYTE_LEN, 0},
	 {0x506f,0x1f,BYTE_LEN, 0},
	
	 {0x3003,0x80,BYTE_LEN, 0},
	 {0x3004,0x20,BYTE_LEN, 0},
	 {0x3005,0x18,BYTE_LEN, 0},
	 {0x3006,0x0d,BYTE_LEN, 0},

	 {0x3503,0x00,BYTE_LEN, 0}
	 

};

static const struct ov2659_i2c_reg_conf const snapshot_tbl[] = {
	//1600*1200 5fps
	 {0x3005,0x24,BYTE_LEN, 0},
	 {0x3807,0xbb,BYTE_LEN, 0},
	 {0x3808,0x06,BYTE_LEN, 0},
	 {0x3809,0x40,BYTE_LEN, 0},
	 {0x380a,0x04,BYTE_LEN, 0},
	 {0x380b,0xb0,BYTE_LEN, 0},
	 {0x380c,0x07,BYTE_LEN, 0},
	 {0x380d,0x9f,BYTE_LEN, 0},
	 {0x380e,0x04,BYTE_LEN, 0},
	 {0x380f,0xd0,BYTE_LEN, 0},
	 {0x3811,0x10,BYTE_LEN, 0},
	 {0x3813,0x06,BYTE_LEN, 0},
	 {0x3814,0x11,BYTE_LEN, 0},
	 {0x3815,0x11,BYTE_LEN, 0},
	 {0x3a02,0x04,BYTE_LEN, 0},
	 {0x3a03,0xd0,BYTE_LEN, 0},
	 {0x3a09,0xb8,BYTE_LEN, 0},
	 {0x3a0b,0x9a,BYTE_LEN, 0},
	 {0x3a14,0x04,BYTE_LEN, 0},
	 {0x3a15,0x50,BYTE_LEN, 0},
	 {0x3634,0x44,BYTE_LEN, 0},
	 {0x3702,0x30,BYTE_LEN, 0},
	 {0x3703,0x48,BYTE_LEN, 0},
	 {0x3704,0x48,BYTE_LEN, 0},
	 {0x3705,0x18,BYTE_LEN, 0},
	 {0x3820,0x80,BYTE_LEN, 0},
	 {0x3821,0x00,BYTE_LEN, 0},
	 {0x370a,0x12,BYTE_LEN, 0},

	 {0x506e,0x44,BYTE_LEN, 0},
	 {0x506f,0xa6,BYTE_LEN, 0},
	 
	 {0x3004,0x30,BYTE_LEN, 0}


};

//effect
static const struct ov2659_i2c_reg_conf const effect_off_tbl[] = { 
	{0x5001,0x1f,BYTE_LEN, 0},
	{0x507b,0x02,BYTE_LEN, 0},	
    {0x507e,0x40,BYTE_LEN, 0},    
	{0x4300,0x32,BYTE_LEN, 0},//add
    {0x507f,0x40,BYTE_LEN, 0},  //50-48
    {0x3406,0x00,BYTE_LEN, 0}  //50-48
};

static const struct ov2659_i2c_reg_conf const effect_mono_tbl[] = { 
	{0x5001,0x1f,BYTE_LEN, 0},
	{0x4300,0x32,BYTE_LEN, 0},//add
	{0x3406,0x00,BYTE_LEN, 0},
	{0x507b,0x02,BYTE_LEN, 0},
	{0x507e,0x00,BYTE_LEN, 0},	
	{0x507f,0x00,BYTE_LEN, 0}
};

static const struct ov2659_i2c_reg_conf const effect_sepia_tbl[] = {
	{0x5001,0x1f,BYTE_LEN, 0},
	{0x3406,0x01,BYTE_LEN, 0},	
	{0x3400,0x07,BYTE_LEN, 0},	
	{0x3401,0x88,BYTE_LEN, 0},	
	{0x3402,0x07,BYTE_LEN, 0},	
	{0x3403,0x00,BYTE_LEN, 0},	
	{0x3404,0x04,BYTE_LEN, 0},		
	{0x3405,0x00,BYTE_LEN, 0},	
	{0x507b,0x1c,BYTE_LEN, 0},
	{0x507e,0x40,BYTE_LEN, 0},
	{0x4300,0x32,BYTE_LEN, 0},//add
	{0x507f,0xa0,BYTE_LEN, 0}
};

static const struct ov2659_i2c_reg_conf const effect_negative_tbl[] = {
	{0x4300,0x32,BYTE_LEN, 0},//add
	{0x5001,0x1f,BYTE_LEN, 0},
	{0x507b,0x44,BYTE_LEN, 0},
	{0x3406,0x00,BYTE_LEN, 0}
};

static const struct ov2659_i2c_reg_conf const effect_solarize_tbl[] = {
	{0x4300,0x33,BYTE_LEN, 0},
	{0x5001,0x1f,BYTE_LEN, 0},
	{0x507b,0x44,BYTE_LEN, 0},
	
	{0x3406,0x00,BYTE_LEN, 0}
};

static const struct ov2659_i2c_reg_conf const effect_bluish_tbl[] = {
	{0x5001,0x08,BYTE_LEN, 0},
	{0x507b,0x1c,BYTE_LEN, 0},
	{0x507e,0xa0,BYTE_LEN, 0},
	{0x4300,0x32,BYTE_LEN, 0},//add
	{0x507f,0x40,BYTE_LEN, 0}
};

static const struct ov2659_i2c_reg_conf const effect_greenish_tbl[] = {
	{0x5001,0x08,BYTE_LEN, 0},
	{0x507b,0x1c,BYTE_LEN, 0},
	{0x507e,0x60,BYTE_LEN, 0},
	{0x4300,0x32,BYTE_LEN, 0},//add
	{0x507f,0x60,BYTE_LEN, 0}
};

static const struct ov2659_i2c_reg_conf const effect_reddish_tbl[] = {
	{0x5001,0x08,BYTE_LEN, 0},
	{0x507b,0x1c,BYTE_LEN, 0},
	{0x507e,0x80,BYTE_LEN, 0},
	{0x4300,0x32,BYTE_LEN, 0},//add
	{0x507f,0xc0,BYTE_LEN, 0}
};
//scene
static const struct ov2659_i2c_reg_conf const scene_auto_tbl[] = {
	//{0x3004,0x20,BYTE_LEN, 0}
	{0x3a00,0x78,BYTE_LEN, 0}	

};

static const struct ov2659_i2c_reg_conf const scene_night_tbl[] = {
	{0x3003,0x80,BYTE_LEN, 0},
	{0x3004,0x20,BYTE_LEN, 0},
	{0x3005,0x18,BYTE_LEN, 0},
	{0x3006,0x0d,BYTE_LEN, 0},
	
	{0x3a00,0x7c,BYTE_LEN, 0},
	{0x3a02,0x07,BYTE_LEN, 0},
	{0x3a03,0x38,BYTE_LEN, 0},
	{0x3a14,0x07,BYTE_LEN, 0},
	{0x3a15,0x38,BYTE_LEN, 0},
};
//wb
static const struct ov2659_i2c_reg_conf const awb_tbl[] = {

	{0x3406,0x00,BYTE_LEN, 0},
	{0x3400,0x04,BYTE_LEN, 0},
	{0x3401,0x00,BYTE_LEN, 0},
	{0x3402,0x04,BYTE_LEN, 0},
	{0x3403,0x00,BYTE_LEN, 0},
	{0x3404,0x04,BYTE_LEN, 0},
	{0x3405,0x00,BYTE_LEN, 0}
};


static const struct ov2659_i2c_reg_conf const mwb_cloudy_tbl[] = {
	{0x3406,0x01,BYTE_LEN, 0},
	{0x3406,0x01,BYTE_LEN, 0},
	{0x3400,0x07,BYTE_LEN, 0},
	{0x3401,0x88,BYTE_LEN, 0},
	{0x3402,0x04,BYTE_LEN, 0},
	{0x3403,0x00,BYTE_LEN, 0},
	{0x3404,0x05,BYTE_LEN, 0},
	{0x3405,0x00,BYTE_LEN, 0}
};


static const struct ov2659_i2c_reg_conf const mwb_day_light_tbl[] = {
	{0x3406,0x01,BYTE_LEN, 0},
	{0x3400,0x06,BYTE_LEN, 0},
	{0x3401,0x2a,BYTE_LEN, 0},
	{0x3402,0x04,BYTE_LEN, 0},
	{0x3403,0x00,BYTE_LEN, 0},
	{0x3404,0x05,BYTE_LEN, 0},
	{0x3405,0x24,BYTE_LEN, 0}

};

static const struct ov2659_i2c_reg_conf const mwb_fluorescent_tbl[] = {
	{0x3406,0x01,BYTE_LEN, 0},	 
	{0x3406,0x01,BYTE_LEN, 0},	 
	{0x3400,0x07,BYTE_LEN, 0},	 
	{0x3401,0x02,BYTE_LEN, 0},	 
	{0x3402,0x04,BYTE_LEN, 0},	 
	{0x3403,0x00,BYTE_LEN, 0}, 
	{0x3404,0x05,BYTE_LEN, 0}, 
	{0x3405,0x15,BYTE_LEN, 0}

};

static const struct ov2659_i2c_reg_conf const mwb_incandescent_tbl[] = {
	{0x3406,0x01,BYTE_LEN, 0},
	{0x3406,0x01,BYTE_LEN, 0},
	{0x3400,0x04,BYTE_LEN, 0},
	{0x3401,0x58,BYTE_LEN, 0},
	{0x3402,0x04,BYTE_LEN, 0},
	{0x3403,0x00,BYTE_LEN, 0},
	{0x3404,0x08,BYTE_LEN, 0},
	{0x3405,0x40,BYTE_LEN, 0}

};




struct ov2659_reg ov2659_regs = {
	.init_tbl = init_tbl,
	.init_tbl_size = ARRAY_SIZE(init_tbl),
	.preview_tbl = preview_tbl,
	.preview_tbl_size = ARRAY_SIZE(preview_tbl),
	.snapshot_tbl = snapshot_tbl,
	.snapshot_tbl_size = ARRAY_SIZE(snapshot_tbl),

	.awb_tbl = awb_tbl,//add by lijiankun 2010-9-3 auto whitebalance
	.awb_tbl_size = ARRAY_SIZE(awb_tbl),
	.mwb_cloudy_tbl = mwb_cloudy_tbl,//add by lijiankun 2010-9-3 cloudy
	.mwb_cloudy_tbl_size = ARRAY_SIZE(mwb_cloudy_tbl),
	.mwb_day_light_tbl = mwb_day_light_tbl,//add by lijiankun 2010-9-3 Day_light
	.mwb_day_light_tbl_size = ARRAY_SIZE(mwb_day_light_tbl),
	.mwb_fluorescent_tbl = mwb_fluorescent_tbl,//add by lijiankun 2010-9-3 FLUORESCENT
	.mwb_fluorescent_tbl_size = ARRAY_SIZE(mwb_fluorescent_tbl),
	.mwb_incandescent_tbl = mwb_incandescent_tbl,//add by lijiankun 2010-9-3 INCANDESCENT
	.mwb_incandescent_tbl_size = ARRAY_SIZE(mwb_incandescent_tbl),

	.effect_off_tbl = effect_off_tbl,//add by lijiankun 2010-9-7 EFFECT_OFF
	.effect_off_tbl_size = ARRAY_SIZE(effect_off_tbl),
	.effect_mono_tbl = effect_mono_tbl,//add by lijiankun 2010-9-7 EFFECT_MONO
	.effect_mono_tbl_size = ARRAY_SIZE(effect_mono_tbl),
	.effect_sepia_tbl = effect_sepia_tbl,//add by lijiankun 2010-9-7 EFFECT_SEPIA
	.effect_sepia_tbl_size = ARRAY_SIZE(effect_sepia_tbl),
	.effect_negative_tbl = effect_negative_tbl,//add by lijiankun 2010-9-7 EFFECT_NEGATIVE
	.effect_negative_tbl_size = ARRAY_SIZE(effect_negative_tbl),
	.effect_solarize_tbl = effect_solarize_tbl,//add by lijiankun 2010-9-7 EFFECT_NEGATIVE
	.effect_solarize_tbl_size = ARRAY_SIZE(effect_solarize_tbl),
	.effect_bluish_tbl = effect_bluish_tbl,//add by lijiankun 2010-9-7 EFFECT_SOLARIZE
	.effect_bluish_tbl_size = ARRAY_SIZE(effect_bluish_tbl),
	.effect_greenish_tbl = effect_greenish_tbl,//add by lijiankun 2010-9-7 EFFECT_SOLARIZE
	.effect_greenish_tbl_size = ARRAY_SIZE(effect_greenish_tbl),
	.effect_reddish_tbl = effect_reddish_tbl,//add by lijiankun 2010-9-7 EFFECT_SOLARIZE
	.effect_reddish_tbl_size = ARRAY_SIZE(effect_reddish_tbl),
	
	.scene_auto_tbl = scene_auto_tbl,//add by lijiankun 2010-9-15 scene
	.scene_auto_tbl_size = ARRAY_SIZE(scene_auto_tbl),
	.scene_night_tbl = scene_night_tbl,//add by lijiankun 2010-9-15 scene
	.scene_night_tbl_size = ARRAY_SIZE(scene_night_tbl)
};



