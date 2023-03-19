
#ifndef _MVID_CODEREADER_DEFINE_H_
#define _MVID_CODEREADER_DEFINE_H_

// ch:正确码定义 | en://Definition of correct code
#define MVID_CR_OK                  0x00000000  ///< ch:成功，无错误 | en:Successed, no error

//ch:通用错误码定义:范围0x80000000-0x800000FF | en:
#define MVID_CR_E_HANDLE            0x80000000  ///< ch:错误或无效的句柄 | en:Error or invalid handle
#define MVID_CR_E_SUPPORT           0x80000001  ///< ch:不支持的功能 | en:The function is not supported
#define MVID_CR_E_BUFOVER           0x80000002  ///< ch:缓存已满 | en:Buffer is full
#define MVID_CR_E_CALLORDER         0x80000003  ///< ch:函数调用顺序错误 | en:Incorrect calling sequence
#define MVID_CR_E_PARAMETER         0x80000004  ///< ch:错误的参数 | en:Incorrect parameter
#define MVID_CR_E_RESOURCE          0x80000005  ///< ch:资源申请失败 | en:Applying resource failed
#define MVID_CR_E_NODATA            0x80000006  ///< ch:无数据 | en:No data
#define MVID_CR_E_PRECONDITION      0x80000007  ///< ch:前置条件有误，或运行环境已发生变化 | en:Precondition error, or running environment changed
#define MVID_CR_E_ENCRYPT           0x80000008  ///< ch:凭证错误，可能是未插加密狗，或加密狗过期 | en:Credential error, possibly because the dongle was not installed or expired.
#define MVID_CR_E_RULE              0x8000000A  ///< ch:过滤规则相关的错误 | en:Filter rule error.
#define MVID_CR_E_LOAD_LIBRARY      0x8000000B  ///< ch:动态导入DLL失败 | en:Dynamically importing the DLL file failed.
#define MVID_CR_E_JPGENC            0x80000012  ///< ch:jpg编码相关错误 | en:Jpg encoding error.
#define MVID_CR_E_IMAGE             0x80000013  ///< ch:输入的图像数据有损或图像格式,宽高错误 | en:Abnormal image. Incomplete image caused by packet loss or incorrect image format, width, or height.
#define MVID_CR_E_CONVERT           0x80000014  ///< ch:格式转换错误 | en:Format conversion error
#define MVID_CR_E_UNKNOW            0x800000FF  ///< ch:未知的错误 | en:Unknown error

// ch:GenICam系列错误:范围0x80000100-0x800001FF | en:GenICam Series Error Codes: Range from 0x80000100 to 0x800001FF
#define MVID_CR_E_GC_GENERIC        0x80000100  ///< ch:通用错误 | en:General error
#define MVID_CR_E_GC_ARGUMENT       0x80000101  ///< ch:参数非法 | en:Invalid parameter
#define MVID_CR_E_GC_RANGE          0x80000102  ///< ch:值超出范围 | en:The value is out of range
#define MVID_CR_E_GC_PROPERTY       0x80000103  ///< ch:属性错误 | en:Attribute error
#define MVID_CR_E_GC_RUNTIME        0x80000104  ///< ch:运行环境有问题 | en:Running environment error
#define MVID_CR_E_GC_LOGICAL        0x80000105  ///< ch:逻辑错误 | en:Incorrect logic
#define MVID_CR_E_GC_ACCESS         0x80000106  ///< ch:节点访问条件有误 | en:Node accessing condition error
#define MVID_CR_E_GC_TIMEOUT        0x80000107  ///< ch:超时 | en:Timeout
#define MVID_CR_E_GC_DYNAMICCAST    0x80000108  ///< ch:转换异常 | en:Transformation exception
#define MVID_CR_E_GC_UNKNOW         0x800001FF  ///< ch:GenICam未知错误 | en:GenICam unknown error

// ch:GigE_STATUS对应的错误码:范围0x80000200-0x800002FF | en:GigE_STATUS Error Codes: Range from 0x80000200 to 0x800002FF
#define MVID_CR_E_NOT_IMPLEMENTED   0x80000200  ///< ch:命令不被设备支持 | en:The command is not supported by device
#define MVID_CR_E_INVALID_ADDRESS   0x80000201  ///< ch:访问的目标地址不存在 | en:Target address does not exist
#define MVID_CR_E_WRITE_PROTECT     0x80000202  ///< ch:目标地址不可写 | en:The target address is not writable
#define MVID_CR_E_ACCESS_DENIED     0x80000203  ///< ch:设备无访问权限 | en:No access permission
#define MVID_CR_E_BUSY              0x80000204  ///< ch:设备忙，或网络断开 | en:Device is busy, or network is disconnected
#define MVID_CR_E_PACKET            0x80000205  ///< ch:网络包数据错误 | en:Network packet error
#define MVID_CR_E_NETER             0x80000206  ///< ch:网络相关错误 | en:Network error

// ch:GigE相机特有的错误码
#define MVID_CR_E_IP_CONFLICT       0x80000221  ///< ch:设备IP冲突 | en:IP address conflicted

