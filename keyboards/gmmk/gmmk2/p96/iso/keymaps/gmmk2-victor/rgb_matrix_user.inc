RGB_MATRIX_EFFECT(layer0)
RGB_MATRIX_EFFECT(layer1)
RGB_MATRIX_EFFECT(layer2)
RGB_MATRIX_EFFECT(layer3)
RGB_MATRIX_EFFECT(layer15)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static void set_color_scaled_reactive(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
    if (index == 61) {
        rgb_matrix_set_color(index, 0, 0, 0);
        return;
    }

    uint8_t val = rgb_matrix_get_val();
    uint16_t out_r = r;
    uint16_t out_g = g;
    uint16_t out_b = b;

    if (val < 128) {
        out_r = (r * val) / 128;
        out_g = (g * val) / 128;
        out_b = (b * val) / 128;
    } else if (val > 128) {
        uint16_t boost_amount = val - 128;
        out_r += (r * boost_amount * 13) / 127;
        out_g += (g * boost_amount * 13) / 127;
        out_b += (b * boost_amount * 13) / 127;
    }

    // Ensure non-indicator keys (which have original Red < 200) NEVER exceed ~60% brightness globally, 
    // leaving room for indicators (like F1 or Caps Lock) to permanently stand out at 100%.
    if (r < 200) {
        if (out_r > 160) out_r = 160;
        if (out_g > 125) out_g = 125;
        if (out_b > 160) out_b = 160;
    }

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
    uint8_t count = g_last_hit_tracker.count;
    uint16_t max_tick = 400; // ~0.5 sec fade
    for (int8_t j = count - 1; j >= 0; j--) {
        if (g_last_hit_tracker.index[j] == index) {
            uint16_t tick = g_last_hit_tracker.tick[j];
            if (tick < max_tick) {
                uint16_t boost = 255 - (tick * 255 / max_tick);
                out_r += (r * boost * 13) / 255;
                out_g += (g * boost * 13) / 255;
                out_b += (b * boost * 13) / 255;
            }
            break;
        }
    }
#endif

    if (out_r > 255) out_r = 255;
    if (out_g > 255) out_g = 255;
    if (out_b > 255) out_b = 255;
    rgb_matrix_set_color(index, out_r, out_g, out_b);
}

static void set_color_all_scaled_reactive(uint8_t r, uint8_t g, uint8_t b, uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        set_color_scaled_reactive(i, r, g, b);
    }
}

static bool layer0(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    set_color_all_scaled_reactive(0x12, 0x0e, 0x00, led_min, led_max);
    set_color_scaled_reactive(101, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(102, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(103, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(104, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(105, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(106, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(107, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(108, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(109, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(110, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(111, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(112, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(113, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(114, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(115, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(116, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(117, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(118, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(119, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(100, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(1,  0xff, 0xcc, 0x00); //F1
    set_color_scaled_reactive(61, 0x00, 0x00, 0x00); //J hardware fix

    return rgb_matrix_check_finished_leds(led_max);
}


static bool layer1(effect_params_t* params) {

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    set_color_all_scaled_reactive(0x12, 0x0e, 0x00, led_min, led_max);
    set_color_scaled_reactive(101, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(102, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(103, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(104, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(105, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(106, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(107, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(108, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(109, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(110, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(111, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(112, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(113, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(114, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(115, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(116, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(117, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(118, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(119, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(100, 0x4d, 0x17, 0x00);        
    set_color_scaled_reactive(2,  0xff, 0xcc, 0x00); //F2
    set_color_scaled_reactive(61, 0x00, 0x00, 0x00); //J hardware fix

    return rgb_matrix_check_finished_leds(led_max);
}

static bool layer2(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    set_color_all_scaled_reactive(0x12, 0x0e, 0x00, led_min, led_max);
    set_color_scaled_reactive(101, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(102, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(103, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(104, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(105, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(106, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(107, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(108, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(109, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(110, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(111, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(112, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(113, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(114, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(115, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(116, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(117, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(118, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(119, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(100, 0x4d, 0x17, 0x00);        
    set_color_scaled_reactive(3,  0xff, 0xcc, 0x00); //F3
    set_color_scaled_reactive(61, 0x00, 0x00, 0x00); //J hardware fix

    return rgb_matrix_check_finished_leds(led_max);
}

static bool layer3(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    set_color_all_scaled_reactive(0x12, 0x0e, 0x00, led_min, led_max);
    set_color_scaled_reactive(101, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(102, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(103, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(104, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(105, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(106, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(107, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(108, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(109, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(110, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(111, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(112, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(113, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(114, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(115, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(116, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(117, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(118, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(119, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(100, 0x4d, 0x17, 0x00);        
    set_color_scaled_reactive(4,  0xff, 0xcc, 0x00); //F4
    set_color_scaled_reactive(61, 0x00, 0x00, 0x00); //J hardware fix

    return rgb_matrix_check_finished_leds(led_max);
}

static bool layer15(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    set_color_all_scaled_reactive(0x12, 0x0e, 0x00, led_min, led_max);
    set_color_scaled_reactive(101, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(102, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(103, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(104, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(105, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(106, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(107, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(108, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(109, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(110, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(111, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(112, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(113, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(114, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(115, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(116, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(117, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(118, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(119, 0x4d, 0x17, 0x00);
    set_color_scaled_reactive(100, 0x4d, 0x17, 0x00);        
    set_color_scaled_reactive(61, 0x00, 0x00, 0x00); //J hardware fix

    return rgb_matrix_check_finished_leds(led_max);
}


#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS