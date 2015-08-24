#ifndef G4HIVEACTIONS_IBEGINRUNACTION_H
#define G4HIVEACTIONS_IBEGINRUNACTION_H

// Forward declarations
class G4Run;

namespace g4hive
{

  /// Simple interface for an ATLAS begin-of-run action
  class IBeginRunAction
  {
    public:
      /// Virtual destructor
      virtual ~IBeginRunAction(){};
      /// Method called before simulating a G4 run
      virtual void beginOfRun(const G4Run*) = 0;
  };

} // namespace g4hive

#endif