// ch:USB_STATUS对应的错误码:范围0x80000300-0x800003FF | en:USB_STATUS Error Codes: Range from 0x80000300 to 0x800003FF
#define MVID_CR_E_USB_READ          0x80000300      ///< ch:读usb出错 | en:USB read error
#define MVID_CR_E_USB_WRITE         0x80000301      ///< ch:写usb出错 | en:USB write error
#define MVID_CR_E_USB_DEVICE        0x80000302      ///< ch:设备异常 | en:Device exception
#define MVID_CR_E_USB_GENICAM       0x80000303      ///< ch:GenICam相关错误 | en:GenICam error
#define MVID_CR_E_USB_BANDWIDTH     0x80000304      ///< ch:带宽不足  该错误码新增 | en:Insufficient bandwidth, this error code is newly added
#define MVID_CR_E_USB_DRIVER        0x80000305      ///< ch:驱动不匹配或者未装驱动 | en:Driver is mismatched, or is not installed.
#define MVID_CR_E_USB_UNKNOW        0x800003FF      ///< ch:USB未知的错误 | en:USB unknown error

#define MVID_CR_E_CAMERA            0x80002100      ///< ch:相机相关的错误 | en:Camera error
#define MVID_CR_E_BCR               0x80002200      ///< ch:一维码相关错误 | en:1D barcode error
#define MVID_CR_E_TDCR              0x80002300      ///< ch:二维码相关错误 | en:2D barcode error
#define MVID_CR_E_WAYBILL           0x80002400      ///< ch:抠图相关错误 | en:Matting error
#define MVID_CR_E_SCRIPT            0x80002500      ///< ch:脚本规则相关错误 | en:Script rule error


#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif

// ch:跨平台定义 | en:Cross Platform Definition
#ifdef WIN32
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

#ifndef __cplusplus
typedef char    bool;
#define true    1
#define false   0
#endif


// 相机类型定义
#define MVID_GIGE_CAM          0x00000001          // ch:GigE设备 | en:GigE Device
#define MVID_USB_CAM           0x00000004          // ch:USB3.0 设备 | en:USB3.0 Device

// ch: 异常消息类型 | en:Exception message type
#define MVID_EXCEPTION_DEV_DISCONNECT          0x00008001      // ch:设备断开连接 | en:The device is disconnected
#define MVID_EXCEPTION_SOFTDOG_DISCONNECT      0x00008002      // ch:加密狗掉线 | en:The softdog is disconnected

typedef struct _MVID_CAMERA_INFO_
{
    //相机通用属性
    unsigned int        nCamType;                       // ch:相机类型，G口或U口 | en:Camera type: USB, GigE
    unsigned char       chManufacturerName[32];         // ch:制造商名字 | en:Manufacturer Name
    unsigned char       chModelName[32];                // ch:型号名字 | en:Model Name
    unsigned char       chDeviceVersion[32];            // ch:设备版本号 | en:Device version No.
    unsigned char       chManufacturerSpecificInfo[48]; // ch:制造商特定的信息 | en:Manufacturer specific information
    unsigned char       chSerialNumber[16];             // ch:序列号 | en:Device serial No.
    unsigned char       chUserDefinedName[16];          // ch:用户自定义名字 | en:Custom name 
    unsigned int        nMacAddrHigh;                   // ch:MAC 地址 高位| en:High MAC address
    unsigned int        nMacAddrLow;                    // ch:MAC 地址 低位| en:Low MAC address
    unsigned int        nCommomReaserved[8];            // ch:保留| en:Reserved 


    // 网口相机属性
    unsigned int        nCurrentIp;                 // ch:当前IP | en:Current IP address 
    unsigned int        nNetExport;                 // ch:网口IP地址 | en:GIGE IP Address
    unsigned int        nGigEReserved[32];          // ch:gige保留 | en:GigE Reserved


    // U口相机属性
    unsigned char       CrtlInEndPoint;             // ch:控制输入端点 | en:Control input endpoint
    unsigned char       CrtlOutEndPoint;            // ch:控制输出端点 | en:Control output endpoint
    unsigned char       StreamEndPoint;             // ch:流端点 | en:Stream endpoint
    unsigned char       EventEndPoint;              // ch:事件端点 | en:Event endpoint
    unsigned short      idVendor;                   // ch:供应商ID号 | en:Vendor ID 
    unsigned short      idProduct;                  // ch:产品ID号 | en:Product ID 
    unsigned int        nDeviceNumber;              // ch:设备序列号 | en:Device ID 
    unsigned int        nUsbReserved[31];           // ch:USB保留 | en:Usb Reserved

    // 是否为指定系列型号相机
    // true -指定系列型号相机 false- 非指定系列型号相机
    bool                bSelectDevice;              // ch:选择设备 |en:Choose device

    // 保留字节
    unsigned int        nReserved[63];              // ch:保留| en:Reserved 

}MVID_CAMERA_INFO;

#define MVID_MAX_CAM_NUM      256                   // ch:最大支持的设备个数 | en:The maximum number of supported devices

// ch:设备信息列表 | en:Device Information List
typedef struct _MVID_CAMERA_INFO_LIST_
{
    OUT unsigned int            nCamNum;                            // ch:在线设备数量 | en:The number of online devices
    OUT MVID_CAMERA_INFO*       pstCamInfo[MVID_MAX_CAM_NUM];       // ch:支持最多256个设备 | en:Device information, up to 256 devices can be supported

}MVID_CAMERA_INFO_LIST;


// 处理能力集
#define MVID_BCR                0x00000001          // ch:一维码 | en:One-dimensional code
#define MVID_TDCR               0x00000002          // ch:二维码 | en:Two-dimensional code
#define MVID_WAYBILL            0x00000004          // ch:面单抠图 | en:Image Matting

