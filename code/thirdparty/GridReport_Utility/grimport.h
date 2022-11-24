#pragma once

#import ".\gregn.tlb" no_namespace named_guids
#import ".\grdes.tlb" no_namespace named_guids
//也可以丛安装目录的DLL文件中引入类型定义
//#import "C:\Grid++Report 6\gregn6.dll" no_namespace named_guids
//#import "C:\Grid++Report 6\grdes6.dll" no_namespace named_guids

//GridppReport event dispid
const int DISPID_INITIALIZE				= 01;
const int DISPID_FETCHRECORD			= 02;
const int DISPID_BEFOREPOSTRECORD		= 03;
const int DISPID_BEFORESORT				= 04;

const int DISPID_FIELDGETDIAPLYTEXT		= 20;
const int DISPID_TEXTBOXGETDIAPLYTEXT	= 22;
const int DISPID_SECTIONFORMAT			= 23;
const int DISPID_CONTROLCUSTOMDRAW 	    = 24;
const int DISPID_CHARTREQUESTDATA 	    = 25;

const int DISPID_PROCESSBEGIN			= 30;
const int DISPID_PROCESSEND				= 31;
const int DISPID_GROUPBEGIN				= 32;
const int DISPID_GROUPEND				= 33;
const int DISPID_PROCESSRECORD			= 34;
const int DISPID_PAGEPROCESSRECORD		= 35;
const int DISPID_PAGESTART				= 36;
const int DISPID_PAGEEND				= 37;
const int DISPID_GENERATEPAGESBEGIN		= 38;
const int DISPID_GENERATEPAGESEND		= 39;

const int DISPID_PRINTBEGIN				= 40;
const int DISPID_PRINTEND				= 41;
const int DISPID_PRINTPAGE				= 42;
const int DISPID_PRINTABORTED			= 43;

const int DISPID_EXPORTBEGIN			= 50;
const int DISPID_EXPORTEND				= 51;

const int DISPID_SHOWPREVIEWWND			= 60;

const int DISPID_HYPERLINKCLICK			= 65;

//DisplayViewer event dispid
const int DISPID_CONTROLCLICK			= 1;
const int DISPID_CONTROLDBLCLICK		= 2;
const int DISPID_SECTIONCLICK			= 3;
const int DISPID_SECTIONDBLCLICK		= 4;
const int DISPID_CONTENTCELLCLICK		= 5;
const int DISPID_CONTENTCELLDBLCLICK	= 6;
const int DISPID_TITLECELLCLICK			= 7;
const int DISPID_TITLECELLDBLCLICK		= 8;
const int DISPID_COLUMNLAYOUTCHANGE		= 9;
const int DISPID_SELECTIONCELLCHANGE	= 10;
const int DISPID_CHARTCLICKSERIES		= 11;
const int DISPID_CHARTDBLCLICKSERIES	= 12;
const int DISPID_CHARTCLICKLEGEND		= 13;
const int DISPID_CHARTDBLCLICKLEGEND	= 14;

//PrinterViewer event dispid
const int DISPID_CURPAGECHANGE			= 21;
const int DISPID_STATUSCHANGE			= 22;
const int DISPID_RULERCLICK				= 23;
const int DISPID_RULERDBLCLICK			= 24;
const int DISPID_PAGECLICK				= 27;
const int DISPID_PAGEDBLCLICK			= 28;
const int DISPID_CLOSEBUTTONCLICK		= 29;
const int DISPID_CUSTOMBUTTONCLICK      = 30;
