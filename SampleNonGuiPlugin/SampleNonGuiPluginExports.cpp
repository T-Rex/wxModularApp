#include "stdwx.h"
#include <wxNonGuiPluginBase.h>
#include "SampleNonGuiPlugin.h"

PLUGIN_EXPORTED_API wxNonGuiPluginBase * CreatePlugin()
{
	return new SampleNonGuiPlugin;
}

PLUGIN_EXPORTED_API void DeletePlugin(wxNonGuiPluginBase * plugin)
{
	wxDELETE(plugin);
}
