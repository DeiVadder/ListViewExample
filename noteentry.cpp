#include "noteentry.h"

NoteEntry::NoteEntry(const QString &name, int age, bool dead, QObject *parent)
    : QObject(parent) , m_name(name), m_age(age), m_dead(dead)
{

}

void NoteEntry::setName(const QString &name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

void NoteEntry::setAge(int age)
{
    if (m_age == age)
        return;

    m_age = age;
    emit ageChanged(m_age);
}

void NoteEntry::setDead(bool dead)
{
    if (m_dead == dead)
        return;

    m_dead = dead;
    emit deadChanged(m_dead);
}
