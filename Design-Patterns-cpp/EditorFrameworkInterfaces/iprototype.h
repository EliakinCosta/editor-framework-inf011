#ifndef IPROTOTYPE_H
#define IPROTOTYPE_H


class IPrototype
{
public:
    IPrototype();
    virtual IPrototype* clone() const;
};

#endif // IPROTOTYPE_H
