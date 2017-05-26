#include "header.h"
#include <limits.h>
#include <stdbool.h>
#include <string.h> //NULL

//function assumes hotspots are sorted by position, smallest to greatest

int selectHotspots(struct s_hotspot **hotspots) {
	struct s_hotspot *last;
	int count = 1;

	last = *hotspots;
	if (last == NULL)
		return (0);
	hotspots++;
	while (*hotspots) {
		//if the hotspot overlap
		if ((*hotspots)->pos - (*hotspots)->radius < last->pos + last->radius) {
			//if the new hotspot reached far right than the old one
			if ((*hotspots)->pos + (*hotspots)->radius < last->pos - last->radius)
				last = *hotspots;
		} else {
			last = *hotspots;
			count++;
		}
		hotspots++;
	}
	return (count);
}
