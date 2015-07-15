#ifndef G4HIVEACTIONS_IPOSTTRACKINGACTIONTOOL_H
#define G4HIVEACTIONS_IPOSTTRACKINGACTIONTOOL_H

// Framework includes
#include "GaudiKernel/IAlgTool.h"

// Local includes
#include "G4HiveActions/IPostTrackingAction.h"

namespace g4hive
{

  /// @class IPostTrackingActionTool
  /// @brief Abstract interface for tools that manage ATLAS post-tracking
  /// actions.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class IPostTrackingActionTool : virtual public IAlgTool
  {

    public:

      /// Return the action for current thread.
      virtual IPostTrackingAction* getPostTrackingAction() = 0;

      /// Interface declaration
      static const InterfaceID& interfaceID() {
        static const InterfaceID iid_IPostTrkTool("g4hive::IPostTrackingActionTool", 1, 0);
        return iid_IPostTrkTool;
      }

  }; // class IPostTrackingActionTool

} // namespace g4hive

#endif
