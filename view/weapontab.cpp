#include "weapontab.h"

WeaponTab::WeaponTab(QWidget* parent) : QTableView(parent) {
    //interfacciarsi col model
    setSelectionBehavior(QAbstractItemView::SelectRows);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
