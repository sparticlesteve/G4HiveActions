// Local includes
#include "G4AtlasTrackingAction.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  G4AtlasTrackingAction::G4AtlasTrackingAction()
  {
  }

  //---------------------------------------------------------------------------
  // Pre-tracking action
  //---------------------------------------------------------------------------
  void G4AtlasTrackingAction::PreUserTrackingAction(const G4Track* trk)
  {
    // Loop over my pre-actions and apply each one in turn
    for(IPreTrackingAction* action : m_preTrackActions){
      action->preTracking(trk);
    }
  }

  //---------------------------------------------------------------------------
  // Post-tracking action
  //---------------------------------------------------------------------------
  void G4AtlasTrackingAction::PostUserTrackingAction(const G4Track* trk)
  {
    // Loop over my post-actions and apply each one in turn
    for(IPostTrackingAction* action : m_postTrackActions){
      action->postTracking(trk);
    }
  }

  //---------------------------------------------------------------------------
  // Add one action to the list
  //---------------------------------------------------------------------------
  void G4AtlasTrackingAction::addPreTrackAction(IPreTrackingAction* action)
  {
    m_preTrackActions.push_back(action);
  }

  //---------------------------------------------------------------------------
  // Add one action to the list
  //---------------------------------------------------------------------------
  void G4AtlasTrackingAction::addPostTrackAction(IPostTrackingAction* action)
  {
    m_postTrackActions.push_back(action);
  }

} // namespace g4hive
