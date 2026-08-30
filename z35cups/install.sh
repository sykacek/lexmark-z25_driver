#!/usr/bin/bash

sudo cp usr/lib/cups/backend/z35 /usr/lib/cups/backend/
sudo cp usr/lib/cups/filter/rastertoz35 /usr/lib/cups/filter/
sudo cp usr/share/cups/model/Lexmark-Z35-lxz35cj-cups.ppd /usr/share/cups/model/

sudo chown root:root /usr/lib/cups/backend/z35
sudo chmod 755 /usr/lib/cups/backend/z35

sudo chown root:root /usr/lib/cups/filter/rastertoz35
sudo chmod 755 /usr/lib/cups/filter/rastertoz35
