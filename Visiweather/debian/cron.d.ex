#
# Regular cron jobs for the visiweather package
#
0 4	* * *	root	[ -x /usr/bin/visiweather_maintenance ] && /usr/bin/visiweather_maintenance
