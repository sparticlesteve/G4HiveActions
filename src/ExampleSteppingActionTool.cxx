#include "CxxUtils/make_unique.h"
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
  std::unique_ptr<ExampleSteppingAction>
  ExampleSteppingActionTool::makeAction()
  {
    // Configure it here also
    auto action = CxxUtils::make_unique<ExampleSteppingAction>();
    return std::move(action);
  }

}
