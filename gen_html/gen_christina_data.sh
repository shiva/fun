#!/bin/sh


find ~/Desktop/export/cferancik/pen_ink -name "*[0-9].jpg" | xargs python natural_sort.py | xargs python gen_html.py > pen_ink.html
find ~/Desktop/export/cferancik/drawings -name "*[0-9].jpg" | xargs python natural_sort.py | xargs python gen_html.py > drawings.html
find ~/Desktop/export/cferancik/paintings -name "*[0-9].jpg" | xargs python natural_sort.py | xargs python gen_html.py > paintings.html