typedef enum _MVID_CODE_TYPE_
{
    MVID_CODE_NONE        = 0,                  // ch:无可识别条码 | en:No recognizable bar code

    // 二维码
    MVID_CODE_TDCR_DM          = 1,             // ch:DM码 | en:DM code
    MVID_CODE_TDCR_QR          = 2,             // ch:QR码 | en:QR code

    // 一维码
    MVID_CODE_BCR_EAN8    = 8,                  // ch:EAN8码 | en:EAN8 code
    MVID_CODE_BCR_UPCE    = 9,                  // ch:UPCE码 | en:UPCE code
    MVID_CODE_BCR_UPCA    = 12,                 // ch:UPCA码 | en:UPCA code
    MVID_CODE_BCR_EAN13   = 13,                 // ch:EAN13码 | en:EAN13 code
    MVID_CODE_BCR_ISBN13  = 14,                 // ch:ISBN13码 | en:ISBN13 code
    MVID_CODE_BCR_CODABAR = 20,                 // ch:库德巴码 | en:Codabar code
    MVID_CODE_BCR_ITF25   = 25,                 // ch:交叉25码 | en:ITF25 code
    MVID_CODE_BCR_CODE39  = 39,                 // ch:Code 39 | en:Code 39
    MVID_CODE_BCR_CODE93  = 93,                 // ch:Code 93 | en:Code 93
    MVID_CODE_BCR_CODE128 = 128,                // ch:Code 128 | en:Code 128
} MVID_CODE_TYPE;

// 图像格式
typedef enum _MVID_IMAGE_TYPE_
{
    MVID_IMAGE_Undefined            = 0,    // ch:未定义 | en:Undefined format
    MVID_IMAGE_MONO8                = 1,    // ch:Mono8 | en:MONO8 format
    MVID_IMAGE_JPEG                 = 2,    // ch:JPEG | en:JPEG format
    MVID_IMAGE_BMP                  = 3,    // ch:Bmp | en:BMP format
    MVID_IMAGE_RGB24                = 4,    // ch:RGB24 | en:RGB format
    MVID_IMAGE_BGR24                = 5,    // ch:BGR24 | en:BGR format

    MVID_IMAGE_MONO10               = 6,    // ch:Mono10 | en:Mono10 format
    MVID_IMAGE_MONO10_Packed        = 7,    // ch:Mono10_Packed | en:Mono10_Packed format
    MVID_IMAGE_MONO12               = 8,    // ch:Mono12 | en:Mono12 format
    MVID_IMAGE_MONO12_Packed        = 9,    // ch:Mono12_Packed | en:Mono12_Packed format
    MVID_IMAGE_MONO16               = 10,   // ch:Mono16 | en:Mono16 format
    MVID_IMAGE_BayerGR8             = 11,   // ch:BGR8 | en:BGR8 format
    MVID_IMAGE_BayerRG8             = 12,   // ch:BRG8 | en:BRG8 format
    MVID_IMAGE_BayerGB8             = 13,   // ch:BGB8 | en:BGB8 format
    MVID_IMAGE_BayerBG8             = 14,   // ch:BBG8 | en:BBG8 format
    MVID_IMAGE_BayerGR10            = 15,   // ch:BGR10 | en:BGR10 format
    MVID_IMAGE_BayerRG10            = 16,   // ch:BRG10 | en:BRG10 format
    MVID_IMAGE_BayerGB10            = 17,   // ch:BGB10 | en:BGB10 format
    MVID_IMAGE_BayerBG10            = 18,   // ch:BBG10 | en:BBG10 format
    MVID_IMAGE_BayerGR12            = 19,   // ch:BGR12 | en:BGR12 format
    MVID_IMAGE_BayerRG12            = 20,   // ch:BRG12 | en:BRG12 format
    MVID_IMAGE_BayerGB12            = 21,   // ch:BGB12 | en:BGB12 format
    MVID_IMAGE_BayerBG12            = 22,   // ch:BBG12 | en:BBG12 format
    MVID_IMAGE_BayerGR10_Packed     = 23,   // ch:BGR10_Packed | en:BGR10_Packed format
    MVID_IMAGE_BayerRG10_Packed     = 24,   // ch:BRG10_Packed | en:BRG10_Packed format
    MVID_IMAGE_BayerGB10_Packed     = 25,   // ch:BGB10_Packed | en:BGB10_Packed format
    MVID_IMAGE_BayerBG10_Packed     = 26,   // ch:BBG10_Packed | en:BBG10_Packed format
    MVID_IMAGE_BayerGR12_Packed     = 27,   // ch:BGR12_Packed | en:BGR12_Packed format
    MVID_IMAGE_BayerRG12_Packed     = 28,   // ch:BRG12_Packed | en:BRG12_Packed format
    MVID_IMAGE_BayerGB12_Packed     = 29,   // ch:BGB12_Packed | en:BGB12_Packed format
    MVID_IMAGE_BayerBG12_Packed     = 30,   // ch:BBG12_Packed | en:BBG12_Packed format
    MVID_IMAGE_YUV422_Packed        = 31,   // ch:YUV422_Packed | en:YUV422_Packed format
    MVID_IMAGE_YUV422_YUYV_Packed   = 32,   // ch:YUV422_YUYV_Packed | en:YUV422_YUYV_Packed format
    MVID_IMAGE_RGB8_Packed          = 33,   // ch:RGB8_Packed | en:RGB8_Packed format
    MVID_IMAGE_BGR8_Packed          = 34,   // ch:BGR8_Packed | en:BGR8_Packed format
    MVID_IMAGE_RGBA8_Packed         = 35,   // ch:RGBA8_Packed | en:RGBA8_Packed format
    MVID_IMAGE_BGRA8_Packed         = 36,   // ch:BGRA8_Packed | en:BGRA8_Packed format
}MVID_IMAGE_TYPE;

