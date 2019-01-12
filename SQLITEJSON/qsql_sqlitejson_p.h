#pragma once

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtSql/qsqldriver.h>

struct sqlite3;

#ifdef QT_PLUGIN
#define Q_EXPORT_SQLDRIVER_SQLITE
#else
#define Q_EXPORT_SQLDRIVER_SQLITE Q_SQL_EXPORT
#endif

QT_BEGIN_NAMESPACE

class QSqlResult;
class QSQLiteJsonDriverPrivate;

class Q_EXPORT_SQLDRIVER_SQLITE QSQLiteJsonDriver : public QSqlDriver
{
    Q_DECLARE_PRIVATE(QSQLiteJsonDriver)
    Q_OBJECT
    friend class QSQLiteJsonResultPrivate;
public:
    explicit QSQLiteJsonDriver(QObject* parent = 0);
    explicit QSQLiteJsonDriver(sqlite3* connection, QObject* parent = 0);
    ~QSQLiteJsonDriver();
    bool hasFeature(DriverFeature f) const Q_DECL_OVERRIDE;
    bool open(const QString& db,
              const QString& user,
              const QString& password,
              const QString& host,
              int port,
              const QString& connOpts) Q_DECL_OVERRIDE;
    void close() Q_DECL_OVERRIDE;
    QSqlResult* createResult() const Q_DECL_OVERRIDE;
    bool beginTransaction() Q_DECL_OVERRIDE;
    bool commitTransaction() Q_DECL_OVERRIDE;
    bool rollbackTransaction() Q_DECL_OVERRIDE;
    QStringList tables(QSql::TableType) const Q_DECL_OVERRIDE;

    QSqlRecord record(const QString& tablename) const Q_DECL_OVERRIDE;
    QSqlIndex primaryIndex(const QString& table) const Q_DECL_OVERRIDE;
    QVariant handle() const Q_DECL_OVERRIDE;
    QString escapeIdentifier(const QString& identifier, IdentifierType) const Q_DECL_OVERRIDE;

    bool subscribeToNotification(const QString& name) Q_DECL_OVERRIDE;
    bool unsubscribeFromNotification(const QString& name) Q_DECL_OVERRIDE;
    QStringList subscribedToNotifications() const Q_DECL_OVERRIDE;
private Q_SLOTS:
    void handleNotification(const QString& tableName, qint64 rowid);
};

QT_END_NAMESPACE