
#ifndef _MV_CODEREADER_PARAMS_H_
#define _MV_CODEREADER_PARAMS_H_

#include "MvCodeReaderPixelType.h"

#ifndef __cplusplus
typedef char    bool;
#define true    1
#define false   0
#endif

// 设备类型定义
#define MV_CODEREADER_UNKNOW_DEVICE        0x00000000           // 未知设备类型
#define MV_CODEREADER_GIGE_DEVICE          0x00000001           // GigE设备
#define MV_CODEREADER_1394_DEVICE          0x00000002           // 1394-a/b 设备
#define MV_CODEREADER_USB_DEVICE           0x00000004           // USB3.0 设备
#define MV_CODEREADER_CAMERALINK_DEVICE    0x00000008           // CameraLink设备

// GigE设备信息
typedef struct _MV_CODEREADER_GIGE_DEVICE_INFO_
{
    unsigned int        nIpCfgOption;                           // 设备支持的IP类型
    unsigned int        nIpCfgCurrent;                          // 设备当前IP类型
    unsigned int        nCurrentIp;                             // 设备当前IP
    unsigned int        nCurrentSubNetMask;                     // 设备当前子网掩码
    unsigned int        nDefultGateWay;                         // 设备默认网关
    unsigned char       chManufacturerName[32];                 // 设备厂商
    unsigned char       chModelName[32];                        // 设备型号
    unsigned char       chDeviceVersion[32];                    // 设备版本
    unsigned char       chManufacturerSpecificInfo[48];         // 设备厂商特殊信息
    unsigned char       chSerialNumber[16];                     // 设备序列号
    unsigned char       chUserDefinedName[16];                  // 设备用户自定义名称

    unsigned int        nNetExport;                             // 主机网口IP地址
    unsigned int        nCurUserIP;                             // 当前占用设备的用户IP

    unsigned int        nReserved[3];                           // 保留字节

}MV_CODEREADER_GIGE_DEVICE_INFO;

#define INFO_MAX_BUFFER_SIZE 64                                 // 最大信息长度

// U3V设备信息
typedef struct _MV_CODEREADER_USB3_DEVICE_INFO_
{
    unsigned char           CrtlInEndPoint;                             // 控制输入端点
    unsigned char           CrtlOutEndPoint;                            // 控制输出端点
    unsigned char           StreamEndPoint;                             // 流端点
    unsigned char           EventEndPoint;                              // 事件端点
    unsigned short          idVendor;                                   // 供应商ID号
    unsigned short          idProduct;                                  // 产品ID号
    unsigned int            nDeviceNumber;                              // 设备序列号
    unsigned char           chDeviceGUID[INFO_MAX_BUFFER_SIZE];         // 设备GUID号
    unsigned char           chVendorName[INFO_MAX_BUFFER_SIZE];         // 供应商名称
    unsigned char           chModelName[INFO_MAX_BUFFER_SIZE];          // 设备型号
    unsigned char           chFamilyName[INFO_MAX_BUFFER_SIZE];         // 设备家族名称
    unsigned char           chDeviceVersion[INFO_MAX_BUFFER_SIZE];      // 设备版本
    unsigned char           chManufacturerName[INFO_MAX_BUFFER_SIZE];   // 设备厂商
    unsigned char           chSerialNumber[INFO_MAX_BUFFER_SIZE];       // 设备序列号
    unsigned char           chUserDefinedName[INFO_MAX_BUFFER_SIZE];    // 设备用户自定义名称
    unsigned int            nbcdUSB;                                    // 设备支持的USB协议
    unsigned int            nReserved[3];                               // 保留字节
}MV_CODEREADER_USB3_DEVICE_INFO;

// 设备信息
typedef struct _MV_CODEREADER_DEVICE_INFO_
{
    unsigned short      nMajorVer;                  // 设备主版本号
    unsigned short      nMinorVer;                  // 设备次版本号
    unsigned int        nMacAddrHigh;               // 设备MAC地址高位
    unsigned int        nMacAddrLow;                // 设备MAC地址低位

    unsigned int        nTLayerType;                // 设备传输层协议类型

    // 是否为指定系列型号相机
    // true -指定系列型号相机 false- 非指定系列型号相机
    bool                bSelectDevice;              // ch:选择设备 |en:Choose device

    unsigned int        nReserved[3];               // 保留字节

    union
    {
        MV_CODEREADER_GIGE_DEVICE_INFO stGigEInfo;  // GigE设备信息
        MV_CODEREADER_USB3_DEVICE_INFO stUsb3VInfo; // U3V设备信息
        // more ...
    }SpecialInfo;

}MV_CODEREADER_DEVICE_INFO;

// 最大支持的设备个数
#define MV_CODEREADER_MAX_DEVICE_NUM      256

// 设备信息列表
typedef struct _MV_CODEREADER_DEVICE_INFO_LIST_
{
    unsigned int            nDeviceNum;                                             // 在线设备数量
    MV_CODEREADER_DEVICE_INFO*      pDeviceInfo[MV_CODEREADER_MAX_DEVICE_NUM];      // 设备信息(支持最多256个设备)

}MV_CODEREADER_DEVICE_INFO_LIST;

// 输出帧信息
typedef struct _MV_CODEREADER_FRAME_OUT_INFO_
{
    unsigned short      nWidth;                             // 图像宽
    unsigned short      nHeight;                            // 图像高
    enum MvCodeReaderGvspPixelType     enPixelType;         // 像素格式

    unsigned int        nFrameNum;                          // 帧号
    unsigned int        nDevTimeStampHigh;                  // 时间戳高32位
    unsigned int        nDevTimeStampLow;                   // 时间戳低32位
    unsigned int        nReserved0;                         // 保留，8字节对齐
    int64_t             nHostTimeStamp;                     // 主机生成的时间戳

    unsigned int        nFrameLen;                          // 图像长度

    unsigned int        nLostPacket;                        // 本帧丢包数
    unsigned int        nReserved[2];                       // 保留字节
}MV_CODEREADER_FRAME_OUT_INFO;