// 条码标识
typedef enum _MVID_CODE_FLAG_
{
    MVID_CODE_CORRECT           = 0,    // ch:正常条码 | en:Normal bar code
    MVID_CODE_FILTERED          = 1,    // ch:过滤条码 | en:Filter bar code
}MVID_CODE_FLAG;

typedef enum _MVID_IMAGE_OUTPUT_MODE_
{
    MVID_OUTPUT_NORMAL          = 0,      // ch:常规输出 | en:normal output
    MVID_OUTPUT_RAW             = 1,      // ch:原图输出 | en:raw output
}MVID_IMAGE_OUTPUT_MODE;

// ch:输出图像的信息 | en:Output Frame Information
typedef struct _MVID_IMAGE_INFO_
{
    OUT unsigned char*      pImageBuf;          // ch:原始图像缓存，由SDK内部分配 | en:Original image buffer
    OUT unsigned int        nImageLen;          // ch:原始图像长度 | en:Original image size
    OUT MVID_IMAGE_TYPE     enImageType;        // ch:图像格式 | en:Image Type
    OUT unsigned short      nWidth;             // ch:图像宽 | en:Image Width
    OUT unsigned short      nHeight;            // ch:图像高 | en:Image Height

    OUT unsigned int        nFrameNum;          // ch:帧号 | en:Frame No.
    OUT unsigned int        nDevTimeStampHigh;  // ch:时间戳高32位 | en:Timestamp high 32 bits
    OUT unsigned int        nDevTimeStampLow;   // ch:时间戳低32位 | en:Timestamp low 32 bits

    unsigned int            nReserved[32];      // ch:保留 | en:Reserved
}MVID_IMAGE_INFO;

typedef struct _MVID_POINT_I_
{
    int             nX;                         // ch:X坐标 | en:X-coordinate
    int             nY;                         // ch:Y坐标 | en:Y-coordinate
} MVID_POINT_I;

#define     MVID_MAX_CODECHARATERLEN        4096    // ch:最大条码长度 | en:Maximum barcode length
#define     MVID_MAX_CODENUM                256     // ch:最大条码数量 | en:Maximum number of barcodes

typedef struct _MVID_CODE_INFO_
{
    unsigned char           strCode[MVID_MAX_CODECHARATERLEN];      // ch:字符 | en:Character, maximum size: 4096
    int                     nLen;                                   // ch:字符长度 | en:Character size
    MVID_CODE_TYPE          enBarType;                              // ch:条码类型 | en:Bar code type
    MVID_POINT_I            stCornerPt[4];                          // ch:条码位置 | en:Bar code location
    int                     nAngle;                                 // ch:条码角度（0~3600） | en:Bar code angle, range: [0, 3600°]
    int                     nFilterFlag;                            // ch:过滤码标识(0为正常码，1为过滤码) | en:Filter identifier: 0- normal code, 1-filter code
    unsigned int            nReserved[31];                          // ch:保留 | en:Reserved
}MVID_CODE_INFO;

typedef struct _MVID_CODE_INFO_LIST_
{
    int                     nCodeNum;                       // ch:条码数量 | en:The number of bar codes
    MVID_CODE_INFO          stCodeInfo[MVID_MAX_CODENUM];   // ch:条码信息 | en:Bar code information, maximum size: 256

    unsigned int            nReserved[32];                  // ch:保留 | en:Reserved
}MVID_CODE_INFO_LIST;

typedef struct _MVID_CAM_OUTPUT_INFO_
{
    OUT MVID_IMAGE_INFO         stImage;            // ch:输出图像的信息 | en:Image information
    OUT MVID_CODE_INFO_LIST     stCodeList;         // ch:条码信息列表 | en:Bar code information

    OUT unsigned char*          pImageWaybill;      // ch:抠图缓存，由SDK内部分配 | en:Image matting buffer
    OUT unsigned int            nImageWaybillLen;   // ch:图像大小 | en:Image size
    OUT MVID_IMAGE_TYPE         enWaybillImageType; // ch:抠图图像格式 | en:Image format

    unsigned int                nReserved[31];      // ch:保留 | en:Reserved
}MVID_CAM_OUTPUT_INFO;

typedef struct _MVID_PROC_PARAM_
{
    IN unsigned char*       pImageBuf;              // ch:原始图像缓存，由用户传入 | en:Original image buffer
    IN unsigned int         nImageLen;              // ch:原始图像长度 | en:Original image size
    IN MVID_IMAGE_TYPE      enImageType;            // ch:输入图像的格式 | en:Image type
    IN unsigned short       nWidth;                 // ch:图像宽 | en:Image width
    IN unsigned short       nHeight;                // ch:图像高 | en:Image height

    OUT MVID_CODE_INFO_LIST stCodeList;             // ch:条码信息 | en:Bar code information

    OUT unsigned char*      pImageWaybill;          // ch:抠图缓存，由SDK内部分配 | en:Matting buffer, which is allocated by SDK
    OUT unsigned int        nImageWaybillLen;       // ch:图像大小 | en:Image size
    OUT MVID_IMAGE_TYPE     enWaybillImageType;     // ch:抠图图像格式 | en:The format of the matted image

    unsigned int            nReserved[31];          // ch:保留 | en:Reserved
}MVID_PROC_PARAM;

