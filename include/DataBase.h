#ifndef DATABASE_H
#define DATABASE_H

class DataBase{
public:

    virtual void load() = 0;

    virtual void update() = 0;
};

#endif