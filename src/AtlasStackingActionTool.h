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
  class AtlasStackingActionTool : public ActionToolBase<AtlasStackingAction>,
                                  public IStackingActionTool
    //: public extends1< ActionToolBase<AtlasStackingAction>, IStackingActionTool >
  {

    public:

      /// Standard constructor
      AtlasStackingActionTool(const std::string& type, const std::string& name,
                              const IInterface* parent);

      /// Initialize the tool (just for debugging printout)
      virtual StatusCode initialize() override;

      /// Retrieve the stepping action
      virtual IStackingAction* getStackingAction() override final
      { return static_cast<IStackingAction*>( getAction() ); }

      /// Query interface for gaudi
      virtual StatusCode queryInterface(const InterfaceID& riid, void** ppvInterface);

    protected:

      /// Create an action for this thread
      virtual std::unique_ptr<AtlasStackingAction> makeAction() override final;

    private:

      /// Configuration parameters
      AtlasStackingAction::Config m_config;

  }; // class AtlasStackingActionTool

} // namespace g4hive

#endif
