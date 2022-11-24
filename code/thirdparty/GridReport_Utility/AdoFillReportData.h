#pragma once

#include "GridppReportEventImpl.h"

BOOL FillRecordsetFromAdoQuery(IGRRecordset *pRecordset, const CString &ConnectionString, const CString &QuerySQL);
BOOL FetchRecordFromAdoQuery(IGridppReport *pReport, const CString &ConnectionString, const CString &QuerySQL);

