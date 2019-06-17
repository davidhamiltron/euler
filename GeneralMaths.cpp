

#include "GeneralMaths.h"


double PascalsValueAt(double row, double column)
{
    if (column == 0) return 1;

    return ((row + 1 - column) / column) * PascalsValueAt(row, column - 1);
}