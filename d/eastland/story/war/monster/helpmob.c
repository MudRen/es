#include <mudlib.h>

inherit MONSTER;
void create()
{
	::create();
        set("help_war",1);
}
void init()
{
     object player;
     player=this_player();  
     if ( player->query("palace_war") ) {
        tell_room(environment(),sprintf(
            "%s����%s�������ɶ����Ⱦ�����ȷ����������ǣ������µ���ȥ�ɣ���\n",
            this_object()->query("c_name"),player->query("c_name")));
            this_object()->kill_ob(player);
     }
     ::init();
}
void die()
{
    int damage;
    object killer;
    killer=query("last_attacker");
    if ( killer) {
      if ( !killer->query("npc") ) {
         tell_object(killer,"\n���д����Ƶ۴�ŭ��������ԭ��������������Ե׵ģ�\n\n");
         tell_object(killer,"�Ƶ�����һ������������ͷ�ϣ���\n\n\n");
         tell_room(environment(),sprintf("�Ƶ�����һ����������%s��ͷ�ϣ�\n",
            killer->query("c_name")),killer);
         damage=killer->query("max_hp")*9/10;
         killer->add("hit_points",-damage);  
      }
    }
    ::die();
}
