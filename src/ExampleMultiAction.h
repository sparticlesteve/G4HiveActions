#ifndef G4HIVEACTIONS__EXAMPLEMULTIACTION_H
#define G4HIVEACTIONS__EXAMPLEMULTIACTION_H

// Local includes
#include "G4HiveActions/IPreTrackingAction.h"
#include "G4HiveActions/IEndEventAction.h"

namespace g4hive
{

  /// @class ExampleMultiAction
  /// @brief Example action for both pre-tracking and end-event
  ///
  class ExampleMultiAction : public IPreTrackingAction,
                             public IEndEventAction
  {

    public:

      /// Constructor
      ExampleMultiAction();

      /// Method called before tracking a particle
      void preTracking(const G4Track* track) override final;

      /// Method called after simulating a G4 event
      void endOfEvent(const G4Event* event) override final;

    }; // class ExampleMultiAction

} // namespace g4hive

#endif
