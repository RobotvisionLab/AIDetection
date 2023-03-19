
#ifndef _MVID_CODEREADER_DEFINE_H_
#define _MVID_CODEREADER_DEFINE_H_

// ch:��ȷ�붨�� | en://Definition of correct code
#define MVID_CR_OK                  0x00000000  ///< ch:�ɹ����޴��� | en:Successed, no error

//ch:ͨ�ô����붨��:��Χ0x80000000-0x800000FF | en:
#define MVID_CR_E_HANDLE            0x80000000  ///< ch:�������Ч�ľ�� | en:Error or invalid handle
#define MVID_CR_E_SUPPORT           0x80000001  ///< ch:��֧�ֵĹ��� | en:The function is not supported
#define MVID_CR_E_BUFOVER           0x80000002  ///< ch:�������� | en:Buffer is full
#define MVID_CR_E_CALLORDER         0x80000003  ///< ch:��������˳����� | en:Incorrect calling sequence
#define MVID_CR_E_PARAMETER         0x80000004  ///< ch:����Ĳ��� | en:Incorrect parameter
#define MVID_CR_E_RESOURCE          0x80000005  ///< ch:��Դ����ʧ�� | en:Applying resource failed
#define MVID_CR_E_NODATA            0x80000006  ///< ch:������ | en:No data
#define MVID_CR_E_PRECONDITION      0x80000007  ///< ch:ǰ���������󣬻����л����ѷ����仯 | en:Precondition error, or running environment changed
#define MVID_CR_E_ENCRYPT           0x80000008  ///< ch:ƾ֤���󣬿�����δ����ܹ�������ܹ����� | en:Credential error, possibly because the dongle was not installed or expired.
#define MVID_CR_E_RULE              0x8000000A  ///< ch:���˹�����صĴ��� | en:Filter rule error.
#define MVID_CR_E_LOAD_LIBRARY      0x8000000B  ///< ch:��̬����DLLʧ�� | en:Dynamically importing the DLL file failed.
#define MVID_CR_E_JPGENC            0x80000012  ///< ch:jpg������ش��� | en:Jpg encoding error.
#define MVID_CR_E_IMAGE             0x80000013  ///< ch:�����ͼ�����������ͼ���ʽ,��ߴ��� | en:Abnormal image. Incomplete image caused by packet loss or incorrect image format, width, or height.
#define MVID_CR_E_CONVERT           0x80000014  ///< ch:��ʽת������ | en:Format conversion error
#define MVID_CR_E_UNKNOW            0x800000FF  ///< ch:δ֪�Ĵ��� | en:Unknown error

// ch:GenICamϵ�д���:��Χ0x80000100-0x800001FF | en:GenICam Series Error Codes: Range from 0x80000100 to 0x800001FF
#define MVID_CR_E_GC_GENERIC        0x80000100  ///< ch:ͨ�ô��� | en:General error
#define MVID_CR_E_GC_ARGUMENT       0x80000101  ///< ch:�����Ƿ� | en:Invalid parameter
#define MVID_CR_E_GC_RANGE          0x80000102  ///< ch:ֵ������Χ | en:The value is out of range
#define MVID_CR_E_GC_PROPERTY       0x80000103  ///< ch:���Դ��� | en:Attribute error
#define MVID_CR_E_GC_RUNTIME        0x80000104  ///< ch:���л��������� | en:Running environment error
#define MVID_CR_E_GC_LOGICAL        0x80000105  ///< ch:�߼����� | en:Incorrect logic
#define MVID_CR_E_GC_ACCESS         0x80000106  ///< ch:�ڵ������������ | en:Node accessing condition error
#define MVID_CR_E_GC_TIMEOUT        0x80000107  ///< ch:��ʱ | en:Timeout
#define MVID_CR_E_GC_DYNAMICCAST    0x80000108  ///< ch:ת���쳣 | en:Transformation exception
#define MVID_CR_E_GC_UNKNOW         0x800001FF  ///< ch:GenICamδ֪���� | en:GenICam unknown error

// ch:GigE_STATUS��Ӧ�Ĵ�����:��Χ0x80000200-0x800002FF | en:GigE_STATUS Error Codes: Range from 0x80000200 to 0x800002FF
#define MVID_CR_E_NOT_IMPLEMENTED   0x80000200  ///< ch:������豸֧�� | en:The command is not supported by device
#define MVID_CR_E_INVALID_ADDRESS   0x80000201  ///< ch:���ʵ�Ŀ���ַ������ | en:Target address does not exist
#define MVID_CR_E_WRITE_PROTECT     0x80000202  ///< ch:Ŀ���ַ����д | en:The target address is not writable
#define MVID_CR_E_ACCESS_DENIED     0x80000203  ///< ch:�豸�޷���Ȩ�� | en:No access permission
#define MVID_CR_E_BUSY              0x80000204  ///< ch:�豸æ��������Ͽ� | en:Device is busy, or network is disconnected
#define MVID_CR_E_PACKET            0x80000205  ///< ch:��������ݴ��� | en:Network packet error
#define MVID_CR_E_NETER             0x80000206  ///< ch:������ش��� | en:Network error

// ch:GigE������еĴ�����
#define MVID_CR_E_IP_CONFLICT       0x80000221  ///< ch:�豸IP��ͻ | en:IP address conflicted

