#include "table.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\stringTokenizer\StringTokenizer/STokenizer.h"

void mark_cells(int _table[][MAX_COLUMNS_ST],
 int sRows, int eRows, int sCol, int eCol, int value) {

    for (int i = sRows; i < eRows + 1; i++)
    {
        for (int j = sCol; j < eCol + 1; j++)
        {
            _table[i][j] = value;
        }
    }
}

void mark_cells(int _table[][MAX_COLUMNS_ST], int sRows, int eRows, string var, int value) {
    int num = 0;
    while(num < var.size()) {
        for (int i = sRows; i < eRows + 1; i++) {
            _table[i][var[num]] = value;
        }
        num++;
    }
}

void mark_cells(int _table[][21], int sRows, int eRows, int sCol, int eCol, int value){
    for (int i = sRows; i < eRows ; i++)
    {
        for (int j = sCol; j < eCol ; j++)
        {
            _table[i][j] = value;
        }
    }
}

void mark_cells(int _table[][21], int Row, int Col, int value) {
    _table[Row][Col] = value;
}