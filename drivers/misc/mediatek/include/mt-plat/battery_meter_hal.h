/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef _BATTERY_METER_HAL_H
#define _BATTERY_METER_HAL_H


/* ============================================================ */
/* define */
/* ============================================================ */
#define BM_LOG_CRTI (7)
#define BM_LOG_FULL (8)

#define bm_print(num, fmt, args...)   \
do {									\
	if (Enable_FGADC_LOG >= (int)num) {				\
		pr_debug(fmt, ##args); \
	}								   \
} while (0)

#define BMLOG_ERROR_LEVEL   3
#define BMLOG_WARNING_LEVEL 4
#define BMLOG_NOTICE_LEVEL  5
#define BMLOG_INFO_LEVEL    6
#define BMLOG_DEBUG_LEVEL   7
#define BMLOG_TRACE_LEVEL   8


#define bm_err(fmt, args...)   \
do {									\
	if (Enable_FGADC_LOG >= BMLOG_ERROR_LEVEL) {			\
		pr_notice(fmt, ##args); \
	}								   \
} while (0)

#define bm_warn(fmt, args...)   \
do {									\
	if (Enable_FGADC_LOG >= BMLOG_WARNING_LEVEL) {		\
		pr_notice(fmt, ##args); \
	}								   \
} while (0)

#define bm_notice(fmt, args...)   \
do {									\
	if (Enable_FGADC_LOG >= BMLOG_NOTICE_LEVEL) {			\
		pr_notice(fmt, ##args); \
	}								   \
} while (0)

#define bm_info(fmt, args...)   \
do {									\
	if (Enable_FGADC_LOG >= BMLOG_INFO_LEVEL) {		\
		pr_info(fmt, ##args); \
	}								   \
} while (0)

#define bm_debug(fmt, args...)   \
do {									\
	if (Enable_FGADC_LOG >= BMLOG_DEBUG_LEVEL) {		\
		pr_debug(fmt, ##args); \
	}								   \
} while (0)

#define bm_trace(fmt, args...)\
do {									\
	if (Enable_FGADC_LOG >= BMLOG_TRACE_LEVEL) {			\
		pr_debug(fmt, ##args);\
	}						\
} while (0)


#define BM_DAEMON_DEFAULT_LOG_LEVEL BMLOG_ERROR_LEVEL


/* ============================================================ */
/* ENUM */
/* ============================================================ */
enum BATTERY_METER_CTRL_CMD {
	BATTERY_METER_CMD_HW_FG_INIT,

	BATTERY_METER_CMD_GET_HW_FG_CURRENT,	/* fgauge_read_current */
	BATTERY_METER_CMD_GET_HW_FG_CURRENT_SIGN,	/*  */
	BATTERY_METER_CMD_GET_HW_FG_CAR,	/* fgauge_read_columb */

	BATTERY_METER_CMD_HW_RESET,	/* FGADC_Reset_SW_Parameter */

	BATTERY_METER_CMD_GET_ADC_V_BAT_SENSE,
	BATTERY_METER_CMD_GET_ADC_V_I_SENSE,
	BATTERY_METER_CMD_GET_ADC_V_BAT_TEMP,
	BATTERY_METER_CMD_GET_ADC_V_CHARGER,

	BATTERY_METER_CMD_GET_HW_OCV,
	BATTERY_METER_CMD_DUMP_REGISTER,
	BATTERY_METER_CMD_SET_COLUMB_INTERRUPT,
	BATTERY_METER_CMD_GET_BATTERY_PLUG_STATUS,
	BATTERY_METER_CMD_GET_HW_FG_CAR_ACT,	/* fgauge_read_columb */
	BATTERY_METER_CMD_SET_LOW_BAT_INTERRUPT,
	BATTERY_METER_CMD_GET_LOW_BAT_INTERRUPT_STATUS,
	BATTERY_METER_CMD_GET_REFRESH_HW_OCV,

	BATTERY_METER_CMD_NUMBER
};

#ifndef BATTERY_BOOL
#define BATTERY_BOOL
#define kal_bool enum KAL_BOOL

enum KAL_BOOL {
	KAL_FALSE = 0,
	KAL_TRUE  = 1,
};
#endif


/* ============================================================ */
/* structure */
/* ============================================================ */

/* ============================================================ */
/* typedef */
/* ============================================================ */
typedef signed int(*BATTERY_METER_CONTROL) (enum BATTERY_METER_CTRL_CMD cmd, void *data);

/* ============================================================ */
/* External Variables */
/* ============================================================ */
extern int Enable_FGADC_LOG;

/* ============================================================ */
/* External function */
/* ============================================================ */
extern signed int bm_ctrl_cmd(enum BATTERY_METER_CTRL_CMD cmd, void *data);

#endif				/* #ifndef _BATTERY_METER_HAL_H */