#define MVID_MAX_XML_SYMBOLIC_NUM      64           // ch:每个已经实现单元的名称数量 | en:The number of names of each implemented unit

typedef struct _MVID_CR_CAM_INTVALUE_
{
    unsigned int    nCurValue;      // ch:当前值 | en:Current Value
    unsigned int    nMax;           // ch:最大值 | en:The maximum value
    unsigned int    nMin;           // ch:最小值 | en:The minimum value
    unsigned int    nInc;           // ch:增量值 | en:Increment

    unsigned int    nReserved[4];   // ch:保留 | en:Reserved
}MVID_CAM_INTVALUE;

typedef struct _MVID_CAM_INTVALUE_EX_
{
    int64_t    nCurValue;           // ch:当前值 | en:Current Value
    int64_t    nMax;                // ch:最大值 | en:The maximum value
    int64_t    nMin;                // ch:最小值 | en:The minimum value
    int64_t    nInc;                // ch:增量值 | en:Increment

    unsigned int    nReserved[16];  // ch:保留 | en:Reserved
}MVID_CAM_INTVALUE_EX;

typedef struct _MVID_CAM_ENUMVALUE_
{
    unsigned int    nCurValue;                                  // ch:当前值 | en:Current Value
    unsigned int    nSupportedNum;                              // ch:数据的有效数据个数 | The number of valid data
    unsigned int    nSupportValue[MVID_MAX_XML_SYMBOLIC_NUM];   // ch:支持的枚举类型，每个数组表示一种类型，最大大小为：64 | en:Supported enumeration types, each array indicates one type, , maximum size: 64

    unsigned int    nReserved[4];                               // ch:保留 | en:Reserved
}MVID_CAM_ENUMVALUE;

typedef struct _MVID_CAM_FLOATVALUE_
{
    float           fCurValue;      // ch:当前值 | en:Current Value
    float           fMax;           // ch:最大值 | en:The maximum value
    float           fMin;           // ch:最小值 | en:The minimum value

    unsigned int    nReserved[4];   // ch:保留 | en:Reserved
}MVID_CAM_FLOATVALUE;

typedef struct _MVID_CAM_STRINGVALUE_
{
    char   chCurValue[256];         // ch:当前值 | en:Current Value

    int64_t nMaxLength;             // ch:最大长度 | en:The maximum size
    unsigned int    nReserved[2];   // ch:保留字节 | en:Reserved
}MVID_CAM_STRINGVALUE;

//Event事件回调信息 | en:Event callback infomation
#define MVID_MAX_EVENT_NAME_SIZE     128                    // ch:相机Event事件名称最大长度 | en:Max length of event name

typedef struct _MVID_EVENT_OUT_INFO_
{
    char            EventName[MVID_MAX_EVENT_NAME_SIZE];    // ch:Event名称 | en:Event name, , maximum size: 128

    unsigned short  nEventID;                               // ch:Event号 | en:Event ID
    unsigned short  nStreamChannel;                         // ch:流通道序号 | en:Stream channel ID

    unsigned int    nBlockIdHigh;                           // ch:帧号高位 | en:High frame ID
    unsigned int    nBlockIdLow;                            // ch:帧号低位 | en:Low frame ID

    unsigned int    nTimestampHigh;                         // ch:时间戳高位 | en:High timestamp
    unsigned int    nTimestampLow;                          // ch:时间戳低位 | en:Low timestamp

    void *          pEventData;                             // ch:Event数据 | en:Event data
    unsigned int    nEventDataSize;                         // ch:Event数据长度 | en:Event data size

    unsigned int    nReserved[16];                          // ch:预留 | en:Reserved
}MVID_EVENT_OUT_INFO;

#define MVID_ALGORITHM_MIN_WIDTH        128                 // ch:算法支持最小宽度 | en:Algorithm supports minimum width
#define MVID_ALGORITHM_MIN_HEIGHT       128                 // ch:算法支持最小高度 | en:Algorithm supports minimum height

/************************************************************************/
/* 一维码参数，内部有默认值，可以不设置                                 */
/************************************************************************/
#define KEY_BCR_ABILITY                 "BCR_Ability"               // ch:算法能力集，含Code39[1]，Code128[2]，CodeBar[4]，EAN[8]，ITF25[16]，CODE93[32]，默认值63，范围[0,63] | en:Algorithm capability set.contain:Code39[1]，Code128[2]，CodeBar[4]，EAN[8]，ITF25[16]，CODE93[32],Range: [0, 63], default: 63
#define KEY_BCR_ROI_X                   "BCR_PositionXROI"          // ch:图像ROI X方向偏移，默认值0，范围[0,65535] | en:Image ROI X direction offset,Range: [0,65535], default: 0
#define KEY_BCR_ROI_Y                   "BCR_PositionYROI"          // ch:图像ROI Y方向偏移，默认值0，范围[0,65535] | en:Image ROI Y direction offset,Range: [0,65535], default: 0
#define KEY_BCR_ROI_WIDTH               "BCR_WidthROI"              // ch:图像ROI宽度，默认值65535，范围[100,65535] | en:Image ROI width. Range: [100,65535], default: 65535
#define KEY_BCR_ROI_HEIGHT              "BCR_HeightROI"             // ch:图像ROI高度，默认值65535，范围[40,65535] | en:Image ROI height. Range: [40,65535], default: 65535
#define KEY_BCR_MAX_WIDTH               "BCR_MaxWidth"              // ch:算法最大宽度，默认3840，范围[0,65535] | en:Maximum width of the algorithm. Range: [0,65535], default: 3840
#define KEY_BCR_MAX_HEIGHT              "BCR_MaxHeight"             // ch:算法最大高度，默认2748，范围[0,65535] | en:Maximum height of the algorithm. Range: [0,65535], default: 2748 

