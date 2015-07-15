# G4HiveActions
A package for testing out G4Hive user action design.

In this prototype we make use of thread-local storage for multi-threading.
Thread-local Geant4 actions own lists of custom ATLAS action "plugins" which
get called in turn. Tools are used to create the action plugins on demand
during the initialization of each thread. A top-level service manages things.

# Class structure
Just highlighting some of the important ones:

* [ISteppingAction](G4HiveActions/ISteppingAction.h) - Interface for custom
  stepping action plugins. Note that this is _not_ a framework component
  interface.
* [ISteppingActionTool](G4HiveActions/ISteppingActionTool.h) - Interface for a
  tool which creates and manages an ISteppingAction. Corresponding interfaces
  also exist for the other action types. Not all are implemented here.
* [SteppingActionBaseTool](G4HiveActions/SteppingActionBaseTool.h) - Helper
  base class for stepping action tools which manages the thread-local storage
  of its actions. Note that helper classes like this can be written for
  single-type actions, but for multi-type actions this approach would quickly
  get too complicated.
* [ExampleSteppingAction](src/ExampleSteppingAction.h) - A stepping action
  plugin. Doesn't actually do anything.
* [ExampleSteppingActionTool](src/ExampleSteppingActionTool.h) - A stepping
  action tool which creates the ExampleSteppingAction. Realistically this
  would also have some configuration options which are used when creating the
  action plugin.
* [ExampleMultiAction](src/ExampleMultiAction.h) - An example action plugin
  that implemments two types of actions: pre-tracking and end-of-event.
* [ExampleMultiActionTool](src/ExampleMultiActionTool.h) - Tool which manages
  the ExampleMultiAction. Note that no helper base class is used here, so the
  boiler plate code for managing/retrieving the action is explicit.
* [G4AtlasSteppingAction](src/G4AtlasSteppingAction.h) - A Geant4 stepping
  action class which owns a list of ISteppingActions and calls them when
  invoked by Geant4. This class is thread-locally owned by the UserActionSvc.
  Examples for a few other actions are also included.
* [UserActionSvc](src/UserActionSvc.h) - A top-level service which manages
  the Geant4 actions and the custom action tools. Will trigger the creation
  and assignment of the action plugins on demand for current thread.
* [ThreadActionHolder](G4HiveActions/ThreadActionHolder.h) - A thread-local
  container for the actions implemented as a tbb concurrent unordered map
  keyed by thread ID.
  * Will be made into a simple pointer wrapper for non-hive builds.
