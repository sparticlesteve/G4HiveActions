#include "CxxUtils/make_unique.h"
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
  std::unique_ptr<ExampleMultiAction> ExampleMultiActionTool::makeAction()
  {
    // Configure it here also
    auto action = CxxUtils::make_unique<ExampleMultiAction>();
    return std::move(action);
  }

} // namespace g4hive
