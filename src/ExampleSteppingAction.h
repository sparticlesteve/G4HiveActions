#ifndef G4HIVEACTIONS_EXAMPLESTEPPINGACTION_H
#define G4HIVEACTIONS_EXAMPLESTEPPINGACTION_H

// Local includes
#include "G4HiveActions/ISteppingAction.h"

namespace g4hive
{

  /// @class ExampleSteppingAction
  /// @brief Example stepping action plugin
  ///
  class ExampleSteppingAction : public ISteppingAction
  {

    public:

      /// Constructor
      ExampleSteppingAction();

      /// Process one step
      void processStep(const G4Step* step) override final;

  }; // class ExampleSteppingAction

} // namespace g4hive

#endif
