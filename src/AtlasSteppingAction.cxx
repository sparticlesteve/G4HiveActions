// Local includes
#include "AtlasSteppingAction.h"
#include "G4HiveActions/ISteppingAction.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  AtlasSteppingAction::AtlasSteppingAction()
  {
  }

  //---------------------------------------------------------------------------
  // Process one step
  //---------------------------------------------------------------------------
  void AtlasSteppingAction::UserSteppingAction(const G4Step* step)
  {
    // Loop over my actions and apply each one in turn
    for(ISteppingAction* action : m_actions){
      action->processStep(step);
    }
  }

} // namespace g4hive
