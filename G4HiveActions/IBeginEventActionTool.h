#ifndef G4HIVEACTIONS_IBEGINEVENTACTIONTOOL_H
#define G4HIVEACTIONS_IBEGINEVENTACTIONTOOL_H

// Framework includes
#include "GaudiKernel/IAlgTool.h"

// Local includes
#include "G4HiveActions/IBeginEventAction.h"

namespace g4hive
{

  /// @class IBeginEventActionTool
  /// @brief Abstract interface for tools that manage ATLAS begin-of-event
  /// custom actions.
  ///
  /// @author Steve Farrell <Steven.Farrell@cern.ch>
  ///
  class IBeginEventActionTool : virtual public IAlgTool
  {

    public:

      /// Return the action for current thread.
      virtual IBeginEventAction* getBeginEventAction() = 0;

      /// Interface declaration
      static const InterfaceID& interfaceID() {
        static const InterfaceID iid_IBeginEventTool("g4hive::IBeginEventActionTool", 1, 0);
        return iid_IBeginEventTool;
      }

  }; // class IBeginEventActionTool

} // namespace g4hive

#endif
