#ifndef G4HIVEACTIONS_ISTEPPINGACTION_H
#define G4HIVEACTIONS_ISTEPPINGACTION_H

// Forward declarations
class G4Step;

namespace g4hive
{

  /// Simple interface class for an ATLAS stepping action
  class ISteppingAction
  {
    public:
      /// Virtual destructor
      virtual ~ISteppingAction(){};
      /// Method called at every step for processing
      virtual void processStep(const G4Step*) = 0;
  };

} // namespace g4hive

#endif
