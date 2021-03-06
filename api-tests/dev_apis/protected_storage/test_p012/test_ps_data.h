/** @file
 * Copyright (c) 2019, Arm Limited or ps affiliates. All rights reserved.
 * SPDX-License-Identifier : Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**/
#ifndef _TEST_P012_PS_DATA_TESTS_H_
#define _TEST_P012_PS_DATA_TESTS_H_

#include "val_protected_storage.h"

#define SST_FUNCTION val->ps_function

typedef struct {
    enum ps_function_code  api;
    psa_status_t        status;
} test_data;

static const test_data p012_data[] = {
{
 VAL_PS_GET_SUPPORT, PSA_STORAGE_SUPPORT_SET_EXTENDED /* Check if optional PS API supported */
},
{
 VAL_PS_CREATE, PSA_SUCCESS /* Create valid storage */
},
{
 VAL_PS_SET_EXTENDED, PSA_SUCCESS /* Set data using set_extended API */
},
{
 VAL_PS_SET_EXTENDED, PSA_ERROR_INVALID_ARGUMENT /* Set_extended with invalid offset + length */
},
{
 VAL_PS_SET_EXTENDED, PSA_ERROR_INVALID_ARGUMENT /* Set_extended call with invalid offset */
},
{
 VAL_PS_SET_EXTENDED, PSA_SUCCESS /* Set_extended call with valid offset and zero length */
},
{
 VAL_PS_SET_EXTENDED, PSA_ERROR_INVALID_ARGUMENT /* Set_extended with invalid offset + length */
},
{
 VAL_PS_SET_EXTENDED, PSA_ERROR_INVALID_ARGUMENT /* Set_extended with invalid length */
},
{
 VAL_PS_SET, PSA_SUCCESS /* Write data using set API */
},
{
 VAL_PS_GET, PSA_SUCCESS /* Check data validity using get API */
},
{
 0, 0 /* This is dummy for index10 */
},
{
 VAL_PS_CREATE, PSA_ERROR_INVALID_ARGUMENT /* Create call with UID 0 */
},
{
 VAL_PS_SET_EXTENDED, PSA_ERROR_INVALID_ARGUMENT /* Call set_extended with UID 0 */
},
{
 VAL_PS_REMOVE, PSA_ERROR_INVALID_ARGUMENT /* Call remove with UID 0 */
},
{
 VAL_PS_REMOVE, PSA_SUCCESS /* Remove with UID */
},
};
#endif /* _TEST_P012_PS_DATA_TESTS_H_ */
