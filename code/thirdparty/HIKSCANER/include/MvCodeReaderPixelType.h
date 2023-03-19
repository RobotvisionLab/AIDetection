
#ifndef _MV_CODEREADER_PIXEL_TYPE_H_
#define _MV_CODEREADER_PIXEL_TYPE_H_



/************************************************************************/
/*     GigE Vision (2.0.03) PIXEL FORMATS                               */
/************************************************************************/

// Indicate if pixel is monochrome or RGB
#define MV_CODEREADER_GVSP_PIX_MONO                                0x01000000
#define MV_CODEREADER_GVSP_PIX_RGB                                 0x02000000 // deprecated in version 1.1
#define MV_CODEREADER_GVSP_PIX_COLOR                               0x02000000
#define MV_CODEREADER_GVSP_PIX_CUSTOM                              0x80000000
#define MV_CODEREADER_GVSP_PIX_COLOR_MASK                          0xFF000000

// Indicate effective number of bits occupied by the pixel (including padding).
// This can be used to compute amount of memory required to store an image.
#define MV_CODEREADER_PIXEL_BIT_COUNT(n)                           ((n) << 16)

#define MV_CODEREADER_GVSP_PIX_EFFECTIVE_PIXEL_SIZE_MASK           0x00FF0000
#define MV_CODEREADER_GVSP_PIX_EFFECTIVE_PIXEL_SIZE_SHIFT          16

// Pixel ID: lower 16-bit of the pixel formats
#define MV_CODEREADER_GVSP_PIX_ID_MASK                             0x0000FFFF
#define MV_CODEREADER_GVSP_PIX_COUNT                               0x46 // next Pixel ID available


enum MvCodeReaderGvspPixelType
{
    // Undefined pixel type
#ifdef WIN32
    PixelType_CodeReader_Gvsp_Undefined                =   0xFFFFFFFF, 
#else
    PixelType_CodeReader_Gvsp_Undefined                =   -1, 
#endif