// ch:USB_STATUS��Ӧ�Ĵ�����:��Χ0x80000300-0x800003FF | en:USB_STATUS Error Codes: Range from 0x80000300 to 0x800003FF
#define MVID_CR_E_USB_READ          0x80000300      ///< ch:��usb���� | en:USB read error
#define MVID_CR_E_USB_WRITE         0x80000301      ///< ch:дusb���� | en:USB write error
#define MVID_CR_E_USB_DEVICE        0x80000302      ///< ch:�豸�쳣 | en:Device exception
#define MVID_CR_E_USB_GENICAM       0x80000303      ///< ch:GenICam��ش��� | en:GenICam error
#define MVID_CR_E_USB_BANDWIDTH     0x80000304      ///< ch:������  �ô��������� | en:Insufficient bandwidth, this error code is newly added
#define MVID_CR_E_USB_DRIVER        0x80000305      ///< ch:������ƥ�����δװ���� | en:Driver is mismatched, or is not installed.
#define MVID_CR_E_USB_UNKNOW        0x800003FF      ///< ch:USBδ֪�Ĵ��� | en:USB unknown error

#define MVID_CR_E_CAMERA            0x80002100      ///< ch:�����صĴ��� | en:Camera error
#define MVID_CR_E_BCR               0x80002200      ///< ch:һά����ش��� | en:1D barcode error
#define MVID_CR_E_TDCR              0x80002300      ///< ch:��ά����ش��� | en:2D barcode error
#define MVID_CR_E_WAYBILL           0x80002400      ///< ch:��ͼ��ش��� | en:Matting error
#define MVID_CR_E_SCRIPT            0x80002500      ///< ch:�ű�������ش��� | en:Script rule error


#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif

// ch:��ƽ̨���� | en:Cross Platform Definition
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


// ������Ͷ���
#define MVID_GIGE_CAM          0x00000001          // ch:GigE�豸 | en:GigE Device
#define MVID_USB_CAM           0x00000004          // ch:USB3.0 �豸 | en:USB3.0 Device

// ch: �쳣��Ϣ���� | en:Exception message type
#define MVID_EXCEPTION_DEV_DISCONNECT          0x00008001      // ch:�豸�Ͽ����� | en:The device is disconnected
#define MVID_EXCEPTION_SOFTDOG_DISCONNECT      0x00008002      // ch:���ܹ����� | en:The softdog is disconnected

typedef struct _MVID_CAMERA_INFO_
{
    //���ͨ������
    unsigned int        nCamType;                       // ch:������ͣ�G�ڻ�U�� | en:Camera type: USB, GigE
    unsigned char       chManufacturerName[32];         // ch:���������� | en:Manufacturer Name
    unsigned char       chModelName[32];                // ch:�ͺ����� | en:Model Name
    unsigned char       chDeviceVersion[32];            // ch:�豸�汾�� | en:Device version No.
    unsigned char       chManufacturerSpecificInfo[48]; // ch:�������ض�����Ϣ | en:Manufacturer specific information
    unsigned char       chSerialNumber[16];             // ch:���к� | en:Device serial No.
    unsigned char       chUserDefinedName[16];          // ch:�û��Զ������� | en:Custom name 
    unsigned int        nMacAddrHigh;                   // ch:MAC ��ַ ��λ| en:High MAC address
    unsigned int        nMacAddrLow;                    // ch:MAC ��ַ ��λ| en:Low MAC address
    unsigned int        nCommomReaserved[8];            // ch:����| en:Reserved 


    // �����������
    unsigned int        nCurrentIp;                 // ch:��ǰIP | en:Current IP address 
    unsigned int        nNetExport;                 // ch:����IP��ַ | en:GIGE IP Address
    unsigned int        nGigEReserved[32];          // ch:gige���� | en:GigE Reserved


    // U���������
    unsigned char       CrtlInEndPoint;             // ch:��������˵� | en:Control input endpoint
    unsigned char       CrtlOutEndPoint;            // ch:��������˵� | en:Control output endpoint
    unsigned char       StreamEndPoint;             // ch:���˵� | en:Stream endpoint
    unsigned char       EventEndPoint;              // ch:�¼��˵� | en:Event endpoint
    unsigned short      idVendor;                   // ch:��Ӧ��ID�� | en:Vendor ID 
    unsigned short      idProduct;                  // ch:��ƷID�� | en:Product ID 
    unsigned int        nDeviceNumber;              // ch:�豸���к� | en:Device ID 
    unsigned int        nUsbReserved[31];           // ch:USB���� | en:Usb Reserved

    // �Ƿ�Ϊָ��ϵ���ͺ����
    // true -ָ��ϵ���ͺ���� false- ��ָ��ϵ���ͺ����
    bool                bSelectDevice;              // ch:ѡ���豸 |en:Choose device

    // �����ֽ�
    unsigned int        nReserved[63];              // ch:����| en:Reserved 

}MVID_CAMERA_INFO;

#define MVID_MAX_CAM_NUM      256                   // ch:���֧�ֵ��豸���� | en:The maximum number of supported devices

