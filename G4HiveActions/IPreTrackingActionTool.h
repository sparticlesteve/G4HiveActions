#ifndef G4HIVEACTIONS_IPRETRACKINGACTIONTOOL_H
#define G4HIVEACTIONS_IPRETRACKINGACTIONTOOL_H

// Framework includes
#include "GaudiKernel/IAlgTool.h"

// Local includes
#include "G4HiveActions/IPreTrackingAction.h"

namespace g4hive
{

  /// @class IPreTrackingActionTool
  /// @brief Abstract interface for tools that manage ATLAS pre-tracking
  /// actions.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class IPreTrackingActionTool : virtual public IAlgTool
  {

    public:

      /// Return the action for current thread.
      virtual IPreTrackingAction* getAction() = 0;

      /// Interface declaration
      static const InterfaceID& interfaceID() {
        static const InterfaceID iid_IPreTrkTool("g4hive::IPreTrackingActionTool", 1, 0);
        return iid_IPreTrkTool;
      }

  }; // class IPreTrackingActionTool

} // namespace g4hive

#endif
