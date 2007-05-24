/* \class HiggsAnalysisSkimming
 *
 * Consult header file for description
 *
 * author:  Dominique Fortin - UC Riverside
 *
 */


// system include files
#include <HiggsAnalysis/Skimming/interface/HiggsAnalysisSkimming.h>

#include <DataFormats/Common/interface/Handle.h>
#include <FWCore/Framework/interface/ESHandle.h>

#include <HiggsAnalysis/Skimming/interface/HiggsAnalysisSkimType.h>
#include <HiggsAnalysis/Skimming/interface/HiggsAnalysisSkimmingPluginFactory.h>

#include <FWCore/Utilities/interface/Exception.h>
#include <FWCore/MessageLogger/interface/MessageLogger.h> 

// C++
#include <memory>
#include <vector>

using namespace std;
using namespace edm;


// Constructor
HiggsAnalysisSkimming::HiggsAnalysisSkimming(const edm::ParameterSet& pset) {

  // Local Debug flag
  debug = pset.getParameter<bool>("DebugHiggsAnalysisSkimming");

  // Find out which skim filter to use:
  int chosenSkim = pset.getParameter<int>("skim_type");
    
  // Find appropriate ParameterSets this skim type
  std::vector<edm::ParameterSet> allSkimPSets = pset.getParameter<std::vector<edm::ParameterSet> >("skim_psets");

  // Find name of class for this skim  
  std::string skimName = allSkimPSets[chosenSkim].getParameter<std::string>("skim_name");

  // Store all parameters for this skim
  std::vector<edm::ParameterSet> skimPSets = allSkimPSets[chosenSkim].getParameter<std::vector<edm::ParameterSet> >("skim_psets");
        
  skimFilter = HiggsAnalysisSkimmingPluginFactory::get()->create(skimName, skimPSets[0]);

}


// Destructor
HiggsAnalysisSkimming::~HiggsAnalysisSkimming() {}


// Filter
bool HiggsAnalysisSkimming::filter(edm::Event& event, const edm::EventSetup& setup) {

  bool keepEvent = false;

  keepEvent = skimFilter->skim( event, setup );

  return keepEvent;
}


