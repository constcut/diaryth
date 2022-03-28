#ifndef SQLBASE_HPP
#define SQLBASE_HPP

#include <QObject>
#include <QVariantList>
#include <QSqlQuery>

namespace diaryth {


    class SQLBase : public QObject
    {
        Q_OBJECT

    public:
        SQLBase();

        QSqlQuery executeRequest(const QString& requestBody);

        //TODO const& for QString

        Q_INVOKABLE void addAudioRecord(QString date, QString time, int localId,
                            QString name, quint64 durationMs);

        Q_INVOKABLE void editAudioRecord(QString date, int localId,
                             QString tags, QString description);

        Q_INVOKABLE void removeAudioRecord(QString date, int localId);

        Q_INVOKABLE int recordsMaxLocalId(QString date);
        Q_INVOKABLE int getTotalRecords();

        Q_INVOKABLE QStringList findSingleRecord(QString date, int localId);
        Q_INVOKABLE QVariantList findRecords(QString date);

        Q_INVOKABLE QVariantList findByNameMask(QString nameMask);
        Q_INVOKABLE QVariantList findByTagMask(QString tagMask);

        Q_INVOKABLE QVariantList findByNameMaskAndDate(QString date, QString nameMask);
        Q_INVOKABLE QVariantList findByTagMaskAndDate(QString date, QString tagMask);


    private:

        QSqlError initBase();
        void createTablesIfNeeded();

        QVariantList fillRecordsSearchResults(QSqlQuery& query);

        bool logIfError(QSqlQuery& query, const QString& request);

        const int audioFieldsCount = 7; //Later use walkaround with query.last() and query.at() + 1

    };

}

#endif // SQLBASE_HPP
