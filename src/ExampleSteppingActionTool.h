#ifndef G4HIVEACTIONS_EXAMPLESTEPPINGACTIONTOOL_H
#define G4HIVEACTIONS_EXAMPLESTEPPINGACTIONTOOL_H

// STL includes
#include <string>

// Framework includes
#include "AthenaBaseComps/AthAlgTool.h"

// Local includes
#include "G4HiveActions/ISteppingActionTool.h"
#include "G4HiveActions/ActionToolBase.h"
#include "ExampleSteppingAction.h"

namespace g4hive
{

  typedef ActionToolBase<ExampleSteppingAction> ExampleStepToolBase;

  /// @class ExampleSteppingActionTool
  /// @brief Tool which manages the ExampleSteppingAction
  ///
  class ExampleSteppingActionTool : public virtual ISteppingActionTool,
                                    public AthAlgTool,
                                    public ExampleStepToolBase
  {

    public:

      /// Standard constructor
      ExampleSteppingActionTool(const std::string& type, const std::string& name,
                                const IInterface* parent);

      /// Retrieve the stepping action
      ISteppingAction* getSteppingAction() override final
      { return static_cast<ISteppingAction*>( getAction() ); }

    protected:

      /// Create an action for this thread
      ExampleSteppingAction* makeAction() override final;

  }; // class ExampleSteppingActionTool

} // namespace g4hive

#endif
