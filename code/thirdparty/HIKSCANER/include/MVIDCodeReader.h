
#ifndef _MVID_CODEREADER_H_
#define _MVID_CODEREADER_H_

#include "MVIDCodeReaderDefine.h"

/**
*  @brief  动态库导入导出定义
*  @brief  Import and export definition of the dynamic library 
*/
#ifndef MVID_CODEREADER_API

    #if (defined (_WIN32) || defined(WIN64))
        #if defined(MVID_CODEREADER_EXPORTS)
            #define MVID_CODEREADER_API __declspec(dllexport)
        #else
            #define MVID_CODEREADER_API __declspec(dllimport)
        #endif
    #else
        #ifndef __stdcall
            #define __stdcall
        #endif

        #ifndef MVID_CODEREADER_API
            #define  MVID_CODEREADER_API
        #endif
    #endif

#endif

#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif

#ifdef __cplusplus
extern "C" {
#endif 


/************************************************************************
 *  @fn     MVID_CR_GetVersion(IN OUT char* const chVersion)
 *  @brief  获取SDK版本号
 *  @param  chVersion           [IN][OUT]       SDK版本号
 *  @return 返回SDK,一维码,二维码版本号，如1.0.0_3.1.0_1.7.0

 *  @fn     MVID_CR_GetVersion(IN OUT char* const chVersion)
 *  @brief  Get SDK Version
 *  @param  chVersion           [IN][OUT]       SDK Version
 *  @return SDK Version 
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_GetVersion(IN OUT char* const chVersion);

/************************************************************************
 *  @fn     MVID_CR_CreateHandle(OUT void ** handle, IN unsigned int nCodeAbility)
 *  @brief  创建句柄
 *  @param  handle                 [OUT]          句柄地址
 *  @param  nCodeAbility           [IN]           读码能力集
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码 
 
 *  @fn     MVID_CR_CreateHandle(OUT void ** handle, IN unsigned int nCodeAbility)
 *  @brief  Create Handle
 *  @param  handle                 [OUT]          Handle Address
 *  @param  nCodeAbility           [IN]           Code Ability
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CreateHandle(OUT void ** handle, IN unsigned int nCodeAbility);

/************************************************************************
 *  @fn     MVID_CR_DestroyHandle(IN void * handle)
 *  @brief  销毁句柄
 *  @param  handle                 [IN]          句柄
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码 
 
 *  @fn     MVID_CR_DestroyHandle(IN void * handle)
 *  @brief  Destroy Handle
 *  @param  handle                 [IN]          Handle
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_DestroyHandle(IN void * handle);

/************************************************************************
 *  @fn     MVID_CR_Algorithm_SetIntValue(IN void* handle, IN const char* const strParamKeyName, IN const int nValue)
 *  @brief  设置整型参数
 *  @param  handle                 [IN]          句柄
 *  @param  strParamKeyName        [IN]          属性键值
 *  @param  nValue                 [IN]          参数值
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码 
 
 *  @fn     MVID_CR_Algorithm_SetIntValue(IN void* handle, IN const char* const strParamKeyName, IN const int nValue)
 *  @brief  Set Integer Value
 *  @param  handle                 [IN]          Handle
 *  @param  strParamKeyName        [IN]          Param KeyName
 *  @param  nValue                 [IN]          Value
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_Algorithm_SetIntValue(IN void* handle, IN const char* const strParamKeyName, IN const int nValue);

/************************************************************************
 *  @fn     MVID_CR_Algorithm_GetIntValue(IN void* handle, IN const char* const strParamKeyName, IN OUT int* const pnValue)
 *  @brief  获取整型参数
 *  @param  handle                 [IN]          句柄
 *  @param  strParamKeyName        [IN]          属性键值
 *  @param  pnValue                [IN][OUT]     参数值
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码 
 
 *  @fn     MVID_CR_Algorithm_GetIntValue(IN void* handle, IN const char* const strParamKeyName, IN OUT int* const pnValue)
 *  @brief  Get Integer Value
 *  @param  handle                 [IN]          Handle
 *  @param  strParamKeyName        [IN]          Param KeyName
 *  @param  pnValue                [IN][OUT]     Value
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_Algorithm_GetIntValue(IN void* handle, IN const char* const strParamKeyName, IN OUT int* const pnValue);

/************************************************************************
 *  @fn     MVID_CR_Algorithm_SetFloatValue(IN void* handle, IN const char* const strParamKeyName, IN const float fValue)
 *  @brief  设置浮点型参数
 *  @param  handle                 [IN]          句柄
 *  @param  strParamKeyName        [IN]          属性键值
 *  @param  fValue                 [IN]          参数值
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码 
 
 *  @fn     MVID_CR_Algorithm_SetFloatValue(IN void* handle, IN const char* const strParamKeyName, IN const float fValue)
 *  @brief  Set Float Value
 *  @param  handle                 [IN]          Handle
 *  @param  strParamKeyName        [IN]          Param KeyName
 *  @param  fValue                 [IN]          Value
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_Algorithm_SetFloatValue(IN void* handle, IN const char* const strParamKeyName, IN const float fValue);

/************************************************************************
 *  @fn     MVID_CR_Algorithm_GetFloatValue(IN void* handle, IN const char* const strParamKeyName, IN OUT float* const pfValue)
 *  @brief  获取浮点型参数
 *  @param  handle                 [IN]          句柄
 *  @param  strParamKeyName        [IN]          属性键值
 *  @param  pfValue                [OUT]         参数值
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码 
 
 *  @fn     MVID_CR_Algorithm_GetFloatValue(IN void* handle, IN const char* const strParamKeyName, IN OUT float* const pfValue)
 *  @brief  Get Float Value
 *  @param  handle                 [IN]          Handle
 *  @param  strParamKeyName        [IN]          Param KeyName
 *  @param  pfValue                [OUT]         Value
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_Algorithm_GetFloatValue(IN void* handle, IN const char* const strParamKeyName, IN OUT float* const pfValue);

/************************************************************************
 *  @fn     MVID_CR_Algorithm_SetStringValue(IN void* handle, IN const char* const strParamKeyName, IN const char* const strValue)
 *  @brief  设置字符串型参数
 *  @param  handle                 [IN]          句柄
 *  @param  strParamKeyName        [IN]          属性键值
 *  @param  strValue               [IN]          参数值
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码 
 
 *  @fn     MVID_CR_Algorithm_SetStringValue(IN void* handle, IN const char* const strParamKeyName, IN const char* const strValue)
 *  @brief  Set String Value
 *  @param  handle                 [IN]          Handle
 *  @param  strParamKeyName        [IN]          Param KeyName
 *  @param  strValue               [IN]          Value
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_Algorithm_SetStringValue(IN void* handle, IN const char* const strParamKeyName, IN const char* const strValue);

/************************************************************************
 *  @fn     MVID_CR_Algorithm_GetStringValue(IN void* handle, IN const char* const strParamKeyName, OUT char* const strValue)
 *  @brief  获取字符串型参数
 *  @param  handle                 [IN]          句柄
 *  @param  strParamKeyName        [IN]          属性键值
 *  @param  strValue               [OUT]         参数值
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码 
 
 *  @fn     MVID_CR_Algorithm_GetStringValue(IN void* handle, IN const char* const strParamKeyName, OUT char* const strValue)
 *  @brief  Get String Value
 *  @param  handle                 [IN]          Handle
 *  @param  strParamKeyName        [IN]          Param KeyName
 *  @param  strValue               [OUT]         Value
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_Algorithm_GetStringValue(IN void* handle, IN const char* const strParamKeyName, IN OUT char* const strValue);

/************************************************************************
 *  @fn     MVID_CR_Process(IN void* handle, IN OUT MVID_PROC_PARAM* pstParam , IN unsigned int nCodeAbility)
 *  @brief  读码
 *  @param  handle                 [IN]          句柄
 *  @param  pstParam               [IN]          图片信息结构体
 *  @param  nCodeAbility           [IN]          读码能力集
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码 
 
 *  @fn     MVID_CR_Process(IN void* handle, IN OUT MVID_PROC_PARAM* pstParam , IN unsigned int nCodeAbility)
 *  @brief  Process
 *  @param  handle                 [IN]          Handle
 *  @param  pstParam               [IN]          Param of input Image
 *  @param  nCodeAbility           [IN]          Code Ability
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_Process(IN void* handle, IN OUT MVID_PROC_PARAM* pstParam , IN unsigned int nCodeAbility);

/************************************************************************
*  @fn     MVID_CR_EnumDevices(IN OUT MVID_CAMERA_INFO_LIST* pstCamList)
*  @brief  枚举设备
*  @param  pstCamList             [OUT]          设备列表
*  @return 成功，返回MVID_CR_OK；错误，返回错误码 

*  @fn     MVID_CR_EnumDevices(IN OUT MVID_CAMERA_INFO_LIST* pstCamList)
*  @brief  Enumerate Device
*  @param  pstCamList             [OUT]          Device List
*  @return Success, return MVID_CR_OK. Failure, return error code 
************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_EnumDevices(IN OUT MVID_CAMERA_INFO_LIST* pstCamList);

/************************************************************************
*  @fn     MVID_CR_CAM_EnumDevicesByCfg(IN OUT MVID_CAMERA_INFO_LIST* pstCamList)
*  @brief  根据配置文件枚举指定设备
*  @param  pstCamList             [OUT]          设备列表
*  @return 成功，返回MVID_CR_OK；错误，返回错误码 

*  @fn     MVID_CR_CAM_EnumDevicesByCfg(IN OUT MVID_CAMERA_INFO_LIST* pstCamList)
*  @brief  Enumerate Specified Series Device
*  @param  pstCamList             [OUT]          Device List
*  @return Success, return MVID_CR_OK. Failure, return error code 
************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_EnumDevicesByCfg(IN OUT MVID_CAMERA_INFO_LIST* pstCamList);

/************************************************************************
 *  @fn     MVID_CR_BindDevice(IN void * handle, IN const MVID_CAMERA_INFO* pstCamInfo)
 *  @brief  绑定设备
 *  @param  handle                 [OUT]          句柄地址
 *  @param  pstCamInfo             [IN]           设备信息结构体
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码 
 
 *  @fn     MVID_CR_BindDevice(IN void * handle, IN const MVID_CAMERA_INFO* pstCamInfo)
 *  @brief  Bind Device
 *  @param  handle                 [OUT]          Handle Address
 *  @param  pstCamInfo             [IN]           Camera Information
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_BindDevice(IN void * handle, IN const MVID_CAMERA_INFO* pstCamInfo);

/************************************************************************
 *  @fn     MVID_CR_CAM_BindDeviceByIP(IN void * handle, IN const char* chCurrentIp, IN const char* chNetExport)
 *  @brief  通过IP绑定设备
 *  @param  handle                 [OUT]          句柄地址
 *  @param  chCurrentIp            [IN]           相机IP
 *  @param  chNetExport            [IN]           当前PC IP
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码 
 
 *  @fn     MVID_CR_CAM_BindDeviceByIP(IN void * handle, IN const char* chCurrentIp, IN const char* chNetExport)
 *  @brief  Bind Device By IP
 *  @param  handle                 [OUT]          Handle Address
 *  @param  chCurrentIp            [IN]           Camera IP
 *  @param  chNetExport            [IN]           Current PC IP
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_BindDeviceByIP(IN void * handle, IN const char* chCurrentIp, IN const char* chNetExport);

/************************************************************************
 *  @fn     MVID_CR_CAM_BindDeviceBySerialNumber(IN void * handle, IN const char* chSerialNumber)
 *  @brief  通过序列号绑定设备
 *  @param  handle                 [OUT]          句柄地址
 *  @param  chSerialNumber         [IN]           相机序列号
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码 
 
 *  @fn     MVID_CR_CAM_BindDeviceBySerialNumber(IN void * handle, IN const char* chSerialNumber)
 *  @brief  Bind Device By SerialNumber
 *  @param  handle                 [OUT]          Handle Address
 *  @param  chSerialNumber         [IN]           Camera Serial Number
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_BindDeviceBySerialNumber(IN void * handle, IN const char* chSerialNumber);

/***********************************************************************
 *  @fn         MVID_CODEREADER_API int __stdcall MVID_CR_CAM_RegisterImageCallBack(IN void* handle, 
                                                         IN void(__stdcall* cbOutput)(MVID_CAM_OUTPUT_INFO* pstOutput, void* pUser),
                                                         IN void* pUser)
 *  @brief      注册图像数据回调，包含解码信息
 *  @param       handle                 [IN]          句柄
 *  @param       cbOutput               [IN]          回调函数指针
 *  @param       pUser                  [IN]          用户自定义变量
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码
 
 *  @fn         MVID_CODEREADER_API int __stdcall MVID_CR_CAM_RegisterImageCallBack(IN void* handle, 
                                                         IN void(__stdcall* cbOutput)(MVID_CAM_OUTPUT_INFO* pstOutput, void* pUser),
                                                         IN void* pUser)
 *  @brief      register image data callback, include barcode info
 *  @param       handle                 [IN]          Handle
 *  @param       cbOutput               [IN]          Callback function pointer
 *  @param       pUser                  [IN]          User defined variable
 *  @return      Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_RegisterImageCallBack(IN void* handle, 
                                                         IN void(__stdcall* cbOutput)(MVID_CAM_OUTPUT_INFO* pstOutput, void* pUser),
                                                         IN void* pUser);

/***********************************************************************
*  @fn         MVID_CR_CAM_RegisterImageBufferCallBack(IN void* handle, 
                                                         IN void(__stdcall* cbOutput)(MVID_IMAGE_INFO* pstOutput, void* pUser),
                                                         IN void* pUser)
 *  @brief      注册图像数据回调，不包含解码信息
 *  @param       handle                 [IN]          句柄
 *  @param       cbOutput               [IN]          回调函数指针
 *  @param       pUser                  [IN]          用户自定义变量
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码
 
 *  @fn         MVID_CR_CAM_RegisterImageBufferCallBack(IN void* handle, 
                                                         IN void(__stdcall* cbOutput)(MVID_IMAGE_INFO* pstOutput, void* pUser),
                                                         IN void* pUser)
 *  @brief      register image data callback, without barcode info
 *  @param       handle                 [IN]          Handle
 *  @param       cbOutput               [IN]          Callback function pointer
 *  @param       pUser                  [IN]          User defined variable
 *  @return      Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_RegisterImageBufferCallBack(IN void* handle, 
                                                         IN void(__stdcall* cbOutput)(MVID_IMAGE_INFO* pstOutput, void* pUser),
                                                         IN void* pUser);

/***********************************************************************
 *  @fn         MVID_CR_CAM_RegisterPreImageCallBack(IN void* handle, 
                                                         IN void(__stdcall* cbPreOutput)(MVID_IMAGE_INFO* pstPreOutput, MVID_IMAGE_INFO* pstProcInput, void* pUser),
                                                         IN void* pUser)
 *  @brief      注册预处理图像数据回调
 *  @param       handle                 [IN]          句柄
 *  @param       cbPreOutput            [IN]          回调函数指针，预处理输入参数内存由SDK内部分配
 *  @param       pUser                  [IN]          用户自定义变量
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码
 
 *  @fn         MVID_CR_CAM_RegisterPreImageCallBack(IN void* handle, 
                                                         IN void(__stdcall* cbPreOutput)(MVID_IMAGE_INFO* pstPreOutput, MVID_IMAGE_INFO* pstProcInput, void* pUser),
                                                         IN void* pUser)
 *  @brief      register pretreatment image data callback
 *  @param       handle                 [IN]          Handle
 *  @param       cbPreOutput            [IN]          Callback function pointer，Preprocessing input parameter memory is allocated internally by the SDK
 *  @param       pUser                  [IN]          User defined variable
 *  @return      Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_RegisterPreImageCallBack(IN void* handle, 
                                                         IN void(__stdcall* cbPreOutput)(MVID_IMAGE_INFO* pstPreOutput, MVID_IMAGE_INFO* pstProcInput, void* pUser),
                                                         IN void* pUser);

/************************************************************************
 *  @fn     MVID_CR_CAM_RegisterAllEventCallBack(IN void* handle, 
                                                         IN void(__stdcall* cbEvent)(MVID_EVENT_OUT_INFO * pEventInfo, void* pUser),
                                                         IN void* pUser)
 *  @brief  注册全部事件回调，在打开设备之后调用,只支持GIGE
 *  @param  handle：          [IN]      设备句柄
 *  @param  cbEvent           [IN]      用户注册事件回调函数
 *  @param  pUser             [IN]      用户自定义变量
 *  @return 见返回错误码
 
 *  @fn     MVID_CR_CAM_RegisterAllEventCallBack(IN void* handle, 
                                                         IN void(__stdcall* cbEvent)(MVID_EVENT_OUT_INFO * pEventInfo, void* pUser),
                                                         IN void* pUser)
 *  @brief  Register event callback, which is called after the device is opened
 *  @param  handle:           [IN]      Device Handle
 *  @param  cbEvent           [IN]      Event CallBack Function Pointer
 *  @param  pUser             [IN]      User defined variable
 *  @return Refer to error code
************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_RegisterAllEventCallBack(IN void* handle, 
                                                         IN void(__stdcall* cbEvent)(MVID_EVENT_OUT_INFO * pEventInfo, void* pUser),
                                                         IN void* pUser);

/***********************************************************************
 *  @fn         MVID_CR_CAM_StartGrabbing(IN void* handle)
 *  @brief      开始取流
 *  @param       handle                 [IN]          句柄
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码
 
 *  @fn         MVID_CR_CAM_StartGrabbing(IN void* handle)
 *  @brief      Start Grabbing
 *  @param      handle                 [IN]          Handle
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_StartGrabbing(IN void* handle);

/***********************************************************************
 *  @fn         MVID_CR_CAM_StopGrabbing(IN void* handle)
 *  @brief      停止取流
 *  @param       handle                 [IN]          句柄
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码
 
 *  @fn         MVID_CR_CAM_StopGrabbing(IN void* handle)
 *  @brief      Stop Grabbing
 *  @param      handle                 [IN]          Handle
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_StopGrabbing(IN void* handle);

/***********************************************************************
 *  @fn         MVID_CR_CAM_GetOneFrameTimeout(IN void* handle, IN OUT MVID_CAM_OUTPUT_INFO* pFrameInfo, IN unsigned int nMsec)
 *  @brief      采用超时机制获取一帧图片，SDK内部等待直到有数据时返回，包含解码信息
 *  @param       handle                 [IN]          句柄
 *  @param       pFrameInfo             [OUT]         图像信息结构体
 *  @param       nMsec                  [IN]          等待超时时间
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码
 
 *  @fn         MVID_CR_CAM_GetOneFrameTimeout(IN void* handle, IN OUT MVID_CAM_OUTPUT_INFO* pFrameInfo, IN unsigned int nMsec)
 *  @brief      Timeout mechanism is used to get image, and the SDK waits inside until the data is returned, include barcode info
 *  @param       handle                 [IN]          Handle
 *  @param       pFrameInfo             [OUT]         Image information structure
 *  @param       nMsec                  [IN]          Waiting timeout
 *  @return      Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_GetOneFrameTimeout(IN void* handle, IN OUT MVID_CAM_OUTPUT_INFO* pFrameInfo, IN unsigned int nMsec);

/***********************************************************************
 *  @fn         MVID_CR_CAM_GetImageBuffer(IN void* handle, IN OUT MVID_IMAGE_INFO* pImageInfo, IN unsigned int nMsec)
 *  @brief      采用超时机制获取一帧图片，SDK内部等待直到有数据时返回，不包含解码信息
 *  @param       handle                 [IN]          句柄
 *  @param       pImageInfo             [OUT]         图像信息结构体
 *  @param       nMsec                  [IN]          等待超时时间
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码
 
 *  @fn         MVID_CR_CAM_GetImageBuffer(IN void* handle, IN OUT MVID_IMAGE_INFO* pImageInfo, IN unsigned int nMsec)
 *  @brief      Timeout mechanism is used to get image, and the SDK waits inside until the data is returned, without barcode info
 *  @param       handle                 [IN]          Handle
 *  @param       pImageInfo             [OUT]         Image information structure
 *  @param       nMsec                  [IN]          Waiting timeout
 *  @return      Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_GetImageBuffer(IN void* handle, IN OUT MVID_IMAGE_INFO* pImageInfo, IN unsigned int nMsec);

/************************************************************************
 *  @fn         MVID_CODEREADER_API int __stdcall MVID_CR_CAM_SetIntValue(IN void* handle,
                                                               IN const char* strKey,
                                                               IN int64_t nValue)
 *  @brief      设置相机Int型属性值
 *  @param      handle                [IN]        相机句柄
 *  @param      strKey                [IN]        属性键值，如获取宽度信息则为"Width"
 *  @param      nValue                [IN]        想要设置的相机的属性值
 *  @return     成功,返回MVID_CR_OK,失败,返回错误码
 
 *  @fn         MVID_CODEREADER_API int __stdcall MVID_CR_CAM_SetIntValue(IN void* handle,
                                                               IN const char* strKey,
                                                               IN int64_t nValue)
 *  @brief      Set Camera Int value
 *  @param      handle                [IN]        Handle
 *  @param      strKey                [IN]        Key value, for example, using "Width" to set width
 *  @param      nValue                [IN]        Feature value to set
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_SetIntValue(IN void* handle, IN const char* strKey, IN int64_t nValue);

/************************************************************************
 *  @fn         MVID_CR_CAM_GetIntValue(IN void* handle, IN const char* strKey, IN OUT MVID_CAM_INTVALUE_EX *pIntValue)
 *  @brief      获取Int属性值
 *  @param      handle                [IN]              相机句柄
 *  @param      strKey                [IN]              属性键值，如获取宽度信息则为"Width"
 *  @param      pIntValue             [IN][OUT]         返回给调用者有关相机属性结构体指针
 *  @return     成功,返回MVID_CR_OK,失败,返回错误码
 
 *  @fn         MVID_CR_CAM_GetIntValue(IN void* handle, IN const char* strKey, IN OUT MVID_CAM_INTVALUE_EX *pIntValue)
 *  @brief      Get Int value
 *  @param      handle                [IN]              Handle
 *  @param      strKey                [IN]              Key value, for example, using "Width" to get width
 *  @param      pIntValue             [IN][OUT]         Structure pointer of camera features
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_GetIntValue(IN void* handle, IN const char* strKey, IN OUT MVID_CAM_INTVALUE_EX *pIntValue);

/************************************************************************
 *  @fn         MVID_CR_CAM_SetEnumValue(IN void* handle, IN const char* strKey, IN unsigned int nValue)
 *  @brief      设置相机Enum型属性值
 *  @param      handle                [IN]        相机句柄
 *  @param      strKey                [IN]        属性键值，如获取像素格式信息则为"PixelFormat"
 *  @param      nValue                [IN]        想要设置的相机的属性值
 *  @return     成功,返回MVID_CR_OK,失败,返回错误码
 
 *  @fn         MVID_CR_CAM_SetEnumValue(IN void* handle, IN const char* strKey, IN unsigned int nValue)
 *  @brief      Set Camera Enum value
 *  @param      handle                [IN]        Handle
 *  @param      strKey                [IN]        Key value, for example, using "PixelFormat" to set pixel format
 *  @param      nValue                [IN]        Feature value to set
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_SetEnumValue(IN void* handle, IN const char* strKey, IN unsigned int nValue);

/************************************************************************
 *  @fn         MVID_CR_CAM_SetEnumValueByString(IN void* handle, IN const char* strKey, IN const char* sValue)
 *  @brief      通过字符串设置相机Enum型属性值
 *  @param      handle                [IN]        相机句柄
 *  @param      strKey                [IN]        属性键值，如获取像素格式信息则为"PixelFormat"
 *  @param      sValue                [IN]        想要设置的相机的属性字符串
 *  @return     成功,返回MVID_CR_OK,失败,返回错误码
 
 *  @fn         MVID_CR_CAM_SetEnumValueByString(IN void* handle, IN const char* strKey, IN const char* sValue)
 *  @brief      Set Camera Enum value by string
 *  @param      handle                [IN]        Handle
 *  @param      strKey                [IN]        Key value, for example, using "PixelFormat" to set pixel format
 *  @param      sValue                [IN]        Feature String to set
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_SetEnumValueByString(IN void* handle, IN const char* strKey, IN const char* sValue);

/************************************************************************
 *  @fn         MVID_CR_CAM_GetEnumValue(IN void* handle, IN const char* strKey, IN OUT MVID_CAM_ENUMVALUE *pEnumValue)
 *  @brief      获取相机Enum属性值
 *  @param      handle                   [IN]        相机句柄
 *  @param      strKey                   [IN]        属性键值，如获取像素格式信息则为"PixelFormat"
 *  @param      pEnumValue               [IN][OUT]   返回给调用者有关相机属性结构体指针
 *  @return     成功,返回MVID_CR_OK,失败,返回错误码
 
 *  @fn         MVID_CR_CAM_GetEnumValue(IN void* handle, IN const char* strKey, IN OUT MVID_CAM_ENUMVALUE *pEnumValue)
 *  @brief      Get Camera Enum value
 *  @param      handle                   [IN]        Handle
 *  @param      strKey                   [IN]        Key value, for example, using "PixelFormat" to get pixel format
 *  @param      pEnumValue               [IN][OUT]   Structure pointer of camera features
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_GetEnumValue(IN void* handle, IN const char* strKey, IN OUT MVID_CAM_ENUMVALUE *pEnumValue);

/************************************************************************
 *  @fn         MVID_CR_CAM_SetFloatValue(IN void* handle, IN const char* strKey, IN float fValue)
 *  @brief      设置相机Float型属性值
 *  @param      handle                [IN]        相机句柄
 *  @param      strKey                [IN]        属性键值
 *  @param      fValue                [IN]        想要设置的相机的属性值
 *  @return     成功,返回MVID_CR_OK,失败,返回错误码
 
 *  @fn         MVID_CR_CAM_SetFloatValue(IN void* handle, IN const char* strKey, IN float fValue)
 *  @brief      Set Camera Float value
 *  @param      handle                [IN]        Handle
 *  @param      strKey                [IN]        Key value
 *  @param      fValue                [IN]        Feature value to set
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_SetFloatValue(IN void* handle, IN const char* strKey, IN float fValue);

/************************************************************************
 *  @fn         MVID_CR_CAM_GetFloatValue(IN void* handle, IN const char* strKey, IN OUT MVID_CAM_FLOATVALUE *pFloatValue)
 *  @brief      获取相机Float属性值
 *  @param      handle                     [IN]        相机句柄
 *  @param      strKey                     [IN]        属性键值
 *  @param      pFloatValue                [IN][OUT]   返回给调用者有关相机属性结构体指针
 *  @return     成功,返回MVID_CR_OK,失败,返回错误码
 
 *  @fn         MVID_CR_CAM_GetFloatValue(IN void* handle, IN const char* strKey, IN OUT MVID_CAM_FLOATVALUE *pFloatValue)
 *  @brief      Get Cmera Float value
 *  @param      handle                     [IN]        Handle
 *  @param      strKey                     [IN]        Key value
 *  @param      pFloatValue                [IN][OUT]   Structure pointer of camera features
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_GetFloatValue(IN void* handle, IN const char* strKey, IN OUT MVID_CAM_FLOATVALUE *pFloatValue);

/************************************************************************
 *  @fn         MVID_CR_CAM_SetStringValue(IN void* handle, IN const char* strKey, IN const char * sValue)
 *  @brief      设置相机String型属性值
 *  @param      handle                  [IN]        相机句柄
 *  @param      strKey                  [IN]        属性键值
 *  @param      sValue                  [IN]        想要设置的相机的属性值
 *  @return     成功,返回MVID_CR_OK,失败,返回错误码
 
 *  @fn         MVID_CR_CAM_SetStringValue(IN void* handle, IN const char* strKey, IN const char * sValue)
 *  @brief      Set Camera String value
 *  @param      handle                  [IN]        Handle
 *  @param      strKey                  [IN]        Key value
 *  @param      sValue                  [IN]        Feature value to set
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_SetStringValue(IN void* handle, IN const char* strKey, IN const char * sValue);

/************************************************************************
 *  @fn         MVID_CR_CAM_GetStringValue(IN void* handle, IN const char* strKey, IN OUT MVID_CAM_STRINGVALUE *pStringValue)
 *  @brief      获取相机String属性值
 *  @param      handle                       [IN]        相机句柄
 *  @param      strKey                       [IN]        属性键值
 *  @param      pStringValue                 [IN][OUT]   返回给调用者有关相机属性结构体指针
 *  @return     成功,返回MVID_CR_OK,失败,返回错误码
 
 *  @fn         MVID_CR_CAM_GetStringValue(IN void* handle, IN const char* strKey, IN OUT MVID_CAM_STRINGVALUE *pStringValue)
 *  @brief      Get Camera String value
 *  @param      handle                       [IN]        Handle
 *  @param      strKey                       [IN]        Key value
 *  @param      pStringValue                 [IN][OUT]   Structure pointer of camera features
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_GetStringValue(IN void* handle, IN const char* strKey, IN OUT MVID_CAM_STRINGVALUE *pStringValue);

/************************************************************************
 *  @fn         MVID_CR_CAM_SetBoolValue(IN void* handle, IN const char* strKey, IN bool bValue)
 *  @brief      设置相机Boolean型属性值
 *  @param      handle                [IN]        相机句柄
 *  @param      strKey                [IN]        属性键值
 *  @param      bValue                [IN]        想要设置的相机的属性值
 *  @return     成功,返回MVID_CR_OK,失败,返回错误码
 
 *  @fn         MVID_CR_CAM_SetBoolValue(IN void* handle, IN const char* strKey, IN bool bValue)
 *  @brief      Set Camera Boolean value
 *  @param      handle                [IN]        Handle
 *  @param      strKey                [IN]        Key value
 *  @param      bValue                [IN]        Feature value to set
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_SetBoolValue(IN void* handle, IN const char* strKey, IN bool bValue);

/************************************************************************
 *  @fn         MVID_CR_CAM_GetBoolValue(IN void* handle, IN const char* strKey, IN OUT bool *pBoolValue)
 *  @brief      获取相机Boolean属性值
 *  @param      handle                     [IN]        相机句柄
 *  @param      strKey                     [IN]        属性键值
 *  @param      pBoolValue                 [IN][OUT]   返回给调用者有关相机属性值
 *  @return     成功,返回MVID_CR_OK,失败,返回错误码
 
 *  @fn         MVID_CR_CAM_GetBoolValue(IN void* handle, IN const char* strKey, IN OUT bool *pBoolValue)
 *  @brief      Get Camera Boolean value
 *  @param      handle                     [IN]        Handle
 *  @param      strKey                     [IN]        Key value
 *  @param      pBoolValue                 [IN][OUT]   Structure pointer of camera features
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_GetBoolValue(IN void* handle, IN const char* strKey, IN OUT bool *pBoolValue);

/************************************************************************
 *  @fn         MVID_CR_CAM_SetCommandValue(IN void* handle, IN const char* strKey)
 *  @brief      设置相机Command型属性值
 *  @param      handle                  [IN]        相机句柄
 *  @param      strKey                  [IN]        属性键值
 *  @return     成功,返回MVID_CR_OK,失败,返回错误码
 
 *  @fn         MVID_CR_CAM_SetCommandValue(IN void* handle, IN const char* strKey)
 *  @brief      Set Camera Command value
 *  @param      handle                  [IN]        Handle
 *  @param      strKey                  [IN]        Key value
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_SetCommandValue(IN void* handle, IN const char* strKey);

/***********************************************************************
 *  @fn     MVID_CR_CAM_SetImageNodeNum(IN void* handle, unsigned int nNum)
 *  @brief  设置SDK内部图像缓存节点个数，大于等于1，在抓图前调用
 *  @param  handle                      [IN]            设备句柄
 *  @param  nNum                        [IN]            缓存节点个数
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码
 
 *  @fn     MVID_CR_CAM_SetImageNodeNum(IN void* handle, unsigned int nNum)
 *  @brief  Set the number of the internal image cache nodes in SDK, Greater than or equal to 1, to be called before the capture
 *  @param  handle                      [IN]            Device handle
 *  @param  nNum                        [IN]            Image Node Number
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_SetImageNodeNum(IN void* handle, unsigned int nNum);

/***********************************************************************
 *  @fn     MVID_CR_CAM_SetImageOutPutMode(IN void* handle, MVID_IMGAE_OUTPUT_MODE enImageOutPutMode)
 *  @brief  设置图像输出模式(MVID_OUTPUT_NORMAL - 非MONO8均转换为MVID_IMAGE_BGR24 MVID_OUTPUT_RAW - 以原始图像格式输出)
 *  @param  handle                      [IN]            设备句柄
 *  @param  nNum                        [IN]            图像输出模式
 *  @return 成功，返回MVID_CR_OK；错误，返回错误码
 
 *  @fn     MVID_CR_CAM_SetImageOutPutMode(IN void* handle, MVID_IMGAE_OUTPUT_MODE enImageOutPutMode)
 *  @brief  Set Image OutPutMode
 *  @param  handle                      [IN]            Device handle
 *  @param  nNum                        [IN]            Image OutPut Mode
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_SetImageOutPutMode(IN void* handle, MVID_IMAGE_OUTPUT_MODE enImageOutPutMode);

/************************************************************************
 *  @fn         MVID_CODEREADER_API int __stdcall MVID_CR_RegisterExceptionCallBack(IN void* handle, 
                                                                    IN void(__stdcall* cbException)(unsigned int nMsgType, void* pUser),
                                                                    IN void* pUser)
 *  @brief      注册异常消息回调，在打开设备之后调用
 *  @param      handle            [IN]      设备句柄
 *  @param      cbException       [IN]      异常回调函数指针
 *  @param      pUser             [IN]      用户自定义变量
 *  @return     见返回错误码
 
 *  @fn         MVID_CODEREADER_API int __stdcall MVID_CR_RegisterExceptionCallBack(IN void* handle, 
                                                                    IN void(__stdcall* cbException)(unsigned int nMsgType, void* pUser),
                                                                    IN void* pUser)
 *  @brief      Register Exception Message CallBack, call after open device
 *  @param      handle            [IN]       Device handle
 *  @param      cbException       [IN]       Exception Message CallBack Function Pointer
 *  @param      pUser             [IN]       User defined variable
 *  @return     Refer to error code
************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_RegisterExceptionCallBack(IN void* handle, 
                                                                    IN void(__stdcall* cbException)(unsigned int nMsgType, void* pUser),
                                                                    IN void* pUser);

/************************************************************************
 *  @fn         MVID_CR_SaveImage(IN void* handle, IN MVID_IMAGE_INFO* pstInputImage, IN MVID_IMAGE_TYPE enImageType, IN OUT MVID_IMAGE_INFO* pstOutputImage, IN unsigned int nJpgQuality = 80)
 *  @brief      保存图片，支持Bmp和Jpeg.编码质量在50-99之间
 *  @param      handle                 [IN]           句柄地址
 *  @param      pstInputImage          [IN]           输入图片参数结构体,支持Mono8/BGR24格式图像
 *  @param      enImageType            [IN]           目标转换类型，默认为Jpeg
 *  @param      pstOutputImage         [IN][OUT]      输出图片参数结构体
 *  @param      nJpgQuality            [IN]           JPG压缩质量，默认为80，若目标转换类型为BMP则该参数无效
 *  @return     成功，返回MVID_CR_OK；错误，返回错误码 
 
 *  @fn         MVID_CR_SaveImage(IN void* handle, IN MVID_IMAGE_INFO* pstInputImage, IN MVID_IMAGE_TYPE enImageType, IN OUT MVID_IMAGE_INFO* pstOutputImage, IN unsigned int nJpgQuality = 80)
 *  @brief      Save image, support Bmp and Jpeg. Encoding quality, [50-99]
 *  @param      handle                 [IN]           Handle
 *  @param      pstInputImage          [IN]           Input image parameters structure
 *  @param      enImageType            [IN]           Convery image type，default Jpeg
 *  @param      pstOutputImage         [IN][OUT]      OutPut image parameters structure
 *  @param      nJpgQuality            [IN]           Jpg quality，default quality 80, no use for Bmp image
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_SaveImage(IN void* handle, IN MVID_IMAGE_INFO* pstInputImage, IN MVID_IMAGE_TYPE enImageType, IN OUT MVID_IMAGE_INFO* pstOutputImage, IN unsigned int nJpgQuality = 80);

/***********************************************************************
 *  @fn         MVID_CR_RuleLoad(IN void* handle, char* pFilePath)
 *  @brief      过滤规则导入
 *  @param      handle                 [IN]          句柄
 *  @param      pFilePath              [IN]          过滤规则文件路径，设置NULL为取消过滤
 *  @return     成功，返回MVID_CR_OK；错误，返回错误码
 
 *  @fn         MVID_CR_RuleLoad(IN void* handle, char* pFilePath)
 *  @brief      Load Rule File
 *  @param      handle                 [IN]          Handle
 *  @param      pFilePath              [IN]          FileName of Rule
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_RuleLoad(IN void* handle, IN const char* pFilePath);

/***********************************************************************
 *  @fn         MVID_CR_ScriptLoad(IN void* handle, IN const char* pFilePath, IN const char* pFuncName)
 *  @brief      脚本文件导入
 *  @param      handle                 [IN]          句柄
 *  @param      pFilePath              [IN]          脚本文件路径，设置NULL为取消过滤
 *  @param      pFuncName              [IN]          过滤函数名称
 *  @return     成功，返回MVID_CR_OK；错误，返回错误码
 
 *  @fn         MVID_CR_ScriptLoad(IN void* handle, IN const char* pFilePath, IN const char* pFuncName)
 *  @brief      Load Script File
 *  @param      handle                 [IN]          Handle
 *  @param      pFilePath              [IN]          FilePath of Script
 *  @param      pFuncName              [IN]          Filter Function Name
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_ScriptLoad(IN void* handle, IN const char* pFilePath, IN const char* pFuncName);

#ifdef __cplusplus
}
#endif 

#endif //_MVID_CODEREADER_H_
