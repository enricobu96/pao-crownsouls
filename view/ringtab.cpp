#include "ringtab.h"

RingTab::RingTab(QWidget* parent) : QTableView(parent) {
    setSelectionBehavior(QAbstractItemView::SelectRows);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
