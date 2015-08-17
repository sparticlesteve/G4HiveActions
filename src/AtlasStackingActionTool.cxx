#include "CxxUtils/make_unique.h"
#include "AtlasStackingActionTool.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  AtlasStackingActionTool::
  AtlasStackingActionTool(const std::string& type, const std::string& name,
                          const IInterface* parent)
    : ActionToolBase<AtlasStackingAction>(type, name, parent)
  {
    declareProperty("KillAllNeutrinos", m_config.killAllNeutrinos,
                    "Toggle killing of all neutrinos");
    declareProperty("PhotonEnergyCut", m_config.photonEnergyCut,
                    "Energy threshold for tracking photons");
  }

  //---------------------------------------------------------------------------
  // Create the action on request
  //---------------------------------------------------------------------------
  std::unique_ptr<AtlasStackingAction>
  AtlasStackingActionTool::makeAction()
  {
    // Configure it here also
    auto action = CxxUtils::make_unique<AtlasStackingAction>(m_config);
    return std::move(action);
  }

}