#define KEY_BCR_LOCBARNUM               "BCR_LocBarNum"             // ch:条形码区域定位模块条码区域个数，默认值4，范围[1,200] | en:The number of barcodes to read, Range: [1, 200], default: 4
#define KEY_BCR_LOCWINSIZE              "BCR_LocWinSize"            // ch:条形码区域定位模块窗口大小，默认值4，范围[4,65] | en:Barcode height, Range: [4, 65], default: 4
#define KEY_BCR_WAITINGTIME             "BCR_WaitingTime"           // ch:算法库Process最大运行时间，超过限定时间强行return，默认值500，范围[0,5000] | en:Algorithm library's maximum running time. The current image processing will end when exceeding the specified running time., Range: [0, 5000], default: 500
#define KEY_BCR_SEGQUIETW               "BCR_SegQuietW"             // ch:条码静区宽度，默认值30，范围[0,200] | en:Width of the barcode quiet zone Range: [0, 200], default: 30
#define KEY_BCR_DFKSIZELOWERLIMIT       "BCR_DfkSizeLowerLimit"     // ch:去伪过滤尺寸下限（宽不足此数的条码删掉），默认值30，范围[0,4000] | en:Lower limit of barcode width, below which the bar code will be filtered out.Range: [0, 4000], default: 30
#define KEY_BCR_DFKSIZEUPPERLIMIT       "BCR_DfkSizeUpperLimit"     // ch:去伪过滤尺寸上限（宽超过此数的条码删掉），默认值2400，范围[0,4000] | en:Upper limit of barcode width, above which the barcode will be filtered out.Range: [0, 4000], default: 2400
#define KEY_BCR_SAVEIMAGELEVEL          "BCR_SaveImageLevel"        // ch:保存未译出图片的灵敏度，默认值1，范围[1,3] | en:Sensitivity of saving untranslated images, Range: [1, 3], default: 1
#define KEY_BCR_APPMODE                 "BCR_AppMode"               // ch:算法库运行模式（动态模式/预留模式），默认值1，范围[0,2147483646] | en:Algorithm library operating mode in dynamic mode or reservation mode. Range: [0, 2147483646], default: 1
#define KEY_BCR_DISTORTION              "BCR_Distortion"            // ch:动态模式下 透视畸变开关，默认值0，范围[0,2147483646] | en:Perspective distortion switch in expert mode. Range: [0, 2147483646], default: 0
#define KEY_BCR_WHITEGAP                "BCR_WhiteGap"              // ch:动态模式下 印刷质量开关，默认值0，范围[0,2147483646] | en:Printing quality switch in dynamic mode, Range: [0, 2147483646], default: 0
#define KEY_BCR_SPOT                    "BCR_Spot"                  // ch:动态模式下 镜面反光开关，默认值0，范围[0,2147483646] | en:Specular reflective switch in dynamic mode. Range: [0, 2147483646], default: 0
#define KEY_BCR_SAMPLELEVEL             "BCR_SampleLevel"           // ch:图像采样尺度，默认值1，范围[1,8] | en:Image sampling scale. Range: [1, 8], default: 1
#define KEY_BCR_IAMGEMORPH              "BCR_ImageMorph"            // ch:图像形态学预处理，默认值0，范围[0，2] | en:Image morphology preprocessing. Range: [0, 2], default: 0
#define KEY_BCR_DELERRFLAG              "BCR_DelErrFlag"            // ch:降错识开关，默认值1，范围[0,1] | en:Lower error identification switch. Range: [0, 1], default: 1



/************************************************************************/
/* 二维码参数，内部有默认值，可以不设置                                 */
/************************************************************************/
#define KEY_TDCR_ABILITY                 "TDCR_Ability"             // ch:算法能力集，含QR[1]，DM[2]，默认值3，范围[0,3] | en:Algorithm capability set.contain:QR[1]，DM[2], Range: [0, 3], default: 3
#define KEY_TDCR_ROI_X                   "TDCR_PositionXROI"        // ch:图像ROI X方向偏移，默认值0，范围[0,65535] | en:Image ROI X direction offset,Range: [0,65535], default: 0
#define KEY_TDCR_ROI_Y                   "TDCR_PositionYROI"        // ch:图像ROI Y方向偏移，默认值0，范围[0,65535] | en:Image ROI Y direction offset,Range: [0,65535], default: 0
#define KEY_TDCR_ROI_WIDTH               "TDCR_WidthROI"            // ch:图像ROI宽度，默认值65535，范围[128,65535] | en:Image ROI width. Range: [128,65535], default: 65535
#define KEY_TDCR_ROI_HEIGHT              "TDCR_HeightROI"           // ch:图像ROI高度，默认值65535，范围[128,65535] | en:Image ROI height. Range: [128,65535], default: 65535
#define KEY_TDCR_MAX_WIDTH               "TDCR_MaxWidth"            // ch:算法最大宽度，默认3840，范围[0,65535] | en:Maximum width of the algorithm. Range: [0,65535], default: 3840
#define KEY_TDCR_MAX_HEIGHT              "TDCR_MaxHeight"           // ch:算法最大高度，默认2748，范围[0,65535] | en:Maximum height of the algorithm. Range: [0,65535], default: 2748 

