#include "GaudiKernel/DeclareFactoryEntries.h"

#include "../UserActionSvc.h"

// DECLARE_TOOL_FACTORY( SctSDTool )
DECLARE_SERVICE_FACTORY( UserActionSvc )

DECLARE_FACTORY_ENTRIES( G4HiveActions ) {
  //DECLARE_TOOL( SctSDTool )
  DECLARE_SERVICE( UserActionSvc )
}
