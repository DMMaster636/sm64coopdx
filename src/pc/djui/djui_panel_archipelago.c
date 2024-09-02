/*#include "djui.h"
#include "djui_panel.h"
#include "djui_panel_menu.h"
#include "djui_unicode.h"
#include "djui_panel_main.h"
#include "djui_panel_pause.h"
#include "djui_panel_options.h"
#include "pc/network/network_player.h"
#include "pc/platform.h"
#include "game/level_update.h"
#include "game/area.h"

static struct DjuiSelectionbox* sPalettePresetSelection = NULL;

static struct DjuiInputbox* sHexColorTextBox = NULL;
static struct DjuiSlider *sSliderR = NULL;
static struct DjuiSlider *sSliderG = NULL;
static struct DjuiSlider *sSliderB = NULL;
static struct DjuiInputbox* sPalettePresetNameTextBox = NULL;

static struct DjuiRect *sColorRect = NULL;

struct DjuiText* gDjuiPaletteToggle = NULL;

void djui_panel_archipelago_create(struct DjuiBase* caller);

static bool djui_panel_archipelago_name_valid(char* buffer) {
    if (buffer[0] == '\0') { return false; }
    char* c = buffer;
    while (*c != '\0') {
        if (*c == ' ') { return false; }
        if (!djui_unicode_valid_char(c)) { return false; }
        c = djui_unicode_next_char(c);
    }
    return true;
}

static void djui_panel_archipelago_name_text_change(struct DjuiBase* caller) {
    struct DjuiInputbox* inputbox1 = (struct DjuiInputbox*)caller;
    if (djui_panel_archipelago_name_valid(inputbox1->buffer)) {
        djui_inputbox_set_text_color(inputbox1, 0, 0, 0, 255);
    } else {
        djui_inputbox_set_text_color(inputbox1, 255, 0, 0, 255);
    }
}

static void djui_panel_archipelago_name_on_focus_end(struct DjuiBase* caller) {
    struct DjuiInputbox* inputbox1 = (struct DjuiInputbox*)caller;
    if (!djui_panel_archipelago_name_valid(inputbox1->buffer)) {
        djui_inputbox_set_text(inputbox1, DLANG(PLAYER, PLAYER));
    }
    snprintf(configPlayerName, MAX_CONFIG_STRING, "%s", inputbox1->buffer);
    djui_inputbox_set_text_color(inputbox1, 0, 0, 0, 255);

    if (gNetworkType != NT_NONE) {
        network_send_archipelago_settings();
    }
    djui_inputbox_on_focus_end(&inputbox1->base);
}

void djui_panel_archipelago_create(struct DjuiBase* caller) {
    struct DjuiThreePanel* panel = djui_panel_menu_create(DLANG(PLAYER, PLAYER_TITLE), true);
    struct DjuiBase* body = djui_three_panel_get_body(panel);
    {
        struct DjuiRect* rect1 = djui_rect_container_create(body, 32);
        {
            struct DjuiText* text1 = djui_text_create(&rect1->base, DLANG(PLAYER, NAME));
            djui_base_set_size_type(&text1->base, DJUI_SVT_RELATIVE, DJUI_SVT_ABSOLUTE);
            djui_base_set_color(&text1->base, 220, 220, 220, 255);
            djui_base_set_size(&text1->base, 0.585f, 64);
            djui_base_set_alignment(&text1->base, DJUI_HALIGN_LEFT, DJUI_VALIGN_TOP);
            djui_text_set_drop_shadow(text1, 64, 64, 64, 100);

            struct DjuiInputbox* inputbox1 = djui_inputbox_create(&rect1->base, MAX_CONFIG_STRING);
            djui_base_set_size_type(&inputbox1->base, DJUI_SVT_RELATIVE, DJUI_SVT_ABSOLUTE);
            djui_base_set_size(&inputbox1->base, 0.45f, 32);
            djui_base_set_alignment(&inputbox1->base, DJUI_HALIGN_RIGHT, DJUI_VALIGN_TOP);
            if (djui_panel_archipelago_name_valid(configPlayerName)) {
                djui_inputbox_set_text(inputbox1, configPlayerName);
            } else {
                djui_inputbox_set_text(inputbox1, DLANG(PLAYER, PLAYER));
            }
            djui_interactable_hook_value_change(&inputbox1->base, djui_panel_archipelago_name_text_change);
            djui_interactable_hook_focus(&inputbox1->base, djui_inputbox_on_focus_begin, NULL, djui_panel_archipelago_name_on_focus_end);
        }

        djui_button_create(body, DLANG(MENU, BACK), DJUI_BUTTON_STYLE_BACK, djui_panel_menu_back);
    }

    struct DjuiPanel* p = djui_panel_add(caller, panel, NULL);
}*/