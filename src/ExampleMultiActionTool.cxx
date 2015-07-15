// Local includes
#include "ExampleMultiActionTool.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  ExampleMultiActionTool::
  ExampleMultiActionTool(const std::string& type, const std::string& name,
                         const IInterface* parent)
    : ActionToolBase<ExampleMultiAction>(type, name, parent)
  {
  }

  //---------------------------------------------------------------------------
  // Create the action on demand
  //---------------------------------------------------------------------------
  ExampleMultiAction* ExampleMultiActionTool::makeAction()
  {
    // Configure it here also
    return new ExampleMultiAction();
  }

} // namespace g4hive
