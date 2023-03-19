
#ifndef _MV_CODEREADER_ERROR_DEFINE_H_
#define _MV_CODEREADER_ERROR_DEFINE_H_

// ch:正确码定义
#define MV_CODEREADER_OK                                    0x00000000  ///< 成功，无错误

//通用错误码定义:范围0x80020000-0x800200FF
#define MV_CODEREADER_E_HANDLE                              0x80020000  ///< 错误或无效的句柄
#define MV_CODEREADER_E_SUPPORT                             0x80020001  ///< 不支持的功能
#define MV_CODEREADER_E_BUFOVER                             0x80020002  ///< 缓存已满
#define MV_CODEREADER_E_CALLORDER                           0x80020003  ///< 函数调用顺序错误
#define MV_CODEREADER_E_PARAMETER                           0x80020004  ///< 错误的参数
#define MV_CODEREADER_E_RESOURCE                            0x80020005  ///< 资源申请失败
#define MV_CODEREADER_E_NODATA                              0x80020006  ///< 无数据
#define MV_CODEREADER_E_PRECONDITION                        0x80020007  ///< 前置条件有误，或运行环境已发生变化
#define MV_CODEREADER_E_VERSION                             0x80020008  ///< 版本不匹配
#define MV_CODEREADER_E_NOENOUGH_BUF                        0x80020009  ///< 传入的内存空间不足
#define MV_CODEREADER_E_ABNORMAL_IMAGE                      0x8002000A  ///< 异常图像，可能是丢包导致图像不完整
#define MV_CODEREADER_E_LOAD_LIBRARY                        0x8002000B  ///< 动态导入DLL失败
#define MV_CODEREADER_E_NOOUTBUF                            0x8002000C  ///< 没有可输出的缓存
#define MV_CODEREADER_E_FILE_PATH                           0x8002000F  ///< 文件路径错误
#define MV_CODEREADER_E_UNKNOW                              0x800200FF  ///< 未知的错误

// GenICam系列错误:范围0x80020100-0x800201FF
#define MV_CODEREADER_E_GC_GENERIC                          0x80020100  ///< 通用错误
#define MV_CODEREADER_E_GC_ARGUMENT                         0x80020101  ///< 参数非法
#define MV_CODEREADER_E_GC_RANGE                            0x80020102  ///< 值超出范围
#define MV_CODEREADER_E_GC_PROPERTY                         0x80020103  ///< 属性错误
#define MV_CODEREADER_E_GC_RUNTIME                          0x80020104  ///< 运行环境有问题
#define MV_CODEREADER_E_GC_LOGICAL                          0x80020105  ///< 逻辑错误
#define MV_CODEREADER_E_GC_ACCESS                           0x80020106  ///< 节点访问条件有误
#define MV_CODEREADER_E_GC_TIMEOUT                          0x80020107  ///< 超时
#define MV_CODEREADER_E_GC_DYNAMICCAST                      0x80020108  ///< 转换异常
#define MV_CODEREADER_E_GC_UNKNOW                           0x800201FF  ///< GenICam未知错误

//GigE_STATUS对应的错误码:范围0x80000200-0x800002FF
#define MV_CODEREADER_E_NOT_IMPLEMENTED                     0x80020200  ///< 命令不被设备支持
#define MV_CODEREADER_E_INVALID_ADDRESS                     0x80020201  ///< 访问的目标地址不存在
#define MV_CODEREADER_E_WRITE_PROTECT                       0x80020202  ///< 目标地址不可写
#define MV_CODEREADER_E_ACCESS_DENIED                       0x80020203  ///< 设备无访问权限
#define MV_CODEREADER_E_BUSY                                0x80020204  ///< 设备忙，或网络断开
#define MV_CODEREADER_E_PACKET                              0x80020205  ///< 网络包数据错误
#define MV_CODEREADER_E_NETER                               0x80020206  ///< 网络相关错误

// GigE相机特有的错误码
#define MV_CODEREADER_E_IP_CONFLICT                         0x80020221  ///< 设备IP冲突

//USB_STATUS对应的错误码:范围0x80000300-0x800003FF
#define MV_CODEREADER_E_USB_READ                            0x80020300  ///< 读usb出错
#define MV_CODEREADER_E_USB_WRITE                           0x80020301  ///< 写usb出错
#define MV_CODEREADER_E_USB_DEVICE                          0x80020302  ///< 设备异常
#define MV_CODEREADER_E_USB_GENICAM                         0x80020303  ///< GenICam相关错误
#define MV_CODEREADER_E_USB_BANDWIDTH                       0x80020304  ///< 带宽不足
#define MV_CODEREADER_E_USB_DRIVER                          0x80020305  ///< 驱动不匹配或者未装驱动
#define MV_CODEREADER_E_USB_UNKNOW                          0x800203FF  ///< USB未知的错误

//升级时对应的错误码:范围0x80020400-0x800204FF
#define MV_CODEREADER_E_UPG_MIN_ERRCODE                     0x80020400  ///< 升级模块错误码最小值
#define MV_CODEREADER_E_UPG_FILE_MISMATCH                   0x80020400  ///< 升级固件不匹配
#define MV_CODEREADER_E_UPG_LANGUSGE_MISMATCH               0x80020401  ///< 升级固件语言不匹配
#define MV_CODEREADER_E_UPG_CONFLICT                        0x80020402  ///< 升级冲突
#define MV_CODEREADER_E_UPG_INNER_ERR                       0x80020403  ///< 升级时相机内部出现错误

