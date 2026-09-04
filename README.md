# Z25 PRINTER LEGACY LINUX DRIVER for x86\_64

Note: drivers used in this project are deprecated cups might have problem with them


## INSTALLATION

Make sure you have cups installed, then run 

```sh
./install.sh
```

which will install drivers.

### FIX DEPENDENCIES

DRIVER IS 32 BIT ELF - MAKE SURE YOU HAVE 32 BIT LIBRARARIES INSTALLED

`/usr/lib/cups/filter/rastertoz35` is probably missing some `.so` libraries and you
have to install them manually depending on your distribution. First step is to find out what you are missing.

```sh
ldd /usr/lib/cups/filter/rastertoz35
```

which ideally looks like

```
	linux-gate.so.1 (0xf7f08000)
	liblexprintjob.so.0 => /usr/lib32/liblexprintjob.so.0 (0xf7ec3000)
	liblexz35core.so.0 => /usr/lib32/liblexz35core.so.0 (0xf7e14000)
	libcups.so.2 => /usr/lib32/libcups.so.2 (0xf7d86000)
	libcupsimage.so.2 => /usr/lib32/libcupsimage.so.2 (0xf7d81000)
	libstdc++.so.5 => /usr/lib32/libstdc++.so.5 (0xf7cc4000)
	libm.so.6 => /usr/lib32/libm.so.6 (0xf7bb2000)
	libgcc_s.so.1 => /usr/lib32/libgcc_s.so.1 (0xf7b7e000)
	libc.so.6 => /usr/lib32/libc.so.6 (0xf793b000)
	libgnutls.so.30 => /usr/lib32/libgnutls.so.30 (0xf7736000)
	libz.so.1 => /usr/lib32/libz.so.1 (0xf771c000)
	/lib/ld-linux.so.2 => /usr/lib/ld-linux.so.2 (0xf7f0b000)
	libp11-kit.so.0 => /usr/lib32/libp11-kit.so.0 (0xf757c000)
	libidn2.so.0 => /usr/lib32/libidn2.so.0 (0xf755b000)
	libtasn1.so.6 => /usr/lib32/libtasn1.so.6 (0xf7544000)
	libhogweed.so.7 => /usr/lib32/libhogweed.so.7 (0xf7501000)
	libnettle.so.9 => /usr/lib32/libnettle.so.9 (0xf74ab000)
	libgmp.so.10 => /usr/lib32/libgmp.so.10 (0xf7423000)
	libffi.so.8 => /usr/lib32/libffi.so.8 (0xf7418000)
	libunistring.so.5 => /usr/lib32/libunistring.so.5 (0xf7239000)
```

On Arch you can fix most of dependencies by enabling `multilib` in `/etc/pacman.conf` and 
```sh
	pacman -S lib32-libcups  
	yay -S lib32-stdc++5
```


## ADD PRINTER
With your printer plugged in go to `http://localhost:631` -> `Administartion` -> `Add Printer` 
-> `Local Printers: 	Lexmark Z25-Z35 (Lexmark Z25-Z35)` -> `Continue` ->
`Or Provide a PPD File: Browse` -> `/usr/share/cups/model/Lexmark-Z35-lxz35cj-cups.ppd`

and that should be it.

### TEST YOUR PRINTER
`http://localhost:631` -> `Printers` -> `Lexmark_Z25-Z35` -> under Maintaince -> `Print Test Page`