#define KEY_TDCR_LOCCODENUM              "TDCR_LocCodeNum"          // ch:检测模块输出ROI个数，默认值5，范围[1,1000] | en:The number of ROIs outputted by detection module. Range: [1, 1000], default: 5
#define KEY_TDCR_MINBARSIZE              "TDCR_MinBarSize"          // ch:blob筛选时，最小宽高，默认值40，范围[20,1000] | en:The minimum width and height when filtering blobs. Range: [20, 1000], default: 40
#define KEY_TDCR_MAXBARSIZE              "TDCR_MaxBarSize"          // ch:blob筛选时，最大宽高，默认值300，范围[20,1000] | en:The maximum width and height when filtering blobs. Range: [20, 1000], default: 300
#define KEY_TDCR_MIRRORMODE              "TDCR_MirrorMode"          // ch:镜像模式是否打开，默认值0，范围[0,2] | en:Whether to enable mirror mode. Range: [0, 2], default: 0
#define KEY_TDCR_SAMPLELEVEL             "TDCR_SampleLevel"         // ch:图像降采样倍数，默认值1，范围[1,8] | en:Image downsampling ratio. Range: [1, 8], default: 1
#define KEY_TDCR_CODECOLOR               "TDCR_CodeColor"           // ch:白底黒码标识，默认值0，范围[0,2] | en:Identifier of the black bar code on white background. Range: [0, 2], default: 0
#define KEY_TDCR_DISCRETEFLAG            "TDCR_DiscreteFlag"        // ch:连续与离散码标志，0-连续码 1-离散码，默认值0，范围[0,2] | en:Code flag: "0"-continuous code, "1"-discrete code, "2"-self-adaptive Range: [0, 2], default: 0
#define KEY_TDCR_DISTORTIONFLAG          "TDCR_DistortionFlag"      // ch:QR畸变配置参数，默认值0，范围[0,1] | en:QR distortion configuration parameter. Range: [0, 1], default: 0
#define KEY_TDCR_ADVANCEPARAM            "TDCR_AdvanceParam"        // ch:高级参数，默认值0，范围[0,2147483640] | en:Advanced parameters. Range: [0, 2147483640], default: 0
#define KEY_TDCR_ADVANCEPARAM2           "TDCR_AdvanceParam2"       // ch:高级参数2，默认值0，范围[0,2147483640] | en:Advanced parameters 2. Range: [0, 2147483640], default: 0
#define KEY_TDCR_WAITINGTIME             "TDCR_WaitingTime"         // ch:超时退出时间，默认值1000，范围[0,5000] | en:Timeout exit time. Range: [0, 5000], default: 1000
#define KEY_TDCR_DEBUGFLAG               "TDCR_DebugFlag"           // ch:debug信息是否打开，默认值0，范围[0,1] | en:Whether to enable debug information. Range: [0, 1], default: 0
#define KEY_TDCR_RECTANGLE               "TDCR_Rectangle"           // ch:dm正方形长方形码类型，0 正方形 1 长方形 2 兼容模式，默认值0，范围[0,2] | en:Code types: 0-sqaure, 1-rectangle, 2-compatible mode. Range: [0, 2], default: 0
#define KEY_TDCR_APPMODE                 "TDCR_AppMode"             // ch:算法库运行模式（普通模式/专业模式/极速模式），默认值0，范围[0,2] | en:Algorithm library operation mode



/************************************************************************/
/* 抠图参数，内部有默认值，可以不设置                                   */
/************************************************************************/
#define KEY_WAYBILL_ABILITY                     "WAYBILL_Ability"                   // ch:算法能力集，含面单提取[1]，图像增强[2]，码提取[4]，默认7，范围[1,7] | en:Algorithm capability set. contain:Waybill [1], image enhancement [2], code extraction [4]. Range: [1, 7], default: 7
#define KEY_WAYBILL_MAX_WIDTH                   "WAYBILL_Max_Width"                 // ch:算法最大宽度，默认3840，范围[0,65535] | en:Maximum width of the algorithm. Range: [0,65535], default: 3840
#define KEY_WAYBILL_MAX_HEIGHT                  "WAYBILL_Max_Height"                // ch:算法最大高度，默认2748，范围[0,65535] | en:Maximum height of the algorithm. Range: [0,65535], default: 2748 
#define KEY_WAYBILL_OUTPUTIMAGETYPE             "WAYBILL_OutputImageType"           // ch:面单抠图输出的图片格式，默认Jpg，范围[1,3],1为Mono8，2为Jpg，3为BMP | en:Waybill Image format of the image output，1-Mono8,2-Jpg,3-BMP,Range: [1,3], default: jpg
#define KEY_WAYBILL_JPGQUALITY                  "WAYBILL_JpgQuality"                // ch:jpg编码质量，默认80，范围[1,100] | en:Jpp encoding quality. Range: [1,100], default: 80

