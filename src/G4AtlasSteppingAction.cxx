// Local includes
#include "G4AtlasSteppingAction.h"
#include "G4HiveActions/ISteppingAction.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  G4AtlasSteppingAction::G4AtlasSteppingAction()
  {
  }

  //---------------------------------------------------------------------------
  // Process one step
  //---------------------------------------------------------------------------
  void G4AtlasSteppingAction::UserSteppingAction(const G4Step* step)
  {
    // Loop over my actions and apply each one in turn
    for(ISteppingAction* action : m_actions){
      action->processStep(step);
    }
  }

  //---------------------------------------------------------------------------
  // Add one action to the action list
  //---------------------------------------------------------------------------
  void G4AtlasSteppingAction::addAction(ISteppingAction* action)
  {
    m_actions.push_back(action);
  }

} // namespace g4hive
