// Local includes
#include "ExampleSteppingActionTool.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  ExampleSteppingActionTool::
  ExampleSteppingActionTool(const std::string& type, const std::string& name,
                            const IInterface* parent)
    : ActionToolBase<ExampleSteppingAction>(type, name, parent)
  {
  }

  //---------------------------------------------------------------------------
  // Create the action on request
  //---------------------------------------------------------------------------
  ExampleSteppingAction* ExampleSteppingActionTool::makeAction()
  {
    return new ExampleSteppingAction();
  }

}