// ch:�豸��Ϣ�б� | en:Device Information List
typedef struct _MVID_CAMERA_INFO_LIST_
{
    OUT unsigned int            nCamNum;                            // ch:�����豸���� | en:The number of online devices
    OUT MVID_CAMERA_INFO*       pstCamInfo[MVID_MAX_CAM_NUM];       // ch:֧�����256���豸 | en:Device information, up to 256 devices can be supported

}MVID_CAMERA_INFO_LIST;


// ����������
#define MVID_BCR                0x00000001          // ch:һά�� | en:One-dimensional code
#define MVID_TDCR               0x00000002          // ch:��ά�� | en:Two-dimensional code
#define MVID_WAYBILL            0x00000004          // ch:�浥��ͼ | en:Image Matting

typedef enum _MVID_CODE_TYPE_
{
    MVID_CODE_NONE        = 0,                  // ch:�޿�ʶ������ | en:No recognizable bar code

    // ��ά��
    MVID_CODE_TDCR_DM          = 1,             // ch:DM�� | en:DM code
    MVID_CODE_TDCR_QR          = 2,             // ch:QR�� | en:QR code

    // һά��
    MVID_CODE_BCR_EAN8    = 8,                  // ch:EAN8�� | en:EAN8 code
    MVID_CODE_BCR_UPCE    = 9,                  // ch:UPCE�� | en:UPCE code
    MVID_CODE_BCR_UPCA    = 12,                 // ch:UPCA�� | en:UPCA code
    MVID_CODE_BCR_EAN13   = 13,                 // ch:EAN13�� | en:EAN13 code
    MVID_CODE_BCR_ISBN13  = 14,                 // ch:ISBN13�� | en:ISBN13 code
    MVID_CODE_BCR_CODABAR = 20,                 // ch:��°��� | en:Codabar code
    MVID_CODE_BCR_ITF25   = 25,                 // ch:����25�� | en:ITF25 code
    MVID_CODE_BCR_CODE39  = 39,                 // ch:Code 39 | en:Code 39
    MVID_CODE_BCR_CODE93  = 93,                 // ch:Code 93 | en:Code 93
    MVID_CODE_BCR_CODE128 = 128,                // ch:Code 128 | en:Code 128
} MVID_CODE_TYPE;

