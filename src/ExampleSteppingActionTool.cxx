// Local includes
#include "ExampleSteppingActionTool.h"
#include "ExampleSteppingAction.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  ExampleSteppingActionTool::
  ExampleSteppingActionTool(const std::string& type, const std::string& name,
                            const IInterface* parent)
    : SteppingActionBaseTool(type, name, parent)
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
