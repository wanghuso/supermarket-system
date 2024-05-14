#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>
#include"page_login.h"
#include"itemform.h"
#include<QListWidgetItem>
#include<QMessageBox>
#include<QFile>
#include<QKeyEvent>
#include"sql_manage.h"
#include"addempdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void data();  //生成随机员工信息并插入到数据库中


private slots:


    void on_deleteButton_clicked();  //删除员工信息

    void on_updateButton_clicked();  //更新员工信息

    void on_addButton_clicked();  //添加员工信息

    void on_exitButton_clicked(); //退出界面

    void showList();  //从数据库中获取员工信息并在表格中显示出来

    void on_searchButton_clicked();  //查询员工信息

    void on_showButton_clicked();  //重新加载并显示员工信息

private:
    Ui::MainWindow *ui;
    sql_manage *ptrEmp;
    Page_Login login;
    AddempDialog addDlg;

};
#endif // MAINWINDOW_H
