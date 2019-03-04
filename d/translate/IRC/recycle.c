// Recycle bin..  to clean up some empty containers.
// Elon@eastern.Stories   Sun  08-21-94
 
#include <irc.h>
 
inherit OBJECT;
 
void create() {
  seteuid(getuid());
  set_name("recycle bin","��Դ����Ͱ");
  set("id",({"bin","tube"}));
  set_short("A green tube","��ɫͰ��");
  set("prevent_get",1);
  set_long(
@LONG
A green metal tube, the word [RECYCLE BIN] was painted on the side.
In order to keep ES clean, please recycle your empty cans and bottles
here.
(and for the sake of money, hey, you get something for recycle.)
 
LONG
,
@CLONG
�㿴��һ�������ɫ��Ͱ��. ����д�� [��Դ����Ͱ], Ϊ�˱��� ES �����
�����ֽ���ƿ, �չ�֮��Ŀɻ�����Դ�͵����� (recycle).
(�����㲻�ǻ���С���, ����Ǯ�ķ���Ҳ�����հ�.)
 
CLONG
);
 
}
 
void init() {
  add_action("recycle_me", "recycle");
}
 
int recycle_me(string str)
{
    string *objs,tmps;
    int i,mon,tmpi;
    if (!str || str=="") {
        return notify_fail("Syntax: recycle <item>\n");
    }
    objs=all_inventory(this_player());
    for (i=0; i<sizeof(objs); i++) {
        if ((string)objs[i]->query("name")==str) {
        if (sscanf(file_name(objs[i]),"%sempty#%d",tmps,tmpi)==2) {
//            if (objs[i]->query("recycle")) {
                    mon=(int)objs[i]->query("recycle");
                    write(can_read_chinese()?
                    "�㽫"+objs[i]->query("c_short")+"��������Ͳ��. �õ� "+mon+" ��ͭ��.\n":
                    "You deposit "+objs[i]->query("short")+" into the bin and"+
                    " got "+mon+" copper coins in return.\n");
                    this_player()->set("wealth/copper",mon);
                    objs[i]->remove();
                    return 1;
                    }
                else {
                write(can_read_chinese()?
                "�����������ܻ���.\n":
                "You can\'t recycle this.\n");
                return 1;
                }
            }
        }
        write(can_read_chinese()?
        "��û����������.\n":
        "You don\'t have this item.\n");
        return 1;
}
 
