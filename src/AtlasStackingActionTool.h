#ifndef G4HIVEACTIONS_ATLASSTACKINGACTIONTOOL_H
#define G4HIVEACTIONS_ATLASSTACKINGACTIONTOOL_H

// STL includes
#include <string>

// Local includes
#include "G4HiveActions/IStackingActionTool.h"
#include "G4HiveActions/ActionToolBase.h"
#include "AtlasStackingAction.h"


namespace g4hive
{

  /// @class AtlasStackingActionTool
  /// @brief Tool which manages the AtlasStackingAction
  ///
  class AtlasStackingActionTool : public IStackingActionTool,
                                  public ActionToolBase<AtlasStackingAction>
  {

    public:

      /// Standard constructor
      AtlasStackingActionTool(const std::string& type, const std::string& name,
                              const IInterface* parent);

      /// Retrieve the stepping action
      virtual IStackingAction* getStackingAction() override final
      { return static_cast<IStackingAction*>( getAction() ); }

    protected:

      /// Create an action for this thread
      virtual std::unique_ptr<AtlasStackingAction> makeAction() override final;

    private:

      /// Configuration parameters
      AtlasStackingAction::Config m_config;

  }; // class AtlasStackingActionTool

} // namespace g4hive

#endif