// ch:Chunk内容 | en:The content of ChunkData
typedef struct _MV_CODEREADER_CHUNK_DATA_CONTENT_
{
    unsigned char*  pChunkData;
    unsigned int    nChunkID;
    unsigned int    nChunkLen;

    unsigned int    nReserved[8];       // 保留

}MV_CODEREADER_CHUNK_DATA_CONTENT;

// 输出帧信息
typedef struct _MV_CODEREADER_FRAME_OUT_INFO_EX_
{
    unsigned short      nWidth;                             // 图像宽
    unsigned short      nHeight;                            // 图像高
    enum MvCodeReaderGvspPixelType     enPixelType;         // 像素格式

    unsigned int        nFrameNum;                          // 帧号
    unsigned int        nDevTimeStampHigh;                  // 时间戳高32位
    unsigned int        nDevTimeStampLow;                   // 时间戳低32位
    unsigned int        nReserved0;                         // 保留，8字节对齐
    int64_t             nHostTimeStamp;                     // 主机生成的时间戳

    unsigned int        nFrameLen;                          // 图像长度

    // chunk新增水印信息
    // 设备水印时标
    unsigned int        nSecondCount;                       // 秒数
    unsigned int        nCycleCount;                        // 循环计数
    unsigned int        nCycleOffset;                       // 循环计数偏移量

    float               fGain;                              // 增益
    float               fExposureTime;                      // 曝光时间
    unsigned int        nAverageBrightness;                 // 平均亮度

    // 白平衡相关
    unsigned int        nRed;                               // 红色数据
    unsigned int        nGreen;                             // 绿色数据
    unsigned int        nBlue;                              // 蓝色数据

    unsigned int        nFrameCounter;                      // 图像数量计数
    unsigned int        nTriggerIndex;                      // 触发计数

    // Line 输入/输出
    unsigned int        nInput;                             // 输入
    unsigned int        nOutput;                            // 输出

    // ROI区域
    unsigned short      nOffsetX;                           // ROI X轴偏移
    unsigned short      nOffsetY;                           // ROI Y轴偏移
    unsigned short      nChunkWidth;                        // Chunk宽度
    unsigned short      nChunkHeight;                       // Chunk高度

    unsigned int        nLostPacket;                        // 本帧丢包数

    unsigned int        nUnparsedChunkNum;                  //未解析的Chunkdata个数
    union
    {
        MV_CODEREADER_CHUNK_DATA_CONTENT* pUnparsedChunkContent;
        int64_t nAligning;
    }UnparsedChunkList;

    unsigned int        nReserved[36];                      // 保留字节
}MV_CODEREADER_FRAME_OUT_INFO_EX;

// 图像显示信息
typedef struct _MV_CODEREADER_DISPLAY_FRAME_INFO_
{
    void*                    hWnd;                          // 显示窗口句柄
    unsigned char*           pData;                         // 源图像数据
    unsigned int             nDataLen;                      // 源图像数据长度
    unsigned short           nWidth;                        // 源图像宽
    unsigned short           nHeight;                       // 源图像高
    enum MvCodeReaderGvspPixelType     enPixelType;         // 源图像像素格式
    unsigned int             nRes[4];                       // 保留字节

}MV_CODEREADER_DISPLAY_FRAME_INFO;

// 保存图片格式
enum MV_CODEREADER_IAMGE_TYPE
{
    MV_CODEREADER_Image_Undefined       = 0,
    MV_CODEREADER_Image_Mono8           = 1,
    MV_CODEREADER_Image_Jpeg            = 2,
    MV_CODEREADER_Image_Bmp             = 3,
    MV_CODEREADER_Image_RGB24           = 4,
    MV_CODEREADER_Image_Png             = 5,      // Png图像(暂不支持)
    MV_CODEREADER_Image_Tif             = 6,      // Tif图像(暂不支持)
};

// 保存图片参数
typedef struct _MV_CODEREADER_SAVE_IMAGE_PARAM_T_
{
    unsigned char*        pData;                            // 输入数据缓存
    unsigned int          nDataLen;                         // 输入数据大小
    enum MvCodeReaderGvspPixelType       enPixelType;       // 输入数据的像素格式
    unsigned short        nWidth;                           // 图像宽
    unsigned short        nHeight;                          // 图像高

    unsigned char*        pImageBuffer;                     // 输出图片缓存
    unsigned int          nImageLen;                        // 输出图片大小
    unsigned int          nBufferSize;                      // 提供的输出缓冲区大小
    enum MV_CODEREADER_IAMGE_TYPE    enImageType;      // 输出图片格式

}MV_CODEREADER_SAVE_IMAGE_PARAM;

// 图片保存参数
typedef struct _MV_CODEREADER_SAVE_IMAGE_PARAM_T_EX_
{
    unsigned char*      pData;                              // 输入数据缓存
    unsigned int        nDataLen;                           // 输入数据大小
    enum MvCodeReaderGvspPixelType     enPixelType;         // 输入数据的像素格式
    unsigned short      nWidth;                             // 图像宽
    unsigned short      nHeight;                            // 图像高

    unsigned char*      pImageBuffer;                       // 输出图片缓存
    unsigned int        nImageLen;                          // 输出图片大小
    unsigned int        nBufferSize;                        // 提供的输出缓冲区大小
    enum MV_CODEREADER_IAMGE_TYPE  enImageType;             // 输出图片格式
    unsigned int        nJpgQuality;                        // 编码质量, (50-99]

    // 格式转为RGB24的插值方法  0-最近邻 1-双线性 2-Hamilton （如果传入其它值则默认为最近邻）
    unsigned int        iMethodValue;                       // 插值方式
    unsigned int        nReserved[3];                       // 保留字节

}MV_CODEREADER_SAVE_IMAGE_PARAM_EX;

