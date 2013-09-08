#include "stdwx.h"
#include <wxGuiPluginBase.h>
#include "SampleGuiPlugin2.h"

PLUGIN_EXPORTED_API wxGuiPluginBase * CreatePlugin()
{
	return new SampleGuiPlugin2;
}

PLUGIN_EXPORTED_API void DeletePlugin(wxGuiPluginBase * plugin)
{
	wxDELETE(plugin);
}
