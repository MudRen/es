// Recycle bin..  to clean up some empty containers.
// Elon@eastern.Stories   Sun  08-21-94
 
#include <irc.h>
 
inherit OBJECT;
 
void create() {
  seteuid(getuid());
  set_name("recycle bin","��Դ����Ͱ");
  set("id",({"bin","tube"}));
  set_short("��ɫͰ��");
  set("prevent_get",1);
  set_long(
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
    string tmps;
    object *objs;
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
                    write("�㽫"+objs[i]->query("short")+"��������Ͳ��. �õ� "+mon+" ��ͭ��.\n");
                    this_player()->credit("copper",mon);
                    objs[i]->remove();
                    return 1;
                    }
                else {
                write("�����������ܻ���.\n");
                return 1;
                }
            }
        }
        write("��û����������.\n");
        return 1;
}
 
