#include "GaudiKernel/DeclareFactoryEntries.h"

#include "../UserActionSvc.h"
#include "../AtlasStackingActionTool.h"
#include "../ExampleSteppingActionTool.h"
#include "../ExampleMultiActionTool.h"


DECLARE_SERVICE_FACTORY( g4hive::UserActionSvc )
DECLARE_TOOL_FACTORY( g4hive::AtlasStackingActionTool )
DECLARE_TOOL_FACTORY( g4hive::ExampleSteppingActionTool )
DECLARE_TOOL_FACTORY( g4hive::ExampleMultiActionTool )

DECLARE_FACTORY_ENTRIES( G4HiveActions ) {
  DECLARE_SERVICE( g4hive::UserActionSvc )
  DECLARE_TOOL( g4hive::AtlasStackingActionTool )
  DECLARE_TOOL( g4hive::ExampleSteppingActionTool )
  DECLARE_TOOL( g4hive::ExampleMultiActionTool )
}
