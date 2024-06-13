/* Engin Eray Kabalak- 2526424, Cengiz Demiray – 2526960
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */

#ifndef ASSIGMENT_ELEMENT_H
#define ASSIGMENT_ELEMENT_H


class Element {
private:
    int size;
    char representingChar;
    int effect;
public:
    Element();
    virtual char getRepresentingChar() const;
    Element(int size, char representingChar, int effect);
};


#endif //ASSIGMENT_ELEMENT_H
