import sys, midi

track = midi.read_midifile(sys.argv[1])[int(sys.argv[2])]

notes = [n for n in track if isinstance(n, midi.NoteOnEvent)]

raw = []
for i, n in enumerate(notes):
    if i % 2 == 0:
        if i != 0:
            raw[-1].append(n.tick)
        raw.append([n.data[0]])
    else:
        raw[-1].append(n.tick)

if len(notes) % 2 == 0:
    raw[-1].append(raw[0][2])

raw = [tuple(r) for r in raw]

for r in raw:
    print "{%d, %d, %d}," % r
