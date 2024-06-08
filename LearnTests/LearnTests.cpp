#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <mysql.h>

using namespace std;

// Интерфейс для соединения с базой данных
class IDBConnection {
public:
    virtual ~IDBConnection() = default;
    virtual void open(MYSQL& mysql_) = 0;
    virtual void execQuery(MYSQL& mysql_, const char* localhost, const char* login, const char* password, const char* dbname) = 0;
    virtual void close(MYSQL& mysql_) = 0;
};

// Реализация интерфейса
class DBConnection : public IDBConnection {
public:
    void open(MYSQL& mysql_) override { mysql_init(&mysql_); }
    void execQuery(MYSQL& mysql_, const char* localhost, const char* login, const char* password, const char* dbname) override {
        if (!mysql_real_connect(&mysql_, localhost, login, password, dbname, 0, NULL, 0)) {
            cout << "Error: can't connect to database " << endl;
        }
    }
    void close(MYSQL& mysql_) override { mysql_close(&mysql_); }
};

// Функция для тестирования
void algForTest(IDBConnection* connection) {
    MYSQL mysql;
    connection->open(mysql);
    connection->execQuery(mysql, "localhost", "root", "1234567890", "testdb");
    connection->close(mysql);
}

// Мок класс
class MockDBConnection : public IDBConnection {
public:
    MOCK_METHOD(void, open, (MYSQL& mysql_), (override));
    MOCK_METHOD(void, execQuery, (MYSQL& mysql_, const char* localhost, const char* login, const char* password, const char* dbname), (override));
    MOCK_METHOD(void, close, (MYSQL& mysql_), (override));
};

// Тест
TEST(TestConnection, test_1) {
    MockDBConnection mockConn;

    EXPECT_CALL(mockConn, open(testing::_)).Times(1);
    EXPECT_CALL(mockConn, execQuery(testing::_, "localhost", "root", "1234567890", "testdb")).Times(1);
    EXPECT_CALL(mockConn, close(testing::_)).Times(1);

    algForTest(&mockConn);
}

int main(int argc, char* argv[]) {
    // Инициализация и запуск тестов
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
