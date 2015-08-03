// Local includes
#include "ExampleMultiAction.h"

// Geant4 includes
#include "G4Track.hh"
#include "G4Event.hh"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  ExampleMultiAction::ExampleMultiAction(const Config& conf)
    : m_conf(conf)
  {}

  //---------------------------------------------------------------------------
  // Pre-tracking
  //---------------------------------------------------------------------------
  void ExampleMultiAction::preTracking(const G4Track* track)
  {
    auto energy = track->GetTotalEnergy();
    if( m_conf.checkTrack &&
        energy > m_conf.minE ) {
      track->GetPosition();
    }
  }

  //---------------------------------------------------------------------------
  // End of event
  //---------------------------------------------------------------------------
  void ExampleMultiAction::endOfEvent(const G4Event* event)
  {
    // Do something with the event...
    event->Print();
  }

} // namespace g4hive