// 触发模式
typedef enum _MV_CODEREADER_TRIGGER_MODE_
{
    MV_CODEREADER_TRIGGER_MODE_OFF         = 0,            // 触发关闭
    MV_CODEREADER_TRIGGER_MODE_ON          = 1,            // 触发打开

}MV_CODEREADER_TRIGGER_MODE;

// 触发源
typedef enum _MV_CODEREADER_TRIGGER_SOURCE_
{
    MV_CODEREADER_TRIGGER_SOURCE_LINE0             = 0,     // Line0
    MV_CODEREADER_TRIGGER_SOURCE_LINE1             = 1,     // Line1
    MV_CODEREADER_TRIGGER_SOURCE_LINE2             = 2,     // Line2
    MV_CODEREADER_TRIGGER_SOURCE_LINE3             = 3,     // Line3
    MV_CODEREADER_TRIGGER_SOURCE_COUNTER0          = 4,     // Line4

    MV_CODEREADER_TRIGGER_SOURCE_SOFTWARE          = 7,     // 软触发
    MV_CODEREADER_TRIGGER_SOURCE_FrequencyConverter= 8,     // 变频器触发

}MV_CODEREADER_TRIGGER_SOURCE;

// GigEVision IP配置方式
#define MV_CODEREADER_IP_CFG_STATIC        0x05000000       // 静态IP
#define MV_CODEREADER_IP_CFG_DHCP          0x06000000       // DHCP
#define MV_CODEREADER_IP_CFG_LLA           0x04000000       // LLA

// 条码类型
typedef enum _MV_CODEREADER_CODE_TYPE_
{
    MV_CODEREADER_CODE_NONE         = 0,                    // 无可识别条码

    // 二维码
    MV_CODEREADER_TDCR_DM           = 1,                    // DM码
    MV_CODEREADER_TDCR_QR           = 2,                    // QR码

    // 一维码
    MV_CODEREADER_BCR_EAN8          = 8,                    // EAN8码
    MV_CODEREADER_BCR_UPCE          = 9,                    // UPCE码
    MV_CODEREADER_BCR_UPCA          = 12,                   // UPCA码
    MV_CODEREADER_BCR_EAN13         = 13,                   // EAN13码
    MV_CODEREADER_BCR_ISBN13        = 14,                   // ISBN13码
    MV_CODEREADER_BCR_CODABAR       = 20,                   // 库德巴码
    MV_CODEREADER_BCR_ITF25         = 25,                   // 交叉25码
    MV_CODEREADER_BCR_CODE39        = 39,                   // Code 39
    MV_CODEREADER_BCR_CODE93        = 93,                   // Code 93
    MV_CODEREADER_BCR_CODE128       = 128,                  // Code 128

    MV_CODEREADER_TDCR_PDF417       = 131,                  // PDF417码

    MV_CODEREADER_BCR_MATRIX25      = 26,                   // MATRIX25码
    MV_CODEREADER_BCR_MSI           = 30,                   // MSI码
    MV_CODEREADER_BCR_CODE11        = 31,                   // code11
    MV_CODEREADER_BCR_INDUSTRIAL25  = 32,                   // industrial25
    MV_CODEREADER_BCR_CHINAPOST     = 33,                   // 中国邮政码
    MV_CODEREADER_BCR_ITF14         = 27,                   // 交叉14码

    MV_CODEREADER_TDCR_ECC140       = 133,                  // ECC140码制

}MV_CODEREADER_CODE_TYPE;

// 最大类型个数(适用于枚举类型)
#define MV_CODEREADER_MAX_XML_SYMBOLIC_NUM          64

// 异常消息类型
#define MV_CODEREADER_EXCEPTION_DEV_DISCONNECT      0x00008001      // 设备断开连接
#define MV_CODEREADER_EXCEPTION_VERSION_CHECK       0x00008002      // SDK与驱动版本不匹配


// 设备的访问模式
// 独占权限，其他APP只允许读CCP寄存器
#define MV_CODEREADER_ACCESS_Exclusive                                         1
// 可以从5模式下抢占权限，然后以独占权限打开
#define MV_CODEREADER_ACCESS_ExclusiveWithSwitch                               2
// 控制权限，其他APP允许读所有寄存器
#define MV_CODEREADER_ACCESS_Control                                           3
// 可以从5的模式下抢占权限，然后以控制权限打开
#define MV_CODEREADER_ACCESS_ControlWithSwitch                                 4
// 以可被抢占的控制权限打开
#define MV_CODEREADER_ACCESS_ControlSwitchEnable                               5
// 可以从5的模式下抢占权限，然后以可被抢占的控制权限打开
#define MV_CODEREADER_ACCESS_ControlSwitchEnableWithKey                        6
// 读模式打开设备，适用于控制权限下
#define MV_CODEREADER_ACCESS_Monitor                                           7

// 节点访问模式
enum MV_CODEREADER_XML_AccessMode
{
    MV_CODEREADER_AM_NI,                                // 节点未实现
    MV_CODEREADER_AM_NA,                                // 节点不可达
    MV_CODEREADER_AM_WO,                                // 节点只写
    MV_CODEREADER_AM_RO,                                // 节点只读
    MV_CODEREADER_AM_RW,                                // 节点可读可写
    MV_CODEREADER_AM_Undefined,                         // 节点未定义
    MV_CODEREADER_AM_CycleDetect,                       // 节点需周期检测
};

