//-----------------------------------------------------------------------------
// The re-implementation of the solvespace nurbs kernal for use with older models
//
// Copyright 2025-2025 drwho495.
//-----------------------------------------------------------------------------

#include <vector>
#include "srf/surface.h"
#include "kernal_base.h"

namespace SolveSpace {

    class SolvespaceShape : public KernalShape {
        public:
            void clear() override;
            std::vector<SShell*> shells;
            std::vector<SEdge*>  edges;
            std::vector<SBezierLoop*> wires;

            SBezierLoopSet* getBezierSet();
            void addWire(SBezierLoop *wire) override;
            void addSet(SBezierLoopSet *wireSet) override;
        private:
            KernalType kernalType = KernalType::SOLVESPACE_NURBS;
    };

    // this is the class files for the legacy nurbs kernal that solvespace has
    // been using for 17+ years.
    class SolvespaceKernal : public Kernal {
        public:
            virtual ~SolvespaceKernal() { };

            // some of these variable names aren't readable yet, i'm not sure what they mean in the
            // original code, so i copies them
            // maybe tbot == toBottomVector ?
            // maybe ttop == toTopVector ?
            KernalShape createExtrusion(KernalShape *surface,
                                        KernalShape *wires,
                                        Vector tbot,
                                        Vector ttop,
                                        RgbaColor color) const override;
            KernalShape* makeShape() const override;
        private:
            KernalType kernalType = KernalType::SOLVESPACE_NURBS;
    };
};