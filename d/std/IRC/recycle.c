// Recycle bin..  to clean up some empty containers.
// Elon@eastern.Stories   Sun  08-21-94
 
#include <irc.h>
 
inherit OBJECT;
 
void create() {
  seteuid(getuid());
  set_name("recycle bin","资源回收桶");
  set("id",({"bin","tube"}));
  set_short("绿色桶子");
  set("prevent_get",1);
  set_long(
@CLONG
你看到一个漆成绿色的桶子. 上面写著 [资源回收桶], 为了保持 ES 的清洁
请随手将空瓶, 空罐之类的可回收资源送到这里 (recycle).
(就算你不是环保小尖兵, 看在钱的份上也来回收吧.)
 
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
                    write("你将"+objs[i]->query("short")+"丢进回收筒内. 得到 "+mon+" 个铜币.\n");
                    this_player()->credit("copper",mon);
                    objs[i]->remove();
                    return 1;
                    }
                else {
                write("这样东西不能回收.\n");
                return 1;
                }
            }
        }
        write("你没有这样东西.\n");
        return 1;
}
 
