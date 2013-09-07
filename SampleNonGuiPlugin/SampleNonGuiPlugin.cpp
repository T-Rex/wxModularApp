#include "stdwx.h"
#include "SampleNonGuiPlugin.h"

IMPLEMENT_DYNAMIC_CLASS(SampleNonGuiPlugin, wxObject)

SampleNonGuiPlugin::SampleNonGuiPlugin()
{
}

SampleNonGuiPlugin::~SampleNonGuiPlugin()
{
}

int SampleNonGuiPlugin::Work()
{
	return 10;
}
