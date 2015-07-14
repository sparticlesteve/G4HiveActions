#ifndef G4HIVEACTIONS_EXAMPLESTEPPINGACTIONTOOL_H
#define G4HIVEACTIONS_EXAMPLESTEPPINGACTIONTOOL_H

// STL includes
#include <string>

// Framework includes
#include "AthenaBaseComps/AthAlgTool.h"

// Local includes
#include "G4HiveActions/SteppingActionBaseTool.h"
#include "G4HiveActions/ISteppingActionTool.h"

namespace g4hive
{

  /// @class ExampleSteppingActionTool
  /// @brief Tool which manages the ExampleSteppingAction
  ///
  class ExampleSteppingActionTool : public SteppingActionBaseTool,
                                    public virtual ISteppingActionTool
  {

    public:

      /// Standard constructor
      ExampleSteppingActionTool(const std::string& type, const std::string& name,
                                const IInterface* parent);

    protected:

      /// Create an action for this thread
      ISteppingAction* makeSteppingAction() override final;

  }; // class ExampleSteppingActionTool

} // namespace g4hive

#endif
