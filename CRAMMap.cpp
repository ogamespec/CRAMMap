// CRAMMap.cpp: A simple utility for generating PPUs Color RAM (palette) memory cells layout.

#include "pch.h"

const size_t originOffset = 10ULL;
const size_t cellSize = 10ULL;
const size_t GapBetweenCells = 1ULL;

void EmitCellText(std::string& text, size_t bit_num, size_t row, size_t col, size_t pp[8])
{
    char cell[0x400]{};
    const char* CellColor = "";
    char CellLabel[0x20]{};

    size_t PAL4 = (row >> 2) & 1;

    size_t cram_addr = (col << 2) | (row & 3) | (PAL4 << 4);

    if (row == 0)
    {
        // Rows 0 and 4 are combined into one row.
        // (Addresses $3F10/$3F14/$3F18/$3F1C are mirrors of $3F00/$3F04/$3F08/$3F0C)

        CellColor = "Tomato";

        size_t cram_addr2 = (col << 2) | (1 << 4);
        sprintf_s(CellLabel, sizeof(CellLabel), "%02X/%02X-%zd\nrow: 0/4\ncol: %zd", (uint8_t)cram_addr, (uint8_t)cram_addr2, bit_num, col);
    }
    else
    {
        CellColor = PAL4 ? "GreenYellow" : "Teal";
        sprintf_s(CellLabel, sizeof(CellLabel), "%02X-%zd\nrow: %zd\ncol: %zd", (uint8_t)cram_addr, bit_num, row, col);
    }

    sprintf_s(cell, sizeof(cell), cellText, CellLabel, CellColor,
        pp[0], pp[1],
        pp[2], pp[3],
        pp[4], pp[5],
        pp[6], pp[7]);

    text += cell;
}

void GenRowLane(std::string& text, size_t& y, size_t row)
{
    size_t pp[8]{};

    for (size_t n = 0; n < 4 * 6; n++)
    {
        size_t col = n;

        size_t x = (cellSize + GapBetweenCells) * n + originOffset;
        size_t cell_y = y;

        pp[0] = x;
        pp[1] = cell_y;
        pp[2] = x + cellSize;
        pp[3] = cell_y;
        pp[4] = x + cellSize;
        pp[5] = cell_y + cellSize;
        pp[6] = x;
        pp[7] = cell_y + cellSize;

        EmitCellText(text, n / 4, row, col & 3, pp);
    }

    y += cellSize + GapBetweenCells;
}

void GenMap()
{
    // Order of rows
    int rows_order[] = { 0, 6, 2, 5, 1, 7, 3 };

    std::string text = "";

    text += headerText;

    size_t y = originOffset;

    for (size_t p = 0; p < _countof(rows_order); p++)
    {
        GenRowLane(text, y, rows_order[p]);
    }

    text += footerText;

    FILE* f;
    fopen_s(&f, "crammap.xml", "wt");
    if (f)
    {
        fwrite(text.c_str(), 1, text.size(), f);
        fclose(f);
    }
}

int main()
{
    GenMap();
}
