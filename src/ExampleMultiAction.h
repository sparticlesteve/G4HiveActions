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

      /// @class Config
      /// @brief Configuration parameters for ExampleMultiAction
      ///
      struct Config
      {
        /// An energy threshold
        double minE;
        /// A boolean flag
        bool checkTrack;
      };

      /// Constructor
      ExampleMultiAction(const Config& conf);

      /// Method called before tracking a particle
      void preTracking(const G4Track* track) override final;

      /// Method called after simulating a G4 event
      void endOfEvent(const G4Event* event) override final;

    private:

      Config m_conf;

  }; // class ExampleMultiAction

} // namespace g4hive

#endif
