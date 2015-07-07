#include "GaudiKernel/DeclareFactoryEntries.h"

#include "../UserActionSvc.h"

DECLARE_SERVICE_FACTORY( g4hive::UserActionSvc )
// DECLARE_TOOL_FACTORY( g4hive::SteppingActionTool )

DECLARE_FACTORY_ENTRIES( G4HiveActions ) {
  DECLARE_SERVICE( g4hive::UserActionSvc )
  //DECLARE_TOOL( g4hive::SteppingActionTool )
}
