/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TBASE_MNODE_NORMAL_TABLE_H
#define TBASE_MNODE_NORMAL_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "mnode.h"

int32_t mgmtInitNormalTables();
void    mgmtCleanUpNormalTables();
void *  mgmtGetNormalTable(char *tableId);

void *  mgmtCreateNormalTable(SCMCreateTableMsg *pCreate, SVgObj *pVgroup, int32_t sid);
void *  mgmtBuildCreateNormalTableMsg(SNormalTableObj *pTable);

int32_t mgmtDropNormalTable(SQueuedMsg *newMsg, SNormalTableObj *pTable);
int32_t mgmtAddNormalTableColumn(SNormalTableObj *pTable, SSchema schema[], int32_t ncols);
int32_t mgmtDropNormalTableColumnByName(SNormalTableObj *pTable, char *colName);

int32_t mgmtGetNormalTableMeta(SDbObj *pDb, SNormalTableObj *pTable, STableMetaMsg *pMeta, bool usePublicIp);

void mgmtDropAllNormalTables(SDbObj *pDropDb);

#ifdef __cplusplus
}
#endif

#endif