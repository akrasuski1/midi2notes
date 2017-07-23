# Midi to note translator

This program was tested only on MIDIs downloaded from `musescore.com`. It
heavily relies on their MIDI note structure, and it is unlikely it will work
on generic MIDIs. Still, this program reasonably well translates them
into notes, which can be then replayed by simple C program (or uploaded to
Arduino or something).

Usage:
```bash
python makenotes.py samples/score.mid 0 > mus.inc
gcc play.c -lm -o play
./play | aplay
```