// 每个节点对应的接口类型
enum MV_CODEREADER_XML_InterfaceType
{
    MV_CODEREADER_IFT_IValue,                       // Value类型值
    MV_CODEREADER_IFT_IBase,                        // Base类型值
    MV_CODEREADER_IFT_IInteger,                     // Integer类型值
    MV_CODEREADER_IFT_IBoolean,                     // Boolean类型值
    MV_CODEREADER_IFT_ICommand,                     // Command类型值
    MV_CODEREADER_IFT_IFloat,                       // Float类型值
    MV_CODEREADER_IFT_IString,                      // String类型值
    MV_CODEREADER_IFT_IRegister,                    // Register类型值
    MV_CODEREADER_IFT_ICategory,                    // Category类型值
    MV_CODEREADER_IFT_IEnumeration,                 // Enumeration类型值
    MV_CODEREADER_IFT_IEnumEntry,                   // EnumEntry类型值
    MV_CODEREADER_IFT_IPort,                        // Port类型值
};

// Event事件回调信息 
#define MV_CODEREADER_MAX_EVENT_NAME_SIZE     128       // 相机Event事件名称最大长度

typedef struct _MV_CODEREADER_EVENT_OUT_INFO_
{
    char            EventName[MV_CODEREADER_MAX_EVENT_NAME_SIZE];     // Event名称

    unsigned short  nEventID;                           // Event号
    unsigned short  nStreamChannel;                     // 流通道序号

    unsigned int    nBlockIdHigh;                       // 帧号高位
    unsigned int    nBlockIdLow;                        // 帧号低位

    unsigned int    nTimestampHigh;                     // 时间戳高位
    unsigned int    nTimestampLow;                      // 时间戳低位

    void *          pEventData;                         // Event数据
    unsigned int    nEventDataSize;                     // Event数据长度

    unsigned int    nReserved[16];                      // 预留
}MV_CODEREADER_EVENT_OUT_INFO;

// 文件存取
typedef struct _MV_CODEREADER_FILE_ACCESS_T
{
    const char * pUserFileName;                         // 用户文件名
    const char * pDevFileName;                          // 设备文件名

    unsigned int    nReserved[32];                      // 预留字节
}MV_CODEREADER_FILE_ACCESS;

// 文件存取进度
typedef struct _MV_CODEREADER_FILE_ACCESS_PROGRESS_T
{
    int64_t nCompleted;                                 // 已完成的长度
    int64_t nTotal;                                     // 总长度

    unsigned int    nReserved[8];                       // 预留字节
}MV_CODEREADER_FILE_ACCESS_PROGRESS;

// Enum类型值
typedef struct _MV_CODEREADER_ENUMVALUE_T
{
    unsigned int    nCurValue;                                          // 当前值
    unsigned int    nSupportedNum;                                      // 有效数据个数
    unsigned int    nSupportValue[MV_CODEREADER_MAX_XML_SYMBOLIC_NUM];  // 支持的枚举类型

    unsigned int    nReserved[4];                                       // 保留字节
}MV_CODEREADER_ENUMVALUE;

// Int类型值
typedef struct _MV_CODEREADER_INTVALUE_T
{
    unsigned int    nCurValue;                          // 当前值
    unsigned int    nMax;                               // 最大值
    unsigned int    nMin;                               // 最小值
    unsigned int    nInc;                               // 增量值

    unsigned int    nReserved[4];                       // 保留字节
}MV_CODEREADER_INTVALUE;

// Int类型值
typedef struct _MV_CODEREADER_INTVALUE_EX_T
{
    int64_t    nCurValue;                               // 当前值
    int64_t    nMax;                                    // 最大值
    int64_t    nMin;                                    // 最小值
    int64_t    nInc;                                    // 增量值

    unsigned int    nReserved[16];                      // 保留字节
}MV_CODEREADER_INTVALUE_EX;

// Float类型值
typedef struct _MV_CODEREADER_FLOATVALUE_T
{
    float           fCurValue;                          // 当前值
    float           fMax;                               // 最大值
    float           fMin;                               // 最小值

    unsigned int    nReserved[4];                       // 保留字节
}MV_CODEREADER_FLOATVALUE;

// String类型值
typedef struct _MV_CODEREADER_STRINGVALUE_T
{
    char            chCurValue[256];                    // 当前值

    int64_t         nMaxLength;                         // 最大长度
    unsigned int    nReserved[2];                       // 保留字节
}MV_CODEREADER_STRINGVALUE;

// 最大条码长度
#define MV_CODEREADER_MAX_BCR_CODE_LEN 256

// 最大条码长度扩展
#define MV_CODEREADER_MAX_BCR_CODE_LEN_EX 4096

// 最大OCR长度
#define MV_CODEREADER_MAX_OCR_LEN 128

// Int型坐标
typedef struct _MV_CODEREADER_POINT_I_
{
    int x;                                              // x坐标
    int y;                                              // y坐标
}MV_CODEREADER_POINT_I;

// Float型坐标
typedef struct _MV_CODEREADER_POINT_F_
{
    float x;                                            // x坐标
    float y;                                            // y坐标
}MV_CODEREADER_POINT_F;

// 条码信息
typedef struct _MV_CODEREADER_BCR_INFO_
{
    unsigned int                nID;                                        // 条码ID
    char                        chCode[MV_CODEREADER_MAX_BCR_CODE_LEN];     // 字符
    unsigned int                nLen;                                       // 字符长度
    unsigned int                nBarType;                                   // 条码类型

    MV_CODEREADER_POINT_I       pt[4];                                      // 条码位置

    // 一维码：以图像x正轴为基准，顺时针0-3600度；二维码：以图像x正轴为基准，逆时针0-3600度
    int                         nAngle;                                     // 条码角度(10倍)（0~3600）
    unsigned int                nMainPackageId;                             // 主包ID
    unsigned int                nSubPackageId;                              // 次包ID
    unsigned short              sAppearCount;                               // 条码被识别的次数
    unsigned short              sPPM;                                       // PPM(10倍)
    unsigned short              sAlgoCost;                                  // 算法耗时
    unsigned short              sSharpness;                                 // 图像清晰度(10倍)
} MV_CODEREADER_BCR_INFO;

