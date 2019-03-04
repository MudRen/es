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
  set_name("small letter","���Ƶ���");
  set_short("��Ƥ���Ƶ���");
  set_long("һ�⿴���ܹ��ϵ��ţ������Ѿ��ܾ�û��ȥ������...\n");
  set("weight",10);
  set("bulk",1);
  set("unit","��");
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
 
