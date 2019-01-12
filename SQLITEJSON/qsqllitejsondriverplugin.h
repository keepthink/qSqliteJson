#ifndef QSQLLITEJSONDRIVERPLUGIN_H
#define QSQLLITEJSONDRIVERPLUGIN_H

#include <QSqlDriverPlugin>


class QSqlliteJsonDriverPlugin : public QSqlDriverPlugin
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QSqlDriverFactoryInterface" FILE "SQLITEJSON.json")
#endif // QT_VERSION >= 0x050000

public:
    QSqlliteJsonDriverPlugin(QObject* parent = 0);
    QSqlDriver* create(const QString&) Q_DECL_OVERRIDE;
};

#endif // QSQLLITEJSONDRIVERPLUGIN_H
