# TableBox

A very rough fltk 1.x port of pyrgen's original fltk2/GPLv2 "TableBox" widget (0.9.x) up on [google code](https://code.google.com/archive/p/tablebox/)
which was posted on FLTK's Links page at https://www.fltk.org/links.php?V339+Q back in 2007 I think.

![screenshot](https://raw.githubusercontent.com/erco77/TableBox/main/docs/images/test1-demo-screenshot.jpg)

I made this port mainly to just explore the widget. I couldn't get the old + abandoned fltk2 toolkit 
to build with modern compilers, so I tried hacking TableBox's code to roughly port it to build
with fltk 1.4.x. While it builds and the test program now runs, I'm not sure it fully works
as expected -- needs more work. Here's a ![short screenshot-video](https://raw.githubusercontent.com/erco77/TableBox/main/docs/images/test1-exercise.webm)
showing the current code's resizing action.

Perhaps someone else more motivated than I can take this rough port as a starting point
for a cleaner implementation; feel free to fork and continue.

The main things I had to tweak to do the port (and should probably be checked):

    * The fltk2 layout() virtual which TableBox overloads, does not exist in fltk 1.x,
      had to do some code gymnastics to get that method to be invoked; once after widgets
      are initially created (to position/size everything to their initial positions),
      and again whenever there's a resize(). So I kinda hacked that, perhaps not completely.

    * I emulated the fltk2 methods is_group() and is_window() using C++'s 's typeid().
      Not sure this works as intended
      
Someone cleaning this port up would want to look carefully at
[my diffs](https://github.com/erco77/TableBox/commit/ae1dbdc443a0a09f5da9f8813e15782348802b6c?w=1)
from the original pyren code (4b6dbbb) with white space disabled and look for problems.
      


