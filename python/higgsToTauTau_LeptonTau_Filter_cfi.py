import FWCore.ParameterSet.Config as cms

higgsToTauTauLeptonTauFilter = cms.EDFilter("HiggsToTauTauLeptonTauSkim",
    # Collection to be accessed
    DebugHiggsToTauTauLeptonTauSkim = cms.bool(False),
    HLTResultsCollection = cms.InputTag("TriggerResults::HLT"),
    HLTEventCollection = cms.InputTag("hltTriggerSummaryAOD"),
    HLTFilterCollections = cms.vstring('hltSingleMuIsoL3IsoFiltered15',
	                               'hltSingleMuNoIsoL3PreFiltered11',
                                       'hltL1IsoSingleElectronTrackIsolFilter'),
    minDRFromLepton = cms.double(0.5),
    jetEtaMin = cms.double(-2.6),
    jetEtaMax = cms.double(2.6),
    minNumberOfJets = cms.int32(1),
    jetEtMin = cms.double(20.0),
    JetTagCollection = cms.InputTag("iterativeCone5CaloJets")
)


