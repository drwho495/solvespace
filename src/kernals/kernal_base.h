//-----------------------------------------------------------------------------
// The base abstraction for the kernals used to generate models in a way that
// is selectable by the user.
//
// Copyright 2025-2025 drwho495.
//-----------------------------------------------------------------------------


#include <vector>
#include "srf/surface.h"
#include "kernal_types.h"
#include <iostream>
// #include "platform/gui.h"
// #include "platform/platform.h"

namespace SolveSpace {

    class KernalShape {
        public:
            virtual ~KernalShape() { };
            KernalType getKernalType() const;
            virtual void clear() { };
            // this will be the standard wire type for the program,
            // which means opencascade will need to convert it to 
            // create extrusions.
            virtual void addWire(SBezierLoop *wire) { }
            virtual void addSet(SBezierLoopSet *wireSet) { }
            // virtual ShapeType getType();
        private:
            KernalType kernalType;
            // ShapeType shapeType;
    };

    // this is the class file that all kernals extend, 
    // it contains methods to create all the operations needed for designing parts.
    class Kernal {
        public:
            virtual ~Kernal() { };

            // some of these variable names aren't readable yet, i'm not sure what they mean in the
            // original code, so i copies them
            // maybe tbot == toBottomVector ?
            // maybe ttop == toTopVector ?
            virtual KernalShape createExtrusion(KernalShape *surface,
                                                KernalShape *wires,
                                                Vector tbot,
                                                Vector ttop,
                                                RgbaColor color) const;
            virtual KernalType getType() const;
            virtual KernalShape* makeShape() const {  };
        private:
            KernalType kernalType;
    };
};