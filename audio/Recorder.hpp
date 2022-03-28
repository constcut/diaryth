#ifndef RECORDER_H
#define RECORDER_H

#include <memory>

#include <QObject>
#include <QAudioProbe>
#include <QAudioRecorder>


namespace diaryth {


    class Recorder : public QObject
    {
        Q_OBJECT

    public:
        Recorder();

        Q_INVOKABLE void start();
        Q_INVOKABLE void pause();
        Q_INVOKABLE void stop();
        Q_INVOKABLE void cancel();

        Q_INVOKABLE QString lastFilename();

        Q_INVOKABLE QStringList inputDevices();
        Q_INVOKABLE QStringList audioCodecs();
        Q_INVOKABLE QStringList fileContainers();
        Q_INVOKABLE QStringList sampleRates();

        Q_INVOKABLE QString getInputDevice();
        Q_INVOKABLE QString getAudioCodec();
        Q_INVOKABLE QString getFileContainer();
        Q_INVOKABLE int getSampleRate();

        Q_INVOKABLE void setInputDevice(QString device);
        Q_INVOKABLE void setAudioCodec(QString codec);
        Q_INVOKABLE void setFileContainer(QString container);
        Q_INVOKABLE void setSampleRate(QString sampleRate);

    public slots:
        void processBuffer(const QAudioBuffer& buffer);

    signals:
        void timeUpdate(quint64 ms);
        void dbsUpdate(qreal dbs);

    private:

        std::unique_ptr<QAudioProbe> _audioProbe;
        std::unique_ptr<QAudioRecorder> _audioRecorder;

        quint64 _durationMicroSeconds;

        QString _defaultInput;
        QString _defaultCodec;
        QString _defaultContainer;
        int _defaultSampleRate;

    };


}

#endif // RECORDER_H