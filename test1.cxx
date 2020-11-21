#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Double_Window.H>
#include "TableBox.H"

int main(int argc, char ** argv) {
    Fl_Double_Window *win = new Fl_Double_Window(420, 420, "Test 1");
    win->begin();
    
    TableBox *table1 = new TableBox(10, 10, win->w() - 20, win->h() - 20);
    
    table1->Size(3, 3);
    table1->box(FL_BORDER_BOX);
    table1->begin();
    
    // row 0
    //             Widget being added                                 col,row  w,h      x,y properties       x,y span  x,y align
    //             -------------------------------------------------- -------  -------  -------------------- --------  -----------
    table1->Attach((Fl_Widget*) new Fl_Button(0, 0, 0, 0, "Button 1"), 0, 0,   100, 25, FILL, FILL,          1, 1,     0.0f, 0.5f);
    table1->Attach((Fl_Widget*) new Fl_Input(0, 0, 0, 0),              1, 0,   200, 25, EXPAND | FILL, FILL, 1, 1,     0.5f, 0.5f);
    table1->Attach((Fl_Widget*) new Fl_Button(0, 0, 0, 0, "Button 2"), 2, 0,   100, 25, FILL | EXPAND, FILL, 1, 1,     0.5f, 0.5f);

    // row 2
    TableBox *table2 = new TableBox(0, 0, 0, 0);
    table2->Size(1, 3);
    table2->box(FL_BORDER_BOX);
    table2->begin();
    //             Widget being added                                   col,row  w,h      x,y properties     x,y span
    //             ---------------------------------------------------- -------  -------  -----------------  --------
    table2->Attach((Fl_Widget *) new Fl_Button(0, 0, 0, 0, "Button 3"), 0, 0,    100, 25);
    table2->Attach((Fl_Widget *) new Fl_Button(0, 0, 0, 0, "B... 4"),   1, 0,    100, 25, EXPAND|FILL);
    table2->Attach((Fl_Widget *) new Fl_Button(0, 0, 0, 0, "Button 5"), 2, 0,    100, 25);
    table2->end();
    table1->Attach((Fl_Widget *) table2,                                0, 1,    100, 25, FILL|EXPAND, FILL, 2, 1);
    
    // row 3
    TableBox * table3 = new TableBox(0, 0, 0, 0);
    table3->Size(2, 3);
    table3->box(FL_BORDER_BOX);
    table3->begin();
    //             Widget being added                                   col,row  w,h      x,y properties           x,y span
    //             ---------------------------------------------------- -------  -------  ------------------------ --------
    table3->Attach((Fl_Widget *) new Fl_Button(0, 0, 0, 0, "Button 6"), 0, 0,    80, 25,  NONE, NONE);
    table3->Attach((Fl_Widget *) new Fl_Button(0, 0, 0, 0, "Button 7"), 1, 0,    80, 25,  NONE, NONE);
    table3->Attach((Fl_Widget *) new Fl_Input(0, 0, 0, 0),              2, 0,    100, 25, FILL|EXPAND);
    table3->Attach((Fl_Widget *) new Fl_Input(0, 0, 0, 0),              0, 1,    100, 25, FILL|EXPAND, FILL|EXPAND, 3, 1);
    table3->end();
    table1->Attach((Fl_Widget *) table3,                                0, 2,    100, 25, FILL|EXPAND, FILL|EXPAND, 2, 1);
    
    // row 2-4
    TableBox *table4 = new TableBox(0, 0, 0, 0);
    table4->Size(2, 1);
    table4->box(FL_BORDER_BOX);
    table4->begin();
    //             Widget being added                                   col,row  w,h       x,y properties x,y span x,y align
    //             ---------------------------------------------------- -------  --------- -------------- -------- -----------
    table4->Attach((Fl_Widget *) new Fl_Input(0, 0, 0, 0),              0, 0,    100, 25);
    table4->Attach((Fl_Widget *) new Fl_Button(0, 0, 0, 0, "Button 8"), 0, 1,    80,  25,  NONE,EXPAND,   1, 1,    0.5f, 1.0f);
    table4->end();
    table1->Attach((Fl_Widget *) table4,                                2, 1,    102, 102, NONE,NONE,     1, 2,    0.5f, 0.5f);
    
    table1->end();
    table1->layout();
    table2->layout();
    table3->layout();
    table4->layout();

    table1->end(); table1->layout();
    win->end();
    win->resizable(table1);
    win->size_range(420, 420);
    win->show(argc, argv);
    return Fl::run();
}
