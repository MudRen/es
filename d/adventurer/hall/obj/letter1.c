/*
A simple file reader... useful when you want to show the player
your files or text files...
ver: 1.0 alpha 2-23-94
for TMI lib by elon@eastern.stories
*/
#include <mudlib.h>;
#include <config.h>;
 
inherit OBJECT;
inherit DAEMON ;

void create();
void init();
int read_me(string str);
 
void create() {
  seteuid(getuid());
  set("id",({"letter"}));
  set_name("small letter","发黄的信");
  set_short("表皮泛黄的信");
  set_long("一封看来很古老的信，好像已经很久没人去读它了...\n");
  set("weight",10);
  set("bulk",1);
  set("unit","封");
}
 
void init() {
  add_action("read_me", "read");
}
 
int read_me (string str)
{
    if (!str) {
        notify_fail("Read what?\n");
        return 1;
    }
    if (str != "letter") {
        return 0;
    }
this_player()->more("/d/adventurer/book_info/story1");
    return 1;
}
 
