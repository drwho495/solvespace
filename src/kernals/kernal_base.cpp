#include "kernal_base.h"
// #include "platform/gui.h"

namespace SolveSpace {

KernalShape Kernal::createExtrusion(KernalShape *surface,
                                    KernalShape *wires,
                                    Vector tbot,
                                    Vector ttop,
                                    RgbaColor color) const
{
    // Platform::FatalError("Extrusion is not implemented with this kernal!");
};

KernalType Kernal::getType() const {
    return kernalType;
};

KernalType KernalShape::getKernalType() const {
    return kernalType;
};

}; // namespace solvespace