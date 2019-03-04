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
  set("id",({"story1"}));
  set_name("story1","ֽ�ɻ�����");
  set_short("story1","ֽ�ɻ�����");
  set_long("This is a message reader, you were given this reader when\n"+
           "Elon wants you to read a document or something like that\n"+
           "Just type read note to read the content.\n","ֽ�ɻ�����\n");
  set("mass",1);
  set("bulk",1);
  set("unit","��");
  set("value",({10,"silver"}) );
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
    if (str!="story1") {
        return 0;
    }
this_player()->more("/u/w/wind/shops/story1.txt");
say(this_player()->query("c_cap_name")+"���ڶ�һ���飬�����ǡ�ֽ�ɻ����á���\n");
    return 1;
}
 
