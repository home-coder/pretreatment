#include <stdio.h>

int board_display_device_open(void)

{

#if (defined CONFIG_ARCH_SUN8IW5P1)

#else

#if defined(CONFIG_VIDEO_SUNXI_V1) || defined(CONFIG_VIDEO_SUNXI_V2)

#endif

#if defined(CONFIG_VIDEO_SUNXI_V1) || defined(CONFIG_VIDEO_SUNXI_V2)

#endif

#if defined(CONFIG_VIDEO_SUNXI_V1)

#endif

#if !defined(CONFIG_VIDEO_SUNXI_V3)

#if !(defined CONFIG_ARCH_SUN9IW1P1) && !(defined CONFIG_ARCH_SUN8IW8P1)&& !(defined CONFIG_ARCH_SUN8IW7P1) 

#else

#endif

#if !(defined CONFIG_ARCH_SUN9IW1P1) && !(defined CONFIG_ARCH_SUN8IW8P1)&& !(defined CONFIG_ARCH_SUN8IW7P1) 

#else

#endif

#if defined(CONFIG_VIDEO_SUNXI_V1)

#endif // !(defined CONFIG_ARCH_SUN9IW1P1)

#else

#endif // !CONFIG_VIDEO_SUNXI_V3


#endif // CONFIG_ARCH_SUN8IW5P1

	return ret;

}


