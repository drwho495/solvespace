#include "kernal_solvespace.h"
#include <iostream>

namespace SolveSpace {

void SolvespaceShape::clear() {
    wires.clear();
    edges.clear();
    shells.clear();
}

void SolvespaceShape::addWire(SBezierLoop *wire) {
    wires.push_back(wire);
}

void SolvespaceShape::addSet(SBezierLoopSet *loopSet) {
    for (SBezierLoop &wire : loopSet->l) {
        wires.push_back(&wire);
    }
}

SBezierLoopSet* SolvespaceShape::getBezierSet() {
    SBezierLoopSet *returnSet;
    
    for (SBezierLoop* loop : wires) {
        returnSet->l.Add(loop);
    }

    return returnSet;
}

KernalShape* SolvespaceKernal::makeShape() const {
    std::cout << "make shape\n";
    return new SolvespaceShape();
}

KernalShape SolvespaceKernal::createExtrusion(KernalShape *surface,
                                              KernalShape *wires,
                                              Vector tbot,
                                              Vector ttop,
                                              RgbaColor color) const
{
    // if (auto surfaceShape = dynamic_cast<SolvespaceShape*>(surface)) {
    //     if (auto wireShape = dynamic_cast<SolvespaceShape*>(wires)) {
    //         if (surfaceShape->shells.size() == 1) {
    //             SShell *extrudeShell = surfaceShape->shells[0];

    //             extrudeShell->MakeFromExtrusionOf(wireShape->getBezierSet(),
    //                                               tbot,
    //                                               ttop,
    //                                               color);
                
    //             surfaceShape->shells.clear();
    //             surfaceShape->shells.push_back(extrudeShell);

    //             return (*surfaceShape);
    //         } else {
    //             std::cout << "not enough/too many shells in surface arg";
    //         }
    //     }
    // } else {
    //     std::cout << "is other shape";
    // }
};

}; // namespace solvespace