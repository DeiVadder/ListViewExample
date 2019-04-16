#ifndef NOTEENTRY_H
#define NOTEENTRY_H

#include <QObject>

class NoteEntry : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(bool dead READ dead WRITE setDead NOTIFY deadChanged)
public:
    explicit NoteEntry(const QString &name, int age, bool dead, QObject *parent = nullptr);

    inline const QString &name() const { return m_name; }
    inline int age() const { return m_age; }
    inline bool dead() const { return m_dead; }

signals:

    void nameChanged(const QString &name);
    void ageChanged(int age);
    void deadChanged(bool dead);

public slots:

    void setName(const QString &name);
    void setAge(int age);
    void setDead(bool dead);

private:
    QString m_name;
    int m_age;
    bool m_dead;
};

#endif // NOTEENTRY_H