// ͼ���ʽ
typedef enum _MVID_IMAGE_TYPE_
{
    MVID_IMAGE_Undefined            = 0,    // ch:δ���� | en:Undefined format
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

// �����ʶ
typedef enum _MVID_CODE_FLAG_
{
    MVID_CODE_CORRECT           = 0,    // ch:�������� | en:Normal bar code
    MVID_CODE_FILTERED          = 1,    // ch:�������� | en:Filter bar code
}MVID_CODE_FLAG;

typedef enum _MVID_IMAGE_OUTPUT_MODE_
{
    MVID_OUTPUT_NORMAL          = 0,      // ch:������� | en:normal output
    MVID_OUTPUT_RAW             = 1,      // ch:ԭͼ��� | en:raw output
}MVID_IMAGE_OUTPUT_MODE;

// ch:���ͼ�����Ϣ | en:Output Frame Information
typedef struct _MVID_IMAGE_INFO_
{
    OUT unsigned char*      pImageBuf;          // ch:ԭʼͼ�񻺴棬��SDK�ڲ����� | en:Original image buffer
    OUT unsigned int        nImageLen;          // ch:ԭʼͼ�񳤶� | en:Original image size
    OUT MVID_IMAGE_TYPE     enImageType;        // ch:ͼ���ʽ | en:Image Type
    OUT unsigned short      nWidth;             // ch:ͼ��� | en:Image Width
    OUT unsigned short      nHeight;            // ch:ͼ��� | en:Image Height

    OUT unsigned int        nFrameNum;          // ch:֡�� | en:Frame No.
    OUT unsigned int        nDevTimeStampHigh;  // ch:ʱ�����32λ | en:Timestamp high 32 bits
    OUT unsigned int        nDevTimeStampLow;   // ch:ʱ�����32λ | en:Timestamp low 32 bits

    unsigned int            nReserved[32];      // ch:���� | en:Reserved
}MVID_IMAGE_INFO;

typedef struct _MVID_POINT_I_
{
    int             nX;                         // ch:X���� | en:X-coordinate
    int             nY;                         // ch:Y���� | en:Y-coordinate
} MVID_POINT_I;

#define     MVID_MAX_CODECHARATERLEN        4096    // ch:������볤�� | en:Maximum barcode length
#define     MVID_MAX_CODENUM                256     // ch:����������� | en:Maximum number of barcodes

typedef struct _MVID_CODE_INFO_
{
    unsigned char           strCode[MVID_MAX_CODECHARATERLEN];      // ch:�ַ� | en:Character, maximum size: 4096
    int                     nLen;                                   // ch:�ַ����� | en:Character size
    MVID_CODE_TYPE          enBarType;                              // ch:�������� | en:Bar code type
    MVID_POINT_I            stCornerPt[4];                          // ch:����λ�� | en:Bar code location
    int                     nAngle;                                 // ch:����Ƕȣ�0~3600�� | en:Bar code angle, range: [0, 3600��]
    int                     nFilterFlag;                            // ch:�������ʶ(0Ϊ�����룬1Ϊ������) | en:Filter identifier: 0- normal code, 1-filter code
    unsigned int            nReserved[31];                          // ch:���� | en:Reserved
}MVID_CODE_INFO;

typedef struct _MVID_CODE_INFO_LIST_
{
    int                     nCodeNum;                       // ch:�������� | en:The number of bar codes
    MVID_CODE_INFO          stCodeInfo[MVID_MAX_CODENUM];   // ch:������Ϣ | en:Bar code information, maximum size: 256

    unsigned int            nReserved[32];                  // ch:���� | en:Reserved
}MVID_CODE_INFO_LIST;

typedef struct _MVID_CAM_OUTPUT_INFO_
{
    OUT MVID_IMAGE_INFO         stImage;            // ch:���ͼ�����Ϣ | en:Image information
    OUT MVID_CODE_INFO_LIST     stCodeList;         // ch:������Ϣ�б� | en:Bar code information

    OUT unsigned char*          pImageWaybill;      // ch:��ͼ���棬��SDK�ڲ����� | en:Image matting buffer
    OUT unsigned int            nImageWaybillLen;   // ch:ͼ���С | en:Image size
    OUT MVID_IMAGE_TYPE         enWaybillImageType; // ch:��ͼͼ���ʽ | en:Image format

    unsigned int                nReserved[31];      // ch:���� | en:Reserved
}MVID_CAM_OUTPUT_INFO;

typedef struct _MVID_PROC_PARAM_
{
    IN unsigned char*       pImageBuf;              // ch:ԭʼͼ�񻺴棬���û����� | en:Original image buffer
    IN unsigned int         nImageLen;              // ch:ԭʼͼ�񳤶� | en:Original image size
    IN MVID_IMAGE_TYPE      enImageType;            // ch:����ͼ��ĸ�ʽ | en:Image type
    IN unsigned short       nWidth;                 // ch:ͼ��� | en:Image width
    IN unsigned short       nHeight;                // ch:ͼ��� | en:Image height

    OUT MVID_CODE_INFO_LIST stCodeList;             // ch:������Ϣ | en:Bar code information

    OUT unsigned char*      pImageWaybill;          // ch:��ͼ���棬��SDK�ڲ����� | en:Matting buffer, which is allocated by SDK
    OUT unsigned int        nImageWaybillLen;       // ch:ͼ���С | en:Image size
    OUT MVID_IMAGE_TYPE     enWaybillImageType;     // ch:��ͼͼ���ʽ | en:The format of the matted image

    unsigned int            nReserved[31];          // ch:���� | en:Reserved
}MVID_PROC_PARAM;

#define MVID_MAX_XML_SYMBOLIC_NUM      64           // ch:ÿ���Ѿ�ʵ�ֵ�Ԫ���������� | en:The number of names of each implemented unit

typedef struct _MVID_CR_CAM_INTVALUE_
{
    unsigned int    nCurValue;      // ch:��ǰֵ | en:Current Value
    unsigned int    nMax;           // ch:���ֵ | en:The maximum value
    unsigned int    nMin;           // ch:��Сֵ | en:The minimum value
    unsigned int    nInc;           // ch:����ֵ | en:Increment

    unsigned int    nReserved[4];   // ch:���� | en:Reserved
}MVID_CAM_INTVALUE;

typedef struct _MVID_CAM_INTVALUE_EX_
{
    int64_t    nCurValue;           // ch:��ǰֵ | en:Current Value
    int64_t    nMax;                // ch:���ֵ | en:The maximum value
    int64_t    nMin;                // ch:��Сֵ | en:The minimum value
    int64_t    nInc;                // ch:����ֵ | en:Increment

    unsigned int    nReserved[16];  // ch:���� | en:Reserved
}MVID_CAM_INTVALUE_EX;

typedef struct _MVID_CAM_ENUMVALUE_
{
    unsigned int    nCurValue;                                  // ch:��ǰֵ | en:Current Value
    unsigned int    nSupportedNum;                              // ch:���ݵ���Ч���ݸ��� | The number of valid data
    unsigned int    nSupportValue[MVID_MAX_XML_SYMBOLIC_NUM];   // ch:֧�ֵ�ö�����ͣ�ÿ�������ʾһ�����ͣ�����СΪ��64 | en:Supported enumeration types, each array indicates one type, , maximum size: 64

    unsigned int    nReserved[4];                               // ch:���� | en:Reserved
}MVID_CAM_ENUMVALUE;

typedef struct _MVID_CAM_FLOATVALUE_
{
    float           fCurValue;      // ch:��ǰֵ | en:Current Value
    float           fMax;           // ch:���ֵ | en:The maximum value
    float           fMin;           // ch:��Сֵ | en:The minimum value

    unsigned int    nReserved[4];   // ch:���� | en:Reserved
}MVID_CAM_FLOATVALUE;

typedef struct _MVID_CAM_STRINGVALUE_
{
    char   chCurValue[256];         // ch:��ǰֵ | en:Current Value

    int64_t nMaxLength;             // ch:��󳤶� | en:The maximum size
    unsigned int    nReserved[2];   // ch:�����ֽ� | en:Reserved
}MVID_CAM_STRINGVALUE;

//Event�¼��ص���Ϣ | en:Event callback infomation
#define MVID_MAX_EVENT_NAME_SIZE     128                    // ch:���Event�¼�������󳤶� | en:Max length of event name

typedef struct _MVID_EVENT_OUT_INFO_
{
    char            EventName[MVID_MAX_EVENT_NAME_SIZE];    // ch:Event���� | en:Event name, , maximum size: 128

    unsigned short  nEventID;                               // ch:Event�� | en:Event ID
    unsigned short  nStreamChannel;                         // ch:��ͨ����� | en:Stream channel ID

    unsigned int    nBlockIdHigh;                           // ch:֡�Ÿ�λ | en:High frame ID
    unsigned int    nBlockIdLow;                            // ch:֡�ŵ�λ | en:Low frame ID

    unsigned int    nTimestampHigh;                         // ch:ʱ�����λ | en:High timestamp
    unsigned int    nTimestampLow;                          // ch:ʱ�����λ | en:Low timestamp

    void *          pEventData;                             // ch:Event���� | en:Event data
    unsigned int    nEventDataSize;                         // ch:Event���ݳ��� | en:Event data size

    unsigned int    nReserved[16];                          // ch:Ԥ�� | en:Reserved
}MVID_EVENT_OUT_INFO;

#define MVID_ALGORITHM_MIN_WIDTH        128                 // ch:�㷨֧����С��� | en:Algorithm supports minimum width
#define MVID_ALGORITHM_MIN_HEIGHT       128                 // ch:�㷨֧����С�߶� | en:Algorithm supports minimum height

/************************************************************************/
/* һά��������ڲ���Ĭ��ֵ�����Բ�����                                 */
/************************************************************************/
#define KEY_BCR_ABILITY                 "BCR_Ability"               // ch:�㷨����������Code39[1]��Code128[2]��CodeBar[4]��EAN[8]��ITF25[16]��CODE93[32]��Ĭ��ֵ63����Χ[0,63] | en:Algorithm capability set.contain:Code39[1]��Code128[2]��CodeBar[4]��EAN[8]��ITF25[16]��CODE93[32],Range: [0, 63], default: 63
#define KEY_BCR_ROI_X                   "BCR_PositionXROI"          // ch:ͼ��ROI X����ƫ�ƣ�Ĭ��ֵ0����Χ[0,65535] | en:Image ROI X direction offset,Range: [0,65535], default: 0
#define KEY_BCR_ROI_Y                   "BCR_PositionYROI"          // ch:ͼ��ROI Y����ƫ�ƣ�Ĭ��ֵ0����Χ[0,65535] | en:Image ROI Y direction offset,Range: [0,65535], default: 0
#define KEY_BCR_ROI_WIDTH               "BCR_WidthROI"              // ch:ͼ��ROI��ȣ�Ĭ��ֵ65535����Χ[100,65535] | en:Image ROI width. Range: [100,65535], default: 65535
#define KEY_BCR_ROI_HEIGHT              "BCR_HeightROI"             // ch:ͼ��ROI�߶ȣ�Ĭ��ֵ65535����Χ[40,65535] | en:Image ROI height. Range: [40,65535], default: 65535
#define KEY_BCR_MAX_WIDTH               "BCR_MaxWidth"              // ch:�㷨����ȣ�Ĭ��3840����Χ[0,65535] | en:Maximum width of the algorithm. Range: [0,65535], default: 3840
#define KEY_BCR_MAX_HEIGHT              "BCR_MaxHeight"             // ch:�㷨���߶ȣ�Ĭ��2748����Χ[0,65535] | en:Maximum height of the algorithm. Range: [0,65535], default: 2748 

#define KEY_BCR_LOCBARNUM               "BCR_LocBarNum"             // ch:����������λģ���������������Ĭ��ֵ4����Χ[1,200] | en:The number of barcodes to read, Range: [1, 200], default: 4
#define KEY_BCR_LOCWINSIZE              "BCR_LocWinSize"            // ch:����������λģ�鴰�ڴ�С��Ĭ��ֵ4����Χ[4,65] | en:Barcode height, Range: [4, 65], default: 4
#define KEY_BCR_WAITINGTIME             "BCR_WaitingTime"           // ch:�㷨��Process�������ʱ�䣬�����޶�ʱ��ǿ��return��Ĭ��ֵ500����Χ[0,5000] | en:Algorithm library's maximum running time. The current image processing will end when exceeding the specified running time., Range: [0, 5000], default: 500
#define KEY_BCR_SEGQUIETW               "BCR_SegQuietW"             // ch:���뾲����ȣ�Ĭ��ֵ30����Χ[0,200] | en:Width of the barcode quiet zone Range: [0, 200], default: 30
#define KEY_BCR_DFKSIZELOWERLIMIT       "BCR_DfkSizeLowerLimit"     // ch:ȥα���˳ߴ����ޣ��������������ɾ������Ĭ��ֵ30����Χ[0,4000] | en:Lower limit of barcode width, below which the bar code will be filtered out.Range: [0, 4000], default: 30
#define KEY_BCR_DFKSIZEUPPERLIMIT       "BCR_DfkSizeUpperLimit"     // ch:ȥα���˳ߴ����ޣ���������������ɾ������Ĭ��ֵ2400����Χ[0,4000] | en:Upper limit of barcode width, above which the barcode will be filtered out.Range: [0, 4000], default: 2400
#define KEY_BCR_SAVEIMAGELEVEL          "BCR_SaveImageLevel"        // ch:����δ���ͼƬ�������ȣ�Ĭ��ֵ1����Χ[1,3] | en:Sensitivity of saving untranslated images, Range: [1, 3], default: 1
#define KEY_BCR_APPMODE                 "BCR_AppMode"               // ch:�㷨������ģʽ����̬ģʽ/Ԥ��ģʽ����Ĭ��ֵ1����Χ[0,2147483646] | en:Algorithm library operating mode in dynamic mode or reservation mode. Range: [0, 2147483646], default: 1
#define KEY_BCR_DISTORTION              "BCR_Distortion"            // ch:��̬ģʽ�� ͸�ӻ��俪�أ�Ĭ��ֵ0����Χ[0,2147483646] | en:Perspective distortion switch in expert mode. Range: [0, 2147483646], default: 0
#define KEY_BCR_WHITEGAP                "BCR_WhiteGap"              // ch:��̬ģʽ�� ӡˢ�������أ�Ĭ��ֵ0����Χ[0,2147483646] | en:Printing quality switch in dynamic mode, Range: [0, 2147483646], default: 0
#define KEY_BCR_SPOT                    "BCR_Spot"                  // ch:��̬ģʽ�� ���淴�⿪�أ�Ĭ��ֵ0����Χ[0,2147483646] | en:Specular reflective switch in dynamic mode. Range: [0, 2147483646], default: 0
#define KEY_BCR_SAMPLELEVEL             "BCR_SampleLevel"           // ch:ͼ������߶ȣ�Ĭ��ֵ1����Χ[1,8] | en:Image sampling scale. Range: [1, 8], default: 1
#define KEY_BCR_IAMGEMORPH              "BCR_ImageMorph"            // ch:ͼ����̬ѧԤ����Ĭ��ֵ0����Χ[0��2] | en:Image morphology preprocessing. Range: [0, 2], default: 0
#define KEY_BCR_DELERRFLAG              "BCR_DelErrFlag"            // ch:����ʶ���أ�Ĭ��ֵ1����Χ[0,1] | en:Lower error identification switch. Range: [0, 1], default: 1



/************************************************************************/
/* ��ά��������ڲ���Ĭ��ֵ�����Բ�����                                 */
/************************************************************************/
#define KEY_TDCR_ABILITY                 "TDCR_Ability"             // ch:�㷨����������QR[1]��DM[2]��Ĭ��ֵ3����Χ[0,3] | en:Algorithm capability set.contain:QR[1]��DM[2], Range: [0, 3], default: 3
#define KEY_TDCR_ROI_X                   "TDCR_PositionXROI"        // ch:ͼ��ROI X����ƫ�ƣ�Ĭ��ֵ0����Χ[0,65535] | en:Image ROI X direction offset,Range: [0,65535], default: 0
#define KEY_TDCR_ROI_Y                   "TDCR_PositionYROI"        // ch:ͼ��ROI Y����ƫ�ƣ�Ĭ��ֵ0����Χ[0,65535] | en:Image ROI Y direction offset,Range: [0,65535], default: 0
#define KEY_TDCR_ROI_WIDTH               "TDCR_WidthROI"            // ch:ͼ��ROI��ȣ�Ĭ��ֵ65535����Χ[128,65535] | en:Image ROI width. Range: [128,65535], default: 65535
#define KEY_TDCR_ROI_HEIGHT              "TDCR_HeightROI"           // ch:ͼ��ROI�߶ȣ�Ĭ��ֵ65535����Χ[128,65535] | en:Image ROI height. Range: [128,65535], default: 65535
#define KEY_TDCR_MAX_WIDTH               "TDCR_MaxWidth"            // ch:�㷨����ȣ�Ĭ��3840����Χ[0,65535] | en:Maximum width of the algorithm. Range: [0,65535], default: 3840
#define KEY_TDCR_MAX_HEIGHT              "TDCR_MaxHeight"           // ch:�㷨���߶ȣ�Ĭ��2748����Χ[0,65535] | en:Maximum height of the algorithm. Range: [0,65535], default: 2748 

#define KEY_TDCR_LOCCODENUM              "TDCR_LocCodeNum"          // ch:���ģ�����ROI������Ĭ��ֵ5����Χ[1,1000] | en:The number of ROIs outputted by detection module. Range: [1, 1000], default: 5
#define KEY_TDCR_MINBARSIZE              "TDCR_MinBarSize"          // ch:blobɸѡʱ����С��ߣ�Ĭ��ֵ40����Χ[20,1000] | en:The minimum width and height when filtering blobs. Range: [20, 1000], default: 40
#define KEY_TDCR_MAXBARSIZE              "TDCR_MaxBarSize"          // ch:blobɸѡʱ������ߣ�Ĭ��ֵ300����Χ[20,1000] | en:The maximum width and height when filtering blobs. Range: [20, 1000], default: 300
#define KEY_TDCR_MIRRORMODE              "TDCR_MirrorMode"          // ch:����ģʽ�Ƿ�򿪣�Ĭ��ֵ0����Χ[0,2] | en:Whether to enable mirror mode. Range: [0, 2], default: 0
#define KEY_TDCR_SAMPLELEVEL             "TDCR_SampleLevel"         // ch:ͼ�񽵲���������Ĭ��ֵ1����Χ[1,8] | en:Image downsampling ratio. Range: [1, 8], default: 1
#define KEY_TDCR_CODECOLOR               "TDCR_CodeColor"           // ch:�׵��\���ʶ��Ĭ��ֵ0����Χ[0,2] | en:Identifier of the black bar code on white background. Range: [0, 2], default: 0
#define KEY_TDCR_DISCRETEFLAG            "TDCR_DiscreteFlag"        // ch:��������ɢ���־��0-������ 1-��ɢ�룬Ĭ��ֵ0����Χ[0,2] | en:Code flag: "0"-continuous code, "1"-discrete code, "2"-self-adaptive Range: [0, 2], default: 0
#define KEY_TDCR_DISTORTIONFLAG          "TDCR_DistortionFlag"      // ch:QR�������ò�����Ĭ��ֵ0����Χ[0,1] | en:QR distortion configuration parameter. Range: [0, 1], default: 0
#define KEY_TDCR_ADVANCEPARAM            "TDCR_AdvanceParam"        // ch:�߼�������Ĭ��ֵ0����Χ[0,2147483640] | en:Advanced parameters. Range: [0, 2147483640], default: 0
#define KEY_TDCR_ADVANCEPARAM2           "TDCR_AdvanceParam2"       // ch:�߼�����2��Ĭ��ֵ0����Χ[0,2147483640] | en:Advanced parameters 2. Range: [0, 2147483640], default: 0
#define KEY_TDCR_WAITINGTIME             "TDCR_WaitingTime"         // ch:��ʱ�˳�ʱ�䣬Ĭ��ֵ1000����Χ[0,5000] | en:Timeout exit time. Range: [0, 5000], default: 1000
#define KEY_TDCR_DEBUGFLAG               "TDCR_DebugFlag"           // ch:debug��Ϣ�Ƿ�򿪣�Ĭ��ֵ0����Χ[0,1] | en:Whether to enable debug information. Range: [0, 1], default: 0
#define KEY_TDCR_RECTANGLE               "TDCR_Rectangle"           // ch:dm�����γ����������ͣ�0 ������ 1 ������ 2 ����ģʽ��Ĭ��ֵ0����Χ[0,2] | en:Code types: 0-sqaure, 1-rectangle, 2-compatible mode. Range: [0, 2], default: 0
#define KEY_TDCR_APPMODE                 "TDCR_AppMode"             // ch:�㷨������ģʽ����ͨģʽ/רҵģʽ/����ģʽ����Ĭ��ֵ0����Χ[0,2] | en:Algorithm library operation mode



/************************************************************************/
/* ��ͼ�������ڲ���Ĭ��ֵ�����Բ�����                                   */
/************************************************************************/
#define KEY_WAYBILL_ABILITY                     "WAYBILL_Ability"                   // ch:�㷨�����������浥��ȡ[1]��ͼ����ǿ[2]������ȡ[4]��Ĭ��7����Χ[1,7] | en:Algorithm capability set. contain:Waybill [1], image enhancement [2], code extraction [4]. Range: [1, 7], default: 7
#define KEY_WAYBILL_MAX_WIDTH                   "WAYBILL_Max_Width"                 // ch:�㷨����ȣ�Ĭ��3840����Χ[0,65535] | en:Maximum width of the algorithm. Range: [0,65535], default: 3840
#define KEY_WAYBILL_MAX_HEIGHT                  "WAYBILL_Max_Height"                // ch:�㷨���߶ȣ�Ĭ��2748����Χ[0,65535] | en:Maximum height of the algorithm. Range: [0,65535], default: 2748 
#define KEY_WAYBILL_OUTPUTIMAGETYPE             "WAYBILL_OutputImageType"           // ch:�浥��ͼ�����ͼƬ��ʽ��Ĭ��Jpg����Χ[1,3],1ΪMono8��2ΪJpg��3ΪBMP | en:Waybill Image format of the image output��1-Mono8,2-Jpg,3-BMP,Range: [1,3], default: jpg
#define KEY_WAYBILL_JPGQUALITY                  "WAYBILL_JpgQuality"                // ch:jpg����������Ĭ��80����Χ[1,100] | en:Jpp encoding quality. Range: [1,100], default: 80

#define KEY_WAYBILL_MINWIDTH                    "WAYBILL_MinWidth"                  // ch:waybill��С��, ���ǳ���, ���Ƕ̱ߣ�Ĭ��100����Χ[15,2592] | en:Minimum width of waybill. Range: [15, 2592], default: 100
#define KEY_WAYBILL_MINHEIGHT                   "WAYBILL_MinHeight"                 // ch:waybill��С�ߣ�Ĭ��100����Χ[10,2048] | en:Minimum height of waybill. Range: [10, 2048], default: 100
#define KEY_WAYBILL_MAXWIDTH                    "WAYBILL_MaxWidth"                  // ch:waybill����, ���ǳ���, ���Ƕ̱ߣ�Ĭ��3072����Χ[15,3072] | en:Maximum width of waybill. Range: [15, 3072], default: 3072
#define KEY_WAYBILL_MAXHEIGHT                   "WAYBILL_MaxHeight"                 // ch:waybill���ߣ�Ĭ��2048����Χ[10,2048] | en:Maximum height of waybill. Range: [10, 2048], default: 2048
#define KEY_WAYBILL_MORPHTIMES                  "WAYBILL_MorphTimes"                // ch:���ʹ�����Ĭ��0����Χ[0,10] | en:Expansion times. Range: [0, 10], default: 0
#define KEY_WAYBILL_GRAYLOW                     "WAYBILL_GrayLow"                   // ch:�浥��������ַ��Ҷ���Сֵ��Ĭ��0����Χ[0,255] | en:Minimum gray value of the bar code and character gray on the waybill. Range: [0, 255], default: 0
#define KEY_WAYBILL_GRAYMID                     "WAYBILL_GrayMid"                   // ch:�浥�ϻҶ��м�ֵ��������������ͱ�����Ĭ��70����Χ[0,255] | en:Median gray value of waybill which is used to distinguish barcode from background. Range: [0, 255], default: 70
#define KEY_WAYBILL_GRAYHIGH                    "WAYBILL_GrayHigh"                  // ch:�浥�ϱ����Ҷ����ֵ��Ĭ��130����Χ[0,255] | en:Maximum gray value of waybill background. Range: [0, 255], default: 130
#define KEY_WAYBILL_BINARYADAPTIVE              "WAYBILL_BinaryAdaptive"            // ch:����Ӧ��ֵ����Ĭ��1����Χ[0,1] | en:Adaptive binarization. Range: [0, 1], default: 1
#define KEY_WAYBILL_BOUNDARYROW                 "WAYBILL_BoundaryRow"               // ch:�浥��ͼ�з������ߣ�Ĭ��0����Χ[0,2000] | en:Expand the edge in row direction when matting waybill. Range: [0, 2000], default: 0
#define KEY_WAYBILL_BOUNDARYCOL                 "WAYBILL_BoundaryCol"               // ch:�浥��ͼ�з������ߣ�Ĭ��0����Χ[0,2000] | en:Expand the edge in column direction when matting waybill. Range: [0, 2000], default: 0
#define KEY_WAYBILL_MAXBILLBARHEIGTHRATIO       "WAYBILL_MaxBillBarHightRatio"      // ch:����浥������߶ȱ�����Ĭ��20����Χ[1,100] | en:Maximum height ratio of waybill to barcode. Range: [1, 100], default: 20
#define KEY_WAYBILL_MAXBILLBARWIDTHRATIO        "WAYBILL_MaxBillBarWidthRatio"      // ch:����浥�������ȱ�����Ĭ��5����Χ[1,100] | en:Maximum width ratio of waybill to barcode. Range: [1, 100], default: 5
#define KEY_WAYBILL_MINBILLBARHEIGTHRATIO       "WAYBILL_MinBillBarHightRatio"      // ch:��С�浥������߶ȱ�����Ĭ��5����Χ[1,100] | en:Minimum height ratio of waybill to barcode. Range: [1, 100], default: 5
#define KEY_WAYBILL_MINBILLBARWIDTHRATIO        "WAYBILL_MinBillBarWidthRatio"      // ch:��С�浥�������ȱ�����Ĭ��2����Χ[1,100] | en:Minimum width ratio of waybill to barcode. Range: [1, 100], default: 2
#define KEY_WAYBILL_ENHANCEMETHOD               "WAYBILL_EnhanceMethod"             // ch:��ǿ������Ĭ��2����Χ[1,4] | en:Enhancement method. Range: [1, 4], default: 2
#define KEY_WAYBILL_ENHANCECLIPRATIOLOW         "WAYBILL_ClipRatioLow"              // ch:��ǿ�������ֵ������Ĭ��1����Χ[0,100] | en:Enhance the low threshold ratio of stretching. Range: [0, 100], default: 1
#define KEY_WAYBILL_ENHANCECLIPRATIOHIGH        "WAYBILL_ClipRatioHigh"             // ch:��ǿ�������ֵ������Ĭ��99����Χ[0,100] | en:Enhance the high threshold ratio of stretching. Range: [0, 100], default: 99
#define KEY_WAYBILL_ENHANCECONTRASTFACTOR       "WAYBILL_ContrastFactor"            // ch:�Աȶ�ϵ����Ĭ��100����Χ[1,10000] | en:Contrast ratio. Range: [1, 10000], default: 100
#define KEY_WAYBILL_ENHANCESHARPENFACTOR        "WAYBILL_SharpenFactor"             // ch:��ϵ����Ĭ��0����Χ[0,10000] | en:Sharpness. Range: [0,10000], default: 0
#define KEY_WAYBILL_SHARPENKERNELSIZE           "WAYBILL_KernelSize"                // ch:���˲��˴�С��Ĭ��3����Χ[3,15] | en:Size of sharpening filter core. Range: [3, 15], default: 3
#define KEY_WAYBILL_CODEBOUNDARYROW             "WAYBILL_CodeBoundaryRow"           // ch:�뵥��ͼ�з������ߣ�Ĭ��0����Χ[0,2000] | en:Expand the edge in row direction when matting weight memo. Range: [0, 2000], default: 0
#define KEY_WAYBILL_CODEBOUNDARYCOL             "WAYBILL_CodeBoundaryCol"           // ch:�뵥��ͼ�з������ߣ�Ĭ��0����Χ[0,2000] | en:Expand the edge in column direction when matting weight memo. Range: [0, 2000], default: 0


#endif //_MVID_CODEREADER_DEFINE_H_
