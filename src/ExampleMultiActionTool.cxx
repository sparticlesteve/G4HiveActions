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
    declareProperty("MinE", m_conf.minE, "Track energy threshold");
    declareProperty("CheckTrack", m_conf.checkTrack, "Flag to check track");
  }

  //---------------------------------------------------------------------------
  // Create the action on demand
  //---------------------------------------------------------------------------
  std::unique_ptr<ExampleMultiAction> ExampleMultiActionTool::makeAction()
  {
    // Configure it here also
    auto action = CxxUtils::make_unique<ExampleMultiAction>(m_conf);
    return std::move(action);
  }

  //---------------------------------------------------------------------------
  // Merge results from all threads
  //---------------------------------------------------------------------------
  StatusCode ExampleMultiActionTool::finalize()
  {
    for(auto tidAction : actions())
      ATH_MSG_INFO("Merging action " << tidAction.second);
    return StatusCode::SUCCESS;
  }

} // namespace g4hive
