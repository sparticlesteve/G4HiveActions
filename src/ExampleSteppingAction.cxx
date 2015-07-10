// Local includes
#include "ExampleSteppingAction.h"

// Geant4 includes
#include "G4Step.hh"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  ExampleSteppingAction::ExampleSteppingAction()
  {}

  //---------------------------------------------------------------------------
  // Process one step
  //---------------------------------------------------------------------------
  void ExampleSteppingAction::processStep(const G4Step* step)
  {
    // Do something here...
    step->GetTrack();
  }

} // namespace g4hive
