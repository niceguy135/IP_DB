#include "sqlservice.h"
#include "configuratedatabase.h"

SqlService::SqlService()
{
    this->database_name_ = DATABASE_NAME;
    this->user_name_ = USER_NAME;
    this->password_ = PASSWORD;
    this->host_name_ = HOST_NAME;
}

void SqlService::databaseConnect()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(host_name_); // IP-адрес
    db.setPort(5432); // порт по умолчанию для PostgreSQL
    db.setDatabaseName(database_name_); // имя БД
    db.setUserName(user_name_); // имя пользователя БД
    db.setPassword(password_); // пароль
    db.setConnectOptions("client_encoding=UTF8");

    if (!db.open()) {
        qDebug() << "Failed to connect to database.";
        qDebug() << "Error: ";
        qDebug() << db.lastError().text();
    } else {
        qDebug() << "Connected to database succesfully!";
    }
}

QSqlQuery SqlService::runQuery(QString content)
{
    QSqlQuery query;
    query.exec(content);

    // Обработка

    if (query.lastError().isValid()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
    } else {
        // Запрос выполнен успешно
    }
    return query;
}
