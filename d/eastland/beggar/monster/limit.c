#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
}
int stop_attack()
{
   object player;
   player=this_player();
   if ( player->query_level() > query("lvlimit") ) {
     write("ι�������ڷ����͵ȼ�����ҳ԰ɣ�\n");
     return 1;
   }
   return 0;
}