#define KEY_WAYBILL_MINWIDTH                    "WAYBILL_MinWidth"                  // ch:waybill最小宽, 宽是长边, 高是短边，默认100，范围[15,2592] | en:Minimum width of waybill. Range: [15, 2592], default: 100
#define KEY_WAYBILL_MINHEIGHT                   "WAYBILL_MinHeight"                 // ch:waybill最小高，默认100，范围[10,2048] | en:Minimum height of waybill. Range: [10, 2048], default: 100
#define KEY_WAYBILL_MAXWIDTH                    "WAYBILL_MaxWidth"                  // ch:waybill最大宽, 宽是长边, 高是短边，默认3072，范围[15,3072] | en:Maximum width of waybill. Range: [15, 3072], default: 3072
#define KEY_WAYBILL_MAXHEIGHT                   "WAYBILL_MaxHeight"                 // ch:waybill最大高，默认2048，范围[10,2048] | en:Maximum height of waybill. Range: [10, 2048], default: 2048
#define KEY_WAYBILL_MORPHTIMES                  "WAYBILL_MorphTimes"                // ch:膨胀次数，默认0，范围[0,10] | en:Expansion times. Range: [0, 10], default: 0
#define KEY_WAYBILL_GRAYLOW                     "WAYBILL_GrayLow"                   // ch:面单上条码和字符灰度最小值，默认0，范围[0,255] | en:Minimum gray value of the bar code and character gray on the waybill. Range: [0, 255], default: 0
#define KEY_WAYBILL_GRAYMID                     "WAYBILL_GrayMid"                   // ch:面单上灰度中间值，用于区分条码和背景，默认70，范围[0,255] | en:Median gray value of waybill which is used to distinguish barcode from background. Range: [0, 255], default: 70
#define KEY_WAYBILL_GRAYHIGH                    "WAYBILL_GrayHigh"                  // ch:面单上背景灰度最大值，默认130，范围[0,255] | en:Maximum gray value of waybill background. Range: [0, 255], default: 130
#define KEY_WAYBILL_BINARYADAPTIVE              "WAYBILL_BinaryAdaptive"            // ch:自适应二值化，默认1，范围[0,1] | en:Adaptive binarization. Range: [0, 1], default: 1
#define KEY_WAYBILL_BOUNDARYROW                 "WAYBILL_BoundaryRow"               // ch:面单抠图行方向扩边，默认0，范围[0,2000] | en:Expand the edge in row direction when matting waybill. Range: [0, 2000], default: 0
#define KEY_WAYBILL_BOUNDARYCOL                 "WAYBILL_BoundaryCol"               // ch:面单抠图列方向扩边，默认0，范围[0,2000] | en:Expand the edge in column direction when matting waybill. Range: [0, 2000], default: 0
#define KEY_WAYBILL_MAXBILLBARHEIGTHRATIO       "WAYBILL_MaxBillBarHightRatio"      // ch:最大面单和条码高度比例，默认20，范围[1,100] | en:Maximum height ratio of waybill to barcode. Range: [1, 100], default: 20
#define KEY_WAYBILL_MAXBILLBARWIDTHRATIO        "WAYBILL_MaxBillBarWidthRatio"      // ch:最大面单和条码宽度比例，默认5，范围[1,100] | en:Maximum width ratio of waybill to barcode. Range: [1, 100], default: 5
#define KEY_WAYBILL_MINBILLBARHEIGTHRATIO       "WAYBILL_MinBillBarHightRatio"      // ch:最小面单和条码高度比例，默认5，范围[1,100] | en:Minimum height ratio of waybill to barcode. Range: [1, 100], default: 5
#define KEY_WAYBILL_MINBILLBARWIDTHRATIO        "WAYBILL_MinBillBarWidthRatio"      // ch:最小面单和条码宽度比例，默认2，范围[1,100] | en:Minimum width ratio of waybill to barcode. Range: [1, 100], default: 2
#define KEY_WAYBILL_ENHANCEMETHOD               "WAYBILL_EnhanceMethod"             // ch:增强方法，默认2，范围[1,4] | en:Enhancement method. Range: [1, 4], default: 2
#define KEY_WAYBILL_ENHANCECLIPRATIOLOW         "WAYBILL_ClipRatioLow"              // ch:增强拉伸低阈值比例，默认1，范围[0,100] | en:Enhance the low threshold ratio of stretching. Range: [0, 100], default: 1
#define KEY_WAYBILL_ENHANCECLIPRATIOHIGH        "WAYBILL_ClipRatioHigh"             // ch:增强拉伸高阈值比例，默认99，范围[0,100] | en:Enhance the high threshold ratio of stretching. Range: [0, 100], default: 99
#define KEY_WAYBILL_ENHANCECONTRASTFACTOR       "WAYBILL_ContrastFactor"            // ch:对比度系数，默认100，范围[1,10000] | en:Contrast ratio. Range: [1, 10000], default: 100
#define KEY_WAYBILL_ENHANCESHARPENFACTOR        "WAYBILL_SharpenFactor"             // ch:锐化系数，默认0，范围[0,10000] | en:Sharpness. Range: [0,10000], default: 0
#define KEY_WAYBILL_SHARPENKERNELSIZE           "WAYBILL_KernelSize"                // ch:锐化滤波核大小，默认3，范围[3,15] | en:Size of sharpening filter core. Range: [3, 15], default: 3
#define KEY_WAYBILL_CODEBOUNDARYROW             "WAYBILL_CodeBoundaryRow"           // ch:码单抠图行方向扩边，默认0，范围[0,2000] | en:Expand the edge in row direction when matting weight memo. Range: [0, 2000], default: 0
#define KEY_WAYBILL_CODEBOUNDARYCOL             "WAYBILL_CodeBoundaryCol"           // ch:码单抠图列方向扩边，默认0，范围[0,2000] | en:Expand the edge in column direction when matting weight memo. Range: [0, 2000], default: 0


#endif //_MVID_CODEREADER_DEFINE_H_
