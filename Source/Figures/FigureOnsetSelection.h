#pragma once

#include "NumberProtocolController.h"

#include <DurationsProducer.hpp>
#include <juce_gui_basics/juce_gui_basics.h>

class FigureOnsetSelection : public juce::Component {
  public:
    FigureOnsetSelection(aleatoric::DurationsProducer &durationsProducer);
    ~FigureOnsetSelection();

    void paint(juce::Graphics &) override;
    void resized() override;

  private:
    // TODO: check that the duration protocol is not set in such a way that it
    // will have a collectionSize < 2 as this will cause the number protocol to
    // throw error (or at least I think it will). Need to check this in
    // Aleatoric. I don't think it is accounted for in the Aleatoric tests.
    // Aleatoric should be throwing an error if this behaviour is not allowed
    // and then Montage can catch the error and handle the UI messaging
    // appropriately. So in short, check if this is disallowed behaviour in
    // Aleatoric. If it is, change Aleatoric to handle it with errors, then
    // catch them in Montage and handle UI messaging. If it isn't disallowed
    // behaviour in Aleatoric, then don't worry about it here!
    aleatoric::DurationsProducer &producer;
    std::unique_ptr<NumberProtocolController> numberProtocolController;

    juce::Label onsetSelectionHeading;
    juce::Label numberProtocolSelectorLabel;
    juce::ComboBox numberProtocolSelector;

    void configureNumberProtocolSelector();
    void numberProtocolChanged();
    void updateNumberProtocolParams(
        aleatoric::NumberProtocolParameters::Protocols newParams);
    void setInitialActiveNumberProtocol();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FigureOnsetSelection)
};
