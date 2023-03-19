
#ifndef _MVID_CODEREADER_H_
#define _MVID_CODEREADER_H_

#include "MVIDCodeReaderDefine.h"

/**
*  @brief  ��̬�⵼�뵼������
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
 *  @brief  ��ȡSDK�汾��
 *  @param  chVersion           [IN][OUT]       SDK�汾��
 *  @return ����SDK,һά��,��ά��汾�ţ���1.0.0_3.1.0_1.7.0

 *  @fn     MVID_CR_GetVersion(IN OUT char* const chVersion)
 *  @brief  Get SDK Version
 *  @param  chVersion           [IN][OUT]       SDK Version
 *  @return SDK Version 
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_GetVersion(IN OUT char* const chVersion);

/************************************************************************
 *  @fn     MVID_CR_CreateHandle(OUT void ** handle, IN unsigned int nCodeAbility)
 *  @brief  �������
 *  @param  handle                 [OUT]          �����ַ
 *  @param  nCodeAbility           [IN]           ����������
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 
 
 *  @fn     MVID_CR_CreateHandle(OUT void ** handle, IN unsigned int nCodeAbility)
 *  @brief  Create Handle
 *  @param  handle                 [OUT]          Handle Address
 *  @param  nCodeAbility           [IN]           Code Ability
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CreateHandle(OUT void ** handle, IN unsigned int nCodeAbility);

/************************************************************************
 *  @fn     MVID_CR_DestroyHandle(IN void * handle)
 *  @brief  ���پ��
 *  @param  handle                 [IN]          ���
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 
 
 *  @fn     MVID_CR_DestroyHandle(IN void * handle)
 *  @brief  Destroy Handle
 *  @param  handle                 [IN]          Handle
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_DestroyHandle(IN void * handle);

/************************************************************************
 *  @fn     MVID_CR_Algorithm_SetIntValue(IN void* handle, IN const char* const strParamKeyName, IN const int nValue)
 *  @brief  �������Ͳ���
 *  @param  handle                 [IN]          ���
 *  @param  strParamKeyName        [IN]          ���Լ�ֵ
 *  @param  nValue                 [IN]          ����ֵ
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 
 
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
 *  @brief  ��ȡ���Ͳ���
 *  @param  handle                 [IN]          ���
 *  @param  strParamKeyName        [IN]          ���Լ�ֵ
 *  @param  pnValue                [IN][OUT]     ����ֵ
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 
 
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
 *  @brief  ���ø����Ͳ���
 *  @param  handle                 [IN]          ���
 *  @param  strParamKeyName        [IN]          ���Լ�ֵ
 *  @param  fValue                 [IN]          ����ֵ
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 
 
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
 *  @brief  ��ȡ�����Ͳ���
 *  @param  handle                 [IN]          ���
 *  @param  strParamKeyName        [IN]          ���Լ�ֵ
 *  @param  pfValue                [OUT]         ����ֵ
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 
 
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
 *  @brief  �����ַ����Ͳ���
 *  @param  handle                 [IN]          ���
 *  @param  strParamKeyName        [IN]          ���Լ�ֵ
 *  @param  strValue               [IN]          ����ֵ
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 
 
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
 *  @brief  ��ȡ�ַ����Ͳ���
 *  @param  handle                 [IN]          ���
 *  @param  strParamKeyName        [IN]          ���Լ�ֵ
 *  @param  strValue               [OUT]         ����ֵ
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 
 
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
 *  @brief  ����
 *  @param  handle                 [IN]          ���
 *  @param  pstParam               [IN]          ͼƬ��Ϣ�ṹ��
 *  @param  nCodeAbility           [IN]          ����������
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 
 
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
*  @brief  ö���豸
*  @param  pstCamList             [OUT]          �豸�б�
*  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 

*  @fn     MVID_CR_EnumDevices(IN OUT MVID_CAMERA_INFO_LIST* pstCamList)
*  @brief  Enumerate Device
*  @param  pstCamList             [OUT]          Device List
*  @return Success, return MVID_CR_OK. Failure, return error code 
************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_EnumDevices(IN OUT MVID_CAMERA_INFO_LIST* pstCamList);

/************************************************************************
*  @fn     MVID_CR_CAM_EnumDevicesByCfg(IN OUT MVID_CAMERA_INFO_LIST* pstCamList)
*  @brief  ���������ļ�ö��ָ���豸
*  @param  pstCamList             [OUT]          �豸�б�
*  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 

*  @fn     MVID_CR_CAM_EnumDevicesByCfg(IN OUT MVID_CAMERA_INFO_LIST* pstCamList)
*  @brief  Enumerate Specified Series Device
*  @param  pstCamList             [OUT]          Device List
*  @return Success, return MVID_CR_OK. Failure, return error code 
************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_EnumDevicesByCfg(IN OUT MVID_CAMERA_INFO_LIST* pstCamList);

/************************************************************************
 *  @fn     MVID_CR_BindDevice(IN void * handle, IN const MVID_CAMERA_INFO* pstCamInfo)
 *  @brief  ���豸
 *  @param  handle                 [OUT]          �����ַ
 *  @param  pstCamInfo             [IN]           �豸��Ϣ�ṹ��
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 
 
 *  @fn     MVID_CR_BindDevice(IN void * handle, IN const MVID_CAMERA_INFO* pstCamInfo)
 *  @brief  Bind Device
 *  @param  handle                 [OUT]          Handle Address
 *  @param  pstCamInfo             [IN]           Camera Information
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_BindDevice(IN void * handle, IN const MVID_CAMERA_INFO* pstCamInfo);

/************************************************************************
 *  @fn     MVID_CR_CAM_BindDeviceByIP(IN void * handle, IN const char* chCurrentIp, IN const char* chNetExport)
 *  @brief  ͨ��IP���豸
 *  @param  handle                 [OUT]          �����ַ
 *  @param  chCurrentIp            [IN]           ���IP
 *  @param  chNetExport            [IN]           ��ǰPC IP
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 
 
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
 *  @brief  ͨ�����кŰ��豸
 *  @param  handle                 [OUT]          �����ַ
 *  @param  chSerialNumber         [IN]           ������к�
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش����� 
 
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
 *  @brief      ע��ͼ�����ݻص�������������Ϣ
 *  @param       handle                 [IN]          ���
 *  @param       cbOutput               [IN]          �ص�����ָ��
 *  @param       pUser                  [IN]          �û��Զ������
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش�����
 
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
 *  @brief      ע��ͼ�����ݻص���������������Ϣ
 *  @param       handle                 [IN]          ���
 *  @param       cbOutput               [IN]          �ص�����ָ��
 *  @param       pUser                  [IN]          �û��Զ������
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش�����
 
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
 *  @brief      ע��Ԥ����ͼ�����ݻص�
 *  @param       handle                 [IN]          ���
 *  @param       cbPreOutput            [IN]          �ص�����ָ�룬Ԥ������������ڴ���SDK�ڲ�����
 *  @param       pUser                  [IN]          �û��Զ������
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش�����
 
 *  @fn         MVID_CR_CAM_RegisterPreImageCallBack(IN void* handle, 
                                                         IN void(__stdcall* cbPreOutput)(MVID_IMAGE_INFO* pstPreOutput, MVID_IMAGE_INFO* pstProcInput, void* pUser),
                                                         IN void* pUser)
 *  @brief      register pretreatment image data callback
 *  @param       handle                 [IN]          Handle
 *  @param       cbPreOutput            [IN]          Callback function pointer��Preprocessing input parameter memory is allocated internally by the SDK
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
 *  @brief  ע��ȫ���¼��ص����ڴ��豸֮�����,ֻ֧��GIGE
 *  @param  handle��          [IN]      �豸���
 *  @param  cbEvent           [IN]      �û�ע���¼��ص�����
 *  @param  pUser             [IN]      �û��Զ������
 *  @return �����ش�����
 
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
 *  @brief      ��ʼȡ��
 *  @param       handle                 [IN]          ���
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش�����
 
 *  @fn         MVID_CR_CAM_StartGrabbing(IN void* handle)
 *  @brief      Start Grabbing
 *  @param      handle                 [IN]          Handle
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_StartGrabbing(IN void* handle);

/***********************************************************************
 *  @fn         MVID_CR_CAM_StopGrabbing(IN void* handle)
 *  @brief      ֹͣȡ��
 *  @param       handle                 [IN]          ���
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش�����
 
 *  @fn         MVID_CR_CAM_StopGrabbing(IN void* handle)
 *  @brief      Stop Grabbing
 *  @param      handle                 [IN]          Handle
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_StopGrabbing(IN void* handle);

/***********************************************************************
 *  @fn         MVID_CR_CAM_GetOneFrameTimeout(IN void* handle, IN OUT MVID_CAM_OUTPUT_INFO* pFrameInfo, IN unsigned int nMsec)
 *  @brief      ���ó�ʱ���ƻ�ȡһ֡ͼƬ��SDK�ڲ��ȴ�ֱ��������ʱ���أ�����������Ϣ
 *  @param       handle                 [IN]          ���
 *  @param       pFrameInfo             [OUT]         ͼ����Ϣ�ṹ��
 *  @param       nMsec                  [IN]          �ȴ���ʱʱ��
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش�����
 
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
 *  @brief      ���ó�ʱ���ƻ�ȡһ֡ͼƬ��SDK�ڲ��ȴ�ֱ��������ʱ���أ�������������Ϣ
 *  @param       handle                 [IN]          ���
 *  @param       pImageInfo             [OUT]         ͼ����Ϣ�ṹ��
 *  @param       nMsec                  [IN]          �ȴ���ʱʱ��
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش�����
 
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
 *  @brief      �������Int������ֵ
 *  @param      handle                [IN]        ������
 *  @param      strKey                [IN]        ���Լ�ֵ�����ȡ�����Ϣ��Ϊ"Width"
 *  @param      nValue                [IN]        ��Ҫ���õ����������ֵ
 *  @return     �ɹ�,����MVID_CR_OK,ʧ��,���ش�����
 
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
 *  @brief      ��ȡInt����ֵ
 *  @param      handle                [IN]              ������
 *  @param      strKey                [IN]              ���Լ�ֵ�����ȡ�����Ϣ��Ϊ"Width"
 *  @param      pIntValue             [IN][OUT]         ���ظ��������й�������Խṹ��ָ��
 *  @return     �ɹ�,����MVID_CR_OK,ʧ��,���ش�����
 
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
 *  @brief      �������Enum������ֵ
 *  @param      handle                [IN]        ������
 *  @param      strKey                [IN]        ���Լ�ֵ�����ȡ���ظ�ʽ��Ϣ��Ϊ"PixelFormat"
 *  @param      nValue                [IN]        ��Ҫ���õ����������ֵ
 *  @return     �ɹ�,����MVID_CR_OK,ʧ��,���ش�����
 
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
 *  @brief      ͨ���ַ����������Enum������ֵ
 *  @param      handle                [IN]        ������
 *  @param      strKey                [IN]        ���Լ�ֵ�����ȡ���ظ�ʽ��Ϣ��Ϊ"PixelFormat"
 *  @param      sValue                [IN]        ��Ҫ���õ�����������ַ���
 *  @return     �ɹ�,����MVID_CR_OK,ʧ��,���ش�����
 
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
 *  @brief      ��ȡ���Enum����ֵ
 *  @param      handle                   [IN]        ������
 *  @param      strKey                   [IN]        ���Լ�ֵ�����ȡ���ظ�ʽ��Ϣ��Ϊ"PixelFormat"
 *  @param      pEnumValue               [IN][OUT]   ���ظ��������й�������Խṹ��ָ��
 *  @return     �ɹ�,����MVID_CR_OK,ʧ��,���ش�����
 
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
 *  @brief      �������Float������ֵ
 *  @param      handle                [IN]        ������
 *  @param      strKey                [IN]        ���Լ�ֵ
 *  @param      fValue                [IN]        ��Ҫ���õ����������ֵ
 *  @return     �ɹ�,����MVID_CR_OK,ʧ��,���ش�����
 
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
 *  @brief      ��ȡ���Float����ֵ
 *  @param      handle                     [IN]        ������
 *  @param      strKey                     [IN]        ���Լ�ֵ
 *  @param      pFloatValue                [IN][OUT]   ���ظ��������й�������Խṹ��ָ��
 *  @return     �ɹ�,����MVID_CR_OK,ʧ��,���ش�����
 
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
 *  @brief      �������String������ֵ
 *  @param      handle                  [IN]        ������
 *  @param      strKey                  [IN]        ���Լ�ֵ
 *  @param      sValue                  [IN]        ��Ҫ���õ����������ֵ
 *  @return     �ɹ�,����MVID_CR_OK,ʧ��,���ش�����
 
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
 *  @brief      ��ȡ���String����ֵ
 *  @param      handle                       [IN]        ������
 *  @param      strKey                       [IN]        ���Լ�ֵ
 *  @param      pStringValue                 [IN][OUT]   ���ظ��������й�������Խṹ��ָ��
 *  @return     �ɹ�,����MVID_CR_OK,ʧ��,���ش�����
 
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
 *  @brief      �������Boolean������ֵ
 *  @param      handle                [IN]        ������
 *  @param      strKey                [IN]        ���Լ�ֵ
 *  @param      bValue                [IN]        ��Ҫ���õ����������ֵ
 *  @return     �ɹ�,����MVID_CR_OK,ʧ��,���ش�����
 
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
 *  @brief      ��ȡ���Boolean����ֵ
 *  @param      handle                     [IN]        ������
 *  @param      strKey                     [IN]        ���Լ�ֵ
 *  @param      pBoolValue                 [IN][OUT]   ���ظ��������й��������ֵ
 *  @return     �ɹ�,����MVID_CR_OK,ʧ��,���ش�����
 
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
 *  @brief      �������Command������ֵ
 *  @param      handle                  [IN]        ������
 *  @param      strKey                  [IN]        ���Լ�ֵ
 *  @return     �ɹ�,����MVID_CR_OK,ʧ��,���ش�����
 
 *  @fn         MVID_CR_CAM_SetCommandValue(IN void* handle, IN const char* strKey)
 *  @brief      Set Camera Command value
 *  @param      handle                  [IN]        Handle
 *  @param      strKey                  [IN]        Key value
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_SetCommandValue(IN void* handle, IN const char* strKey);

/***********************************************************************
 *  @fn     MVID_CR_CAM_SetImageNodeNum(IN void* handle, unsigned int nNum)
 *  @brief  ����SDK�ڲ�ͼ�񻺴�ڵ���������ڵ���1����ץͼǰ����
 *  @param  handle                      [IN]            �豸���
 *  @param  nNum                        [IN]            ����ڵ����
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش�����
 
 *  @fn     MVID_CR_CAM_SetImageNodeNum(IN void* handle, unsigned int nNum)
 *  @brief  Set the number of the internal image cache nodes in SDK, Greater than or equal to 1, to be called before the capture
 *  @param  handle                      [IN]            Device handle
 *  @param  nNum                        [IN]            Image Node Number
 *  @return Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_CAM_SetImageNodeNum(IN void* handle, unsigned int nNum);

/***********************************************************************
 *  @fn     MVID_CR_CAM_SetImageOutPutMode(IN void* handle, MVID_IMGAE_OUTPUT_MODE enImageOutPutMode)
 *  @brief  ����ͼ�����ģʽ(MVID_OUTPUT_NORMAL - ��MONO8��ת��ΪMVID_IMAGE_BGR24 MVID_OUTPUT_RAW - ��ԭʼͼ���ʽ���)
 *  @param  handle                      [IN]            �豸���
 *  @param  nNum                        [IN]            ͼ�����ģʽ
 *  @return �ɹ�������MVID_CR_OK�����󣬷��ش�����
 
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
 *  @brief      ע���쳣��Ϣ�ص����ڴ��豸֮�����
 *  @param      handle            [IN]      �豸���
 *  @param      cbException       [IN]      �쳣�ص�����ָ��
 *  @param      pUser             [IN]      �û��Զ������
 *  @return     �����ش�����
 
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
 *  @brief      ����ͼƬ��֧��Bmp��Jpeg.����������50-99֮��
 *  @param      handle                 [IN]           �����ַ
 *  @param      pstInputImage          [IN]           ����ͼƬ�����ṹ��,֧��Mono8/BGR24��ʽͼ��
 *  @param      enImageType            [IN]           Ŀ��ת�����ͣ�Ĭ��ΪJpeg
 *  @param      pstOutputImage         [IN][OUT]      ���ͼƬ�����ṹ��
 *  @param      nJpgQuality            [IN]           JPGѹ��������Ĭ��Ϊ80����Ŀ��ת������ΪBMP��ò�����Ч
 *  @return     �ɹ�������MVID_CR_OK�����󣬷��ش����� 
 
 *  @fn         MVID_CR_SaveImage(IN void* handle, IN MVID_IMAGE_INFO* pstInputImage, IN MVID_IMAGE_TYPE enImageType, IN OUT MVID_IMAGE_INFO* pstOutputImage, IN unsigned int nJpgQuality = 80)
 *  @brief      Save image, support Bmp and Jpeg. Encoding quality, [50-99]
 *  @param      handle                 [IN]           Handle
 *  @param      pstInputImage          [IN]           Input image parameters structure
 *  @param      enImageType            [IN]           Convery image type��default Jpeg
 *  @param      pstOutputImage         [IN][OUT]      OutPut image parameters structure
 *  @param      nJpgQuality            [IN]           Jpg quality��default quality 80, no use for Bmp image
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ************************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_SaveImage(IN void* handle, IN MVID_IMAGE_INFO* pstInputImage, IN MVID_IMAGE_TYPE enImageType, IN OUT MVID_IMAGE_INFO* pstOutputImage, IN unsigned int nJpgQuality = 80);

/***********************************************************************
 *  @fn         MVID_CR_RuleLoad(IN void* handle, char* pFilePath)
 *  @brief      ���˹�����
 *  @param      handle                 [IN]          ���
 *  @param      pFilePath              [IN]          ���˹����ļ�·��������NULLΪȡ������
 *  @return     �ɹ�������MVID_CR_OK�����󣬷��ش�����
 
 *  @fn         MVID_CR_RuleLoad(IN void* handle, char* pFilePath)
 *  @brief      Load Rule File
 *  @param      handle                 [IN]          Handle
 *  @param      pFilePath              [IN]          FileName of Rule
 *  @return     Success, return MVID_CR_OK. Failure, return error code
 ***********************************************************************/
MVID_CODEREADER_API int __stdcall MVID_CR_RuleLoad(IN void* handle, IN const char* pFilePath);

/***********************************************************************
 *  @fn         MVID_CR_ScriptLoad(IN void* handle, IN const char* pFilePath, IN const char* pFuncName)
 *  @brief      �ű��ļ�����
 *  @param      handle                 [IN]          ���
 *  @param      pFilePath              [IN]          �ű��ļ�·��������NULLΪȡ������
 *  @param      pFuncName              [IN]          ���˺�������
 *  @return     �ɹ�������MVID_CR_OK�����󣬷��ش�����
 
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
