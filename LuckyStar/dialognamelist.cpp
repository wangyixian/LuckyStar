#include "dialognamelist.h"
#include "ui_dialognamelist.h"

#include <common/constants.h>

DialogNameList::DialogNameList(QWidget *parent, int projectID) :
    QDialog(parent),
    ui(new Ui::DialogNameList)
{
    ui->setupUi(this);

    this->projectID = projectID;

    this->userDtos = this->userDao.selectAll(this->projectID);

    this->ui->tableUsers->setColumnCount(4);
    this->ui->tableUsers->setRowCount(this->userDtos.size());

    //Set the table's headers
    QStringList headers;
    headers.append(Constants::USER_NO);
    headers.append(Constants::USER_NAME);
    headers.append(Constants::USER_DEPART);
    headers.append(Constants::USER_PHONE);
    this->ui->tableUsers->setHorizontalHeaderLabels(headers);

    int i = 0;
    foreach (UserDto userDto, this->userDtos) {
        this->ui->tableUsers->setItem(i, 0, new QTableWidgetItem(userDto.getUserNo()));
        this->ui->tableUsers->setItem(i, 1, new QTableWidgetItem(userDto.getUserName()));
        this->ui->tableUsers->setItem(i, 2, new QTableWidgetItem(userDto.getUserDepart()));
        this->ui->tableUsers->setItem(i, 3, new QTableWidgetItem(userDto.getUserPhone()));
        i++;
    }

    //Select one row
    this->ui->tableUsers->selectRow(0);

    //Select row
    this->ui->tableUsers->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tableUsers->setFocus(Qt::MouseFocusReason);

}

DialogNameList::~DialogNameList()
{
    delete ui;
}
