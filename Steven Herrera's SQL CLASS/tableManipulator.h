#ifndef table_H_
#define table_H_

#include "list.h"
#include "C:\Users\Steven_Dev\Desktop\CS_Stuff\stringTokenizer\StringTokenizer\STokenizer.h"

void mark_cells(int _table[][MAX_COLUMNS_ST],int sRows, int eRows, int sCol, int eCol, int value);
void mark_cells(int _table[][MAX_COLUMNS_ST], int sRows, int eRows, string var, int value);
void mark_cells(int _table[][21], int sRows, int eRows, int sCol, int eCol, int value);
void mark_cells(int _table[][21], int Row, int Col, int value);

#endif // !table_H_
