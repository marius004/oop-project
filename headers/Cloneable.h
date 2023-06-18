#ifndef OOP_CLONEABLE_H
#define OOP_CLONEABLE_H

#include <memory>

template<typename T>
class Cloneable {
public:
    virtual std::shared_ptr<T> clone() const = 0;
};

#endif //OOP_CLONEABLE_H
