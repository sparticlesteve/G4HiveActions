#ifndef G4HIVEACTIONS_IPOSTTRACKINGACTION_H
#define G4HIVEACTIONS_IPOSTTRACKINGACTION_H

// Forward declarations
class G4Track;

namespace g4hive
{

  /// Simple interface for an ATLAS post-tracking action
  class IPostTrackingAction
  {
    public:
      /// Virtual destructor
      virtual ~IPostTrackingAction(){};
      /// Method called before tracking a particle
      virtual void postTracking(const G4Track*) = 0;
  };

} // namespace g4hive

#endif
