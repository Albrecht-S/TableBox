# TableBox

A very rough fltk 1.4.x port of pyrgen's fltk2 based widget "TableBox", version 0.9.x
which was posted on FLTK's Links page at https://www.fltk.org/links.php?V339+Q back in 2007 I think.

I made this port mainly to just explore the widget. I couldn't get the abandoned fltk2 project 
to build against, so I tried hacking TableBox just enough to get it to build with fltk 1.4.x.
While it builds and seems to run the test program, I'm not sure it works as expected.

Perhaps someone else more motivated than I can take this rough port as a starting point
for a cleaner implementation.

The main things I had to deal with which should probably be checked on a cleaner port:

    * The fltk2 layout() virtual, which TableBox overloads, and I think just needs 
      to be called after widgets are created (to position/size everything to their
      initial positions), and during resize(). So I kinda hacked that, perhaps not
      completely. See the diff between the first commit, and my 'rough port' branch.

    * I emulated the fltk2 methods is_group() and is_window() using C++'s 's typeid().
      Not sure this works as intended, someone cleaning this port up would want to look
      carefully at my mods, and make more appropriate changes..
      


