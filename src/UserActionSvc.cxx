// Local includes
#include "UserActionSvc.h"

namespace g4hive
{

  //---------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  UserActionSvc::UserActionSvc(const std::string& name,
                               ISvcLocator* pSvcLocator)
    : AthService(name, pSvcLocator)
  {
  }

  //---------------------------------------------------------------------------
  // Initialize the service
  //---------------------------------------------------------------------------
  StatusCode UserActionSvc::initialize()
  {
    return StatusCode::SUCCESS;
  }

  //---------------------------------------------------------------------------
  // Initialize the user actions for the current thread
  //---------------------------------------------------------------------------
  StatusCode UserActionSvc::initializeActions()
  {
    return StatusCode::SUCCESS;
  }

  //---------------------------------------------------------------------------
  // Gaudi interface query
  //---------------------------------------------------------------------------
  StatusCode UserActionSvc::queryInterface(const InterfaceID& riid,
                                           void** ppvInterface)
  {
    if(IUserActionSvc::interfaceID().versionMatch(riid)){
      *ppvInterface = static_cast<IUserActionSvc*>(this);
    }
    else{
      // Interface is not directly available; try out a base class
      return AthService::queryInterface(riid, ppvInterface);
    }
    addRef();
    return StatusCode::SUCCESS;
  }

} // namespace g4hive
