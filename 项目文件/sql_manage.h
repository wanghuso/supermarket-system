#ifndef SQL_MANAGE_H
#define SQL_MANAGE_H

#include <QObject>
#include<QSqlDatabase>

//首先分别创建一个员工信息和用户信息的结构体，方便后续的操作。
struct EmployInfo
{
    int id;
    QString name;
    int age;
    QString address;
    QString position;
    int salary;
};

struct UserInfo
{
   QString uername;
   QString password;
   QString auth;
};

class sql_manage : public QObject
{
    Q_OBJECT
public:

    static sql_manage *ptrsql;
    static sql_manage *getinstance()
    {
        if(ptrsql==nullptr)
        {
            ptrsql= new sql_manage;
        }
        return ptrsql;
    }

    void init();   //初始化数据库连接
    explicit sql_manage(QObject *parent = nullptr);

    //针对员工信息
    quint32 getCount();    //获取员工表中的员工数量
    QList<EmployInfo> getPage(quint32 page,quint32 uiCnt);  //分页查询员工信息并返回指定页码的员工信息列表
    bool add(EmployInfo);   //添加新的员工信息
    bool delEmp(int id);    //根据员工的id删除员工的信息
    void clearStuTable();   //清空员工表的数据
    void Update(EmployInfo);  //更新员工表中的数据
    QList<EmployInfo> select(QString name);   //根据员工姓名查询员工信息

    //针对用户账号
    QList<UserInfo> getAllUser();  //获取所有用户的信息列表
    bool isExit(QString strUser);  //检查用户的信息是否存在
    bool UpdateUser(UserInfo info);  //更新用户信息
    bool AddUser(UserInfo info);  //增加用户信息
    bool delUser(QString strUserName);  //删除用户信息
    UserInfo selUser(QString name);  //查询用户信息

private:
    //创建数据库
    QSqlDatabase db;

};

#endif // SQL_MANAGE_H
