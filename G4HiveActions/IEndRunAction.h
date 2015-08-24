#ifndef G4HIVEACTIONS_IENDRUNACTION_H
#define G4HIVEACTIONS_IENDRUNACTION_H

// Forward declarations
class G4Run;

namespace g4hive
{

  /// Simple interface for an ATLAS end-of-run action
  class IEndRunAction
  {
    public:
      /// Virtual destructor
      virtual ~IEndRunAction(){};
      /// Method called after simulating a G4 run
      virtual void endOfRun(const G4Run*) = 0;
  };

} // namespace g4hive

#endif
