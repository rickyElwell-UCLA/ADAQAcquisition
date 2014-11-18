/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//                           Copyright (C) 2012-2015                           //
//                 Zachary Seth Hartwig : All rights reserved                  //
//                                                                             //
//      The ADAQAcquisition source code is licensed under the GNU GPL v3.0.    //
//      You have the right to modify and/or redistribute this source code      //      
//      under the terms specified in the license, which may be found online    //
//      at http://www.gnu.org/licenses or at $ADAQACQUISITION/License.txt.     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
// name: ADAQAcquisition.cc
// date: 17 Oct 14
// auth: Zach Hartwig
// mail: hartwig@psfc.mit.edu
//
// desc:
//
/////////////////////////////////////////////////////////////////////////////////


// ROOT 
#include <TApplication.h>

// C++ 
#include <iostream>
#include <string>
using namespace std;

// ADAQ 
#include "AAAcquisitionManager.hh"
#include "AAVMEManager.hh"
#include "AAGraphics.hh"
#include "AAInterface.hh"


int main(int argc, char **argv)
{
  // Run ROOT in standalone mode
  TApplication *TheApplication = new TApplication("ADAQAcquisition", &argc, argv);

  // Create the various singleton manager classes. 

  AAVMEManager *TheVMEManager = new AAVMEManager;

  AAAcquisitionManager *TheACQManager = new AAAcquisitionManager;

  AAGraphics *TheGraphicsManager = new AAGraphics;
  
  // Create the graphical user interface
  AAInterface *TheInterface = new AAInterface;
  
  // Run the standalone application
  TheApplication->Run();
    
  // Garbage collection ..
  delete TheInterface;
  delete TheGraphicsManager;
  delete TheACQManager;
  delete TheVMEManager;
  delete TheApplication;

  return 42;
}
