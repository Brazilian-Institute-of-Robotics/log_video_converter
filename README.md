log2video
=============
Convert the image [Rock Framework](www.rock-robotics.org) log files to an MPEG(.mkv) video file.


Usage
=============
This tool install a binary file on rock. So after setting the rock environment (source $ROCK_DIRECTORY/env.sh), from any folder you can perform the following command:

```
Log2Video <input_log_file> <stream_name> <output_file>
```

For example:

```
Log2Video camera_aravis_front_left.0.log camera_aravis_front_left.frame ./camera_aravis_front_left.mkv
```

Note
==============
Some log files are compressed or are corrupted. The ruby script `fixlog.rb`
tries to fix the log files. If you enconter any problem running Log2Video, try
to run fixlog.rb on you logfile before.