// 条码质量（质量分5等[0,4], 越高等质量越好; 1D指一维码，2D指二维码）
typedef struct _MV_CODEREADER_CODE_INFO_
{
    // 等级
    int             nOverQuality;             // 总体质量评分（1D/2D共用）
    int             nDeCode;                  // 译码评分（1D/2D共用）
    int             nSCGrade;                 // Symbol Contrast对比度质量评分（1D/2D共用）
    int             nModGrade;                // modulation模块均匀性评分（1D/2D共用）

    // 2D等级
    int             nFPDGrade;                // fixed_pattern_damage评分
    int             nANGrade;                 // axial_nonuniformity码轴规整性评分 
    int             nGNGrade;                 // grid_nonuniformity基础grid均匀性质量评分
    int             nUECGrade;                // unused_error_correction未使用纠错功能评分
    int             nPGHGrade;                // Print Growth Horizontal 打印伸缩(水平)评分
    int             nPGVGrade;                // Print Growth Veritical 打印伸缩(垂直)评分

    // 分数
    float           fSCScore;                 // Symbol Contrast对比度质量分数（1D/2D共用）
    float           fModScore;                // modulation模块均匀性分数（1D/2D共用）

    // 2D分数
    float           fFPDScore;                // fixed_pattern_damage分数
    float           fAnScore;                 // axial_nonuniformity码轴规整性分数 
    float           fGNScore;                 // grid_nonuniformity基础grid均匀性质量分数
    float           fUECScore;                // unused_error_correction未使用纠错功能分数
    float           fPGHScore;                // Print Growth Horizontal 打印伸缩(水平)分数
    float           fPGVScore;                // Print Growth Veritical 打印伸缩(垂直)分数

    int             nRMGrade;                 // reflectance margin反射率余量评分
    float           fRMScore;                 // reflectance margin反射率余量分数

    // 1D等级
    int             n1DEdgeGrade;               // edge determination     边缘确定度质量等级
    int             n1DMinRGrade;               // minimum reflectance    最小反射率质量等级
    int             n1DMinEGrade;               // minimum edge contrast  最小边缘对比度质量等级
    int             n1DDcdGrade;                // decodability           可译码性质量等级 
    int             n1DDefGrade;                // defects                缺陷质量等级
    int             n1DQZGrade;                 // quiet zone             静区质量等级

    // 1D分数
    float           f1DEdgeScore;               // edge determination     边缘确定度分数
    float           f1DMinRScore;               // minimum reflectance    最小反射率分数
    float           f1DMinEScore;               // minimum edge contrast  最小边缘对比度分数
    float           f1DDcdScore;                // decodability           可译码性分数 
    float           f1DDefScore;                // defects                缺陷分数
    float           f1DQZScore;                 // quiet zone             静区分数

    int    nReserved[18];

} MV_CODEREADER_CODE_INFO;

// 带质量信息的BCR信息
typedef struct _MV_CODEREADER_BCR_INFO_EX_
{
    unsigned int                nID;                                        // 条码ID
    char                        chCode[MV_CODEREADER_MAX_BCR_CODE_LEN];     // 字符
    unsigned int                nLen;                                       // 字符长度
    unsigned int                nBarType;                                   // 条码类型

    MV_CODEREADER_POINT_I       pt[4];                                      // 条码位置
    MV_CODEREADER_CODE_INFO     stCodeQuality;                              // 条码质量评价

    // 一维码：以图像x正轴为基准，顺时针0-3600度；二维码：以图像x正轴为基准，逆时针0-3600度
    int                         nAngle;                                     // 条码角度(10倍)（0~3600）
    unsigned int                nMainPackageId;                             // 主包ID
    unsigned int                nSubPackageId;                              // 次包ID
    unsigned short              sAppearCount;                               // 条码被识别的次数
    unsigned short              sPPM;                                       // PPM(10倍)
    unsigned short              sAlgoCost;                                  // 算法耗时(ms)
    unsigned short              sSharpness;                                 // 清晰度
    bool                        bIsGetQuality;                              // 是否支持二维码质量评级
    unsigned int                nIDRScore;                                  // 读码评分

    unsigned int                n1DIsGetQuality;                            // 是否支持一维码质量评级(0-不支持 1-支持)

    unsigned int                nReserved[29];

} MV_CODEREADER_BCR_INFO_EX;


// 带质量信息且条码字符扩展的BCR信息
typedef struct _MV_CODEREADER_BCR_INFO_EX_2_
{
    unsigned int                nID;                                        // 条码ID
    char                        chCode[MV_CODEREADER_MAX_BCR_CODE_LEN_EX];  // 字符可识别长度扩展至4096
    unsigned int                nLen;                                       // 字符实际真实长度
    unsigned int                nBarType;                                   // 条码类型

    MV_CODEREADER_POINT_I       pt[4];                                      // 条码位置
    MV_CODEREADER_CODE_INFO     stCodeQuality;                              // 条码质量评价

    // 一维码：以图像x正轴为基准，顺时针0-3600度；二维码：以图像x正轴为基准，逆时针0-3600度
    int                         nAngle;                                     // 条码角度(10倍)（0~3600）
    unsigned int                nMainPackageId;                             // 主包ID
    unsigned int                nSubPackageId;                              // 次包ID
    unsigned short              sAppearCount;                               // 条码被识别的次数
    unsigned short              sPPM;                                       // PPM(10倍)
    unsigned short              sAlgoCost;                                  // 算法耗时(ms)
    unsigned short              sSharpness;                                 // 清晰度
    bool                        bIsGetQuality;                              // 是否支持二维码质量评级
    unsigned int                nIDRScore;                                  // 读码评分

    unsigned int                n1DIsGetQuality;                            // 是否支持一维码质量评级(0-不支持 1-支持)

    int                         nReserved[64];

} MV_CODEREADER_BCR_INFO_EX2;

