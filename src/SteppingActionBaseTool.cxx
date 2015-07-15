// Local includes
#include "G4HiveActions/SteppingActionBaseTool.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  SteppingActionBaseTool::SteppingActionBaseTool(const std::string& type,
                                                 const std::string& name,
                                                 const IInterface* parent)
    : AthAlgTool(type, name, parent)
  {
  }

  //---------------------------------------------------------------------------
  // Return the action for the current thread
  //---------------------------------------------------------------------------
  ISteppingAction* SteppingActionBaseTool::getSteppingAction()
  {
    ISteppingAction* action = m_action.get();
    if(!action){
      action = makeSteppingAction();
      m_action.set(action);
    }
    return action;
  }

} // namespace g4hive
