/*
 * libmm-session
 *
 * Copyright (c) 2000 - 2011 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Seungbae Shin <seungbae.shin@samsung.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/**
* @ingroup	MMF_SESSION_API
* @addtogroup	SESSION
*/

/**
* @ingroup	SESSION
* @addtogroup	UTS_MMF_SESSION Unit
*/

/**
* @ingroup	UTS_MMF_SESSION Unit
* @addtogroup	UTS_MMF_SESSION_FINISH Uts_Mmf_Session_Finish
* @{
*/

/**
* @file uts_mmf_session_finish.c
* @brief This is a suit of unit test cases to test mm_session_finish API
* @version Initial Creation Version 0.1
* @date 2010.07.06
*/


#include "utc_mm_session_common.h"


///////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////
// Declare the global variables and registers and Internal Funntions
//-------------------------------------------------------------------------------------------------
#define API_NAME "mm_session_finish"

struct tet_testlist tet_testlist[] = {
	{utc_mm_session_finish_func_01, 1},
	{utc_mm_session_finish_func_02, 2},
	{NULL, 0}
};

///////////////////////////////////////////////////////////////////////////////////////////////////
/* Initialize TCM data structures */

/* Start up function for each test purpose */
void
startup ()
{
}

/* Clean up function for each test purpose */
void
cleanup ()
{
}

void utc_mm_session_finish_func_01()
{
	int ret = 0;

	/* Define the Multimedia Session Policy*/
	ret = mm_session_init(MM_SESSION_TYPE_SHARE);

	dts_check_eq(API_NAME, ret, MM_ERROR_NONE,"err=0x%x",ret);

	/* Finish the Multimedia Session */
	ret = mm_session_finish();

	dts_check_eq(API_NAME, ret, MM_ERROR_NONE,"err=0x%x",ret);

	return;
}


void utc_mm_session_finish_func_02()
{
	int ret = 0;

	/* forced cleanup previous session */
	mm_session_finish();

	/* Finish the Multimedia Session */
	ret = mm_session_finish();

	dts_check_ne(API_NAME, ret, MM_ERROR_NONE,"err=0x%x",ret);

	return;
}


/** @} */



