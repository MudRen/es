#include <mudlib.h>;
#include <config.h>;
 
inherit OBJECT;
inherit DAEMON ;

void create();
void init();
int read_me(string str);
 
void create() {
  seteuid(getuid());
  set("id",({"pie_book1"}));
  set_name("pie_book1","�顸�����ƻ���ɡ�");
  set_short("pie_book1","�顸�����ƻ���ɡ�");
  set_long("This is a message reader, you were given this reader when\n"+
           "Elon wants you to read a document or something like that\n"+
           "Just type read note to read the content.\n","����һ���ÿ�����...\n");
  set("mass",1);
  set("bulk",1);
  set("unit","��");
  set("value",({20,"silver"}) );
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
    if (str!="pie_book1") {
        return 0;
    }
this_player()->more("/u/w/wind/shops/pie_book1.txt");
say(this_player()->query("c_cap_name")+"���ڶ�һ���飬�����ǡ������ƻ���ɡ���\n");
    return 1;
}
 
