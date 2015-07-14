// Local includes
#include "G4AtlasEventAction.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  G4AtlasEventAction::G4AtlasEventAction()
  {
  }

  //---------------------------------------------------------------------------
  // Begin-event action
  //---------------------------------------------------------------------------
  G4AtlasEventAction::BeginOfEventAtion(const G4Event* event)
  {
    // Loop over my pre-actions and apply each one in turn
    for(IBeginEventAction* action : m_beginEventActions){
      action->beginOfEvent(event);
    }
  }

  //---------------------------------------------------------------------------
  // Post-tracking action
  //---------------------------------------------------------------------------
  void G4AtlasTrackingAction::PostUserTrackingAction(const G4Event* event)
  {
    // Loop over my post-actions and apply each one in turn
    for(IEndEventAction* action : m_endEventActions){
      action->endOfEvent(event);
    }
  }

  //---------------------------------------------------------------------------
  // Add one action to the list
  //---------------------------------------------------------------------------
  void G4AtlasTrackingAction::addBeginEventAction(IBeginEventAction* action)
  {
    m_beginEventActions.push_back(action);
  }

  //---------------------------------------------------------------------------
  // Add one action to the list
  //---------------------------------------------------------------------------
  void G4AtlasTrackingAction::addEndEventAction(IEndEventAction* action)
  {
    m_endEventActions.push_back(action);
  }

} // namespace g4hive