// 一次最多输出条码个数
#define MAX_CODEREADER_BCR_COUNT    200

// 一次最多输出条码个数
#define MAX_CODEREADER_BCR_COUNT_EX    300

// 条码信息列表
typedef struct _MV_CODEREADER_RESULT_BCR_
{
    unsigned int            nCodeNum;                                   // 条码数量
    MV_CODEREADER_BCR_INFO  stBcrInfo[MAX_CODEREADER_BCR_COUNT];        // 条码信息
    unsigned int            nReserved[4];                               // 保留字节
}MV_CODEREADER_RESULT_BCR;

// 条码信息加条码质量列表
typedef struct _MV_CODEREADER_RESULT_BCR_EX_
{
    unsigned int                        nCodeNum;                                   // 条码数量
    MV_CODEREADER_BCR_INFO_EX           stBcrInfoEx[MAX_CODEREADER_BCR_COUNT];      // 条码信息
    unsigned int                        nReserved[4];                               // 保留字节
}MV_CODEREADER_RESULT_BCR_EX;

// 条码信息字符扩展加条码质量列表
typedef struct _MV_CODEREADER_RESULT_BCR_EX_2_
{
    unsigned int                        nCodeNum;                                   // 条码数量（扩展）
    MV_CODEREADER_BCR_INFO_EX2          stBcrInfoEx2[MAX_CODEREADER_BCR_COUNT_EX];  // 条码信息（条码字符扩展）
    unsigned int                        nReserved[8];                               // 保留字节
}MV_CODEREADER_RESULT_BCR_EX2;

// 最大数据缓存
#define MV_CODEREADER_MAX_RESULT_SIZE       (1024*64)

// 输出帧信息
typedef struct _MV_CODEREADER_IMAGE_OUT_INFO_
{
    unsigned short      nWidth;                                     // 图像宽
    unsigned short      nHeight;                                    // 图像高
    MvCodeReaderGvspPixelType   enPixelType;                        // 像素或图片格式

    unsigned int        nTriggerIndex;                              // 触发序号
    unsigned int        nFrameNum;                                  // 帧号
    unsigned int        nFrameLen;                                  // 当前帧数据大小
    unsigned int        nTimeStampHigh;                             // 时间戳高32位
    unsigned int        nTimeStampLow;                              // 时间戳低32位

    unsigned int        nResultType;                                // 输出消息类型

    unsigned char       chResult[MV_CODEREADER_MAX_RESULT_SIZE];    // 根据消息类型对应不同结构体
    bool                bIsGetCode;                                 // 是否读到条码

    unsigned char*      pImageWaybill;                              // 面单图像
    unsigned int        nImageWaybillLen;                           // 面单数据大小
    enum MV_CODEREADER_IAMGE_TYPE     enWaybillImageType;           // 面单图像类型

    unsigned int        bFlaseTrigger;                              // 是否误触发
    unsigned int        nFocusScore;                                // 聚焦得分

    unsigned int        nChannelID;                                 // 对应Stream通道序号
    unsigned int        nImageCost;                                 // 帧图像在相机内部的处理耗时

    unsigned int        nReserved[6];                               // 保留字节
}MV_CODEREADER_IMAGE_OUT_INFO;


typedef struct _MV_CODEREADER_WAYBILL_INFO_
{
    // 面单坐标信息
    float fCenterX;                 // 中心点列坐标
    float fCenterY;                 // 中心点行坐标
    float fWidth;                   // 矩形宽度，宽度为长半轴
    float fHeight;                  // 矩形高度，高度为短半轴
    float fAngle;                   // 矩形角度
    float fConfidence;              // 置信度

    // 面单图片
    unsigned char*  pImageWaybill;
    unsigned int    nImageLen;

	unsigned int	nOcrRowNum;		// 当前面单内的ocr行数
    unsigned int    nReserved[11];
}MV_CODEREADER_WAYBILL_INFO;

#define MAX_CODEREADER_WAYBILL_COUNT        50
#define MAX_CODEREADER_OCR_COUNT			100

// 面单信息列表
typedef struct _MV_CODEREADER_WAYBILL_LIST_
{
    unsigned int                    nWaybillNum;                                    // 面单数量
    enum MV_CODEREADER_IAMGE_TYPE   enWaybillImageType;                             // 面单图像类型，可选择bmp、raw、jpg输出

    MV_CODEREADER_WAYBILL_INFO      stWaybillInfo[MAX_CODEREADER_WAYBILL_COUNT];    // 面单信息

	unsigned int					nOcrAllNum;										// 所有面单内的OCR总行数 面单1(ocr)+面单2(ocr)+...
    unsigned int                    nReserved[3];                                   // 保留字节
}MV_CODEREADER_WAYBILL_LIST;

// OCR基础信息
typedef struct _MV_CODEREADER_OCR_ROW_INFO_
{
	unsigned int                nID;                                        // OCR ID
	unsigned int                nOcrLen;                                    // OCR字符实际真实长度
	char                        chOcr[MV_CODEREADER_MAX_OCR_LEN];			// 识别到的OCR字符

	float						fCharConfidence;							// 字符行整体置信度

	unsigned int				nOcrRowCenterX;                 // 单行OCR中心点列坐标
	unsigned int				nOcrRowCenterY;                 // 单行OCR中心点行坐标
	unsigned int				nOcrRowWidth;                   // 单行OCR矩形宽度，宽度为长半轴
	unsigned int				nOcrRowHeight;                  // 单行OCR矩形高度，高度为短半轴
	float						fOcrRowAngle;                   // 单行OCR矩形角度
	float						fDeteConfidence;                // 单行OCR定位置信度
	unsigned short				sOcrAlgoCost;                   // OCR算法耗时 单位ms

	unsigned short				sReserved;						// 预留
	int							nReserved[31];
}MV_CODEREADER_OCR_ROW_INFO;

