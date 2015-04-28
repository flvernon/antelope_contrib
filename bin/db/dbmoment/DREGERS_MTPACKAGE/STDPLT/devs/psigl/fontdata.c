/* These arrays contain width info for a 1 unit sized font. The numbers
 * are obtained using PostScript's stringwidth operator.
 */

#include "const.h"
#include "types.h"

EXPORT float CourierWidth = 0.6;	/* Font 0 (fixed width font) */

EXPORT float TimesRomanWidth[256] = {  /* Font 1 */
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.332999,0.407999,0.499999,0.499999,0.832998,0.777997,0.332999,
  0.332999,0.332999,0.499999,0.563998,0.249998,0.332999,0.249998,0.277998,
  0.499999,0.499999,0.499999,0.499999,0.499999,0.499999,0.499999,0.499999,
  0.499999,0.499999,0.277998,0.277998,0.563998,0.563998,0.563998,0.443998,
  0.920999,0.721999,0.666998,0.666998,0.721999,0.610997,0.556,0.721999,
  0.721999,0.332999,0.388997,0.721999,0.610997,0.888999,0.721999,0.721999,
  0.556,0.721999,0.666998,0.556,0.610997,0.721999,0.721999,0.943997,
  0.721999,0.721999,0.610997,0.332999,0.277998,0.332999,0.468999,0.499999,
  0.332999,0.443998,0.499999,0.443998,0.499999,0.443998,0.332999,0.499999,
  0.499999,0.277998,0.277998,0.499999,0.277998,0.777997,0.499999,0.499999,
  0.499999,0.499999,0.332999,0.388997,0.277998,0.499999,0.499999,0.721999,
  0.499999,0.499999,0.443998,0.48,0.199999,0.48,0.541,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.332999,0.499999,0.499999,0.167,0.499999,0.499999,0.499999,0.499999,
  0.18,0.443998,0.499999,0.332999,0.332999,0.556,0.556,0.249998,0.499999,
  0.499999,0.499999,0.249998,0.249998,0.452999,0.349999,0.332999,0.443998,
  0.443998,0.499999,0.999998,0.999998,0.249998,0.443998,0.249998,0.332999,
  0.332999,0.332999,0.332999,0.332999,0.332999,0.332999,0.332999,0.249998,
  0.332999,0.332999,0.249998,0.332999,0.332999,0.332999,0.999998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.888999,
  0.249998,0.275999,0.249998,0.249998,0.249998,0.249998,0.610997,0.721999,
  0.888999,0.309998,0.249998,0.249998,0.249998,0.249998,0.249998,0.666998,
  0.249998,0.249998,0.249998,0.277998,0.249998,0.249998,0.277998,0.499999,
  0.721999,0.499999,0.249998,0.249998,0.249998,0.249998};


EXPORT float TimesItalicWidth[256] = { /* Font 2 */
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.332999,0.42,0.499999,0.499999,0.832998,0.777997,0.332999,0.332999,
  0.332999,0.499999,0.675,0.249998,0.332999,0.249998,0.277998,0.499999,0.499999,
  0.499999,0.499999,0.499999,0.499999,0.499999,0.499999,0.499999,0.499999,
  0.332999,0.332999,0.675,0.675,0.675,0.499999,0.919999,0.610997,0.610997,
  0.666998,0.721999,0.610997,0.610997,0.721999,0.721999,0.332999,0.443998,
  0.666998,0.556,0.832998,0.666998,0.721999,0.610997,0.721999,0.610997,
  0.499999,0.556,0.721999,0.610997,0.832998,0.610997,0.556,0.556,0.388997,
  0.277998,0.388997,0.422,0.499999,0.332999,0.499999,0.499999,0.443998,
  0.499999,0.443998,0.277998,0.499999,0.499999,0.277998,0.277998,0.443998,
  0.277998,0.721999,0.499999,0.499999,0.499999,0.499999,0.388997,0.388997,
  0.277998,0.499999,0.443998,0.666998,0.443998,0.443998,0.388997,0.399998,
  0.274999,0.399998,0.541,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.388997,0.499999,
  0.499999,0.167,0.499999,0.499999,0.499999,0.499999,0.213999,0.556,
  0.499999,0.332999,0.332999,0.499999,0.499999,0.249998,0.499999,0.499999,
  0.499999,0.249998,0.249998,0.522997,0.349999,0.332999,0.556,0.556,
  0.499999,0.888999,0.999998,0.249998,0.499999,0.249998,0.332999,0.332999,
  0.332999,0.332999,0.332999,0.332999,0.332999,0.332999,0.249998,0.332999,
  0.332999,0.249998,0.332999,0.332999,0.332999,0.888999,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.888999,0.249998,
  0.275999,0.249998,0.249998,0.249998,0.249998,0.556,0.721999,0.943997,
  0.309998,0.249998,0.249998,0.249998,0.249998,0.249998,0.666998,0.249998,
  0.249998,0.249998,0.277998,0.249998,0.249998,0.277998,0.499999,0.666998,
  0.499999,0.249998,0.249998,0.249998,0.249998};


EXPORT float TimesBoldWidth[256] = {  /* Font 3 */
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.332999,0.555,0.499999,0.499999,0.999998,0.832998,0.332999,
  0.332999,0.332999,0.499999,0.57,0.249998,0.332999,0.249998,0.277998,
  0.499999,0.499999,0.499999,0.499999,0.499999,0.499999,0.499999,0.499999,
  0.499999,0.499999,0.332999,0.332999,0.57,0.57,0.57,0.499999,0.93,
  0.721999,0.666998,0.721999,0.721999,0.666998,0.610997,0.777997,0.777997,
  0.388997,0.499999,0.777997,0.666998,0.943997,0.721999,0.777997,0.610997,
  0.777997,0.721999,0.556,0.666998,0.721999,0.721999,0.999998,0.721999,
  0.721999,0.666998,0.332999,0.277998,0.332999,0.580997,0.499999,
  0.332999,0.499999,0.556,0.443998,0.556,0.443998,0.332999,0.499999,
  0.556,0.277998,0.332999,0.556,0.277998,0.832998,0.556,0.499999,0.556,
  0.556,0.443998,0.388997,0.332999,0.556,0.499999,0.721999,0.499999,
  0.499999,0.443998,0.393999,0.219998,0.393999,0.519998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.332999,0.499999,0.499999,0.167,0.499999,0.499999,0.499999,0.499999,
  0.277998,0.499999,0.499999,0.332999,0.332999,0.556,0.556,0.249998,0.499999,
  0.499999,0.499999,0.249998,0.249998,0.54,0.349999,0.332999,0.499999,
  0.499999,0.499999,0.999998,0.999998,0.249998,0.499999,0.249998,
  0.332999,0.332999,0.332999,0.332999,0.332999,0.332999,0.332999,0.332999,
  0.249998,0.332999,0.332999,0.249998,0.332999,0.332999,0.332999,0.999998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.249998,0.999998,0.249998,0.3,0.249998,0.249998,0.249998,0.249998,
  0.666998,0.777997,0.999998,0.33,0.249998,0.249998,0.249998,0.249998,0.249998,
  0.721999,0.249998,0.249998,0.249998,0.277998,0.249998,0.249998,0.277998,0.499999,
  0.721999,0.556,0.249998,0.249998,0.249998,0.249998};


/* Distance from baseline to top of character, obtained with a ruler. */
EXPORT float BaseLineDepth[4] = {0.58, 0.66, 0.66, 0.66};