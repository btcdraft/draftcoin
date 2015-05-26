#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/DraftCoin.ico

convert ../../src/qt/res/icons/DraftCoin-16.png ../../src/qt/res/icons/DraftCoin-32.png ../../src/qt/res/icons/DraftCoin-48.png ${ICON_DST}