// OCR信息列表
typedef struct _MV_CODEREADER_OCR_INFO_LIST_
{
	unsigned int                    nOCRAllNum;                                    // 所有面单内的OCR总行数

	MV_CODEREADER_OCR_ROW_INFO      stOcrRowInfo[MAX_CODEREADER_OCR_COUNT];    // OCR行基础信息

	int                    nReserved[8];                                   // 保留字节
}MV_CODEREADER_OCR_INFO_LIST;

typedef struct _MV_CODEREADER_IMAGE_OUT_INFO_EX_
{
    unsigned short              nWidth;                     // 图像宽
    unsigned short              nHeight;                    // 图像高
    MvCodeReaderGvspPixelType   enPixelType;                // 像素或图片格式

    unsigned int                nTriggerIndex;              // 触发序号
    unsigned int                nFrameNum;                  // 帧号
    unsigned int                nFrameLen;                  // 当前帧数据大小
    unsigned int                nTimeStampHigh;             // 时间戳高32位
    unsigned int                nTimeStampLow;              // 时间戳低32位

    unsigned int                bFlaseTrigger;              // 是否误触发
    unsigned int                nFocusScore;                // 聚焦得分

    bool                        bIsGetCode;                 // 是否读到条码
    MV_CODEREADER_RESULT_BCR*   pstCodeList;

    MV_CODEREADER_WAYBILL_LIST* pstWaybillList;             // 面单信息

    unsigned int                nEventID;                   // 事件ID

    unsigned int                nChannelID;                 // 对应Stream通道序号

    unsigned int                nImageCost;                 // 帧图像在相机内部的处理耗时

	union
	{
		MV_CODEREADER_OCR_INFO_LIST*   pstOcrList;     // OCR信息
		int64_t nAligning;
	}UnparsedOcrList;

    unsigned int                nReserved[4];               // 保留字节
}MV_CODEREADER_IMAGE_OUT_INFO_EX;

typedef struct _MV_CODEREADER_IMAGE_OUT_INFO_EX_2_
{
    unsigned short                  nWidth;                     // 图像宽
    unsigned short                  nHeight;                    // 图像高
    MvCodeReaderGvspPixelType       enPixelType;                // 像素或图片格式

    unsigned int                    nTriggerIndex;              // 触发序号
    unsigned int                    nFrameNum;                  // 帧号
    unsigned int                    nFrameLen;                  // 当前帧数据大小
    unsigned int                    nTimeStampHigh;             // 时间戳高32位
    unsigned int                    nTimeStampLow;              // 时间戳低32位

    unsigned int                    bFlaseTrigger;              // 是否误触发
    unsigned int                    nFocusScore;                // 聚焦得分

    bool                            bIsGetCode;                 // 是否读到条码
    MV_CODEREADER_RESULT_BCR_EX*    pstCodeListEx;              // 条码信息

    MV_CODEREADER_WAYBILL_LIST*     pstWaybillList;             // 面单信息

    unsigned int                    nEventID;                   // 事件ID
    unsigned int                    nChannelID;                 // 对应Stream通道序号
    unsigned int                    nImageCost;                 // 帧图像在相机内部的处理耗时

    union
    {
        MV_CODEREADER_RESULT_BCR_EX2*   pstCodeListEx2;     // 条码信息（条码字符长度扩展）建议以该扩展条码字符的条码信息解析条码
        int64_t nAligning;
    }UnparsedBcrList;

	union
	{
		MV_CODEREADER_OCR_INFO_LIST*   pstOcrList;     // OCR信息
		int64_t nAligning;
	}UnparsedOcrList;

    unsigned int                    nReserved[26];               // 保留字节
}MV_CODEREADER_IMAGE_OUT_INFO_EX2;


// 输出信息类型
enum MvCodeReaderType
{
    CodeReader_ResType_NULL       = 0,    // 没有结果输出
    CodeReader_ResType_BCR        = 1,    // 输出信息为BCR(对应结构体 MV_CODEREADER_RESULT_BCR)
};

// 输出协议类型
#define CommuPtlSmartSDK 1          // SamrtSDK协议
#define CommuPtlTcpIP    2          // TCPIP协议
#define CommuPtlSerial   3          // Serial协议

/************************************************************************/
/* 抠图参数，内部有默认值，可以不设置                                   */
/************************************************************************/
#define KEY_WAYBILL_ABILITY                     "WAYBILL_Ability"                   // 算法能力集，含面单提取[0x1]，图像增强[0x2]，码提取[0x4]，Box拷贝模块[0x8]，面单提取模块[0x10]，模块最大编号[0x3F]
#define KEY_WAYBILL_MAX_WIDTH                   "WAYBILL_Max_Width"                 // 算法最大宽度，默认5472，范围[0,65535]
#define KEY_WAYBILL_MAX_HEIGHT                  "WAYBILL_Max_Height"                // 算法最大高度，默认3648，范围[0,65535]
#define KEY_WAYBILL_OUTPUTIMAGETYPE             "WAYBILL_OutputImageType"           // 面单抠图输出的图片格式，默认Jpg，范围[1,3],1为Mono8，2为Jpg，3为Bmp
#define KEY_WAYBILL_JPGQUALITY                  "WAYBILL_JpgQuality"                // jpg编码质量，默认80，范围[1,100]
#define KEY_WAYBILL_ENHANCEENABLE               "WAYBILL_EnhanceEnable"             // 图像增强使能，默认0，范围[0,1]