#define MV_CODEREADER_E_UPG_REGRESH_TYPE_ERR                0x80020404  ///< 获取相机型号失败
#define MV_CODEREADER_E_UPG_COPY_FPGABIN_ERR                0x80020405  ///< 复制FPGA文件失败
#define MV_CODEREADER_E_UPG_ZIPEXTRACT_ERR                  0x80020406  ///< ZIP文件解压失败
#define MV_CODEREADER_E_UPG_DAVEXTRACT_ERR                  0x80020407  ///< DAV文件解压失败
#define MV_CODEREADER_E_UPG_DAVCOMPRESS_ERR                 0x80020408  ///< DAV文件压缩失败
#define MV_CODEREADER_E_UPG_ZIPCOMPRESS_ERR                 0x80020409  ///< ZIP文件压缩失败
#define MV_CODEREADER_E_UPG_GET_PROGRESS_TIMEOUT_ERR        0x80020410  ///< 获取升级进度超时
#define MV_CODEREADER_E_UPG_SEND_QUERY_PROGRESS_ERR         0x80020411  ///< 发送进度查询指令失败
#define MV_CODEREADER_E_UPG_RECV_QUERY_PROGRESS_ERR         0x80020412  ///< 接收进度查询指令失败
#define MV_CODEREADER_E_UPG_GET_QUERY_PROGRESS_ERR          0x80020413  ///< 获取查询进度失败
#define MV_CODEREADER_E_UPG_GET_MAX_QUERY_PROGRESS_ERR      0x80020414  ///< 获得最大进度失败

#define MV_CODEREADER_E_UPG_CHECKT_PACKET_FAILED            0x80020465  ///< 文件验证失败
#define MV_CODEREADER_E_UPG_FPGA_PROGRAM_FAILED             0x80020466  ///< FPGA程序升级失败
#define MV_CODEREADER_E_UPG_WATCHDOG_FAILED                 0x80020467  ///< 看门狗升级失败
#define MV_CODEREADER_E_UPG_CAMERA_AND_BARE_FAILED          0x80020468  ///< 裸相机升级失败
#define MV_CODEREADER_E_UPG_RETAIN_CONFIG_FAILED            0x80020469  ///< 保留配置文件失败
#define MV_CODEREADER_E_UPG_FPGA_DRIVER_FAILED              0x8002046A  ///< FPGA驱动升级失败
#define MV_CODEREADER_E_UPG_SPI_DRIVER_FAILED               0x8002046B  ///< SPI驱动升级失败
#define MV_CODEREADER_E_UPG_REBOOT_SYSTEM_FAILED            0x8002046C  ///< 重新启动失败
#define MV_CODEREADER_E_UPG_UPSELF_FAILED                   0x8002046D  ///< 升级服务升级失败
#define MV_CODEREADER_E_UPG_STOP_RELATION_PROGRAM_FAILED    0x8002046E  ///< 停止相关服务失败
#define MV_CODEREADER_E_UPG_DEVCIE_TYPE_INCONSISTENT        0x8002046F  ///< 设备类型不一致
#define MV_CODEREADER_E_UPG_READ_ENCRYPT_INFO_FAILED        0x80020470  ///< 读取加密信息失败
#define MV_CODEREADER_E_UPG_PLAT_TYPE_INCONSISTENT          0x80020471  ///< 设备平台错误
#define MV_CODEREADER_E_UPG_CAMERA_TYPE_INCONSISTENT        0x80020472  ///< 相机型号错误
#define MV_CODEREADER_E_UPG_DEVICE_UPGRADING                0x80020473  ///< 相机正在升级
#define MV_CODEREADER_E_UPG_UNZIP_FAILED                    0x80020474  ///< 升级包解压失败
#define MV_CODEREADER_E_UPG_UNKNOW                          0x800204FF  ///< 升级时未知错误

//网络组件对应的错误码:范围0x80020500-0x800205FF
#define MV_CODEREADER_E_CREAT_SOCKET                        0x80020500  ///< 创建Socket错误
#define MV_CODEREADER_E_BIND_SOCKET                         0x80020501  ///< 绑定错误
#define MV_CODEREADER_E_CONNECT_SOCKET                      0x80020502  ///< 连接错误
#define MV_CODEREADER_E_GET_HOSTNAME                        0x80020503  ///< 获取主机名错误
#define MV_CODEREADER_E_NET_WRITE                           0x80020504  ///< 写入数据错误
#define MV_CODEREADER_E_NET_READ                            0x80020505  ///< 读取数据错误
#define MV_CODEREADER_E_NET_SELECT                          0x80020506  ///< Select错误
#define MV_CODEREADER_E_NET_TIMEOUT                         0x80020507  ///< 超时
#define MV_CODEREADER_E_NET_ACCEPT                          0x80020508  ///< 接收错误
#define MV_CODEREADER_E_NET_UNKNOW                          0x800205FF  ///< 网络未知错误

#endif //_MVCODEREADER_ERROR_DEFINE_H_
