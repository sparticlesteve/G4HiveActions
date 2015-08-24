#include "CxxUtils/make_unique.h"
#include "G4TrackCounterTool.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  G4TrackCounterTool::
  G4TrackCounterTool(const std::string& type, const std::string& name,
                     const IInterface* parent)
    : ActionToolBase<G4TrackCounter>(type, name, parent)
  {}

  //---------------------------------------------------------------------------
  // Initialize - temporarily here for debugging
  //---------------------------------------------------------------------------
  StatusCode G4TrackCounterTool::initialize()
  {
    ATH_MSG_INFO("initialize");
    return StatusCode::SUCCESS;
  }

  //---------------------------------------------------------------------------
  // Create the action on request
  //---------------------------------------------------------------------------
  std::unique_ptr<G4TrackCounter>
  G4TrackCounterTool::makeAction()
  {
    ATH_MSG_DEBUG("makeAction");
    auto action = CxxUtils::make_unique<G4TrackCounter>();
    return std::move(action);
  }

  //---------------------------------------------------------------------------
  // Query interface
  //---------------------------------------------------------------------------
  StatusCode G4TrackCounterTool::queryInterface(const InterfaceID& riid,
                                                void** ppvIf)
  {
    if(riid == IBeginEventActionTool::interfaceID()) {
      *ppvIf = (IBeginEventActionTool*) this;
      addRef();
      return StatusCode::SUCCESS;
    }
    if(riid == IEndRunActionTool::interfaceID()) {
      *ppvIf = (IEndRunActionTool*) this;
      addRef();
      return StatusCode::SUCCESS;
    }
    if(riid == IPreTrackingActionTool::interfaceID()) {
      *ppvIf = (IPreTrackingActionTool*) this;
      addRef();
      return StatusCode::SUCCESS;
    }
    return ActionToolBase<G4TrackCounter>::queryInterface(riid, ppvIf);
  }

}