#define KEY_WAYBILL_MINWIDTH                    "WAYBILL_MinWidth"                  // waybill最小宽, 宽是长边, 高是短边，默认100，范围[15,2592]
#define KEY_WAYBILL_MINHEIGHT                   "WAYBILL_MinHeight"                 // waybill最小高，默认100，范围[10,2048]
#define KEY_WAYBILL_MAXWIDTH                    "WAYBILL_MaxWidth"                  // waybill最大宽, 宽是长边, 高是短边，默认3072，最小值15
#define KEY_WAYBILL_MAXHEIGHT                   "WAYBILL_MaxHeight"                 // waybill最大高，默认2048，最小值10
#define KEY_WAYBILL_MORPHTIMES                  "WAYBILL_MorphTimes"                // 膨胀次数，默认0，范围[0,10]
#define KEY_WAYBILL_GRAYLOW                     "WAYBILL_GrayLow"                   // 面单上条码和字符灰度最小值，默认0，范围[0,255]
#define KEY_WAYBILL_GRAYMID                     "WAYBILL_GrayMid"                   // 面单上灰度中间值，用于区分条码和背景，默认70，范围[0,255]
#define KEY_WAYBILL_GRAYHIGH                    "WAYBILL_GrayHigh"                  // 面单上背景灰度最大值，默认130，范围[0,255]
#define KEY_WAYBILL_BINARYADAPTIVE              "WAYBILL_BinaryAdaptive"            // 自适应二值化，默认1，范围[0,1]
#define KEY_WAYBILL_BOUNDARYROW                 "WAYBILL_BoundaryRow"               // 面单抠图行方向扩边，默认0，范围[0,2000]
#define KEY_WAYBILL_BOUNDARYCOL                 "WAYBILL_BoundaryCol"               // 面单抠图列方向扩边，默认0，范围[0,2000]
#define KEY_WAYBILL_MAXBILLBARHEIGTHRATIO       "WAYBILL_MaxBillBarHightRatio"      // 最大面单和条码高度比例，默认20，范围[1,100]
#define KEY_WAYBILL_MAXBILLBARWIDTHRATIO        "WAYBILL_MaxBillBarWidthRatio"      // 最大面单和条码宽度比例，默认5，范围[1,100]
#define KEY_WAYBILL_MINBILLBARHEIGTHRATIO       "WAYBILL_MinBillBarHightRatio"      // 最小面单和条码高度比例，默认5，范围[1,100]
#define KEY_WAYBILL_MINBILLBARWIDTHRATIO        "WAYBILL_MinBillBarWidthRatio"      // 最小面单和条码宽度比例，默认2，范围[1,100]
#define KEY_WAYBILL_ENHANCEMETHOD               "WAYBILL_EnhanceMethod"             // 增强方法，最小值/默认值/不进行增强[0x1]，线性拉伸[0x2]，直方图拉伸[0x3]，直方图均衡化[0x4]，亮度校正/最大值[0x5]
#define KEY_WAYBILL_ENHANCECLIPRATIOLOW         "WAYBILL_ClipRatioLow"              // 增强拉伸低阈值比例，默认1，范围[0,100]
#define KEY_WAYBILL_ENHANCECLIPRATIOHIGH        "WAYBILL_ClipRatioHigh"             // 增强拉伸高阈值比例，默认99，范围[0,100]
#define KEY_WAYBILL_ENHANCECONTRASTFACTOR       "WAYBILL_ContrastFactor"            // 对比度系数，默认100，范围[1,10000] 
#define KEY_WAYBILL_ENHANCESHARPENFACTOR        "WAYBILL_SharpenFactor"             // 锐化系数，默认0，范围[0,10000]
#define KEY_WAYBILL_SHARPENKERNELSIZE           "WAYBILL_KernelSize"                // 锐化滤波核大小，默认3，范围[3,15]
#define KEY_WAYBILL_CODEBOUNDARYROW             "WAYBILL_CodeBoundaryRow"           // 码单抠图行方向扩边，默认0，范围[0,2000]
#define KEY_WAYBILL_CODEBOUNDARYCOL             "WAYBILL_CodeBoundaryCol"           // 码单抠图列方向扩边，默认0，范围[0,2000]


/************************************************************************/
/* 升级相关高级参数                                                      */
/************************************************************************/
// 升级最大支持的设备个数
#define MV_CODEREADER_MAX_UPGARDEDEVICE_NUM     100

// 设备运行状态
enum MV_CODEREADER_PROGRAM_STATE
{
    MV_CODEREADER_PROGRAM_UNKNOWN,                      // 未知状态
    MV_CODEREADER_PROGRAM_RUNNING,                      // 设备正在运行
    MV_CODEREADER_PROGRAM_STOP                          // 设备停止运行
};

// 设备当前连接状态
typedef enum _MV_CODEREADER_DEVICE_CONNECT_STATUS_
{
    MV_CODEREADER_DEVICE_STATUS_FREE          = 1,      // 空闲状态
    MV_CODEREADER_DEVICE_STATUS_BASE          = 2,      // 第三方连接状态

}MV_CODEREADER_DEVICE_CONNECT_STATUS;

//明场/暗场矫正模式
typedef enum _MV_CODEREADER_FIELD_CORRECT_MODE_
{
    MV_CODEREADER_DARK_FILED_CORRECT         = 0,       // 暗场校验
    MV_CODEREADER_BRIGHT_FILED_CORRECT       = 1,       // 明场校验
    MV_CODEREADER_INVAILED_FILED_CORRECT     = 2,       // 无效校验

}MV_CODEREADER_FIELD_CORRECT_MODE;

#endif /* _MV_CODEREADER_PARAMS_H_ */
