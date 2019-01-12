#include "qsqllitejsondriverplugin.h"
#include "qsql_sqlitejson_p.h"


QSqlliteJsonDriverPlugin::QSqlliteJsonDriverPlugin(QObject* parent) :
    QSqlDriverPlugin(parent)
{
}

QSqlDriver* QSqlliteJsonDriverPlugin::create(const QString& name)
{
    if (name == QLatin1String("QSQLITEJSON"))
    {
        QSQLiteJsonDriver* driver = new QSQLiteJsonDriver();
        return driver;
    }

    return 0;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(SQLITEJSON, QSqlliteJsonDriverPlugin)
#endif // QT_VERSION < 0x050000
