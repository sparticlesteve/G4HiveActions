#ifndef G4HIVEACTIONS_IENDEVENTACTIONTOOL_H
#define G4HIVEACTIONS_IENDEVENTACTIONTOOL_H

// Framework includes
#include "GaudiKernel/IAlgTool.h"

// Local includes
#include "G4HiveActions/IEndEventAction.h"

namespace g4hive
{

  /// @class IEndEventActionTool
  /// @brief Abstract interface for tools that manage ATLAS end-of-event
  /// custom actions.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class IEndEventActionTool : virtual public IAlgTool
  {

    public:

      /// Return the action for current thread.
      virtual IEndEventAction* getAction() = 0

      /// Interface declaration
      static const InterfaceID& interfaceID() {
        static const InterfaceID iid_IEndEventTool("g4hive::IEndEventActionTool", 1, 0);
        return iid_IEndEventTool;
      }

  }; // class IEndEventActionTool

} // namespace g4hive

#endif
