#include <stdio.h>
#include <stdint.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <lvgl.h>
#include <zephyr/device.h>
#include "../gui/ui.h"
#include "../include/main.h"

LOG_MODULE_REGISTER(app);

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void)
{
	gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	gpio_pin_set_dt(&led, false);

	const struct device *display_dev;
	display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(display_dev)) {
		return 0;
	}
	ui_init();
	ui_Screen1_screen_init();
	lv_task_handler();
	display_blanking_off(display_dev);

    while (1)
    {
		k_msleep(lv_task_handler());
    }
    return 0;
}