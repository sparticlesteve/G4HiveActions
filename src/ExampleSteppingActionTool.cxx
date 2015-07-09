// Local includes
#include "ExampleSteppingActionTool.h"
#include "ExampleSteppingAction.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  ExampleSteppingActionTool::ExampleSteppingActionTool(const std::string& name)
    : SteppingActionBaseTool(name)
  {
  }

  //---------------------------------------------------------------------------
  // Create the action on request
  //---------------------------------------------------------------------------
  ISteppingAction* ExampleSteppingActionTool::makeSteppingAction()
  {
    return new ExampleSteppingAction();
  }

}
