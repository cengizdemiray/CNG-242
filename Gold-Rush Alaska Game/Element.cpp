/* Engin Eray Kabalak- 2526424, Cengiz Demiray – 2526960
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */


#include "Element.h"

Element::Element() {
    size=0;
    representingChar='?';
    effect=0;

}

char Element::getRepresentingChar() const {
    return representingChar;
}

Element::Element(int size, char representingChar, int effect) : size(size), representingChar(representingChar),
                                                                effect(effect) {}