    // Mono buffer format defines
    PixelType_CodeReader_Gvsp_Mono1p                   =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(1) | 0x0037),
    PixelType_CodeReader_Gvsp_Mono2p                   =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(2) | 0x0038),
    PixelType_CodeReader_Gvsp_Mono4p                   =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(4) | 0x0039),
    PixelType_CodeReader_Gvsp_Mono8                    =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(8) | 0x0001),
    PixelType_CodeReader_Gvsp_Mono8_Signed             =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(8)  | 0x0002),
    PixelType_CodeReader_Gvsp_Mono10                   =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0003),
    PixelType_CodeReader_Gvsp_Mono10_Packed            =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x0004),
    PixelType_CodeReader_Gvsp_Mono12                   =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0005),
    PixelType_CodeReader_Gvsp_Mono12_Packed            =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x0006),
    PixelType_CodeReader_Gvsp_Mono14                   =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0025),
    PixelType_CodeReader_Gvsp_Mono16                   =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0007),

    // Bayer buffer format defines 
    PixelType_CodeReader_Gvsp_BayerGR8                 =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(8) | 0x0008),
    PixelType_CodeReader_Gvsp_BayerRG8                 =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(8) | 0x0009),
    PixelType_CodeReader_Gvsp_BayerGB8                 =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(8) | 0x000A),
    PixelType_CodeReader_Gvsp_BayerBG8                 =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(8) | 0x000B),
    PixelType_CodeReader_Gvsp_BayerGR10                =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x000C),
    PixelType_CodeReader_Gvsp_BayerRG10                =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x000D),
    PixelType_CodeReader_Gvsp_BayerGB10                =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x000E),
    PixelType_CodeReader_Gvsp_BayerBG10                =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x000F),
    PixelType_CodeReader_Gvsp_BayerGR12                =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0010),
    PixelType_CodeReader_Gvsp_BayerRG12                =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0011),
    PixelType_CodeReader_Gvsp_BayerGB12                =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0012),
    PixelType_CodeReader_Gvsp_BayerBG12                =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0013),
    PixelType_CodeReader_Gvsp_BayerGR10_Packed         =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x0026),
    PixelType_CodeReader_Gvsp_BayerRG10_Packed         =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x0027),
    PixelType_CodeReader_Gvsp_BayerGB10_Packed         =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x0028),
    PixelType_CodeReader_Gvsp_BayerBG10_Packed         =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x0029),
    PixelType_CodeReader_Gvsp_BayerGR12_Packed         =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x002A),
    PixelType_CodeReader_Gvsp_BayerRG12_Packed         =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x002B),
    PixelType_CodeReader_Gvsp_BayerGB12_Packed         =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x002C),
    PixelType_CodeReader_Gvsp_BayerBG12_Packed         =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x002D),
    PixelType_CodeReader_Gvsp_BayerGR16                =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x002E),
    PixelType_CodeReader_Gvsp_BayerRG16                =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x002F),
    PixelType_CodeReader_Gvsp_BayerGB16                =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0030),
    PixelType_CodeReader_Gvsp_BayerBG16                =   (MV_CODEREADER_GVSP_PIX_MONO | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0031),

    // RGB Packed buffer format defines 
    PixelType_CodeReader_Gvsp_RGB8_Packed              =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(24) | 0x0014),
    PixelType_CodeReader_Gvsp_BGR8_Packed              =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(24) | 0x0015),
    PixelType_CodeReader_Gvsp_RGBA8_Packed             =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(32) | 0x0016),
    PixelType_CodeReader_Gvsp_BGRA8_Packed             =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(32) | 0x0017),
    PixelType_CodeReader_Gvsp_RGB10_Packed             =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(48) | 0x0018),
    PixelType_CodeReader_Gvsp_BGR10_Packed             =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(48) | 0x0019),
    PixelType_CodeReader_Gvsp_RGB12_Packed             =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(48) | 0x001A),
    PixelType_CodeReader_Gvsp_BGR12_Packed             =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(48) | 0x001B),
    PixelType_CodeReader_Gvsp_RGB16_Packed             =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(48) | 0x0033),
    PixelType_CodeReader_Gvsp_RGB10V1_Packed           =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(32) | 0x001C),
    PixelType_CodeReader_Gvsp_RGB10V2_Packed           =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(32) | 0x001D),
    PixelType_CodeReader_Gvsp_RGB12V1_Packed           =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(36) | 0X0034),
    PixelType_CodeReader_Gvsp_RGB565_Packed            =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0035),
    PixelType_CodeReader_Gvsp_BGR565_Packed            =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0X0036),

    // YUV Packed buffer format defines 
    PixelType_CodeReader_Gvsp_YUV411_Packed            =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x001E),
    PixelType_CodeReader_Gvsp_YUV422_Packed            =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x001F),
    PixelType_CodeReader_Gvsp_YUV422_YUYV_Packed       =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0032),
    PixelType_CodeReader_Gvsp_YUV444_Packed            =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(24) | 0x0020),
    PixelType_CodeReader_Gvsp_YCBCR8_CBYCR             =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(24) | 0x003A),
    PixelType_CodeReader_Gvsp_YCBCR422_8               =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x003B),
    PixelType_CodeReader_Gvsp_YCBCR422_8_CBYCRY        =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0043),
    PixelType_CodeReader_Gvsp_YCBCR411_8_CBYYCRYY      =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x003C),
    PixelType_CodeReader_Gvsp_YCBCR601_8_CBYCR         =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(24) | 0x003D),
    PixelType_CodeReader_Gvsp_YCBCR601_422_8           =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x003E),
    PixelType_CodeReader_Gvsp_YCBCR601_422_8_CBYCRY    =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0044),
    PixelType_CodeReader_Gvsp_YCBCR601_411_8_CBYYCRYY  =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x003F),
    PixelType_CodeReader_Gvsp_YCBCR709_8_CBYCR         =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(24) | 0x0040),
    PixelType_CodeReader_Gvsp_YCBCR709_422_8           =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0041),
    PixelType_CodeReader_Gvsp_YCBCR709_422_8_CBYCRY    =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(16) | 0x0045),
    PixelType_CodeReader_Gvsp_YCBCR709_411_8_CBYYCRYY  =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(12) | 0x0042),

    // RGB Planar buffer format defines 
    PixelType_CodeReader_Gvsp_RGB8_Planar              =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(24) | 0x0021),
    PixelType_CodeReader_Gvsp_RGB10_Planar             =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(48) | 0x0022),
    PixelType_CodeReader_Gvsp_RGB12_Planar             =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(48) | 0x0023),
    PixelType_CodeReader_Gvsp_RGB16_Planar             =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(48) | 0x0024),

    // 自定义的图片格式
    PixelType_CodeReader_Gvsp_Jpeg                     =   (MV_CODEREADER_GVSP_PIX_CUSTOM | MV_CODEREADER_PIXEL_BIT_COUNT(24) | 0x0001),

    PixelType_CodeReader_Gvsp_Coord3D_ABC32f           =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(96) | 0x00C0),
    PixelType_CodeReader_Gvsp_Coord3D_ABC32f_Planar    =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(96) | 0x00C1),


    PixelType_CodeReader_Gvsp_Coord3D_AC32f            =   (MV_CODEREADER_GVSP_PIX_COLOR | MV_CODEREADER_PIXEL_BIT_COUNT(40) | 0x00C2),//0x024000C2, /* 3D coordinate A-C 32-bit floating point */
    PixelType_CodeReader_Gvsp_COORD3D_DEPTH_PLUS_MASK  =   (0x82000000 | MV_CODEREADER_PIXEL_BIT_COUNT(28) | 0x0001),//0x82280001
};

//跨平台定义
//Cross Platform Definition
#ifdef WIN32
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif


#endif /* _MV_CODEREADER_PIXEL_TYPE_H_ */
