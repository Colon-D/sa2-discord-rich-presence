#include "sa2_discord_rich_presence/clipboard.h"
#include "sa2_discord_rich_presence/modding.h"

std::string read_clipboard() {
	std::string clipboard{};
	// copy clipboard to string
	if ((IsClipboardFormatAvailable(CF_TEXT) != 0)) {
		if ((OpenClipboard(nullptr) != 0)) {
			if (
				const char* const clipboard_ptr{
					reinterpret_cast<const char*>(GetClipboardData(CF_TEXT))
				};
				clipboard_ptr != nullptr
			) {
				clipboard = clipboard_ptr;
			}
			CloseClipboard();
		}
	}
	return clipboard;
}
